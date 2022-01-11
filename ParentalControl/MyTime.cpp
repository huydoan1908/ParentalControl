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
					if (d == 0 || d == s)
						d = s = stoi(split[i].substr(1));
					else
						s = stoi(split[i].substr(1));
				}
			}
			time = MyTime(hs, ms, he, me, d, in, s);
			config.push_back(time);
		}
		file.close();
	}
}

void WriteFile(const vector<MyTime> config)
{
	fstream file;
	file.open("config.txt", ios::out);
	if (file.is_open()) {
		for (int i = 0; i < config.size(); i++) {
			file << "F" << config[i].start.tm_hour << ":" << config[i].start.tm_min
				<< " T" << config[i].end.tm_hour << ":" << config[i].end.tm_min;
			if (config[i].duration != 0)
				file << " D" << config[i].duration;
			if (config[i].interrupt != 0)
				file << " I" << config[i].interrupt;
			if (config[i].sum != 0)
				file << " S" << config[i].sum;
			file << "\n";
		}
		file.close();
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

void MyTime::Input()
{
	cout << "Input start hour: ";
	cin >> start.tm_hour;
	cout << "Input start minute: ";
	cin >> start.tm_min;
	cout << "Input end hour: ";
	cin >> end.tm_hour;
	cout << "Input end minute: ";
	cin >> end.tm_min;
	cin.ignore();
	duration = sum = (end.tm_hour - start.tm_hour) * 60 + end.tm_min - start.tm_min;
	cout << "Do you want to input duration time (Default is total time)\nESC to skip. Enter to continue\n";
	if (_getch() != 27) {
		cout << "Input duration time: ";
		cin >> duration;
	}
	cout << "Do you want to input interruption time (Default is 0)\nESC to skip. Enter to continue\n";
	if (_getch() != 27) {
		cout << "Input interruption time: ";
		cin >> interrupt;
	}
	cout << "Do you want to input total time.\nESC to skip. Enter to continue\n";
	if (_getch() != 27) {
		cout << "Input total time: ";
		if (sum == duration || duration == 0) {
			cin >> sum;
			duration = sum;
		}
		else
			cin >> sum;
	}
}
