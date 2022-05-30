#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;
#define w 500
#define h 500

void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
}

void setpixel(GLint x, GLint y)
{
    glColor3f(0.0,0.0,1.0);
    glPointSize(2.0);
    glBegin (GL_POINTS);   glVertex2f(x,y);
    glEnd();  glFlush();
}
float mati[30][2],mato[30][2];
int k=0,c; 

class trans
{
int transl[2][2];

public:
int mul(float s[2][2])
 {
    int i,j,k;   float sum;
    for(i=0;i<c;i++) {
        for(j=0;j<2;j++) 
        {
            sum=0;
            for(k=0;k<2;k++)
                sum=sum+mati[i][k]*s[k][j];
            mato[i][j]=sum;  
        }
     }
    return mato[30][2];  
}
void plot(float m[][2])
 {
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<c;i++)
    glVertex2f(m[i][0],m[i][1]);
    glEnd();  glFlush();
}
void translation(float tx,float ty) {
    int i;
    for (i=0;i<c;i++) {
        mato [i][0]=mati[i][0] + tx;
        mato[i][1]=mati[i][1] + ty; 
    }
}
void scaling()
 {
    float scale[2][2];
    int i;  float sx,sy;
    cout<<"\nScaling:\nEnterSx factor::";
    cin>>sx;
    cout<<"\nEnterSy factor::";
    cin>>sy;
    scale[0][0]=sx;
    scale[0][1]=0;
    scale[1][0]=0;
    scale[1][1]=sy;
    mul(scale);
    plot(mato); 
}

void rotation() {
    int rot;
    float angle,rota[2][2];
    cout<<"\nRotation:\nEnter angle:";
    cin>>angle;
    angle=(3.14*angle)/180;
    cout<<"1.For Anti-Clockwise rotation\n2.For Clockwise rotation\nEnter your choice::";
    cin>>rot;
    switch(rot){
    case 1 :
        rota[0][0]=cos(angle);
        rota[0][1]=-sin(angle);
        rota[1][0]=sin(angle);
        rota[1][1]=cos(angle);
        break;
    case 2 :
        rota[0][0]=cos(angle);
        rota[0][1]=sin(angle);
        rota[1][0]=-sin(angle);
        rota[1][1]=cos(angle);
        break;
    default:cout<<"\nenter valid option";
    exit(0);  
    }
    mul(rota);
}
void reflection() {
    char axis;
    int i;
    cout<<"\nEnter reflection axis(x/y):";
    cin>>axis;
    glBegin(GL_LINE_LOOP);
    if(axis=='x'||axis=='X')  
        {
        for(i=0;i<c;i++) {
        glVertex2i(round(mati[i][0]),round(mati[i][1] * -1));   }
      }
    else if(axis=='y'||axis=='Y') 
    {
        for(i=0;i<c;i++)  {
        glVertex2i(round(mati[i][0] * -1), round(mati[i][1]));   }
    }
    glEnd();
    }
}t;

void menu(int c)
{
    float tx,ty;
    if(c==1)
    {
        cout<<"\nTranslation->\nEntertx factor:";
        cin>>tx;
        cout<<"\nEnterty factor:";
        cin>>ty;
        t.translation(tx,ty);
        t.plot(mato);
        cout<<"Translation Done\n";
    }
    else if(c==2)
    {
        t.scaling();
        cout<<"Scaling Done\n";
    }
    else if(c==3)
    {
        t.rotation();
        t.plot(mato);
        cout<<"Rotation Done\n";
    }
    else if(c==4)
    {
        t.reflection();
        t.plot(mati);
        cout<<"Reflection Done\n";
    }
    else if(c==5)
    {
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }
    else if(c==6)
    {
        exit(1);
    }
    else
    {
        cout<<"\nplease enter correct value";
    }
}
void mouse(int button,int state,int x,int y)
{
    int x1,y1,p;
    if(button==GLUT_LEFT_BUTTON && state== GLUT_DOWN) {
        mati[k][0]=(float)(x-250);
        mati[k][1]=(float)(250-y);
        glColor3f(1.0,0.0,0.0);
        glPointSize(3.0);
        glBegin(GL_POINTS);
        glVertex2f(mati[k][0],mati[k][1]);
        glEnd();
        k++;
        glFlush();
    }
    if(button==GLUT_RIGHT_BUTTON && state== GLUT_DOWN) {
        glColor3f(0.0,0.0,1.0);
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<k;i++)
        glVertex2f(mati[i][0],mati[i][1]);
        glEnd();
        c=k;
        k=0;
        glFlush();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(w,h);
    glutInitWindowPosition(450,150);
    glutCreateWindow("2D Transformations");
    cout<<"Left button to plot points\nRight button to make polygon\nMiddle button for menu\n";
    glutDisplayFunc(init);
    glutMouseFunc(mouse);
    glutCreateMenu(menu);
    glutAddMenuEntry("TRANSLATION",1);
    glutAddMenuEntry("SCALING",2);
    glutAddMenuEntry("ROTATION",3);
    glutAddMenuEntry("REFLECTION",4);
    glutAddMenuEntry("CLEAR",5);
    glutAddMenuEntry("EXIT",6);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    glutMainLoop();
    return 0;
}
