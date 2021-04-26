#pragma once

#include "vector.hh"
/*!
 * \brief Kalasa opisujaca prostokat
 *
 *nieniejsza klasa zawiera metody oraz paremetry potrzebne do opisu prostokata
 */
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


/*!
 * Konstruktor parametryczny budujacy prostokat przez obliczenie wierzcholkow na podstawie
 * podanych danych punbktu pierwszego oraz długiosci i szerokosci
 * \param[in] pkt0 - wektor poczatkowy okreslajacy lewy dolny rog prostokata
 * \param[in] wysokosc - parametr przyjmujacy wysokosci prostokata
 * \param[in] szerokosc - parametr przyjmujacy szerokosc prostokata
 */
 rectangle::rectangle(Vector pkt0, double wysokosc, double szerokosc)
 {
     for(int i=0;i<SIZE_RECTANGLE;i++)
 point[i]=pkt0;
 point[1][0]+=szerokosc;
 point[2][1]+=wysokosc;
 point[2][0]+=szerokosc;
 point[3][1]+=wysokosc;
 }
/*!
 *  Funktor Prostokata.                                                                                                                      
 * \param[in] index - index wektora.                                                                                                             
 * \retval Wartosc prostokata w danym miejscu tablicy.                              
 */
const Vector &rectangle::operator [] (int index) const
{
    return point[index];
}
/*!
 *  Funktor Prostokata.                                                                                                                      
 * \param[in] index - index wektora.                                                                                                             
 * \retval Wartosc prostokata w danym miejscu tablicy.                              
 */
Vector &rectangle::operator [] (int index) 
{
return point[index];
}
/*!
*  Realizuje dodawanie Wektora do prostokata.                                                                      
 * \param[in]  move- drugi skladnik dodawania.                                         
  * \retval    Suma dwoch skladnikow wierzcholkow prostokata i wektora                                                                             
 */
rectangle rectangle::operator + (Vector move)
{
    
    rectangle wynik;
    for(int i=0;i<SIZE_RECTANGLE;i++)
        wynik[i]=point[i]+move;
    return wynik;
    
}

/*!
*  Przeciazenie operatora <<                                                                                                               
 * \param[in]     out - strumien wejsciowy,                                             
 * \param[in]    tmp - prostokat.                                                         
 */
std::ostream &operator <<(std::ostream &out,const rectangle &tmp )
{
    for(int i=0;i<SIZE_RECTANGLE;i++)
    out<<tmp[i]<<std::endl;
     out<<tmp[0]<<std::endl;
     return out;
}
/*!
*  funkcja przesowajaca prostokat o dany wektor                                                                  
 * \param[in]  move- wektor translacjia.   
 * \param this - prostokat                                     
  * \retval   prostokat po przesunueciu                                                                          
 */
void rectangle::move_r(Vector move)
{
    *this=*this+move;
}





