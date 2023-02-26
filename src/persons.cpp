#include <stdio.h>//Solo para debug
#include <string.h>//strlen
class Point{
public:
	double x,y;
	Point(const double x,const double y){
		this->x=x;
		this->y=y;
	}
	Point(const Point* p){
		this->x=p->x;
		this->y=p->y;
	}
	Point(const double* p){
		this->x=p[0];
		this->y=p[1];
	}
};
/**
 * Clase que almacena las dimensiones y coordenadas de cada personaje.
 */
class Person: public Point{
protected:
	unsigned int* dim=NULL;
	char* name=NULL;
public:
	double speed,angle;
	///Inicializamos todas las variables. width, height y name son opcionales.
	Person(int x,int y,double speed,double angle,int width=-1,int height=-1,char* name=NULL):Point(x,y){
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
	}
	/*unsigned int* get_position(){//Fue por otro arreglo que tuve, pero ahora no sirve.
		return this->dim[0];
	}
	*/
	unsigned int* get_dim2d(){
		return this->dim;
	}
	char* get_name(){
		return this->name;
	}
	unsigned int len_name(){
		return strlen(this->name);
	}
	void set_name(char* name){
		delete[] this->name;
		this->name=new char[strlen(name)+1];
		strcpy(this->name,name);
	}
	~Person(){
		if (this->dim!=NULL)
			delete[] this->dim;
		if (this->name!=NULL)
			delete[] this->name;
	}
	
};
/**
 * Aqui debemos definir al personaje.
 */
class Player: public Person{
public:
	Player(int x,int y,double speed,int width,int height,char* name=NULL,double* color_rgb=NULL,double a=-1)
		:Person(x,y,speed,0,width,height,name){
		
	}
};
