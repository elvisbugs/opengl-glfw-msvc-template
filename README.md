# C/C++ MSVC Compiler Template for VS Code
This is a template project for compiling and debugging C/C++ (`.c` or `.cpp`) files using the Microsoft C++ (MSVC) compiler directly within VisualStudio Code.

The main goal is to enable compiling and debugging with `F5` without needing to launch VS Code from the "Developer Command Prompt for VS".

## Prerequisites
Before using this template, you must have the following software installed:

1.  **[Visual Studio Code](https://code.visualstudio.com/download)**: The code editor;
2.  **[Microsoft C/C++ Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)**: The official extension (`ms-vscode.cpptools`) for VS Code;
3.  **MSVC C++ build tools**: The Microsoft C++ compiler. You can install the `Desktop development with C++` workload without a full Visual Studio IDE installation. From the Visual Studio [Downloads](https://visualstudio.microsoft.com/downloads/#remote-tools-for-visual-studio-2022) page, scroll down until you see `Tools for Visual Studio` under the `All Downloads` section and select the download for `Build Tools for Visual Studio 2022`. This will launch the Visual Studio Installer, which will bring up a dialog showing the available Visual Studio Build Tools workloads. Check the `Desktop development with C++` workload and select Install.

---

## Project Structure
This template expects the following directory structure:

```
my_project/
│
├── .vscode/
│   ├── tasks.json              # Build task (compiles project)
│   ├── launch.json             # Debugger config (launches executable)
│   └── c_cpp_properties.json   # IntelliSense config
│
├── bin/                        # Folder for the final compiled executable
│   └── my_project.exe
│
├── build/                      # Folder for intermediate object files
│   └── main.obj                # Where intermediate object files (.obj) are located
│   └── utils.obj
│
├── include/                    # Folder for header files (.h, .hpp)
│   └── utils.h 
│
├── src/                        # Folder for source files (.cpp)
│   ├── main.cpp
│   └── utils.cpp
│
├── lib/                        # (Optional) Third-party libraries
│
├── .gitignore
└── README.md
```

---
## Environment Setup
After cloning this repository, you **must** update two paths in the `.vscode` configuration files to match your local installation of Visual Studio / Build Tools.

MSVC is not added to the global Windows `PATH` and relies on scripts to set up the environment. Our configuration files need to know where these scripts are located.

### Step 1: Find the Paths on Your Machine
You will need to locate two files from your Visual Studio installation:

1.  **`VsDevCmd.bat`**: The main script that configures the developer environment;
    * *Common location:* `C:\Program Files\Microsoft Visual Studio\[YEAR]\[EDITION]\Common7\Tools\VsDevCmd.bat`
2.  **`cl.exe`**: The compiler executable.
    * *Common location:* `C:/Program Files (x86)/Microsoft Visual Studio/[YEAR]/BuildTools/VC/Tools/MSVC/[VERSION]/bin/Hostx64/x64/cl.exe`

> **Tip:** An easy way to find the root folder is to search for "Developer Command Prompt" in your Start Menu, right-click it, and select "Open file location." The shortcut will point to the `VsDevCmd.bat` location.

### Step 2: Update the `.vscode` Files
Open the `.vscode` folder and edit the following files:

**1. `.vscode/tasks.json`**
This file is responsible for running the build task. It needs to know where `VsDevCmd.bat` is.
* **Change line 11:** Replace the path `"I:/Visual Studio Compiler/Common7/Tools/VsDevCmd.bat"` with the path you found in Step 1.

```json[9-11]
{
  "version": "2.0.0",
  "windows": {
    "options": {
      "shell": {
        "executable": "cmd.exe",
        "args": [
          "/C",
          // V-- CHANGE THIS LINE --V
          "\"I:/Visual Studio Compiler/Common7/Tools/VsDevCmd.bat\"",
          "&&"
        ]
      }
    }
  },
  "tasks": [
    {
      "type": "shell",
      "label": "cl.exe build project",
      "command": "cl.exe",
      "args": [
        "/Zi",
        "/EHsc",
        "/I", "${workspaceFolder}/include",                 // Include directory
        "/Fe:", "${workspaceFolder}/bin/my_project.exe",    // Output executable
        "${workspaceFolder}/src/*.cpp"                      // Source files
      ],
      "problemMatcher": ["$msCompile"],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    }
  ]
}
```

**2. `.vscode/c_cpp_properties.json`**
This file tells IntelliSense (autocomplete and error checking) where to find the compiler.
* **Change line 13:** Replace the path `"I:\\Visual Studio Compiler\\...\\cl.exe"` with your cl.exe path from Step 1;
* **Note:** In JSON files, backslashes (`\`) must be escaped (doubled up as `\\`).

```json[9-11]
{
  "configurations": [
    {
      "name": "Win32",
      // ...
      "intelliSenseMode": "windows-msvc-x64",
      // V-- CHANGE THIS LINE (use double backslashes \\) --V
      "compilerPath": "\"I:\\Visual Studio Compiler\\VC\\Tools\\MSVC\\14.44.35207\\bin\\Hostx64\\x64\\cl.exe\""
    }
  ],
  "version": 4
}
```

---
## How to Use
After you have configured the paths correctly and structured your project with `src/` and `include/` folders:

1. Open any `.c` or `.cpp` file in VS Code;
2. Press `F5` (or go to "Run" > "Start Debugging");
3. VS Code will:
    * Execute the `preLaunchTask` defined in `launch.json`;
    * This task (from `tasks.json`) will first load the environment using `VsDevCmd.bat`;
    * It will then compile **all `.cpp` files in the `src/` folder**, link them, and output a single executable to the `bin/` folder (e.g., `bin/my_project.exe`);
    * After a successful compilation, the VS Code debugger will launch and attach to your program.

---
## References
This configuration is based on the official Visual Studio Code documentation. For more details, see:
https://code.visualstudio.com/docs/cpp/config-msvc
