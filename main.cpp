#include <iostream>  //es una bibliote esntandar de entrada y salida
#include <fstream>  // incluye la biblioteca de flujo a traves de la consola
#include <string>    // biblioteca de cades la cual proporciona funcionalidad para manipular la cadenas de texto

using namespace std;

const string carpetaDatos = "C:/Users/rexyr/OneDrive/Documents/Salon/";

struct Cliente {
    string nombre;
    string telefono;
    string direccion; // Nueva variable para la dirección del cliente
    string fechaRegistro; // Nueva variable para la fecha de registro del cliente
};

// Función para registrar un nuevo cliente
void registrarCliente(const Cliente& cliente) {
    ofstream archivo(carpetaDatos + "clientes.txt", ios::app);
    if (archivo) {
        archivo << "Nombre: " << cliente.nombre << ", Telefono: " << cliente.telefono << ", Direccion: " << cliente.direccion << ", Fecha de Registro: " << cliente.fechaRegistro << endl;
        cout << "Cliente registrado correctamente." << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    // Crear un archivo con el nombre del cliente
    ofstream archivoCliente(carpetaDatos + cliente.nombre + ".txt");
    if (archivoCliente) {
        archivoCliente << "Nombre: " << cliente.nombre << ", Telefono: " << cliente.telefono << ", Direccion: " << cliente.direccion << ", Fecha de Registro: " << cliente.fechaRegistro << endl;
        cout << "Archivo del cliente creado correctamente." << endl;
    } else {
        cout << "Error al crear el archivo del cliente." << endl;
    }
}

// Función para registrar una nueva cita
void registrarCita(const string& nombreCliente, const string& fecha, const string& hora) {
    ofstream archivo(carpetaDatos + "citas.txt", ios::app);
    if (archivo) {
        archivo << "Nombre: " << nombreCliente << ", Fecha: " << fecha << ", Hora: " << hora << endl;
        cout << "Cita registrada correctamente." << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    //no
    // Crear un archivo con la fecha y hora de la cita
    ofstream archivoCita(carpetaDatos + nombreCliente + "_" + fecha + "_" + hora + ".txt");
    if (archivoCita) {
        archivoCita << "Nombre: " << nombreCliente << ", Fecha: " << fecha << ", Hora: " << hora << endl;
        cout << "Archivo de la cita creado correctamente." << endl;
    } else {
        cout << "Error al crear el archivo de la cita." << endl;
    }
}

//si Función para mostrar la lista de clientes
void mostrarClientes() {
    ifstream archivo(carpetaDatos + "clientes.txt");
    if (archivo) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

//si Función para buscar un cliente por nombre
void buscarClientePorNombre(const string& nombre) {
    ifstream archivo(carpetaDatos + "clientes.txt");
    if (archivo) {
        string linea;
        bool encontrado = false;
        while (getline(archivo, linea)) {
            size_t pos = linea.find(nombre);
            if (pos != string::npos) {
                cout << linea << endl;
                encontrado = true;
            }
        }
        if (!encontrado) {
            cout << "Cliente no encontrado." << endl;
        }
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}//hasta aqui

// Función para buscar citas por nombre de cliente
void buscarCitaPorNombre(const string& nombreCliente) {
    ifstream archivo(carpetaDatos + "citas.txt");
    if (archivo) {
        string linea;
        bool encontrado = false;
        while (getline(archivo, linea)) {
            size_t pos = linea.find(nombreCliente);
            if (pos != string::npos) {
                cout << linea << endl;
                encontrado = true;
            }
        }
        if (!encontrado) {
            cout << "No se encontraron citas para el cliente." << endl;
        }
    } else {
        cout << "Error al abrir el archivo de citas." << endl;
    }
}

// Función para registrar la dirección del cliente
void registrarDireccionCliente(Cliente& cliente) {
    cout << "Ingrese la dirección del cliente: ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, cliente.direccion);
}

// Función para registrar la fecha de registro del cliente
void registrarFechaRegistroCliente(Cliente& cliente) {
    cout << "Ingrese la fecha de registro del cliente (dd/mm/aaaa): ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, cliente.fechaRegistro);
}

//aqui si Función principal (main)
int main() {
    int opcion;
    string nombre;
    Cliente cliente;
    string fecha, hora;

    do {
        cout << "Menu de opciones:" << endl;
        cout << "1. Registrar nuevo cliente" << endl;
        cout << "2. Mostrar lista de clientes" << endl;
        cout << "3. Buscar cliente por nombre" << endl;
        cout << "4. Registrar nueva cita" << endl;
        cout << "5. Buscar cita por nombre de cliente" << endl;
        cout << "6. Registrar direccion del cliente" << endl;
        cout << "7. Registrar fecha de registro del cliente" << endl;
        cout << "0. Salir" << endl; // Cambié esta línea de "8. Salir" a "0. Salir"
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            // esta función registra un nuevo cliente,toma un objeto de tipo Cliente como argumento y guarda la información del cliente en un archivo
            case 1:
                cout << "Ingrese el nombre del cliente: ";
                cin >> cliente.nombre;
                cout << "Ingrese el teléfono del cliente: ";
                cin >> cliente.telefono;
                registrarDireccionCliente(cliente);
                registrarFechaRegistroCliente(cliente);
                registrarCliente(cliente);
                break;
         //registra una nueva cita para un cliente específico, toma el nombre del cliente, la fecha y la hora de la cita como argumentos y los guarda en un archivo l
            case 2:
                cout << "\nLista de clientes registrados:" << endl;
                mostrarClientes();
                break;
            case 3:
           //la función muestra la lista de clientes registrado, desde la carpeta de datos y muestra cada línea en la consola.
                cout << "Ingrese el nombre del cliente a buscar: ";
                cin >> nombre;
                buscarClientePorNombre(nombre);
                break;
           //busca un cliente por su nombre en el archivo, en la carpeta de datos, si encuentra el nombre del cliente en alguna línea del archivo, muestra esa línea en la consola.
            case 4:
                cout << "Ingrese el nombre del cliente: ";
                cin.ignore(); // Limpiar el buffer de entrada
                getline(cin, nombre);
                cout << "Ingrese la fecha de la cita (dd/mm/aaaa): ";
                cin >> fecha;
                cout << "Ingrese la hora de la cita (hh:mm): ";
                cin >> hora;
                registrarCita(nombre, fecha, hora);
                break;
            case 5:
                cout << "Ingrese el nombre del cliente para buscar sus citas: ";
                cin >> nombre;
                buscarCitaPorNombre(nombre);
                break;
            case 6:
                registrarDireccionCliente(cliente);
                break;
            case 7:
                registrarFechaRegistroCliente(cliente);
                break;
            case 0: // Cambié este caso de "8" a "0"
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    } while (opcion != 0); //

    return 0;
}