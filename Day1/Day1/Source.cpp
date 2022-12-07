// basic file operations
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv){
	
	string line;
	ifstream infile("C:/Users/anton/OneDrive/Dokument/GitHub/Advent-of-code-2022/Input-files/input.txt");
	
	int elf = 0;
	while (std::getline(infile, line))
	{
		if (line.empty()) {
			elf+=1;
		} 
	}
	infile.clear();
	infile.seekg(0, std::ios::beg);
	
	vector <int> elfs(elf+1);
	
	for (int i = 0; i < elf; i++) {
		elfs[i] = 0;
	}

	int elfInd = 0;

	while (std::getline(infile, line))
	{	
		if (line.empty()) {
			elfInd+=1;
		}
		else {
			elfs[elfInd] += stoi(line);
		}	
	}
	infile.close();
	sort(elfs.begin(), elfs.end(), greater<int>());
	
	
	cout <<"Individual max " << elfs[0] << " calories." << endl;
	
	cout << "Max three total " << elfs[0] + elfs[1] + elfs[2] << endl;
	return 0;
}
