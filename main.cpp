#include <iostream>
#include <string>
#include "Onibus.hpp"
#include "Empresa.hpp"

using namespace std;

int main() {
    char resp;
    string placa;
    int lotacao_max, num_pessoas, vaga;
    bool flag;
    Onibus* situacao;

    Empresa* Bus=new Empresa();

    do{
        cin>>resp;
        switch(resp){

            case 'C':
            {
            cin >> placa >> lotacao_max;
            situacao=Bus->adicionar_onibus(placa,lotacao_max);
            if(situacao!=nullptr){
                cout<<"novo onibus cadastrado"<<endl;
            }else{
                cout<<"ERRO : onibus repetido"<<endl;
            }
            }
            break;

            case 'S':
            {
            cin >> placa >> num_pessoas;
            flag=false;
            vaga=0;

            while(vaga < 20 && Bus->frota[vaga] != nullptr) {
                if(Bus->frota[vaga]->placa == placa) {
                    // Atualizar a lotação
                    Bus->frota[vaga]->subir_passageiros(num_pessoas);
                    flag = true;
                    break;
                }
                vaga++;
                }
            /*Se o ônibus não tiver sido encontrado...*/
            if(flag==false){
                cout<<"ERRO : onibus inexistente"<<endl;
                }
            }
            break;
            
            case 'D':
            {
            cin >> placa >> num_pessoas;
            flag=false;
            vaga=0;

            while(vaga<20 && Bus->frota[vaga]!=nullptr){
                /*Verificamos se há alguma vaga de ônibus correspondente à placa recebida:*/
                if(Bus->frota[vaga]->placa==placa){
                        Bus->frota[vaga]->descer_passageiros(num_pessoas);
                        flag=true;
                        break;        
                }
                vaga++;
            }

            if(!flag){
                cout<<"ERRO : onibus inexistente"<<endl;
                }
            }
            break;

            case 'T': 
            {
                string placa_1, placa_2;
                cin >> placa_1 >> placa_2 >> num_pessoas;
                int vaga = 0;
                int correspondencia = 0;
                int posicao_1 = -1, posicao_2 = -1;

                // Loop para encontrar ônibus correspondentes às placas
                while (vaga < 20 && Bus->frota[vaga] != nullptr) {
                    if (Bus->frota[vaga]->placa == placa_1) {
                        correspondencia++;
                        posicao_1 = vaga;
                        }
                    if (Bus->frota[vaga]->placa == placa_2) {
                        correspondencia++;
                        posicao_2 = vaga;
                        }
                vaga++;
                }
                        
                // Verificação de correspondência das placas
                if (correspondencia != 2) {
                    cout << "ERRO : onibus inexistente"<<endl;
                } else {
                    Bus->frota[posicao_1]->transfere_passageiros(Bus->frota[posicao_2], num_pessoas);
                    }
            } 
            break;

            case 'I':
            {
            Bus->imprimir_estado();
            }
            break;
            
            default:
            break;

        }
    }while(resp!='F');
    delete Bus;
}
