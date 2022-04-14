#pragma once

#ifdef PZ_PLATFORM_WINDOWS

extern Pizza::Application* Pizza::CreateApplication();

// Move main() from client who include this file back to engine 
int main(int argc, char** argv)
{
	Pizza::Log::Init();
	PZ_CORE_WARN("Initialized Log!");

	int a = 5;
	PZ_INFO("Hello! Var={0}", a);

	auto app = Pizza::CreateApplication();

	app->Run();

	delete app;
}

#endif

