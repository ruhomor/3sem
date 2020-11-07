#include "graphics.h"

void DrawCircle(float x, float y, float r)
{
  glClearColor(1.0, 1.0, 1.0, 0);

  float prevX = x;
  float prevY = y - r;

  for (int i = 0; i <= STEPS; i++)
  {
    float newX = r * sin(ANGLE * i);
    float newY = -r * cos(ANGLE * i);

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0.5, 0);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(prevX, prevY, 0.0f);
    glVertex3f(newX, newY, 0.0f);
    glEnd();

    prevX = newX;
    prevY = newY;
  }
}
