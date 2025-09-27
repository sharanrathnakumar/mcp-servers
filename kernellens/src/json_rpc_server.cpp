#include "json_rpc_server.h"
#include <iostream>
#include <nlohmann/json.hpp>

#include "syscall_tracer.h"

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
        resp["result"] = "network activity for pid";
    } else if (method == "explain_behavior") {
        resp["result"] = "behavior explanation";
    } else {
        resp["error"] = "Unknown method";
    }
    return resp.dump();
}
