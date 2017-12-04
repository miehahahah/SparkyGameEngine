#include "window.h"

namespace sparky {
	namespace graphics {

		void windowResize(GLFWwindow *window, int width, int height);

		Window::Window(const char* name, int width, int height)
		{
			m_Name = name;
			m_Width = width;
			m_Height = height;
			if (!init())
				glfwTerminate();
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize glfw" << std::endl;
				return false;
			}
				
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);
			if (!m_Window)
			{
				std::cout << "Failed to create the window"<<std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowSizeCallback(m_Window, windowResize);
			return true;

		}

		bool Window::closed() const 
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void Window::update()
		{
			glfwPollEvents();
			//glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			//glViewport(0, 0, m_Width, m_Height);
			glfwSwapBuffers(m_Window);
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void windowResize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

	}
}