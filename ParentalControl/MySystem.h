#pragma once
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class MySystem
{
public:
	void shutdownLinux() {
		system("shutdown -P now");
	}

	void shutdownWindow() {
		system("c:\\windows\\system32\\shutdown /s");
	}

	void restartWindow() {
		system("c:\\windows\\system32\\shutdown /r");
	}
};
