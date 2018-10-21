
#include <iostream>
using namespace std;


/*
 * uma classe bem simples tipo pessoa para conseguirmos adminstrar as pessoas
 */
class Item {

public:

	Item(){

	}

	void setItem(string txt){
		item = txt;
	}
	string getItem(){
		return item;
	}

	void setDescricao(string txt){
		descricao = txt;
	}
	string getDescricao(){
		return descricao;
	}

	void setQntd(float txt){
		qntd = txt;
	}
	float getQntd(){
		return qntd;
	}

	void setPreco(float txt){
		preco = txt;
	}
	float getPreco(){
		return preco;
	}

	void setTotal(float txt,float xtx){
		total = (txt*xtx);
	}
	float getTotal(){
		return total;
	}


private:
	string item;
	string descricao;
	float qntd;
	float preco;
	float total;


};




