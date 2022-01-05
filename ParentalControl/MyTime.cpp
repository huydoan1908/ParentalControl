#include "MyTime.h"

void ReadFile(vector<MyTime>& config) {
	fstream file;
	file.open("config.txt", ios::in);
	if (file.is_open()) {
		while (!file.eof()) {
			string line;
			MyTime time;
			int hs, ms, he, me, d, in, s;
			hs = ms = he = me = d = in = s = 0;
			getline(file, line);
			vector<string> split = splitString(line, " ");
			for (int i = 0; i < split.size(); i++) {
				if (split[i][0] == 'F') {
					split[i] = split[i].substr(1);
					int pos = split[i].find(':');
					hs = stoi(split[i].substr(0, pos));
					ms = stoi(split[i].substr(pos + 1));
				}
				else if (split[i][0] == 'T') {
					split[i] = split[i].substr(1);
					int pos = split[i].find(':');
					he = stoi(split[i].substr(0, pos));
					me = stoi(split[i].substr(pos + 1));
					d = s = (he - hs) * 60 + (me - ms);
				}
				else if (split[i][0] == 'D') {
					d = stoi(split[i].substr(1));
				}
				else if (split[i][0] == 'I') {
					in = stoi(split[i].substr(1));
				}
				else if (split[i][0] == 'S') {
					s = stoi(split[i].substr(1));
					if (d == 0 || d == s)
						d = s;
				}
			}
			time = MyTime(hs, ms, he, me, d, in, s);
			config.push_back(time);
		}
	}
}

vector<string> splitString(string src, string token) {
	vector<string> result;
	int start = 0;
	int end = src.find(token);
	while (end != -1) {
		result.push_back(src.substr(start, end - start));
		start = end + 1;
		end = src.find(token, start);
	}
	result.push_back(src.substr(start, end - start));
	return result;
}