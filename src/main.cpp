#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "include/define.h"
#include "include/person.h"
#include "include/geometric_figure.h"
/**
 * Titulo de la ventana.
 */
const char* W_TITLE="Mortal-D";
//Lo use para familierizarme con glut en opengl.
unsigned short is_180_agle=false,
	is_left=false,
	is_top=false,
	l_is_left=true,
	l_is_top=true;
unsigned int width_screen=600,height_screen=400;
Person ball=Person(width_screen/2,height_screen/2,0.2,1,69,69);
Person light_ball=Person(width_screen/3,height_screen/2,0.2,1);
Point p_camara=Point(0,0);
Person gamer=Person(width_screen/3,height_screen/2,1,1,50,50);
double speed_camara=1;
bool keyStates[MAX_KEY];//Estados de las teclas. Al llamar a key up se debe volver al false.
bool keySpecialStates[MAX_KEY_SPECIAL];
unsigned short tema=TEMA_GAME;

//end.
//Una funcion que hice para crear rectangulos, pero ahora ya no es necesaria usando GL_QUANS, al menos que necesites crear los bordes.
void draw_ball(Person* rect){
	unsigned int* dim2d=rect->get_dim2d();
	glBegin(GL_QUADS);
	//glScalef(1.0f, 2.5f, 1.0f);
	//rect_horizontal:
	glVertex2i(rect->x,rect->y); glVertex2i(rect->x+dim2d[0],rect->y);//----------
	glVertex2i(rect->x+dim2d[0],rect->y); glVertex2i(rect->x+dim2d[0],rect->y+dim2d[1]);// |
	//rect_vertical
	glVertex2i(rect->x+dim2d[0],rect->y+dim2d[1]);glVertex2i(rect->x,rect->y+dim2d[1]);//----
	glVertex2i(rect->x,rect->y); glVertex2i(rect->x,rect->y+dim2d[1]);// |
	glEnd();
	glColor3f(1,0.2,0.2);
	//Creamos los bordes.
	glBegin(GL_LINES);
	//rect_horizontal:
	glVertex2i(rect->x,rect->y); glVertex2i(rect->x+dim2d[0],rect->y);//----------
	glVertex2i(rect->x+dim2d[0],rect->y); glVertex2i(rect->x+dim2d[0],rect->y+dim2d[1]);// |
	//rect_vertical
	glVertex2i(rect->x+dim2d[0],rect->y+dim2d[1]);glVertex2i(rect->x,rect->y+dim2d[1]);//----
	glVertex2i(rect->x,rect->y); glVertex2i(rect->x,rect->y+dim2d[1]);// |
	glEnd();
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_LINE_LOOP);
		glVertex2i(light_ball.x,light_ball.y);glVertex2i(rect->x,rect->y);
		glColor3f(0,0,1);
		glVertex2i(light_ball.x,light_ball.y);glVertex2i(rect->x+dim2d[0],rect->y);
		glColor3f(0,1,0);
		glVertex2i(light_ball.x,light_ball.y);glVertex2i(rect->x+dim2d[0],rect->y+dim2d[1]);
		glColor3f(1,0,0);
		glVertex2i(light_ball.x,light_ball.y);glVertex2i(rect->x,rect->y+dim2d[1]);
		glColor3f(0,0,0);
	glEnd();
	glPointSize(30);
	//Je pequeña lampara.
	glColor3f(1,1,1);
	glBegin(GL_POINTS);
	glVertex3f(light_ball.x, light_ball.y, 1.0f);
	glEnd();
}
//Evento de redimencionamiento de la ventana.
void reshape_cb (int w, int h) {
	if (w==0||h==0) return;
	glViewport(0,0,w,h);//Nota: hay que ponerle las coordenadas de la camara.
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(0,w,0,h);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	gamer.x=(width_screen=w)/2;gamer.y=(height_screen=h)/2;//Update screen dimension.
}
//Solo util con pelota que revota por la pantalla.
void move_no_choque(Person* p,unsigned int limit_w,unsigned int limit_h,unsigned short* _is_left,unsigned short* _is_top){
	if (*_is_left){
		p->x+=p->speed;
		if (p->x>limit_w)
			*_is_left=false;
	}else{
		p->x-=p->speed;
		if (p->x<0)
			*_is_left=true;
	}
	if (*_is_top){
		p->y+=(p->speed+0.01);
		if (p->y>limit_h)
			*_is_top=false;
	}else{
		p->y-=(p->speed+0.01);
		if (p->y<0)
			*_is_top=true;
	}
}
/*Aqui se hace el analizis del juego.*/
void move_var(){
	//glLoadIdentity();
	tratar_teclas_especiales();
	ball.angle+=(!is_180_agle)?1:-1;
	if (ball.angle>180)
		is_180_agle=1;
	else if (ball.angle<0)
		is_180_agle=0;
	//Move nave
	move_no_choque(&ball,width_screen,height_screen,&is_left,&is_top);
	move_no_choque(&light_ball,width_screen,height_screen,&l_is_left,&l_is_top);
	glutPostRedisplay ();// A juro debes llamarlo para que se actualize la pantalla.
	
}
//Imvestigar mejor esto. Lo consegui en internet y lo pegue.
void Timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(TIME_OF_REFRESH_MILISECONDS, Timer, 0);
}
//Dibujar todo.
void display_cb() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 1.0, 0,1);
	
	glLoadIdentity();
	/*glMatrixMode(GL_MODELVIEW);
	gluLookAt(
			  p_camara.x-width_screen,p_camara.y-height_screen,  1,
			  p_camara.x+(width_screen/2),p_camara.y+(height_screen/2),  1,
			  p_camara.x+width_screen,p_camara.y+height_screen, 1);
	*/
	glPushMatrix ();
	glTranslated(p_camara.x,p_camara.y,1);
	glEnable(GL_COLOR_MATERIAL);
	//glRotatef(90,0,0,1);//Hasta 180ª
	// Set the camera
	
	glColor3f(0,0,1); glLineWidth(30);
	glBegin(GL_TRIANGLES);
	glVertex2d(300,height_screen);
	glVertex2d(150,height_screen/2);
	glVertex2d(450,height_screen/2);
	glVertex2d(150,height_screen);
	glColor3f(1,1,0); glLineWidth(3);
	glEnd();
	glColor3f(1,0,0); glLineWidth(30);
	glBegin(GL_TRIANGLES);
	glVertex2d(150,150);
	glVertex2d(75,75);
	glVertex2d(225,150);
	glVertex2d(150,225);
	glColor3f(1,1,0); glLineWidth(3);
	glEnd();
	//Un triangulo que dibuje verde.
	glColor3f(0,1,0); glLineWidth(30);
	glBegin(GL_TRIANGLES);
	glVertex2d(300,300);
	glVertex2d(150,150);
	glVertex2d(450,300);
	glVertex2d(300,450);
	glColor3f(1,1,0); glLineWidth(3);
	glEnd();
	draw_ball(&ball);
	glColor3f(1,0,0);
	glLineWidth(30);
	glBegin(GL_QUADS);
	int n=10;
	glVertex2i(p_camara.x-n,p_camara.y-n); glVertex2i(p_camara.x+n,p_camara.y-n);
	glVertex2i(p_camara.x+n,p_camara.y-n);glVertex2i(p_camara.x+n,p_camara.y+n);
	
	glVertex2i(p_camara.x+n,p_camara.y+n);glVertex2i(p_camara.x-n,p_camara.y+n);
	glVertex2i(p_camara.x-n,p_camara.y+n);glVertex2i(p_camara.x-n,p_camara.y-n);
	glEnd();
	draw_rect(&gamer);
	glPopMatrix();
	glutSwapBuffers();//cambiamos los bufferes
}

