#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

float x1,x2,x3,x4,y11,y2,y3,y4,x1n,x2n,x3n,x4n,y11n,y2n,y3n,y4n,d,Wx,Wy;

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
		glVertex2f(Wx/2,20);
		glVertex2f(Wx/2,Wy-20);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(20,Wy/2);
		glVertex2f(Wx-20,Wy/2);
	glEnd();
	glFlush();
	
	glColor3f(1,0,1);
	for(int i=Wx/2,j=Wy/2+10;i<=Wx-20;i=i+20){
		glBegin(GL_LINE_LOOP);
			glVertex2f(i,j);
			glVertex2f(i,j-20);
		glEnd();
		glFlush();
	}
	for(int i=Wx/2+10,j=Wy/2;j<=Wy-20;j=j+20){
		glBegin(GL_LINE_LOOP);
			glVertex2f(i,j);
			glVertex2f(i-20,j);
		glEnd();
		glFlush();
	}

	for(int i=Wx/2,j=Wy/2+10;i>=20;i=i-20){
		glBegin(GL_LINE_LOOP);
			glVertex2f(i,j);
			glVertex2f(i,j-20);
		glEnd();
		glFlush();
	}
	for(int i=Wx/2+10,j=Wy/2;j>=20;j=j-20){
		glBegin(GL_LINE_LOOP);
			glVertex2f(i,j);
			glVertex2f(i-20,j);
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
		glVertex2f(x1,y11);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
	glEnd();
	glFlush();
}

void rotateIt()
{

	x1-=Wx/2;x2-=Wx/2;x3-=Wx/2;x4-=Wx/2;
	y11-=Wy/2;y2-=Wy/2;y3-=Wy/2;y4-=Wy/2;
	

	d*=M_PI/180;

	x1n=x1*cos(d)-y11*sin(d);
	y11n=x1*sin(d)+y11*cos(d);
	x2n=x2*cos(d)-y2*sin(d);
	y2n=x2*sin(d)+y2*cos(d);
	x3n=x3*cos(d)-y3*sin(d);
	y3n=x3*sin(d)+y3*cos(d);
	x4n=x4*cos(d)-y4*sin(d);
	y4n=x4*sin(d)+y4*cos(d);

	x1n+=Wx/2;x2n+=Wx/2;x3n+=Wx/2;x4n+=Wx/2;
	y11n+=Wy/2;y2n+=Wy/2;y3n+=Wy/2;y4n+=Wy/2;
	
	glClearColor(0.0,0.0,0.0,1.0);
	glLineWidth(1);
	glPointSize(1);
	glClear(GL_COLOR_BUFFER_BIT);
	drawAxis();
	glColor3f(0,1,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(x1n,y11n);
		glVertex2f(x2n,y2n);
		glVertex2f(x3n,y3n);
		glVertex2f(x4n,y4n);
	glEnd();
	glFlush();
}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON)
	{
		if(state==GLUT_DOWN)
		{
			rotateIt();
		}
	}
}

int main(int argc, char** argv)
{
	Wx=700,Wy=700;
	cout<<"Enter 4 vertices of a Quadrilateral"<<endl;
	cin>>x1>>y11>>x2>>y2>>x3>>y3>>x4>>y4;
	
	x1*=20;x2*=20;x3*=20;x4*=20;
	y11*=20;y2*=20;y3*=20;y4*=20;
	
	x1+=Wx/2;x2+=Wx/2;x3+=Wx/2;x4+=Wx/2;
	y11+=Wy/2;y2+=Wy/2;y3+=Wy/2;y4+=Wy/2;
	
	cout<<"Enter the degree of rotation"<<endl;
	cin>>d;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(Wx,Wx);
	glutInitWindowPosition(1000,200);
	glutCreateWindow("Rotate it");

	glutDisplayFunc(my_display);
	glutMouseFunc(mouse);
	my_init();
	glutMainLoop();

	return 0;
}
