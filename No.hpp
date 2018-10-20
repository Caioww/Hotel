#ifndef NO_HPP
#define NO_HPP

#include <iostream>
using namespace std;

class LDE;

class No{
public:
    No* proximo;
    string nome;
    int nivel;
    string cargo;
    string senha;
    No(string senha,string cargo,string nome,int nivel): proximo(nullptr){

    }

    No() {

    }

    ~No(){
        cout << "deletando no" << endl;
    }

};


#endif