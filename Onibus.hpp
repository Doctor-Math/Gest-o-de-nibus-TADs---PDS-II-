#ifndef ONIBUS_H
#define ONIBUS_H

#include<iostream>
#include<string>

using namespace std;

struct Onibus{
	string placa;
	int capacidade;
	int lotacao;
	
	Onibus(string,int);
	void subir_passageiros(int &);
	void descer_passageiros(int &);
	void transfere_passageiros(Onibus*,int &);
	void imprimir_estado();
};

#endif
