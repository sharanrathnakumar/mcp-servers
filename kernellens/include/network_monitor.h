#pragma once
#include <vector>
#include <string>

class NetworkMonitor {
public:
    std::vector<std::string> monitor_network(pid_t pid);
};
