#ifndef CIUDAD_H
#define CIUDAD_H

class Ciudad
{
    public:
        int getID();
        char * getIDPais();
        char * getNombre();
        int getPoblacion();
        void setID(int);
        void setIDPais(const char *);
        void setNombre(const char *);
        void setPoblacion(int);
        void mostrar();
        bool leerEnDisco(int);
        bool guardarEnDisco(int);
        bool guardarEnDisco();
        void cargar();
    private:
        int _ID;
        char _nombre[35];
        char _idpais[4];
        int _poblacion;
};

#endif // CIUDAD_H
