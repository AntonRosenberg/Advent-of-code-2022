#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int play(char yourMove, char elfMove) {
	int score = 0;

	if (yourMove == 'R') {
		score += 1;
		if (yourMove == elfMove) {
			score += 3;
		}
		else if (elfMove == 'S') {
			score += 6;
		}
	}
	else if (yourMove == 'P') {
		score += 2;
		if (yourMove == elfMove) {
			score += 3;
		}
		else if (elfMove == 'R') {
			score += 6;
		}
	}
	else if (yourMove=='S') {
		score += 3;
		if (yourMove == elfMove) {
			score += 3;
		}
		else if (elfMove == 'P') {
			score += 6;
		}
	}

	return score;
}

int main(int argc, char** argv) {

	string line;
	ifstream infile("C:/Users/anton/OneDrive/Dokument/GitHub/Advent-of-code-2022/Input-files/input2.txt");

	vector <char> elfPlay, yourPlay;
	while (std::getline(infile, line)){
		if (line[0]=='A')
			elfPlay.push_back('R');
		else if (line[0]=='B')
			elfPlay.push_back('P');
		else
			elfPlay.push_back('S');

		if (line[2] == 'X')
			yourPlay.push_back('R');
		else if (line[2] == 'Y')
			yourPlay.push_back('P');
		else
			yourPlay.push_back('S');
	}
	infile.close();
	
	int score = 0;
	for (int i = 0; i < yourPlay.size(); i++) {
		score += play(yourPlay[i], elfPlay[i]);
	}
	cout << "Part 1 total score = " << score << endl;


	return 0;
}