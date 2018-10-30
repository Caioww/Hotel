//
// Created by djalma cunha on 05/09/2018.
//

#ifndef PILHA_PILHA_HPP
#define PILHA_PILHA_HPP
#include <iostream>
#include <cstdlib>
#include <cstring>
#define num 10
using namespace std;


class Pilha {
private:
    int topo;
    int maximo;

    struct caracteristica {
        float valor_diaria;
        int nPessoas;
        bool estado; //Disponivel ou Ocupado;
        string tipoQuarto;
        string descricao;//Exemplo:Quarto de frente pro mar
        int numero;
        int andar;
        //Fazer um List que armazena os quartos cadastrados,
        int disponiveis;
        int existentes;
        int inicial;
        int faixa_de_numeros;
    };

    typedef struct caracteristica caracteristica;

    caracteristica* v;

    bool realoca(){
        puts("dobrou");
        caracteristica* vTemp = new caracteristica[maximo*2];
        if(vTemp == NULL){
            return true;
        }
        memcpy(vTemp,v, sizeof(caracteristica)*maximo);
        maximo *=2;
        delete [] v;
        v = vTemp;
        return true;
    }
public:
    Pilha() : v(new caracteristica[num]),topo(0),maximo(num){

    }

    bool empilha(float valor_diaria, int nPessoas, bool estado, string tipoQuarto, string descricao,
                 int numero, int andar, int disponiveis, int existentes, int inicial, int faixa_de_numeros){

        caracteristica valor;
        valor.valor_diaria = valor_diaria;
        valor.nPessoas = nPessoas;
        valor.estado = estado;
        valor.tipoQuarto = tipoQuarto;
        valor.descricao = descricao;
        valor.numero = numero;
        valor.andar = andar;
        valor.disponiveis = disponiveis;
        valor.existentes = existentes;
        valor.inicial = inicial;
        valor.faixa_de_numeros = faixa_de_numeros;
        if (topo == maximo)
            if(!realoca()){
                return false;
            }


        v[topo++] = valor;
        return true;
    }

    virtual ~Pilha(){
        delete [] v;
    }

    //bolar esquema
    bool desemplilha(Pilha *des = NULL) {
        if (topo == 0) {
            return false;
        }
        topo--;
        if(des)
            *des = &v[topo];
        return true;
    }

};


#endif //PILHA_PILHA_HPP