/*Inicializar todas las configuraciones de glut.*/
void initialize() {
	//GLUT_DEPTH|GLUT_DOUBLE
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);/*Usar buffer de profundidad, rgba  y doble buffer*/
	glutInitWindowSize (width_screen,height_screen);
	glutInitWindowPosition (0,0); 
	glutCreateWindow (W_TITLE);
	//Eventos:
	glutIdleFunc(move_var);
	glutDisplayFunc (display_cb);
	glutReshapeFunc (reshape_cb);
	//Tecla normales.
	glutKeyboardFunc(teclado);
	glutKeyboardUpFunc(key_up);//Cuando suelta la tecla.
	//Teclas especiales.
	glutSpecialFunc(special_key);//Teclas especiales.
	glutSpecialUpFunc(special_key_up);
	//FTS y mouse.
	glutTimerFunc(0, Timer, 0);
	glutMouseFunc(mouse);
	glClearColor(0,0,0,0);
}

int main (int argc, char **argv) {
	glutInit (&argc, argv);//Iniciar glut
	initialize();
	glutMainLoop();//Buvle para procesar eventos.
	return 0;
}


/********EVEMTOS TECLADO Y MOUSE************/
void mouse(int boton, int estado, int x, int y){
}
/*Evento del teclado. @todo: Hacer: Crear una macro que obtenga el caracter en minuscula.*/
void teclado(unsigned char key,int x,int y){
	if(key>='A' && key<='Z'){
		key=tolower(key);
	}
	//static bool is_full_screen=true; // Si no funciona el fullscreen entonces no nos sirve.
	switch (key)
	{
	case 'h'://Solo fue para probar como funciona.
		glViewport(ball.x,ball.y,width_screen,height_screen);//Mueve la camara.
		break;
	case 'q':
		exit (0);
		break;
	case 'p'://Nota: Por alguna razon no funciona el full screen.
		/*glutFullScreen();//Si esta en pantalla completa no hara nada.
		if (!is_full_screen){//Quitamos la pantalla completa.
			glutInitWindowSize (width_screen,height_screen);
			glutPositionWindow(0,0);
		}
		is_full_screen!=true;*/
		break;
	default:
		keyStates[key]=true;
	}
}
void key_up(unsigned char key,int x,int y){
	if(key>='A' && key<='Z'){
		key=tolower(key);
	}
	keyStates[key]=false;
}
void special_key(int key,int x, int y){
	keySpecialStates[key]=true;
}
void special_key_up(int key,int x, int y){
	keySpecialStates[key]=false;
}
void tratar_teclas_especiales(){
	switch(tema){
	case TEMA_GAME:
		if(keySpecialStates[GLUT_KEY_UP]){
			p_camara.y-=gamer.speed;
			gamer.y+=gamer.speed;//A juro debemos hacer operaciones distintas al de la camara.
		}
		if (keySpecialStates[GLUT_KEY_DOWN]){
			p_camara.y+=gamer.speed;
			gamer.y-=gamer.speed;
		}
		if (keySpecialStates[GLUT_KEY_LEFT]){
			p_camara.x+=gamer.speed;
			gamer.x-=gamer.speed;
		}
		if (keySpecialStates[GLUT_KEY_RIGHT]){
			p_camara.x-=gamer.speed;
			gamer.x+=gamer.speed;
		}
		break;
	case TEMA_MAIN:
		break;
	}
}