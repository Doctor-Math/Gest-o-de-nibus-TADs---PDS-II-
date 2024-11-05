#include <iostream>
#include <string>
#include "Onibus.hpp"
#include <cmath>

using namespace std;

Onibus::Onibus(string placa, int capacidade){
    this->placa=placa;
    this->capacidade=capacidade;
    this->lotacao=0;
}
void Onibus::subir_passageiros(int &quantidade){
    if((quantidade + this->lotacao) > (this->capacidade)) {
        cout << "ERRO : onibus lotado"<<endl;
    } else {
        this->lotacao+=quantidade;
        cout << "passageiros subiram com sucesso"<<endl;
    }
}

void Onibus::descer_passageiros(int &quantidade){
    /*Analisamos se o ônibus tem capacidade para receber todos os passageiros:*/
    if((this->lotacao-quantidade)<0){
        cout<<"ERRO : faltam passageiros"<<endl;
    }else{
        this->lotacao-=quantidade;
        cout<<"passageiros desceram com sucesso"<<endl;
    }

}

void Onibus::transfere_passageiros(Onibus* o2, int &quantidade){
    // Verifica se a transferência é possível considerando as capacidades
    if ((this->lotacao - quantidade) < 0 || (o2->lotacao + quantidade) > (o2->capacidade)) {
        cout << "ERRO : transferencia cancelada"<<endl;
    } else {
    // Realiza a transferência de passageiros
        o2->lotacao+=quantidade;
        this->lotacao-=quantidade;
        cout << "transferencia de passageiros efetuada"<<endl;
    }
    
}

void Onibus::imprimir_estado(){
cout<<this->placa<<" ("<<this->lotacao<<"/"<<this->capacidade<<")";
}
