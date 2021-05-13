#include "Ciudad.h"
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int  Ciudad::getID()
{
    return _ID;
}
char * Ciudad::getNombre()
{
    return _nombre;
}
char * Ciudad::getIDPais()
{
    return _idpais;
}
int  Ciudad::getPoblacion()
{
    return _poblacion;
}
void Ciudad::setID(int val)
{
    _ID = val;
}
void Ciudad::setNombre(const char * val)
{
    strcpy(_nombre, val);
}
void Ciudad::setIDPais(const char * val)
{
    strcpy(_idpais, val);
}
void Ciudad::setPoblacion(int val)
{
    _poblacion = val;
}
void Ciudad::mostrar(){
    cout << _ID << " " << _idpais << " " << _nombre << " " << _poblacion << endl;
}

void Ciudad::cargar(){
    cout << "ID CIUDAD    : " ;
    cin >> _ID;
    cout << "ID PAIS      : " ;
    cin >> _idpais;
    cout << "NOMBRE CIUDAD: " ;
    cin >> _nombre;
    cout << "POBLACIÓN    : " ;
    cin >> _poblacion;
}

bool Ciudad::leerEnDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("ciudades.dat", "rb");
    if( p == NULL ){
        cout << "No se pudo leer en Disco";
        return false;
    }
    fseek(p, sizeof (Ciudad)*pos, SEEK_SET );
    lectura = fread(this, sizeof(Ciudad), 1, p);
    fclose(p);
    return lectura;
}
bool Ciudad::guardarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("ciudades.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Ciudad)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(Ciudad), 1, p);
    fclose(p);
    return guardo;
}

bool Ciudad::guardarEnDisco(){
    bool guardo;
    FILE *p;
    p = fopen("ciudades.dat", "ab");
    if( p == NULL ){
        return false;
    }
    guardo = fwrite(this, sizeof(Ciudad), 1, p);
    fclose(p);
    return guardo;
}
