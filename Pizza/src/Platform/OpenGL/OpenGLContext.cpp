#include "pzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Pizza {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		PZ_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		//将一个glfwWindow设置为当前上下文，一个thread同时只能拥有一个上下文，
		//这省去了一些函数每次都指定window的麻烦，像glfwSwapInterval()这样的函数只操作当前Context
		glfwMakeContextCurrent(m_WindowHandle);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PZ_CORE_ASSERT(status, "Failed to initialize Glad!");

		PZ_CORE_INFO("OpenGL Info:");
		PZ_CORE_INFO("     Vendor:   {0}", glGetString(GL_VENDOR));
		PZ_CORE_INFO("   Renderer:   {0}", glGetString(GL_RENDERER));
		PZ_CORE_INFO("    Version:   {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		//Swap是指把Framebuffer后台帧换到前台，把Framebuffer当前帧换到后台，
		//从而达到刷新下一帧的目的
		glfwSwapBuffers(m_WindowHandle);
	}

}