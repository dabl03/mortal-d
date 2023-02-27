#ifndef PERSON_H
 #define PERSON_H 1
class Point{
public:
	double x,y;
	Point(const double x,const double y);
	Point(const Point* p);
	Point(const double* p);
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
	Person(int x,int y,double speed,double angle,int width=-1,int height=-1,char* name=NULL);
	unsigned int* get_dim2d();
	void set_dim(unsigned int width,unsigned int height);
	char* get_name();
	unsigned int len_name();
	void set_name(char* name);
	~Person();
	
};
/**
 * Aqui debemos definir al personaje.
 */
class Player: public Person{
public:
	Player(int x,int y,double speed,int width,int height,char* name=NULL,double* color_rgb=NULL,double a=-1);
};

 #endif