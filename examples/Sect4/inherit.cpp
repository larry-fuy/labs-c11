#include <iostream>
#include <typeinfo>
#include <iomanip>
using namespace std;

class myparent
{
public:
  virtual void display() { cout << "Parent display" << endl; }
};

class mychild: public myparent
{
public:
  void display() const { cout << "Child display" << endl; }
};

class mygrandchild: public mychild
{
public:
  void display() { cout << "Grandchild display" << endl; }
};

class abparent
{
public:
  virtual void display() = 0;
  void show() { cout << "abParent show" << endl; }
  //void show() const { cout << "abParent show" << endl; }
};

class abchild: public abparent
{
public:
  void display() { cout << "abChild display" << endl; }
  virtual void show() = 0;
  //virtual void show() final = 0;
};

class realgrandchild: public abchild
{
public:
  void display() override { cout << "abGrandchild display" << endl; }
  void show() override { cout << "abGrandchild show" << endl; }
};


int main()
{
  myparent* a;
  mychild* b;
  mygrandchild* c;
  mychild x;
  mygrandchild y;

  a = &x;
  a->display();

  a = &y;
  a->display();

  b = &y;
  b->display();

  abparent* d;
  abchild* e;
  realgrandchild* f;
  // abchild u;     not allowed
  realgrandchild w;

  d = &w;
  d->display();

  e = &w;
  e->display();

  return 0;
}

