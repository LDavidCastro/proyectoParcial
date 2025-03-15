#include"logo.h"


#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

struct Ventas
{
	int ID_Ventas;
	int ID_Cliente;

	string Tipo_de_Cafe_ventido;
	string Fecha_de_venta;
	int Precio_Unitario;
	int Cantidad_vendida;

	string Descuento;
	string Total;
	string Metodo_de_pago;
} VENTAS;

struct Nodop
{
	Ventas datos;
	Nodop* siguiente;
};

Nodop* pila = NULL;

void Menu_Pila();
void DibujarRecuadro();
void dibujarCuadro(int x1, int y1, int x2, int y2);
void Insertar_Nodop(Nodop*&, int, int, int, int, string, string, string, string, string);
void Mostrar_Pila(Nodop*&, int, int, int, int, string, string, string, string, string);
void Modificar_Nodop(Nodop*&, int, int, int, int, string, string, string, string, string);
int Opciones_Menu(const char* titulo, const char* opciones[], int n);
void Eliminar_Nodop(Nodop*&, int, int, int, int, string, string, string, string, string);
void Buscar_Nodop(Nodop*&, int, int, int, int, string, string, string, string, string);
void dibujarFigura(int opcion);
void clearCin()
{
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}


void Insertar_Nodop(Nodop*& pila, int a, int b, int c, int d, string h, string i, string j, string l, string m) {
	string Fecha_de_venta = i = obtenerFechaActual();
	char continuar;

	do {

		Nodop* nuevo_nodo = new Nodop();
		system("cls");  // Limpiar pantalla
		clearCin();  // Limpiar buffer de entrada
		DibujarRecuadro();  // Dibuja el recuadro

		gotoxy(40, 7); cout << a;  // ID_Ventas
		gotoxy(40, 8); cin >> b;  // ID_Cliente
		cin.ignore();  // Limpiar buffer de entrada después de cin

		gotoxy(48, 13); getline(cin, h);  // Tipo_de_Cafe_ventido
		gotoxy(48, 14); cout << i;  // Fecha_de_venta
		gotoxy(48, 15); cin >> c;  // Precio_Unitario
		gotoxy(48, 16); cin >> d;  // Cantidad_vendida
		cin.ignore();  // Limpiar buffer

		gotoxy(48, 21); getline(cin, j);  // Descuento

		// Calcular el total considerando el descuento
		float precio_total = c * d;
		float descuento = stof(j) / 100.0 * precio_total;  // Convertir descuento a decimal y calcular
		float total_final = precio_total - descuento;

		l = to_string(total_final);  // Convertir total a string

		gotoxy(48, 22); cout << l;  // Mostrar Total calculado
		gotoxy(48, 23); getline(cin, m);  // Metodo_de_pago

		// Asignar los datos al nodo
		nuevo_nodo->datos.ID_Ventas = a;
		nuevo_nodo->datos.ID_Cliente = b;
		nuevo_nodo->datos.Tipo_de_Cafe_ventido = h;
		nuevo_nodo->datos.Fecha_de_venta = i;
		nuevo_nodo->datos.Precio_Unitario = c;
		nuevo_nodo->datos.Cantidad_vendida = d;
		nuevo_nodo->datos.Descuento = j;
		nuevo_nodo->datos.Total = l;
		nuevo_nodo->datos.Metodo_de_pago = m;

		// Insertar nodo en la pila
		nuevo_nodo->siguiente = pila;
		pila = nuevo_nodo;

		// Mostrar mensaje y actualizar archivo
		gotoxy(2, 27);
		cout << " *- NODO INGRESADO  -*" << endl << endl;

		// Mostrar la pila
		Mostrar_Pila(pila, VENTAS.Cantidad_vendida, VENTAS.Precio_Unitario, VENTAS.ID_Ventas, VENTAS.ID_Cliente, VENTAS.Tipo_de_Cafe_ventido, VENTAS.Fecha_de_venta, VENTAS.Descuento, VENTAS.Total, VENTAS.Metodo_de_pago);

		a++;
		// Preguntar si desea ingresar otro nodo
		gotoxy(5, 29);
		cout << endl << " DESEA INGRESAR OTRO NODO DE DATOS? (s/n): ";
		cin >> continuar;
		cin.ignore();  // Limpiar el buffer antes de la siguiente iteración
	} while (continuar == 's' || continuar == 'S');
}

