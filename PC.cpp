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
    vector<string> numeros_direccion_ip;
    
    while((posicion = cadena_temporal.find(delimitador))!= string::npos){
        numeros_direccion_ip.push_back(cadena_temporal.substr(0, posicion));
        cadena_temporal.erase(0, posicion + delimitador.length());
    }

    numeros_direccion_ip.push_back(cadena_temporal);

    for (int i = 0; i < numeros_direccion_ip.size(); i++){
        cout << numeros_direccion_ip[i] << endl;
    }
    
    
    
    
}
PC::~PC(){}
