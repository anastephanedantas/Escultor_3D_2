#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include "figurageometrica.h"
#include <string>
using namespace std;

class Interpretador
{
    int dimx,dimy,dimz;
    float r,g,b,a;
public:
    Interpretador();
    ~Interpretador(){};
    // container de ponteiros para figuraGeometrica, aqui será feita a leitura do arquivo
    vector<FiguraGeometrica*> anl(string filename);
    // retorna os valores das dimensões
    int getdimx();
    int getdimy();
    int getdimz();
};

#endif // INTERPRETADOR_H