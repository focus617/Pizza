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
        if (Pizza::Input::IsKeyPressed(PZ_KEY_TAB))
            PZ_TRACE("Tab key is pressed (poll)!");
    }

    void OnEvent(Pizza::Event& event) override
    {
        if (event.GetEventType() == Pizza::EventType::KeyPressed)
        {
            Pizza::KeyPressedEvent& e = (Pizza::KeyPressedEvent&)event;
            if (e.GetKeyCode() == PZ_KEY_TAB)
                PZ_TRACE("Tab key is pressed (event)!");
            PZ_TRACE("{0}", (char)e.GetKeyCode());
        }
    }

};

class Sandbox : public Pizza::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Pizza::ImGuiLayer());
    }

    ~Sandbox()
    {

    }
};

Pizza::Application* Pizza::CreateApplication()
{
    return new Sandbox();
}
