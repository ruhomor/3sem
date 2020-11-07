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
	int				m = MAPX, n = MAPY;

	/* reading map size from command line */
	if (argc != 2)
	{
		if (argc == 4)
		{
			m = atoi(argv[2]);
			n = atoi(argv[3]);
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

	/* reading algorithms to playerTable */
	PlayerVec		playersTable(argv[1]);

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

	//DONE write game step
	/* game step */
	for (int j = 0; j < 1; j++)
	{
		std::cout << "STEP" << j << '\n';
		gameMap.display();
		//DONE write map to file map.txt
		gameMap.writeToFile(argv[1]);
		//DONE write playerinfo to file players.txt
		playersTable.writeToFile(argv[1]);
		//DONE write getNewAction which will get action from binaries
		int		alivePlayers = playersTable.getAlivePlayersNum();
		int		tmpAction;
		for (int i = 0; i < playersTable.size(); i++) //1 to skip no_algo
		{
			tmpAction = 0;
			//std::cout << i << '\n';
			if (playersTable[i].getAlive())
			{
				//std::cout << "getting action for: " + playersTable[i].getName() + '\n';
				playersTable[i].getNewAction(argv[1], alivePlayers, m, n);
				std::cout << "ALIVE PLAYERS NUMBER : " << alivePlayers << '\n';
				std::cout << playersTable[i].getAlgoName() << '\n';
				tmpAction = playersTable[i].getAction();
				std::cout << "ACTION: " << tmpAction << '\n';
				if ((tmpAction > 0) && (tmpAction < 5)) //0 1 2 3 4 are MOVE_UP MOVE_DOWN etc
					playersTable[i].updatePos(gameMap.move(playersTable[i].getId(), tmpAction));
			}
		}
		//DONE write move step
		//std::cout << "TableSize: " << playersTable.size() << '\n';
		for (int i = 0; i < playersTable.size(); i++)
		{
			if (playersTable[i].getAlive())
			{
				tmpAction = playersTable[i].getAction();
				int		hitId = gameMap.shoot(playersTable[i].getId(), tmpAction);
				if ((tmpAction > 4) && (tmpAction < 9))
				{
					playersTable.decreaseHealth(hitId);
					if (playersTable[hitId].getDied())
					{
						playersTable[i].plusScore(KILLSCORE);
						std::cout << playersTable[i].getAlgoName()
							<< " killed " << playersTable[hitId].getAlgoName();
					}
					else
					{
						playersTable[i].plusScore(SHOTSCORE);
						std::cout << playersTable[i].getAlgoName()
							<< " hit " << playersTable[hitId].getAlgoName();
					}
				}
			}
		}
		//DONE write shoot step

		for (int i = 0; i < playersTable.size(); i++)
		{
			std::pair<int, int>		corpse;

			if (playersTable[i].getDied())
			{
				corpse = gameMap.findPos(playersTable[i].getId());
				gameMap[corpse.second][corpse.first] = 0;
				playersTable[i].setDied(false);
			}
		}
	//DONE write remove dead people from map
	}
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


		float		SidePx = std::min(WINX / m, WINY / n); //Px
		float		xPx = 2.0 / WINX * SidePx, yPx = 2.0 / WINY * SidePx; //Doli


		glBegin(GL_LINES);
		//horizontal

		for (int i = 0; i <= n; i++)
		{
			float		start = -1.0f;

			start += i * yPx;
			glVertex2f(-1.0f, start);
			glVertex2f(m * xPx - 1.0f, start);
    }

    //vertical
    for (int i = 0; i <= m; i++)
		{
			float		start = -1.0f;

			start += i * xPx;
			glVertex2f(start, -1.0f);
			glVertex2f(start, n * yPx - 1.0f);
    }
    glEnd();

		//Draw players
		for (int i = 0; i < 1 /*playersTable.size()*/; i++) //1 to skip no_algo
		{
			int x = playersTable[i].getX();
			int y = playersTable[i].getY();

			float xPos = (2 * x + 1) / 2 * xPx - 1.0f;
			float yPos = (2 * (n - y) - 1) / 2 * yPx - 1.0f;
			float r = xPx / 2;

			printf("%f - x, %f - y\n", xPos, yPos);

			DrawCircle(xPos, yPos, r);

		}


		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
