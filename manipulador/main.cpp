/*T145R - COMPUTAÇÃO GRÁFICA
Aluno(a): Yasmin Cristina de Souza, matricula: 2020101033

---TECLAS---
TECLA + e - : AMPLIA E REDUZ O OBJETO
TECLA SETA CIMA, BAIXO, DIREITA E ESQUERDA: MOVE O OBJETO PELO DISPLAY
TECLAS ESC E END: FECHA O PROGRAMA
TECLAS HOME: REINICIA TODO O DISPLAY E OBJETOS.
------------
MOUSE BOTÃO DIREITO: MOVE O OBJETO PELO DISPLAY
*/

#include <stdlib.h>
#include <gl\glut.h>
#include <cmath>

float cor[3] = {0,0,0};
int obj[4] = {-1,-1,-1,-1};

//Triângulo
float T[3][2] = {50,75,
				450,75,
				250,425
				};
				
//Quadrado				
float Q[4][2] = {75, 425,
				425,425,
				425,75,
				75,75
				};
				
//Circulo		
float C[3] = {150, 
			 250, 
			 250};

//Estrela
float E[6][2] = {250,475,
				450,125,
				50,125,
				50,375,
				450,375,
				250,25
				};
				
void Layout(){ 
	float x, y;
	float r = 30;

	//Cores superior
	glBegin(GL_QUADS);
	glColor3f(1,1,1); //1-Branca
	glVertex2f( 0, 500);
	glVertex2f( 0, 550);
	glVertex2f( 50, 550);
	glVertex2f( 50, 500);
	
	glColor3f(1,1,0); //2-Amarelo
	glVertex2f( 50, 500);
	glVertex2f( 50, 550);
	glVertex2f( 100, 550);
	glVertex2f( 100, 500);
	
	glColor3f(1,0.45,0); //3-Laranja
	glVertex2f( 100, 500);
	glVertex2f( 100, 550);
	glVertex2f( 150, 550);
	glVertex2f( 150, 500);
	
	glColor3f(1,0,0); //4-Vermelho
	glVertex2f( 150, 500);
	glVertex2f( 150, 550);
	glVertex2f( 200, 550);
	glVertex2f( 200, 500);
	
	glColor3f(1,0.6,10); //5-Rosa
	glVertex2f( 200, 500);
	glVertex2f( 200, 550);
	glVertex2f( 250, 550);
	glVertex2f( 250, 500);

	glColor3f(1,0,1); //6-Magenta
	glVertex2f( 250, 500);
	glVertex2f( 250, 550);
	glVertex2f( 300, 550);
	glVertex2f( 300, 500);

	glColor3f(0.6,0,10); //7-Roxo
	glVertex2f( 300, 500);
	glVertex2f( 300, 550);
	glVertex2f( 350, 550);
	glVertex2f( 350, 500);

	glColor3f(0,0,0.8); //8-Azul escuro
	glVertex2f( 350, 500);
	glVertex2f( 350, 550);
	glVertex2f( 400, 550);
	glVertex2f( 400, 500);
	
	glColor3f(0,0.8,20); //9-Azul claro
	glVertex2f( 400, 500);
	glVertex2f( 400, 550);
	glVertex2f( 450, 550);
	glVertex2f( 450, 500);

	glColor3f(0,0.5,0); //10-Verde escuro
	glVertex2f( 450, 500);
	glVertex2f( 450, 550);
	glVertex2f( 500, 550);
	glVertex2f( 500, 500);

	glColor3f(0,2,0); //11-Verde claro
	glVertex2f( 500, 500);
	glVertex2f( 500, 550);
	glVertex2f( 550, 550);
	glVertex2f( 550, 500);

	glColor3f(0.5,0.20,0); //12-Marrom
	glVertex2f( 550, 500);
	glVertex2f( 550, 550);
	glVertex2f( 600, 550);
	glVertex2f( 600, 500);
	glEnd();
	
	//retangulo para menu
	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex2f( 500, 500);
	glVertex2f( 600, 500);
	glVertex2f( 600, 0);
	glVertex2f( 500, 0);
	glEnd();
	
	//TRIANGULO
	glBegin(GL_TRIANGLES);
	glColor3f(0,0,0); //PRETO
	glVertex2f( 550, 475);
	glVertex2f( 575, 425);
	glVertex2f( 525, 425);
	glEnd();
	
	//QUADRADO
	glBegin(GL_QUADS);
	glColor3f(0,0,0); //PRETO
	glVertex2f( 525, 325);
	glVertex2f( 525, 375);
	glVertex2f( 575, 375);
	glVertex2f( 575, 325);
	glEnd();
	
	//ESTRELA
	glBegin(GL_TRIANGLES);
	glColor3f(0,0,0); //PRETO
	glVertex2f( 550, 190);
	glVertex2f( 580, 130);
	glVertex2f( 520, 130);
	
	glVertex2f( 520, 175);
	glVertex2f( 580, 175);
	glVertex2f( 550, 115);
	glEnd();
	
	//CIRCULO
	glBegin(GL_LINES);
	for (x = -r; x <= r; x++){
		y = pow((r * r ) - (x * x), 0.5);
		glVertex2f(x + 550, y + 250);
		glVertex2f(x + 550,-y + 250);
	}
	glEnd();
	
	//X - Saída (Reinicia os estados)
	glBegin(GL_QUADS);
	glColor3f(1,0,0); //VERMELHO
	glVertex2f( 520, 70);
	glVertex2f( 535, 80);
	glVertex2f( 575, 30);
	glVertex2f( 560, 20);

	glVertex2f( 520, 30);
	glVertex2f( 560, 80);
	glVertex2f( 575, 70);
	glVertex2f( 535, 20);
	glEnd();
	
		
	glColor3f(0,0,0); //PRETO 
	glLineWidth(5); //espessura da linha
	glBegin(GL_LINE_LOOP); //LINHA POLIGONAL FECHADA
	glVertex2f(0,550);
	glVertex2f(600,550);
	glVertex2f(600,0);
	glVertex2f(0,0);
	glEnd();
	
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(500,550);
	glVertex2f(500,0);
	
	glVertex2f(0,500);
	glVertex2f(600,500);
	
	for (int i = 0; i <= 600 ; i += 50){
		glVertex2f( i, 500);
		glVertex2f( i, 550);
	}
	for (int i = 0; i <= 550 ; i += 100){
		glVertex2f(500, i);
		glVertex2f(600, i);
	}
	glEnd();
	
	glLineWidth(1); //espessura da linha normal
	
}

