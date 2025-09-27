#include "json_rpc_server.h"
#include <iostream>
#include <nlohmann/json.hpp>

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
        resp["result"] = "syscalls for pid";
    } else if (method == "monitor_network") {
        resp["result"] = "network activity for pid";
    } else if (method == "explain_behavior") {
        resp["result"] = "behavior explanation";
    } else {
        resp["error"] = "Unknown method";
    }
    return resp.dump();
}
