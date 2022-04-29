#pragma once

#include "Pizza.h"

class ExampleLayer : public Pizza::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Pizza::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Pizza::Event& e) override;
private:
	Pizza::ShaderLibrary m_ShaderLibrary;
	Pizza::Ref<Pizza::Shader> m_Shader;
	Pizza::Ref<Pizza::VertexArray> m_VertexArray;

	Pizza::Ref<Pizza::Shader> m_FlatColorShader;
	Pizza::Ref<Pizza::VertexArray> m_SquareVA;

	Pizza::Ref<Pizza::Texture2D> m_Texture, m_ChernoLogoTexture;

	Pizza::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

