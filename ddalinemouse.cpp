#include<iostream>
#include<GL/glut.h>
using namespace std;



void Init()
{
    glClearColor(0,0,0,0);
    
    glColor3f(0,1,0);
    gluOrtho2D(0,640,0,480);
    glClear(GL_COLOR_BUFFER_BIT);
}


int sign(float a){


    if(a==0){
        return 0;
    }
    if(a>0){

        return 1;
    }
    return -1;

}

void DDA_LINE(int x_1,int y_1,int x_2,int y_2){


    float dx,dy,length;
    dx = x_2-x_1;
    dy = y_2-y_1;

    if(abs(dx) >= abs(dy)){

        length = abs(dx);
    }
    else{
        length = abs(dy);
    }

    float xin, yin;
    xin = dx/length;
    yin = dy/length;

    float x,y;

    x = x_1 + 0.5 * sign(xin);
    y = y_1 + 0.5 * sign(yin);

    int i=0;
    int cnt =1;
    while(i<=length){
       
            glBegin(GL_POINTS);
                glVertex2i(x,y);
            glEnd();
        

        x = x + xin;
        y = y + yin;
        i++ ;

    }

    glFlush();

}

void display()
{
    DDA_LINE(0,240,640,240);
   


    glFlush();
}
void mymouse(int b,int s, int x, int y)
{
    static int x_s,y_s,x_e,y_e,pt=0;
    if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN)
    {
        if(pt==0)
        {
            x_s =x;
            y_s =480 - y;
            pt++;

            glBegin(GL_POINTS);
                glVertex2i(x_s,y_s);
            glEnd();
        }
        else
        {
            x_e=x;
            y_e=480-y;
            cout<<"\n x_1_click "<<x_s<<" y_1_click "<<y_s;
            cout<<"\n x_2_click "<<x_e<<" y_2_click "<<y_e<<"\n";
            glBegin(GL_POINTS);
                glVertex2i(x_e,y_e);
            glEnd();
            DDA_LINE(x_s,y_s,x_e,y_e);
            

        }


    }
    else if(b==GLUT_RIGHT_BUTTON && s==GLUT_DOWN)
        {
            pt=0;
        }
    glFlush();
}





int main(int argc ,char **argv)
{

    cout<<"dda mouse simple";
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);
    glutCreateWindow("DDA-Line");
    Init();
    glutDisplayFunc(display);
    glutMouseFunc(mymouse);

    glutMainLoop();
    return 0;

}

