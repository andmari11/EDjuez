#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <map>
#include <set>

using namespace std;
using partidos=string;
using estados=string;
using votos=int;




class Elecciones{

    struct infoEstado{
        int numCompromisarios;
        unordered_map<partidos,votos> partido; 
        //pair <map <string, int> ::iterator, votos> ganador;
        pair <set<pair<partidos, int>>::iterator, votos> ganador;

    };
    set<pair<partidos, int>>ganadores;

    unordered_map <estados, infoEstado> registroEstados;

public:

    void nuevo_estado(const string &nombre, int num_compromisarios){

        if(registroEstados.count(nombre)){

            throw domain_error("Estado ya existente");
        }
        infoEstado info;
        info.numCompromisarios=num_compromisarios;
        info.ganador={ganadores.end(), 0};
        registroEstados[nombre]=info;
    }

    void sumar_votos(const string &estado, const string &partido, int num_votos){

        if(!registroEstados.count(estado)){

            throw domain_error("Estado no encontrado");
        }

        registroEstados[estado].partido[partido]+=num_votos;

         pair <set<pair<partidos, int>>::iterator, votos> ganador=registroEstados[estado].ganador;
        int puntuacion=registroEstados[estado].partido[partido];
        
        if(puntuacion>ganador.second){

            if(ganador.first!=ganadores.end()){

                ganadores.erase(ganador.first);
            }
            auto it=ganadores.insert(ganadores.end(), {partido, registroEstados.at(estado).numCompromisarios});
            registroEstados[estado].ganador={it,puntuacion};
        }

        else if(puntuacion==ganador.second){

            registroEstados[estado].ganador={ganadores.end(), puntuacion};
        }
        
    }

    string ganador_en(const string &estado) const{

        if(!registroEstados.count(estado)){

            throw domain_error("Estado no encontrado");
        }

        return (*registroEstados.at(estado).ganador.first).first;
    }

    vector<pair<string,int>> resultados() const{
        vector<pair<string,int>> ret;
        for(auto it:ganadores){

            pair<string, int> aux=it;

            if(!ret.empty() and ret.front().first==aux.first){

                ret.front().second+=aux.second;
            }
            else{

                ret.push_back({aux.first, aux.second});
            }
        }   

        return ret;
    }
};



bool resuelveCaso(){

    string instruccion;
    cin>>instruccion;

    if(!cin){

        return false;
    }

    Elecciones e;
    estados estado;
    partidos partido;
    int num;

    while(instruccion!="FIN"){
        try{
        if(instruccion=="nuevo_estado"){
            cin>>estado>>num;
            e.nuevo_estado(estado, num);
        }
        else if(instruccion=="sumar_votos"){
            cin>>estado>>partido>>num;
            e.sumar_votos(estado, partido, num);
        }
        else if(instruccion=="ganador_en"){

            cin>>estado;
            string aux=e.ganador_en(estado);
            cout << "Ganador en "<< estado<<": " <<aux<<endl;
        }
        else{

            for(pair<string, int> aux: e.resultados()){

                cout<<aux.first<<" "<<aux.second<<"\n";
            }
        }}
        catch(domain_error e){

            cout<<e.what()<<"\n";
        }
        cin>>instruccion;
    }

    cout<<"---\n";


    return true;
}


int main(){

        while(resuelveCaso());
}