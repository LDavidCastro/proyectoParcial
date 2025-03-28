
#include "logo.h"



void limpiarBuffer() {
    cin.clear();           // Limpia errores en cin
    cin.ignore(10000, '\n'); // Descarta cualquier entrada previa
}

void mostrarMenu() {
    while (true) {
        system("cls"); // Limpia la pantalla

        int x = 45, y = 10;
        int opcion = 1;
        int tecla;
        PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo1.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse

        while (true) {
            system("cls");
            int numero = generarNumeroAleatorio();
           grafica(numero);
            setColor((numero + 2) % 16); // Cambia el color del texto, limita a un rango de 0-9
            gotoxy(45, 7);cout << "  .:Menu Principal:.";
            gotoxy(45, 8);cout << "Seleccione una opcion:";

            // Mostrar opciones
            for (int i = 1; i <= 6; i++) {
                gotoxy(x, y + i - 1);
                if (i == opcion) {
                    setColor(14);
                    cout << "-> ";
                }
                else {
                    setColor((numero + 3) % 16); // Cambia el color del texto, limita a un rango de 0-9
                    cout << "   ";
                }

                switch (i) {
                case 1: cout << "Compra (cola)"; break;
                case 2: cout << "Venta (pila)"; break;
                case 3: cout << "Producto(lista simple)"; break;
                case 4: cout << "Trabajadores(lista doblemente enlazada)";break;
                case 5: cout << "Clientes (lista circular)";break;
                case 6: cout << "Salir"; break;
                }
            }

            tecla = _getch();       //capturamos la tecla precionada
            if (tecla == 224) {     // detectar si es una tecla flechas  
                tecla = _getch();   // capturar el nuevo valor 
                if (tecla == 72 && opcion > 1) { // Flecha arriba
                    opcion--;
                    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo3.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
                }
                else if (tecla == 80 && opcion < 6) { // Flecha abajo
                    opcion++;
                    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo3.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
                }
            }
            else if (tecla == 13) { // Enter para seleccionar
                break;
            }
        }

        setColor(15);
        if (opcion == 6) {
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\notificacion8.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al salir
            Sleep(1000); // Espera un poco para que el sonido se reproduzca antes de cerrar
            break;
        } // Opción "Salir" cierra el programa

        switch (opcion) {
        case 1:
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo6.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
            compra();
            break;
        case 2:
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo6.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
            Menu_Pila();
            break;
        case 3:
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo6.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
            Menu_Lista();
            break;
        case 4:
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo6.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
            trabajadores();
            break;
        case 5:
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo6.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
            cliente();
            break;
        }   
    }
}
