#include <string>
#include "Empresa.hpp"
#include <cmath>

using namespace std;

Empresa::Empresa(){
    this->num_onibus_cadastrados=0;
    for(int i=0;i<20;i++){
        this->frota[i]=nullptr;
    }
}

Onibus* Empresa::adicionar_onibus(string placa, int capacidade){
    for(int vaga=0; vaga<20; vaga++){
        if(this->frota[vaga] != nullptr && this->frota[vaga]->placa == placa) {
            return nullptr; // Placa já cadastrada
        }
    }

    for(int vaga=0; vaga<20; vaga++){
        if(this->frota[vaga] == nullptr) {
            this->frota[vaga] = new Onibus(placa, capacidade); // Aloca novo ônibus
            this->num_onibus_cadastrados++; // Atualiza contador
            return this->frota[vaga];
        }
    }
    return nullptr; // Frota cheia
}

Onibus* Empresa::busca_onibus(string placa){
    for(int vaga=0; vaga<20; vaga++){
        if(this->frota[vaga] != nullptr && this->frota[vaga]->placa == placa){
            return this->frota[vaga];
        }
    }
    return nullptr; // Não encontrado
}

void Empresa::imprimir_estado(){
    for(int vaga=0; vaga<20; vaga++){
        if(this->frota[vaga] != nullptr){
            cout << this->frota[vaga]->placa << " (" 
                 << this->frota[vaga]->lotacao << "/" 
                 << this->frota[vaga]->capacidade << ")" << endl;
        }
    }
}
