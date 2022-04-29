#pragma once

#include "Pizza/Core/Core.h"

#include "Pizza/Core/Window.h"
#include "Pizza/Core/LayerStack.h"
#include "Pizza/Events/Event.h"
#include "Pizza/Events/ApplicationEvent.h"

#include "Pizza/Core/Timestep.h"

#include "Pizza/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Pizza {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}