void Mostrar_Pila(Nodop*& pila, int a, int b, int c, int d, string h, string i, string j, string l, string m) {

	Nodop* aux = new Nodop();
	aux = pila;
	if (pila != NULL)
	{
		while (aux != NULL) {

			cout << "----------------------------------";
			cout << endl << &aux->datos << "\n";
			cout << endl << " ID venta: " << aux->datos.ID_Ventas << "\n";
			cout << endl << " ID cliente: " << aux->datos.ID_Cliente << "\n";
			cout << endl << " Tipo de Cafe: " << aux->datos.Tipo_de_Cafe_ventido << "\n";
			cout << endl << " Fecha de venta: " << aux->datos.Fecha_de_venta << "\n";
			cout << endl << " Precio Unitario: " << aux->datos.Precio_Unitario << "\n";
			cout << endl << " Cantidad Vendida: " << aux->datos.Cantidad_vendida << "\n";
			cout << endl << " Descuento: " << aux->datos.Descuento << "\n";
			cout << endl << " Metodo de pago: " << aux->datos.Metodo_de_pago << "\n";
			cout << endl << " Total: " << aux->datos.Total << "\n";
			cout << "----------------------------------\n";

			aux = aux->siguiente; //Avanzar al siguiente nodo
		}
	}
	else
	{
		gotoxy(27, 14); cout << " *- LA PILA SE ENCUENTRA VACIA -* ";
	}

	_getch();

}

