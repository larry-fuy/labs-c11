
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{ 
vector<pair<string, int>> states = {
{"Alaska", 1959},
{"Arizona", 1912},
{"Colorado", 1876},
{"Hawaii", 1959},
{"Idaho", 1890},
{"Montana", 1889},
{"Nebraska", 1867},
{"Nevada", 1864},
{"New Mexico", 1912},
{"North Dakota", 1889},
{"Oklahoma", 1907},
{"South Dakota", 1889},
{"Utah", 1896},
{"Washington", 1889},
{"Wyoming", 1890} };

  cout << "Sorted alphebetically" << endl;
  for ( int i=0; i<states.size(); i++)
    cout << states[i].first << " in " << states[i].second << endl;

  //sort(states.begin(), states.end(), put lambda here );

  cout << "\nSorted by year" << endl;
  for ( int i=0; i<states.size(); i++)
    cout << states[i].first << " in " << states[i].second << endl;

}
