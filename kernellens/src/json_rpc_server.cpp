#include "json_rpc_server.h"
#include <iostream>
#include <nlohmann/json.hpp>

#include "syscall_tracer.h"
#include "network_monitor.h"
#include "behavior_explainer.h"

using json = nlohmann::json;

void JsonRpcServer::start(int port) {
    std::cout << "Starting JSON-RPC server on port " << port << std::endl;
    // TODO: Implement TCP server loop
}

std::string JsonRpcServer::handle_request(const std::string& request) {
    json req = json::parse(request, nullptr, false);
    json resp;
    if (!req.is_object() || !req.contains("method")) {
        resp["error"] = "Invalid request";
        return resp.dump();
    }
    std::string method = req["method"];
    if (method == "list_syscalls") {
        if (!req.contains("params") || !req["params"].contains("pid")) {
            resp["error"] = "Missing pid parameter";
        } else {
            pid_t pid = req["params"]["pid"];
            SyscallTracer tracer;
            auto syscalls = tracer.list_syscalls(pid);
            resp["result"] = syscalls;
        }
    } else if (method == "monitor_network") {
        if (!req.contains("params") || !req["params"].contains("pid")) {
            resp["error"] = "Missing pid parameter";
        } else {
            pid_t pid = req["params"]["pid"];
            NetworkMonitor monitor;
            auto events = monitor.monitor_network(pid);
            resp["result"] = events;
        }
    } else if (method == "explain_behavior") {
        if (!req.contains("params") || !req["params"].contains("trace_log")) {
            resp["error"] = "Missing trace_log parameter";
        } else {
            std::string trace_log = req["params"]["trace_log"];
            BehaviorExplainer explainer;
            auto explanation = explainer.explain_behavior(trace_log);
            resp["result"] = explanation;
        }
    } else {
        resp["error"] = "Unknown method";
    }
    return resp.dump();
}
