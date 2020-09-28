
#include <curses.h>
#include <vector>
#include <iostream>
using namespace std;
WINDOW *ventana, *ventana2;
/*void pintardisco(int num_disk, int coory, int coorx, WINDOW *ventana3)
{
       vector<int> discos;
       //LLena el vector de numeros de discos
       for (int i = 1; i <= num_disk; i++)
       {
              discos.push_back(i);
       }
       //Colorea los discos
       start_color();
       init_pair(3, COLOR_WHITE, COLOR_RED);
       wattron(ventana3, COLOR_PAIR(3));
       int tam = 3;
       for (int i = 0; i < discos.size(); i++)
       {
              for (int j = 0; j < tam; j++)
              {
                     mvwprintw(ventana3, coory + tam, coorx + j, " ");
                     mvwprintw(ventana3, coory + tam, coorx - j, " ");
              }

              tam++;
       }
       wattroff(ventana3, COLOR_PAIR(3));
       touchwin(ventana3);
       wrefresh(ventana3);
}*/
void hanoi(WINDOW *ventana3, int disc, vector<int> O, vector<int> A, vector<int> D)
{
       getchar();

       if (disc == 1)
       {
              cout << "Movi un disco" << endl;
       }
       else
       {
              hanoi(ventana3, disc - 1, O, D, A);

              cout << "Movi otro disco" << disc << endl;

              hanoi(ventana3, disc - 1, A, O, D);
       }
}
void impresion(WINDOW *ventana2, int num_disk, vector<int> O, vector<int> A, vector<int> D)
{
      
       int maxy2,maxx2;
        getmaxyx(ventana2, maxy2, maxx2);
       start_color();
       init_pair(1, COLOR_BLACK, COLOR_WHITE);
       wattron(ventana2, COLOR_PAIR(1));
       //Aqui va el palo 1
       for (int i = 0; i < maxy2; i++)
       {
              for (int j = 0; j < maxx2; j++)
              {
                     if (j == ((maxx2 / 2) - 20))
                     {
                            mvwprintw(ventana2, i, j, " ");
                     }
              }
       }
       //Esto pone los discos en el palo 1
       wattroff(ventana2, COLOR_PAIR(1));
       int coorx = ((maxx2 / 2) - 20);
       init_pair(3, COLOR_WHITE, COLOR_RED);
       wattron(ventana2, COLOR_PAIR(3));
       int tam = 3;
       for (int i = 0; i < num_disk; i++)
       {
              for (int j = 0; j < tam; j++)
              {
                     mvwprintw(ventana2, (maxy2 - (num_disk + 1)) + i, coorx + j, " ");
                     mvwprintw(ventana2, (maxy2 - (num_disk + 1)) + i, coorx - j, " ");
              }
              tam++;
       }
       wattroff(ventana2, COLOR_PAIR(3));

       //Aqui finaliza
       wattroff(ventana2, COLOR_PAIR(1));
       touchwin(ventana2);
       wrefresh(ventana2);

       // pintardisco(5, 0, coorx, ventana2);
       wattron(ventana2, COLOR_PAIR(1));
       //Aqui va el palo 2
       for (int i = 0; i < maxy2; i++)
       {
              for (int j = 0; j < maxx2; j++)
              {
                     if (j == (maxx2 / 2))
                     {
                            mvwprintw(ventana2, i, j, " ");
                     }
              }
       }
       wattroff(ventana2, COLOR_PAIR(1));
       touchwin(ventana2);
       wrefresh(ventana2);
       //Aqui va el palo 3
       wattron(ventana2, COLOR_PAIR(1));
       for (int i = 0; i < maxy2; i++)
       {
              for (int j = 0; j < maxx2; j++)
              {
                     if (j == ((maxx2 / 2) + 20))
                     {
                            mvwprintw(ventana2, i, j, " ");
                     }
              }
       }
       wattroff(ventana2, COLOR_PAIR(1));
       touchwin(ventana2);
       wrefresh(ventana2);
       //Este for es para la base de las torres
       wattron(ventana2, COLOR_PAIR(1));
       for (int i = 0; i < maxx2; i++)
       {
              if (i == ((maxx2 / 2) - 20))
              {
                     mvwprintw(ventana2, maxy2 - 1, i, "1");
              }
              else if (i == (maxx2 / 2))
              {
                     mvwprintw(ventana2, maxy2 - 1, i, "2");
              }
              else if (i == ((maxx2 / 2) + 20))
              {
                     mvwprintw(ventana2, maxy2 - 1, i, "3");
              }
              else if ((i != (maxx2 / 2) + 20) && (i != (maxx2 / 2)) && (i != ((maxx2 / 2) - 20)))
              {
                     mvwprintw(ventana2, maxy2 - 1, i, " ");
              }
       }
       wattroff(ventana2, COLOR_PAIR(1));
       touchwin(ventana2);
       wrefresh(ventana2);
}
int main()
{
       vector<int> discos1;
       vector<int> discos2;
       vector<int> discos3;
       int num_disk;
       num_disk = 5;
       int MaxY, MaxX;
       initscr();
       getmaxyx(stdscr, MaxY, MaxX);
       ventana = newwin(MaxY, MaxX, 0, 0);
       int maxy2 = MaxY / 2;
       int maxx2 = MaxX / 2;
       ventana2 = newwin(maxy2, maxx2, (MaxY / 2) - 7, (MaxX / 2) - 30);
       cbreak();
       noecho();
       start_color();
       init_pair(1, COLOR_BLACK, COLOR_WHITE);
       init_pair(2, COLOR_WHITE, COLOR_BLACK);
       keypad(ventana, TRUE);
       box(ventana, ACS_VLINE, ACS_HLINE);
       refresh();
       //Esto es lo de arriba
       mvwaddstr(ventana, 0, (MaxX / 2) - 17, " T O R R E S   D E   H A N O I ");
       mvwaddstr(ventana, MaxY - 1, (MaxX / 2) - 17, " P R O G R A M A C I O N   I I I ");
       wattron(ventana, COLOR_PAIR(1));
       mvwprintw(ventana, 3, (MaxX / 2) - 24, " MUESTRA DE MOVIMIENTOS NECESARIOS PASO A PASO ");
       wattroff(ventana, COLOR_PAIR(1));
       wattron(ventana, COLOR_PAIR(2));
       mvwprintw(ventana, 4, (MaxX / 2) - 9, "MOVIMIENTO # 000");
       wattroff(ventana, COLOR_PAIR(2));
       //Esta es mi segunda ventana
       impresion(ventana2, 5, discos1, discos2, discos3);
       //Esto es lo de abajo
       wattron(ventana, COLOR_PAIR(1));
       mvwprintw(ventana, MaxY - 5, (MaxX / 2) - 30, "Presione cualquier tecla para continuar o ESC para finalizar");
       wattroff(ventana, COLOR_PAIR(1));
       wattron(ventana, COLOR_PAIR(2));
       mvwprintw(ventana, MaxY - 4, (MaxX / 2) - 20, "Desarrollado por Diego Varela (119412222)");
       wattroff(ventana, COLOR_PAIR(2));
       // hanoi(ventana2, 5, discos1, discos2, discos3);
       touchwin(ventana);
       wrefresh(ventana);
       touchwin(ventana2);
       wrefresh(ventana2);
       getchar();
       endwin();
}