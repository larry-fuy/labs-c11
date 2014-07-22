
#include <iostream>
using namespace std;

#include "parent.h"

// Parent class for section 4, exercise 2

// implementation

Parent::Parent(string name, int age): name_(name), age_(age) { }

Parent::Parent(): Parent("unnamed", 99) { }  //delegate

Parent::~Parent() { }

void Parent::about()
{
  cout << "Parent : " << name_ << ", " << age_ << endl;
}

int Parent::discipline()
{
  cout << "That is not the right thing to do." << endl;
}

string Parent::talk(string s)
{
  cout << s << endl;
  return "Yes, please";
}

