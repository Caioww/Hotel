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
        nome = "-1";
        sexo = "-1";
        RG = "-1";
        tipoQuarto = "-1";
        email = "-1";
        modeloCarro = "-1";
        placa = "-1";
        adulto = false;

    }

    void setCarro(string model){
        modeloCarro = model;
    }

    string getCarro(){
        return modeloCarro;
    }

    void setPlaca(string abc){
        placa = abc;
    }

    string getPlaca(){
        return placa;
    }

    void setRG(string txt){
        RG = txt;
    }

    string getRG(){
        return RG;
    }

    void setEmail(string txt){
        email = txt;
    }

    string getEmail(){
        return email;
    }

    void setQuarto(string txt){
        tipoQuarto = txt;
    }

    string getQuarto(){
        return tipoQuarto;
    }

    void setNome(string txt){
        nome = nome;
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

    string getSexo(){
        return sexo;
    }

private:
        string nome;
        string RG;
        string sexo;
        string email;
        string tipoQuarto;
        string modeloCarro;
        string placa;
        bool adulto;
};


#endif //HOTEL_PESSOA_HPP
