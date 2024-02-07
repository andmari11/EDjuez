#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Carnet
{

    unordered_map<string, int> conductores;
    vector<int> Vpuntos;

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
        Vpuntos[15]++;
    }

    void quitar(string dni, int puntos)
    {

        if (!conductores.count(dni))
        {

            throw domain_error("Conductor inexistente");
        }
        Vpuntos[conductores.at(dni)]--;

        conductores[dni] = max(0, conductores.at(dni) - puntos);

        Vpuntos[conductores.at(dni)]++;
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

        return Vpuntos.at(puntos);
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
            else /*(operacion == "cuantos_con_puntos")*/
            {
                cin >> puntos;
                int num_conductores = c.cuantos_con_puntos(puntos);
                cout << "Con " << puntos << " puntos hay " << num_conductores
                     << endl;
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

    while (resuelveCaso())
        ;
}