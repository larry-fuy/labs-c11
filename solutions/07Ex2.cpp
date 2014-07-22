
#include <iostream>
#include <tuple>
#include <vector>
#include <memory>
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
using Book = tuple<const string, const string, int, Date>;

template<typename T, typename... Arg> 
shared_ptr<T> factory(Arg&&... arg)
{ 
  return shared_ptr<T>(new T(std::forward<Arg>(arg)...));
}

int main()
{
  // the vector of Books
  vector<shared_ptr<Book>> books;

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

    // Add to the vector
    books.push_back(factory<Book>(author, title, numpages, d));
    //shared_ptr<Book> sptr(new Book(author, title, numpages, d));
    //books.push_back(sptr);
  }

  // Print the array of books
  for (int i = 0; i<books.size(); i++) {
    shared_ptr<Book> b = books[i];
    cout << "\nBook " << i+1 << endl;
    cout << "Author: " << get<0>(*b) << endl;
    cout << "Title: " << get<1>(*b) << endl;
    cout << "Pages: " << get<2>(*b) << endl;
    cout << "Published: " << get<3>(*b).display() << endl;
  }

}
