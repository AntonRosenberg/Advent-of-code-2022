#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int play(char yourMove, char elfMove) {
	int score = 0;

	if (yourMove == 'X') {
		if (elfMove == 'R') {
			score += 3;
		}
		else if (elfMove == 'P') {
			score += 1;
		}
		else {
			score += 2;
		}
	}
	else if (yourMove == 'Y') {
		if (elfMove == 'R') {
			score += 3+1;
		}
		else if (elfMove == 'P') {
			score += 3+2;
		}
		else {
			score += 3+3;
		}
	}
	else if (yourMove == 'Z') {
		if (elfMove == 'R') {
			score += 6+2;
		}
		else if (elfMove == 'P') {
			score += 6+3;
		}
		else {
			score += 6+1;
		}
	}

	return score;
}

int main(int argc, char** argv) {

	string line;
	ifstream infile("C:/Users/anton/OneDrive/Dokument/GitHub/Advent-of-code-2022/Input-files/input2.txt");

	vector <char> elfPlay, yourPlay;
	while (std::getline(infile, line)) {
		if (line[0] == 'A')
			elfPlay.push_back('R');
		else if (line[0] == 'B')
			elfPlay.push_back('P');
		else
			elfPlay.push_back('S');

		yourPlay.push_back(line[2]);
	}
	infile.close();

	int score = 0;
	for (int i = 0; i < yourPlay.size(); i++) {
		score += play(yourPlay[i], elfPlay[i]);
	}
	cout << "Part 2 total score = " << score << endl;


	return 0;
}