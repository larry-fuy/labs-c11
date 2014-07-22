#include <iostream>
#include <fstream>
#include <regex>
using namespace std;


int main()
{

  ifstream fl;
  fl.open("Oregon.txt");

  string pat("Oregon");
  regex r(pat);
  smatch res;

  while (! fl.eof()) {
    string fit;
    getline(fl, fit);
    cout << fit << endl;
    if (regex_search(fit, res, r))
      cout << res.str() << endl;
    else
      cout << "***** regex_search failed to find anything" << endl;

/*  Iterators not yet implemented
    for (sregex_iterator it(fit.begin(), fit.end(), r), end_it;
         it != end_it; ++it) {
      cout << it->str() << endl;
    }
*/
  }

}
