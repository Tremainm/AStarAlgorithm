#include <vector>
#include <iostream>

#include "AStarAlgorithm.h"

void AStarAlgorithm::AStarGrid()
{
	std::vector<std::vector<int>> grid = {
		{0, 0, 0, 0},
		{0, 1, 0, 1},
		{0, 0, 1, 1},
		{1, 0, 0, 0}
	};

	for (auto const& row : grid)
	{
		for (int cell : row)
		{
			std::cout << (cell == 0 ? '.' : '#') << ' ';
		}
		std::cout << '\n';
	}
		
}
