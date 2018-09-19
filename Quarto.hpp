//
// Created by djalma cunha on 16/09/2018.
//

#ifndef HOTEL_QUARTO_HPP
#define HOTEL_QUARTO_HPP
#include <iostream>
#include "Pessoa.hpp"
#include "Configuracoes.hpp"
using namespace std;
/*
 * a ideia dessa classe é administar as pessoas como um quarto,
 * assim podemos separar melhor os gastos, porem tem que ser estipulado antes valores fixos,
 * como valor por pessoa fixo.
 */
class Quarto: public Pessoa {
public:
//a funcao quarto serve apenas para iniciar tudo zerado
    Quarto() {
        nPessoas = 0;
        consumo = 0;
        valor_total = 0;
    }
/*
 * a laco é um laco de repeticao comum para todas as categorias de quarto e elas
 * dao valor por pessoa para o quarto levando em conta se sao ou nao criancas
 */
    float laco(float adult, float crian, int np, Pessoa *vet) {
        for (int i = 0; i < nPessoas; i++) {
            if (vet[i].getIdade() <= 10) {
                vet[i].setAdulto(true);
                valor_total += valor_adulto;
            } else {
                vet[i].getAdulto(false);
                valor_total += valor_crianca;
            }
        }
        return valor_total;
    }

    void luxo(Pessoa *vet) {
        valor_crianca = 250;
        valor_adulto = 500;
        valor_total = laco(valor_adulto, valor_crianca, nPessoas, vet);
    }

    void comum(Pessoa *vet) {
        valor_crianca = 100;
        valor_adulto = 250;
        valor_total = laco(valor_adulto, valor_crianca, nPessoas, vet);
    }

    void economico(Pessoa *vet) {
        valor_crianca = 50;
        valor_adulto = 100;
        valor_total = laco(valor_adulto, valor_crianca, nPessoas, vet);
    }

    void setNpessoas(int num) {
        nPessoas = num;
    }

    int getNpessoas() {
        return nPessoas;
    }

    float getAdulto() {
        return valor_adulto;
    }

    float getCrianca() {
        return valor_crianca;
    }

private:
    int nPessoas;
    float consumo;
    float valor_adulto;
    float valor_crianca;
    float valor_total;
};


#endif //HOTEL_QUARTO_HPP
