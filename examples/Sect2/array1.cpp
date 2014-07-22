#include <iostream>
using namespace std;

void fun(int a)
{
  int arr[10];
  if(a) {
    for(int i=0; i<10; i++) arr[i] = a;
  }
  for(int i=0; i<10; i++) cout << arr[i] << ' ';
  cout << endl;
}

void fum()
{
  int arr[10] = { 1, 2, 3 };
  for(int i=0; i<10; i++) cout << arr[i] << ' ';
  cout << endl;
}

int main()
{

  fun(8);
  fun(0);
  fun(7);
  fun(0);
  fum();

}
