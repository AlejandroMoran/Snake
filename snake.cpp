#include<ncurses.h>
#include<time.h>
#include <stdlib.h>
typedef struct {
	int posx,posy;
	} segmento;
int main () {
	segmento serpiente[8000];
	serpiente[0].posx=15;
	serpiente[0].posy=15;
	int segmentos=1;
	int d=-1;
// 	initscr();                      /* Start curses mode              */
// 	printw("Hello World !!!");      /* Print Hello World              */
// 	refresh();                      /* Print it on to the real screen */
// 	getch();                        /* Wait for user input */
// 	endwin();                       /* End curses mode                */
// 	return 0;
// 	}

		WINDOW * mainwin;
	initscr();
	clear();
	keypad(stdscr,TRUE);//le dices a la termina lque usare el teclado y mouse
	noecho();//para que la terminal no regrese lo que ingreso
	cbreak();//lo mismo
	curs_set(0);//desabilitar todo
	//printw("K PEDO MUNDO\n");
	refresh();
	nodelay(stdscr,TRUE);
// 	delwin();
	int lol,salir=1,t_a=0,poss=0,a,b,n=0,vida=0,dim_x,dim_y,x;
	getmaxyx ( stdscr , dim_y , dim_x );
	a=rand()%dim_y;
	b=rand()%dim_x;
    struct timespec tim,tim2;
    tim.tv_sec = 0;
    tim.tv_nsec=90000000;
	while (salir==1) {
		nanosleep(&tim,&tim2);
		lol = getch();
		if (vida>0) {
			vida--;
			}
		else {
			mvprintw(a ,b," ");
			a=random()%dim_y;
			b=random()%dim_x;
			mvprintw(a,b,"*");
			vida=300;
			}
		//mvprintw(16,15,"ta %d %d vs %d -- %d vs %d  ",t_a,b,serpiente[t_a].posx,a,serpiente[t_a].posy);
		if(b==serpiente[t_a].posx&&a==serpiente[t_a].posy) {
            tim.tv_nsec=tim.tv_nsec*.90;
			t_a++;
			serpiente[t_a].posx=serpiente[t_a-1].posx;
			serpiente[t_a].posy=serpiente[t_a-1].posy;
			vida=1;
			}
		if(lol==KEY_UP){
			d=lol;
			//mvprintw(serpiente[0].posy,serpiente[0].posx,"D");
			}
		else if(lol==KEY_DOWN){
			d=lol;
			//mvprintw(serpiente[0].posy,serpiente[0].posx,"D");
			}
		else if(lol==KEY_RIGHT){
			d=lol;
			//mvprintw(serpiente[0].posy,serpiente[0].posx,"D");
			}
		else if(lol==KEY_LEFT){
			d=lol;
			//mvprintw(serpiente[0].posy,serpiente[0].posx,"D");
			}
		///mvprintw(10,10,"dim %d %d ",dim_y,dim_x);
		//mvprintw(6,5,"%d %d ",serpiente[t_a].posx,serpiente[0].posx);
		int j=serpiente[0].posy;
		int k=serpiente[0].posx;
		mvprintw(j,k," ");
		//mvprintw(3,3,"ccc %d %d %d %d ",serpiente[poss].posy,serpiente[0].posy,serpiente[poss].posx,serpiente[0].posx);
		for(poss=0;poss<t_a;poss++){
			serpiente[poss].posx=serpiente[poss+1].posx;
			serpiente[poss].posy=serpiente[poss+1].posy;
			//mvprintw(3+poss,3,"ccc %d %d %d %d ",serpiente[poss].posy,serpiente[0].posy,serpiente[poss].posx,serpiente[0].posx);
			}
		if (d==KEY_UP) {
			if(serpiente[poss].posy<=0) {
				serpiente[poss].posy=dim_y;
			}
 			serpiente[t_a].posy--;
 			}
 		else if (d==KEY_DOWN) {
			if(serpiente[poss].posy>=dim_y){
				serpiente[poss].posy=0;
			}
			serpiente[t_a].posy++;
 			}
 		else if (d==KEY_RIGHT) {
			if(serpiente[poss].posx>=dim_x) {
				serpiente[poss].posx=0;
			}
 			serpiente[t_a].posx++;
 			}
 		else if (d==KEY_LEFT) {
			if (serpiente[poss].posx<=0) {
				serpiente[poss].posx=dim_x;
			}
 			serpiente[t_a].posx--;
 			}
		for (poss=0;poss<=t_a;poss++) {
			mvprintw(serpiente[poss].posy,serpiente[poss].posx,"S");
			}
		refresh();
		for(x=0;x<poss-1;x++) {
			if(serpiente[poss-1].posx==serpiente[x].posx&&serpiente[poss-1].posy==serpiente[x].posy){
				 salir=2;
				}
			}
		}
	if (salir==2){
// 		for(x=0;x<poss-1;x++) {
// 			if(serpiente[poss-1].posx==serpiente[x].posx&&serpiente[poss-1].posy==serpiente[x].posy){
// 				 salir=2;
// 				}
// 			}
        tim.tv_sec = 3;
        tim.tv_nsec=0;
        clear();
		mvprintw(20,20,"GG");
		refresh();
		nanosleep(&tim,&tim2);
		}
	endwin();
	delwin(mainwin);
return 0;
}
