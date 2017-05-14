#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
 
extern int errno;

/*размер карты*/
#define WIDTH_MAP 100
#define HEIGHT_MAP 100

Display *d;
Window w;
XEvent e;
int s,x,y,key_Escape,key_Up,key_Down,key_Left,key_Right,key_l,key_r,x_old,y_old,dx,dy,dx_old,dy_old,bx,by,ex,ey,ll,rl,am,first,dx_old1,dy_old1;
GC Def_GC;
Colormap screen_colormap;
Status status_red_color, status_white_color, status_black_color,status_orange_color;
XColor color_red, color_white, color_black,color_orange;
short int map_road[WIDTH_MAP][HEIGHT_MAP];

/*рисуем точку по координатам in_x и in_y с указанным цветом in_color, если его удалось получить то есть in_status_color не ноль иначе цвет кисти не меняется*/
void drawPoint(int in_x, int in_y, XColor in_color, Status in_status_color) {
	if (in_status_color!=0)
		XSetForeground(d, Def_GC, in_color.pixel);
	XDrawPoint( d, w, Def_GC, in_x, in_y);
}

/*печать пояснения о направлении движения, так как авто лишь точка*/
void PrintArrow(XColor in_color, Status in_status_color) {
	if (in_status_color!=0)
		XSetForeground(d, Def_GC, in_color.pixel);
	if (am==1) XDrawString (d, w, Def_GC, 5, 165, "North", 5);
			else if (am==2) XDrawString (d, w, Def_GC, 5, 165, "East", 4);
				else if (am==3) XDrawString (d, w, Def_GC, 5, 165, "South", 5);
					else XDrawString (d, w, Def_GC, 5, 165, "West", 4);
}

/*стирание сообщении о не включенном поворотнике*/
void DelPrintErrorMove() {
	if (status_white_color!=0)
		XSetForeground(d, Def_GC, color_white.pixel);
	XDrawString (d, w, Def_GC, 60, 165, "NO Left-turn signal", 19);
	XDrawString (d, w, Def_GC, 60, 165, "NO Right-turn signal", 20);
}

/*сообщение о не включенном повортнике*/
void PrintErrorMove(int l_r) {
	DelPrintErrorMove();
	if (status_red_color!=0)
		XSetForeground(d, Def_GC, color_red.pixel);
	if (l_r==1)
		XDrawString (d, w, Def_GC, 60, 165, "NO Left-turn signal", 19);
		else
			XDrawString (d, w, Def_GC, 60, 165, "NO Right-turn signal", 20);
}

/*обработка движения авто*/
void moveAuto() {
	/*затираем старую отрисовку*/
	if (x<WIDTH_MAP&&y<HEIGHT_MAP)
		if (map_road[x][y]==1)//если на дороге, то цветом дороги иначе цветом формы
			drawPoint(x,y,color_black, status_black_color);
			else
				drawPoint(x,y,color_white, status_white_color);
		else
			drawPoint(x,y,color_white, status_white_color);
	if (e.xkey.keycode == key_Up) {//стрелка вверх всегда движение вперед по выбранному направлению
		if (am==1) y--;
			else if (am==2) x++;
				else if (am==3) y++;
					else x--;
		}
		else if (e.xkey.keycode == key_Down) {//стрелка вниз движение назад
			if (am==1) y++;
				else if (am==2) x--;
					else if (am==3) y--;
						else x++;
			}
			else if (e.xkey.keycode == key_Left) {//стрелка влево смена направления движения против часовой стрелки
				PrintArrow(color_white,status_white_color);
				if (am==1) am = 4;
					else am = am-1;
				PrintArrow(color_black,status_black_color);
				}
				else if (e.xkey.keycode == key_Right) {//стрелка влево смена направления движения по часовой стрелки
					PrintArrow(color_white,status_white_color);
					if (am==4) am = 1;
						else am = am+1;
					PrintArrow(color_black,status_black_color);
					}
	drawPoint(x,y,color_red, status_red_color);//отрисовка нового положения
	/*определяем изменение координат в пространстве*/
	dx	= x_old-x;
	dy	= y_old-y;
	x_old	= x;
	y_old	= y;
	if ((first==0)&&(dx!=dx_old||dy!=dy_old)) {//если не первая итерация и вектор движения изменился проверяем не перекресток ли это
		DelPrintErrorMove();
		/*определяем диапозон для анализа*/
		bx	= x-2;
		ex	= x+2;
		by	= y-2;
		ey	= y+2;
		if (bx<0) bx = 0;
		if (by<0) by = 0;
		if (ex>=WIDTH_MAP) ex = WIDTH_MAP-1;
		if (ey>=HEIGHT_MAP) ex = HEIGHT_MAP-1;
		/*считаем количество дорог выходящих из участка*/
		int k_road	= 0;
		int i;
		for(i=bx;i<ex;i++)
			if (map_road[i][by]==1) {
				k_road = k_road+1;
				break;
			}
		for(i=bx-1;i<=ex;i++)
			if (map_road[i][ey]==1) {
				k_road = k_road+1;
				break;
			}
		for(i=by;i<ey;i++)
			if (map_road[ex][i]==1) {
				k_road = k_road+1;
				break;
			}
		for(i=by-1;i<=ey;i++)
			if (map_road[bx][i]==1) {
				k_road = k_road+1;
				break;
			}
		if (k_road>2) {//если дорог более двух значит это перекресток
			if (dx_old==0) {
				if (dy_old1==1) {
					if (dx==1) {
						if (ll==0) PrintErrorMove(1);
					}
					else if (dx==-1) {
						if (rl==0) PrintErrorMove(2);
						}
				}
				else if (dy_old1==-1) {
					if (dx==1) {
						if (ll==0) PrintErrorMove(2);
					}
					else if (dx==-1) {
						if (rl==0) PrintErrorMove(1);
						}
					}
			}
			if (dy_old==0) {
				if (dx_old1==-1) {
					if (dy==1) {
						if (ll==0) PrintErrorMove(1);
					}
					else if (dy==-1) {
						if (rl==0) PrintErrorMove(2);
						}
				}
				else if (dx_old1==1) {
					if (dy==1) {
						if (ll==0) PrintErrorMove(2);
					}
					else if (dy==-1) {
						if (rl==0) PrintErrorMove(1);
						}
					}				
			}
		}
	}
	if ((dx_old1!=0&&dx_old1==-dx_old)||(dy_old1!=0&&dy_old1==-dy_old)) {//разворт
		if (ll==0) PrintErrorMove(1);
	}
	dx_old1	= dx_old;
	dy_old1	= dy_old;
	dx_old	= dx;
	dy_old	= dy;
	first	= 0;
}

