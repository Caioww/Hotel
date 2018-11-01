#ifndef LDDE_H
#define LDDE_H
#include <iostream>
#include <string>
#include "menupainel.h"

using namespace std;

class No {
private:
public:
  typedef struct{
        string nome;
        string idade;
        string sexo;
        string rg;
        string data;
        string email;
        string cidade;
        string estado;
        string telefone;
        string celular;
  }Cliente;

  Cliente c;

  No *prox;

  No(string nome, string idade, string sexo, string rg, string data, string email, string cidade, string estado, string telefone, string celular) {
      this->c.nome = nome;
      this->c.idade = idade;
      this->c.sexo = sexo;
      this->c.rg = rg;
      this->c.data=data;
      this->c.email = email;
      this->c.cidade = cidade;
      this->c.estado = estado;
      this->c.telefone= telefone;
      this->c.celular= celular;
      this->prox = NULL;
  }
};

class LDE {
private:

    int total = 0;

public:
    No* primeiro;


    LDE(): primeiro(nullptr), total(0){
    }

    bool insere(string nome, string idade, string sexo, string rg, string data, string email, string cidade, string estado, string telefone, string celular) {
        No *atual = primeiro;
        No *anterior = NULL;

        No *novo = new No(nome, idade, sexo, rg, data, email, cidade, estado, telefone, celular);

        if (!novo)
          return false;

        while (atual) {
          anterior = atual;
          atual = atual->prox;
        }

        if (anterior)
          anterior->prox = novo;
        else
          primeiro = novo;

        novo->prox = atual;



        return true;
      }

    void salvaClientes(){
        No *atual = primeiro;
        while(atual->prox ){


            atual = atual->prox;
        }

        QFile file("C:\\Users\\Caio\\Documents\\testeRemover.txt");
        if((file.open(QIODevice::Append | QIODevice::Text))){
            QTextStream in(&file);
            in<<
            QString::fromStdString(atual->c.nome)<<"-"<<
            QString::fromStdString(atual->c.idade)<<"-"<<
            QString::fromStdString(atual->c.sexo)<<"-"<<
            QString::fromStdString(atual->c.rg)<<"-"<<
            QString::fromStdString(atual->c.data)<<"-"<<
            QString::fromStdString(atual->c.estado)<<"-"<<
            QString::fromStdString(atual->c.cidade)<<"-"<<
            QString::fromStdString(atual->c.telefone)<<"-"<<
            QString::fromStdString(atual->c.celular)<<"-"<<
            QString::fromStdString(atual->c.email)<<"\n";
        }

    }

    void imprime() {
       No *atual = primeiro;
       while (atual) {
         cout << atual->c.nome << endl;
         cout << atual->c.telefone << endl;
         atual = atual->prox;
        }
    }

    void carregaLDE(){
        QFile file("C:\\Users\\Caio\\Documents\\testeRemover.txt");
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
                QTextStream stream(&file);
                while (!stream.atEnd()){
                    QString nome = stream.readLine();
                    QString idade = stream.readLine();
                    QString sexo = stream.readLine();
                    QString rg = stream.readLine();
                    QString data = stream.readLine();
                    QString estado = stream.readLine();
                    QString cidade = stream.readLine();
                    QString telefone = stream.readLine();
                    QString celular = stream.readLine();
                    QString email = stream.readLine();
                    insere(nome.toStdString(), idade.toStdString(), sexo.toStdString(), rg.toStdString(), data.toStdString(), email.toStdString(), cidade.toStdString(), estado.toStdString(), telefone.toStdString(), celular.toStdString());
                }
            }
          file.close();
       }
};


#endif // LDDE_H
