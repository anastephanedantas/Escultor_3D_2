#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

// Classe abstrata
class FiguraGeometrica
{
protected:
    float r,g,b,a; // as subclasses devem herdar as cores e transparência
public:
    virtual void draw(Sculptor &t)=0;
    virtual ~FiguraGeometrica(){};
};

#endif // FIGURAGEOMETRICA_H