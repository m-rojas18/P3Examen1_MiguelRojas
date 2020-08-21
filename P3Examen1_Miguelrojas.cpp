#include <iostream>
#include <vector>
#include "PC.hpp"
using namespace std;

int main(){
    //Crear vector
    vector<PC*> lista_PC;
    char seguir = 's';
    int opcion_usuario;
    while(seguir == 's'){
        cout << "\nMenu Examen 1 P3" << endl
            << "[1] Agregar PC" << endl
            << "[2] Ingresar a PC" << endl
            << "[3] Salir " << endl
            << "Seleccione una opcion: ";
        cin >> opcion_usuario;
        cout << endl;
        switch (opcion_usuario){
        case 1:{
            //Opcion Agregar PC
            string direccion_ip = "";
            string mascara_red = "";
            string host_name = "";
            //Pedir Datos
            cout << "Ingrese la direccion IP de la PC: ";
            cin >> direccion_ip;
            cout << endl;
            cout << "Ingrese la mascara de red de la PC: ";
            cin >> mascara_red;
            cout << endl;
            cout << "Ingrese el nombre del host de la PC:";
            cin >> host_name;
            cout << endl;
            //Crear Objeto
            PC* nueva_pc = new PC(direccion_ip,mascara_red, host_name);
            //Agregar a lista de PCs
            lista_PC.push_back(nueva_pc);
            cout << "Se agrego exitosamente la PC\n";
            break;
        }
        case 2:{
            //Opcion Ingresar a PC

            //Seleccionar una PC
            if(lista_PC.empty()){
                cout << "No existe ninguna PC\n";
            } else {
                //Existe minimo 1 PC
                
            }
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