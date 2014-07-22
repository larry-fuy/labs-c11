// MyString.cpp
// Implementation of the non-inline member functions of the "MyString" class 
//

#include "MyString.h"

using namespace std;

MyString::MyString(const char* s)
{
	length_ = strlen(s);
	sPtr_ = new char[length_ + 1];
	strcpy(sPtr_, s);
}

MyString::MyString(const MyString& copy)
{
   cout << "copy constructor " << endl;
	length_ = copy.length_;
	sPtr_ = new char[length_ + 1];
	strcpy(sPtr_, copy.sPtr_);
}

MyString::MyString(MyString&& copy)
{
   cout << "move constructor" << endl;
	length_ = copy.length_;
        sPtr_ = copy.sPtr_;
        copy.length_ = 0;
        copy.sPtr_ = nullptr;
}


MyString::~MyString()
{
	delete [] sPtr_;
}

MyString&
MyString::operator=(const MyString& right)
{
   cout << "assignment " << endl;
        if (&right != this) {
                delete [] sPtr_;
                length_ = right.length_;
                sPtr_ = new char[length_ + 1];
                strcpy(sPtr_, right.sPtr_);
        }

        return *this;
}

MyString&
MyString::operator=(MyString&& right)
{
   cout << "move assignment" << endl;
        if (&right != this) {
                delete [] sPtr_;
                length_ = right.length_;
                sPtr_ = right.sPtr_;
                right.length_ = 0;
                right.sPtr_ = nullptr;
        }

        return *this;
}

MyString
MyString::operator+(const MyString& right)
{
	size_t len = length_ + right.length_;
	char* temp = new char[len + 1];
	strcpy(temp, sPtr_);
	strcat(temp,right.sPtr_);
	
	MyString tempString(temp);
	
	delete [] temp;
	
	return tempString;
}

MyString&
MyString::operator+=(const MyString& right)
{
	char* tempLeftPtr = sPtr_;
	char* tempRightPtr = right.sPtr_;
	length_ += right.length_;
	sPtr_ = new char[length_ + 1];
	strcpy(sPtr_, tempLeftPtr);
	strcat(sPtr_, tempRightPtr);
	delete [] tempLeftPtr;
	
	return *this;
}


MyString
MyString::operator()(int index, size_t subLength)
{
	MyString sub;        // Temporary for the substring
	
	if ((subLength == 0) || (index + subLength > length_))
		sub.length_ = length_ - index + 1;
	else
		sub.length_ = subLength + 1;
		
	delete sub.sPtr_;
	sub.sPtr_ = new char[sub.length_ + 1];
	
	strncpy(sub.sPtr_, &sPtr_[index], sub.length_);
	
	sub.sPtr_[sub.length_] = '\0';
	
	return sub;
}


ostream& operator<<(ostream& output, const MyString& s)
{
	output << s.sPtr_;
	return output;
}

istream& operator>>(istream& input, MyString& s)
{
	char temp[100];

  input.getline(temp, 100);
	s = temp;
	return input;
}