void Modificar_Nodop(Nodop*& pila, int a, int b, int c, int d, string h, string i, string j, string l, string m)
{
	Nodop* aux = new Nodop;
	aux = pila;

	bool encontrado = false;
	int id_v, id_c;

	if (pila != NULL)
	{
		clearCin();
		gotoxy(40, 5); cout << "INGRESE LOS DATOS QUE SE SOLICITAN\n";
		gotoxy(54, 10); cout << " ID Ventas: ";
		gotoxy(54, 11); cin >> id_v;
		gotoxy(54, 13); cout << " ID CLIENTE: ";
		gotoxy(54, 14); cin >> id_c;

		while (pila != NULL && encontrado != true)
		{
			if (aux != NULL)
			{
				if (aux->datos.ID_Ventas == id_v && aux->datos.ID_Cliente == id_c)
				{
					cout << " *- EL USUARIO FUE ENCONTRADO *- ";
					cout << "----------------------------------";
					cout << endl << &aux->datos << "\n";
					cout << endl << " ID venta: " << aux->datos.ID_Ventas << "\n";
					cout << endl << " ID cliente: " << aux->datos.ID_Cliente << "\n";
					cout << endl << " Tipo de Cafe: " << aux->datos.Tipo_de_Cafe_ventido << "\n";
					cout << endl << " Fecha de venta: " << aux->datos.Fecha_de_venta << "\n";
					cout << endl << " Precio Unitario: " << aux->datos.Precio_Unitario << "\n";
					cout << endl << " Cantidad Vendida: " << aux->datos.Cantidad_vendida << "\n";
					cout << endl << " Descuento: " << aux->datos.Descuento << "\n";
					cout << endl << " Metodo de pago: " << aux->datos.Metodo_de_pago << "\n";
					cout << endl << " Total: " << aux->datos.Total << "\n";
					cout << "----------------------------------\n";

					system("pause");
					encontrado = true;

					bool rep = true;
					int op = 0;
					const char* titulo = "-*-*-*- OPCIONES DE MODIFICACION DEL NODO -*-*-*-";
					const char* opciones[] = { "*- ID VENTAS -*","*- ID CLIENTE -*","*- Tipo de Cafe -*","*- Fecha de venta -*", "*- Precio Unitario -*", "*- Cantidad Vendida -*", "*- Descuento -*", "*- Metodo de pago -*","*- Total -*","*- regreasr -*","*- salir -*" };
					int no = 10;
					cout << "Seleccione el parametro que desee modificar del nodo";

					do
					{
						op = Opciones_Menu(titulo, opciones, no);
						switch (op) {
							system("cls");
						case 1:
							system("cls");
							cout << endl << "\t Ingrese El Nuevo Dato Para Este Nodo: ";
							cin >> aux->datos.ID_Ventas;
							cout << endl << " *- NODO MODIFICADO -* " << endl << endl;
							break;
						case 2:
							system("cls");
							cout << endl << "\t Ingrese El Nuevo Dato Para Este Nodo: ";
							cin >> aux->datos.ID_Cliente;
							cout << endl << " *- NODO MODIFICADO -* " << endl << endl;
							break;
						case 3:
							system("cls");
							cout << endl << "\t Ingrese El Nuevo Dato Para Este Nodo: ";
							cin >> aux->datos.Tipo_de_Cafe_ventido;
							cout << endl << " *- NODO MODIFICADO -* " << endl << endl;
							break;
						case 4:
							system("cls");
							cout << endl << "\t Ingrese El Nuevo Dato Para Este Nodo: ";
							getline(cin, aux->datos.Fecha_de_venta);
							cout << endl << " *- NODO MODIFICADO -* " << endl << endl;
							break;

						case 5:
							system("cls");
							cout << endl << "\t Ingrese El Nuevo Dato Para Este Nodo: ";
							cin >> aux->datos.Precio_Unitario;
							cout << endl << " *- NODO MODIFICADO -* " << endl << endl;
							break;
						case 6:
							system("cls");
							cout << endl << "\t Ingrese El Nuevo Dato Para Este Nodo: ";
							cin >> aux->datos.Cantidad_vendida;
							cout << endl << " *- NODO MODIFICADO -* " << endl << endl;
							break;
						case 7:
							system("cls");
							cout << endl << "\t Ingrese El Nuevo Dato Para Este Nodo: ";
							getline(cin, aux->datos.Descuento);
							cout << endl << " *- NODO MODIFICADO -* " << endl << endl;
							break;
						case 8:
							system("cls");
							cout << endl << "\t Ingrese El Nuevo Dato Para Este Nodo: ";
							getline(cin, aux->datos.Metodo_de_pago);
							cout << endl << " *- NODO MODIFICADO -* " << endl << endl;
							break;

						case 9:
							cout << endl << "\t Ingrese El Nuevo Dato Para Este Nodo: ";
							getline(cin, aux->datos.Total);
							cout << endl << " *- NODO MODIFICADO -* " << endl << endl;
							break;


						case 10:
							PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\OOT_MainMenu_Cancel.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
						
							system("cls");
							rep = false;
							break;
						}
						system("cls");

						cout << " *- FUERON MODIFICADOS *- ";
						cout << endl << "----------------------------------";
						cout << endl << &aux->datos << "\n";
						cout << endl << " ID venta: " << aux->datos.ID_Ventas << "\n";
						cout << endl << " ID cliente: " << aux->datos.ID_Cliente << "\n";
						cout << endl << " Tipo de Cafe: " << aux->datos.Tipo_de_Cafe_ventido << "\n";
						cout << endl << " Fecha de venta: " << aux->datos.Fecha_de_venta << "\n";
						cout << endl << " Precio Unitario: " << aux->datos.Precio_Unitario << "\n";
						cout << endl << " Cantidad Vendida: " << aux->datos.Cantidad_vendida << "\n";
						cout << endl << " Descuento: " << aux->datos.Descuento << "\n";
						cout << endl << " Metodo de pago: " << aux->datos.Metodo_de_pago << "\n";
						cout << endl << " Total: " << aux->datos.Total << "\n";
						cout << endl << "----------------------------------" << endl;

					} while (rep);

					return;
				}
				else
				{
					aux = aux->siguiente; //Avanzar al siguiente nodo
				}
			}
			else
			{
				gotoxy(40, 14); cout << " *- NO SE ENCONTRO EL NODO -* ";

				return;
			}
		}
	}
	else
	{
		gotoxy(40, 14); cout << " *- LA PILA SE ENCUENTRA VACIA -* ";

		return;
	}
}

