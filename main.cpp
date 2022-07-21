
#include <iostream>
#include <fstream>
#include <string>
#include "voxel.h"
#include "sculptor.h"
#include "interpretador.h"
#include <vector>
#include "putVoxel.h"
#include "putbox.h"
#include "putsphere.h"
#include "putellipsoid.h"
#include "cutvoxel.h"
#include "cutbox.h"
#include "cutsphere.h"
#include "cutellipsoid.h"
#include "figurageometrica.h"
using namespace std;




int main()
{
    Sculptor *sx;
    Interpretador anl;
    vector<FiguraGeometrica*> fig;

    fig = anl.anl("bart.txt"); //  todos os processos serão realizados a partir do container que armazenou os mesmos.

    sx = new Sculptor(anl.getdimx(),anl.getdimy(),anl.getdimz());
     // alocação de memória

    // cada processo recebe o método draw relacionado ao tipo de classe [putbox,putsphere...]
    for (size_t x=0; x<fig.size(); x++){
        fig[x] -> draw(*sx);
    }

    sx->writeOFF((char*)"bart.off"); // criação do arquivo .off

    for (size_t x=0; x<fig.size(); x++){
        delete fig[x];
    }
    delete sx;
}