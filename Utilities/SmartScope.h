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
// sample(double data):
//   data is pushed to the history, and displayed on the graph when triggered
// trigger(length, offset):
//   length = number of data points to display
//   offset = trigger forward (positive) or backward (negative) in time from now
//   When you call trigger(), <length> data points are displayed,
//     starting from now plus or minus <offset> samples
// 
// Typical usage:
// - create a SmartScope object, giving it a keyName and (optionally) histSize:
//   SmartScope myScope = new SmartScope("My Data", 100);
// - iteratively call sample(), ideally at a regular interval:
//   myScope->sample(someValue);
// - When you want to display a value, issue a trigger:
//   myScope->trigger(150, -10);    // show 150 samples, starting 10 samples ago


#include "SmartDashboard/SmartDashboard.h"
#include <string>
#include <list>

using namespace std;

class SmartScope {
public:
	SmartScope(string keyName, unsigned int histSize);
	virtual ~SmartScope();
	
	void histSize(unsigned int histSize);	// change the history size
	
	void sample(double data);				// push data to history
	void trigger(int length, int offset=0);	// trigger and display
	
	bool triggerActive();					// true if a trigger is in progress
	void clearTrigger();					// clear an active trigger
	
private:
	string m_keyName;			// SmartDahsboard keyName
	unsigned int m_histSize;	// max number of data samples to keep
	list<double> m_history;		// data history buffer
	int m_triggerCount;			// number of samples remaining to be displayed
	int m_triggerOffset;		// amount of time to wait before displaying
};

#endif
