#pragma once

#include "Pizza/Core.h"

namespace Pizza {

	/**
	* Input是一个singleton的接口，不需要直接把这个类实例出来。
	* 所有的public函数都是静态函数，并且只是protected函数实现的一个wrap；
	* 所有的protected函数都是纯虚函数/抽象函数，这也意味着派生类必须根据平台做不同的实现。
	* 而高层逻辑在调用时，则不用考虑具体实现，直接从这里调用静态函数即可。
	*/
	class PIZZA_API Input
	{
	public:
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

