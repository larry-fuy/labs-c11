#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>

// MyString.h
// Definition of the "MyString" class

class MyString {
public:
  MyString(const char* s = "");   
                  // constructor

  MyString(const MyString& copy);   
                  // copy constructor

  ~MyString();            
                  // destructor
  
  MyString& operator=(const MyString& right);
                  // assignment operator
                  
  MyString operator+(const MyString& right);
                  // concatenation operator
  
  MyString& operator+=(const MyString& right);
                  // concatenation operator

  bool operator!() const;
                  // determine if string is empty
  
  bool operator==(const MyString& right) const;
                  // equality operator
                  
  bool operator!=(const MyString& right) const;  
                  // ineqaulity operator
                  
  bool operator<(const MyString& right) const;
                  // determine if s1 < s2
                  
  bool operator>(const MyString& right) const;
                  // determine if s1 > s2
  
  bool operator<=(const MyString& right) const;
                  // determine if s1 <= s2
  
  bool operator>=(const MyString& right) const;
                  // determine if s1 >= s2
                  
  char& operator[](int index);  
                  // subscript operator
  
  const char& operator[](int index) const;  
                  // const subscript operator
                  
  MyString operator()(int index, size_t subLength);  
                  // return a substring
  
  size_t getLength() const;
                  // return current length of string

private:
  char* sPtr_;
  size_t length_;
  

// Global functions

friend std::ostream& operator<<(std::ostream& output, const MyString& s);
                // output operator

friend std::istream& operator>>(std::istream& input, MyString& s);
                // input operator
  
};


// inline member functions for the class "MyString"

inline bool
MyString::operator!() const
{
  return (length_ == 0);
}

inline bool
MyString::operator==(const MyString& right) const
{
  return (std::strcmp(sPtr_, right.sPtr_) == 0);
}
            
inline bool
MyString::operator!=(const MyString& right) const
{
  return !(*this == right);
}

inline bool
MyString::operator<(const MyString& right) const
{
  return (std::strcmp(sPtr_, right.sPtr_) < 0);
}

inline bool
MyString::operator>(const MyString& right) const
{
  return (std::strcmp(sPtr_, right.sPtr_) > 0);
}

inline bool
MyString::operator<=(const MyString& right) const
{
  return (std::strcmp(sPtr_, right.sPtr_) <= 0);
}

inline bool
MyString::operator>=(const MyString& right) const
{
  return (std::strcmp(sPtr_, right.sPtr_) >= 0);
}

inline char&
MyString::operator[](int index)
{
  return sPtr_[index];
}

inline const char&
MyString::operator[](int index) const
{
  return sPtr_[index];
}

inline size_t
MyString::getLength() const
{
  return length_;
}

            
#endif
