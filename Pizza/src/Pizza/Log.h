#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Pizza {

	class PIZZA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}


// Core log macros
#define PZ_CORE_TRACE(...)   ::Pizza::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PZ_CORE_INFO(...)    ::Pizza::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PZ_CORE_WARN(...)    ::Pizza::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PZ_CORE_ERROR(...)   ::Pizza::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PZ_CORE_FATAL(...)   ::Pizza::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define PZ_TRACE(...)   ::Pizza::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PZ_INFO(...)    ::Pizza::Log::GetClientLogger()->info(__VA_ARGS__)
#define PZ_WARN(...)    ::Pizza::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PZ_ERROR(...)   ::Pizza::Log::GetClientLogger()->error(__VA_ARGS__)
#define PZ_FATAL(...)   ::Pizza::Log::GetClientLogger()->critical(__VA_ARGS__)

