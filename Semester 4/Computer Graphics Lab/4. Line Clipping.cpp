#include<GL/glut.h>
#include<stdio.h>
#include<iostream>
using namespace std;

float xmin=-100;  float ymin=-100;
float xmax=100;  float ymax=100;
float xd1,yd1,xd2,yd2;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin,ymin);  glVertex2i(xmin,ymax);
    glVertex2i(xmax,ymax);  glVertex2i(xmax,ymin);
    glEnd();
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2i(xd1,yd1);  glVertex2i(xd2,yd2);
    glEnd();  glFlush();
}
void init(void)
{
    glClearColor(0.0,0,1,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300,300,-300,300);
}
int orr(float x,float y)
{
    int c=0;
    if(y>ymax)c=8;
    if(y<ymin)c=4;
    if(x>xmax)c=c|2;
    if(x<xmin)c=c|1;
    return c;
}

void cohenClip(float x1,float y1,float x2,float y2)
{
    int c1=orr(x1,y1);
    int c2=orr(x2,y2);
    float m=(y2-y1)/(x2-x1);
while((c1|c2)>0) {
    if((c1 & c2)>0) {   exit(0);   }
    float xi=x1;float yi=y1;  int c=c1;
    if(c==0)  
    {
        c=c2;  xi=x2;  yi=y2;  
    }
    float x,y;
    if((c & 8)>0)  {
        y=ymax;
        x=xi+ 1.0/m*(ymax-yi);
    }
    else if((c & 4)>0){
        y=ymin;
        x=xi+1.0/m*(ymin-yi);
    }
    else if((c & 2)>0)
    {  x=xmax;
        y=yi+m*(xmax-xi);
    }
    else if((c & 1)>0)
    {  x=xmin;
        y=yi+m*(xmin-xi);
    }
    if(c==c1)
    {  xd1=x;  yd1=y;
        c1=orr(xd1,yd1);  }
    if(c==c2)
    {   xd2=x;   yd2=y;
        c2=orr(xd2,yd2);  }
    }
display();
}
void mykey(unsigned char key,int x,int y)
{
    if(key=='c'|| 'C')
    {  
        cout<<"Clipped"<<endl;
        cohenClip(xd1,yd1,xd2,yd2);
        glFlush();  
    }
}
void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON){
        cout<<"Clipped"<<endl;
        cohenClip(xd1,yd1,xd2,yd2);
        glFlush();  
    }
        glutPostRedisplay();
}
int main(int argc,char** argv)
{
    cout<<"The screen is divided into four quadrants from -300 to 300 on both axis \nlimit the coordinates accordingly\nthe window is from -100 to 100 on both axis\n \nEnter line co-ordinates: \n";
    cin>>xd1>>yd1>>xd2>>yd2;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(450,150);
    glutCreateWindow("Clipping-4244");
    cout<<"click left mouse button to clip"<<endl;
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(mykey);
    init();
    glutMainLoop();
    return 0;
}
