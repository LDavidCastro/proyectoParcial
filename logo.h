#pragma once

#include <iostream>
#include <windows.h>  // Manipulación de la consola y colores (gotoxy(), setColor()).
#include <thread>     // reproducir musica, evita que el programa se bloquee miestras suena la musica 
#include <chrono>     //Pausas en milisegundos (std::this_thread::sleep_for).
#include <conio.h>    // Detección de teclas, Para usar _kbhit() y _getch()
#include <string>  
#include <iomanip>  // Para std::put_time  
#include <ctime>    // Para std::time_t, std::localtime  
#include < mmsystem.h >  //reproduccion de audio con PlaySound()
#pragma comment(lib, "winmm.lib")    // Indica al compilador que debe vincular la biblioteca winmm.lib, necesaria para PlaySound().
using namespace std;

void gotoxy(int x, int y);
void delay(int ms);        //pausar
void setColor(int color);  //cambiar color 
void mostrarNombres();
int generarNumeroAleatorio();
void grafica(int color);
void limpiarBuffer();

// menu principal 
void mostrarMenu();

//submenu compra
void compra();
string obtenerFechaActual();

//submenu venta
void Menu_Pila();

//submenu producto
void Menu_Lista();

//submenu trabajadores
void trabajadores(); 

//submenu cliente
void cliente();