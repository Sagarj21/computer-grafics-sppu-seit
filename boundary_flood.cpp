#include <GL/glut.h>
#include <cstdlib>
#include <iostream>

using namespace std;



void my_init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,640,0,480);
}

void my_display()
{
	glLineWidth(3);
	glPointSize(3);
	glClear(GL_COLOR_BUFFER_BIT);
	
		glBegin(GL_LINE_LOOP);
			glColor3f(1,0,0);
			glVertex2i(150,100);
			glColor3f(0,1,0);
			glVertex2i(300,300);
			glColor3f(0,0,1);
			glVertex2i(450,100);
		glEnd();
		glFlush();	

	
}

void boundary_fill(int x, int y, float* b, float* f)
{
	float current[3];
	glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,current);
	
	if((current[0]!=b[0] || current[1]!=b[1] || current[2]!=b[2]) 
		&& (current[0]!=f[0] || current[1]!=f[1] || current[2]!=f[2]))
	{
		glColor3f(f[0],f[1],f[2]);
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		glFlush();

		boundary_fill(x+3,y,b,f);
		boundary_fill(x-3,y,b,f);
		boundary_fill(x,y+3,b,f);
		boundary_fill(x,y-3,b,f);
	}
}

void flood_fill(int x, int y, float* o, float* n)
{
	float current[3];
	glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,current);
	
	if(current[0]==o[0] && current[1]==o[1] && current[2]==o[2])
	{
		glColor3f(n[0],n[1],n[2]);
		glBegin(GL_POINTS);
			glVertex2i(x,y);
		glEnd();
		glFlush();

		flood_fill(x+3,y,o,n);
		flood_fill(x-3,y,o,n);
		flood_fill(x,y+3,o,n);
		flood_fill(x,y-3,o,n);
	}
}

void mouse(int btn,int state, int x, int y)
{
	y=480-y;
	if(btn==GLUT_LEFT_BUTTON)
	{
		if(state==GLUT_DOWN)
		{
			float b[] = {1.0,0.0,0.0};
			float f[] = {0.0,0.0,1};
			float o[] = {1.0,1.0,1.0};
			float n[] = {0.0,0.0,1};

			
				flood_fill(x,y,o,n);
					
		}
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(1000,200);
	glutCreateWindow("Menu");
	cout<<"Flood Fill"<<endl;
	
	glutDisplayFunc(my_display);
	glutMouseFunc(mouse);
	my_init();
	glutMainLoop();
	return 0;
}

