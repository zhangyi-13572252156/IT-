#include<vector>
#include<iostream>

int getDigitSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

bool check(int threshold, int rows, int cols, int row, int col, std::vector<bool>& visited)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols && 
		getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row*cols + col])
		return true;
	return false;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, std::vector<bool>& visited)
{
	int count = 0;
	if (check(threshold, rows, cols, row, col, visited))
	{
		visited[row*cols + col] = true;
		count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
			+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
	}
	return count;
}

int movingCount(int threshold, int rows, int cols)
{
	if (threshold < 0 || rows <= 0 || cols <= 0)
		return 0;
	std::vector<bool> visited(false, rows*cols);
	
	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

	return count;
}

