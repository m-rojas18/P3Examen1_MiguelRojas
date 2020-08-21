#include "PC.hpp"
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

PC::PC(string direccion_IP, string mascara_red, string host_name){
    this->direccion_IP = direccion_IP;
    this->mascara_red = mascara_red;
    this->host_name = host_name;
}

string PC::getDireccion_IP(){return direccion_IP;}
string PC::getHost_Name(){return host_name;}
string PC::getMascara_Red(){return mascara_red;}


//Metodo Ping
void PC::ping(string ip_buscado){
    //Conseguir valores de ip de pc ingresada
    string delimitador = ".";
    string cadena_temporal = direccion_IP;
    int posicion = 0;
    vector<string> valores_direccion_ip;
    //Recorrer cadena y agregar numeros a lista de string
    while((posicion = cadena_temporal.find(delimitador))!= string::npos){
        valores_direccion_ip.push_back(cadena_temporal.substr(0, posicion));
        cadena_temporal.erase(0, posicion + delimitador.length());
    }
    valores_direccion_ip.push_back(cadena_temporal);

    //Convertir valores de string obtenidos a int
    int numeros_direccionIP_usuario[4];
    for (int i = 0; i < 4; i++){
        int entero_temporal = std::stoi(valores_direccion_ip[i]);
        numeros_direccionIP_usuario[i] = entero_temporal;
    }

    //Repetir proceso con la direccion ip buscada
    string cadena_buscada_temporal = ip_buscado;
    int posicion_2 = 0;
    vector<string> valores_direccion_buscada;
    
    while((posicion_2 = cadena_buscada_temporal.find(delimitador))!= string::npos){
        valores_direccion_buscada.push_back(cadena_buscada_temporal.substr(0, posicion_2));
        cadena_buscada_temporal.erase(0, posicion_2 + delimitador.length());
    }
    valores_direccion_buscada.push_back(cadena_temporal);
    int numeros_direccionIP_buscada[4];
    //Convertir valores de string obtenidos a int
    for (int i = 0; i < 4; i++){
        int entero_temporal = std::stoi(valores_direccion_buscada[i]);
        numeros_direccionIP_buscada[i] = entero_temporal;
    }


    //Convertir direccion ip de usuario a binario
    vector<string> binario_ip_usuario;
    for (int i = 0; i < 4; i++){
        int valor_temporal = numeros_direccionIP_usuario[i];
        cout << "Valores [" << i << "]" << valor_temporal << endl;
        string valor_binario = conversionBinario(valor_temporal);
        cout << "[" << i << "]"<< valor_binario << endl;
        binario_ip_usuario.push_back(valor_binario);
    }
    
}

string PC::conversionBinario(int numero){
    int arreglo_binario[100];
    int contador = 0;
    string binario;
    while(numero > 0){
        arreglo_binario[contador] = numero % 2;
        numero = numero /2;
        contador++;
    }

    for (int i = contador - 1; i >=0 ; i--){
        binario += std::to_string(arreglo_binario[i]);
    }
    int contador_ceros = -7;
    string cero = "0";
    
    return binario;
    
}
//Destructor
PC::~PC(){}
