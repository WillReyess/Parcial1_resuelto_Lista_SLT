#include "Venta.h"

Venta::Venta()
{
    this->noFactura = 0;
}

Venta::~Venta()
{
    //dtor
}
Venta::Venta(int noFact, string fechaVent, Cliente cli){
    this->noFactura = noFact;
    this->fechaVenta = fechaVent;
    this->cliente = cli;
}
void Venta::setNumeroFactura(int numFact){
    this->noFactura = numFact;
}
int Venta::getNumeroFactura(){
    return this->noFactura;
}
void Venta::setFecha(string fecha){
    this->fechaVenta = fecha;
}
string Venta::getFecha(){
    return this->fechaVenta;
}
void Venta::setCliente(Cliente cli){
    this->cliente = cli;
}
Cliente Venta::getCliente(){
    return this->cliente;
}
void Venta::setListaProducto(list<Producto*> lst){
    this->productoVendidos = lst;
}
list<Producto*> Venta::getListaProductos(){
    return this->productoVendidos;
}
int Venta::getNumeroProductos(){
    return productoVendidos.size();//se usa size para retornar el tamaño de la lista es decir, la cantidad de item
}
int Venta::getTipoObjeto(){///implementacion del metodo virtual puro de objeto
    return 3;
}
