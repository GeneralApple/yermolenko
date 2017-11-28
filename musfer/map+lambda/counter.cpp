#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>



using namespace std;



/*!
 * @brief      Read file and contruct ``map`` of frequencies.
 * Keys are unique symbols, values are number of occurences.
 *
 * @param[in]  fileName  The name of file to read from
 *
 * @return     map of symbol/occurences
 */

map<char, int> counter(string fileName) 
{
	char x;
	map<char, int> frequencies;
	ifstream inFile;

	inFile.open(fileName);
	while (inFile >> x) 
	{
		frequencies[x]++;
	}
	inFile.close();

	return frequencies;
}


/*!
 * @brief      Sort vector of pair by second value in-place
 *
 * @param      v     vector of pairs
 */

void sortSecond(vector< pair<char, int> > & v) {
	auto sortingFunc = [](pair<char, int> x, pair<char, int> y)
	{
		return x.second > y.second;
	};

	sort(v.begin(), v.end(), sortingFunc);
}


/*!
 * @brief      Print vector of pairs
 *
 * @param[in]  v     vector of pairs
 */

void printV(const vector< pair<char, int> > & v) {
	for_each(v.begin(), v.end(), [](pair<char, int> x)
	{
		cout << x.first << " was found " << x.second << " times." << endl;
	});
}

int main()
{
	map<char, int> freqs = counter("input.txt");
	vector< pair<char, int> > freqs_vec(freqs.begin(), freqs.end());
	
	sortSecond(freqs_vec);

	printV(freqs_vec);

    return 0;
}

