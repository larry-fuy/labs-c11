#ifndef PARENT_H
#define PARENT_H

#include <string>

using namespace std;

// Parent class for section 4, exercise 2

class Parent
{
public:
Parent(string name, int age) : name_(name), age_(age) { }
Parent() : Parent("unnamed", 99) {}

   virtual void about() {
      cout << "Parent: < " << name_ <<">, <" << age_ << ">" << endl;
   }
   
   string talk(string s) {
      cout << " Yes, please " << endl;
   }
   
   void discipline() {
      cout << "That is not the right thing to do" << endl;
   }


protected:
  string name_;
  int age_;
};

#endif
