#include "pzpch.h"
#include "Pizza/Core/Input.h"

#ifdef PZ_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace Pizza {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
#ifdef PZ_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else
		PZ_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}