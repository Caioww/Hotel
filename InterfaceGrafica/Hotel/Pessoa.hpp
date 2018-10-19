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
	}
    /*Pessoa(){
        nome = "-1";
        sexo = "-1";
        RG = "-1";
        tipoQuarto = "-1";
        email = "-1";
        modeloCarro = "-1";
        placa = "-1";
        adulto = false;

    }
    
    Pessoa(){
        nome = "-1";
        sexo = "-1";
        idade = "-1";
        RG = "-1";
        tipoQuarto = "-1";
        email = "-1";
        cidade = null;
        estado = null;
        telefone = "-1";
        celular = "-1";
        modeloCarro = "-1";
        placa = "-1";
        adulto = false;

    }*/

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




    void setQuarto(string txt){
        tipoQuarto = txt;
    }

    string getQuarto(){
        return tipoQuarto;
    }




    void setAdulto(bool ok){
        adulto = ok;
    }

    bool getAdulto(bool b) {
        return adulto;
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


    void setNome(string txt){
        nome = txt;
    }

    void setSexo(string txt){
        sexo = txt;
    }

    string getNome(){
        return nome;
    }

    string getSexo(){
        return sexo;
    }

    void setCidade(string txt){
        cidade = txt;
    }

    string getCidade(){
        return cidade;
    }

    void setEstado(string txt){
        estado = txt;
    }

    string getEstado(){
        return estado;
    }

    void setTelefone(string txt){
        telefone= txt;
    }

    string getTelefone(){
        return telefone;
    }

    void setCelular(string txt){
        celular= txt;
    }

    string getCelular(){
        return celular;
    }

    void setIdade(string txt){
        idade= txt;
    }

    string getIdade(){
        return idade;
    }

    void setData(string txt){
        data = txt;
    }

    string getData(){
        return data;
    }

private:
        string nome;
        string idade;
        string RG;
        string sexo;
        string data;
        string email;
        string cidade;
        string estado;
        string telefone ;
        string celular;
        string tipoQuarto;
        string modeloCarro;
        string placa;
        bool adulto;
};


#endif //HOTEL_PESSOA_HPP
