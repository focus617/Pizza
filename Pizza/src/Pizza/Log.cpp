#include "pzpch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"	// used for spdlog::stdout_color_mt

namespace Pizza {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// ����Log�ĸ�ʽ:
		//	%^- %$��Color Range������������ڵ�������ɫ�᲻ͬ��
		//	[%T]�����˲���HH:MM:SS��ʽ�ĵ�ǰʱ�䣬
		//	%n�ǵ�ǰLogger�����֣�
		//	%v��ʵ�ʵ���������
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("PIZZA");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}