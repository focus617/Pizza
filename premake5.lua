workspace "Pizza"
    architecture "x64"

    configurations { "Debug", "Release", "Dist"}

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Pizza/vendor/GLFW/include"

-- Include submodule's premake file
include "Pizza/vendor/GLFW"


project "Pizza"
    location "Pizza"
    kind "SharedLib"
    language "C++"

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
        "%{IncludeDir.GLFW}"
    }

    links 
    { 
        "GLFW",
        "opengl32.lib"
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
        buildoptions "/MDd"
        optimize "On"

    filter "configurations:Release"
        defines "PZ_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "PZ_DIST"
        buildoptions "/MD"
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
        buildoptions "/MDd"
        optimize "On"

    filter "configurations:Release"
        defines "PZ_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "PZ_DIST"
        buildoptions "/MD"
        optimize "On"
