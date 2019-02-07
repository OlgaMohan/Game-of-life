#pragma once
#include "game_state.h"
#include <string>

using namespace std;

class game_reader {

public:
	game_reader();

	game_state *read_cells(string file_location);
};