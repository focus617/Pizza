#include "pzpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Pizza {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}