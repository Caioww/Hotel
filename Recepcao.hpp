//
// Created by djalma cunha on 25/09/18.
//

#ifndef HOTEL_RECEPCAO_HPP
#define HOTEL_RECEPCAO_HPP
#include <iostream>
#include "Pessoa.hpp"
using namespace std;
#include "Fila.hpp"
template <typename T>
class Recepcao{
public:

    /*
     * nao irei colocar tipo de quarto pois a fila ira mudar de acordo com o tipo de quarto
     * logo tal questao sera aplicada em outra funcao
     */
    void agenda() {
        Pessoa pe;
        string txt;
        int num;
        senha = 0;
        puts("insira o nome do cliente");
        cin >> txt;
        pe.setNome(txt);
        puts("insira o RG");
        cin >> txt;
        pe.setRG(txt);
        puts("insira o sexo");
        cin >> txt;
        pe.setSexo(txt);
        puts("tem email?\n Y - sim // N - não");
        cin >> txt;
        if (txt == "y") {
            puts("insira email(se tiver)");
            cin >> txt;
            pe.setEmail(txt);
        }
        puts("tem carro?\n Y - sim // N - não");
        cin >> txt;
        if (txt == "y") {
            puts("insira o modelo do carro");
            cin >> txt;
            pe.setCarro(txt);
            puts("insira a placa do carro");
            cin >> txt;
            pe.setPlaca(txt);
        }
        puts("adulto?\n Y - sim // N - não");
        cin >> txt;
        if (txt == "y") {
            pe.setAdulto(true);
        }
        senha+=1;
        p.enfileira(pe);
    }

    void disponibilidade(){
        Pessoa temp;
        p.desinfileira(&temp);
        cout<<temp.getNome() <<"\n"<< temp.getEmail()<<"\n"
        <<senha<<endl;
    }


private:
    int senha;
    Fila<Pessoa> p;
};


#endif //HOTEL_RECEPCAO_HPP
