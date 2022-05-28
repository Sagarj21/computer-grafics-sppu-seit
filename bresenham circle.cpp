#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
using namespace std;

int x1,y1,x2,y2;

void myInit() {
   glclear clolour(0.0,0.0,0.0,1.0);
   glPointsSize(4);
   glViewport(0,0,640,480);
   gluOrtho2D(0,640,0,480);
}

void draw_pixel(int x,int y){
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}

void DDA(int x1,int y1,int x2, int y2) {
int dx ,dy , step, i;
float incx, incy ,x ,y ;

dx = x2-x1;
dx = y2-y1;
if (abs(dx)>abs(dy))
      step=abs(dx);
      else 
         step = abs(dy);
         incx=(float)dx/step;
         incy=(float)dy/step;
         x=x1;
         y=y1;
         
         draw_pixel(x,y);
         for(i=1;i<step;i++){
         x=x+incx;
         y=y+incy;
         
         
         draw_pixel(x,y);
         }
         }
         
         
         void axis(){
         int i,x,y;
         
         glColor3f(0.0,1.0,0.0);
         DDA(320,30,320,450);
         DDA(20,240,620,240);
         
         for(i=-20,x=20;i<=10;i++,x+=30){
         glColor3f(0.0,1.0,0.0);
         DDA(x,238,x,242);
         }
         for(i=7,x=30;i>=-7;i--,y+=30){
         glColor3f(0.0,1.0,0.0);
         DDA(315, y,325,y);
         }
         }
         
         void myDisplay()
        {
        glClear(GL_COLOR_BUFFER_BIT);
        axis();
        DDA(x1+320,y1+240,x2+320,y2+240);
        glFlush;
        }
        
        int main (int argc , char **argb)
        { 
        cout<<"Enter (x1,y1,x2,y2);
        cin>>x1>>y1>>x2>>y2;
        
        
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(640,480);
        glutInitWindowPosition(0,0);
        glutCreateWindow("DDA Line Drawing");
        myInit();
        glutDisplayFunc(myDisplay);
        glutMainLoop();
        return 1;
        }
        
         
         
         }
         
   

