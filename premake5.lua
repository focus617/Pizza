workspace "Pizza"
    architecture "x64"
    startproject "Sandbox"

    configurations { 
        "Debug", 
        "Release", 
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Pizza/vendor/GLFW/include"
IncludeDir["Glad"] = "Pizza/vendor/Glad/include"
IncludeDir["ImGui"] = "Pizza/vendor/imgui"
IncludeDir["glm"] = "Pizza/vendor/glm"

-- Include submodule's premake file
include "Pizza/vendor/GLFW"
include "Pizza/vendor/Glad"
include "Pizza/vendor/imgui"

project "Pizza"
    location "Pizza"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
	staticruntime "on"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "pzpch.h"
    pchsource "Pizza/src/pzpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp" ,
        "%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
    }

    defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
    }

    links 
    { 
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "PZ_PLATFORM_WINDOWS",
            "PZ_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
        }

    filter "configurations:Debug"
        defines "PZ_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "PZ_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "PZ_DIST"
        runtime "Release"
        optimize "on"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
        "Pizza/src",
        "Pizza/vendor",
		"%{IncludeDir.glm}"
    }

    links
    {
        "Pizza"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "PZ_PLATFORM_WINDOWS"
        }


    filter "configurations:Debug"
        defines "PZ_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "PZ_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "PZ_DIST"
        runtime "Release"
        optimize "on"
