#include <iostream>
//#include <unordered_map>
#include <vector>
//#include <map>
#include "hashmap_eda.h"


bool resuelveCaso(){

    int nNum,nPreg;

    std::cin>>nNum>>nPreg;

    if(!std::cin){

        return false; 
    }

    unordered_map <int, std::vector<int>> map;
    int aux;

    for(int i=1;i<=nNum;i++){

        std::cin>>aux;

        map.insert(aux);
        map[aux].push_back(i);
    }


    int k, v;
    bool encontrado;

    for(int i=0;i<nPreg;i++){

        std::cin>>k>>v;

        if(--k>=map[v].size()){

            std::cout <<"NO HAY\n";
        }
        else
            std::cout <<map[v].at(k)<<"\n";

    }
    std::cout<<"---\n";
    return true;
}



int main(){

    while(resuelveCaso());
}