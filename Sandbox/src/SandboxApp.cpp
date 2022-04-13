#include <Pizza.h>

class Sandbox : public Pizza::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Pizza::Application* Pizza::CreateApplication()
{
	return new Sandbox();
}