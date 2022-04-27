#pragma once

#include "Pizza.h"

class Sandbox2D : public Pizza::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Pizza::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Pizza::Event& e) override;
private:
	Pizza::OrthographicCameraController m_CameraController;
	
	// Temp
	Pizza::Ref<Pizza::VertexArray> m_SquareVA;
	Pizza::Ref<Pizza::Shader> m_FlatColorShader;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};