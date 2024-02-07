#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <list>

using namespace std;

class Autoescuela
{

    unordered_map<string, set<string>> listaProfesores;
    unordered_map<string, pair<int, string>> listAlumnos;

public:
    Autoescuela() {}

    void alta(string alumno, string profesor)
    {

        if (!listAlumnos.count(alumno))
        {

            // se añade a la lista de alummnos
            listAlumnos.insert({alumno, {0, profesor}});
        }
        else
        {

            // se modifica la lista de alumnos
            listAlumnos[alumno] = {listAlumnos.at(alumno).first, profesor};
            // se borra del profesor previo

            if(listaProfesores.count(profesor))
                listaProfesores.at(profesor).erase(alumno);
        }

        // se actualiza la lista del profesor nuevo
        listaProfesores[profesor].insert(alumno);
    }

    bool es_alumno(string alumno, string profesor) const
    {

        return listAlumnos.at(alumno).second == profesor;
    }

    int puntuacion(string alumno) const
    {

        if (!listAlumnos.count(alumno))
        {

            throw domain_error("El alumno A no  esta matriculado");
        }
        return listAlumnos.at(alumno).first;
    }

    void actualizar(string alumno, int n)
    {

        if (!listAlumnos.count(alumno))
        {

            throw domain_error("El alumno A no  esta matriculado");
        }

        listAlumnos[alumno].first += n;
    }

    list<string> examen(string profesor, int n)
    {

        pair<string, int> aux;
        list<string> listaRet;

        if(!listaProfesores.count(profesor) or listaProfesores.at(profesor).empty()){

            return listaRet;
        }

        for (string alumno : listaProfesores.at(profesor))
        {

            if (listAlumnos.at(alumno).first >= n)
            {

                listaRet.push_back(alumno);
            }
        }
        return listaRet;
    }

    void aprobar(string alumno)
    {

        if (!listAlumnos.count(alumno))
        {

            throw domain_error("El alumno A no  esta matriculado");
        }

        listaProfesores.at(listAlumnos.at(alumno).second).erase(alumno);
        listAlumnos.erase(alumno);
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

    Autoescuela autoescuela;

    while (instruccion != "FIN")
    {

        string a, p;
        int n;
        try
        {
            if (instruccion == "alta")
            {
                cin >> a >> p;
                autoescuela.alta(a, p);
            }
            else if (instruccion == "es_alumno")
            {
                cin >> a >> p;
                bool es_alumno = autoescuela.es_alumno(a, p);
                if (es_alumno)
                    cout << a << " es alumno de " << p << endl;
                else
                    cout << a << " no es alumno de " << p << endl;
            }
            else if (instruccion == "puntuacion")
            {
                cin >> a;
                int puntuacion = autoescuela.puntuacion(a);
                cout << "Puntuacion de " << a << ": " << puntuacion << endl;
            }
            else if (instruccion == "actualizar")
            {
                cin >> a >> n;
                autoescuela.actualizar(a, n);
            }
            else if (instruccion == "examen")
            {
                cin >> p >> n;
                list<string> l = autoescuela.examen(p, n);
                cout << "Alumnos de " << p << " a examen:" << endl;
                for (auto it : l)
                    cout << it << endl;
            }
            else
            {
                cin >> a;
                autoescuela.aprobar(a);
            }
        }

        catch (exception &e)
        {
            cout << "ERROR" << endl;
        }
        cin >> instruccion;
    }

    cout << "---" << endl;

    return true;
}



int main(){

    while(resuelveCaso());
}