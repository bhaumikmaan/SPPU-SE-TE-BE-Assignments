#include <bits/stdc++.h>
#include <GL/glut.h>

#define w 700
#define h 700

using namespace std;

GLint x_1,y_1,x_2,y_2;
void setpixel(GLint x,GLint y)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}
class line
{
public:
    void DDA(int choice)
    {
        GLfloat dx,dy,steps,x,y;
        GLfloat xinc,yinc;
        dx=x_2-x_1;
        dy=y_2-y_1;
        if(abs(dx)>=abs(dy))
            steps=dx;
        else
            steps=dy;
        xinc=(float)dx/abs(steps);
        yinc=(float)dy/abs(steps);
        x=x_1;
        y=y_1;
        setpixel(x,y);
        for(int i=0; i<abs(steps); i++)
        {
            x+=xinc;
            y+=yinc;
            x_1=x+0.5;
            y_1=y+0.5;
            if(choice==1)
            {
                setpixel(x_1,y_1);
            }
            else if(choice==2 && i%6==0)
            {
                setpixel(x_1,y_1);
            }
            else if(choice==3 && i%10<5)
            {
                setpixel(x_1,y_1);
            }
            else if(choice==4)
            {
                glPointSize(4.0);
                setpixel(x_1,y_1);
            }

        }

    }
    void Bresenham(int choice)
    {
        GLint dx=abs(x_1-x_2),dy=abs(y_1-y_2);


        bool f=dy>dx;

        if(f)
        {
            GLint p=2*dx-dy;
            if(y_1>y_2)
            {
                swap(x_1,x_2);
                swap(y_1,y_2);
            }
            GLint x,y,yend;
            x=x_1;
            y=y_1;
            yend=y_2;
            setpixel(x,y);
            int i=0;
            while (y<yend)
            {
                y++;
                if(p<0)
                    p+=2*dx;
                else
                {
                    if(x_2<x_1)
                        x--;
                    else
                        x++;
                    p+=2*(dx-dy);
                }
                if(choice==5)
                {
                    setpixel(x,y);
                }
                else if(choice==6 && i%6==0)
                {
                    setpixel(x,y);
                }
                else if(choice==7 && i%10<5)
                {
                    setpixel(x,y);
                }
                else if(choice==8)
                {
                    glPointSize(4.0);
                    setpixel(x,y);
                }
                i++;

            }
        }
        else
        {
            GLint p=2*dy-dx;
            if(x_1>x_2)
            {
                GLint temp=x_2,temp2=y_2;
                x_2=x_1;
                y_2=y_1;
                x_1=temp;
                y_1=temp2;
            }
            GLint x,y,xend;
            x=x_1;
            y=y_1;
            xend=x_2;
            setpixel(x,y);
            int i=0;
            while (x<xend)
            {
                x++;
                if(p<0)
                    p+=2*dy;
                else
                {
                    if(y_2<y_1)
                        y--;
                    else
                        y++;
                    p+=2*(dy-dx);
                }
                if(choice==5)
                {
                    setpixel(x,y);
                }
                else if(choice==6 && i%6==0)
                {
                    setpixel(x,y);
                }
                else if(choice==7 && i%10<5)
                {
                    setpixel(x,y);
                }
                else if(choice==8)
                {
                    glPointSize(4.0);
                    setpixel(x,y);
                }
                i++;

            }
        }
    }
};
line obj;



void initialize()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
void choice()
{
    int i;
    glPointSize(2.0);
    for(i=-w; i<w; i++)
    {
        setpixel(0,i);
        setpixel(i,0);
    }
}

void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN)
    {
        if(button==GLUT_LEFT_BUTTON)
        {
            x_1=x-350;
            y_1=350-y;
            glPointSize(2.0);
            setpixel(x_1,y_1);
        }
        else if(button==GLUT_RIGHT_BUTTON)
        {
            x_2=x-350;
            y_2=350-y;
            glPointSize(2.0);
            setpixel(x_2,y_2);
        }
    }
}

void keyboard(unsigned char key,int x,int y)
{
    if(key==27)
    {
        exit(0);
    }
}

void menu(int choice)
{
    if(choice==9)
        exit(0);
    if(choice<5)
        obj.DDA(choice);
    else
        obj.Bresenham(choice);
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(w,h);
    glutInitWindowPosition(100,0);
    glutCreateWindow("line drawing");
    initialize();
    glutDisplayFunc(choice);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutCreateMenu(menu);
    glutAddMenuEntry("DDA simple",1);
    glutAddMenuEntry("DDA dotted",2);
    glutAddMenuEntry("DDA dashed",3);
    glutAddMenuEntry("DDA solid",4);
    glutAddMenuEntry("BRESENHAM simple",5);
    glutAddMenuEntry("BRESENHAM dotted",6);
    glutAddMenuEntry("BRESENHAM dashed",7);
    glutAddMenuEntry("BRESENHAM solid",8);
    glutAddMenuEntry("EXIT",9);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    glutMainLoop();
    return 0;
}
