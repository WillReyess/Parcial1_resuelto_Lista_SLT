#include <iostream>
#include <list>
#include "Cliente.h"
#include "Producto.h"
#include "Venta.h"


using namespace std;
int menu(){
    int opc;

    cout <<"1. agregar clientes" <<endl;
    cout <<"2. agregar productos" <<endl;
    cout <<"3. hacer ventas" <<endl;
    cout <<"4. ver lista de clientes" <<endl;
    cout <<"5. ver lista de productos" <<endl;
    cout <<"6. ver lista de ventas" <<endl;
    cout <<"7. ver detalles de la venta" <<endl;
    cout <<"8. salir" <<endl;

    cout <<"Digite su opcion: ";
    cin >> opc;

    ///se retorna la opcion seleccionada
    return opc;
}

int main()
{
    ///se crea una lista de punteros a objeto
    list<Objeto*> lista;

    int opc;
    do{
        system("cls");
        opc = menu();
        switch(opc){
            case 1:
                ///Agregar clientes
                {
                    ///declaracion de variables
                    int id;
                    string nombre, apellido;

                    ///solicitud de datos
                    cout <<"Digite el id del cliente: ";
                    cin >> id;
                    cout <<"Digite el nombre del cliente: ";
                    cin >> nombre;
                    cout <<"Digite el apellido del cliente: ";
                    cin >> apellido;

                    ///se agrega a la lista
                    lista.push_back(new Cliente(id, nombre, apellido));

                    cout <<"El cliente se agrego con exito" <<endl;
                }
                break;
            case 2:
                ///Agregar productos
                {
                    ///declaracion de variables
                    int id;
                    string descripcion;
                    float existencia;

                    ///solicitud de datos
                    Medida um(1, "Unidad");

                    cout <<"Digite el Id del producto: ";
                    cin >> id;
                    cout <<"Digite la descripcion del producto: ";
                    cin >> descripcion;
                    cout <<"Digite la existencia del producto: ";
                    cin >> existencia;

                    ///se agrega a la lisa
                    lista.push_back(new Producto(id, descripcion, um, existencia));

                    cout <<"El producto fue agregado con exito" <<endl;
                }

                break;
            case 3:
                ///Agregar ventas
                {
                    ///declaracion de variables
                    int idCliente, idProducto, NumFactura;
                    string fechaVenta;
                    Venta *vent = NULL;
                    Cliente* cli = NULL;
                    Producto* prod = NULL;
                    int resp;

                    ///solicitud de datos
                    cout <<"Digite el id del cliente: ";
                    cin >> idCliente;

                    ///se busca el cliente
                    for(Objeto *obj : lista){/// Itera sobre cada elemento en la lista de objetos
                        cli = dynamic_cast<Cliente*>(obj);///Intenta convertir el puntero de tipo Objeto a un puntero de tipo Cliente
                        // Verifica si cliente no es nulo
                        // y si el ID del cliente coincide con el ID buscado
                        if(cli && cli->getIdCliente() == idCliente){
                                break;//cliente econtrado
                        }
                    }

                    if(cli){
                        ///se solicita la informacion de la factura
                        cout <<"Digite el numero de factura: ";
                        cin >> NumFactura;
                        cout <<"Digite la fecha de venta(dd//mm//aa): ";
                        cin >> fechaVenta;

                        ///se crea la venta con el cliente encontrado
                        vent = new Venta(NumFactura, fechaVenta, *cli);
                        vent->setNumeroFactura(NumFactura);

                        ///se crea una lista para los productos vendidos
                        list<Producto*>lstprodVendidos;

                        do{
                            ///se solicita el id del producto
                            cout <<"Digite el id del producto: ";
                            cin >> idProducto;

                            ///se busca el producto
                            for(Objeto *obj : lista){/// Itera sobre cada elemento en la lista de objetos
                                prod = dynamic_cast<Producto*>(obj);///Intenta convertir el puntero de tipo Objeto a un puntero de tipo Cliente
                                // Verifica si el producto no es nulo
                                // y si el ID del producto coincide con el ID buscado
                                if(prod && prod->getIdProducto() == idProducto){
                                        break; ///producto econtrado
                                }
                            }

                            if(prod){
                                lstprodVendidos.push_back(prod);///se agrega el producto a la lista de productos vendidos
                                cout <<"EL producto se agrego con exito" <<endl;
                            }
                            else{
                                cout <<"El producto no se encontro en la lista"  <<endl;
                            }
                            cout <<"¿Desea agregar otro producto SI = 1, NO = 2?: ";
                            cin >> resp;
                        }while(resp ==1);

                        ///se asigna la lista de productos vendidos a la lista
                        vent->setListaProducto(lstprodVendidos);

                        ///se agrega la venta a la lista de objetos
                        lista.push_back(vent);
                    }
                    else{
                        cout <<"El cliente no fue encontrado" <<endl;
                    }
                }
                break;
            case 4:
                ///Lista de clientes
                {
                    if(lista.empty()){///se verifica si la lista esta vacia
                        cout <<"La lista de estudiantes esta vacia" <<endl;
                    }
                    else{
                        ///si no esta vacia, se crea un iterador para recorrerla
                        list<Objeto*>::iterator pos = lista.begin();

                        ///se recorre la lista mientras el iterador no llegue al final
                        while(pos!= lista.end()){

                            ///se intenta convertir el puntero a objeto a un puntero a cliente
                            Cliente *cli = dynamic_cast<Cliente*>(*pos);

                            ///si el puntero es valido se imprime la informacion
                            if(cli){
                                cout <<"ID: " <<cli->getIdCliente() <<endl;
                                cout <<"Nombre: " <<cli->getNombre() <<endl;
                                cout <<"Apellido: " <<cli->getApellidos() <<endl;
                            }

                            ///se avanza el iterador al siguiente elemento de la lista
                            pos++;
                        }
                    }
                }
                break;
            case 5:
                ///Lista de productos{
                {
                    ///se verifica si la lista esta vacia
                    if(lista.empty()){
                        cout <<"La lista de productos esta vacia" <<endl;
                    }
                    else{
                        ///si no esta vacia, se crea un iterador para recorrerla
                        list<Objeto*>::iterator pos = lista.begin();

                        ///se recorre la lista mientras el iterador no llegue al final
                        while(pos!= lista.end()){

                            ///se intenta convertir el puntero a objeto a un puntero a cliente
                            Producto *prod = dynamic_cast<Producto*>(*pos);

                            ///si el puntero es valido se imprime la informacion
                            if(prod){
                                cout <<"ID: " <<prod->getIdProducto() <<endl;
                                cout <<"Descripcion: " <<prod->getDescripcion() <<endl;
                                cout <<"Existencia: " <<prod->getExistencia() <<endl;
                            }
                            ///se avanza el iterador al siguiente elemento de la lista
                            pos++;
                        }
                    }
                }
                break;
            case 6:
                ///Lista de ventas
                {
                    ///se verifica si la lista esta vacia
                    if(lista.empty()){
                        cout <<"La lista de ventas esta vacia" <<endl;
                    }
                    else{
                        ///si no esta vacia, se crea un iterador para recorrerla
                        list<Objeto*>::iterator pos = lista.begin();

                        ///se recorre la lista mientras el iterador no llegue al final
                        while(pos!= lista.end()){

                            ///se intenta convertir el puntero a objeto a un puntero a cliente
                            Venta *vent = dynamic_cast<Venta*>(*pos);

                            ///si el puntero es valido se imprime la informacion
                            if(vent){
                                cout <<"Numero de factura: " <<vent->getNumeroFactura() <<endl;
                                cout <<"Cliente: " <<vent->getCliente().getNombre() <<" " <<vent->getCliente().getApellidos() <<endl;
                                cout <<"Fecha: " <<vent->getFecha() <<endl;
                            }
                            ///se avanza el iterador al siguiente elemento de la lista
                            pos++;
                        }
                    }
                }
                break;
            case 7:
                ///Detalles de la venta
                {
                    ///declaracion de variables
                    int numFactura;
                    Venta *vent = NULL;

                    ///solicitud de datos
                    cout <<"Digite el numero de factura: ";
                    cin >> numFactura;

                    ///se busca el numero de factura en la venta
                    ///se busca el producto
                    for(Objeto *obj : lista){/// Itera sobre cada elemento en la lista de objetos

                        ///Intenta convertir el puntero de tipo Objeto a un puntero de tipo venta
                        vent = dynamic_cast<Venta*>(obj);

                        // Verifica si la no es nulo
                        // y si el ID de la venta coincide con el ID buscado
                        if(vent && vent->getNumeroFactura() == numFactura){
                                break; ///producto econtrado
                        }
                    }

                    ///si la venta no es nula
                    if(vent){
                        cout <<"Numero de factura:" <<vent->getNumeroFactura() <<endl;
                        cout <<"Fecha de la Venta:" <<vent->getFecha() <<endl;
                        cout <<"Cliente:" <<vent->getCliente().getNombre()<< " " << vent->getCliente().getApellidos() << endl;
                        cout <<"Lista de productos vendidos" <<endl;
                        list<Producto*> listaProdvendidos = vent->getListaProductos();
                        if(!listaProdvendidos.empty()){
                            for(Producto *prod : listaProdvendidos){
                                cout <<"ID: " <<prod->getIdProducto() <<endl;
                                cout <<"Descripcion: " <<prod->getDescripcion() <<endl;
                                cout <<"Existencia: " <<prod->getExistencia() <<endl;
                            }
                        }
                        else{
                            cout <<"La factura no tiene productos asignados" <<endl;
                        }
                    }
                    else{
                        cout <<"La factura no esta en la lista" <<endl;
                    }
                }
                break;
            case 8:
                cout<<"Saliendo del programa...\n";
                break;
            default:
                cout<<"Error, opcion no valida\n";
                break;
        }
        system("pause");
    }while (opc!=8);
    return 0;
}
