#pragma once

#include "Pizza/Core.h"
#include "Pizza/Events/Event.h"

namespace Pizza {

	class PIZZA_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}				// �������Layer
		virtual void OnEvent(Event& event) {}	// ��������¼�������ɶ�Ӧ��ת��

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}