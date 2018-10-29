#ifndef NO_H
#define NO_H

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class No{
private:
public:
  typedef struct Cliente{
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

  No(string nome,string idade,string sexo,string rg,string data,string email,string cidade,string estado,string telefone,string celular) {
    this->c.nome = nome;
    this->c.idade = idade;
    this->c.sexo = sexo;
    this->c.rg = rg;
    this->c.data = data;	
    this->c.email = email;
    this->c.cidade = cidade;
    this->c.estado = estado;
    this->c.telefone= telefone;
    this->c.celular= celular;
    this->prox = NULL;
  }
};

#endif // NO_H