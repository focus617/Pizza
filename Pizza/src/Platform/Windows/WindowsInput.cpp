#include "pzpch.h"
#include "Platform/Windows/WindowsInput.h"

#include "Pizza/Core/Application.h"
#include <GLFW/glfw3.h>

namespace Pizza {

	Scope<Input> Input::s_Instance = CreateScope<WindowsInput>();

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		// glfwGetKey�����ҵ�����window�У����һ�������ָ��Key��״̬
		auto state = glfwGetKey(window, keycode);
		// �ж��Ƿ��ǰ��»��ظ�״̬��״̬�������֣��ɿ������£��ظ���
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		// ��ȡ����window������position
		glfwGetCursorPos(window, &xpos, &ypos);

		return { (float)xpos, (float)ypos };
	}

	float WindowsInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return x;
	}

	float WindowsInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return y;
	}

}