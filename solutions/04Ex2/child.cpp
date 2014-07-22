
#include <iostream>
using namespace std;

#include "child.h"

// Child class for section 4, exercise 2

// implementation

void Child::about()
{
  cout << "Child : " << name_ << ", " << age_ << endl;
}

Child::operator int()
{
  return age_;
}

