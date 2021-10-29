vector <int> separate(string line, char separator = ',') {
	vector <int> ans;
	string value;
	for (auto c : line) {
		if (c == separator) {
			ans.push_back(stoi(value));
			value.clear();
		}
		else {
			value += c;
		}
	}
	ans.push_back(stoi(value));
	return ans;
}

