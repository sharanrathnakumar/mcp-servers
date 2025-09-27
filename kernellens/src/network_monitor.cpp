#include "network_monitor.h"
#include <vector>
#include <string>

std::vector<std::string> NetworkMonitor::monitor_network(pid_t pid) {
    // Basic stub: return demo network events
    std::vector<std::string> events;
    events.push_back("connect: 127.0.0.1:8080");
    events.push_back("send: 128 bytes");
    events.push_back("recv: 256 bytes");
    return events;
}
