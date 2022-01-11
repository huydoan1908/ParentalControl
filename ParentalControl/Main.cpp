#include <iostream>
#include "MySystem.h"
#include "MyTime.h"

int main() {
	/*MySystem ms;
	ms.shutdownWindow();*/
	vector<MyTime> config;
	ReadFile(config);
	MyTime a;
	a.Input();
	config.push_back(a);
	WriteFile(config);
	return 0;
}