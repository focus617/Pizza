#include <Pizza.h>
#include <Pizza/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public Pizza::Application
{
public:
	Sandbox()
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

    ~Sandbox()
    {

    }
};

Pizza::Application* Pizza::CreateApplication()
{
    return new Sandbox();
}
