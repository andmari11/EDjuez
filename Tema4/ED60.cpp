#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <list>


using namespace std;

class Carnet
{

    unordered_map<string, int> conductores;
    vector<set< pair<int,string >>> Vpuntos;
    int casos=0;
public:
    Carnet()
    {
        Vpuntos.resize(16);
    }

    void nuevo(string dni)
    {

        if (conductores.count(dni))
        {

            throw domain_error("Conductor duplicado");
        }

        conductores[dni] = 15;
        Vpuntos[15].insert({casos, dni});
    }

 

    int consultar(string dni) const
    {

        if (!conductores.count(dni))
        {

            throw domain_error("Conductor inexistente");
        }

        return conductores.at(dni);
    }

    int cuantos_con_puntos(int puntos) const
    {
        if (puntos > 15 || puntos < 0)
            throw domain_error("Puntos no validos");

        return Vpuntos[puntos].size();
    }

    list <string> lista_por_puntos(int puntos){

        list<string> ret;

        if (puntos > 15 || puntos < 0)
            throw domain_error("Puntos no validos");

        for(auto it:Vpuntos.at(puntos)){

            ret.push_front(it.second);
        }

        return ret;
    }

    void quitar(string dni, int puntos)
    {

        if (!conductores.count(dni))
        {

            throw domain_error("Conductor inexistente");
        }
        auto borrar=Vpuntos[conductores.at(dni)].find({conductores.at(dni),dni });
       // Vpuntos[conductores.at(dni)].erase(borrar);

        conductores[dni] = max(0, conductores.at(dni) - puntos);
        Vpuntos[conductores.at(dni)].insert({casos, dni});

        casos++;
    }

    void recuperar(string dni, int puntos){
        if (!conductores.count(dni))
        {

            throw domain_error("Conductor inexistente");
        }

        auto borrar=Vpuntos[conductores.at(dni)].find({conductores.at(dni),dni });
        //Vpuntos[conductores.at(dni)].erase(borrar);

        conductores[dni] = max(0, conductores.at(dni) + puntos);
        Vpuntos[conductores.at(dni)].insert({casos, dni});
    }
};

bool resuelveCaso()
{

    string instruccion;
    cin >> instruccion;

    if (!cin)
    {
        return false;
    }

    Carnet c;

    while (instruccion != "FIN")
    {

        try
        {
            string dni;
            int puntos;
            if (instruccion == "nuevo")
            {
                cin >> dni;
                c.nuevo(dni);
            }
            else if (instruccion == "quitar")
            {
                cin >> dni >> puntos;
                c.quitar(dni, puntos);
            }
            else if (instruccion == "consultar")
            {
                cin >> dni;
                int num_puntos = c.consultar(dni);
                cout << "Puntos de " << dni << ": " << num_puntos << endl;
            }
            else if (instruccion == "cuantos_con_puntos")
            {
                cin >> puntos;
                int num_conductores = c.cuantos_con_puntos(puntos);
                cout << "Con " << puntos << " puntos hay " << num_conductores
                     << endl;
            }
            else if(instruccion=="lista_por_puntos"){
                cin >> puntos;
                list <string> l= c.lista_por_puntos(puntos);
                if(l.empty())
                    break;
                cout<<"Tienen "<< puntos<< " puntos: ";
                for(string s:l){

                    cout<<s<<" ";
                }
                cout<<endl;
            }
        }
        catch (exception &e)
        {
            cout << "ERROR: " << e.what() << endl;
        }

        cin >> instruccion;
    }
    cout << "---" << endl;
    return true;
}

int main()
{

    while (resuelveCaso());
}