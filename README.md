# Vectorscope Visualizer

This project is a prototype stereo XY vectorscope built with C++17 for the backend and React for the frontend. The components communicate using WebSockets. Rendering is done with OpenGL and GLSL shaders.

## Folder Layout

- `src/` — C++ source code
- `src/shaders/` — Vertex and fragment shaders
- `frontend/` — React application
- `build/` — Generated binaries

## Building

### Requirements
- C++17 compiler
- CMake 3.10+
- `glfw` and `boost` installed on the system
- Node.js (for the React frontend)

### Linux / macOS
```bash
./scripts/build_and_run.sh
```

### Windows
```cmd
scripts\\build_and_run.bat
```

This will build the backend and start the React development server.
