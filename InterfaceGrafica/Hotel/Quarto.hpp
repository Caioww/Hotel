#ifndef HOTEL_QUARTO_HPP
#define HOTEL_QUARTO_HPP
#include <iostream>
#include "Configuracoes.hpp"
#include "Pilha.hpp"
#include "Senha.hpp"
#include "Caracteristicas.hpp"
using namespace std;
class Quarto{
public:

    //para criar inicialmente os quartos pré estipulados, inicialmente todos livres
    void ocuparQuarto(int numero,int pessoas,string tipo,string descricao,double valor,int quantidade,int andar){
        auxiliar.numero = numero;
        auxiliar.nPessoas = pessoas;
        auxiliar.tipoQuarto = tipo;
        auxiliar.descricao = descricao;
        auxiliar.valor_diaria = valor;
        auxiliar.existentes = quantidade;
        auxiliar.andar = andar;
        prato.empilha(auxiliar);
        quant++;
    }


    void buscaQuarto(int numero){
        int l = 0;
        while (l < quant){
            //nao inverter os valores
            prato.busca(numero,l);
            l++;
        }

    }

    //esta imprimindo apenas 1
    void imprime(){
        //bolar esquema para descobrir quantidade de quartos

        int l = 0;
        while (l < quant){

            prato.imprime(l);
            l++;
        }
    }


    void remove1(int numero){
        Caracteristicas temp[quant];
        int init = quant;
        for (int k = 0; k < quant; k++) {
            prato.copia(numero,k,temp,quant);
        }
        for (int i = 0; i < init; i++) {
            if(prato.remove(numero,i,temp,quant)){
                quant = init -1;
            }
        }
        prato.topo = 0;
        for (int j = 0; j < quant; j++) {
            prato.empilha(temp[j]);
        }
    }

private:
    int quant = 0;

    Pilha prato;
    Caracteristicas auxiliar;
};


#endif //HOTEL_QUARTO_HPP
