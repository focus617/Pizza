#include "pzpch.h"
#include "Pizza/Renderer/RenderCommand.h"

namespace Pizza {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}