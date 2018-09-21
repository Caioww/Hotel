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

* Edit Caio:Classe para cadastrar os quartos assim depois que cadastrar ,
 dependendo do tipo de quarto que a pessoa quiser só precisaremos chamar a classe.
 */
class Quarto: public Pessoa {
public:
//a funcao quarto serve apenas para iniciar tudo zerado
    Quarto() {
       
    }
/*
 * a laco é um laco de repeticao comum para todas as categorias de quarto e elas
 * dao valor por pessoa para o quarto levando em conta se sao ou nao criancas
 */

private:

  

    float valor_diaria;
    int nPessoas;
    bool estado; //Disponivel ou Ocupado;
    String tipoQuarto;
    String descricao;//Exemplo:Quarto de frente pro mar
    int numero;
    int andar;
    //Fazer um List que armazena os quartos cadastrados,

};


#endif //HOTEL_QUARTO_HPP
