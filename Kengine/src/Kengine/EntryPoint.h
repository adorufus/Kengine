#pragma once


extern Kengine::Application* Kengine::CreateApplication();
int main(int argc, char** argv) {
	Kengine::Log::Init();
	KE_CORE_WARN("initialize log");
	KE_INFO("initialize log from client");

	printf("starting engine");
	auto app = Kengine::CreateApplication();
	app->Run();
	delete app;
}