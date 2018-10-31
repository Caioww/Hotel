//
// Created by djalma cunha on 05/09/2018.
//

#ifndef PILHA_PILHA_HPP
#define PILHA_PILHA_HPP
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Caracteristicas.hpp"
#define num 10
using namespace std;


class Pilha {
public:
    int topo;
    int maximo;
    Caracteristicas* v;

    bool realoca(){
        puts("dobrou");
        Caracteristicas* vTemp = new Caracteristicas[maximo*2];
        if(vTemp == NULL){
            return true;
        }
        memcpy(vTemp,v, sizeof(Caracteristicas)*maximo);
        maximo *=2;
        delete [] v;
        v = vTemp;
        return true;
    }

    Pilha() : v(new Caracteristicas[num]),topo(0),maximo(num){

    }

    bool empilha(float valor_diaria, int nPessoas, bool estado, string tipoQuarto, string descricao,
                 int numero, int andar, int disponiveis, int existentes, int inicial, int faixa_de_numeros){

        Caracteristicas valor;
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

    bool empilha(Caracteristicas valor){
        if (topo == maximo)
            if(!realoca()){
                return false;
            }


        v[topo++] = valor;
        return true;
    }

    void imprime(int z){
        cout<<v[z].descricao<<endl;
    }


    //bolar esquema
    bool desemplilha(Caracteristicas *des = NULL) {
        if (topo == 0) {
            return false;
        }
        topo--;
        if(des)

            *des = v[topo];
        return true;
    }

};


#endif //PILHA_PILHA_HPP
