#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include <string>
#include "Onibus.hpp"

using namespace std;

struct Empresa{
    int num_onibus_cadastrados;
    Onibus* frota[20];

    Empresa();
    Onibus* adicionar_onibus(string, int);
    Onibus* busca_onibus(string);
    void imprimir_estado();

};

#endif
