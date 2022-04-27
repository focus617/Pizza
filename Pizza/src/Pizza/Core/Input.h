#pragma once

#include "Pizza/Core/Core.h"

namespace Pizza {

	/**
	* Input��һ��singleton�Ľӿڣ�����Ҫֱ�Ӱ������ʵ��������
	* ���е�public�������Ǿ�̬����������ֻ��protected����ʵ�ֵ�һ��wrap��
	* ���е�protected�������Ǵ��麯��/����������Ҳ��ζ��������������ƽ̨����ͬ��ʵ�֡�
	* ���߲��߼��ڵ���ʱ�����ÿ��Ǿ���ʵ�֣�ֱ�Ӵ�������þ�̬�������ɡ�
	*/
	class PIZZA_API Input
	{
	protected:
		Input() = default;
	public:
		Input(const Input&) = delete;
		Input& operator=(const Input&) = delete;

		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }
		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(int Keycode) = 0;

		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
	private:
		static Input* s_Instance;
	};

}
