
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
		
		 void setQntd(int txt){
	        qntd = txt;
	    }
	    int getQntd(){
	        return qntd;
	    }
		
		 void setPreco(string txt){
	        preco = txt;
	    }
	    string getPreco(){
	        return preco;
	    } 
		
		 void setTotal(string txt){
	        total = txt;
	    }
	    string getTotal(){
	        return total;
	    }    
	   
   
	private:
        string item;
        string descricao;
        int qntd;
        string preco;
        string total;
        
        
};




