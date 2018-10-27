//
// Created by djalma cunha on 27/10/18.
//

#ifndef HOTEL_LES_HPP
#define HOTEL_LES_HPP
#include <iostream>
#define MAX 100
using namespace std;
/*
 * pensa como se o vetor ja estivesse populado, pois se pensarmos como se ja tivesse
 * nos jogariamos um 'if'
 */
namespace gwl {
    class LES {
    private:
        int n;
        int po;
        int v[MAX];
    public:
        LES() : n(0) {
        }
        bool insere(int valor){
            if(n == MAX){
                return false;
            }
            int i;
            for (i = 0; i <n && v[i] < valor ; i++){

            }

            for (int j = n; j > i; j--) {
                v[j] = v[j-1];
            }
            v[i] = valor;
            n++;
            return true;
        }

        void imprime() const{
            for (int i = 0; i < n; ++i) {
                cout<<v[i] << " "<<endl;
            }
        }

        int busca(int valor){
            int i;
            for (i = 0; (i <n && v[i] != valor) ; i++){
            }

            if(v[i] != valor){
                po = -1;
            }
            else{
                po = i;
            }
            return po;
        }

        void remove(int valor){
            busca(valor);
            int i,auxpo,val,val2;
            if(po != -1) {
                auxpo = po;
                for (i = po; i < n; i++) {
                    v[i] = v[i+1];
                }
                n--;
            }
            else{
                cout << "não tem" <<endl;
            }
        }

    };

}

using namespace gwl;

ostream& operator<<(ostream& a, const LES& b){
    b.imprime();
    return cout;
}


#endif //HOTEL_LES_HPP
