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
		//��һ��glfwWindow����Ϊ��ǰ�����ģ�һ��threadͬʱֻ��ӵ��һ�������ģ�
		//��ʡȥ��һЩ����ÿ�ζ�ָ��window���鷳����glfwSwapInterval()�����ĺ���ֻ������ǰContext
		glfwMakeContextCurrent(m_WindowHandle);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PZ_CORE_ASSERT(status, "Failed to initialize Glad!");

		PZ_CORE_INFO("OpenGL Info :");
		PZ_CORE_INFO("   Vendor   :   {0}", glGetString(GL_VENDOR));
		PZ_CORE_INFO("   Renderer :   {0}", glGetString(GL_RENDERER));
		PZ_CORE_INFO("   Version  :   {0}", glGetString(GL_VERSION));
	
	#ifdef PZ_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		PZ_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Pizza requires at least OpenGL version 4.5!");
	#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		//Swap��ָ��Framebuffer��̨֡����ǰ̨����Framebuffer��ǰ֡������̨��
		//�Ӷ��ﵽˢ����һ֡��Ŀ��
		glfwSwapBuffers(m_WindowHandle);
	}

}