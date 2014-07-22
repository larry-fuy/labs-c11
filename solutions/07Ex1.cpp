
#include <iostream>
#include <tuple>
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
using Book = tuple<string, string, int, Date>;

int main()
{
  // the array of Books
  Book books[10];
  int numbooks = 0;

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
    books[numbooks] = Book(author, title, numpages, d);
    numbooks++;
  }

  // Print the array of books
  for (int i = 0; i<numbooks; i++) {
    cout << "\nBook " << i+1 << endl;
    cout << "Author: " << get<0>(books[i]) << endl;
    cout << "Title: " << get<1>(books[i]) << endl;
    cout << "Pages: " << get<2>(books[i]) << endl;
    cout << "Published: " << get<3>(books[i]).display() << endl;
  }

}
