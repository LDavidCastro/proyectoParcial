

#include "logo.h"


int color = 0;
// Estructura para almacenar la compra de café
struct CompraCafe {
    string vendedor;
    string tipoCafe;
    string region;
    int idNegociante;
    bool esSocio;
    string fechaCompra;
    double precioPorKg;
    double cantidadKg;
    double bonificacion;
    double totalCompra;
    string formaPago;
    string calidadCafe;
    double humedad;
    string comentarios;
};

struct nodoCompra {
    CompraCafe compra;
    nodoCompra* siguiente;
};

struct colaCompra {
    nodoCompra* delante;
    nodoCompra* atras;

    colaCompra() : delante(nullptr), atras(nullptr) {} // Constructor para inicializar la cola  
};

void ingredar(colaCompra& q);
string obtenerFechaActual();
void seleccionarTipoCafe(string& tipoCafe);
void seleccionarFormaPago(string& formaPago);
void seleccionarCalidadCafe(string& calidadCafe);
void encolarCompra(colaCompra& q, const CompraCafe& compra);

void mostrarCola(const colaCompra& q);

void modificarRecibo(colaCompra& q);
nodoCompra* buscarPorIdNegociante(colaCompra& q, int idNegociante);
void mostrarMenu(CompraCafe& compra);

void buscarYMostrarRecibo(const colaCompra& q);
void eliminarPrimerRecibo(colaCompra& q);



void compra() {

    colaCompra q; // Crear la cola de compras 

    while (true) {
        system("cls"); // Limpia la pantalla

        int x = 45, y = 10;
        int opcion = 1;
        int tecla;

        while (true) {
            system("cls");
            int numero = generarNumeroAleatorio();
            grafica(numero);
            setColor((numero + 2) % 16); // Cambia el color del texto, limita a un rango de 0-9
            gotoxy(45, 7);cout << "  .:SubMenu Compra de cafe:.";
            gotoxy(45, 8);cout << " Seleccione una opcion";

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
                case 1: cout << "Ingreso de datos del cafe "; break;
                case 2: cout << "Ver datos en forma de cola"; break;
                case 3: cout << "Modificar una compra"; break;
                case 4: cout << "Buscar una compra"; break;
                case 5: cout << "Eliminar una compra"; break;
                case 6: cout << "Regrasar el menu Principal"; break;
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
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo6.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
            Sleep(1000); // Espera un poco para que el sonido se reproduzca antes de cerrar
            break;
        } // Opción "Salir" cierra el programa

        switch (opcion) {
        case 1:
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo4.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
            ingredar(q);
            break;
        case 2:
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo6.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
            mostrarCola(q);
            _getch();
            break;
        case 3:
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo6.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
            modificarRecibo(q);
            break;
        case 4:
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo6.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
            buscarYMostrarRecibo(q);
            break;
        case 5:
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo6.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
            eliminarPrimerRecibo(q);
            break;
        }
    }
}


