#include <vector>
#include <stdexcept>
#include <iostream>


#include "horas.h"

using namespace std;


#ifndef PELICULA
#define PELICULA




class pelicula{

private:
    
    
    string name;

    tHora hora;
    tHora duracion;
    tHora fin;

public:
    pelicula(){

    }

    tHora getFin () const{ return fin;}
    string getName () const{ return name;}
    
    bool operator<(pelicula const& other) const {
        bool ret;

        if(this->fin==other.fin){

            ret=this->getName()<other.getName();
        }
        else{

            ret=this->fin<other.fin;
        }
        return ret;
    }

    bool operator==(pelicula const& other) const {

        return this->fin==other.fin;
    }

    pelicula(tHora hora, tHora duracion, string name){

        this->name=name;
        this->duracion=duracion;
        this->hora=hora;
        this->fin=this->hora+this->duracion;

    }



};

#endif