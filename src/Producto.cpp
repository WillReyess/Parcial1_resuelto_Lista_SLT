#include "Producto.h"

Producto::Producto()
{
    this->idProducto = 0;
    this->PrecioUnitario = 0;
    this->existencia = 0;
}
Producto::~Producto()
{
    //dtor
}
Producto::Producto(int id, string descrip, Medida med, float exist){
    this->idProducto = id;
    this->descripcion = descrip;
    this->unidadMedida = med;
    this->existencia = exist;
}
void Producto::setIdProducto(int id){
    this->idProducto = id;
}
int Producto::getIdProducto(){
    return this->idProducto;
}
void Producto::setDescripcion(string descrip){
    this->descripcion = descrip;
}
string Producto::getDescripcion(){
    return this->descripcion;
}
void Producto::setPrecioUnitario(float preUnit){
    this->PrecioUnitario = preUnit;
}
float Producto::getPrecioUnitario(){
    return this->PrecioUnitario;
}
float Producto::getExistencia(){
    return this->existencia;
}
void Producto::setExistencia(float exist){
    this->existencia = exist;
}
void Producto::setUnidadMedida(Medida med){
    this->unidadMedida = med;
}
Medida Producto::getUnidadMedida(){
    return this->unidadMedida;
}
int Producto::getTipoObjeto(){
    return 2;
}