void makeMap() {//формируем карту дорог
	int i;
	for(i=0; i<HEIGHT_MAP; i++) {
		map_road[60][i]	= 1;
		map_road[61][i]	= 1;
	}
	for(i=0; i<60; i++)
		map_road[i][40]	= 1;
	for(i=0; i<20; i++)
		map_road[20][i]	= 1;
	for(i=20; i<60; i++)
		map_road[i][20]	= 1;
}

void DrawMap() {//отрисовываем карту дорог
	int i,j;
	for(i=0; i<WIDTH_MAP; i++)
		for(j=0; j<HEIGHT_MAP; j++)
			if (map_road[i][j]==1)
				drawPoint(i,j,color_black, status_black_color);
}

void PrintSignal() {//печатаем сообщение, если включен повортник
	if (ll==1) {
		if (status_orange_color!=0)
			XSetForeground(d, Def_GC, color_orange.pixel);
	}
		else 
			if (status_white_color!=0)
				XSetForeground(d, Def_GC, color_white.pixel);
	XDrawString (d, w, Def_GC, 5, 150, "Left-turn signal", 16);
	if (rl==1) {
		if (status_orange_color!=0)
			XSetForeground(d, Def_GC, color_orange.pixel);
	}
		else 
			if (status_white_color!=0)
				XSetForeground(d, Def_GC, color_white.pixel);
	XDrawString (d, w, Def_GC, 5, 180, "Right-turn signal", 17);
}

int main( void ) {
  
  /*создаем окно*/
   if( ( d = XOpenDisplay( getenv( "DISPLAY" ) ) ) == NULL ) {
      printf( "Can't connect X server: %s\n", strerror( errno ) );
      exit( 1 );
   }
   s = DefaultScreen( d );
   w = XCreateSimpleWindow( d, RootWindow( d, s ),10, 10, 200, 200, 1,BlackPixel( d, s ), WhitePixel( d, s ) );
   XSelectInput( d, w, ExposureMask | KeyPressMask );
   XMapWindow( d, w );
 
 /*подкючаем графику*/
   Def_GC	= DefaultGC( d, s );
   screen_colormap	= DefaultColormap(d, s);
   color_red.red	= 65535;
   color_red.green	= 0;
   color_red.blue	= 0;
   status_red_color	= XAllocColor(d, screen_colormap, &color_red);
   color_white.red	= 65535;
   color_white.green	= 65535;
   color_white.blue	= 65535;
   status_white_color	= XAllocColor(d, screen_colormap, &color_white);
   color_black.red	= 0;
   color_black.green	= 0;
   color_black.blue	= 0;
   status_black_color	= XAllocColor(d, screen_colormap, &color_black);
   color_orange.red	= 65535;
   color_orange.green	= 42598;
   color_orange.blue	= 0;
   status_orange_color	= XAllocColor(d, screen_colormap, &color_orange);
   
   /*задаем начальные значения переменных*/
   x	= 20;
   y	= 20;
   x_old	= x;
   y_old	= y;
   dx	= 0;
   dy	= 0;
   dx_old	= 0;
   dy_old   = 0;
   ll	= 0;
   rl	= 0;
   am	= 1;
   first	= 1;
   dx_old1	= 0;
   dy_old1   = 0;
   
   /*определяем клавиши управления*/
   key_Escape	= XKeysymToKeycode(d, XK_Escape);
   key_Up		= XKeysymToKeycode(d, XK_Up);
   key_Down		= XKeysymToKeycode(d, XK_Down);
   key_Left		= XKeysymToKeycode(d, XK_Left);
   key_Right	= XKeysymToKeycode(d, XK_Right);
   key_l		= XKeysymToKeycode(d, XK_l);
   key_r		= XKeysymToKeycode(d, XK_r);
   
   makeMap();
   DrawMap();
   
   while( 1 ) {
      XNextEvent( d, &e );//получаем события
      if( e.type == Expose ) {//обработка изменений окна
		  DrawMap();
		  drawPoint(x,y,color_red, status_red_color);
		  PrintSignal();
		  PrintArrow(color_black,status_black_color);
      }
      if( e.type == KeyPress )//обработка нажатий клавиш
		{
			if (e.xkey.keycode == key_Escape)//выход по Эскейп
				break;
				else if (e.xkey.keycode == key_l) { //клавиша l левый повортник
					if (ll==0)
						ll = 1;
						else 
							ll = 0;
					PrintSignal();
					}
					else if (e.xkey.keycode == key_r) {//клавиша r правый повортник
						if (rl==0)
							rl = 1;
							else
								rl = 0;
						PrintSignal();
						}
						else moveAuto();
		}
   }
   XCloseDisplay( d );//закрываем соединение с Х сервером
   return 0;
}
