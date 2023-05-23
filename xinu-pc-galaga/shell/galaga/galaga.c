
#include "titlescreen.h"
#include "playerImage.h"
#include "enemy.h"
#include "boss.h"
#include "gameover.h"
#include "shoot.h"
#include <xinu.h>

extern unsigned char tecla_actual;
extern unsigned char teclas[3];
extern int32 vidas;
extern pid32 pid2;
extern pid32 pid3;
typedef unsigned short u16;
#define RGB(r, g, b) (r | (g << 5) | (b << 10))
// #define REG_DISPCNT *(u16 *)0x4000000
#define extern videoBuffer
#define MODE3 3
#define BG2_ENABLE (1 << 10)
#define WHITE RGB(31, 31, 31)
#define BLACK RGB(0, 0, 0)

/*
#define BUTTON_A		(1<<0)
#define BUTTON_B		(1<<1)
#define BUTTON_SELECT	(1<<2)
#define BUTTON_START	(1<<3)
#define BUTTON_RIGHT	(1<<4)
#define BUTTON_LEFT		(1<<5)
#define BUTTON_UP		(1<<6)
#define BUTTON_DOWN		(1<<7)
#define BUTTON_R		(1<<8)
#define BUTTON_L		(1<<9)
#define KEY_DOWN_NOW(key)  (~(BUTTONS) & key)
*/
//#define BUTTONS *(volatile unsigned int *)0x4000130

#define BUTTON_ESC	0x01
#define BUTTON_A	0x24
#define BUTTON_B	0x25 
#define BUTTON_SELECT	0x03
#define BUTTON_A	0x24
#define BUTTON_START	0x2c
#define BUTTON_RIGHT	0x1f
#define BUTTON_LEFT	0x1e	
#define BUTTON_UP	'w'
#define BUTTON_DOWN 	's'	
#define BUTTON_R	'1'
#define BUTTON_L	'2'

//MACRO
#define KEY_DOWN_NOW(key)  (tecla_actual == key)

//Arreglo de teclas presionadas


//variable definitions
#define playerXspeed 2
#define playerYspeed 2
#define enemyspeed 1
#define fastXSpeed 3
#define fastYSpeed 2
#define N_EASY  9
#define N_HARD  9
#define N_SHOOTS 10
#define W_SCREEN 240
#define H_SCREEN 160

struct Object {
	volatile u16 x;
	volatile u16 y;
	volatile u16 w;
	volatile u16 h;
	volatile u16 speedX;
	volatile u16 speedY;
	volatile u16 state; // 0 no existe // 1 existe // 2 invl?
};
void setPixel(int x, int y, u16 color);
void drawRect(int x, int y, int width, int height, u16 color);
void drawHollowRect(int x, int y, int width, int height, u16 color);
void drawImage3(struct Object obj, const u16* image);
void delay_galaga();
void waitForVBlank();

//helpers
void initialize();
void drawEnemies();
void endGame();
int collision(struct Object object1, struct Object object2);


//objects


int32 itero;
struct Object screen;

