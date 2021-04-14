#pragma once

#include "vector.hh"

class rectangle{
   Vector point[SIZE_RECTANGLE];
   public:
   rectangle(){};
   rectangle(Vector pkt0, double wysokosc, double szerokosc);

const Vector &operator [] (int index) const;
Vector &operator [] (int index) ;
rectangle operator + (Vector move);
void move_r(Vector move);

};
 rectangle::rectangle(Vector pkt0, double wysokosc, double szerokosc)
 {
     for(int i=0;i<SIZE_RECTANGLE;i++)
 point[i]=pkt0;
 point[1][0]+=szerokosc;
 point[2][1]+=wysokosc;
 point[2][0]+=szerokosc;
 point[3][1]+=wysokosc;
 }

const Vector &rectangle::operator [] (int index) const
{
    return point[index];
}

Vector &rectangle::operator [] (int index) 
{
return point[index];
}

rectangle rectangle::operator + (Vector move)
{
    
    rectangle wynik;
    for(int i=0;i<SIZE_RECTANGLE;i++)
        wynik[i]=point[i]+move;
    return wynik;
}
std::ostream &operator <<(std::ostream &out,const rectangle &tmp )
{
    for(int i=0;i<SIZE_RECTANGLE;i++)
    out<<tmp[i]<<std::endl;
     out<<tmp[0]<<std::endl;
     return out;
}

void rectangle::move_r(Vector move)
{
    *this=*this+move;
}





