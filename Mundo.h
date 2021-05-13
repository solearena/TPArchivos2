#ifndef MUNDO_H
#define MUNDO_H


class Mundo{
    private:
        char _codigoPais[4];
        char _nombrePais[45];
        char _nombreCiudad[35];
        int _poblacionMayor;
    public:
        char *getNombreCiudad();
        void setCodigoPais(char*);
        void setNombrePais(char*);
        void setNombreCiudad(char*);
        void setPoblacionMayor(int);
        void grabarEnDisco();
        bool leerDeDisco(int);
        void mostrar();
};

#endif // MUNDO_H