int Opciones_Menu(const char* titulo, const char* opciones[], int n) {
	int opcionSeleccionada = 1;
	int tecla;
	bool repite = true;

	do {
		// Limpiar solo la parte del menú, no toda la pantalla
		system("cls");

		// Mostrar el título del menú
		gotoxy(40, 5); cout << titulo;

		// Mostrar las opciones del menú
		for (int i = 0; i < n; i++) {
			gotoxy(40, 11 + i);
			if (i + 1 == opcionSeleccionada) {
				cout << "\xFE " << opciones[i]; // Resaltar la opción seleccionada
			}
			else {
				cout << "   " << opciones[i]; // Opción normal
			}
		}

		// Mostrar instrucciones
		gotoxy(13, 24);
		cout << "USANDO LAS TECLAS DE DIRECCION ESCOJA UNA OPCION, PRESIONE ENTER PARA INGRESAR.";

		// Dibujar la figura correspondiente a la opción seleccionada
		dibujarFigura(opcionSeleccionada); // Llama a la función para dibujar

		// Captura de teclas
		tecla = _getch();
		if (tecla == 0 || tecla == 224) { // Si es una tecla especial
			tecla = _getch(); // Captura el código real de la tecla
		}

		// Procesar entrada del usuario
		switch (tecla) {
		case TECLA_ARRIBA:
			opcionSeleccionada--;
			if (opcionSeleccionada < 1) {
				opcionSeleccionada = n;
			}
			PlaySound(L"..\\OOT_PauseMenu_Cursor.wav", NULL, SND_FILENAME | SND_ASYNC);
			break;
		case TECLA_ABAJO:
			opcionSeleccionada++;
			if (opcionSeleccionada > n) {
				opcionSeleccionada = 1;
			}
			PlaySound(L"..\\OOT_PauseMenu_Cursor.wav", NULL, SND_FILENAME | SND_ASYNC);
			break;
		case ENTER:
			repite = false; // Salir del bucle para seleccionar la opción
			break;
		}

	} while (repite);

	return opcionSeleccionada;
}

