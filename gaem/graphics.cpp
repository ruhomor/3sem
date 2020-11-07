#include "graphics.h"

void	DrawEllipse(float radiusX, float radiusY, float x, float y, Color c)
{
	int		i;

	//glBegin(GL_LINE_LOOP);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(c.r, c.g, c.b);
	glVertex2f(x - 1.0f, y - 1.0f);
	for(i = 0;i < 361; i++)
	{
		float rad = i * DEG2RAD;
		glVertex2f(cos(rad) * radiusX + x - 1.0f,
				sin(rad) * radiusY + y - 1.0f);
	}
	glEnd();
}
