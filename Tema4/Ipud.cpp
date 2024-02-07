#include <iostream>
#include <string>
#include <unordered_map>
#include <list>


using namespace std;

using song=string;
using artista=string;
using duracion=int;



class Ipud{

    struct Cancion{
        artista a;
        duracion d;
        list<song>::iterator enPlaylist;
        list<song>::iterator reciente;
    };

    unordered_map <song, Cancion> listaIpud;
    list<song> playlist;
    list<song> recientes;
    duracion plduracion=0;

public:

    void addSong(const song &s, const artista &a, const duracion &d){

        if(listaIpud.count(s)){

            throw domain_error("error");
        }
        Cancion c={a, d, playlist.end(), recientes.end()};
        listaIpud[s]=c;
    }

    void addtoplaylist(const song &s){

        if(!listaIpud.count(s)){

            throw domain_error("error");
        }

        if(listaIpud.at(s).enPlaylist!=playlist.end()){

            return;
        }

        listaIpud[s].enPlaylist=playlist.insert(playlist.end(), s);
        plduracion+=listaIpud.at(s).d;
    }

    song play(){
        string ret;
        if(!playlist.empty()){

            listaIpud.at(playlist.front()).enPlaylist= playlist.end();
            listaIpud[playlist.front()].reciente=recientes.insert(recientes.end(), playlist.front());
            ret=playlist.front();
            playlist.pop_front();
            plduracion-=listaIpud[ret].d;

        }
        return ret;
    }

    song current(){
        if(playlist.empty()){

            throw domain_error("error");
        }
        return playlist.front();
    } 
    duracion totalTime()const {

        return plduracion;
    }

    list<song> recent(const int& n) const {
        list<song> ret;
        int tamanyoRecientes=recientes.size();

        auto it=recientes.begin();
        for(int i=0; i<min(n,tamanyoRecientes );i++, it++){
            string aux=*it;
            ret.push_back(aux);
        }

        return ret;
    }

    void deleteSong(const song& s){
        if(listaIpud.at(s).reciente!=recientes.end())
            recientes.erase(listaIpud.at(s).reciente);
        if(listaIpud.at(s).enPlaylist != playlist.end())
        playlist.erase(listaIpud.at(s).enPlaylist);
        listaIpud.erase(s);
    }


};

bool resuelveCaso() {
    // leer los datos de la entrada
    std::string acc,aux, aux2;
    int nAux;
    std::cin >> acc;
    if (! std::cin)
        return false;
    Ipud reproductor;
    while (acc != "FIN") {
        try {
            if (acc == "addSong") {
                std::cin >> aux >>aux2>>nAux;
                reproductor.addSong(aux,aux2,nAux);
            }
            if (acc == "addToPlaylist") {
                std::cin >> aux;
                reproductor.addtoplaylist(aux);
            }
            if (acc == "current") {
               
                 reproductor.current();
            }
            if (acc == "play") {
               
                cout<<"Sonando " << reproductor.play()<<"\n";
            }
            if (acc == "totalTime") {
               cout<<"Tiempo total "<<reproductor.totalTime()<<"\n";
            }
            if (acc == "recent") {
            std:cin >> nAux;
               
               for(string s:reproductor.recent(nAux)){

                    cout<<s<<"\n";
               }
            }
            if(acc== "deleteSong"){
                std::cin >> aux;
                reproductor.deleteSong(aux);
			}
        }
        catch (std::domain_error e) {
            std::cout << e.what()<<'\n';
        }
        std::cin.ignore();
        std::cin >> acc;
    }
    std::cout << "---\n";
    // escribir sol
    
    
    return true;
    
}

int main(){


    while(resuelveCaso());
}