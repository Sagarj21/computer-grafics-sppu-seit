#include <GL/glut.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int choice;

void my_init()
{
	glClearColor(1.0,1.0,1.0,1.0);//set background to white colour because it needed as flood fill is independent of boundsry colour
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,800,0,800);
}

void my_display()
{
	glLineWidth(3);
	glPointSize(2);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glColor3f(1,0,0);
	glVertex2i(400,600);
	glColor3f(0,1,0);
	glVertex2i(600,200);
	glColor3f(0,0,1);
	glVertex2i(200,200);
	glEnd();
	glFlush();	

	
}

void flood_fill(int x, int y, float* o, float* n)// A recursive function to replace 'oldcolor' at  '(x, y)' and all surrounding pixels of (x, y) with new color
{
	//this algorithm is independent of boundary colour
	float current[3];   //to store pixel of back current and upcomming
	glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,current); //reads the pixels
	
	if(current[0]==o[0] && current[1]==o[1] && current[2]==o[2])//check whether boundary is there or not to stop
	{
		glColor3f(n[0],n[1],n[2]);//checks the present colour in the pixel
		glBegin(GL_POINTS);
			glVertex2i(x,y);
		glEnd();
		glFlush();
                //4way approach
		flood_fill(x+2,y,o,n);  //calls floodfill itself recursively
		flood_fill(x-2,y,o,n);
		flood_fill(x,y+2,o,n);
		flood_fill(x,y-2,o,n);
	}
}

void mouse(int btn,int state, int x, int y)
{
	y=800-y;
	if(btn==GLUT_LEFT_BUTTON)
	{
		if(state==GLUT_DOWN)
		{
			float o[] = {1.0,1.0,1.0};//loads the old pixels to the vairables
			float n[] = {0.0,1.0,0.0};//loads the  new pixels to the vairables

			flood_fill(x,y,o,n);			
		}
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800,800);  //give the size to the window
	glutInitWindowPosition(500,500);  //sets the position of the window on screen
	glutCreateWindow("Flood Fill");
	cout<<"click anywhere inside the closed figure"<<endl;
	glutDisplayFunc(my_display);
	glutMouseFunc(mouse);
	my_init();
	glutMainLoop();
	return 0;
}

