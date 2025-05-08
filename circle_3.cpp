#include <iostream>
#include <GL/glut.h>
using namespace std;
void init() {
 glClearColor(0, 0, 0, 0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-450, 450, -450, 450);
}
void display() {
 int R, X, Y, pk, PX, PY;
 cout << "\nEnter Radius: ";
 cin >> R;
 cout << "\nEnter Center Coordinates (X, Y): ";
 cin >> X >> Y;
 PX = 0;
 PY = R;
 pk = 3 - 2 * R;
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1, 1, 1);
 glBegin(GL_LINES);
 glVertex2f(450, 0);
 glVertex2f(-450, 0);
 glVertex2f(0, 450);
 glVertex2f(0, -450);
 glEnd();
 glColor3f(1, 0.5, 0);
 glBegin(GL_POINTS);
 while (PY >= PX) {
 glVertex2f(PX + X, PY + Y); // Octant 1
 glVertex2f(-PX + X, PY + Y); // Octant 2
 glVertex2f(PX + X, -PY + Y); // Octant 3
 glVertex2f(-PX + X, -PY + Y);// Octant 4
 glVertex2f(PY + X, PX + Y); // Octant 5
 glVertex2f(-PY + X, PX + Y); // Octant 6
 glVertex2f(PY + X, -PX + Y); // Octant 7
 glVertex2f(-PY + X, -PX + Y);// Octant 8
 if (pk < 0) pk += 4 * PX + 6;
 else {
 pk += 4 * (PX - PY) + 10;
 PY--;
 }
 PX++;
 }
 glEnd();
 glFlush();
}
int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
 glutInitWindowSize(900, 900);
 glutInitWindowPosition(300, 0);
 glutCreateWindow("Bresenham Circle");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}

// for o/p - g++ circle_3.cpp -o circle -framework OpenGL -framework GLUT
//.    ./circle

//Points - radius-100
//Origin points - 0 0