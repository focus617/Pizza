#include "pzpch.h"
#include "WindowsWindow.h"

#include "Pizza/Events/ApplicationEvent.h"
#include "Pizza/Events/MouseEvent.h"
#include "Pizza/Events/KeyEvent.h"

#include <glad/glad.h>

namespace Pizza {

    // To ensure that GLFW only can be initialized once
    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char* description)
    {
        PZ_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }


    Window* Window::Create(const WindowProps& props)
    {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        Init(props);
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        PZ_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        // Make sure to initialize GLFW only once, along with the first window
        if (!s_GLFWInitialized)
        {
            // TODO: glfwTerminate on system shutdown
            int success = glfwInit();
            PZ_CORE_ASSERT(success, "Could not intialize GLFW!");
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        
        //��һ��glfwWindow����Ϊ��ǰ�����ģ�һ��threadͬʱֻ��ӵ��һ�������ģ�
        //��ʡȥ��һЩ����ÿ�ζ�ָ��window���鷳����glfwSwapInterval()�����ĺ���ֻ������ǰContext
        glfwMakeContextCurrent(m_Window);

        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        PZ_CORE_ASSERT(status, "Failed to initialize Glad!");

        PZ_CORE_INFO("openGL version: {0}", glGetString(GL_VERSION));

        //�������ǰ���һ���û��Զ����ָ�뵽window��ǩ�����Ǹ�void*�������ĵ��������
        //һ���û��Լ�������������ڣ�glfw����������ָ�����κβ��������ǿ��԰Ѷ�Ӧ��
        //��Ϣ����ȥ
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        // Set GLFW callbacks
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                data.Width = width;
                data.Height = height;

                WindowResizeEvent event(width, height);
                data.EventCallback(event);
            });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                WindowCloseEvent event;
                data.EventCallback(event);
            });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

                switch (action)
                {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, 1);
                    data.EventCallback(event);
                    break;
                }
                }
            });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

                switch (action)
                {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                }
            });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

                MouseScrolledEvent event((float)xOffset, (float)yOffset);
                data.EventCallback(event);
            });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

                MouseMovedEvent event((float)xPos, (float)yPos);
                data.EventCallback(event);
            });
    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void WindowsWindow::OnUpdate()
    {
        //ÿ��updateʱ������ǰ�ڶ����е��¼�
        glfwPollEvents();

        //Swap��ָ��Framebuffer��̨֡����ǰ̨����Framebuffer��ǰ֡������̨��
        //�Ӷ��ﵽˢ����һ֡��Ŀ��
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        // If w/out brace, only 1 closest line will be executed
        // �����1/0�����ǿ�/�ص���˼��������һ֡Swap֮��Ҫ�ȶ��ٴ�Screen Update������
        // ����glfwSwapInterval�ڲ���װ�˶�Ӧƽ̨��vsync���������Ի����Ͼ��ǿ��ص���˼������
        // Ҫע����ǣ����ǿ��԰����interval����10��Ȼ���Ӵ���������޿�������ȻVSync on
        // �ɼ���VSync��ʵ����Ⱦ��֡��û���κι�ϵ��VSync������60ֻ֡����Ϊ�󲿷���ʾ��
        // ˢ����60HZ������Sync����
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return m_Data.VSync;
    }

}
