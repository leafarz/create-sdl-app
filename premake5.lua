-- User defined
local WORKSPACE_NAME = "workspace"
local PROJECT_NAME = "project"
local ROOT_DIRECTORY = ".\\"

-- Start
local WORKSPACE_DIR = ROOT_DIRECTORY .. WORKSPACE_NAME

workspace (WORKSPACE_NAME)
   location (WORKSPACE_DIR)
   architecture "x64"
	startproject (PROJECT_NAME)
   configurations
   {
      "Debug",
      "Release"
   }


project (PROJECT_NAME)
   location (WORKSPACE_DIR .. "\\" .. "%{prj.name}")
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"

   targetdir ("$(SolutionDir)$(ProjectName)\\bin\\$(PlatformTarget)_$(Configuration)")
   objdir ("$(SolutionDir)$(ProjectName)\\bin\\$(PlatformTarget)_$(Configuration)" .. "\\intermediate\\")
   
   includedirs
   {
      "$(SolutionDir)vendor\\SDL2-2.0.10\\include",
      "$(ProjectDir)include\\"
   }

   libdirs
   {
      "$(SolutionDir)vendor\\SDL2-2.0.10\\lib\\$(PlatformTarget)",
   }

   links 
	{ 
      "SDL2.lib",
      "SDL2main.lib"
   }

   files
   {
      "%{prj.location}\\src\\*.cpp"
   }

   filter "system:windows"
      cppdialect "C++17"
      systemversion "latest"

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

   filter "configurations:*"
      postbuildcommands
      {
         "XCOPY /Y /I $(SolutionDir)vendor\\SDL2-2.0.10\\lib\\x64\\SDL2.dll $(TargetDir)"
      }

      os.execute("mkdir " .. WORKSPACE_DIR .. "\\" .. PROJECT_NAME .. "\\bin\\")
      os.execute("mkdir " .. WORKSPACE_DIR .. "\\" .. PROJECT_NAME .. "\\include\\")

      os.execute("XCOPY /E /Y src\\vendor " .. WORKSPACE_DIR .. "\\vendor\\")
      os.execute("XCOPY /I /Y src\\.gitignore " .. WORKSPACE_DIR .. "\\")
      os.execute("XCOPY /I /Y src\\main.cpp " .. WORKSPACE_DIR .. "\\" .. PROJECT_NAME .. "\\src\\")
      os.execute("XCOPY /I /Y src\\README.md " .. WORKSPACE_DIR .. "\\")
