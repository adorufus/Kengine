#include "hzpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Kengine {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run() {
		WindowResizeEvent l(1280, 720);
		KE_TRACE(l);

		while (true);
	}
}
