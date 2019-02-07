#include "pch.h"
#include <iostream>
#include "game_state.h"
#include "game_reader.h"
#include "grid.h"

int main() {

	game_reader reader = game_reader();

	game_state *state = reader.read_cells("C:\\Users\\mohan\\source\\repos\\ConsoleApplication9\\ConsoleApplication9\\game.txt");

	grid game = grid(state);
	game.run_iterations();
	game.print_current_state();

	return 0;
}