#include <iostream>
#include <vector>
using namespace std;

int main(){
    char seguir = 's';
    int opcion_usuario;
    while(seguir == 's'){
        cout << "\nMenu Examen 1 P3" << endl
            << "[1] Agregar PC" << endl
            << "[2] Ingresar a PC" << endl
            << "[3] Salir " << endl
            << "Seleccione una opcion: ";
        cin >> opcion_usuario;
        switch (opcion_usuario){
        case 1:{
            //Opcion Agregar PC
            break;
        }
        case 2:{
            //Opcion Ingresar a PC
            break;
        }
        case 3:{
            //Opcion Salir
            seguir = 'n';
            cout << "Fin de Programa\n";
            break;
        }
        default:
        cout << "Ingreso una opcion invalida.\n\n";
            break;
        }
    }

    return 0;
}