void Objeto0(){
	//Triângulo
	glColor3f(cor[0],cor[1],cor[2]);
	glBegin(GL_TRIANGLES);
	glVertex2f( T[0][0],T[0][1]);
	glVertex2f( T[1][0],T[1][1]);
	glVertex2f( T[2][0],T[2][1]);
	glEnd();
}

void Objeto1(){
	//QUADRADO
	glColor3f(cor[0],cor[1],cor[2]);
	glBegin(GL_QUADS);
	glVertex2f(Q[0][0],Q[0][1]);
	glVertex2f(Q[1][0],Q[1][1]);
	glVertex2f(Q[2][0],Q[2][1]);
	glVertex2f(Q[3][0],Q[3][1]);
	glEnd();
}

void Objeto2(){
	 //Círculo
	float x, y;
	glColor3f(cor[0],cor[1],cor[2]);
	glBegin(GL_LINES);
		for ( x = -C[0]; x<= C[0]; x++){
			y = pow(C[0]*C[0] - x*x, 0.5);
			glVertex2f(x + C[1] , y + C[2]);
			glVertex2f(x + C[1] ,-y + C[2]);
		}
	glEnd();	 
	 
}

void Objeto3(){
	//ESTRELA
	glColor3f(cor[0],cor[1],cor[2]);
	glBegin(GL_TRIANGLES);
	glVertex2f(E[0][0],E[0][1]);
	glVertex2f(E[1][0],E[1][1]);
	glVertex2f(E[2][0],E[2][1]);

	glVertex2f(E[3][0],E[3][1]);
	glVertex2f(E[4][0],E[4][1]);
	glVertex2f(E[5][0],E[5][1]);
	glEnd();
}

