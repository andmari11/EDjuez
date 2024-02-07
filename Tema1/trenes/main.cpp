#include <algorithm>
#include <iostream>
#include "horas.h"


using namespace std;


bool resuelveCaso(){

    int numTrenes, numHoras;

    cin>>numTrenes>>numHoras;

    if(numTrenes+numHoras==0){

        return false;
    }

    vector <Hora> lista(numTrenes);

    for(int i=0; i<lista.size();i++){

        cin>>lista[i];
    }

    for(int i=0;i<numHoras;i++){

        Hora aux;

        try{

            cin>>aux;

            auto lower=lower_bound(lista.begin(), lista.end(), aux);

            if(lower==lista.end()){

                cout<<"NO\n";
            }
            else{

                cout<<*lower<<"\n";
            }

        }
        catch (domain_error & e) {
            cout << e.what();
        }


    }

    cout << "---\n";
    return true;
}



int main(){

    while(resuelveCaso());
}