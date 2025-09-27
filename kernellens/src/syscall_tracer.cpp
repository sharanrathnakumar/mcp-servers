#include "syscall_tracer.h"
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> SyscallTracer::list_syscalls(pid_t pid) {
    std::vector<std::string> syscalls;
    // Attach to the process
    if (ptrace(PTRACE_ATTACH, pid, nullptr, nullptr) == -1) {
        perror("ptrace attach");
        return syscalls;
    }
    waitpid(pid, nullptr, 0);
    // Basic: collect a few syscalls (demo only)
    for (int i = 0; i < 10; ++i) {
        ptrace(PTRACE_SYSCALL, pid, nullptr, nullptr);
        waitpid(pid, nullptr, 0);
        struct user_regs_struct regs;
        ptrace(PTRACE_GETREGS, pid, nullptr, &regs);
        syscalls.push_back("syscall: " + std::to_string(regs.orig_rax));
    }
    ptrace(PTRACE_DETACH, pid, nullptr, nullptr);
    return syscalls;
}
