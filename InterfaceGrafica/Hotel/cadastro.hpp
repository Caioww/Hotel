#include <iostream>

using namespace std;

class cadastro{
	
public:
    cadastro(){
			
    }
		
    void setNome(string txt){
		nome = txt;
	}
	
    string getNome(){
		return nome;
	}
	
    void setTipo(string txt){
		tipo = txt;
	}
	
    string getTipo(){
		return tipo;
	}
	
    void setSenha(string txt){
		senha = txt;
	}
	
    string getSenha(){
		return senha;
	}
	
    void setNivel(int txt){
		nivel = txt;
	}
	
    int getNivel(){
		return nivel;
	}	
	
	
private:
    string nome;
    string tipo;
    string senha;
    int nivel;
};
