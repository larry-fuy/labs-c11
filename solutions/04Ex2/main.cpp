
#include <iostream>
using namespace std;

#include "parent.h"
#include "child.h"

int main()
{

  // make a parent with defined constructor
  Parent mom("Mary", 33);

  // make a parent with default constructor
  Parent dad;

  // make a child with inherited constructor
  Child son("Jim", 6);

  // see what we got
  mom.about();
  dad.about();
  son.about();

  // call discipline on parent
  mom.discipline();

  // call discipline on child, should not compile
  //son.discipline();

  // call talk on parent
  cout << dad.talk("Would you like a spanking?") << endl;

  // call talk on child
  cout << son.talk("Would you like me to be good?") << endl;

  int i;

  // convert child to int
  i = int(son);

  // try to implicitly convert child to int, should not compile
  //i = son;
  cout << "Son is " << i << endl;
}
