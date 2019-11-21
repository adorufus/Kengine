#pragma once
#include "Core.h"

namespace Kengine {

	class KENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in client
	Application* CreateApplication();

}

