#pragma once

#include "game_state.h"

class grid {
private:
	int size;
	int **current_state;
	int **next_state;
	int iteration;
	static int const POSITIONS[8][2];

	void swap_states();

	int neighbour_count(int x, int y);

	void run_next_iteration();

	bool valid_range_check(int index);

public:
	explicit grid(game_state *state);

	~grid();

	void print_current_state();

	void run_iterations();
};

