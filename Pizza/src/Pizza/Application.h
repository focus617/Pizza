#pragma once

#include "Core.h"
#include "Events/Event.h"

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



