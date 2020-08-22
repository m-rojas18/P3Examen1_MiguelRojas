#include <iostream>
#include <vector>
#include "PC.hpp"
using namespace std;


void imprimirPCs(vector<PC*>);

int main(){
    //Crear vector
    vector<PC*> lista_PCs;
    PC* pc_definida = new PC("192.168.3.58", "255.255.255.192", "Miguel");
    PC* pc_definida2 = new PC("192.168.3.248","255.255.255.128", "Mikasa");
    lista_PCs.push_back(pc_definida);
    lista_PCs.push_back(pc_definida2);
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
            cout << "Ingrese el nombre del host de la PC: ";
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
            //Verificar si existen PCs
            if(lista_PCs.empty()){
                cout << "No existe ninguna PC\n";
            } else {
                //Existe minimo 1 PC
                //Dejar al usuario elegir una PC
                int opcion_pc;
                imprimirPCs(lista_PCs);
                cout << "Seleccione una PC: ";
                cin >> opcion_pc;
                cout << endl;
                while(opcion_pc > lista_PCs.size() || opcion_pc < 0){
                    cout << "Ingrese una opcion invalida\n";
                    imprimirPCs(lista_PCs);
                    cout << "Seleccione una PC: ";
                    cin >> opcion_pc;
                    cout << endl;
                }
                //Conseguir PC elegida
                PC* pc_seleccionada = lista_PCs.at(opcion_pc);
                //Comandos y Funciones del Programa
                string comando = "";
                bool seguir_terminal = true;
                //Opciones de Comandos
                while(seguir_terminal == true){
                    cout << pc_seleccionada->getHost_Name() << "#";
                    cin >> comando;
                    //conseguir substring para verificar el comando
                    string validar_comando_ping = comando.substr(0, 4);

                    if(comando == "show"){
                        //Opcion show
                        cout << "      IP: " << pc_seleccionada->getDireccion_IP() << endl
                            <<  "      Netmask: " << pc_seleccionada->getMascara_Red() << endl;
                    } else if(comando.substr(0,5) == "ping_"){
                        //Opcion Ping
                        string direccion_ip_buscada = comando.substr(5);
                        pc_seleccionada->ping(direccion_ip_buscada, lista_PCs);
                    }else if(comando == "exit"){
                        //El usuario puso el comando exit
                        seguir_terminal = false;  
                        cout << "Termino la sesion\n";
                        break;
                    } else 
                        cout << "      Ingreso un comando invalido.\n";

                    comando = "";
                    validar_comando_ping = "";
                } 
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

    cout << "Lista de PCs: " << endl;
    for (int i = 0; i < lista_PCs.size(); i++){
        PC* pc_temporal = lista_PCs.at(i);
        cout << "PC [" << i << "] " << "Host Name: " << pc_temporal->getHost_Name() << ", Direccion IP: " << pc_temporal->getDireccion_IP() 
        << ", Mascara de Red: " << pc_temporal->getMascara_Red() << endl;
    }
    cout << endl;
    
}