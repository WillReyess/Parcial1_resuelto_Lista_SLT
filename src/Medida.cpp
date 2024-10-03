#include "Medida.h"

Medida::Medida()
{
    this->idMedida = 0;
}

Medida::~Medida()
{
    //dtor
}
Medida::Medida(int idMed, string unidMed){
    this->idMedida = idMed;
    this->UnidadMed = unidMed;
}
void Medida::setIdMedida(int idMed){
    this->idMedida = idMed;
}
int Medida::getIdMedida(){
    return this->idMedida;
}
void Medida::setUnidadMed(string uniMed){
    this->UnidadMed = uniMed;
}
string Medida::getUnidadMed(){
    return this->UnidadMed;
}
