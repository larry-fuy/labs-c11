#ifndef PARENT_H
#define PARENT_H

// Parent class for section 4, exercise 2

class Parent
{
public:
  Parent(string name, int age);

  Parent();

  virtual ~Parent();

  virtual void about();

  int discipline();

  string talk(string s);

protected:
  string name_;
  int age_;
};

#endif
