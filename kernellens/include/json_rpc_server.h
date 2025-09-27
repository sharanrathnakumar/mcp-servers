#pragma once
#include <string>

class JsonRpcServer {
public:
    void start(int port);
    std::string handle_request(const std::string& request);
};
