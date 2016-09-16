#include "../include/Process.h"

Process::Process(unsigned int arrival, unsigned int span) : _arrival(arrival), _span(span){}
Process::~Process(){}

unsigned int Process::getArrivalTime() const {
	return _arrival;
}

unsigned int Process::getProcessSpan() const {
	return _span;
}
