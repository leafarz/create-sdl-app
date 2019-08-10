# create-sdl-app
- Simple tool to generate a C++ SDL project.
- Has only point, line and rectangle draws.

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
(**WARNING:** This has no safety checks so it might be destructive. Make sure to check the paths. This was made only for testing purposes.)
3. Open the solution file in the root directory and you should be able to run the project.

## Project Directory
```
[WORKSPACE_NAME]
├── .gitignore
├── README.md
├── workspace.sln
├── [PROJECT_NAME]/
	├── project.vcxproj
	├── project.vcxproj.filters
	├── bin/
	├── include/
		├── AABB.h
		├── Application.h
		├── Color.h
		├── MathUtil.h
		├── Scene.h
		├── Vec2f.h
		└── Window.h
	└── src/
		├── AABB.cpp
		├── Application.cpp
		├── Color.cpp
		├── main.cpp		<-- entry point
		├── MathUtil.cpp
		├── Scene.cpp		<-- where you put your code
		├── Vec2f.cpp
		└── Window.cpp
└── vendor/
	└──  SDL2-2.0.10/
```

## Libraries
1. SDL2