void Display(){
	glClearColor(0.8, 0.8, 0.8, 0);
	glClear(GL_COLOR_BUFFER_BIT );
		
		if(obj[0] == 1){
			Objeto0();
		} 
		if(obj[1] == 1){
			Objeto1();
		}
		if(obj[2] == 1){
			Objeto2();
		}
		if(obj[3] == 1){
			Objeto3();
		}
		
	Layout();
	glFlush();
}

void Mouse(int button, int state, int x, int y){	
	float d = 5;
	
	//CIMA
	if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_UP)){
		if ((obj[0] == 1) && (y < 225) && (x < 400) && (x > 150)){
			for (int i = 0; i < 3 ; i++){
				T[i][1] = T[i][1] + d;
			}
		}
		if ((obj[1] == 1) && (y < 225) && (x < 400) && (x > 150)){
			for (int i = 0; i < 4 ; i++){
				Q[i][1] = Q[i][1] + d;
			}
		}
		if ((obj[2] == 1) && (y < 225) && (x < 400) && (x > 150)){
			C[2] = C[2] + d;
		}
		if ((obj[3] == 1) && (y < 225) && (x < 400) && (x > 150)){
			for (int i = 0; i < 6 ; i++){
				E[i][1] = E[i][1] + d;
			}
		}
				
	}
	
	//BAIXO
	if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_UP)){
		if ((obj[0] == 1) && (y > 300) && (x < 400) && (x > 150 )){
			for (int i = 0; i < 3 ; i++){
				T[i][1] = T[i][1] - d;
			}
		}
		if ((obj[1] == 1) && (y > 300) && (x < 400) && (x > 150 )){
			for (int i = 0; i < 4 ; i++){
				Q[i][1] = Q[i][1] - d;
			}
		}
		if ((obj[2] == 1) && (y > 300) && (x < 400) && (x > 150 )){
			C[2] = C[2] - d;
		}
		if ((obj[3] == 1) && (y > 300) && (x < 400) && (x > 150 )){
			for (int i = 0; i < 6 ; i++){
				E[i][1] = E[i][1] - d;
			}
		}
	}
	
	//DIREITA
	if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_UP)){
		if ((obj[0] == 1) && (y < 550) && (x <= 525) && (x >= 400)){
			for (int i = 0; i < 3 ; i++){
				T[i][0] = T[i][0] + d;
			}
		}
		if ((obj[1] == 1) && (y < 550) && (x <= 525) && (x >= 400)){
			for (int i = 0; i < 4 ; i++){
				Q[i][0] = Q[i][0] + d;
			}
		}
		if ((obj[2] == 1) && (y < 550) && (x <= 525) && (x >= 400)){
			C[1] = C[1] + d;
		}		
		if ((obj[3] == 1) && (y < 550) && (x <= 525) && (x >= 400)){
			for (int i = 0; i < 6 ; i++){
				E[i][0] = E[i][0] + d;
			}
		}
	}
	
	//ESQUERDA
	if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_UP)){
		if ((obj[0] == 1) && (y < 550) && (x >= 0) && (x < 175)){
			for (int i = 0; i < 3 ; i++){
				T[i][0] = T[i][0] - d;
			}
		}
		if ((obj[1] == 1) && (y < 550) && (x >= 0) && (x < 175)){
			for (int i = 0; i < 4 ; i++){
				Q[i][0] = Q[i][0] - d;
			}
		}
		if ((obj[2] == 1) && (y < 550) && (x >= 0) && (x < 175)){
			C[1] = C[1] - d;
		}
		if ((obj[3] == 1) && (y < 550) && (x >= 0) && (x < 175)){
			for (int i = 0; i < 6 ; i++){
				E[i][0] = E[i][0] - d;
			}
		}
	}
	
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)){
		if (y < 50){
			if ( x < 50){
				cor[0] = 1;
				cor[1] = 1;
				cor[2] = 1;
			}
			else if ( x < 100){
				cor[0] = 1;
				cor[1] = 1;
				cor[2] = 0;
			}
			else if ( x < 150){
				cor[0] = 1;
				cor[1] = 0.45;
				cor[2] = 0;
			}
			else if ( x < 200){
				cor[0] = 1;
				cor[1] = 0;
				cor[2] = 0;
			}
			else if ( x < 250){
				cor[0] = 1;
				cor[1] = 0.6;
				cor[2] = 10;
			}
			else if ( x < 300){
				cor[0] = 1;
				cor[1] = 0;
				cor[2] = 1;
			}
			else if ( x < 350){
				cor[0] = 0.6;
				cor[1] = 0;
				cor[2] = 10;
			}
			else if ( x < 400){
				cor[0] = 0;
				cor[1] = 0;
				cor[2] = 0.8;
			}
			else if ( x < 450){
				cor[0] = 0;
				cor[1] = 0.8;
				cor[2] = 20;
			}
			else if ( x < 500){
				cor[0] = 0;
				cor[1] = 0.5;
				cor[2] = 0;
			}
			else if ( x < 550){
				cor[0] = 0;
				cor[1] = 2;
				cor[2] = 0;
			}
			else if ( x < 600){
				cor[0] = 0.5;
				cor[1] = 0.20;
				cor[2] = 0;
			}
		}
	
	if (x > 500){
		if (y > 50 && y < 150){
			obj[0] = -1 * obj[0];
		}
		else if (y > 150 && y < 250) {
			obj[1] = -1 * obj[1];
		}
		else if (y > 250 && y < 350) {
			obj[2] = -1 * obj[2];
		}
		else if (y > 350 && y < 450) {
			obj[3] = -1 * obj[3];
		}
		//Saída
		else if(y > 450){
			cor[0] = 0;
			cor[1] = 0;
			cor[2] = 0;
			
			for(int i = 0; i < 4; i++){
				obj[i] = -1;
			}
			
			//Reiniciando o Objeto
			T[0][0] = 50;  T[0][1] = 75;
			T[1][0] = 450; T[1][1] = 75;
			T[2][0] = 250; T[2][1] = 425;
			
			Q[0][0] = 75;  Q[0][1] = 425;
			Q[1][0] = 425; Q[1][1] = 425;
			Q[2][0] = 425; Q[2][1] = 75;
			Q[3][0] = 75;  Q[3][1] = 75;
			
			C[0] = 150;
			C[1] = 250;
			C[2] = 250;
			
			E[0][0] = 250; E[0][1] = 475;
			E[1][0] = 450; E[1][1] = 125;
			E[2][0] = 50;  E[2][1] = 125;
			E[3][0] = 50;  E[3][1] = 375;
			E[4][0] = 450; E[4][1] = 375;
			E[5][0] = 250; E[5][1] = 25;
		}
	}
	}
	Display();
}

