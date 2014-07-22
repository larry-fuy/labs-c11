
#include <iostream>
using namespace std;

struct Date
{
  unsigned short  year;    // gregorian, e.g. 2013
  unsigned short  month;   // 1-12
  unsigned short  day;     // 1-31
  string display() { 
    char temp[12];
    sprintf(temp, "%4d/%02d/%02d", year, month, day);
    return temp;
  }
};

// tuple definition (template alias) a Book


int main()
{
  // the array of Books


  while (true)
  {
    // Collect data for a Book
    string author;
    string title;
    int numpages;
    Date d;

    cout << "Enter author: ";
    getline(cin, author);
    if (author.size() == 0) break;
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Number of pages: ";
    cin >> numpages;
    cout << "Enter Year published: ";
    cin >> d.year;
    cout << "Enter Month published (as a number): ";
    cin >> d.month;
    cout << "Enter Day published: ";
    cin >> d.day;
    cin.ignore();

    // Add to the array
  }

  // Print the array of books

}
