#include <iostream>
#include <cstring>
using namespace std;

#pragma once

class PC{
    //atributos
    public:
        string direccion_IP;
        string mascara_red;
        string host_name;
    //constructor y metodos administradores
    public:
        PC(string,string,string);
        string getDireccion_IP();
        string getMascara_Red();
        string getHost_Name();
        void ping(string, vector<PC*>);
        vector<string> separarNumeros(string);
        string unirBinarios(vector<string>);
        string conversionBinario(int);
        ~PC();

};

