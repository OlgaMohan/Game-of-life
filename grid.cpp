#include "pch.h"
#include <iostream>
#include "grid.h"
#include "utility.h"

using namespace std;

const int grid::POSITIONS[8][2] = {
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0,  1},
		{1,  1},
		{1,  0},
		{1,  -1},
		{0,  -1}
};

grid::grid(game_state *state) {
	this->size = state->get_size();
	this->iteration = state->get_iteration();
	this->current_state = state->get_current_state();
	this->next_state = utility::allocate_grid(this->size);
}

grid::~grid() = default;

void grid::print_current_state() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << current_state[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void grid::run_iterations() {
	for (int i = 0; i < iteration; ++i) {
		run_next_iteration();
		swap_states();
	}
}

void grid::run_next_iteration() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {

			int current_cell = current_state[i][j];
			int count = neighbour_count(i, j);
			if (current_cell == 1) {
				if (count < 2) {
					next_state[i][j] = 0;
				}
				else if (count > 3) {
					next_state[i][j] = 0;
				}
				else {
					next_state[i][j] = 1;
				}
			}
			else if (current_cell == 0 && count == 3) {
				next_state[i][j] = 1;
			}
		}
	}
}

int grid::neighbour_count(int x, int y) {
	int count = 0;

	for (int i = 0; i < 8; ++i) {
		int tempX = x + grid::POSITIONS[i][0];
		int tempY = y - grid::POSITIONS[i][1];
		if (valid_range_check(tempX) && valid_range_check(tempY) && current_state[tempX][tempY] == 1) {
			count++;
		}
	}
	return count;
}

void grid::swap_states() {
	int **temp = this->current_state;
	this->current_state = this->next_state;
	this->next_state = temp;
}

bool grid::valid_range_check(int index) {
	return 0 <= index && index < size;
}