// Función para dibujar una figura (puedes personalizarla)
void dibujarFigura(int opcion) {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Limpiar solo el área del dibujo (opcional)
	for (int i = 5; i <= 13; i++) {
		gotoxy(10, i); cout << "             "; // Limpiar 13 espacios
	}

	// Dibujar una figura según la opción seleccionada
	switch (opcion) {


	case 1:
		SetConsoleTextAttribute(hConsole, 1); // Verde claro
		gotoxy(10, 5); cout << "      . . .\n";
		gotoxy(10, 7); cout << "      } } }\n";
		gotoxy(10, 8); cout << "     { { {\n";
		gotoxy(10, 9); cout << "    +-----+\n";
		gotoxy(10, 10); cout << "    |     |]\n";
		gotoxy(10, 11); cout << "    `-----'\n";
		gotoxy(10, 12); cout << "  ___________\n";
		gotoxy(10, 13); cout << "  `---------'\n";
		break;
	case 2:
		SetConsoleTextAttribute(hConsole, 2); // Verde claro
		gotoxy(10, 5); cout << "     { { {\n";
		gotoxy(10, 7); cout << "      } } }\n";
		gotoxy(10, 8); cout << "     ' ' '\n";
		gotoxy(10, 9); cout << "    +-----+\n";
		gotoxy(10, 10); cout << "    |     |]\n";
		gotoxy(10, 11); cout << "    `-----'\n";
		gotoxy(10, 12); cout << "  ___________\n";
		gotoxy(10, 13); cout << "  `---------'\n";
		break;
	case 3:
		SetConsoleTextAttribute(hConsole, 3); // Verde claro
		gotoxy(10, 5); cout << "      . . .\n";
		gotoxy(10, 7); cout << "      } } }\n";
		gotoxy(10, 8); cout << "     { { {\n";
		gotoxy(10, 9); cout << "    +-----+\n";
		gotoxy(10, 10); cout << "    |     |]\n";
		gotoxy(10, 11); cout << "    `-----'\n";
		gotoxy(10, 12); cout << "  ___________\n";
		gotoxy(10, 13); cout << "  `---------'\n";
		break;
	case 4:
		SetConsoleTextAttribute(hConsole, 4); // Verde claro
		gotoxy(10, 5); cout << "     { { {\n";
		gotoxy(10, 7); cout << "      } } }\n";
		gotoxy(10, 8); cout << "     ' ' '\n";
		gotoxy(10, 9); cout << "    +-----+\n";
		gotoxy(10, 10); cout << "    |     |]\n";
		gotoxy(10, 11); cout << "    `-----'\n";
		gotoxy(10, 12); cout << "  ___________\n";
		gotoxy(10, 13); cout << "  `---------'\n";
		break;
	case 5:
		SetConsoleTextAttribute(hConsole, 5); // Verde claro
		gotoxy(10, 5); cout << "      . . .\n";
		gotoxy(10, 7); cout << "      } } }\n";
		gotoxy(10, 8); cout << "     { { {\n";
		gotoxy(10, 9); cout << "    +-----+\n";
		gotoxy(10, 10); cout << "    |     |]\n";
		gotoxy(10, 11); cout << "    `-----'\n";
		gotoxy(10, 12); cout << "  ___________\n";
		gotoxy(10, 13); cout << "  `---------'\n";

		break;
	case 6:
		SetConsoleTextAttribute(hConsole, 6); // Verde claro
		gotoxy(10, 5); cout << "     { { {\n";
		gotoxy(10, 7); cout << "      } } }\n";
		gotoxy(10, 8); cout << "     ' ' '\n";
		gotoxy(10, 9); cout << "    +-----+\n";
		gotoxy(10, 10); cout << "    |     |]\n";
		gotoxy(10, 11); cout << "    `-----'\n";
		gotoxy(10, 12); cout << "  ___________\n";
		gotoxy(10, 13); cout << "  `---------'\n";
		break;
	case 7:
		SetConsoleTextAttribute(hConsole, 7); // Verde claro
		gotoxy(10, 5); cout << "      . . .\n";
		gotoxy(10, 7); cout << "      } } }\n";
		gotoxy(10, 8); cout << "     { { {\n";
		gotoxy(10, 9); cout << "    +-----+\n";
		gotoxy(10, 10); cout << "    |     |]\n";
		gotoxy(10, 11); cout << "    `-----'\n";
		gotoxy(10, 12); cout << "  ___________\n";
		gotoxy(10, 13); cout << "  `---------'\n";
		break;
	case 8:
		SetConsoleTextAttribute(hConsole, 8); // Verde claro
		gotoxy(10, 5); cout << "     { { {\n";
		gotoxy(10, 7); cout << "      } } }\n";
		gotoxy(10, 8); cout << "     ' ' '\n";
		gotoxy(10, 9); cout << "    +-----+\n";
		gotoxy(10, 10); cout << "    |     |]\n";
		gotoxy(10, 11); cout << "    `-----'\n";
		gotoxy(10, 12); cout << "  ___________\n";
		gotoxy(10, 13); cout << "  `---------'\n";
		break;
		break;
	case 9:
		SetConsoleTextAttribute(hConsole, 9); // Verde claro
		gotoxy(10, 5); cout << "      . . .\n";
		gotoxy(10, 7); cout << "      } } }\n";
		gotoxy(10, 8); cout << "     { { {\n";
		gotoxy(10, 9); cout << "    +-----+\n";
		gotoxy(10, 10); cout << "    |     |]\n";
		gotoxy(10, 11); cout << "    `-----'\n";
		gotoxy(10, 12); cout << "  ___________\n";
		gotoxy(10, 13); cout << "  `---------'\n";
		break;
	case 10:
		SetConsoleTextAttribute(hConsole, 10); // Verde claro
		gotoxy(10, 5); cout << "     { { {\n";
		gotoxy(10, 7); cout << "      } } }\n";
		gotoxy(10, 8); cout << "     ' ' '\n";
		gotoxy(10, 9); cout << "    +-----+\n";
		gotoxy(10, 10); cout << "    |     |]\n";
		gotoxy(10, 11); cout << "    `-----'\n";
		gotoxy(10, 12); cout << "  ___________\n";
		gotoxy(10, 13); cout << "  `---------'\n";
		break;
	}
}

