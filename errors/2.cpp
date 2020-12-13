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

void	writeLetter(char a)
{
	try
	{
		if (!((a >= 'a') && (a <= 'z') || (a >= 'A') && (a <= 'Z')))
			throw (SURPRISED_ERROR);
		if ((a == 's') || (a == 'S'))
			throw (SNEAKY_ERROR);
		cout << a << endl;
	}
	catch (Result SURPRISED_ERROR)
	{
		cout << "It's not a letter!! It's another symbol! STILL!!!" << endl;
	}
	catch (Result SNEAKY_ERROR)
	{
		cout << "I don't like the letter Ss try another one!" << endl;
	}
}
/*
Result	writeLetter(double a)
{
	return (ANGRY_ERROR);
}
*/
int		main()
{
	char	c = 's';

	writeLetter(c);
	writeLetter('a');
	writeLetter('\');
	return (NO_ERROR);
}
