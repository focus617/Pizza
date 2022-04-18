#include <Pizza.h>

#include "imgui/imgui.h"

#include "Pizza/Events/ApplicationEvent.h"
#include "Pizza/Events/KeyEvent.h"
#include "Pizza/Events/MouseEvent.h"

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

    virtual void OnImGuiRender() override
    {
        ImGui::Begin("Test");
        ImGui::Text("Hello World");
        ImGui::End();
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
    }

    ~Sandbox()
    {

    }
};

Pizza::Application* Pizza::CreateApplication()
{
    return new Sandbox();
}
