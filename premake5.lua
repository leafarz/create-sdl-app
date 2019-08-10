-- User defined
local WORKSPACE_NAME = "workspace"
local PROJECT_NAME = "project"
local ROOT_DIRECTORY = ".\\"

-- Start
local WORKSPACE_DIR = ROOT_DIRECTORY .. WORKSPACE_NAME
local ARCHITECTURE = "x64"

workspace (WORKSPACE_NAME)
   location (WORKSPACE_DIR)
   architecture (ARCHITECTURE)
	startproject (PROJECT_NAME)
   configurations
   {
      "Debug",
      "Release"
   }


project (PROJECT_NAME)
   location (WORKSPACE_DIR .. "/" .. "%{prj.name}")
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"

   targetdir ("%{prj.location}/bin/" .. ARCHITECTURE .. "_%{cfg.shortname}")
   objdir ("%{prj.location}/bin/" .. ARCHITECTURE .. "_%{cfg.shortname}/intermediate/")

   includedirs
   {
      "%{wks.location}/vendor/SDL2-2.0.10/include",
      "%{prj.location}/include/"
   }

   libdirs
   {
      "%{wks.location}/vendor/SDL2-2.0.10/lib/" .. ARCHITECTURE,
   }

   links 
	{ 
      "SDL2.lib",
      "SDL2main.lib"
   }

   files
   {
      "%{prj.location}/include/*.h",
      "%{prj.location}/src/*.cpp"
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

   filter {}
      postbuildcommands
      {
         "XCOPY /Y /I %{wks.location}vendor\\SDL2-2.0.10\\lib\\".. ARCHITECTURE .. "\\SDL2.dll %{cfg.buildtarget.directory}"
      }

      os.execute("mkdir " .. WORKSPACE_DIR .. "\\" .. PROJECT_NAME .. "\\bin\\")
      
      os.execute("XCOPY /E /Y src\\include " .. WORKSPACE_DIR .. "\\" .. PROJECT_NAME .. "\\include\\")
      os.execute("XCOPY /E /Y src\\src " .. WORKSPACE_DIR .. "\\" .. PROJECT_NAME .. "\\src\\")
      os.execute("XCOPY /E /Y src\\vendor " .. WORKSPACE_DIR .. "\\vendor\\")

      os.execute("XCOPY /I /Y src\\.gitignore " .. WORKSPACE_DIR .. "\\")
      os.execute("XCOPY /I /Y src\\README.md " .. WORKSPACE_DIR .. "\\")
