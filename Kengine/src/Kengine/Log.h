#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Kengine {

	class KENGINE_API Log
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

//core logging macros
#define KE_CORE_ERROR(...)	::Kengine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KE_CORE_WARN(...)	::Kengine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KE_CORE_INFO(...)	::Kengine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KE_CORE_TRACE(...)	::Kengine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KE_CORE_FATAL(...)	::Kengine::Log::GetCoreLogger()->critical(__VA_ARGS__)

//sandbox logging macros
#define KE_ERROR(...)		::Kengine::Log::GetClientLogger()->error(__VA_ARGS__)
#define KE_WARN(...)		::Kengine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KE_INFO(...)		::Kengine::Log::GetClientLogger()->info(__VA_ARGS__)
#define KE_TRACE(...)		::Kengine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KE_FATAL(...)		::Kengine::Log::GetClientLogger()->critical(__VA_ARGS__)
