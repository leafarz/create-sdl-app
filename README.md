# create-sdl-app
Simple tool to generate a C++ SDL project.

## Info
- SDL version: SDL2-2.0.10
- Premake5
- Supports only x64 architecture
- Preconfigured with VS2017
- Tested only with Windows OS.

## Instructions
1. Edit premake5.lua and change the ```WORKSPACE_NAME```, ```PROJECT_NAME``` and ```ROOT_DIRECTORY```
```
-- User defined
local WORKSPACE_NAME = "Workspace"
local PROJECT_NAME = "Project"
local ROOT_DIRECTORY = ".\\"
...
```
2. Run ```GenerateProject.bat``` file and it will generate the VS 2017 solution to ```ROOT_DIRECTORY/WORKSPACE```
(**WARNING:** This has no safety checks so make sure to check paths. This was made only for testing purposes.)
3. Open the solution file in the root directory and you should be able to run the project.

## Project Directory
```
workspace
├── .gitignore
├── README.md
├── workspace.sln
├── project/
    ├── project.vcxproj
    ├── bin/
    ├── include/
    └── src/
        └── main.cpp
└── vendor/
    └──  SDL2-2.0.10/
```

## Libraries
1. SDL2