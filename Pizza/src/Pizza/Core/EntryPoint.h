#pragma once

#ifdef PZ_PLATFORM_WINDOWS

extern Pizza::Application* Pizza::CreateApplication();

// Move main() from client who include this file back to engine 
int main(int argc, char** argv)
{
	Pizza::Log::Init();
	PZ_CORE_TRACE("Initialized Log!");

	// Let the actual project to implement the CreateApplication() and return the app*
	auto app = Pizza::CreateApplication();

	app->Run();

	// While the app finished running, release the memory
	delete app;
}
#else
	#error Pizza Engine only support Windows 64-bit for now
#endif

