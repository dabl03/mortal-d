#ifndef DEFINE_H
#define DEFINE_H
#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#else
# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/freeglut.h>
#endif

	#define GL_PI 3.141592
	#define TIME_OF_REFRESH_MILISECONDS 5
	#define TEMA_MAIN 0
	#define TEMA_GAME 1
	#define MAX_KEY_SPECIAL 246
	#define MAX_KEY 267
	void tratar_teclas_especiales();
	void mouse(int boton, int estado, int x, int y);
/*{
	//glutWarpPointer() mueve el puntero del mouse a las coordenadas relativas a la ventana dadas por x e y .
/*Dejo esto para que veas como contruir esta funcion: Nota lo saque de internet.
	switch (boton)
	{
		
	case GLUT_LEFT_BUTTON:
		if (estado = GLUT_DOWN){
			xPos += xSpeed;
			yPos += ySpeed;
			if(x == xPos){
				x= xPosMin;
				xSpeed = -xSpeed;
				xPosMin = xLeft + ballRadius;
			}
			else if (y== yPos){
				y =yPosMin;
				ySpeed= -ySpeed;
			}
		}
		else{
			
		}
		glutPostRedisplay();
	default:
		break;
	}
}*/
/*Evento del teclado. @todo: Hacer: Crear una macro que obtenga el caracter en minuscula.*/
void teclado(unsigned char key,int x,int y);
void key_up(unsigned char key,int x,int y);
void special_key(int key,int x, int y);
void special_key_up(int key,int x, int y);
void tratar_teclas_especiales();
#endif
