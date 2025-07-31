# OpenGL GLFW Example

This repository contains a minimal C++17 application that opens a window using GLFW and clears the screen each frame with OpenGL. The project is designed to build with package managers like **vcpkg**, **MSYS2** or the standard packages available on Linux distributions.

## Folder Layout

- `src/` — C++ source code
- `build/` — Generated binaries

## Requirements
- C++17 compiler
- CMake 3.10+
- `glfw` and OpenGL development libraries

## Building

```bash
cmake -B build -S .
cmake --build build
```

Run the executable:

```bash
./build/opengl_window
```
