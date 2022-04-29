#pragma once

#include "Pizza/Core/Core.h"

#ifdef PZ_PLATFORM_WINDOWS

extern Pizza::Application* Pizza::CreateApplication();

// Move main() from client who include this file back to engine 
int main(int argc, char** argv)
{
	Pizza::Log::Init();

	PZ_PROFILE_BEGIN_SESSION("Startup", "HazelProfile-Startup.json");

	// Let the actual project to implement the CreateApplication() and return the app*
	auto app = Pizza::CreateApplication();
	PZ_PROFILE_END_SESSION();

	PZ_PROFILE_BEGIN_SESSION("Runtime", "HazelProfile-Runtime.json");
	app->Run();
	PZ_PROFILE_END_SESSION();

	PZ_PROFILE_BEGIN_SESSION("Startup", "HazelProfile-Shutdown.json");
	// While the app finished running, release the memory
	delete app;
	PZ_PROFILE_END_SESSION();
}
#else
	#error Pizza Engine only support Windows 64-bit for now
#endif

