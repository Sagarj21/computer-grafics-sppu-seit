#include <GL/glut.h>
#include <cstdlib>
#include <iostream>

using namespace std;

float x1,x2,x3,x4,y1,y2,y3,y4,Wx,Wy;
char axis;

void my_init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,Wx,0,Wy);
}

void drawAxis(){
	glLineWidth(1);
	glPointSize(1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,1);
	
	glBegin(GL_LINE_LOOP);
		glVertex2i(Wx/2,20);
		glVertex2i(Wx/2,Wy-20);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2i(20,Wy/2);
		glVertex2i(Wx-20,Wy/2);
	glEnd();
	glFlush();
	
	glColor3f(1,0,1);
	for(int i=Wx/2,j=Wy/2+10;i<=Wx-20;i=i+20){
		glBegin(GL_LINE_LOOP);
			glVertex2i(i,j);
			glVertex2i(i,j-20);
		glEnd();
		glFlush();
	}
	for(int i=Wx/2+10,j=Wy/2;j<=Wy-20;j=j+20){
		glBegin(GL_LINE_LOOP);
			glVertex2i(i,j);
			glVertex2i(i-20,j);
		glEnd();
		glFlush();
	}

	for(int i=Wx/2,j=Wy/2+10;i>=20;i=i-20){
		glBegin(GL_LINE_LOOP);
			glVertex2i(i,j);
			glVertex2i(i,j-20);
		glEnd();
		glFlush();
	}
	for(int i=Wx/2+10,j=Wy/2;j>=20;j=j-20){
		glBegin(GL_LINE_LOOP);
			glVertex2i(i,j);
			glVertex2i(i-20,j);
		glEnd();
		glFlush();
	}
}

void my_display()
{
	glLineWidth(1);
	glPointSize(1);
	drawAxis();
	glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2i(x1,y1);
		glVertex2i(x2,y2);
		glVertex2i(x3,y3);
		glVertex2i(x4,y4);
	glEnd();
	glFlush();
}

void reflectIt()
{
	x1-=Wx/2;x2-=Wx/2;x3-=Wx/2;x4-=Wx/2;
	y1-=Wy/2;y2-=Wy/2;y3-=Wy/2;y4-=Wy/2;

	if(axis=='x')
	{
		y1=-y1;
		y2=-y2;
		y3=-y3;
		y4=-y4;
	}
	if(axis=='y')
	{
		x1=-x1;
		x2=-x2;
		x3=-x3;
		x4=-x4;
	}
	x1+=Wx/2;x2+=Wx/2;x3+=Wx/2;x4+=Wx/2;
	y1+=Wy/2;y2+=Wy/2;y3+=Wy/2;y4+=Wy/2;
	
	glClearColor(0.0,0.0,0.0,1.0);
	glLineWidth(1);
	glPointSize(1);
	glClear(GL_COLOR_BUFFER_BIT);
	drawAxis();
	glColor3f(0,1,0);
	glBegin(GL_LINE_LOOP);
		glVertex2i(x1,y1);
		glVertex2i(x2,y2);
		glVertex2i(x3,y3);
		glVertex2i(x4,y4);
	glEnd();
	glFlush();
}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON)
	{
		if(state==GLUT_DOWN)
		{
			reflectIt();
		}
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	Wx=700,Wy=700;
	glutInitWindowSize(Wx,Wx);
	glutInitWindowPosition(1000,200);
	glutCreateWindow("Translate it");
	cout<<"Enter 4 vertices of a Quadrilateral"<<endl;
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	
	x1*=20;x2*=20;x3*=20;x4*=20;
	y1*=20;y2*=20;y3*=20;y4*=20;
	
	x1+=Wx/2;x2+=Wx/2;x3+=Wx/2;x4+=Wx/2;
	y1+=Wy/2;y2+=Wy/2;y3+=Wy/2;y4+=Wy/2;
	
	cout<<"Enter the axis to reflect the object obout it"<<endl;
	cin>>axis;

	glutDisplayFunc(my_display);
	glutMouseFunc(mouse);
	my_init();
	glutMainLoop();

	return 0;
}
