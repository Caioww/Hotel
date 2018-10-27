//
// Created by djalma cunha on 27/10/18.
//

#ifndef HOTEL_COLA_HPP
#define HOTEL_COLA_HPP
#include <iostream>
#include <stdio.h>
using namespace std;

class Cola {
public:
    struct money {
        string nome;
        int dia;
        int mes;
        int ano;
        int idade;
        string RG;
        string cidade;
        string estado;
        string telefone;
        string celular;
        string email;
        bool sexo = false;
    };
    typedef struct money money;
    Cola* proximo;
    Cola* anterior;

    money centavo;

    Cola(money centavo): proximo(NULL), anterior(NULL), centavo(centavo){

    }
    ~Cola(){
        cout << "deletando no" << endl;
    }


};


#endif //HOTEL_COLA_HPP
