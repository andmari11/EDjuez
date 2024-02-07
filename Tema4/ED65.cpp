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

        int compromisarios;

    };

    unordered_map <estados, infoEstado> registroEstados;

};