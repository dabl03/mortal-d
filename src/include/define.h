#ifndef DEFINE_H
#define DEFINE_H
/*#define Frac_Circ 100  // Cien fracciones de circulo
#define PI 3.1415926535897932

glBegin(GL_POLYGON);
for (int i = 0; i < Frac_Circ + 1; i++) {  // +1 para cerrar
	glVertex2f( circ->x + circ->r * cos(2.0 * PI * i / Frac_Circ),
			   circ->y + circ->r * sin(2.0 * PI * i / Frac_Circ) );
}
glEnd(); 
*/

	#define GL_PI 3.141592
	#define TIME_OF_REFRESH_MILISECONDS 5
	#define TEMA_MAIN 0
	#define TEMA_GAME 1
	#define MAX_KEY_SPECIAL 246
	#define MAX_KEY 267
	void tratar_teclas_especiales();
#endif
