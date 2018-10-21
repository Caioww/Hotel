//
// Created by Caio on 20/10/2018.
//

#ifndef HOTEL_QUARTO_HPP
#define HOTEL_QUARTO_HPP

#include <iostream>
using namespace std;

class Quarto{
    public:
        Quarto(){

        }

    void setNumero(string model){
        numero = model;
    }

    string getNumero(){
        return numero;
    }

    void setAndar(string model){
        andar = model;
    }

    string getAndar(){
        return andar;
    }

    void setTipoQuarto(string model){
        tipoQuarto = model;
    }

    string getTipoQuarto(){
        return tipoQuarto;
    }

    void setEstado(string model){
        estado = model;
    }

    string getEstado(){
        return estado;
    }

    void setDateInicial(string model){
        dateInicial = model;
    }

    string getDateInicial(){
        return dateInicial;
    }

    void setDateFim(string model){
        dateFim = model;
    }

    string getDateFim(){
        return dateFim;
    }

    void setPessoas(string model){
        pessoas = model;
    }

    string getPessoas(){
        return pessoas;
    }

    void setValor(string model){
        valor = model;
    }

    string getValor(){
        return valor;
    }

    private:
        string id;
        string numero;
        string andar;
        string tipoQuarto;
        string estado;
        string valor;
        string dateInicial;
        string dateFim;
        string pessoas;
};
#endif //HOTEL_QUARTO_HPP
