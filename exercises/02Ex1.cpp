
#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
  // 1. create an unordered set from this list
unordered_set<string> presidents = {
      string("George Washington"),
      string("John Adams"),
      string("Thomas Jefferson"),
      string("James Madison"),
      string("James Monroe"),
      string("John Quincy Adams"),
      string("Andrew Jackson"),
      string("Martin Van Buren"),
      string("William Henry Harrison"),
      string("John Tyler"),
      string("James K. Polk"),
      string("Zachary Taylor"),
      string("Millard Fillmore"),
      string("Franklin Pierce"),
      string("James Buchanan")
};

  // 2. print using new version of for
for (auto s : presidents) cout << s << endl;

  // 3a. create a new set consisting of just the James presidents
string first_name = "James";
set<string> presidents_james;

copy_if(begin(presidents), end(presidents), inserter(presidents_james, end(presidents_james)), [&](const string& s){ return s.find(first_name) != string::npos; });


  // 3b, find and print the first and last president alphabetically
cout << endl;
cout << *min_element(begin(presidents_james), end(presidents_james)) << endl;
cout << *max_element(begin(presidents_james), end(presidents_james)) << endl;

}
