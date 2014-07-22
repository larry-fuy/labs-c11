#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
  enum TrafficLight { red, yellow, green };   //Traditional
  enum class Color { red, orange, blue };     //Scoped

//  TrafficLight t = 3;        //NG, always was
//  Color c = 3;               //NG, no int->Color conversion
  int i = red;               //OK, always was
  int j = TrafficLight::red; //OK, only in C++11
//  int k = blue;              //NG, blue not in scope
//  int l = Color::blue;       //NG, no Color->int conversion
//  Color d = blue;            //NG, blue not in scope
  Color e = Color::blue;     //OK
//  Color f = green;           //NG, not in class
  TrafficLight u;
  u = green;                 //OK, always was
  e = Color::blue;           //OK
//  e = green;                 //NG, type mismatch
//  u = Color::blue;           //NG, type mismatch
//  i = Color::blue;           //NG, type mismatch
  i = int(Color::blue);      //OK

  enum TrafficLight8 : char { pink, aqua };
  enum class Color16 : short { purple, gray};
//  enum bad : char { bok=1, toobig=300 };    //NG
  enum good : short { bok=1, toobig=300 };  //OK

  enum class Color_forward : long;  //forward declaration
  void fun(Color_forward* p);       //OK
  enum class Color_forward : long { 
     red, orange, yellow, green };  //definition
}
