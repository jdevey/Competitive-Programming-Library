// Print a pair
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, pair <T1, T2> const &p) { 
    return os << '<' << p.first << ", " << p.second << '>';
}

// Print a single value
template <typename T>
void print(T value) {
    std::cout << value << endl;
}

// Print several values
template <typename T, typename... Args>
void print(T value, Args... values) {
    std::cout << value << ' ';
    print(values...);
}

// Print a vector
template <typename T>
void print(vector <T> vec) {
	for (auto elem : vec) {
		cout << elem << ' ';
	}
	cout << endl;
}

