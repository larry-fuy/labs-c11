#include <iostream>
#include <random>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;
default_random_engine re;
//uniform_int_distribution<int> ud(1, 100);
normal_distribution<double> ud(50, 5);

int main()
{
  	auto start = steady_clock::now();
	vector<int> number_count(100, 0);
	for (int i = 0; i < 4000; ++i) ++number_count[ud(re) - 1];
	for (int i = 0; i < number_count.size(); ++i) {
		cout << i + 1 << "\t";
		cout << string(number_count[i] / 8, '*') << endl;
	}
	auto end = steady_clock::now();
	//microseconds ms = end - start;
 auto ms = duration_cast<microseconds>(end - start);
	cout << "time : " << ms.count() << endl; 
}
