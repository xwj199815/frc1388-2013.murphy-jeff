#ifndef SMARTSCOPE_H
#define SMARTSCOPE_H

// The SmartScope class is a data acquisition module which displays data
// on the SmartDashboard, based on a trigger condition.
// It can be used to display a graph similar to what you'd see on an 
// oscilloscope.

// Usage:
// constructor:
//   keyName = SmartDashboard keyName
//   histSize = amount of history to keep
// putData(double data):
//   data is pushed to the history, and displayed on the graph when triggered
// trigger(length, offset):
//   length = number of data points to display
//   offset = trigger forward (positive) or backward (negative) in time from now
//   When you call trigger(), <length> data points are displayed,
//     starting from now plus or minus <offset> samples


#include "SmartDashboard/SmartDashboard.h"
#include <string>
#include <list>

using namespace std;

class SmartScope {
public:
	SmartScope(string keyName, unsigned int histSize);
	virtual ~SmartScope();
	
	void histSize(unsigned int histSize);	// change the history size
	
	void putData(double data);				// push data to history
	void trigger(int length, int offset=0);	// trigger and display
	void clearTrigger();					// clear an active trigger
	
private:
	string m_keyName;			// SmartDahsboard keyName
	unsigned int m_histSize;	// max number of data samples to keep
	list<double> m_history;		// data history
	int m_triggerCount;			// number of samples remaining to be displayed
	int m_triggerOffset;		// amount of time to wait before displaying
};

#endif
