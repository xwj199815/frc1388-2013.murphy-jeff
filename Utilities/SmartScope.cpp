// SmartScope: Display a graph of data on the SmartDashboard in the style
// of a digital storage oscilloscope

#include "SmartScope.h"

SmartScope::SmartScope(string keyName, unsigned int histSize) {
	m_keyName = keyName;
	m_histSize = histSize;
}

void SmartScope::histSize(unsigned int histSize) {
	// Change the history size
	m_histSize = histSize;

	// prune history to at most histSize elements:
	while(m_history.size() > m_histSize) {
		m_history.pop_back();
	}
}

void SmartScope::sample(double data) {
	// Add data to history, and print it if a trigger is active
	m_history.push_front(data);
	
	// prune history to at most histSize elements:
	while(m_history.size() > m_histSize) {
		m_history.pop_back();
	}
	
	// print value if we're in a trigger:
	if (m_triggerOffset > 0) {
		// delayed trigger - we're now one sample closer to the trigger
		m_triggerOffset--;
	} else if (m_triggerCount > 0) {
		SmartDashboard::PutNumber(m_keyName, data);
		m_triggerCount--;
	}
}

void SmartScope::trigger(int length, int offset) {
	// block new triggers if a trigger is already active
	if (triggerActive()) {
		return;
	}
	
	// set a trigger, and print history if offset is negative
	m_triggerCount = length;
	m_triggerOffset = offset;

	if (offset < 0) {
		// trigger started in the past; push history to SmartDashboard
		m_triggerOffset = 0;
				
		// iterate back through history "offset" items,
		// or until the end of history - whichever comes first
		list<double>::const_iterator histItr = m_history.begin();
		while ((histItr != m_history.end())
				&& (offset++ < 0)) {
			histItr++;
		}
		// histItr now points at the beggining of the trigger window
		do {
			SmartDashboard::PutNumber(m_keyName, *histItr);
		} while ((histItr--) != m_history.begin());
	}
}

bool SmartScope::triggerActive() {
	// return true if a trigger is in progress
	return ((m_triggerCount != 0) || (m_triggerOffset != 0));
}

void SmartScope::clearTrigger() {
	// clear an active trigger
	m_triggerCount = 0;
	m_triggerOffset = 0;
}

SmartScope::~SmartScope() {

}
