#pragma once


extern Kengine::Application* Kengine::CreateApplication();
int main(int argc, char** argv) {
	printf("starting engine");
	auto app = Kengine::CreateApplication();
	app->Run();
	delete app;
}