//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	 Lopez Vite Erick Misael   				******//
//*************	 Pastrana Hern�ndez Adriana				******//
//************************************************************//
#include "texture.h"
#include <MMSystem.h>
//#include "cmodel/CModel.h"
#include "Camera.h"

//luces
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = 0.0f;
int rot, rot0, rot1;

float LightAngle = 30.0f;

bool	light = false;		// Luz ON/OFF
bool	positional = true;

static int spin = 0;

//Camaras

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 
CCamera objCamera;										// CAMARA NORMAL
CCamera objCamera2;										// CAMARA 1
CCamera objCamera3;										// CAMARA 2
bool mover_camara = true;
float camPosX, camPosY, camPosZ, camViewX, camViewY, camViewZ, camUpX, camUpY, camUpZ; // PARA MOVER LA C�MARA


GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position
GLfloat LightPosition1[] = { 0.0f, 0.0f, 1.0f, 0.0f };			// Light Position
GLfloat LightDirection[] = { 0.0f, 0.0f, -2.0f };			// Light Position

GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };					// Color background
GLfloat mat_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };					// Object Color main
GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };				// Specular color
GLfloat mat_shininess[] = { 100.0 };							// 1 to greatest
// fin luces


float pos_camX = 0, pos_camY = 0, pos_camZ = -2;
float pos_camX2 = -9, pos_camY2 = -2, pos_camZ2 = -5;
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;

float text_der = 1.0;
float text_izq = 0.0;

//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position


CTexture t_techo;
CTexture t_piso;
CTexture t_fachada;
CTexture t_puerta;
CTexture t_ventana;
CTexture t_fantasma;
CTexture t_holandes;
CTexture t_pasto;
CTexture t_fondo;
CTexture t_noche;
CTexture t_copos;
CTexture t_tallo;
CTexture t_hojas;
CTexture t_pinata;
CTexture t_nochebuena;
CTexture t_corona;

//CModel estrella;
//CModel corona;

int rot2, rot3, rot4, rot5, rot6, rot7, rot8, rot9, rot10, rot11, rot12;


//Animaci�n del PEZ
float movPez = 0.0;
bool g_fanimacion = false;
bool tope = false;

//Animaci�n del fantasma
float movFantasma = 0.0;
float movFantasma1 = 0.0;
bool g_fanimacionF = false;
bool topeF = false;
bool topeF1 = false;



bool mov = true;

int font = (int)GLUT_BITMAP_TIMES_ROMAN_24;


