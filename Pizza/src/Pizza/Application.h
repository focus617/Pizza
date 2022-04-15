#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Pizza/Events/ApplicationEvent.h"

#include "Window.h"

namespace Pizza {

	class PIZZA_API Application
	{
	public:
		Application();
		~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}



