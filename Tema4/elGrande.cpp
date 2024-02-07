#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stdexcept>
#include <set>

using namespace std;


using region=string;
using jugador=string;
using soldados=int;
using puntuacion=int;


struct Compare{
    bool operator()(int a , int b) const{

        return a>b;
    }
};

class ElGrande{

    struct infoRegion{

        pair <jugador, soldados> predominante={"", 0};
        unordered_map<jugador, soldados> info;
    };
    unordered_map<region, infoRegion> listaRegiones;

    unordered_map<jugador, puntuacion> listaJugadoresPuntuacion;


public:

    void anyadir_jugador(const jugador& j){

        if(listaJugadoresPuntuacion.count(j)){

            throw domain_error("Jugador existente");
        }
        listaJugadoresPuntuacion[j]=0;
    }

    void colocar_caballero(const jugador& j, const region& r){

        //nos aseguramos q este registrado el jugador
        if(!listaJugadoresPuntuacion.count(j)){

            throw domain_error("Jugador no existente");
        }
        //la region no existe
        if(!listaRegiones.count(r) ){

            infoRegion infoR;

            listaRegiones[r]=infoR;
        }
        //el jugador no existe en esa region
        if(!listaRegiones.at(r).info.count(j)){

            listaRegiones[r].info[j]=1;
        }
        //el jugador si existe en esa region
        else{

            listaRegiones[r].info[j]++;
        }

        pair <string, int> predominante=listaRegiones.at(r).predominante;

        if(predominante.first==""){

            listaRegiones.at(r).predominante={j, listaRegiones[r].info[j]};
            listaJugadoresPuntuacion[j]++;
        }
        else if(listaRegiones.at(r).predominante.second==listaRegiones.at(r).info.at(j)){

            listaRegiones.at(r).predominante={"disputa", predominante.second};
            listaJugadoresPuntuacion[predominante.first]--;


        }
        else if(listaRegiones.at(r).predominante.second<listaRegiones.at(r).info.at(j)){

            listaRegiones.at(r).predominante={j, listaRegiones[r].info[j]};
            listaJugadoresPuntuacion[j]++;
            if(predominante.first!="disputa")
                listaJugadoresPuntuacion[predominante.first]--;

        }

    }

    puntuacion puntuacionPuntos(const jugador& j)const{

        if(!listaJugadoresPuntuacion.count(j)){

            throw domain_error("Jugador no existente");
        }

        return listaJugadoresPuntuacion.at(j);
    }

    vector<string> regiones_en_disputa()const{

        vector<string> ret ;
        for( auto it: listaRegiones){
            if(it.second.predominante.first=="disputa")
                ret.emplace_back(it.first);
        }

        return ret;
    }

    void expulsar_caballeros(const region& r){

        if(!listaRegiones.count(r) ){

            throw domain_error("Región Vacía");

        }
        listaJugadoresPuntuacion[listaRegiones[r].predominante.first]--;
        listaRegiones.erase(r);
    }

};

using namespace std;


using region = string;
using caballero = int;
using jugador = string;

bool resuelve() {
    string operacion;
    cin >> operacion;
    if (!cin)
        return false;
    caballero cab; region reg; jugador jug;
    ElGrande grande;
    while (operacion != "FIN") {
        try {
            if (operacion == "anyadir_jugador") {
                cin >> jug;
                grande.anyadir_jugador(jug);
            }
            else if (operacion == "colocar_caballero") {
                cin >> jug >> reg;
                grande.colocar_caballero(jug, reg);
            }
            else if (operacion == "puntuacion") {
                int punt;
                cin >> jug;
                punt = grande.puntuacionPuntos(jug);
                cout << "Puntuacion de " << jug << ": " << punt << "\n";
            }
            else if (operacion == "regiones_en_disputa") {
                vector<region> v;
                v = grande.regiones_en_disputa();
                cout << "Regiones en disputa:\n";
                for (int i = 0; i < v.size(); i++) 
                {
                    cout << v[i] << "\n";
                }
            }
            else if (operacion == "expulsar_caballeros") {
                cin >> reg;
                grande.expulsar_caballeros(reg);
            }
 
        }
        catch (domain_error e) {
            cout << "ERROR " << e.what() << '\n';
        }
        cin >> operacion;
    }
    cout << "---\n";
    return true;
}


int main(){

    while(resuelve());
}
