#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

  Sculptor::Sculptor(int _nx, int _ny, int _nz)                     
 {
   
    this->nx=_nx; this->ny=_ny; this->nz=_nz;
    this->r = 0.0; this->g = 0.0; this->b = 0.0; this->a = 0.0;
    
    v = new Voxel **[_nx];     
    for (int i=0;i<_nx;i++){
    
      v[i] = new Voxel *[_ny];
      for (int j=0;j<_ny;j++)
      {
      
        
        v[i][j] = new Voxel [_nz];
        for (int k=0; k<_nz;k++)
        {
         this->v[i][j][k].r = 0.0;             
         this->v[i][j][k].g = 0.0;              
         this->v[i][j][k].b = 0.0;              
         this->v[i][j][k].a = 0.0;              
         this->v[i][j][k].isOn = false;
        }
      }
    }
  } 

  
  Sculptor::~Sculptor(void)
{ 
  for(int i=0; i < this->nx;i++)
  {
   for(int j=0; j < this->ny;j++)
    {
      delete [] this-> v[i][j]; 
    }
    delete [] this-> v[i];
  }
   delete [] this-> v;
};
   
void Sculptor::setColor(float r,float g,float b,float alpha)
{
  this->r = r; this->g = g; this->b = b; this->a = alpha;  
}
void Sculptor::putVoxel(int x,int y,int z)              
{
    if(x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz)
    {
      this->v[x][y][z].isOn = true;
      this->v[x][y][z].r = this->r; this->v[x][y][z].g = this->g; this->v[x][y][z].b = this->b;
      this->v[x][y][z].a = this->a;
    }
}
    void Sculptor::cutVoxel(int x,int y,int z)           
 {
    if(x >= 0 && x < this->nx && y >= 0 && y < this->ny && z >= 0 && z < this->nz)
    {
      this->v[x][y][z].isOn = false;
      
    }
  };
  
  void Sculptor::writeOFF(const char* filename)
{
  std::ofstream fout;
    fout.open (filename);
    if(!fout.is_open())
    {
      std::cout << "Falha em abrir pasta.";
      exit (1);
    
  fout << std:: fixed;                    
  fout << std:: setprecision(1);          
    int active = 0;                     
    int countActives = 0;                 

    for(int i = 0;i < this->nx;i++)
  {
      for(int j = 0;j < this->ny;j++)
    {
        for(int k = 0;k < this->nz;k++)
      {
         if(this->v[i][j][k].isOn)
        {
          active++;
        }
      }
    }
  }
    fout << "OFF" << std::endl;
    fout << 8*active << " " << 6*active << " " << "0" << std::endl;

  for(int i = 0;i < this->nx;i++)
  {
    for(int j = 0;j < this->ny;j++)
    {
      for(int k = 0;k < this->nz;k++)
      {
        if(this->v[i][j][k].isOn)
        {
          // O endl declara o fim da linha para a mÃ¡quina. 
          fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
          fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
          fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
          fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
          fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
          fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
          fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
          fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
        }
      }
    }
  }

for(int i = 0;i < this->nx;i++)
{
  for(int j = 0;j < this->ny;j++)
 {
   for(int k = 0;k < this->nz;k++)
  {
    if(this->v[i][j][k].isOn)
    {
fout << "4 " << countActives * 8 + 0 << " " << countActives * 8 + 3 << " " << countActives * 8 + 2 << " " << countActives * 8 + 1 << " " << this-> v[i][j][k].r << " " << this-> v[i][j][k].g << " " << this-> v[i][j][k].b << " " << this-> v[i][j][k].a << " " << std::endl;        //1
fout << "4 " << countActives * 8 + 4 << " " << countActives * 8 + 5 << " " << countActives * 8 + 6 << " " << countActives * 8 + 7 << " " << this-> v[i][j][k].r << " " << this-> v[i][j][k].g << " " << this-> v[i][j][k].b << " " << this-> v[i][j][k].a << " " << std::endl;        //2
fout << "4 " << countActives * 8 + 0 << " " << countActives * 8 + 1 << " " << countActives * 8 + 5 << " " << countActives * 8 + 4 << " " << this-> v[i][j][k].r << " " << this-> v[i][j][k].g << " " << this-> v[i][j][k].b << " " << this-> v[i][j][k].a << " " << std::endl;        //3
fout << "4 " << countActives * 8 + 0 << " " << countActives * 8 + 4 << " " << countActives * 8 + 7 << " " << countActives * 8 + 3 << " " << this-> v[i][j][k].r << " " << this-> v[i][j][k].g << " " << this-> v[i][j][k].b << " " << this-> v[i][j][k].a << " " << std::endl;       //4
fout << "4 " << countActives * 8 + 3 << " " << countActives * 8 + 7 << " " << countActives * 8 + 6 << " " << countActives * 8 + 2 << " " << this-> v[i][j][k].r << " " << this-> v[i][j][k].g << " " << this-> v[i][j][k].b << " " << this-> v[i][j][k].a << " " << std::endl;      //5
fout << "4 " << countActives * 8 + 1 << " " << countActives * 8 + 2 << " " << countActives * 8 + 6 << " " << countActives * 8 + 5 << " " << this-> v[i][j][k].r << " " << this-> v[i][j][k].g << " " << this-> v[i][j][k].b << " " << this-> v[i][j][k].a << " " << std::endl;      // 6
countActives++;
        }
      }
    }
  }
  fout.close();
};