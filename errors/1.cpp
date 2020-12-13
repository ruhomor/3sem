#include <iostream>
using namespace std;

enum Result
{
	NO_ERROR = 0,
	SAD_ERROR = -1,
	ANGRY_ERROR = -2,
	FRUSTRATED_ERROR = -3,
	SNEAKY_ERROR = -4,
	TIRED_ERROR = -5,
	SURPRISED_ERROR = -6,
	SHY_ERROR = -7,
};

Result	writeLetter(char a)
{
	if ((a >= 'a') && (a <= 'z') || (a >= 'A') && (a <= 'Z'))
	{
		cout << a << endl;
		return (NO_ERROR);
	}
	else
		return (SURPRISED_ERROR);
}

Result	writeLetter(double a)
{
	return (ANGRY_ERROR);
}

int		main()
{
	char	c = 'a';

	switch (writeLetter(c))
	{
		case (NO_ERROR):
			return (NO_ERROR);
		case (SURPRISED_ERROR):
			cout << "it's not a letter! It's another symbol!" << endl;
			return (SURPRISED_ERROR);
		case (ANGRY_ERROR):
			cout << "it's not a letter! It's floating point number!" << endl;
			return (ANGRY_ERROR);
	}
	return (SHY_ERROR);
}
