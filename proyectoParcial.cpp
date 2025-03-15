#include "logo.h"



// Función para mover el cursor a una posición específica en la pantalla
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


// protoripos de funcion 
void delay(int ms);        //pausar
void setColor(int color);  //cambiar color 
void cafe(int color);



// Función para reproducir la música en segundo plano
void reproducirMusica() {
    LPCWSTR soundPath = L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\audio6.WAV"; //especifica la ubicacion del archivo de sonido
    PlaySound(soundPath, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);  // Reproduce en bucle
}

int main() {
    system("cls"); // Limpia la pantalla antes de mostrar el texto

    // Crear un hilo para la música
    thread musicaThread(reproducirMusica);

    int x = 30; // Ajusta esta variable para centrar el texto horizontalmente
    int y = 4;  // Ajusta esta variable para posicionar el texto verticalmente
    int color = 10; // Comienza con el color verde claro

    while (true) {

        cafe(color);

        // Cambiar color después de un pequeño delay (500ms)
        color = (color + 3) % 16;  // Cambiar entre colores de 0 a 9 (el límite de colores de la consola)
        delay(500); // Pausar 500 ms (medio segundo)

        // Verificar si se presionó una tecla
        if (_kbhit()) {
            char tecla = _getch(); // Obtener la tecla presionada
            if (tecla == 13) {  // Si la tecla es Enter (código 13)
                PlaySound(L"C:\\Users\\Castr\\source\\repos\\holaMundo\\x64\\Debug\\notificacion4.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
                mostrarNombres();

                break;  // Salir del ciclo
            }
        }
    }
    musicaThread.join();  // Espera a que el hilo de música termine
    return 0;
}

// Función para cambiar el color del texto
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Función para pausar la ejecución durante un cierto tiempo (en milisegundos)
void delay(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}


void cafe(int color) {
    gotoxy(0, 0);cout << "      `";
    setColor((color + 2) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(48, 10); cout << "       ( (\n";
    gotoxy(48, 11);cout << "        ) )\n";
    gotoxy(48, 12);cout << "     ........\n";
    gotoxy(48, 13);cout << "     |      |]  ";
    gotoxy(48, 14); cout << "     \\      /\n";
    gotoxy(48, 15);cout << "      `----'\n";
    gotoxy(48, 16);cout << "      DYL Cafe\n";
    setColor((color + 3) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(0, 0);cout << "      `";
}


void grafica(int color){

setColor((color + 1) % 16); // Cambia el color del texto, limita a un rango de 0-9

setColor((color + 8) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "     .       .    )     .        .   .       *             .    .   .. .     .     .         .   .           . .    .    . " << endl;
setColor((color + 9) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << ".       *             .     .        .   .   .       *             .         .            .    .     .     .    .  " << endl;
setColor((color + 10) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "            .      .               .   .       *             .         .     .                . .        .    .    " << endl;
setColor((color + 11) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "       .       .   .                   .         .   .       *             .         .      .       .             ." << endl;
setColor((color + 12) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "                 .       .             .                      .         .      .            *        . .    .      " << endl;
setColor((color + 13) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "     .       .            .   .         .         .    .       *    )         .         .   .       .  .   .  .  .  " << endl;
setColor((color + 14) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << ".       *             .     .         .   .       *             .         .    *             .         .   .    . ." << endl;
setColor((color + 15) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "            .      .    .   .        .   .. .  .         .       .   .       *             .         .        *          . " << endl;
setColor((color + 16) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "       .       .   .       *             .    .   .       *             .         .           .    .   .   .   .   " << endl;
setColor((color + 17) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "                 .      .   .                .         .       *             .         .            *   .  .  .    " << endl;
setColor((color + 18) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "     .   '               .       .       *   .   .       *             .         .          *      .         .    ." << endl;
setColor((color + 19) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "               - .    .   .               .         .     .      .       *             .         .      .     *    " << endl;
setColor((color + 1) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "     .       .          .        .   .       *             .         .     .         .   .           . .    .    . " << endl;
setColor((color + 2) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << ".       *             .     .        .   .   .       *             .         .            .    .     .     .    .  " << endl;
setColor((color + 3) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "            .      .               .   .       *             .         .     .                . .        .    .    " << endl;
setColor((color + 4) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "       .       .   .                   .     )    .   .       *             .         .      .       .            ." << endl;
setColor((color + 5) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "                 .       .             .                      .         .      .            *        . .    .      " << endl;
setColor((color + 6) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "     .   '               .       .       *      .   .     .         .             .         .      .     .     .   " << endl;
setColor((color + 7) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "             _.---._   .      .       *          .   .                .         .         .         .     .       *" << endl;
setColor((color + 8) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "   *       .'       '.   .    .   .        .   .. .  .         .       .   .       *            .       .          ." << endl;
setColor((color + 9) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "      _.-~===========~-.          .     .        .   .   .       *             .         .            .    .      ._" << endl;
setColor((color + 10) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "      (___________________)       .  .       .   .                   .     )       .         .      .       .      *" << endl;
setColor((color + 11) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << " __  .'     \_______/   .'  ______        __- .    .   .         .         .     .      .       *             .     " << endl;
setColor((color + 12) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "   |              .'  .'   |      |      |  |    .   .         .       *             .         .      .       .     " << endl;
setColor((color + 13) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "   |             '         |      |      |  |      .   .    . .      .            .         .   .       *           " << endl;
setColor((color + 14) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << "   |                       |      |   ___|  |_      .     .         .   .            .    *             .         . " << endl;
setColor((color + 15) % 16); // Cambia el color del texto, limita a un rango de 0-9
cout << " __|_______________________|__..--~~~~     ~--.  _ - .    .   .              .      .       *     .   .. .        . " << endl;
setColor((color + 16) % 16); // Cambia el color del texto, limita a un rango de 0-9

}