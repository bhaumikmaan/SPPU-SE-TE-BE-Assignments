#include<GL/glut.h>
#include<iostream>
#include <stdlib.h>
#include<math.h>
using namespace std;
#define w 500
#define h 500
GLint xc, yc, xr, yr;

void setpixel(GLint x, GLint y)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();  glFlush();
}
void initialize()
{
    glClearColor(1.0,1.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
void choice()
{
    int i;
    glPointSize(2.0);
    for(i = -w; i < w; i++){
        setpixel(0,i);  setpixel(i,0);
    }
}
class Circle
{
public:
void drawCircle(int xc, int yc, int x, int y)
{
    setpixel(xc+x, yc+y);  setpixel(xc-x, yc+y);
    setpixel(xc+x, yc-y);  setpixel(xc-x, yc-y);
    setpixel(xc+y, yc+x); setpixel(xc-y, yc+x);
    setpixel(xc+y, yc-x);  setpixel(xc-y, yc-x);
 }
void BresenhamCircle()
{
    int r = sqrt( ((xc-xr)*(xc-xr)) + ((yc-yr)*(yc-yr)) );
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x)
    {
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10; 
            }
        else
            d = d + 4 * x + 6;
        drawCircle(xc, yc, x, y);}
    }
};
Circle obj;

void keyboard(unsigned char key, int x, int y)
{
    if( key == 27){
        exit(0); }
}
void menu(int item){
    if( item == 1 )
    {
        obj.BresenhamCircle();
    }
    if( item == 2 ){  exit(0);  }
}
void mouse(int button, int state, int x, int y){
  if( state == GLUT_DOWN )
    {
      if( button == GLUT_LEFT_BUTTON ){
      xc = x - 250;  yc = 250 - y;
      glPointSize(2.0);
      setpixel(xc,yc);
        }
      else
      {
      xr = x-250;  yr = 250-y;
      glPointSize(2.0);  setpixel(xr,yr); 
      }
    }
}
// left click is for centre coordinates , right click coordinate will be used to determine the radius
int main(int argc, char **argv)
{
  glutInit(&argc,argv);;
  glutInitWindowSize(w,h);
  glutInitWindowPosition(100,0);
  glutCreateWindow("Assignment 2");
  initialize();
  glutDisplayFunc(choice);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  glutCreateMenu(menu);
  glutAddMenuEntry("CIRCLE", 1);
  glutAddMenuEntry("EXIT",2);
  glutAttachMenu(GLUT_MIDDLE_BUTTON);
  glutMainLoop();
  return 0;
}