//opcion 1 
//ingresar
void ingredar(colaCompra& q) {
    string fechaCompra = obtenerFechaActual();
    CompraCafe compra;

    system("cls");
    setColor((color + 11) % 16); // Cambia el color del texto, limita a un rango de 0-9


    gotoxy(5, 1);cout << "******************************************************************************************";
    gotoxy(5, 2);cout << "*                            RECIBO DE COMPRA DE CAFE                                    *";
    gotoxy(5, 3);cout << "******************************************************************************************";
    gotoxy(5, 4); cout << "*  Informacion del Vendedor :                                                            *";
    gotoxy(5, 5);cout << "*  Nombre / ID del encargado de la compra :______________________________________        *";
    gotoxy(5, 6);cout << "*  ID del negociante : ______________________________________                            *";
    gotoxy(5, 7);cout << "******************************************************************************************";
    gotoxy(5, 8);cout << "*  Detalles de la Compra :                                                               *";
    gotoxy(5, 9);cout << "*  Tipo de cafe : ______________________________________                                 *";
    gotoxy(5, 10);cout << "*  Region de origen : ______________________________________                             *";
    gotoxy(5, 11);cout << "*  Fecha de la compra :_____________________________________                             * ";
    gotoxy(5, 12);cout << "*  Precio por kg : ______________________________________                                *";
    gotoxy(5, 13);cout << "*  Cantidad comprada(kg) : ______________________________________                        *";
    gotoxy(5, 14);cout << "******************************************************************************************";
    gotoxy(5, 15);cout << "*  Bonificacion :                                                                        *";
    gotoxy(5, 16);cout << "*  Es socio : [s]Si [n]No                                                                *";
    gotoxy(5, 17);cout << "*  Bonificacion(10 %) : __________________________________________________               *";
    gotoxy(5, 18);cout << "*  Total de la compra : ______________________________________                           *";
    gotoxy(5, 19);cout << "******************************************************************************************";
    gotoxy(5, 20);cout << "*  Forma de Pago :                                                                       *";
    gotoxy(5, 21);cout << "*  __________________________________________________                                    *";
    gotoxy(5, 22);cout << "******************************************************************************************";
    gotoxy(5, 23);cout << "*  Estandares de Calidad :                                                               *";
    gotoxy(5, 24);cout << "*  Calidad del cafe: ______________________________________                              *";
    gotoxy(5, 25);cout << "******************************************************************************************";
    gotoxy(5, 26);cout << "*  Notas o Comentarios Adicionales :                                                     *";
    gotoxy(5, 27);cout << "*  ___________________________________________________________________                   *";
    gotoxy(5, 28);cout << "* ___________________________________________________________________                    *";
    gotoxy(5, 29);cout << "******************************************************************************************";

    setColor((color + 12) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(29, 11);cout << fechaCompra;
    
    gotoxy(49, 5); getline(cin >> ws, compra.vendedor); // Usar ws para ignorar espacios  
    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\notificacion4.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse

    gotoxy(29, 6); cin >> compra.idNegociante;
    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\notificacion4.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse

    system("cls");
    setColor((color + 11) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(5, 1);cout << "******************************************************************************************";
    gotoxy(5, 2);cout << "*                            RECIBO DE COMPRA DE CAFE                                    *";
    gotoxy(5, 3);cout << "******************************************************************************************";
    gotoxy(5, 4); cout << "*  Informacion del Vendedor :                                                            *";
    gotoxy(5, 5);cout << "*  Nombre / ID del encargado de la compra :______________________________________        *";
    gotoxy(5, 6);cout << "*  ID del negociante : ______________________________________                            *";
    gotoxy(5, 7);cout << "******************************************************************************************";
    gotoxy(5, 8);cout << "*  Detalles de la Compra :                                                               *";
    gotoxy(5, 9);cout << "*  Tipo de cafe : ______________________________________                                 *";
    gotoxy(5, 10);cout << "*                                                                                        *";

    setColor((color + 12) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(49, 5); cout << compra.vendedor;
    gotoxy(29, 6); cout << compra.idNegociante;

    setColor((color + 3) % 16); // Cambia el color del texto, limita a un rango de 0-9
    // Obtener el tipo de café  
    seleccionarTipoCafe(compra.tipoCafe);
    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\notificacion4.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse

    system("cls");
    setColor((color + 11) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(5, 1);cout << "******************************************************************************************";
    gotoxy(5, 2);cout << "*                            RECIBO DE COMPRA DE CAFE                                    *";
    gotoxy(5, 3);cout << "******************************************************************************************";
    gotoxy(5, 4); cout << "*  Informacion del Vendedor :                                                            *";
    gotoxy(5, 5);cout << "*  Nombre / ID del encargado de la compra :______________________________________        *";
    gotoxy(5, 6);cout << "*  ID del negociante : ______________________________________                            *";
    gotoxy(5, 7);cout << "******************************************************************************************";
    gotoxy(5, 8);cout << "*  Detalles de la Compra :                                                               *";
    gotoxy(5, 9);cout << "*  Tipo de cafe : ______________________________________                                 *";
    gotoxy(5, 10);cout << "*  Region de origen : ______________________________________                             *";
    gotoxy(5, 11);cout << "*  Fecha de la compra :_____________________________________                             * ";
    gotoxy(5, 12);cout << "*  Precio por kg : ______________________________________                                *";
    gotoxy(5, 13);cout << "*  Cantidad comprada(kg) : ______________________________________                        *";
    gotoxy(5, 14);cout << "******************************************************************************************";
    gotoxy(5, 15);cout << "*  Bonificacion :                                                                        *";
    gotoxy(5, 16);cout << "*  Es socio : [s]Si [n]No                                                                *";
    gotoxy(5, 17);cout << "*  Bonificacion(10 %) : __________________________________________________               *";
    gotoxy(5, 18);cout << "*  Total de la compra : ______________________________________                           *";
    gotoxy(5, 19);cout << "******************************************************************************************";
    gotoxy(5, 20);cout << "*  Forma de Pago :                                                                       *";
    gotoxy(5, 21);cout << "*  __________________________________________________                                    *";
    gotoxy(5, 22);cout << "******************************************************************************************";
    gotoxy(5, 23);cout << "*  Estandares de Calidad :                                                               *";
    gotoxy(5, 24);cout << "*  Calidad del cafe: ______________________________________                              *";
    gotoxy(5, 25);cout << "******************************************************************************************";
    gotoxy(5, 26);cout << "*  Notas o Comentarios Adicionales :                                                     *";
    gotoxy(5, 27);cout << "*  ___________________________________________________________________                   *";
    gotoxy(5, 28);cout << "* ___________________________________________________________________                    *";
    gotoxy(5, 29);cout << "******************************************************************************************";

    setColor((color + 12) % 16); // Cambia el color del texto, limita a un rango de 0-16
    gotoxy(49, 5); cout << compra.vendedor;
    gotoxy(29, 6); cout << compra.idNegociante;
    gotoxy(24, 9); cout << compra.tipoCafe;
    gotoxy(29, 11);cout << fechaCompra;
    cin.ignore();
    gotoxy(28, 10); getline(cin, compra.region);
    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\notificacion4.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse


    gotoxy(25, 12); cin >> compra.precioPorKg;
    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\notificacion4.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse

    gotoxy(33, 13); cin >> compra.cantidadKg;
    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\notificacion4.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse

    gotoxy(32, 16);
    char respuesta;
    cin >> respuesta;
    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\notificacion4.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse

    compra.esSocio = (respuesta == 's' || respuesta == 'S');

    // Calcular bonificación si es socio
    compra.bonificacion = compra.esSocio ? (compra.precioPorKg * compra.cantidadKg * 0.10) : 0.0;

    // Calcular total de la compra
    compra.totalCompra = (compra.precioPorKg * compra.cantidadKg) + compra.bonificacion;
    cin.ignore();

    gotoxy(32, 17); cout << compra.bonificacion;
    gotoxy(32, 18); cout << compra.totalCompra;



    system("cls");
    setColor((color + 11) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(5, 1);cout << "******************************************************************************************";
    gotoxy(5, 2);cout << "*                            RECIBO DE COMPRA DE CAFE                                    *";
    gotoxy(5, 3);cout << "******************************************************************************************";
    gotoxy(5, 4); cout << "*  Informacion del Vendedor :                                                            *";
    gotoxy(5, 5);cout << "*  Nombre / ID del encargado de la compra :______________________________________        *";
    gotoxy(5, 6);cout << "*  ID del negociante : ______________________________________                            *";
    gotoxy(5, 7);cout << "******************************************************************************************";
    gotoxy(5, 8);cout << "*  Detalles de la Compra :                                                               *";
    gotoxy(5, 9);cout << "*  Tipo de cafe : ______________________________________                                 *";
    gotoxy(5, 10);cout << "*  Region de origen : ______________________________________                             *";
    gotoxy(5, 11);cout << "*  Fecha de la compra :_____________________________________                             * ";
    gotoxy(5, 12);cout << "*  Precio por kg : ______________________________________                                *";
    gotoxy(5, 13);cout << "*  Cantidad comprada(kg) : ______________________________________                        *";
    gotoxy(5, 14);cout << "******************************************************************************************";
    gotoxy(5, 15);cout << "*  Bonificacion :                                                                        *";
    gotoxy(5, 16);cout << "*  Es socio : [s]Si [n]No __________                                                     *";
    gotoxy(5, 17);cout << "*  Bonificacion(10 %) : __________________________________________________               *";
    gotoxy(5, 18);cout << "*  Total de la compra : ______________________________________                           *";
    gotoxy(5, 19);cout << "******************************************************************************************";
    gotoxy(5, 20);cout << "*  Forma de Pago :                                                                       *";
    gotoxy(5, 21);cout << "*  __________________________________________________                                    *";

    setColor((color + 12) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(49, 5); cout << compra.vendedor;
    gotoxy(29, 6); cout << compra.idNegociante;
    gotoxy(24, 9); cout << compra.tipoCafe;
    gotoxy(28, 10); cout << compra.region;
    gotoxy(29, 11);cout << fechaCompra;
    gotoxy(25, 12); cout << compra.precioPorKg;
    gotoxy(33, 13);cout << compra.cantidadKg;
    gotoxy(33, 16);cout << compra.esSocio;
    gotoxy(32, 17); cout << compra.bonificacion;
    gotoxy(32, 18); cout << compra.totalCompra;

    // Obtener la forma de pago  
    seleccionarFormaPago(compra.formaPago);
    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\notificacion4.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse

    system("cls");
    setColor((color + 11) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(5, 1);cout << "******************************************************************************************";
    gotoxy(5, 2);cout << "*                            RECIBO DE COMPRA DE CAFE                                    *";
    gotoxy(5, 3);cout << "******************************************************************************************";
    gotoxy(5, 4); cout << "*  Informacion del Vendedor :                                                            *";
    gotoxy(5, 5);cout << "*  Nombre / ID del encargado de la compra :______________________________________        *";
    gotoxy(5, 6);cout << "*  ID del negociante : ______________________________________                            *";
    gotoxy(5, 7);cout << "******************************************************************************************";
    gotoxy(5, 8);cout << "*  Detalles de la Compra :                                                               *";
    gotoxy(5, 9);cout << "*  Tipo de cafe : ______________________________________                                 *";
    gotoxy(5, 10);cout << "*  Region de origen : ______________________________________                             *";
    gotoxy(5, 11);cout << "*  Fecha de la compra :_____________________________________                             * ";
    gotoxy(5, 12);cout << "*  Precio por kg : ______________________________________                                *";
    gotoxy(5, 13);cout << "*  Cantidad comprada(kg) : ______________________________________                        *";
    gotoxy(5, 14);cout << "******************************************************************************************";
    gotoxy(5, 15);cout << "*  Bonificacion :                                                                        *";
    gotoxy(5, 16);cout << "*  Es socio : [s]Si [n]No                                                                *";
    gotoxy(5, 17);cout << "*  Bonificacion(10 %) : __________________________________________________               *";
    gotoxy(5, 18);cout << "*  Total de la compra : ______________________________________                           *";
    gotoxy(5, 19);cout << "******************************************************************************************";
    gotoxy(5, 20);cout << "*  Forma de Pago :                                                                       *";
    gotoxy(5, 21);cout << "*  __________________________________________________                                    *";
    gotoxy(5, 22);cout << "******************************************************************************************";
    gotoxy(5, 23);cout << "*  Estandares de Calidad :                                                               *";
    gotoxy(5, 24);cout << "*  Calidad del cafe: ______________________________________                              *";

    setColor((color + 12) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(49, 5); cout << compra.vendedor;
    gotoxy(29, 6); cout << compra.idNegociante;
    gotoxy(24, 9); cout << compra.tipoCafe;
    gotoxy(28, 10); cout << compra.region;
    gotoxy(29, 11);cout << fechaCompra;
    gotoxy(25, 12); cout << compra.precioPorKg;
    gotoxy(33, 13);cout << compra.cantidadKg;
    gotoxy(32, 17); cout << compra.bonificacion;
    gotoxy(32, 18); cout << compra.totalCompra;
    gotoxy(10, 21); cout << compra.formaPago;

    seleccionarCalidadCafe(compra.calidadCafe);
    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\notificacion4.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse

    system("cls");
    setColor((color + 11) % 16); // Cambia el color del texto, limita a un rango de 0-16
    gotoxy(5, 1);cout << "******************************************************************************************";
    gotoxy(5, 2);cout << "*                            RECIBO DE COMPRA DE CAFE                                    *";
    gotoxy(5, 3);cout << "******************************************************************************************";
    gotoxy(5, 4); cout << "*  Informacion del Vendedor :                                                            *";
    gotoxy(5, 5);cout << "*  Nombre / ID del encargado de la compra :______________________________________        *";
    gotoxy(5, 6);cout << "*  ID del negociante : ______________________________________                            *";
    gotoxy(5, 7);cout << "******************************************************************************************";
    gotoxy(5, 8);cout << "*  Detalles de la Compra :                                                               *";
    gotoxy(5, 9);cout << "*  Tipo de cafe : ______________________________________                                 *";
    gotoxy(5, 10);cout << "*  Region de origen : ______________________________________                             *";
    gotoxy(5, 11);cout << "*  Fecha de la compra :_____________________________________                             * ";
    gotoxy(5, 12);cout << "*  Precio por kg : ______________________________________                                *";
    gotoxy(5, 13);cout << "*  Cantidad comprada(kg) : ______________________________________                        *";
    gotoxy(5, 14);cout << "******************************************************************************************";
    gotoxy(5, 15);cout << "*  Bonificacion :                                                                        *";
    gotoxy(5, 16);cout << "*  Es socio : [s]Si [n]No                                                                *";
    gotoxy(5, 17);cout << "*  Bonificacion(10 %) : __________________________________________________               *";
    gotoxy(5, 18);cout << "*  Total de la compra : ______________________________________                           *";
    gotoxy(5, 19);cout << "******************************************************************************************";
    gotoxy(5, 20);cout << "*  Forma de Pago :                                                                       *";
    gotoxy(5, 21);cout << "*  __________________________________________________                                    *";
    gotoxy(5, 22);cout << "******************************************************************************************";
    gotoxy(5, 23);cout << "*  Estandares de Calidad :                                                               *";
    gotoxy(5, 24);cout << "*  Calidad del cafe: ______________________________________                              *";
    gotoxy(5, 25);cout << "******************************************************************************************";
    gotoxy(5, 26);cout << "*  Notas o Comentarios Adicionales :                                                     *";
    gotoxy(5, 27);cout << "*  ___________________________________________________________________                   *";
    gotoxy(5, 28);cout << "* ___________________________________________________________________                    *";
    gotoxy(5, 29);cout << "******************************************************************************************";


    setColor((color + 12) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(49, 5); cout << compra.vendedor;
    gotoxy(29, 6); cout << compra.idNegociante;
    gotoxy(24, 9); cout << compra.tipoCafe;
    gotoxy(28, 10); cout << compra.region;
    gotoxy(29, 11);cout << fechaCompra;
    compra.fechaCompra = fechaCompra;
    gotoxy(25, 12); cout << compra.precioPorKg;
    gotoxy(33, 13);cout << compra.cantidadKg;
    gotoxy(30, 17); cout << compra.bonificacion;
    gotoxy(30, 18); cout << compra.totalCompra;
    gotoxy(10, 21); cout << compra.formaPago;
    gotoxy(27, 24); cout << compra.calidadCafe;
    gotoxy(9, 27); getline(cin, compra.comentarios);
    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\notificacion4.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse

    setColor((color + 3) % 16); // Cambia el color del texto, limita a un rango de 0-9


    encolarCompra(q, compra);

    _getch();
}

// Función para obtener la fecha actual en formato DD/MM/AAAA  
string obtenerFechaActual() {
    time_t t = time(0);  // Obtener la hora actual  
    tm now;               // Estructura para almacenar la fecha y hora  
    localtime_s(&now, &t);  // Convertir a tiempo local de manera segura  

    // Formatear la fecha como DD/MM/AAAA  
    string fechaActual = to_string(now.tm_mday) + "/" +
        to_string(now.tm_mon + 1) + "/" +
        to_string(now.tm_year + 1900);
    return fechaActual;
}

// Función para mostrar el menú de selección de tipo de café  
void seleccionarTipoCafe(string& tipoCafe) {
    const string opciones[] = {
        "Cafe en grano",
        "Cafe pergamino",
        "Cafe oro",
        "Cafe tostado",
        "Cafe molido"
    };
    int seleccion = 0;  // Índice de la opción seleccionada  
    int totalOpciones = sizeof(opciones) / sizeof(opciones[0]);// baytes  / baytes

    while (true) {

        // Mostrar las opciones  
        for (int i = 0; i < totalOpciones; ++i) {
            gotoxy(5, 11 + i); // Mover el cursor a la línea correspondiente  
            if (i == seleccion) { 
                setColor((color + 7) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << "> " << opciones[i] << " <";  // Resaltar la opción seleccionada  
            }
            else {
                setColor((color + 3) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << "  " << opciones[i] << "  ";
            }
        }

        // Capturar la tecla presionada  
        int tecla = _getch();
        if (tecla == 72) { // Tecla de flecha arriba  
            seleccion = (seleccion - 1 + totalOpciones) % totalOpciones; // Mover hacia arriba  
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo3.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
        }
        else if (tecla == 80) { // Tecla de flecha abajo  
            seleccion = (seleccion + 1) % totalOpciones; // Mover hacia abajo  
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo3.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
        }
        else if (tecla == 13) { // Enter  
            tipoCafe = opciones[seleccion]; // Asignar la opción seleccionada  
            break; // Salir del bucle  
        }
    }
}

// Función para mostrar el menú de selección de formato de pago  
void seleccionarFormaPago(string& formaPago) {
    const string opciones[] = {
        "Efectivo",
        "Transferencia bancaria",
        "Pago movil o billetera electronica",
        "Credito o financiamiento",
        "Intercambio o trueque"
    };
    int seleccion = 0;  // Índice de la opción seleccionada  
    int totalOpciones = sizeof(opciones) / sizeof(opciones[0]);

    while (true) {


        // Mostrar las opciones  
        for (int i = 0; i < totalOpciones; ++i) {
            gotoxy(5, 23 + i); // Mover el cursor a la línea correspondiente  
            if (i == seleccion) {
                setColor((color + 7) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << "> " << opciones[i] << " <";  // Resaltar la opción seleccionada  
            }
            else {
                setColor((color + 3) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << "  " << opciones[i] << "  ";
            }
        }

        // Capturar la tecla presionada  
        int tecla = _getch();
        if (tecla == 72) { // Tecla de flecha arriba  
            seleccion = (seleccion - 1 + totalOpciones) % totalOpciones; // Mover hacia arriba  
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo3.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
        }
        else if (tecla == 80) { // Tecla de flecha abajo  
            seleccion = (seleccion + 1) % totalOpciones; // Mover hacia abajo  
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo3.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
        }
        else if (tecla == 13) { // Enter  
            formaPago = opciones[seleccion]; // Asignar la opción seleccionada  
            break; // Salir del bucle  
        }
    }
}

// Función para mostrar el menú de selección de calidad del café  
void seleccionarCalidadCafe(string& calidadCafe) {
    const string opciones[] = {
        "Primera",
        "Segunda",
        "Tercera"
    };
    int seleccion = 0;
    int totalOpciones = sizeof(opciones) / sizeof(opciones[0]);

    while (true) {


        for (int i = 0; i < totalOpciones; ++i) {
            gotoxy(5, 26 + i);
            if (i == seleccion) {
                setColor((color + 7) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << "> " << opciones[i] << " <";
            }
            else {
                setColor((color + 3) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << "  " << opciones[i] << "  ";
            }
        }

        int tecla = _getch();
        if (tecla == 72) {
            seleccion = (seleccion - 1 + totalOpciones) % totalOpciones;
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo3.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
        }
        else if (tecla == 80) {
            seleccion = (seleccion + 1) % totalOpciones;
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo3.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
        }
        else if (tecla == 13) {
            calidadCafe = opciones[seleccion];
            break;
        }
    }
}

//funcion para encolar
void encolarCompra(colaCompra& q, const CompraCafe& compra) {
    nodoCompra* aux = new nodoCompra;
    aux->compra = compra; // Almacena la compra en el nodo  
    aux->siguiente = nullptr;

    if (q.delante == nullptr) {
        q.delante = aux; // Si la cola está vacía, el nuevo nodo es el primero  
    }
    else {
        q.atras->siguiente = aux; // Conecta el nuevo nodo al final  
    }
    q.atras = aux; // Actualiza el puntero al último nodo  

}


//opcion 2
//funcion mostrar 
void mostrarCola(const colaCompra& q) {
    nodoCompra* actual = q.delante;  // Comenzar desde el nodo del frente de la cola  

    if (actual == nullptr) {
        system("CLS");

        gotoxy(49, 13);cout << "La cola esta vacia." << endl;

        PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo8.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
        _getch();
        return;
    }

    system("CLS");  // Limpia la pantalla antes de mostrar las compras  
    int contador = 1; // Contador para separar las compras  

    while (actual != nullptr) {
        const CompraCafe& compra = actual->compra; // Acceder a la compra del nodo actual  

        // Mostrar el recibo de compra  
        cout << "**********************************************************" << endl;
        cout << "*             RECIBO DE COMPRA DE CAFE                   *" << endl;
        cout << "**********************************************************" << endl;
        cout << "*  Nombre: " << compra.vendedor << "                   " << endl;
        cout << "*  ID del negociante : " << compra.idNegociante << "   " << endl;
        cout << "*  Tipo de cafe : " << compra.tipoCafe << "            " << endl;
        cout << "*  Fecha de la compra : " << compra.fechaCompra << "   " << endl;
        cout << "*  Precio por kg : " << compra.precioPorKg << "        " << endl;
        cout << "*  Cantidad comprada(kg) : " << compra.cantidadKg << " " << endl;
        cout << "*  Total de la compra : " << compra.totalCompra << "   " << endl;
        cout << "**********************************************************" << endl;

        actual = actual->siguiente; // Avanzar al siguiente nodo  

        // Agregar un salto de línea entre recibos  
        cout << endl;
        contador++;
    }
}


//opcion 3
// modificar 
void modificarRecibo(colaCompra& q) {
    int idNegociante;
    system("cls");
    setColor((10) % 16); // Cambia el color del texto, limita a un rango de 0-9
    gotoxy(40, 13);cout << "Ingrese el ID del negociante a buscar: ";
    setColor((11) % 16); // Cambia el color del texto, limita a un rango de 0-9
    cin >> idNegociante;
    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\notificacion4.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
    cin.ignore(); //  Limpiar el buffer de entrada  

    nodoCompra* nodo = buscarPorIdNegociante(q, idNegociante);
    if (nodo) {
        system("cls");
        gotoxy(50, 13);cout << "Recibo encontrado." << endl;
        mostrarMenu(nodo->compra); // Mostrar el menú para modificar el recibo  
        PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\notificacion6.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
    }
    else {
        system("cls");
        gotoxy(41, 13);cout << "No se encontró un recibo con ese ID." << endl;
        PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo8.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
    }
    _getch();
}
nodoCompra* buscarPorIdNegociante(colaCompra& q, int idNegociante) {
    nodoCompra* actual = q.delante;
    while (actual != nullptr) {
        if (actual->compra.idNegociante == idNegociante) {
            return actual; // Retorna el nodo encontrado  
        }
        actual = actual->siguiente; // Continuar buscando  
    }
    return nullptr; // No se encontró el recibo  
}
void mostrarMenu(CompraCafe& compra) {
    int opcion = 0; // Opción seleccionada  
    setColor((12) % 16); // Cambia el color del texto, limita a un rango de 0-9
    const string opciones[] = {
        "Modificar Nombre",
        "Modificar Tipo de Cafe",
        "Modificar Region de Origen",
        "Modificar Fecha de Compra",
        "Modificar Precio por Kg",
        "Modificar Cantidad Comprada (kg)",
        "Modificar Es Socio",
        "Modificar Forma de Pago",
        "Modificar Calidad del Cafe",
        "Modificar comentario",
        "Salir"
    };

    while (true) {
        system("CLS");
        setColor((1) % 16); // Cambia el color del texto, limita a un rango de 0-9
        cout << "Seleccione una opcion para modificar:" << endl;

        for (int i = 0; i < sizeof(opciones) / sizeof(opciones[0]); ++i) {
            if (i == opcion) {
                setColor((11) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << "> " << opciones[i] << " <" << endl; // Resaltar opción seleccionada  
            }
            else {
                setColor((12) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << opciones[i] << endl;
            }
        }

        // Capturar la tecla presionada  
        char tecla = _getch(); // Usa <conio.h> para capturar las teclas  
        if (tecla == 72) { // Tecla de flecha arriba  
            opcion = (opcion > 0) ? opcion - 1 : 0;
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo7.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
        }
        else if (tecla == 80) { // Tecla de flecha abajo  
            opcion = (opcion < sizeof(opciones) / sizeof(opciones[0]) - 1) ? opcion + 1 : opcion;
            PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo7.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
        }
        else if (tecla == 13) { // Tecla Enter  
            switch (opcion) {
            case 0: // Modificar Nombre  
                setColor((9) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << "Nuevo Nombre: ";
                setColor((4) % 16); // Cambia el color del texto, limita a un rango de 0-9
                getline(cin, compra.vendedor);
                break;
            case 1: // Modificar Tipo de Cafe  
                setColor((9) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << "Nuevo Tipo de Cafe: " << endl;
                // Obtener el tipo de café  
                setColor((5) % 16); // Cambia el color del texto, limita a un rango de 0-9
                seleccionarTipoCafe(compra.tipoCafe);
                break;
            case 2: // Modificar Region de Origen  
                setColor((9) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << "Nueva Region: ";
                setColor((5) % 16); // Cambia el color del texto, limita a un rango de 0-9
                getline(cin, compra.region);
                break;
            case 3: // Modificar Fecha de Compra  
                setColor((9) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << "Nueva Fecha de Compra: ";
                setColor((5) % 16); // Cambia el color del texto, limita a un rango de 0-9
                getline(cin, compra.fechaCompra);
                break;
            case 4: // Modificar Precio por Kg  
                setColor((9) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << "Nuevo Precio por Kg: ";
                setColor((5) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cin >> compra.precioPorKg;
                cin.ignore(); // Limpiar el buffer de entrada 
                // Calcular el nuevo total de compra  
                compra.bonificacion = compra.esSocio ? (compra.precioPorKg * compra.cantidadKg * 0.10) : 0.0;
                compra.totalCompra = (compra.precioPorKg * compra.cantidadKg) + compra.bonificacion;
                break;
            case 5: // Modificar Cantidad Comprada (kg)  
                setColor((9) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << "Nueva Cantidad Comprada (kg): ";
                setColor((5) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cin >> compra.cantidadKg;
                cin.ignore(); // Limpiar el buffer de entrada  
                // Calcular el nuevo total de compra  
                compra.bonificacion = compra.esSocio ? (compra.precioPorKg * compra.cantidadKg * 0.10) : 0.0;
                compra.totalCompra = (compra.precioPorKg * compra.cantidadKg) + compra.bonificacion;
                break;
            case 6: // Modificar Es Socio 
                setColor((9) % 16); // Cambia el color del texto, limita a un rango de 0-9
                char esSocio;
                cout << "Es socio? (s/n): ";
                setColor((5) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cin >> esSocio;
                compra.esSocio = (esSocio == 's' || esSocio == 'S');
                cin.ignore(); // Limpiar el buffer de entrada  
                // Calcular bonificación si es socio
                compra.bonificacion = compra.esSocio ? (compra.precioPorKg * compra.cantidadKg * 0.10) : 0.0;

                // Calcular total de la compra
                compra.totalCompra = (compra.precioPorKg * compra.cantidadKg) + compra.bonificacion;
                cin.ignore();
                break;
            case 7: // Modificar Forma de Pago  
                setColor((9) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << "Nueva Forma de Pago: " << endl;
                setColor((5) % 16); // Cambia el color del texto, limita a un rango de 0-9
                // Obtener la forma de pago  
                seleccionarFormaPago(compra.formaPago);
                break;
            case 8: // Modificar Calidad del Cafe  
                setColor((9) % 16); // Cambia el color del texto, limita a un rango de 0-9
                cout << "Nueva Calidad del Cafe: " << endl;
                setColor((5) % 16); // Cambia el color del texto, limita a un rango de 0-9
                seleccionarCalidadCafe(compra.calidadCafe);
                break;
            case 9: // Modificar comentario 
                cout << "Nuevo comentario: ";
                setColor((5) % 16); // Cambia el color del texto, limita a un rango de 0-9
                getline(cin, compra.comentarios);
                cin.ignore();
                break;
            case 10: //salir
                return;
            }
        }
    }
}


//opcion 4
//buscar 
void buscarYMostrarRecibo(const colaCompra& q) {
    int idNegociante;
    system("cls");
    gotoxy(40, 13); cout << "Ingrese el ID del negociante a buscar: ";
    cin >> idNegociante;
    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\notificacion4.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
    //cin.ignore(); // Limpiar el buffer de entrada  

    nodoCompra* nodo = buscarPorIdNegociante(const_cast<colaCompra&>(q), idNegociante);
    if (nodo) {
        const CompraCafe& compra = nodo->compra; // Obtener la compra del nodo encontrado  
        system("CLS"); // Limpiar la pantalla antes de mostrar el recibo  


        setColor((color + 11) % 16); // Cambia el color del texto, limita a un rango de 0-9
        gotoxy(5, 1);cout << "******************************************************************************************";
        gotoxy(5, 2);cout << "*                            RECIBO DE COMPRA DE CAFE                                    *";
        gotoxy(5, 3);cout << "******************************************************************************************";
        gotoxy(5, 4); cout << "*  Informacion del Vendedor :                                                            *";
        gotoxy(5, 5);cout << "*  Nombre / ID del encargado de la compra :______________________________________        *";
        gotoxy(5, 6);cout << "*  ID del negociante : ______________________________________                            *";
        gotoxy(5, 7);cout << "******************************************************************************************";
        gotoxy(5, 8);cout << "*  Detalles de la Compra :                                                               *";
        gotoxy(5, 9);cout << "*  Tipo de cafe : ______________________________________                                 *";
        gotoxy(5, 10);cout << "*  Region de origen : ______________________________________                             *";
        gotoxy(5, 11);cout << "*  Fecha de la compra :_____________________________________                             * ";
        gotoxy(5, 12);cout << "*  Precio por kg : ______________________________________                                *";
        gotoxy(5, 13);cout << "*  Cantidad comprada(kg) : ______________________________________                        *";
        gotoxy(5, 14);cout << "******************************************************************************************";
        gotoxy(5, 15);cout << "*  Bonificacion :                                                                        *";
        gotoxy(5, 16);cout << "*  Es socio : [s]Si [n]No                                                                *";
        gotoxy(5, 17);cout << "*  Bonificacion(10 %) : __________________________________________________               *";
        gotoxy(5, 18);cout << "*  Total de la compra : ______________________________________                           *";
        gotoxy(5, 19);cout << "******************************************************************************************";
        gotoxy(5, 20);cout << "*  Forma de Pago :                                                                       *";
        gotoxy(5, 21);cout << "*  __________________________________________________                                    *";
        gotoxy(5, 22);cout << "******************************************************************************************";
        gotoxy(5, 23);cout << "*  Estandares de Calidad :                                                               *";
        gotoxy(5, 24);cout << "*  Calidad del cafe: ______________________________________                              *";
        gotoxy(5, 25);cout << "******************************************************************************************";
        gotoxy(5, 26);cout << "*  Notas o Comentarios Adicionales :                                                     *";
        gotoxy(5, 27);cout << "*  ___________________________________________________________________                   *";
        gotoxy(5, 28);cout << "* ___________________________________________________________________                    *";
        gotoxy(5, 29);cout << "******************************************************************************************";


        setColor((color + 12) % 16); // Cambia el color del texto, limita a un rango de 0-9
        gotoxy(49, 5); cout << compra.vendedor;
        gotoxy(29, 6); cout << compra.idNegociante;
        gotoxy(24, 9); cout << compra.tipoCafe;
        gotoxy(28, 10); cout << compra.region;
        gotoxy(29, 11); compra.fechaCompra;
        gotoxy(25, 12); cout << compra.precioPorKg;
        gotoxy(33, 13);cout << compra.cantidadKg;
        gotoxy(30, 17); cout << compra.bonificacion;
        gotoxy(30, 18); cout << compra.totalCompra;
        gotoxy(10, 21); cout << compra.formaPago;
        gotoxy(27, 24); cout << compra.calidadCafe;
        gotoxy(9, 27); cout << compra.comentarios;
    }
    else {
        system("cls");
        gotoxy(41, 13);cout << "No se encontro un recibo con ese ID." << endl;
        PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo8.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
    }
    _getch();
}


//opcion 5
//eliminar 
void eliminarPrimerRecibo(colaCompra& q) {
    if (q.delante == nullptr) { // Verifica si la cola está vacía  
        system("cls");
        gotoxy(34, 13);cout << "La cola esta vacia. No hay recibos para eliminar." << endl;
        PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo8.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
        _getch();
        return;
    }

    nodoCompra* nodoAEliminar = q.delante; // Nodo a eliminar  
    q.delante = q.delante->siguiente; // Mueve el puntero delante al siguiente nodo  

    // Si la cola queda vacía después de eliminar el nodo  
    if (q.delante == nullptr) {
        q.atras = nullptr; // También actualiza el puntero atrás  
    }

    // Liberar la memoria del nodo eliminado  
    delete nodoAEliminar;
    system("cls");
    gotoxy(42, 13);cout << "Recibo eliminado correctamente." << endl;
    PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\nuevo8.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
    _getch();
}
