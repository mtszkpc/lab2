

#pragma once

#include <iomanip>

using namespace std;

class TimeSpan {
public:
	unsigned int hours;
	unsigned int minutes; 	// [0 .. 59]
	unsigned int seconds; // [0 .. 59] 
	TimeSpan(unsigned int seconds) {
		this->seconds = seconds;
		minutes = seconds / 60;
		hours = minutes / 60;
		TimeSpan::seconds = seconds % 60;
		minutes = minutes % 60;
	}
	int getseconds() {
		return seconds;
	}
	int getminutes() {
		return minutes;
	}
	int gethours() {
		return hours;
	}
	void print() {
		cout << hours << ":" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << endl;
	}

};

