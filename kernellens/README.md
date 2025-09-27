# kernellens MCP Server

A minimal MCP server for Linux, written in C++, providing:
- API: `list_syscalls(pid)` — List system calls for a process
- API: `monitor_network(pid)` — Monitor network activity for a process
- API: `explain_behavior(trace_log)` — Explain process behavior from trace logs

## Features
- Hooks live running processes using `ptrace` or eBPF
- Streams results as JSON-RPC events
- Designed for integration with VS Code Copilot Chat

## Planned Structure
- `/src` — C++ source code
- `/include` — C++ headers
- `/CMakeLists.txt` — Build configuration
- `/docs` — Documentation

## Getting Started
1. Build with CMake
2. Run the server and connect via JSON-RPC

## Next Steps
- Implement project skeleton
- Add API endpoints
- Integrate process hooking and event streaming
