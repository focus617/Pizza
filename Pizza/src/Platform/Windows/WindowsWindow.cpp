#include "pzpch.h"
#include "WindowsWindow.h"

#include "Pizza/Events/ApplicationEvent.h"
#include "Pizza/Events/MouseEvent.h"
#include "Pizza/Events/KeyEvent.h"

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
        
        //将一个glfwWindow设置为当前上下文，一个thread同时只能拥有一个上下文，
        //这省去了一些函数每次都指定window的麻烦，像glfwSwapInterval()这样的函数只操作当前Context
        glfwMakeContextCurrent(m_Window);

        //本质上是绑定了一个用户自定义的指针到window，签名里是个void*，根据文档，这就是
        //一个用户自己爱干嘛干嘛的入口，glfw本身不会对这个指针做任何操作，我们可以把对应的
        //信息传进去
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
        //每次update时，处理当前在队列中的事件
        glfwPollEvents();

        //Swap是指把Framebuffer后台帧换到前台，把Framebuffer当前帧换到后台，
        //从而达到刷新下一帧的目的
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        // If w/out brace, only 1 closest line will be executed
        // 这里的1/0并不是开/关的意思，而是下一帧Swap之间要等多少次Screen Update。。。
        // 但是glfwSwapInterval内部封装了对应平台的vsync函数，所以基本上就是开关的意思。。。
        // 要注意的是，我们可以把这个interval开成10，然后视窗看起来会巨卡，但依然VSync on
        // 可见，VSync跟实际渲染的帧数没有任何关系，VSync看似锁60帧只是因为大部分显示器
        // 刷新率60HZ，被“Sync”了
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
