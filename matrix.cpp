// Multiply a vector by a matrix
template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
vector <T> multiply(vector<vector <T>> left, vector <T> right) {
	assert(left.size() == right.size());
	vector <T> product(left.size());
	for (int i = 0; i < left.size(); ++i) {
		for (int j = 0; j < left.size(); ++j) {
			product[j] += left[i][j] * right[i];
		}
	}
	return product;
}

// Multiply two vectors
template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
vector<vector <T>> multiply(vector<vector <T>> left, vector<vector <T>> right) {
	assert(left.size() == right.size() && left[0].size() == right[0].size());
	vector<vector <T>> product(left.size(), vector<T>(left[0].size()));
	for (int i = 0; i < left.size(); ++i) {
		for (int j = 0; j < left.size(); ++j) {
			for (int k = 0; k < left.size(); ++k) {
				product[i][j] += left[i][k] * right[k][j];
			}
		}
	}
	return product;
}

// Dot notation
template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
vector <T> operator*(vector<vector <T>> left, vector <T> right) {
	return multiply(left, right);
}
