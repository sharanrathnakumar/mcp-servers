#pragma once
#include <vector>
#include <string>

class SyscallTracer {
public:
    std::vector<std::string> list_syscalls(pid_t pid);
};
