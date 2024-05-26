#include <stdio.h>//Solo para debug
#include <string.h>//strlen
#include "include/person.h"

Point::Point(const double x,const double y){
	this->x=x;
	this->y=y;
};
Point::Point(const Point* p){
	this->x=p->x;
	this->y=p->y;
}
Point::Point(const double* p){
	this->x=p[0];
	this->y=p[1];
}; 
/**
 * Clase que almacena las dimensiones y coordenadas de cada personaje.
 */
Person::Person(int x,int y,double speed,double angle,int width,int height,char* name):Point(x,y){
	if (width!=-1){
		this->dim=new unsigned int[2];
		this->dim[0]=width;
		this->dim[1]=height;
	}
	this->speed=speed;
	this->angle=angle;
	if (name!=NULL){
		this->name=new char[strlen(name)+1];
		strcpy(this->name,name);
	}
};
unsigned int* Person::get_dim2d(){
	return this->dim;
};
void Person::set_dim(unsigned int width,unsigned int height){
	this->dim[0]=width;
	this->dim[1]=height;
}
char* Person::get_name(){
	return this->name;
};
unsigned int Person::len_name(){
	return strlen(this->name);
};
void Person::set_name(char* name){
	delete[] this->name;
	this->name=new char[strlen(name)+1];
	strcpy(this->name,name);
};
Person::~Person(){
	if (this->dim!=NULL)
		delete[] this->dim;
	if (this->name!=NULL)
		delete[] this->name;
};
/**
 * Aqui debemos definir al personaje.
 */
Player::Player(int x,int y,double speed,int width,int height,char* name,double* color_rgb,double a)
	:Person(x,y,speed,0,width,height,name){
	
};
