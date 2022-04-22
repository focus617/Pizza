#pragma once

#include "Pizza/Core.h"
#include "Pizza/Core/Timestep.h"
#include "Pizza/Events/Event.h"

namespace Pizza {

	class PIZZA_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}				// 负责更新Layer
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}	// 负责接收事件，并完成对应的转发

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}