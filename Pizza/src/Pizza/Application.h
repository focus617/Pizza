#pragma once

#include "Core.h"

#include "Window.h"
#include "Pizza/LayerStack.h"
#include "Pizza/Events/Event.h"
#include "Pizza/Events/ApplicationEvent.h"

#include "Pizza/ImGui/ImGuiLayer.h"

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

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}



