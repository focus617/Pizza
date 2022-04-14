workspace "Pizza"
	architecture "x64"
	startproject "Sandbox" 
	configurations { "Debug", "Release", "Dist"}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Pizza"
	location "Pizza"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PZ_PLATFORM_WINDOWS",
			"PZ_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PZ_DEBUG"
		optimize "On"

	filter "configurations:Release"
		defines "PZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PZ_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Pizza/vendor/spdlog/include",
		"Pizza/src"
	}

	links
	{
		"Pizza"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PZ_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "PZ_DEBUG"
		optimize "On"

	filter "configurations:Release"
		defines "PZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PZ_DIST"
		optimize "On"