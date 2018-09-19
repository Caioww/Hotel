//
// Created by djalma cunha on 19/09/2018.
//

#ifndef HOTEL_PESSOA_HPP
#define HOTEL_PESSOA_HPP
#include <iostream>
using namespace std;
/*
 * uma classe bem simples tipo pessoa para conseguirmos adminstrar as pessoas
 */
class Pessoa {
public:
    Pessoa(){
        nome = "ninguem";
        idade = -1;
        sexo = "indefinido";
    }
    void setNome(string txt){
        nome = nome;
    }

    void setIdade(int um){
        if(um <= 10){
            adulto = true;
        } else{
            adulto = false;
        }
        idade = um;
    }

    void setSexo(string txt){
        sexo = txt;
    }

    void setAdulto(bool ok){
        adulto = ok;
    }

    bool getAdulto(bool b) {
        return adulto;
    }

    string getNome(){
        return nome;
    }

    int getIdade(){
        return idade;
    }

    string getSexo(){
        return sexo;
    }

private:
    string nome;
    int idade;
    string sexo;
    bool adulto;

};


#endif //HOTEL_PESSOA_HPP
