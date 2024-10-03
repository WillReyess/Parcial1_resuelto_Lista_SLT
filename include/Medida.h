#ifndef MEDIDA_H
#define MEDIDA_H

#include <string>

using namespace std;

class Medida
{
    public:
        Medida();
        virtual ~Medida();
        Medida(int, string);
        void setIdMedida(int);
        int getIdMedida();
        void setUnidadMed(string);
        string getUnidadMed();


    protected:

    private:
        int idMedida;
        string UnidadMed;
};
#endif // MEDIDA_H
