#include "graphics.h"

void	DrawEllipse(float radiusX, float radiusY, float x, float y)
{
	int		i;

	glBegin(GL_LINE_LOOP);
	for(i = 0;i < 360; i++)
	{
		float rad = i * DEG2RAD;
		glVertex2f(cos(rad) * radiusX + x - 1.0f,
				sin(rad) * radiusY + y - 1.0f);
	}
	glEnd();
}
