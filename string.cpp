vector <string> separate(string line, char separator = ',') {
	vector <string> ans;
	string value;
	for (auto it = line.begin(); it != line.end(); ++it) {
		if (*it == separator || next(it) == line.end()) {
			if (!*it.empty()) {
				ans.push_back(string(value.begin() + 1, value.end() - (next(it) != line.end())));
				value.clear();
			}
		}
		else {
			value += *it;
		}
	}
	return ans;
}

