#ifndef PILAR_H
#define PILAR_H
#include <curses.h>
#include <vector>
using namespace std;
class Pilar
{
    vector<int> discos;
    void pintardisco(int num_disk, int coory, int coorx, WINDOW *ventana)
    {
        //LLena el vector de numeros de discos
        for (int i = 1; i < num_disk; i++)
        {
            discos.push_back(i);
        }
        //Colorea los discos
        int maxy, maxx;
        getmaxyx(ventana, maxy, maxx);
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        wattron(ventana,COLOR_PAIR(1));
        for (int i = 0; i < discos.size(); i++)
        {
            int cont = 1;
            mwprintw(ventana, coory, coorx - cont, " ");
            mwprintw(ventana, coory, coorx + cont, " ");
            cont++;
        }
         wattron(ventana,COLOR_PAIR(1));
         touchwin(ventana);
         wrefresh(ventana);
    }
};
#endif