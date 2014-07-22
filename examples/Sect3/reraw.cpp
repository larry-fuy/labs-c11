#include <iostream>
#include <iomanip>
#include <regex>
using namespace std;
#include "presidents.h"

int main()
{
  const char* pat1 = "D.";
  regex r1(pat1);
  const char* pat2 = "D\.";
  regex r2(pat2);
  const char* pat3 = "D\\.";
  regex r3(pat3);
  const char* pat4 = R"(D\.)";
  regex r4(pat4);

  for(int i=0; i<NUMPRESIDENTS*4; i++) {
    if( regex_search(presidents[i], r1) ) {
      cout << "r1 " << presidents[i] << endl;
    }
    if( regex_search(presidents[i], r2) ) {
      cout << "r2 " << presidents[i] << endl;
    }
    if( regex_search(presidents[i], r3) ) {
      cout << "r3 " << presidents[i] << endl;
    }
    if( regex_search(presidents[i], r4) ) {
      cout << "r4 " << presidents[i] << endl;
    }
  }

//  for (int i=0; i<NUMPRESIDENTS*4; i+=4) {
//    const char* years = presidents[i];
//    const char* president = presidents[i+1];
//    const char* firstlady = presidents[i+2];
//    const char* vicepres = presidents[i+3];
//    cout << left << setw(10) << years << setw(26) << president << setw(50) << firstlady << setw(20) << vicepres << "|" << endl;
//  }
}
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
