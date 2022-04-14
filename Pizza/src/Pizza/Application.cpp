#include "Application.h"

#include "Pizza/Events/ApplicationEvent.h"
#include "Pizza/Log.h"

namespace Pizza {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			PZ_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			PZ_TRACE(e);
		}

		while (true);
	}


}