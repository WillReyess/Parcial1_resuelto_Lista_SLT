#include "Cliente.h"

Cliente::Cliente()
{
    this->idCliente = 0;
}

Cliente::~Cliente()
{
    //dtor
}
Cliente::Cliente(int idCli, string nom, string apell){
    this->idCliente = idCli;
    this->nombres = nom;
    this->apellidos = apell;
}
int Cliente::getIdCliente(){
    return this->idCliente;
}
void Cliente::SetNombre(string nom){
    this->nombres = nom;
}
string Cliente::getNombre(){
    return this->nombres;
}
void Cliente::setApellidos(string apell){
    this->apellidos = apell;
}
string Cliente::getApellidos(){
    return this->apellidos;
}
int Cliente::getTipoObjeto(){
    return 1;
}
