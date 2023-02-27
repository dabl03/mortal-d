#include "./include/define.h"
#include "include/person.h"
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