void Menu_Pila() {
	bool rep = true;
	int op = 0;
	const char* titulo = " MENU VENTAS ";
	const char* opciones[] = { "*-Ingreso de datos-*", "*-Ver datos-*", "*-Modificar Datos-*", "*-Buscar datos-*", "*-Eliminar datos-*", "*- SALIR -*" };
	int no = 6;

	do {
		system("cls"); // Limpia la pantalla antes de dibujar
		op = Opciones_Menu(titulo, opciones, no);

		// Dibujar la figura correspondiente a la opción seleccionada
		dibujarFigura(op);

		switch (op) {
		case 1:
			system("cls");
			PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\OOT_MainMenu_Select.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
		
			Insertar_Nodop(pila, VENTAS.Cantidad_vendida, VENTAS.Precio_Unitario, VENTAS.ID_Ventas, VENTAS.ID_Cliente, VENTAS.Tipo_de_Cafe_ventido, VENTAS.Fecha_de_venta, VENTAS.Descuento, VENTAS.Total, VENTAS.Metodo_de_pago);
			break;
		case 2:
			system("cls");
			PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\OOT_MainMenu_Select.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
			
			Mostrar_Pila(pila, VENTAS.Cantidad_vendida, VENTAS.Precio_Unitario, VENTAS.ID_Ventas, VENTAS.ID_Cliente, VENTAS.Tipo_de_Cafe_ventido, VENTAS.Fecha_de_venta, VENTAS.Descuento, VENTAS.Total, VENTAS.Metodo_de_pago);
			break;
		case 3:
			system("cls");
			PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\OOT_MainMenu_Select.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
			Modificar_Nodop(pila, VENTAS.Cantidad_vendida, VENTAS.Precio_Unitario, VENTAS.ID_Ventas, VENTAS.ID_Cliente, VENTAS.Tipo_de_Cafe_ventido, VENTAS.Fecha_de_venta, VENTAS.Descuento, VENTAS.Total, VENTAS.Metodo_de_pago);
			break;
		case 4:
			system("cls");
			PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\OOT_MainMenu_Select.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
			system("cls");
			Buscar_Nodop(pila, VENTAS.Cantidad_vendida, VENTAS.Precio_Unitario, VENTAS.ID_Ventas, VENTAS.ID_Cliente, VENTAS.Tipo_de_Cafe_ventido, VENTAS.Fecha_de_venta, VENTAS.Descuento, VENTAS.Total, VENTAS.Metodo_de_pago);
			break;
		case 5:
			system("cls");
			PlaySound(L"C:\\Users\\Castr\\source\\repos\\proyectoParcial\\x64\\Debug\\OOT_MainMenu_Select.wav", NULL, SND_FILENAME | SND_ASYNC); // Sonido al moverse
			system("cls");
			Eliminar_Nodop(pila, VENTAS.Cantidad_vendida, VENTAS.Precio_Unitario, VENTAS.ID_Ventas, VENTAS.ID_Cliente, VENTAS.Tipo_de_Cafe_ventido, VENTAS.Fecha_de_venta, VENTAS.Descuento, VENTAS.Total, VENTAS.Metodo_de_pago);
			break;
		case 6:
			rep = false;
			break;
		}


	} while (rep);
}

