#include <iostream>
using namespace std;

constexpr int square(int x)
{ 
  return x * x; 
}

int main()
{
  constexpr int arr[square(3)] = {};
  for(int i : arr ) cout << i;
  cout << endl;
}
