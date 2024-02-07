#include <iostream>
#include <string>
#include <sstream>

#include "bintree_eda.h"


using namespace std;

bintree<int> construir(const std::vector<int> &pre, const std::vector<int> &in,
std::pair<int, int> preorden, std::pair<int, int> inorden){
    
    if (preorden.first > preorden.second)
        return {};
    int raiz = pre[preorden.first];
    int pRaiz = inorden.first;
    while (in[pRaiz] != raiz)
    {
        ++pRaiz;
    }
    int izqTam = pRaiz - inorden.first;
    auto izq = construir(pre, in, {preorden.first + 1, preorden.first + izqTam}, {inorden.first, pRaiz - 1});
    auto dcha = construir(pre, in, {preorden.first + 1 + izqTam, preorden.second}, {pRaiz + 1, inorden.second});

    return {izq, raiz, dcha};
}

bool resuelveCaso(){

    string preorden;
    string inorden;
    int n;
    getline(cin, preorden);
    getline(cin, inorden);


    if(!cin){

        return false;
    }

    vector <int> pre;
    vector <int> ind;


    stringstream ssPre(preorden);
    while (ssPre >> n) pre.push_back(n);

    stringstream ssIn(inorden);
    while (ssIn >> n) ind.push_back(n);

    bintree<int> tree=construir(pre, ind, {0,pre.size()-1}, {0,pre.size()-1});
    vector<int> ret =tree.postorder();

    for(int i=0;i<ret.size();i++){

        cout<<ret[i]<<" ";
    }

    cout<<"\n";

    return true;    
}






int main() {

    while(resuelveCaso());
}