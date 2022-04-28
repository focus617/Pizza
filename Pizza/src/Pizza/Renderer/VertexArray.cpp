#include "pzpch.h"
#include "Pizza/Renderer/VertexArray.h"

#include "Pizza/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Pizza {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    PZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		PZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}