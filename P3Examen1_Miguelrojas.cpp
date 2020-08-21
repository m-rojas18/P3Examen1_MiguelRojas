#include <iostream>
#include <vector>
#include "PC.hpp"
using namespace std;


void imprimirPCs(vector<PC*>);
int main(){
    //Crear vector
    vector<PC*> lista_PCs;
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
            lista_PCs.push_back(nueva_pc);
            cout << "Se agrego exitosamente la PC!!!\n";
            break;
        }
        case 2:{
            //Opcion Ingresar a PC
            //Verificar si existen Pcs
            if(lista_PCs.empty()){
                cout << "No existe ninguna PC\n";
            } else {
                //Existe minimo 1 PC
                int opcion_pc;
                cout << "Lista de PCs: " << endl;
                imprimirPCs(lista_PCs);
                cout << "Seleccione una PC: ";
                cin >> opcion_pc;

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


void imprimirPCs(vector<PC*> lista_PCs){


    for (int i = 0; i < lista_PCs.size(); i++){
        PC* pc_temporal = lista_PCs.at(i);
        cout << "PC [" << i << "] " << "Host Name: " << pc_temporal->getHost_Name() << ", Direccion IP: " << pc_temporal->getDireccion_IP() 
        << ", Mascara de Red: " << pc_temporal->getMascara_Red() << endl;
    }
    cout << endl;
    
}