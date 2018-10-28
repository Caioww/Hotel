#ifndef NO_HPP
#define NO_HPP

#include <iostream>
using namespace std;

class LDE;

class No{
public:
    struct funcionario{
        string nome;
        int nivel;
        string cargo;
        string senha;
    };
    typedef struct funcionario funcionario;
    No* proximo;
    funcionario escravo;

    No(): proximo(nullptr), escravo(escravo){

    }

    ~No(){
        cout << "deletando no" << endl;
    }

};


#endif