int galaga() {
	send(pid2,0); //SE RESETEAN LOS TEXTOS DE PUNTAJE Y VIDAS
	itero = 1;
	//easy enemy wave set setup
	struct Object easyEnemies[N_EASY];
	for (int a = 0; a < N_EASY; a++) {
		easyEnemies[a].x = (28*a);
		easyEnemies[a].y = 0;
		easyEnemies[a].w = 20;
		easyEnemies[a].h = 20;
		easyEnemies[a].speedX = 0;
		easyEnemies[a].speedY = enemyspeed;
		easyEnemies[a].state = 1;
	} 
	easyEnemies[1].x = 240;
	easyEnemies[4].x = 240;
	easyEnemies[8].x = 240;
	//difficult enemies setup
	/*struct Object hardEnemies[N_HARD];
	for (int a = 0; a < N_HARD; a++) {
		hardEnemies[a].x = (28*a);
		hardEnemies[a].y = 0;
		hardEnemies[a].w = 20;
		hardEnemies[a].h = 20;
		hardEnemies[a].speedX = 0;
		hardEnemies[a].speedY = 30;
		hardEnemies[a].state = 1;
	} 
	hardEnemies[1].x = 240;
	hardEnemies[4].x = 240;
	hardEnemies[8].x = 240;*/
	//shots setup 
	struct Object shoots[10];
	for (int32 i = 0; i < N_SHOOTS; i++)
	{
		shoots[i].x = 0;
		shoots[i].y = 0;
		shoots[i].speedX = 0;
		shoots[i].speedY = -4;
		shoots[i].w = 5;
		shoots[i].h = 5;
		shoots[i].state=0;
	}
	
	//player setup
	struct Object player;
	player.state = 1;
	player.x = 120;
	player.y = 136;
	player.h = 20;
	player.y = 20;
	player.speedX = 0;
	player.speedY = 0;

	

	screen.x = 0;
	screen.y = 0;
	screen.w = W_SCREEN;
	screen.h = H_SCREEN;
	screen.speedX = 0;
	screen.speedY = 0;
	screen.state = 1;
	//initalize title screen
	print_text_on_vga(10, 20, "GALAGA ");
	drawImage3(screen, titlescreen);
	while(1) {
		if (KEY_DOWN_NOW(BUTTON_START)) {
			break;
		}
	}	
	
	//start black screen for drawing
	
	
	update(&player,easyEnemies,shoots);
	
	return 0;
}
int limpiarpantalla(){
	for (int i = 0; i < 240; i++) {
		for (int j = 0; j < 160; j++) {
			setPixel(i, j, BLACK);
		}
	}
}
int update (struct Object *player ,struct Object easyEnemies[],struct Object shoots[]) {
	int32 currentShot = 0;
	while(itero) {
		//go back to title screen if select button is pressed
		if (KEY_DOWN_NOW(BUTTON_SELECT)) {
			//initialize();
			galaga();
		}
		if (KEY_DOWN_NOW(BUTTON_ESC)) {
				//SALGO DEL JUEGO
				send(pid3,0);
				itero = 0;
		}

		//player input
		if (teclas[0] == 1)
		{
			currentShot = (currentShot +1)%N_SHOOTS;
			if (shoots[currentShot].state == 0)
			{
				/* code */
				shoots[currentShot].state = 1;
				shoots[currentShot].x = player->x;
				shoots[currentShot].y = player->y;
			}
			
		}
		
		if (teclas[1] == 1)
		{
			if (teclas[2] == 0 && player->x > 0)
			{
				//Solo esta presionando la A y esta dentro de la pantalla
				player->speedX = -playerXspeed;
			}else {
				//Estan presionados los dos 
				player->speedX = 0;
			}
		}else{
			if (teclas[2] == 1 && player->x < 216) {
				player->speedX = playerXspeed;
				//Solo esta presionado la D y esta dentro de la pantalla 
			}else {
				//no hay nada presionado entonces 
				player->speedX = 0;
			}
		}
		


		waitForVBlank();
		sleepms(50);
		limpiarpantalla();
		moveANDdraw(player,1,playerImage);
		//drawHollowRect(player.x - 1, player.y - 1, 26, 26, BLACK);
		//drawHollowRect(player.x - 2, player.y - 2, 28, 28, BLACK);
		//moveANDdraw(easyEnemies,N_EASY,enemy);
		//seePlayerColission(player,easyEnemies,N_EASY);
		//seeShootColission(easyEnemies,N_SHOOTS,shoots);
		//moveANDdraw(shoots,N_SHOOTS,shoot);

		

		//draw player
		/*
		
		//draw easy enemies with downward movement
		for (int a = 0; a < 9; a++) {
			// easyEnemies[a].enemyY += enemyspeed;
			drawImage3(easyEnemies[a].enemyX, easyEnemies[a].enemyY, 20, 20, enemy);
			if (collision(easyEnemies[a].enemyX, easyEnemies[a].enemyY, 20, 20, player.playerX, player.playerY)) {
				endGame();
				drawRect(easyEnemies[a].enemyX, easyEnemies[a].enemyY,  20, 20, BLACK);
				easyEnemies[a].enemyY = 0;
			}	
			if (easyEnemies[a].enemyY >= 160) {
				easyEnemies[a].enemyY = 0;
			}		
		}

		//draw shots

		
		//draw hard enemies
		for (int a = 0; a < 9; a++) {
			hardEnemies[a].enemyY += enemyspeed;
			drawImage3(hardEnemies[a].enemyX, hardEnemies[a].enemyY, 20, 20, enemy);
			if (collision(hardEnemies[a].enemyX, hardEnemies[a].enemyY, 20, 20, player.playerX, player.playerY)) {
				endGame();
				hardEnemies[a].enemyY = 0;
				drawRect(hardEnemies[a].enemyX, hardEnemies[a].enemyY,  20, 20, BLACK);
			}	
			if (hardEnemies[a].enemyY >= 228) {
				hardEnemies[a].enemyY = 0;
			}
			if ((hardEnemies[a].enemyY >= 200) && (easyEnemies[a].enemyY <=45)) {
				hardEnemies[a].enemyY = 160;
			}	
			//space enemies apart
			if ((hardEnemies[a].enemyY >= 200) && (easyEnemies[a].enemyY <=45)) {
				hardEnemies[a].enemyY = 160;
			}		
			if ((easyEnemies[a].enemyY >= 120) && (hardEnemies[a].enemyY >=170)) {
				hardEnemies[a].enemyY = 160;
			}							
		}	*/
		//draw fast enemy
		/*drawImage3(fast.fastX, fast.fastY, 15, 15, boss);
		drawHollowRect(fast.fastX - 1, fast.fastY - 1, 17, 17, BLACK);
		drawHollowRect(fast.fastX - 2, fast.fastY - 2, 19, 19, BLACK);
		if(collision(fast.fastX, fast.fastY, 15, 15, player.playerX, player.playerY)) {
			endGame();
			fast.fastY = 0;
			drawRect(fast.fastX, fast.fastY,  20, 20, BLACK);
		}		
		if (fast.fastX >= 240) {
			fast.fastX = 0;
		}
		if (fast.fastY >= 200) {
			fast.fastY = player.playerY - 20;
		}*/
	}	
	return 0;
}

