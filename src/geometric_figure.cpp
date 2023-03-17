#include "include/geometric_figure.h"
void draw_rect(Person* p){
	unsigned int* dim=p->get_dim2d();
	glBegin(GL_QUADS);
	//rect_horizontal:
	glVertex2i(p->x,p->y); glVertex2i(p->x+dim[0],p->y);//----------
	glVertex2i(p->x+dim[0],p->y); glVertex2i(p->x+dim[0],p->y+dim[1]);// |
	//rect_vertical
	glVertex2i(p->x+dim[0],p->y+dim[1]);glVertex2i(p->x,p->y+dim[1]);//----
	glVertex2i(p->x,p->y); glVertex2i(p->x,p->y+dim[1]);// |
	glEnd();
}
void draw_rect(Point* p,int width,int height){
	Person pe=Person(p->x,p->y,1,1,width,height,NULL);
	draw_rect(&pe);
}
/***Como hacer un circulo en opengl.
Now for the meat of this tutorial, the circle creation function
The properties this takes are:
k – the translation on the y axis
r – the radius of the circle
h – the translation on the x axis

void createcircle (int k, int r, int h) {
Now we begin drawing our lines
glBegin(GL_LINES);
Here we are setting up the vertices all in one line function, this
sets every 2 vertices to a line.

First we begin our loop, this loop will cycle through, constantly
changing our x and y values for our lines. It cycles through until
it reaches 180, increasing in intervals of 1
for (int i = 0;i < 180;i++)
{
Now to set up the current x value that we need for our vertex
I am setting it to the radius of the circle, times by the cosine of
the current value of i, then I am taking h to translate it
circle.x = r * cos(i) – h;
Then to set up the current y value that we need for our vertex
I am setting it to the radius of the circle, times by the sine of
the current value of i, then I am adding k to translate it
circle.y = r * sin(i) + k;
Then I am drawing the vertex
glVertex3f(circle.x + k,circle.y – h,0);

Now for the second part of the line, I am doing the same as above, only
I am moving it 0.1 units so that I am not down to points. This also
Lowers the chance of any holes occuring in the circle
circle.x = r * cos(i + 0.1) – h;
circle.y = r * sin(i + 0.1) + k;
Then I am drawing the vertex
glVertex3f(circle.x + k,circle.y – h,0);
}
glEnd();
}*/