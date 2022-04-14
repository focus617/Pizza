#pragma once

#ifdef PZ_PLATFORM_WINDOWS
	#ifdef PZ_BUILD_DLL
		#define PIZZA_API __declspec(dllexport)
	#else
		#define PIZZA_API __declspec(dllimport)
	#endif
#else
	#error Pizza only supports Windows!
#endif

#define BIT(x) (1 << x)

