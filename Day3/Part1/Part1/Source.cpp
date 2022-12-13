#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>


using namespace std;

int main(int argc, char** argv) {
	auto start = chrono::steady_clock::now();
	string line;
	ifstream infile("C:/Users/anton/OneDrive/Dokument/GitHub/Advent-of-code-2022/Input-files/input3.txt");
	
	size_t line_count = 0;
	while (std::getline(infile, line))
	{
		line_count += 1;
	}
	
	infile.clear();
	infile.seekg(0, ios::beg);

	vector <char> rucksack1Tmp, rucksack2Tmp;
	vector <string> rucksack1(line_count+1), rucksack2(line_count+1);

	for (int i = 0; i < line_count + 1; i++) {
		rucksack1[i] = "";
		rucksack2[i] = "";
	}

	int iteration = 0;
	int j;
	
	while (std::getline(infile, line)) {
		int middle = line.size() / 2;
		
		for (int i = 0; i < middle; i++) {
			j = i + middle;
			rucksack1Tmp.push_back(line[i]);
			rucksack2Tmp.push_back(line[j]);
			
			rucksack1[iteration] += rucksack1Tmp[i];
			rucksack2[iteration] += rucksack2Tmp[i];

		}
		rucksack1Tmp.clear();
		rucksack2Tmp.clear();

		iteration += 1;
	}

	infile.close();

	string alphabeth = "abcdefghijklmnopqrstuvwxyz";
	string ALPHABETH = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	vector <int> priorities(2 * alphabeth.size());
	

	for (int i = 0; i < priorities.size(); i++) {
		priorities[i] = 0;
	}
	for (int i = 0; i < rucksack2.size(); i++) {
		string foundCharacters = "";
		for (int j = 0; j < rucksack2[i].size(); j++) {
			string::difference_type n = count(rucksack1[i].begin(), rucksack1[i].end(), rucksack2[i][j]);
			if (n != 0) {
				if (foundCharacters.find(rucksack2[i][j])== string::npos) {
					foundCharacters+=rucksack2[i][j];
					size_t found = alphabeth.find(rucksack2[i][j]);
					if (found == string::npos) {
						found = ALPHABETH.find(rucksack2[i][j]);
						if (found != string::npos) {
							priorities[found + 26] += (found + 1 + 26);
						}
					}
					else {
						priorities[found] += (found + 1);
					}

				}
				
			}
			
		}
	}

	int prioritySum = 0;
	for (int j = 0; j < priorities.size(); j++) {
		if (j < 26) {
			cout << priorities[j] << " " << alphabeth[j] << endl;
		}
		else {
			cout << priorities[j] << " " << ALPHABETH[j-26] << endl;
		}
		prioritySum += priorities[j];
	}
	cout << prioritySum << endl;
	auto end = chrono::steady_clock::now();
	cout << "Elapsed time in milliseconds: "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
	return 0;
}