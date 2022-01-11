#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <conio.h>

using namespace std;
class MyTime
{
public:
	tm start;
	tm end;
	int duration;
	int interrupt;
	int sum;

	MyTime(){
		start.tm_hour = 0;
		start.tm_min = 0;
		start.tm_sec = 0;
		end.tm_hour = 0;
		end.tm_min = 0;
		end.tm_sec = 0;
		duration = 0;
		interrupt = 0;
		sum = 0;
	}
	MyTime(int hs, int ms, int he, int me, int d, int i, int s) {
		start.tm_hour = hs;
		start.tm_min = ms;
		start.tm_sec = 0;
		end.tm_hour = he;
		end.tm_min = me;
		end.tm_sec = 0;
		duration = d;
		interrupt = i;
		sum = s;
	}
	void Input();
};
vector<string> splitString(string src, string token);
void ReadFile(vector<MyTime>& config);
void WriteFile(const vector<MyTime> config);
