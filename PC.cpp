#include "PC.hpp"
#include <iostream>
#include <cstring>
using namespace std;

PC::PC(string direccion_IP, string mascara_red, string host_name){
    this->direccion_IP = direccion_IP;
    this->mascara_red = mascara_red;
    this->host_name = host_name;
}

string PC::getDireccion_IP(){return direccion_IP;}
string PC::getHost_Name(){return host_name;}
string PC::getMascara_Red(){return mascara_red;}

PC::~PC(){}
