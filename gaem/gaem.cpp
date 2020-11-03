#include <iostream>
#include <GLFW3/glfw>

static void		key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) // key -- код клавиши
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int		main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return (-1);

	/* knopka */
	glfwSetKeyCallback(window, key_callback); //windows -- окно key_callback -- функция обрабатывающая кнопки

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "GAEM", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return (-1);
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
