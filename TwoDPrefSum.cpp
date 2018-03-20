//To build one, just pass in a vector. To query, specify the row start and end points and column start and end points
class TwoDPrefSum {
	vector <vector <ll>> matx;
	public:
	TwoDPrefSum(vector <vector <ll>>& matrix) {
		matx = matrix;
		//The vector passed in should be rectangular and nonzero in size
		for (int i = 0; i < matrix[0].size(); ++i)
			for (int j = 0; j < matrix.size(); ++j) {
				matx[i][j] += (i == 0 ? 0 : matx[i - 1][j]) + (j == 0 ? 0 : matx[i][j - 1]) - (i == 0 || j == 0 ? 0 : matx[i - 1][j - 1]);
			}
	}
	//Principle of inclusion-exclusion
	ll query(int row1, int row2, int col1, int col2) {
		return matx[row2][col2] - (row1 == 0 ? 0 : matx[row1 - 1][col2]) - (col1 == 0 ? 0 : matx[row2][col1 - 1]) + (row1 == 0 || col1 == 0 ? 0 : matx[row1 - 1][col1 - 1]);
	}
};
