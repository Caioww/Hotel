//
// Created by djalma cunha on 16/09/2018.
//

#ifndef HOTEL_QUARTO_HPP
#define HOTEL_QUARTO_HPP
#include <iostream>
#include "Pessoa.hpp"
#include "Configuracoes.hpp"
#include "Senha.hpp"
using namespace std;
/*

* Edit Caio:Classe para cadastrar os quartos assim depois que cadastrar ,
 dependendo do tipo de quarto que a pessoa quiser só precisaremos chamar a classe.
 */
class Quarto: public Pessoa {
public:
//a funcao quarto serve apenas para iniciar tudo zerado
    Quarto() {
       valor_diaria = -1;
       nPessoas = -1;
       estado = false;
       tipoQuarto = "-1";
       descricao = "-1";
       numero = -1;
       andar = -1;
    }

    void adcionaQuarto(){

}

private:

    int checaNivel(){
        Senha var;
        return var.confereSenha();
}

    float valor_diaria;
    int nPessoas;
    bool estado; //Disponivel ou Ocupado;
    string tipoQuarto;
    string descricao;//Exemplo:Quarto de frente pro mar
    int numero;
    int andar;
    //Fazer um List que armazena os quartos cadastrados,

};


#endif //HOTEL_QUARTO_HPP
