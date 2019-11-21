#pragma once

#ifdef KE_PLATFORM_WINDOWS
	#ifdef KE_BUILD_DLL
		#define KENGINE_API __declspec(dllexport)
	#else
		#define KENGINE_API __declspec(dllimport)
	#endif
#else
	#error Kengine Only Support Windows!
#endif