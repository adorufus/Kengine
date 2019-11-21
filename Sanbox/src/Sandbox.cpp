#include <Kengine.h>

class Sandbox : public Kengine::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Kengine::Application* Kengine::CreateApplication() {
	return new Sandbox;
}