void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	

	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);


	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading

	//glEnable (GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);				// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);				// Setup The Diffuse Light
	//glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);			// Position The Light
	//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,LightDirection);			// Direction Of The Light

	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	t_piso.LoadTGA("img/piso.tga");
	t_piso.BuildGLTexture();
	t_piso.ReleaseImage();


	t_fachada.LoadTGA("img/ladrillos.tga");
	t_fachada.BuildGLTexture();
	t_fachada.ReleaseImage();

	t_techo.LoadTGA("img/techo.tga");
	t_techo.BuildGLTexture();
	t_techo.ReleaseImage();

	t_puerta.LoadTGA("img/puerta.tga");
	t_puerta.BuildGLTexture();
	t_puerta.ReleaseImage();

	t_ventana.LoadTGA("img/ventana.tga");
	t_ventana.BuildGLTexture();
	t_ventana.ReleaseImage();


	t_pasto.LoadTGA("img/pasto.tga");
	t_pasto.BuildGLTexture();
	t_pasto.ReleaseImage();

	t_fondo.LoadTGA("img/fondo.tga");
	t_fondo.BuildGLTexture();
	t_fondo.ReleaseImage();

	t_noche.LoadTGA("img/noche.tga");
	t_noche.BuildGLTexture();
	t_noche.ReleaseImage();

	t_copos.LoadTGA("img/copos.tga");
	t_copos.BuildGLTexture();
	t_copos.ReleaseImage();

	t_tallo.LoadTGA("img/tallo.tga");
	t_tallo.BuildGLTexture();
	t_tallo.ReleaseImage();

	t_hojas.LoadTGA("img/hojas.tga");
	t_hojas.BuildGLTexture();
	t_hojas.ReleaseImage();

	t_pinata.LoadTGA("img/pinata.tga");
	t_pinata.BuildGLTexture();
	t_pinata.ReleaseImage();

	t_nochebuena.LoadTGA("img/nochebuena.tga");
	t_nochebuena.BuildGLTexture();
	t_nochebuena.ReleaseImage();

	t_corona.LoadTGA("img/corona.tga");
	t_corona.BuildGLTexture();
	t_corona.ReleaseImage();

	//corona._3dsLoad("corona.3ds");

	// CAMARAS

	objCamera.Position_Camera(10.0f, 0.0f, -7, -30.0, 0.0, -1, 0, 1, -0.01);// POSICION DE LA CAMARA 1 ( NORMAL )
	objCamera2.Position_Camera(-12, -2.1f, -9, -30.4, 0.1f, -44.5, 0, 1, -0.01);// POSICION DE LA CAMARA 2 ( CUARTO 1 )
	objCamera3.Position_Camera(3, -2.4f, -15, 41.8, -2.9f, -123.0, 0, 1, -0.01);// POSICION DE LA CAMARA 3 ( CUARTO 2 )

}
void renderBitmapCharacter(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
	//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}
void techo(GLuint textura1)
{
	GLfloat vertice[8][3] = {
	{ 0.0 ,0.0, 0.0 },    //Coordenadas V�rtice 0 V0 //ambos
	{ 1.0 ,0.0, 0.0 },    //Coordenadas V�rtice 1 V1 //ambos
	{ 1.0 ,0.0, -1.0 },    //Coordenadas V�rtice 2 V2 para piramide
	{ 0.5 ,0.5, -0.5 },    //Coordenadas V�rtice 3 V3 para piramide
	{ 0.0 ,0.0, -1.0 },    //Coordenadas V�rtice 4 V2 para ocho
	{ 0.0 ,0.0, -1.0 },    //Coordenadas V�rtice 5 V3 para ocho
	{ 0.5 ,0.5, -0.5 },    //Coordenadas V�rtice 6 V6
	{ 0.5 ,-0.5, -0.5 },    //Coordenadas V�rtice 7 V7
	};

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);  //Bottom
	//glColor3f(0.4, 0.0, 0.6);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);  //Bottom
	//glColor3f(0.4, 0.0, 0.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);  glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();



}
void prisma(GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas V�rtice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas V�rtice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas V�rtice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas V�rtice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
		//glColor3f(0.0,0.0,1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textura2);
	glBegin(GL_POLYGON);	//Right
		//glColor3f(0.0,0.0,1.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textura2);
	glBegin(GL_POLYGON);	//Back
		//glColor3f(0.0,1.0,0.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textura2);
	glBegin(GL_POLYGON);  //Left
		//glColor3f(1.0,1.0,1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);  //Bottom
		//glColor3f(0.4,0.2,0.6);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	// choose the texture to use.
	glBegin(GL_POLYGON);  //Top
		//glColor3f(0.8,0.2,0.4);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}
void cosa(GLuint textura1)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas V�rtice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas V�rtice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas V�rtice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas V�rtice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
		//glColor3f(0.0,0.0,1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();

}
void cono(GLuint textura1) {
	//Dibujar un cono s�lido
	glBindTexture(GL_TEXTURE_2D, textura1);
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0.4, 0.4, 1.0);
	//glScalef(0.2, 0.2, 0.2);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glutSolidCone(1.0, 0.4, 18, 18);

	glLineWidth(2.5);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0, 0.0, -0.5);
	glEnd();
	glLineWidth(2.5);
	glBegin(GL_LINES);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.5, 0.0, -0.5);
	glEnd();
	glLineWidth(2.5);
	glBegin(GL_LINES);
	glVertex3f(-0.5, 0.0, 0.0);
	glVertex3f(-0.5, 0.0, -0.5);
	glEnd();
	glLineWidth(2.5);
	glBegin(GL_LINES);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 0.5, -0.5);
	glEnd();
	glLineWidth(2.5);
	glBegin(GL_LINES);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();
	glPopMatrix();




}
void phantom(GLuint textura1)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas V�rtice 0 V0
	{ -0.5 ,-0.5, 0.5 },    //Coordenadas V�rtice 1 V1
	{ -0.5 ,-0.5, -0.5 },    //Coordenadas V�rtice 2 V2
	{ 0.5 ,-0.5, -0.5 },    //Coordenadas V�rtice 3 V3
	{ 0.5 ,0.5, 0.5 },    //Coordenadas V�rtice 4 V4
	{ 0.5 ,0.5, -0.5 },    //Coordenadas V�rtice 5 V5
	{ -0.5 ,0.5, -0.5 },    //Coordenadas V�rtice 6 V6
	{ -0.5 ,0.5, 0.5 },    //Coordenadas V�rtice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
							//glColor3f(0.0,0.0,1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();

}
void pasto(GLuint textura1) {
	GLfloat vertice[8][3] = {
	{ 0.5 ,-0.5, 0.5 },    //Coordenadas V�rtice 0 V0
	{ -0.5 ,-0.5, 0.5 },    //Coordenadas V�rtice 1 V1
	{ -0.5 ,-0.5, -0.5 },    //Coordenadas V�rtice 2 V2
	{ 0.5 ,-0.5, -0.5 },    //Coordenadas V�rtice 3 V3
	{ 0.5 ,0.5, 0.5 },    //Coordenadas V�rtice 4 V4
	{ 0.5 ,0.5, -0.5 },    //Coordenadas V�rtice 5 V5
	{ -0.5 ,0.5, -0.5 },    //Coordenadas V�rtice 6 V6
	{ -0.5 ,0.5, 0.5 },    //Coordenadas V�rtice 7 V7
	};

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
							//glColor3f(0.0,0.0,1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();
}
void MusicaChida() {
	PlaySound(TEXT("navidad.wav"), NULL, SND_ASYNC | SND_LOOP);
}
void fondo(GLuint textura1, GLuint textura2, GLuint textura3) {

	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas V�rtice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas V�rtice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas V�rtice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas V�rtice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
		//glColor3f(0.0,0.0,1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textura2);
	glBegin(GL_POLYGON);	//Right
		//glColor3f(0.0,0.0,1.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textura2);
	glBegin(GL_POLYGON);	//Back
		//glColor3f(0.0,1.0,0.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textura2);
	glBegin(GL_POLYGON);  //Left
		//glColor3f(1.0,1.0,1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);  //Bottom
		//glColor3f(0.4,0.2,0.6);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	// choose the texture to use.
	glBindTexture(GL_TEXTURE_2D, textura3);
	glBegin(GL_POLYGON);  //Top
		//glColor3f(0.8,0.2,0.4);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}
void cono(void){
glPushMatrix();
glScalef(0.7, 0.7, 0.7);
glutSolidCone(0.8, 0.3, 15, 15);
glPopMatrix();}
void cono2(GLuint textura1) {

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glPushMatrix();
	glScalef(0.7, 0.7, 0.7);
	glutSolidCone(0.8, 1, 15, 15);
	glPopMatrix();
}
void esfera(void) {

	//Dibujar una esfera s�lida

	glPushMatrix();
	glTranslatef(0.0, -0.31, -1.0);
	glRotatef(90, 0, 0, 1);
	glScalef(9.0,9.0, 9.0);
	//glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(0.065, 15, 30);
	glPopMatrix();
}
void esferapinata(void) {

	//Dibujar una esfera s�lida

	glPushMatrix();
	glTranslatef(0.0, -0.31, -1.0);
	glRotatef(90, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	//glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(0.065, 15, 30);
	glPopMatrix();
}
void cilindro(void) {

	//Dibujar cilindro
	glPushMatrix();
	//glColor3f(0.0, 1.0, 1.0);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glTranslatef(0.0, -0.3, -1.0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.35f, 0.35f, 0.95f, 50, 50);
	glPopMatrix();
}
void monito(){
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho
	glScalef(0.5, 0.5, 0.5);
	glColor3f(1.0, 0.0, 0.0);
	prisma(t_piso.GLindex, t_fachada.GLindex);

	glPushMatrix();//Cuello
	glTranslatef(0, 1.5, 1.0);

	glColor3f(1.0, 1.0, 1.0);
	cilindro();
	glPushMatrix();//Cabeza
	glTranslatef(0, -0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	esfera();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo derecho-->
	glTranslatef(1.0, 0.65, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	esfera();
	glPushMatrix();
	glTranslatef(0.25, 0, 0);
	glRotatef(0.0, 0.0, 0.0, 1.0);
	glRotatef(-45, 0, 1, 0);
	glTranslatef(0.75, 0, 0);
	glColor3f(1.0, 0.0, 0.0);
	prisma(t_piso.GLindex, t_fachada.GLindex);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo izquierdo <--
	glTranslatef(-1.0, 0.65, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	esfera();
	glPushMatrix();
	glTranslatef(-0.25, 0, 0);
	glRotatef(45, 0, 1, 0);
	glRotatef(25, 0, 0, 1);
	glRotatef(25, 1, 0, 0);
	glTranslatef(-0.75, 0, 0);
	glColor3f(1.0, 0.0, 0.0);
	prisma(t_piso.GLindex, t_fachada.GLindex);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Cintura
	glColor3f(0, 0, 1);
	glTranslatef(0, -1.5, 0);
	glColor3f(0.0, 0.0, 0.0);
	prisma(t_piso.GLindex, t_fachada.GLindex);

	glPushMatrix(); //Pie Derecho -->
	glTranslatef(0.75, -0.5, 0);
	glRotatef(-15, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	glColor3f(1.0, 0.0, 0.0);
	prisma(t_piso.GLindex, t_fachada.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	glColor3f(1.0, 0.0, 0.0);
	prisma(t_piso.GLindex, t_fachada.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	glColor3f(0.0, 0.0, 0.0);
	prisma(t_piso.GLindex, t_fachada.GLindex);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix(); //Pie Izquierdo -->
	glTranslatef(-0.75, -0.5, 0);
	glRotatef(-5, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	glColor3f(1.0, 0.0, 0.0);
	prisma(t_piso.GLindex, t_fachada.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(0.0, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	glColor3f(1.0, 0.0, 0.0);
	prisma(t_piso.GLindex, t_fachada.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	glColor3f(0.0, 0.0, 0.0);
	prisma(t_piso.GLindex, t_fachada.GLindex);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();


	glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();
}
void muneco() {
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glScalef(1.0, 0.4, 1.0);
	glTranslatef(0.0, 1.4, 0.0);
	cilindro();
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	esfera();
	glScalef(0.09, 0.09, 2.5);
	glColor3f(1.0, 0.5, 0.0);
	glTranslatef(0.0, -2.52, -0.2);
	cono();
	glColor3f(0.0, 0.0, 0.0);
	glScalef(2.0, 2.0, 0.05);
	glTranslatef(0.7, 0.52, 0.8);
	cono();
	glTranslatef(-1.5, 0.0, 0.0);
	cono();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -1.0, 1.0);

	glPushMatrix();
	glScalef(0.09, 0.09, 0.05);
	glTranslatef(-2.0, -2.0, -18.5);
	glColor3f(0.0, 0.0, 0.0);
	cono();
	glTranslatef(0.0, -2.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	cono();
	glPopMatrix();
	glScalef(2, 2, 2);
	glColor3f(1.0, 1.0, 1.0);
	esfera();

	glPopMatrix();
}
void casa() {
	//cuarto1
	//pared frontal

	glPushMatrix();
	glTranslatef(-8, -4, -9);
	glColor3f(1, 1, 1);
	glScalef(2, 4, 0.2);
	glRotatef(180, 0, 1, 0);
	prisma(t_piso.GLindex, t_fachada.GLindex);
	glPopMatrix();

	//pared frontal
	glPushMatrix();
	glTranslatef(-4, -4, -9);
	glScalef(2, 4, 0.2);
	glRotatef(180, 0, 1, 0);
	prisma(t_piso.GLindex, t_fachada.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10, -5, -9);
	glColor3f(1, 1, 1);
	glScalef(2, 2, 0.2);
	glRotatef(180, 0, 1, 0);
	prisma(t_piso.GLindex, t_fachada.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-11.5, -4, -9);
	glScalef(1.1, 4, 0.2);
	glRotatef(180, 0, 1, 0);
	prisma(t_piso.GLindex, t_fachada.GLindex);
	glPopMatrix();


	glPushMatrix();//inicio puerta
	glTranslatef(-6, -4, -10);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(2.0, 4.0, 2.0);
	cosa(t_puerta.GLindex);
	glPopMatrix();//fin puerta

	glPushMatrix();//inicio ventana
	glTranslatef(-10, -3, -10);
	glRotatef(90, 0, 0, 1);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(2.0, 2.0, 2.0);
	cosa(t_ventana.GLindex);
	glPopMatrix();//fin ventana

	glPushMatrix();
	glTranslatef(-12, -4, -15);
	glScalef(0.2, 4, 12);
	glRotatef(180, 0, 1, 0);
	prisma(t_piso.GLindex, t_fachada.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4, -4, -21);
	glColor3f(1, 1, 1);
	glScalef(16, 4, 0.2);
	prisma(t_piso.GLindex, t_fachada.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4, -4, -15);
	glColor3f(1, 1, 1);
	glScalef(0.2, 4, 12);
	prisma(t_piso.GLindex, t_fachada.GLindex);
	glPopMatrix();

	glPushMatrix();//inicio ventana
	glTranslatef(-2, -3, -10);
	glRotatef(90, 0, 0, 1);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(2.0, 2.0, 2.0);
	cosa(t_ventana.GLindex);
	glPopMatrix();//fin ventana

	glPushMatrix();
	glTranslatef(-2, -5, -9);
	glColor3f(1, 1, 1);
	glScalef(2, 2, 0.2);
	glRotatef(180, 0, 1, 0);
	prisma(t_piso.GLindex, t_fachada.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, -4, -9);
	glScalef(5, 4, 0.2);
	glRotatef(180, 0, 1, 0);
	prisma(t_piso.GLindex, t_fachada.GLindex);
	glPopMatrix();

	glPushMatrix();//piso
	glTranslatef(-4,-6,-15);
	glScalef(16,0.1,12);
	prisma(t_piso.GLindex, t_fachada.GLindex);
	glPopMatrix();//fin piso

	glPushMatrix();//inicio techo
	glTranslatef(-12, -1.999, -9);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(16.0, 6.0, 12.0);
	techo(t_techo.GLindex);
	glPopMatrix();//fin techo
}
void arbol() {
	//comienza el arbol
	glPushMatrix();//cuerpo general del arbol
		glPushMatrix();//push tallo	
		glTranslatef(-5, -5, -9);
		glScalef(0.25,2,0.25);
		prisma(t_tallo.GLindex, t_tallo.GLindex);
		glPopMatrix();//pop tallo
		glPushMatrix();//primer nivel de hojas
		glTranslatef(-5,-4.5,-9);
		glScalef(2,0.8,2);
		glRotatef(270, 1, 0, 0);
		cono2(t_hojas.GLindex);
		glPopMatrix();//fin prmer niel
		glPushMatrix();//segundo nivel
		glTranslatef(-5, -4.3, -9);
		glScalef(1.8, 0.8, 1.8);
		glRotatef(270, 1, 0, 0);
		cono2(t_hojas.GLindex);
		glPopMatrix();
		glPushMatrix();//tercer nivel
		glTranslatef(-5, -4.1, -9);
		glScalef(1.65, 0.8, 1.65);
		glRotatef(270, 1, 0, 0);
		cono2(t_hojas.GLindex);
		glPopMatrix();
		glPushMatrix();//cuarto nivel
		glTranslatef(-5, -3.9, -9);
		glScalef(1.5, 1, 1.5);
		glRotatef(270, 1, 0, 0);
		cono2(t_hojas.GLindex);
		glPopMatrix();
		glPushMatrix();//quinto nivel
		glTranslatef(-5, -3.7, -9);
		glScalef(1.35, 1, 1.35);
		glRotatef(270, 1, 0, 0);
		cono2(t_hojas.GLindex);
		glPopMatrix();
		glPushMatrix();//sexto nivel
		glTranslatef(-5, -3.5, -9);
		glScalef(1.2, 1, 1.2);
		glRotatef(270, 1, 0, 0);
		cono2(t_hojas.GLindex);
		glPopMatrix();
		glPushMatrix();//septimo nivel
		glTranslatef(-5, -3.3, -9);
		glScalef(1.05, 1, 1.05);
		glRotatef(270, 1, 0, 0);
		cono2(t_hojas.GLindex);
		glPopMatrix();
		glPushMatrix();//octavo nivel
		glTranslatef(-5, -3.1, -9);
		glScalef(0.9, 1, 0.9);
		glRotatef(270, 1, 0, 0);
		cono2(t_hojas.GLindex);
		glPopMatrix();
		glPushMatrix();//noveno nivel
		glTranslatef(-5, -2.9, -9);
		glScalef(0.75, 1, 0.75);
		glRotatef(270, 1, 0, 0);
		cono2(t_hojas.GLindex);
		glPopMatrix();
	glPopMatrix();//fin cuerpo arbol
}
void pinata(GLuint textura1, GLuint taxtura2) {
	//primero se va a dibujarla esfera de la pi�ata
	glBindTexture(GL_TEXTURE,textura1);
	glTranslatef(0, 0, 0);
	glScalef(1,1,1);
	esferapinata();

	
}
void coposVolador(GLuint textura1) {
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas V�rtice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas V�rtice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas V�rtice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas V�rtice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas V�rtice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas V�rtice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas V�rtice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas V�rtice 7 V7
	};

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
							//glColor3f(0.0,0.0,1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();

}
void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	if (mover_camara) {
		camPosX = objCamera.mPos.x; camPosY = objCamera.mPos.y; camPosZ = objCamera.mPos.z;
		camViewX = objCamera.mView.x; camViewY = objCamera.mView.y; camViewZ = objCamera.mView.z;
		camUpX = objCamera.mUp.x; camUpY = objCamera.mUp.y; camUpZ = objCamera.mUp.z; // POSICION INICIAL DE LA CAMARA
	}

	gluLookAt(camPosX, camPosY, camPosZ, //	INICIA VIENDO A LA CAMARA 1
		camViewX, camViewY, camViewZ,
		camUpX, camUpY, camUpZ);

	glRotatef(g_lookupdown, 0, 1, 0);


	glPushMatrix();
	glTranslatef(pos_camX, pos_camY, pos_camZ);
	glRotatef(eye_camX, 1.0, 0.0, 0.0);
	glRotatef(eye_camY, 0.0, 1.0, 0.0);
	glRotatef(eye_camZ, 0.0, 0.0, 1.0);

	//fondo chido
	glPushMatrix();
	glTranslatef(-4, 13.9, -15);
	glScalef(40, 40, 40);
	fondo(t_pasto.GLindex, t_fondo.GLindex, t_noche.GLindex);
	glPopMatrix();

	//copos de nieve
	glPushMatrix();

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
	glTranslatef(-4.0, 14.0, -17.0);
	glRotatef(-90, 0, 0, 1);
	glScalef(39, 39, 39);
	phantom(t_copos.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -4.0);
	glScalef(39, 39, 39);
	phantom(t_copos.GLindex);
	glPopMatrix();
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//copos de nieve
	glPushMatrix();

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTranslatef(-4.0, 14.0, -26.0);
	glPushMatrix();
	glTranslatef(-4.0, 14.0, -26.0);
	glRotatef(-90, 0, 0, 1);
	glScalef(39, 39, 39);
	phantom(t_copos.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -18.0);
	glScalef(39, 39, 39);
	phantom(t_copos.GLindex);
	glPopMatrix();
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();//fin copos

	glPushMatrix();//inicio casa

	glPushMatrix();//cosas de adentro de la casa


	glPushMatrix();
	glTranslatef(2, -3.0, -6);
	glScalef(1, 1, 1);
	glTranslatef(movPez, 0.0, 0.0);
	muneco();
	glPopMatrix();

	glTranslatef(-1, -4.0, -18);
	glPushMatrix();
	glTranslatef(-1, 0.9, 0);
	glScalef(1, 1, 1);
	monito();
	glPopMatrix();

	glPopMatrix();//fin de cosas de adentro de la casa

	//esferas
	glPushMatrix();
	glTranslatef(-10.95, -5, -20.5);
	glScalef(-2, -2, -2);
	glColor3f(1, 0, 0);
	esferapinata();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-10,-5,-20);
	glScalef(-2, -2, -2);
	glColor3f(1, 0, 0);
	esferapinata();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-10.5, -5, -20.1);
	glScalef(-2, -2, -2);
	glColor3f(1, 0, 0);
	esferapinata();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-9.5, -5, -20.1);
	glScalef(-2, -2, -2);
	glColor3f(1, 0, 0);
	esferapinata();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-9, -5, -20.5);
	glScalef(-2, -2, -2);
	glColor3f(1, 0, 0);
	esferapinata();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-8.95, -5, -21);
	glScalef(-2, -2, -2);
	glColor3f(1, 0, 0);
	esferapinata();
	glPopMatrix();

	casa();

	//nochebuenas
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTranslatef(-7, -5.4, -20);
	glScalef(1, 1, 0);
	glColor3f(1, 1, 1);
	glRotatef(270, 0, 0, 1);
	phantom(t_nochebuena.GLindex);
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTranslatef(-5, -5.4, -20);
	glScalef(1, 1, 0);
	glColor3f(1, 1, 1);
	glRotatef(270, 0, 0, 1);
	phantom(t_nochebuena.GLindex);
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTranslatef(-9, -5.4, -20);
	glScalef(1, 1, 0);
	glColor3f(1, 1, 1);
	glRotatef(270, 0, 0, 1);
	phantom(t_nochebuena.GLindex);
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	pinata(t_pinata.GLindex,t_pinata.GLindex);
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//corona
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTranslatef(-6, -3, -9.499);
	glRotatef(270, 0, 0, 1);
	phantom(t_corona.GLindex);
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();//para mover el arbol adentro de la casa
	glTranslatef(-5, 0, -10);
	arbol();
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();


	//MusicaChida();

	glutSwapBuffers();

}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}
void animar()
{
	if (g_fanimacion)
	{
		if (movPez < 0.7 && !tope) {
			movPez += 0.005;

			if (movPez >= 0.7)
				tope = true;
		}
		if (movPez > -1 * 1 && tope) {
			movPez -= 0.005;

			if (movPez <= -1 * 1)
				tope = false;
		}

	}

	glutPostRedisplay();
}
void animarF()
{
	if (g_fanimacionF)
	{
		if (movFantasma < 2 && !topeF) {
			movFantasma += 0.005;

			if (movFantasma1 < 1 && !topeF1) {
				movFantasma1 += 0.005;


				if (movFantasma1 >= 1)
					topeF1 = true;
			}
			if (movFantasma1 > -1 * 1 && topeF1) {
				movFantasma1 -= 0.005;

				if (movFantasma1 <= -1 * 1)
					topeF1 = false;
			}

			if (movFantasma >= 2)
				topeF = true;
		}
		if (movFantasma > -1 * 2 && topeF) {
			movFantasma -= 0.005;

			if (movFantasma1 < 1 && !topeF1) {
				movFantasma1 += 0.005;


				if (movFantasma1 >= 1)
					topeF1 = true;
			}
			if (movFantasma1 > -1 * 1 && topeF1) {
				movFantasma1 -= 0.005;

				if (movFantasma1 <= -1 * 1)
					topeF1 = false;
			}


			if (movFantasma <= -1 * 2)
				topeF = false;
		}

	}

	glutPostRedisplay();
}
void animacion()
{
	text_izq -= 0.01;
	text_der -= 0.01;
	if (text_izq < -1)
		text_izq = 0;
	if (text_der < 0)
		text_der = 1;

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		pos_camZ += 0.5f;
		//eye_camZ -= 0.5f;
		break;

	case 's':
	case 'S':
		pos_camZ -= 0.5f;
		//eye_camZ += 0.5f;
		break;

	case 'a':
	case 'A':
		pos_camX += 0.5f;
		//eye_camX -= 0.5f;
		break;
	case 'd':
	case 'D':
		pos_camX -= 0.5f;
		//eye_camX += 0.5f;
		break;
	case ' ':		//Poner algo en movimiento
		g_fanimacion ^= true; //Activamos/desactivamos la animac�on
		break;

	case 'F':
	case'f'://Poner algo en movimiento
		g_fanimacionF ^= true; //Activamos/desactivamos la animac�on
		break;

		//Agregar aqu� teclas para movimiento de luz
	case 'i':		//Movimientos de Luz
	case 'I':
		spin = (spin - 20) % 360;
		break;
	case 'k':
	case 'K':
		spin = (spin + 20) % 360;
		break;;


	case 'l':   //Activamos/desactivamos luz
	case 'L':
		light = !light;
		break;

	case 'p':   //Activamos/desactivamos luz
	case 'P':
		positional = !positional;
		break;

	case 'c':
		LightAngle += 2.0f;
		printf("Angulo = %f\n", LightAngle);
		break;
	case 'v':
		LightAngle -= 2.0f;
		printf("Angulo = %f\n", LightAngle);
		break;


	case '1':
		camPosX = objCamera2.mPos.x; camPosY = objCamera2.mPos.y; camPosZ = objCamera2.mPos.z;
		camViewX = objCamera2.mView.x; camViewY = objCamera2.mView.y; camViewZ = objCamera2.mView.z;
		camUpX = objCamera2.mUp.x; camUpY = objCamera2.mUp.y; camUpZ = objCamera2.mUp.z;
		mover_camara = false;
		break;

	case '2':
		camPosX = objCamera.mPos.x; camPosY = objCamera.mPos.y; camPosZ = objCamera.mPos.z;
		camViewX = objCamera.mView.x; camViewY = objCamera.mView.y; camViewZ = objCamera.mView.z;
		camUpX = objCamera.mUp.x; camUpY = objCamera.mUp.y; camUpZ = objCamera.mUp.z;
		mover_camara = true;
		break;

	case '3':
		camPosX = objCamera3.mPos.x; camPosY = objCamera3.mPos.y; camPosZ = objCamera3.mPos.z;
		camViewX = objCamera3.mView.x; camViewY = objCamera3.mView.y; camViewZ = objCamera3.mView.z;
		camUpX = objCamera3.mUp.x; camUpY = objCamera3.mUp.y; camUpZ = objCamera3.mUp.z;
		mover_camara = false;
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		if (mover_camara)
			objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		if (mover_camara)
			objCamera.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		if (mover_camara)
			objCamera.Rotate_View(-CAMERASPEED);
		break;
	case GLUT_KEY_RIGHT:
		if (mover_camara)
			objCamera.Rotate_View(CAMERASPEED);
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(600, 600);	// Tama�o de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("CASA NAVIDE�A"); // Nombre de la Ventana
	//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci�n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci�n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci�n de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutIdleFunc(animar);
	glutIdleFunc(animarF);
	glutMainLoop();          // 

	return 0;
}