workspace "Pizza"
    architecture "x64"

    configurations { "Debug", "Release", "Dist"}

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Pizza/vendor/GLFW/include"
IncludeDir["Glad"] = "Pizza/vendor/Glad/include"
IncludeDir["ImGui"] = "Pizza/vendor/imgui"

-- Include submodule's premake file
include "Pizza/vendor/GLFW"
include "Pizza/vendor/Glad"
include "Pizza/vendor/imgui"

project "Pizza"
    location "Pizza"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "pzpch.h"
    pchsource "Pizza/src/pzpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp" 
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links 
    { 
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
            "PZ_PLATFORM_WINDOWS",
            "PZ_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }

    filter "configurations:Debug"
        defines "PZ_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "PZ_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "PZ_DIST"
        runtime "Release"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

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
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "PZ_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "PZ_DIST"
        runtime "Release"
        optimize "On"
