#ifndef TIMER_H
#define TIMER_H

#include <string>
using namespace std;



class CTimer {
	public:
		CTimer():c_min(0), c_sec(0), c_msec(0)
		{}
		void addTime();
		void resetTime();
		string printTime();
		int getMsec();

	private:
		int c_min;
		int c_sec;
		int c_msec;
		int c_playtime;
};






#endif