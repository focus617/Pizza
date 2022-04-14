#include "pzpch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"	// used for spdlog::stdout_color_mt

namespace Pizza {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// 设置Log的格式:
		//	%^- %$是Color Range，在这个区间内的文字颜色会不同，
		//	[%T]定义了采用HH:MM:SS格式的当前时间，
		//	%n是当前Logger的名字，
		//	%v是实际的文字内容
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("PIZZA");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}