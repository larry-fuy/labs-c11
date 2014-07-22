#include <iostream>
using namespace std;

int square(int x)
{ 
  return x * x; 
}

int main()
{
  int arr[square(3)] = {};
  for(int i : arr ) cout << i;
  cout << endl;
}