void Teclado(unsigned char key, int x, int y){
	switch(key) {
		case '+':
			if (obj[0] == 1){
				for (int i = 0; i < 3; i++){
					T[i][0] = 1.10 * T[i][0] - 25;
					T[i][1] = 1.10 * T[i][1] - 25;
				}
			}
			if (obj[1] == 1){
				for (int i = 0; i < 4; i++){
					Q[i][0] = 1.10 * Q[i][0] - 25;
					Q[i][1] = 1.10 * Q[i][1] - 25;
				}
			}
			if (obj[2] == 1){
					C[0] = 1.10 * C[0];
			}
			if (obj[3] == 1){
				for (int i = 0; i < 6; i++){
					E[i][0] = 1.10 * E[i][0] - 25;
					E[i][1] = 1.10 * E[i][1] - 25;
				}
			}
		break;
		
		case '-':
			if (obj[0] == 1){
				for (int i = 0; i < 3; i++){
					T[i][0] = 0.90 * T[i][0] + 25;
					T[i][1] = 0.90 * T[i][1] + 25;
				}
			}
			if (obj[1] == 1){
				for (int i = 0; i < 4; i++){
					Q[i][0] = 0.90 * Q[i][0] + 25;
					Q[i][1] = 0.90 * Q[i][1] + 25;
				}
			}
			if (obj[2] == 1){
					C[0] = 0.90 * C[0];
			}
			if (obj[3] == 1){
				for (int i = 0; i < 6; i++){
					E[i][0] = 0.90 * E[i][0] + 25;
					E[i][1] = 0.90 * E[i][1] + 25;
				}
			}
		break;
		
		//Tecla ESCAPE(ESC)
		case 27:
			exit(0);
		break;
	}
	
	Display();
	glutPostRedisplay();
}

