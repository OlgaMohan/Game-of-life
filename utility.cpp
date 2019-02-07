#include "pch.h"
#include "utility.h"

utility::utility() = default;

utility::~utility() = default;

int **utility::allocate_grid(int size) {
	int **grid = new int *[size];
	for (int i = 0; i < size; ++i) {
		grid[i] = new int[size];
		for (int j = 0; j < size; j++) {
			grid[i][j] = 0;
		}
	}

	return grid;
}
