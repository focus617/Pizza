#pragma once

#include "Core.h"

namespace Pizza {

	class PIZZA_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}



