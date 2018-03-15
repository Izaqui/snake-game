#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>


typedef struct snake Snake;
struct snake{
	int coordinatey;
	int coordinatex;
	Snake* next;
};

typedef struct screen Screen;
struct screen{
	Snake* snake;
	int coordinatey;
	int coordinatex;
};

Screen* createScreen(Snake* snake, int y, int x){
	Screen* screen = (Screen*) malloc(sizeof(Screen));	
	if(screen != NULL){
		screen->coordinatey = y;
		screen->coordinatex = x;
		screen->snake = snake;
		return screen;
	}
	//lembrar de pesquisar como mandar erro pra tela
	return NULL;
	
}

int calculateMiddleScreen(int value){
	return value / 2;
}

//return some error e.g.
Snake* createSnake(int y, int x){
	int middley = calculateMiddleScreen(y);
	int middlex = calculateMiddleScreen(x);
	Snake* snake = (Snake*) malloc(sizeof(Snake));	
	if(snake != NULL){
		snake->coordinatey = middley;
		snake->coordinatex = middlex;
		return snake;
	}
}	
//Negao
/*comida* createComida(int y,int x){
	int middley = calculateMiddleScreen(y);
	int middlex = calculateMiddleScreen(x);
    Comida* comida = (Comida*) malloc(sizeof(Comida));	
	if(comida != NULL){
		comida->coordinatey = middley;
		comida->coordinatex = middlex;
		return comida;
	}	
} 
//criar comida ...
/*
void gerarComida(){
	
}
*/
int moveOnKeyboard(){
	int ch = getch();
	switch(ch){
		case KEY_LEFT:
			return KEY_LEFT;
			break;
		case KEY_RIGHT:
			return KEY_RIGHT;
			break;
		case KEY_UP:
			return KEY_UP;
			break;
		case KEY_DOWN:
			return KEY_DOWN;
			break;
		default:
			NULL;
	}
}

void showSnake(Snake* snake){
	while(true){
		mvaddch(snake->coordinatey, snake->coordinatex, ACS_DIAMOND);
		wrefresh(stdscr);
	}
}

void drawMenu(){
	int coordx = (COLS / 2) - 1;
	int coordy = (LINES / 2) - 1;
	mvprintw(coordy, coordx-9, "Snake Game");
	mvprintw(coordy+1, coordx-14, "Press Enter to Start");
	mvprintw(coordy+2, coordx-12, "Press ESC to Exit");
}

void draw(int *ymax, int *xmax){
	initscr();
	noecho();	
	cbreak();
	keypad(stdscr, TRUE); //teclas do teclado funcionarem
	curs_set(0); //desabilitar cursor
	timeout(5000);
	getmaxyx(stdscr, *ymax, *xmax); // recupera as as coordenadas da tela -1
}

void killScreen(){
	endwin();
}

void freeSnake(Snake* snake){
	free(snake);
}

void freeBoard(Screen* screen){
    free(screen);
}
//Negão
/*void addRabo{
	if(snake->coordinatex == comida)//(snake->coordinatex == comida){
	  Snake*next = snake;
	}
}
*/

void shutdown(Screen* screen){
	printw("O programa foi finalizado, aperte Enter pra sair!!");
	getch();
	freeSnake(screen->snake);
	freeBoard(screen);
	killScreen();
}

void moveSnake(Snake* snake) {
	while(snake != NULL){
		snake->coordinatex = snake->coordinatex - 1;
		mvaddch(snake->coordinatey, snake->coordinatex, ACS_DIAMOND);
		refresh();
		snake = snake->next;
	}

}


//a coordenada y é de cima pra baixo no ecrã
int main(int argc, char const *argv[]){	
	int xmax, ymax;
	initscr();
	noecho();	
	cbreak();
	keypad(stdscr, TRUE); //teclas do teclado funcionarem
	curs_set(0); //desabilitar cursor
	timeout(100);
	getmaxyx(stdscr, ymax, xmax); // recupera as as coordenadas da tela -1
	
	Screen* screen = createScreen(createSnake(ymax, xmax), ymax, xmax);
	
	while(true){
		clear();
		moveSnake(screen->snake);
		int key = getch();
    	switch(key){
    		case KEY_LEFT:
                //{  snake->coordinatex = snake->coordinatex + 1;}  //movimento //Negao
    		
    		//	showSnake(screen->snake, );
				refresh();
				break;
    		case KEY_RIGHT:
    		    //{  snake->coordinatex = snake->coordinatex - 1;}  //movimento //Negao
    		
    		
			//	showSnake(screen->snake, KEY_RIGHT);
    			refresh();
				break;
    		case KEY_UP:
    			//{snake->coordinatey = snake->coordinatey + 1;}  //movimento //Negao
    		
			//	showSnake(screen->snake, KEY_UP);
    			refresh();
				break;
    		case KEY_DOWN:
    		    //{snake->coordinatey = snake->coordinatey + 1;}  //movimento //Negao
			//	showSnake(screen->snake, KEY_DOWN);
				refresh();
				break;
			default:
				break;
			}
	}
	mvaddch(screen->snake->coordinatey-10, screen->snake->coordinatex-1, ACS_BLOCK);
	//showSnake(screen->snake, KEY_RIGHT);
	getch(); killScreen();
    return 0;
}
	 



	//key = nextMove(screen->snake);

	//showSnake(screen->snake);



	//Essa função é o Menu que eu ainda pretendo fazer
	//drawMenu();

	
	//moveSnake(screen->snake);

	// refresh();

	/*while(true) {
    	int key = getch();
    	switch(key){
    		case KEY_LEFT:
    			display_points(screen->snake);
				refresh();
				display_points2(screen->snake);
				break;
    		case KEY_RIGHT:
				display_points(screen->snake);
    			refresh();
				break;
    		case KEY_UP:
    			display_points(screen->snake);
				refresh();
				break;
    		case KEY_DOWN:
				display_points(screen->snake);
    			refresh();
				break;
    	}
	}
//27 ESC
//10 ENTER

	//if(key == 27){
	//	printw("Jogo Finalizado", key);
	//	killScreen();
	//	exit(0);
	//}

	


	//mvaddch = esse comando coloca o caracter no X,Y específico
	/*while(board->snake) {
		clear();
    	mvaddch(board->snake->coordinatex, board->snake->coordinatey, ACS_DIAMOND);
    	board->snake = board->snake->next;
    	refresh();
    	int key = getch();
    	switch(key){
    		case KEY_LEFT:
    			display_points();
				mvaddch(board->snake->coordinatex, board->snake->coordinatey-1, ACS_DIAMOND);
    			break;
    		case KEY_RIGHT:
    			mvaddch(board->snake->coordinatex+1, board->snake->coordinatey, ACS_DIAMOND);
    			break;
    		case KEY_UP:
    			mvaddch(board->snake->coordinatex, board->snake->coordinatey+1, ACS_DIAMOND);
    			break;
    		case KEY_DOWN:
    			mvaddch(board->snake->coordinatex, board->snake->coordinatey-1, ACS_DIAMOND);
    			refresh();
    			break;
    	}

  	}
*/

