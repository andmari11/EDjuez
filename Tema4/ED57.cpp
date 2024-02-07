#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include "hashmap_eda.h"

using namespace std;


bool resuelveCaso(){

    int n;
    cin>>n;
    
    if(n==0){

        return false;
    }

    //cada numero y su lista de jugadores q tienen ese numero en el carton
    map < int, set<string>> numeros;
    //cada jugador y cuantos numeros tiene en su carton
    hashmap_eda_h::unordered_map <string, int> jugadores;


    for(int i=0;i<n;i++){

        string nombre;
        cin>>nombre;

        int j=0;
        int aux;

        while(cin>>aux, aux!=0){

            j++;

            //cada numero tiene una lista de los jugadores q tienen ese numero
            numeros[aux].insert(nombre);
        }
        //guarda el nombre del jugador y cuantos numeros tiene su carton
        jugadores[nombre]=j;
    }

    //ignoramos el salto de linea
    char a;
    cin.get(a);

    string line;
    getline(cin, line);
    stringstream ss(line);

    set <string> ganadores;

    int aux;

    while(ss>>aux){

        //si tiene ese numero
        if(numeros.count(aux)){

            //resta un numero tachado a cada jugador que tenga ese numero
            for(auto& p: numeros[aux]){

                //si el jugador tiene 0 se le añade a la lista  de gaandores
                if(--jugadores[p]==0){

                    ganadores.insert(p);
                }
            }
        }
    }

    for (const auto& ganador : ganadores) {
        std::cout << ganador << " ";
    }
    std::cout << std::endl;




    return true;
}



int main(){

    while(resuelveCaso());
}