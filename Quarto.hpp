//
// Created by djalma cunha on 16/09/2018.
//

#ifndef HOTEL_QUARTO_HPP
#define HOTEL_QUARTO_HPP
#include <iostream>
using namespace std;
/*

* Edit Caio:Classe para cadastrar os quartos assim depois que cadastrar ,
 dependendo do tipo de quarto que a pessoa quiser só precisaremos chamar a classe.
 */
class Quarto {
public:
    void luxo(){

    }
    void comum(){

    }
    void economico(){

    }
private:
    float valor_diaria;
    int limitePessoas;
    String estado; //Disponivel ou Ocupado;
    String tipoQuarto;
    String descricao;//Exemplo:Quarto de frente pro mar
    int numero;
    int andar;
    //Fazer um List que armazena os quartos cadastrados,
};


#endif //HOTEL_QUARTO_HPP
