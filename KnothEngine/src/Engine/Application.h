#pragma once

#include "Core.h"

namespace Knoth {
	class KNOTH_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}


