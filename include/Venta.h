#ifndef VENTA_H
#define VENTA_H

#include "Objeto.h"
#include "Cliente.h"
#include "Producto.h"

//se agregala la libreria de la lista estandar
#include <list>

class Venta : public Objeto //herencia de la interfaz objeto
{
    public:
        Venta();
        virtual ~Venta();
        Venta(int, string, Cliente);
        void setNumeroFactura(int);
        int getNumeroFactura();
        void setFecha(string);
        string getFecha();
        void setCliente(Cliente);
        Cliente getCliente();
        ///se cambia el puntero lista a list<producto*>
        void setListaProducto(list<Producto*>);
        list<Producto*> getListaProductos();
        int getNumeroProductos();
        ///implementacion del metodo virtual puro de objeto
        int getTipoObjeto();

    protected:

    private:
        int noFactura;
        string fechaVenta;
        Cliente cliente;
        list<Producto*> productoVendidos;
};

#endif // VENTA_H
