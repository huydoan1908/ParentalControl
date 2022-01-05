#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;
class MyTime
{
public:
	tm start;
	tm end;
	int duration;
	int interrupt;
	int sum;

	MyTime(){}
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
};
vector<string> splitString(string src, string token);
void ReadFile(vector<MyTime>& config);
