
#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

  bool is_James(string p) { return ( p.find("James") != -1 ); }
int main()
{
  // 1. create an unordered set from this list
  unordered_set<string> presidents 
      {
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
  for ( auto p : presidents ) cout << p << endl;

  // 3a. create a new set consisting of just the James presidents
  cout << "\nthe james" << endl;
  unordered_set<string> james;
  copy_if(presidents.begin(), presidents.end(), inserter(james, james.begin()), is_James);
  for ( auto p : james ) cout << p << endl;

  // 3b, find and print the first and last president alphabetically
  cout << "\nfirst and last" << endl;
  auto fnl = minmax_element(presidents.begin(), presidents.end());
  cout << *fnl.first << endl;
  cout << *fnl.second << endl;

}
