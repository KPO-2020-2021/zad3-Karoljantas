#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "matrix.hh"
#include "rectangle.hh"




 TEST_CASE("test wektora ")
 { double wek[]={5,6};
  Vector x(wek);
   CHECK(x[0]== 5);
   CHECK(x[1]== 6);
    }
TEST_CASE("test wektora")
{ 
    Vector x;
     CHECK(x[0]== 0); 
     CHECK(x[1]== 0);
     }
  TEST_CASE("wektor - wyswietlanie standard") 
  { double wek[]={5,6};
   Vector x(wek); 
   std::ostringstream out; out <<x;
    CHECK( "5\t6\t" == out.str() );
     }
   TEST_CASE("wektor - wczytywanie standard") 
   {
  Vector x; 
  std::istringstream in("6 7"); 
   in >> x; std::ostringstream out; out <<x; 
   CHECK( "6\t7\t" == out.str() ); 
   } 
  TEST_CASE("test wektora +")
  {
       double wek[]={4,6};
   Vector x(wek); Vector y(wek);
    y=y+x; CHECK(y[0]== 8);
     CHECK(y[1]== 12);
      } 
  TEST_CASE("sprawdzenie []") 
  {
       double wek[]={4,6};
        Vector x(wek);
         WARN_THROWS(x[10]);
          } 


TEST_CASE("test wektora ==") 
{ 
    Vector x,y; 

CHECK( x==y);
}


TEST_CASE("test macierzy")
           { 
               Matrix x;
                double wek[]={4,6};
                 Vector y(wek);
                  y=x*y;
                   CHECK(y[0]== 0);
                    CHECK(y[1]== 0);
                     }
TEST_CASE("test macierzy ")
 { 
     Matrix x;
      for(int i=0; i<2; i++)
       for(int j=0; j<2; j++) 
       CHECK(x(i,j)== 0);
        } 

        TEST_CASE("test ()")
             {
                  Matrix x;
              WARN_THROWS(x(10,20));
               } 
        TEST_CASE("test macierzy ")
        { 
            double mac[2][2]={{1,1},{1,1}};
         Matrix x(mac); 
         for(int i=0; i<2; i++)
          for(int j=0; j<2; j++) 
          CHECK(x(i,j)== 1);
           } 



           TEST_CASE("test prostokata ")
            {
                 Matrix tmpM3;
                
                  double wek[]={0,0};
                   rectangle x(Vector(wek),1,1);
                    tmpM3.rotation(90,x);
                     CHECK(x[0][0]== 0);
                      CHECK(x[0][1]== 0);
                       }

                        TEST_CASE("prostokata - wyswietlanie standard")
            { double wek[]={0,0};
             rectangle x(Vector(wek),1,1);
              std::ostringstream out;
               out <<x; 
               CHECK( "0\t0\t\n1\t0\t\n1\t1\t\n0\t1\t\n0\t0\t\n" == out.str() );
                }
           TEST_CASE("test prostokata")
           { 
               double wek[]={0,0};
                rectangle x(Vector(wek),1,1);
                 CHECK(x[0][0]== 0);
                  CHECK(x[0][1]== 0);
                   } 
           
            TEST_CASE("test prostokata ")
            { 
                double wek[]={0,0};
                 rectangle x(Vector(wek),1,1);
                  double wek2[]={1,1};
                   x.move_r(Vector(wek2));
                    CHECK(x[0][0]== 1);
                     CHECK(x[0][1]== 1);
                      } 
           
           

