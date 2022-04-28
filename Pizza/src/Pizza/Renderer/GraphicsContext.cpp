#include "pzpch.h"
#include "Pizza/Renderer/GraphicsContext.h"

#include "Pizza/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Pizza {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    PZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		PZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}