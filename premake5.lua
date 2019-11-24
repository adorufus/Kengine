workspace "Kengine"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Kengine/vendor/GLFW/include"

include "Kengine/vendor/GLFW"

project "Kengine"
	location "Kengine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "Kengine/src/hzpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"KE_PLATFORM_WINDOWS",
			"KE_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sanbox")
		}

	filter "configurations:Debug"
		defines "KE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KE_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "KE_DIST"
		optimize "On"

project "Sanbox"
	location "Sanbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"Kengine/vendor/spdlog/include",
		"Kengine/src"
	}

	links{
		"Kengine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"KE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "KE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KE_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "KE_DIST"
		optimize "On"