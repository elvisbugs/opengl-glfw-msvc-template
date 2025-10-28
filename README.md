# OpenGL (GLFW + GLAD) Project Template for MSVC
This is a basic template for starting an OpenGL project using **GLFW** for window management and **GLAD** for loading OpenGL functions, pre-configured to compile with `cl.exe` (Microsoft's C/C++ compiler) directly inside VS Code.

The main advantage is using the powerful MSVC compiler in a lightweight environment without needing to create a Solution file (`.sln`) or open the full Visual Studio IDE.

It comes pre-configured with:
* **GLFW:** For window creation and OpenGL context management;

* **GLAD:** For loading modern OpenGL functions;

* **tasks.json:** To automate the build process;

* **c_cpp_properties.json:** For accurate IntelliSense;

* **launch.json:** For debugging (F5);

* **Folder Structure:** A clean separation of `src`, `lib`, `include`, `bin` and `build` directories.


## Prerequisites
The prerequisites are the same as those of the base template used to create this project:
[cpp-mscv-template](https://github.com/elvisbugs/cpp-mscv-template)

---
## Template Structure
```
opengl-glfw-msvc-template/
├── .vscode/
│   ├── c_cpp_properties.json   # IntelliSense configuration
│   ├── launch.json             # Debugging configuration (F5)
│   └── tasks.json              # Build task (Ctrl+Shift+B)
│
├── bin/                    # Output for executables (.exe) and DLLs
├── build/                  # Output for intermediate files (.obj, .pdb)
├── include/                # Headers (.h) specific to your project
│   └── main.h
│
├── lib/                    # Third-party libraries
│   ├── include/
│   │   ├── glad/           # GLAD headers
│   │   └── glfw/           # GLFW headers
│   ├── src/
│   │   └── glad/
│   │       └── glad.c      # GLAD source file (compiled with your project)
│   ├── glfw3.dll           # GLFW DLL (required for execution)
│   └── glfw3.lib           # GLFW import library (required for compiling)
│
├── src/                    # Your project's source code (.cpp)
│   └── main.cpp
│
└── README.md               # This file
```

---
## Environment Setup
The environment setup are the same as those of the base template used to create this project:
[cpp-mscv-template](https://github.com/elvisbugs/cpp-mscv-template)

---
## How to Run
Just press F5 (with any file open) to build and launch the project.

---
## Acknowledgement
This template was based on the [cpp-mscv-template](https://github.com/elvisbugs/cpp-mscv-template)
