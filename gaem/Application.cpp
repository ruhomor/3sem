#include "gaem.h"

static void		key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) // key -- код клавиши
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void		printUsage()
{
	std::cout << "Usage: ./Application OPTIONAL: {map size x} {map size y}\n";
}

static void		printWrong()
{
	std::cout << "Wrong Number of Arguments\n"; //TODO print to errorstream?
}

int		main(int argc, char **argv) //TODO map size
{
	GLFWwindow*		window;
	Map				gameMap;

	/* reading map size from command line */
	if (argc != 1)
	{
		if (argc == 3)
		{
			int		m = atoi(argv[1]), n = atoi(argv[2]);
			gameMap.resize(n, std::vector<int>(m));
			gameMap.setInit();
		}
		else
		{
			printWrong();
			printUsage();
			return (-2);
		}
	}

	if (!(gameMap.isInit()))
		gameMap.resize(MAPY, std::vector<int>(MAPX));

	/* initializing gameMap part2 */
	//TODO compiling algoes
	//create player entity out of algo

	gameMap.display(); //debug

	/* Initialize the library */
	if (!glfwInit())
		return (-1);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(WINX, WINY, "GAEM", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return (-1);
	}

	/* knopka */
	glfwSetKeyCallback(window, key_callback); //windows -- окно key_callback -- функция обрабатывающая кнопки

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