void TeclasEspeciais(int key, int x, int y) {
	float d = 5;
	switch(key) {
		case GLUT_KEY_UP:
			if (obj[0] == 1){
				for (int i = 0; i < 3; i++){
					T[i][1] = T[i][1] + d;
				}
			}
			if(obj[1] == 1){
				for (int i = 0; i < 4; i++){
					Q[i][1] = Q[i][1] + d;
				}
			}
			if(obj[2] == 1){
				C[2] = C[2] + d;
			}
			if(obj[3] == 1){
				for (int i = 0; i < 6; i++){
					E[i][1] = E[i][1] + d;
				}
			}
		break;
		
		case GLUT_KEY_DOWN:
			if (obj[0] == 1){
				for (int i = 0; i < 3; i++){
					T[i][1] = T[i][1] - d;
				}
			}
			if(obj[1] == 1){
				for (int i = 0; i < 6; i++){
					Q[i][1] = Q[i][1] - d;
				}
			}
			if(obj[2] == 1){
				C[2] = C[2] - d;
			}
			if(obj[3] == 1){
				for (int i = 0; i < 6; i++){
					E[i][1] = E[i][1] - d;
				}
			}
		break;
		
		case GLUT_KEY_RIGHT:
			if (obj[0] == 1){
				for (int i = 0; i < 3; i++){
					T[i][0] = T[i][0] + d;
				}
			}
			if(obj[1] == 1){
				for (int i = 0; i < 6; i++){
					Q[i][0] = Q[i][0] + d;
				}
			}
			if(obj[2] == 1){
				C[1] = C[1] + d;
			}
			if(obj[3] == 1){
				for (int i = 0; i < 6; i++){
					E[i][0] = E[i][0] + d;
				}
			}
		break;
		
		case GLUT_KEY_LEFT:
			if (obj[0] == 1){
				for (int i = 0; i < 3; i++){
					T[i][0] = T[i][0] - d;
				}
			}
			if(obj[1] == 1){
				for (int i = 0; i < 4; i++){
					Q[i][0] = Q[i][0] - d;
				}
			}
			if(obj[2] == 1){
				C[1] = C[1] - d;
			}
			if(obj[3] == 1){
				for (int i = 0; i < 6; i++){
					E[i][0] = E[i][0] - d;
				}
			}
		break;
		
		case GLUT_KEY_HOME:
			cor[0] = 0;
			cor[1] = 0;
			cor[2] = 0;
			
			for(int i = 0; i < 4; i++){
				obj[i] = -1;
			}
			
			//Reiniciando o Objeto
			T[0][0] = 50;  T[0][1] = 75;
			T[1][0] = 450; T[1][1] = 75;
			T[2][0] = 250; T[2][1] = 425;
			
			Q[0][0] = 75;  Q[0][1] = 425;
			Q[1][0] = 425; Q[1][1] = 425;
			Q[2][0] = 425; Q[2][1] = 75;
			Q[3][0] = 75;  Q[3][1] = 75;
			
			C[0] = 150;
			C[1] = 250;
			C[2] = 250;
			
			E[0][0] = 250; E[0][1] = 475;
			E[1][0] = 450; E[1][1] = 125;
			E[2][0] = 50;  E[2][1] = 125;
			E[3][0] = 50;  E[3][1] = 375;
			E[4][0] = 450; E[4][1] = 375;
			E[5][0] = 250; E[5][1] = 25;
		
		break;
		
		case GLUT_KEY_END:
			exit(0);
		break;
	}
	Display();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize(600,550);
	glutInitWindowPosition(450,100);
	glutCreateWindow("AV2 - CG");
	
	glutMouseFunc(Mouse);
	glutKeyboardFunc(Teclado);
	glutSpecialFunc(TeclasEspeciais);
	
	gluOrtho2D(0,600,0,550);
	glutDisplayFunc(Display);
	glutMainLoop();
	return(0);
}
