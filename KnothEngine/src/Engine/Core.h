#pragma once

#ifdef KNOTH_PLATFORM_WINDOWS
	#ifdef KNOTH_BUILD_DLL
		#define KNOTH_API __declspec(dllexport)
	#else
		#define KNOTH_API __declspec(dllimport)
	#endif
#else
	#error Only support windows
#endif

#define BIT(x) (1 << x)