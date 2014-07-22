#ifndef CHILD_H
#define CHILD_H

#include "parent.h"

// Child class for section 4, exercise 2

class Child: public Parent
{
public:
  using Parent::Parent;

  ~Child() = default;

  void about() override;

  int discipline() = delete;

  explicit operator int();

};

#endif
