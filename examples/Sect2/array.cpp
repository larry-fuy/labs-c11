#include <iostream>
#include <array>
#include <typeinfo>
#include <algorithm>
using namespace std;

void fun(int a)
{
  int arr[10];
  if(a) {
    for(int i=0; i<10; i++) arr[i] = a;
  }
  for(int i : arr)cout << i << ' ';
  cout << endl;
}

void fum()
{
  int arr[10] = { 1, 2, 3 };
  for(int i : arr)cout << i << ' ';
  cout << endl;
}

int main()
{
  int a[5] = { 3, 5, 7 };
  array<int, 5> b = { 2, 4, 6 };

  a[3] = 1;
  b[3] = 1;      //same as above

  int x = a[4];  //x becomes zero because defaults are 0
  int y = b[4];  //same as above

  int* p = a;    //OK
//int* q = b;    //error, a is not an int pointer

  int* r = &a[1];  //OK
  int* s = &b[1];  //same as above

  cout << typeid(b).name() << endl;
  for(auto i : b) cout << i << ' ';
  cout << *s << endl;

  cout << typeid(a).name() << endl;
  for(auto i : a) cout << i << ' ';
  cout << *r << endl;

  fun(8);
  fun(0);
  fum();

}
