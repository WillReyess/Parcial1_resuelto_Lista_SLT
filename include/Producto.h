#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "Medida.h"
#include "Objeto.h"

class Producto: public Objeto //herencia de la interfaz objeto
{
    public:
        Producto();
        virtual ~Producto();
        Producto(int, string, Medida, float);
        void setIdProducto(int);
        int getIdProducto();
        void setDescripcion(string);
        string getDescripcion();
        void setPrecioUnitario(float);
        float getPrecioUnitario();
        float getExistencia();
        void setExistencia(float);
        void setUnidadMedida(Medida);
        Medida getUnidadMedida();
        ///implementacion del metodo virtual puro de objeto
        int getTipoObjeto();

    protected:

    private:
        int idProducto;
        string descripcion;
        float PrecioUnitario;
        Medida unidadMedida;
        float existencia;
};

#endif // PRODUCTO_H