//Funcion para buscar un nodo
void Buscar_Nodop(Nodop*& pila, int a, int b, int c, int d, string h, string i, string j, string l, string m)
{
	Nodop* aux = new Nodop;
	aux = pila;

	bool encontrado = false;
	int id_v, id_c;

	if (pila != NULL)
	{
		cout << " *- SE ESTA BUSCANDO UN NODO *- " << endl;
		clearCin();

		gotoxy(40, 5); cout << "INGRESE LOS DATOS QUE SE SOLICITAN\n";
		gotoxy(54, 10); cout << " ID Ventas: ";
		gotoxy(54, 11); cin >> id_v;
		gotoxy(54, 13); cout << " ID CLIENTE: ";
		gotoxy(54, 14); cin >> id_c;

		while (pila != NULL && encontrado != true)
		{
			if (aux != NULL)
			{
				if (aux->datos.ID_Ventas == id_v && aux->datos.ID_Cliente == id_c)

				{
					cout << " *- EL Nodo FUE ENCONTRADO *- ";
					cout << endl << "----------------------------------";
					cout << endl << &aux->datos << "\n";
					cout << endl << " ID venta: " << aux->datos.ID_Ventas << "\n";
					cout << endl << " ID cliente: " << aux->datos.ID_Cliente << "\n";
					cout << endl << " Tipo de Cafe: " << aux->datos.Tipo_de_Cafe_ventido << "\n";
					cout << endl << " Fecha de venta: " << aux->datos.Fecha_de_venta << "\n";
					cout << endl << " Precio Unitario: " << aux->datos.Precio_Unitario << "\n";
					cout << endl << " Cantidad Vendida: " << aux->datos.Cantidad_vendida << "\n";
					cout << endl << " Descuento: " << aux->datos.Descuento << "\n";
					cout << endl << " Metodo de pago: " << aux->datos.Metodo_de_pago << "\n";
					cout << endl << " Total: " << aux->datos.Total << "\n";
					cout << "----------------------------------" << endl;

					encontrado = true;
				}
				else
				{
					aux = aux->siguiente; //Avanzar al siguiente nodo
				}
			}
			else
			{
				gotoxy(40, 14); cout << " *- NO SE ENCONTRO EL NODO -* ";
				return;
			}
		}
	}
	else
	{
		gotoxy(40, 14); cout << " *- LA PILA SE ENCUENTRA VACIA -* ";
		return;
	}

	_getch();
}

void Eliminar_Nodop(Nodop*& pila, int a, int b, int c, int d, string h, string i, string j, string l, string m)
{
	Nodop* aux = new Nodop;
	aux = pila;

	if (pila != NULL)
	{
		a = aux->datos.ID_Ventas;
		b = aux->datos.ID_Cliente;

		h = aux->datos.Tipo_de_Cafe_ventido;
		i = aux->datos.Fecha_de_venta;
		c = aux->datos.Precio_Unitario;
		d = aux->datos.Cantidad_vendida;

		j = aux->datos.Descuento;
		l = aux->datos.Total;
		m = aux->datos.Metodo_de_pago;

		cout << " *- SE eliminaran los datos de la venta -* ";
		cout << endl << "----------------------------------";
		cout << endl << &aux->datos << endl;
		cout << endl << " ID VENTAS : " << a << endl;
		cout << endl << " ID CLIENTE: " << b << endl;
		cout << endl << " TIPO DE CAFE: " << h << endl;
		cout << endl << " FECHA DE VENTAS: " << i << endl;
		cout << endl << " PRECIO UNITARIO: " << c << endl;
		cout << endl << " CANTIDAD VENDIDA: " << d << endl;
		cout << endl << " DESCUENTA: " << j << endl;
		cout << endl << " Total: " << l << endl;
		cout << endl << " Metodo de pago: " << m << endl;
		cout << "----------------------------------\n";

		pila = aux->siguiente; // Actualizar el puntero siguiente del nodo anterior
		delete aux;

		cout << " *- LA PILA QUEDO DE LA SIGUIENTE MANERA: -*" << endl;
		Mostrar_Pila(pila, VENTAS.Cantidad_vendida, VENTAS.Precio_Unitario, VENTAS.ID_Ventas, VENTAS.ID_Cliente, VENTAS.Tipo_de_Cafe_ventido, VENTAS.Fecha_de_venta, VENTAS.Descuento, VENTAS.Total, VENTAS.Metodo_de_pago);
	}
	else
	{
		gotoxy(40, 14); cout << " *- LA PILA SE ENCUENTRA VACIA -* ";

		return;
	}
}

