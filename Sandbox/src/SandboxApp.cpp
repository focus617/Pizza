#include <Pizza.h>

class ExampleLayer : public Pizza::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		PZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Pizza::Event& event) override
	{
		PZ_TRACE("{0}", event);
	}

};

class Sandbox : public Pizza::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Pizza::Application* Pizza::CreateApplication()
{
	return new Sandbox();
}
