#include "pch.h"
#include "game_state.h"

game_state::game_state(int size, int iteration, int **current_state) {
	this->size = size;
	this->iteration = iteration;
	this->current_state = current_state;
}

game_state::~game_state() = default;

int game_state::get_size() {
	return this->size;
}

int **game_state::get_current_state() {
	return this->current_state;
}

int game_state::get_iteration() {
	return this->iteration;
}

