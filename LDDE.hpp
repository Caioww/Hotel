//
// Created by djalma cunha on 27/10/18.
//

#ifndef HOTEL_LDDE_HPP
#define HOTEL_LDDE_HPP

#include "Cola.hpp"
class LDDE {
private:
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
    Cola* primeiro;
    Cola* ultimo;
    int n;
public:
    LDDE(): primeiro(primeiro), ultimo(nullptr), n(0){

    }

    bool insere(string nome, int dia, int mes, int ano,int idade,
                string doc,string city,string estado,string tel, string cel,string email,bool sexo){
        Cola* novo = (Cola*)malloc(sizeof(Cola));
        novo->centavo.nome;
        novo->centavo.dia;
        novo->centavo.mes;
        novo->centavo.ano;
        novo->centavo.idade;
        novo->centavo.RG;
        novo->centavo.cidade;
        novo->centavo.estado;
        novo->centavo.telefone;
        novo->centavo.celular;
        novo->centavo.email;
        novo->centavo.sexo;
        if(!novo)
            return false;
        Cola *ATUAL = primeiro;
        Cola* ptrAnterior = nullptr;

        while(ATUAL){
            ptrAnterior = ATUAL;
            ATUAL = ATUAL->proximo;
        }
        novo->anterior = ptrAnterior;
        if(ptrAnterior){
            ptrAnterior -> proximo = novo;
        }
        else{
            primeiro = novo;
        }

        novo -> proximo = ATUAL;
        if(ATUAL){
            ATUAL->anterior = novo;
        }
        else{
            ultimo = novo;
        }

        n++;
        return true;

    }

    Cola* busca(string nome,string doc){
        Cola* temp = nullptr;
        Cola* atual = primeiro;
        while(atual){
            if(atual->centavo.nome != (nome+"\n")){
                cout<<"Nome: "<<atual->centavo.nome<<endl;
                cout<<"RG: "<<atual->centavo.RG<<endl;
                cout<<"Celular: "<<atual->centavo.celular<<endl;
                cout<<"Email: "<<atual->centavo.email<<endl;
                break;
            }
            temp = atual;
            atual = atual->proximo;
        }
        return temp;
    }

    void imprime(){
        Cola* atual = primeiro;
        while(atual){
            cout<<"Nome: "<<atual->centavo.nome<<endl;
            cout<<"RG: "<<atual->centavo.RG<<endl;
            cout<<"Celular: "<<atual->centavo.celular<<endl;
            cout<<"Telefone Fixo: "<<atual->centavo.telefone<<endl;
            cout<<"Email: "<<atual->centavo.email<<endl;
            cout<<"Cidade: "<<atual->centavo.cidade<<endl;
            cout<<"Estado: "<<atual->centavo.estado<<endl;
            cout<<"Nacimento: "<<atual->centavo.dia<<"/"<<atual->centavo.dia<<"/"<<atual->centavo.ano<<endl;
            cout<<"Idade: "<<atual->centavo.idade<<endl;
            cout<<"Sexo: "<<atual->centavo.sexo<<endl;
            cout<<"Email: "<<atual->centavo.email<<endl;
            atual = atual->proximo;
        }
        cout << endl;
    }

    void limpa(){
        Cola* ptr = primeiro;
        while(ptr){
            delete(ptr);
            ptr = ptr -> proximo;
        }
        delete(ptr);
    }

    bool remove(string nome,string doc){
        Cola* ATUAL = primeiro;
        nome = nome + "\n";
        doc = doc + "\n";
        while(ATUAL && ATUAL->centavo.nome != nome && ATUAL->centavo.RG != doc){
            ATUAL = ATUAL -> proximo;
        }

        if(!ATUAL || ATUAL->centavo.nome != nome){
            return false;
        }

        Cola* ptrAnterior = ATUAL->anterior;
        Cola* ptrProximo = ATUAL->proximo;

        if(ptrAnterior)
            ptrAnterior -> proximo = ptrProximo;
        else
            primeiro = ptrProximo;

        if(ptrProximo)
            ptrProximo -> anterior = ptrAnterior;
        else
            ultimo = ptrAnterior;

        delete ATUAL;
        n--;
        return true;

    }
};


#endif //HOTEL_LDDE_HPP
