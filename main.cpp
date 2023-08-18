// Compile command: g++ -std=c++20 -o main main.cpp
// Run command: ./main

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int levenshtein(string, string);
// vector<string> split(string, char);

int main(int argc, char* argv[]) {
    string word1;
    string word2;

    cout << "Input word 1: ";
    cin >> word1;

    cout << "Input word 2: ";
    cin >> word2;

	cout << "L-distance: " << (levenshtein(word1, word2)) << endl;
    return 0;
}

int levenshtein(string a, string b) {
	if(a.size() == 0)
		return b.size();
	if(b.size() == 0)
		return a.size();
	if (a[0] == b[0])
		return levenshtein(a.substr(1), b.substr(1));

	vector<int> list = {
		levenshtein(a.substr(1), b),
		levenshtein(a, b.substr(1)),
		levenshtein(a.substr(1), b.substr(1))
	};

	int min = *min_element(list.begin(), list.end());
	return (1 + min);
}

// string splitting by delimeter
// vector<string> split(string str, char delimiter) {
//     vector<string> internal; 
//     istringstream ss(str); // Turn the string into a stream. 
//     string tok; 
//     while(getline(ss, tok, delimiter))
//         internal.push_back(tok);
//     return internal; 
// }