int32 moveANDdraw(struct Object objs[] ,int32 count,const u16* image){
	for (int32 i = 0; i < count; i++)
	{
		if(objs[i].state == 1){
			objs[i].x += objs[i].speedX;
			objs[i].y += objs[i].speedY;
			drawImage3(objs[i],image);
		}
	}
	return 0;
}
int32 seePlayerColission(struct Object *player, struct Object enemys[] , int32 count){
	for (int a = 0; a < count; a++) {
			if (collision(player[0],enemys[a])) {
				endGame();
				drawRect(enemys[a].x, enemys[a].y,  20, 20, BLACK);
				enemys[a].y = 0;
			}	
			if (enemys[a].y >= 160) {
				enemys[a].y = 0;
			}		
		}
		return 0;
}
int32 seeShootColission(struct Object enemys[] , int32 count , struct Object shoots[]){
		for (int i = 0; i < N_SHOOTS; i++) {
			
			if (shoots[i].state == 1) {
				shoots[i].y += shoots[i].speedX;
				drawRect(shoots[i].x, shoots[i].y+4, 5, 5, BLACK);
				drawImage3(shoots[i], shoot);
				
				for (int j = 0; j < 9; j++) {
					// check hits of shoots
					if (collision(shoots[i],enemys[j])){
						drawRect(enemys[j].x, enemys[j].y,  20, 20, BLACK);
						drawRect(shoots[i].x, shoots[i].x+4, 5, 5, BLACK);
						enemys[j].y = 0;
						shoots[i].state = 0;
						send(pid2,1);
						//MATE A ALGUIEN AUMENTO PUNTAJE
					}
				}
			}
		}
		return 0;
}

int32 collision(struct Object obj1, struct Object obj2) {
	if (obj1.x > obj2.x + obj2.w)
	{
		return 0 ; 
	}
	if (obj1.x+obj1.w < obj2.x)
	{
		return 0 ; 
	}
	if (obj1.y > obj2.y + obj2.h)
	{
		return 0 ; 
	}
	if (obj1.y+obj1.h < obj2.y)
	{
		return 0 ; 
	}
	return 1; 
	
	
	
}

void endGame() {
	send(pid2,-1);
	if (vidas == 0)
	{
		//entre q creo el proceso 1 a cuando cree el proceso 3
		//start Game Over State
		while(1) {
			drawImage3(screen ,gameover);
			drawHollowRect(0, 0, 240, 160, WHITE);
			if (KEY_DOWN_NOW(BUTTON_ESC)) {
				send(pid3,0);
				itero=0;
			}
			if (KEY_DOWN_NOW(BUTTON_START))	{
				galaga();
			}
		}
	}
	
}
