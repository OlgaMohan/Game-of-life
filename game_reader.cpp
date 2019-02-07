#include "pch.h"
#include "game_reader.h"
#include "utility.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

game_state *game_reader::read_cells(string file_location) {

	int iteration = 0;
	int size = 0;
	int **state = nullptr;

	string line;

	ifstream inFile;
	inFile.open(file_location);
	if (inFile.fail()) {
		cerr << "File cannot be found or opened" << endl;
		exit(1);
	}

	if (inFile.is_open()) {
		cout << "File opened successfully!" << endl;


		getline(inFile, line);
		iteration = stoi(line);
		getline(inFile, line);
		size = stoi(line);

		state = utility::allocate_grid(size);

		for (int i = 0; i < size; i++) {
			getline(inFile, line);

			istringstream iss(line);
			vector<string> results(istream_iterator<string>{iss}, istream_iterator<string>());

			for (int j = 0; j < size; j++) {
				state[i][j] = stoi(results.at(j));
			}
		}
		inFile.close();
	}
	return new game_state(size, iteration, state);
}

game_reader::game_reader() = default;
