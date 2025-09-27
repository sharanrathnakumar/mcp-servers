#include <iostream>
#include "json_rpc_server.h"

int main() {
    std::cout << "kernellens MCP server starting..." << std::endl;
    JsonRpcServer server;
    server.start(8080); // Start server on port 8080
    return 0;
}
