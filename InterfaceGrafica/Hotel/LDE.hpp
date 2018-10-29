#ifndef LDDE_H
#define LDDE_H
#include <iostream>
#include <string>


using namespace  std;

class No {
private:
public:
    typedef struct {
        string nome,
	string idade,
	string sexo,
	string rg,
	string data,
	string email,
	string cidade,
	string estado,
	string telefone,
	string celular,
	
 	

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
    No* primeiro;
    int total = 0;

public:
    LDE(): primeiro(nullptr), total(0){
    }

    bool insere( string nome, string idade, string sexo, string rg, string data, string email, string cidade, string estado, string telefone, string celular) {
        No *atual = primeiro;
        No *anterior = NULL;

        cout << "Estou aqui" << endl;

        cout << "Agora aqui" << endl;


        cout << "Cheguei aqui" << endl;

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

        cout << "Endereço do primeiro: " << primeiro << endl;

        cout << "Endereço do atual: " << atual << endl;

        cout << "Endereço do anterior: " << anterior << endl;

        cout << "\n" << endl;

        QFile file("C:\\Users\\Caio\\Documents\\testeRemover.txt");
             if(!file.open(QIODevice::Append|QIODevice::Text))
                return;
             QTextStream out(&file);
                out<<
                     nome<<"-"<<
                     idade<<"-"<<
                     sexo<<"-"<<
                     rg<<"-"<<
                     data<<"-"<<
                     estado<<"-"<<
                     cidade<<"-"<<
                     estado<<"-"<<
                    telefone<<"-"<<
                     celular<<"\n";
        }

        return true;
      }

    void imprime() {
       No *atual = primeiro;
       while (atual) {
         cout << atual->c.nome << endl;
         atual = atual->prox;
        }
    }
};

#endif // LDDE_H
