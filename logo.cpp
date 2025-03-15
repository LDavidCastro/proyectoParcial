#include"logo.h"

// Función que genera un número aleatorio entre 1 y 10
int generarNumeroAleatorio() {
    return (rand() % 16) + 1;
}

void nombres(int color);
void mostrarNombres() {
    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo10.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse

    system("cls");
    while (true) {
  
        // Mostrar el logo de la empresa
        int color = generarNumeroAleatorio();
        grafica(color);
        nombres( color);
  
        delay(500); // Pausar 500 ms (medio segundo)

        // Verificar si se presionó una tecla
        if (_kbhit()) {
            char tecla = _getch(); // Obtener la tecla presionada
            if (tecla == 13) {  // Si la tecla es Enter (código 13)
                PlaySound(L"C:\\Users\\Castr\\source\\repos\\holaMundo\\x64\\Debug\\notificacion4.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
                mostrarMenu();  // Llamar al menú

                break;  // Salir del ciclo
            }
        }
    }
}


void nombres(int color) {
    setColor((color + 1) % 16); // Cambia el color del texto, limita a un rango de 0-9
    // Centrado de la primera parte del texto
    gotoxy(5, 3); cout << "*****************************************************************************************************************" << endl;
    setColor((color + 2) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(5, 4); cout << "*      L     U   U III SSSSS   DDDD   AAAAA  V   V III DDDD     CCCCC  AAAAA  SSSSS TTTTT RRRR   OOO            *" << endl;
    gotoxy(5, 5); cout << "*      L     U   U  I  S       D   D A     A V   V  I  D   D   C      A     A S       T   R   R O   O           *" << endl;
    gotoxy(5, 6); cout << "*      L     U   U  I  SSS     D   D AAAAAAA V   V  I  D   D   C      AAAAAAA SSSSS   T   RRRR  O   O           *" << endl;  
    gotoxy(5, 7); cout << "*      L     U   U  I     S    D   D A     A  V V   I  D   D   C      A     A    S    T   R  R  O   O           *" << endl;   
    gotoxy(5, 8); cout << "*      LLLLL  UUU  III SSSSS   DDDD  A     A   V   III DDDD     CCCCC A     A SSSSS   T   R   R  OOO            *" << endl;
    setColor((color + 1) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(5, 9); cout << "*****************************************************************************************************************" << endl;


    setColor((color + 8) % 16); // Cambia el color del texto, limita a un rango de 0-9
    // Centrado de la segunda parte del texto
    gotoxy(5, 12); cout << "*****************************************************************************************************************" << endl;
    setColor((color + 9) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(5, 13); cout << "*     Y   Y EEEEE FFFFF EEEEE RRRR  SSSSS  OOO  N   N   DDDD   AAAAA  V   V III DDDD    JJJ  OOO  JJJ           *" << endl;
    gotoxy(5, 14); cout << "*      Y Y  E     F     E     R   R S     O   O NN  N   D   D A     A V   V  I  D   D    J  O   O  J            *" << endl;
    gotoxy(5, 15); cout << "*       Y   EEEE  FFFF  EEEE  RRRR  SSSSS O   O N N N   D   D AAAAAAA V   V  I  D   D    J  O   O  J            *" << endl;
    gotoxy(5, 16); cout << "*       Y   E     F     E     R  R      S O   O N  NN   D   D A     A  V V   I  D   D    J  O   O  J            *" << endl;
    gotoxy(5, 17); cout << "*       Y   EEEEE F     EEEEE R   R SSSSS  OOO  N   N   DDDD  A     A   V   III DDDD     J   OOO   J            *" << endl;
    setColor((color + 8) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(5, 18); cout << "*****************************************************************************************************************" << endl;


    setColor((color + 15) % 16); // Cambia el color del texto, limita a un rango de 0-9
    // Centrado de la tercera parte del texto
    gotoxy(5, 21); cout << "*****************************************************************************************************************" << endl;
    setColor((color + 16) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(5, 22); cout << "* DDDD  III L      AAAAA  N   N    AAAAA  BBBB  III M   M  AAAAA  EEEEE L       CCCCC  OOO  JJJ TTTTT III N   N *" << endl;
    gotoxy(5, 23); cout << "* D   D  I  L     A     A NN  N   A     A B   B  I  MM MM A     A E     L       C     O   O  J    T    I  NN  N *" << endl;
    gotoxy(5, 24); cout << "* D   D  I  L     AAAAAAA N N N   AAAAAAA BBBBB  I  M M M AAAAAAA EEEE  L       C     O   O  J    T    I  N N N *" << endl;
    gotoxy(5, 25); cout << "* D   D  I  L     A     A N  NN   A     A B   B  I  M   M A     A E     L       C     O   O  J    T    I  N  NN *" << endl; 
    gotoxy(5, 26); cout << "* DDDD  III LLLLL A     A N   N   A     A BBBB  III M   M A     A EEEEE LLLLL   CCCCC  OOO   J    T   III N   N *" << endl;
    setColor((color + 15) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(5, 27); cout << "*****************************************************************************************************************" << endl;

}