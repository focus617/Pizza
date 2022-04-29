#include "pzpch.h"
#include "Pizza/Core/Window.h"

#ifdef PZ_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Pizza
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef PZ_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		PZ_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}