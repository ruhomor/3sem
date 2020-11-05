#include "gaem.h"

static void		key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) // key -- код клавиши
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void		printUsage()
{
	std::cout << "Usage: ./Application {algo folder name} OPTIONAL: {map size x} {map size y}\n";
}

static void		printWrong()
{
	std::cout << "Wrong Number of Arguments\n"; //TODO print to errorstream?
}

int		main(int argc, char **argv) //TODO map size x[2] y[3] algofolder [1]
{
	GLFWwindow*		window;
	Map				gameMap;

	/* reading algorithms to playerTable */
	PlayerVec		playersTable(argv[1]);

	/* reading map size from command line */
	if (argc != 2)
	{
		if (argc == 4)
		{
			int		m = atoi(argv[2]), n = atoi(argv[3]);
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

	//DONE compiling algoes
	//DONE create player entity out of algo
	//DONE MAP PLACER FUNCTION

	gameMap.display(); //debug

	/* placing players on map */
	for (int i = 0; i < playersTable.size(); i++)
	{
		gameMap.randPlace(playersTable[i].getId());
		gameMap.display(); //debug
	}

	//TODO write game step
	/* game step */
	//TODO write map to file map.txt
	gameMap.writeToFile(argv[1]);
	//TODO write playerinfo to file players.txt
	playersTable.writeToFile(argv[1]);
	//TODO write getAction which will get action from binaries
	std::cout << "coco" << '\n';
	for(int i = 0; i < playersTable.size(); i++)
	{
		std::cout << "coco" << '\n';
		playersTable[i].getAction(argv[1]);
	}
	//TODO write move step

	//TODO write shoot step

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
