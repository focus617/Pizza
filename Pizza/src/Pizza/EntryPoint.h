#pragma once

#ifdef PZ_PLATFORM_WINDOWS

extern Pizza::Application* Pizza::CreateApplication();

// Move main() from client who include this file back to engine 
int main(int argc, char** argv)
{
	auto app = Pizza::CreateApplication();

	app->Run();

	delete app;
}

#endif

