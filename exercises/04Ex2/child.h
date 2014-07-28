#ifndef CHILD_H
#define CHILD_H

#include "parent.h"

// Child class for section 4, exercise 2

class Child : public Parent {
public:
   using Parent::Parent;
   void about() override;
   void discipline() = delete;

   explicit operator int() { return age_;}
};
#endif
