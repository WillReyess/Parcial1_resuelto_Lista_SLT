#ifndef CLIENTE_H
#define CLIENTE_H

#include "Objeto.h"
#include <string>

using namespace std;

class Cliente: public Objeto //herencia de la interfaz objeto
{
    public:
        Cliente();
        virtual ~Cliente();
        Cliente(int, string, string);
        int getIdCliente();
        void SetNombre(string);
        string getNombre();
        void setApellidos(string);
        string getApellidos();
        ///implementacion del metodo virtual puro de objeto
        int getTipoObjeto();

    protected:

    private:
        int idCliente;
        string nombres;
        string apellidos;
};

#endif // CLIENTE_H
