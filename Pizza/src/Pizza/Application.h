#pragma once

#include "Core.h"

#include "Window.h"
#include "Pizza/LayerStack.h"
#include "Pizza/Events/Event.h"
#include "Pizza/Events/ApplicationEvent.h"

namespace Pizza {

	class PIZZA_API Application
	{
	public:
		Application();
		~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}



