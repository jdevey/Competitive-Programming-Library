#define DEBUG
#ifndef DEBUG
#define debug(args...)
#else
#define debug(args...) print(args)
#endif

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, pair <T1, T2> const &p) { 
    return os << '<' << p.first << ", " << p.second << '>';
}

template <typename T>
void print(vector <T> vec) {
	for (auto elem : vec) {
		cout << elem << ' ';
	}
	cout << endl;
}

void print(int a[], int sz) {
	for (size_t i = 0; i < sz; ++i) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

template <typename T>
void print(T value) {
    std::cout << value << endl;
}

template <typename T, typename... Args>
void print(T value, Args... values) {
    std::cout << value << ' ';
    print(values...);
}

