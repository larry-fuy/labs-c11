
#include <iostream>
using namespace std;

int main()
{
#ifdef __LINE__ 
  cout << "__LINE__ is defined" << endl; 
#else 
  cout << "__LINE__ is not defined" << endl; 
#endif

#ifdef __FILE__ 
  cout << "__FILE__ is defined" << endl; 
#else 
  cout << "__FILE__ is not defined" << endl; 
#endif

#ifdef __DATE__ 
  cout << "__DATE__ is defined" << endl; 
#else 
  cout << "__DATE__ is not defined" << endl; 
#endif

#ifdef __TIME__ 
  cout << "__TIME__ is defined" << endl; 
#else 
  cout << "__TIME__ is not defined" << endl; 
#endif

#ifdef __TIMESTAMP__ 
  cout << "__TIMESTAMP__ is defined" << endl; 
#else 
  cout << "__TIMESTAMP__ is not defined" << endl; 
#endif

#ifdef __cplusplus
  cout << "__cplusplus is defined as " << __cplusplus << endl; 
#else 
  cout << "__cplusplus is not defined" << endl; 
#endif
// Was == 1 in 4.6.3, is == 201103 in 4.7.2

//#warning warning is defined
//#error error is defined
}
