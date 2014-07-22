// Test program for thr MyString class
//


#include <iostream>
using namespace std;

#include "MyString.h"

void f1(MyString&& a)
{
	cout << "a : " << a << endl;
}

MyString&& f2()
{
	MyString* tmp = new MyString("mnop");
        return move(*tmp);
}

int main()
{

        MyString s1("abcdef"), s2("abcdef"), s3("abcdeg"), s4("xyz"), s5;
        
        
        cout << "s1 : " << s1 << endl;
        
        cout << "s2 : " << s2 << endl;
        
        cout << "s3 : " << s3 << endl;
        
        cout << "s4 : " << s4 << endl;
        
        cout << "Assignment s5 = s4" << endl;
        s5 = s4;
        
        cout << "s5 : " << s5 << endl;
        
        cout << "Testing s1 == s2" << endl;
        if (s1 == s2) 
                cout << "s1 and s2 are equal" << endl;
        else
                cout << "s1 and s2 are not equal" << endl;
        
        cout << "Testing s1 != s2" << endl;
        if (s1 != s2)
                cout << "s1 and s2 are not equal" << endl;
        else
                cout << "s1 and s2 are equal (from !=)" << endl;

        if (s1 < s2)
                cout << "s1 is < s2" << endl;

        if (s1 < s3)
                cout << "s1 is < s3" << endl;

        if (s3 >= s1)
                cout << "s3 is >= s1" << endl;

        if (s1 <= s1)
                cout << "s1 is <= s1" << endl;
        
        cout << "Assignment s1 = s1 + \"xyz\"" << endl;
        s1 = s1 + "xyz";
        
        cout << "s1 : " << s1 << endl;
        
        cout << "Length of s1 : " << s1.getLength() << endl;
        
        cout << "s1[3] : " << s1[3] << endl;
        
        cout << "Assignment s1[3] = 'X'" << endl;
        s1[3] = 'X';
        
        cout << "s1[3] : " << s1[3] << endl;
        
        cout << "s1 : " << s1 << endl;
        cout << "s1(3, 3) : " << s1(3, 3) << endl;

        cout << "s1 += s2" << endl;
        s1 += s2;
        cout << "s1 : " << s1 << endl;
        
	if (!s1) {
		cout << "Not operator failed." << endl;
	} else {
		cout << "Not operator worked." << endl;
        }

	// using which constructor?
        MyString t1(s1);
	MyString t2 = s2;
	MyString t3 {s3};
	MyString t4 = s4 + s5;
	MyString* t5 = new MyString("abc");

        cout << "f1(\"rst\")" << endl;
	f1("rst");

        cout << "f1(move(*t5))" << endl;
	f1(move(*t5));
        cout << "t5 : " << *t5 << endl;
	delete t5;

        cout << "f1(s4 + s5)" << endl;
	f1(s4 + s5);

        cout << "s6 = f2()" << endl;
	auto s6 = f2();
        cout << "s6 : " << s6 << endl;

        return 0;
        
}

