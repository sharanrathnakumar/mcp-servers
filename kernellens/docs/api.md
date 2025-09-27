# MCP Server API Documentation

## Overview
This document describes the APIs exposed by the kernellens MCP server. All APIs are accessible via JSON-RPC.

---

## API: list_syscalls(pid)
- **Description:** Lists recent system calls for a given process ID using ptrace.
- **Parameters:**
  - `pid` (int): The process ID to trace.
- **Returns:**
  - Array of syscall strings (e.g., `syscall: 59`)
- **Example Request:**
```json
{
  "method": "list_syscalls",
  "params": { "pid": 1234 }
}
```

---

## API: monitor_network(pid)
- **Description:** Returns demo network events for a given process ID.
- **Parameters:**
  - `pid` (int): The process ID to monitor.
- **Returns:**
  - Array of network event strings (e.g., `connect: 127.0.0.1:8080`)
- **Example Request:**
```json
{
  "method": "monitor_network",
  "params": { "pid": 1234 }
}
```

---

## API: explain_behavior(trace_log)
- **Description:** Returns a demo explanation for a given trace log string.
- **Parameters:**
  - `trace_log` (string): The trace log to explain.
- **Returns:**
  - Explanation string
- **Example Request:**
```json
{
  "method": "explain_behavior",
  "params": { "trace_log": "open, read, write" }
}
```

---

## Usage Notes
- All requests and responses are in JSON-RPC format.
- For real syscall and network monitoring, further implementation is required.
- See README for build and run instructions.