void DibujarRecuadro() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls"); // Limpiar la pantalla
	SetConsoleTextAttribute(hConsole, 15);

	dibujarCuadro(10, 0, 100, 4); // Dibujar el cuadro
	dibujarCuadro(10, 4, 100, 25); // Dibujar el cuadro

	dibujarCuadro(10, 10, 100, 10); // Dibujar el cuadro
	dibujarCuadro(10, 18, 100, 18); // Dibujar el cuadro

	gotoxy(100, 4); cout << "\xDB";
	gotoxy(10, 4); cout << "\xDB";
	gotoxy(10, 10); cout << "\xDB";
	gotoxy(10, 18); cout << "\xDB";
	gotoxy(100, 18); cout << "\xDB";
	gotoxy(100, 10); cout << "\xDB";
	gotoxy(100, 25); cout << "\xDB";
	gotoxy(10, 25); cout << "\xDB";

	gotoxy(40, 2); cout << "RECIBO DE VENTA DE CAFE";

	gotoxy(40, 6); cout << "INFORMACION DE LA VENTA";
	gotoxy(20, 7); cout << "ID De la venta :";
	gotoxy(20, 8); cout << "ID del cliente :";

	gotoxy(40, 12); cout << "DETALLES DE LA VENTA";
	gotoxy(20, 13); cout << "Tipo de cafe :";
	gotoxy(20, 14); cout << "Fecha de la Venta :";
	gotoxy(20, 15); cout << "Precio por kg :";
	gotoxy(20, 16); cout << "Cantidad vendida (kg) : ";

	gotoxy(40, 20); cout << "TOTAL";
	gotoxy(20, 21); cout << "Descuento : ";
	gotoxy(20, 22); cout << "Total de la Venta : ";
	gotoxy(20, 23); cout << "Forma de Pago :    ";
}

void dibujarCuadro(int x1, int y1, int x2, int y2) {
	int i;

	for (i = x1; i < x2; i++) {
		gotoxy(i, y1); cout << (char)220;// Línea horizontal superior (\304 - 196 decimal: ─)
		gotoxy(i, y2); cout << (char)220; // Línea horizontal superior (\304 - 196 decimal: ─)
	}

	for (i = y1; i < y2; i++) {
		gotoxy(x1, i); cout << (char)219; // Línea vertical izquierda (\263 - 179 decimal: │)
		gotoxy(x2, i); cout << (char)219; // Línea vertical izquierda (\263 - 179 decimal: │)
	}

	gotoxy(x1, y1); cout << (char)220;// Esquina superior izquierda (\332 - 218 decimal: ┌)
	gotoxy(x1, y2); cout << (char)220;// Esquina inferior izquierda (\300 - 192 decimal: └)
	gotoxy(x2, y1); cout << (char)220;;// Esquina superior derecha (\277 - 191 decimal: ┐)
	gotoxy(x2, y2); cout << (char)220; // Esquina inferior derecha (\331 - 217 decimal: ┘)
}
