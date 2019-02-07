#pragma once

class game_state {
private:
	int size;
	int **current_state;
	int iteration;

public:
	game_state(int size, int iteration, int **current_state);

	~game_state();

	int get_size();

	int **get_current_state();

	int get_iteration();
};


