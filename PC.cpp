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

void PC::ping(string ip_buscado, vector<PC*> lista_pcs){
    //Conseguir valores de ip de pc ingresada
    vector<string> valores_direccion_ip = separarNumeros(direccion_IP);
    //Convertir valores de string obtenidos a int de direccion ip de usuario
    int numeros_direccionIP_usuario[4];
    for (int i = 0; i < 4; i++){
        int entero_temporal = std::stoi(valores_direccion_ip[i]);
        numeros_direccionIP_usuario[i] = entero_temporal;
    }
    //Repetir proceso con la direccion ip buscada
    vector<string> valores_direccion_buscada =separarNumeros(ip_buscado);//Separar numeros
    //Convertir valores de string obtenidos a int de direccion de ip buscada
    int numeros_direccionIP_buscada[4];
    for (int i = 0; i < 4; i++){
        int entero_temporal = std::stoi(valores_direccion_buscada[i]);
        numeros_direccionIP_buscada[i] = entero_temporal;
    }

    //Convertir direccion ip de usuario a binario
    vector<string> binario_IP_usuario;
    for (int i = 0; i < 4; i++){
        string valor_binario = conversionBinario(numeros_direccionIP_usuario[i]);
        binario_IP_usuario.push_back(valor_binario);
    }

    //Convertir direccion ip buscada a binario
    vector<string> binarios_IP_buscado;
    for (int i = 0; i < 4; i++){
        string valor_binario = conversionBinario(numeros_direccionIP_buscada[i]);
        binarios_IP_buscado.push_back(valor_binario);
    }


    //Separar numeros de mascara de red
    vector<string> valores_mascara_red = separarNumeros(mascara_red);
    //Convertir valores de string a int
    int numeros_mascara_red[4];
    for(int i = 0; i < 4; i++){
        int numero_temporal = std::stoi(valores_mascara_red[i]);
         numeros_mascara_red[i] = numero_temporal;
    }

    //Convertir mascara de red a binario
    vector<string> binario_mascara_red;
    for (int i = 0; i < 4; i++){
        string valor_binario = conversionBinario(numeros_mascara_red[i]);
        binario_mascara_red.push_back(valor_binario);
    }

    //Encontrar cantidad de 1's en la mascara de red
    //Hacer una sola string de los binarios
    string binario_mascara = unirBinarios(binario_mascara_red);
    
    int cantidad_uno = 0;
    for(int i =0; i < binario_mascara.length(); i++){
        char caracter_temporal = binario_mascara[i];
        if(caracter_temporal == '1'){
            cantidad_uno++;
        }
    }
    //Conseguir cadena de ip de usuario con respecto a la cantidad de 1's
    string salida_binario_IPuser = unirBinarios(binario_IP_usuario);
    string ip_comparacion_user = salida_binario_IPuser.substr(0, cantidad_uno);

    //Conseguir cadena de ip buscado con respecto a la cantidad de 1's
    string salida_binario_IP_buscado = unirBinarios(binarios_IP_buscado);
    string ip_comparacion_buscado = salida_binario_IP_buscado.substr(0, cantidad_uno);
    //Compararar ip's y mostrar impresion
    if(ip_comparacion_user != ip_comparacion_buscado){
        //Inalcanzable, no son iguales
        cout << "\nPinging to " << ip_buscado << " with 32 bytes of data: " << endl
            << "Reply from " << ip_buscado << ": Destination host unreachable" << endl
            << "Reply from " << ip_buscado << ": Destination host unreachable" << endl
            << "Reply from " << ip_buscado << ": Destination host unreachable" << endl
            << "Reply from " << ip_buscado << ": Destination host unreachable" << endl
            << endl
            << "Ping statistics for " << ip_buscado << ": " << endl
            << "   Packets: Sent = 4, Recieved = 4, Lost = 0 (0% loss)" << endl << endl;
    } else {
        //Ping exitoso
        cout << "\nPinging to " << ip_buscado << " with 32 bytes of data: " << endl
            << "Reply from " << ip_buscado << ": bytes=32 time=37ms TTL=46" << endl
            << "Reply from " << ip_buscado << ": bytes=32 time=37ms TTL=46" << endl
            << "Reply from " << ip_buscado << ": bytes=32 time=37ms TTL=46" << endl
            << "Reply from " << ip_buscado << ": bytes=32 time=37ms TTL=46" << endl
            << endl
            << "Ping statistics for " << ip_buscado << ": " << endl
            << "   Packets: Sent = 4, Recieved = 4, Lost = 0 (0% loss)" << endl << endl;
    }
}

vector<string> PC::separarNumeros(string direccion){
    vector<string> vector_temporal;
    string delimitador = ".";
    string cadena_temporal = direccion;
    int posicion = 0;
    //Recorrer cadena y agregar numeros a lista de string
    while((posicion = cadena_temporal.find(delimitador))!= string::npos){
        vector_temporal.push_back(cadena_temporal.substr(0, posicion));
        cadena_temporal.erase(0, posicion + delimitador.length());
    }
    vector_temporal.push_back(cadena_temporal);    
    return vector_temporal;
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
    while(binario.length() < 8){
        binario.insert(0, "0");
    }
    return binario;
}
string PC::unirBinarios(vector<string> lista_binarios){
    string cadena_temporal;
    for(int i = 0; i < lista_binarios.size(); i ++)
        cadena_temporal += lista_binarios[i];
    
    return cadena_temporal;
}
//Destructor
PC::~PC(){}
