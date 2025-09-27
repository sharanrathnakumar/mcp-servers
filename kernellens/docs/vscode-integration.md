# VS Code Integration: kernellens MCP Server

This guide explains how to integrate the kernellens MCP server with VS Code, enabling Copilot Chat and other extensions to interact with the server APIs.

---

## Prerequisites
- Build and run the MCP server (see README)
- VS Code installed
- Recommended: [VS Code Copilot Chat](https://marketplace.visualstudio.com/items?itemName=GitHub.copilot-chat)

---

## Integration Steps

### 1. Start the MCP Server
Build and run the server:
```bash
mkdir build && cd build
cmake ..
make
./kernellens
```
The server listens for JSON-RPC requests on port 8080 by default.

### 2. Connect from VS Code
You can interact with the MCP server using VS Code extensions that support HTTP/JSON-RPC, such as Copilot Chat or REST Client.

#### Example: Using REST Client Extension
1. Install the [REST Client](https://marketplace.visualstudio.com/items?itemName=humao.rest-client) extension.
2. Create a `.http` file in your workspace:
```http
POST http://localhost:8080
Content-Type: application/json

{
  "method": "list_syscalls",
  "params": { "pid": 1234 }
}
```
3. Send the request and view the response in VS Code.

#### Example: Copilot Chat Custom Tooling
- Use Copilot Chat to generate JSON-RPC requests and parse responses.
- Document API endpoints in your project for Copilot to reference.

### 3. Automate with Tasks
Add VS Code tasks to build and run the server:
```json
// .vscode/tasks.json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Build kernellens",
      "type": "shell",
      "command": "cmake .. && make",
      "options": { "cwd": "${workspaceFolder}/kernellens/build" }
    },
    {
      "label": "Run kernellens",
      "type": "shell",
      "command": "./kernellens",
      "options": { "cwd": "${workspaceFolder}/kernellens/build" }
    }
  ]
}
```

---

## Tips
- Document API requests in markdown for Copilot Chat to reference.
- Use the REST Client for quick manual testing.
- Update API docs as endpoints evolve.

---

For advanced integration, consider writing a custom VS Code extension to interact with the MCP server directly.
