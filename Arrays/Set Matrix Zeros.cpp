#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	bool colZero = false;
	int i, j;
	int rows = matrix.size();
	int cols = matrix[0].size();

	for(i = 0; i < rows; i++){
		if(matrix[i][0] == 0){
			colZero = true;
		}

		for(j = 1; j < cols; j++){
			if(matrix[i][j] == 0){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for(i = (rows - 1); i > -1; i--){
		for(j = (cols - 1); j > 0; j--){
			if((matrix[i][0] == 0) || (matrix[0][j] == 0)){
				matrix[i][j] = 0;
			}
		}
		
		if(colZero){
			matrix[i][0] = 0;
		}
	}
}
