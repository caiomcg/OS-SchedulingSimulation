#include "../include/Process.h"

Process::Process(unsigned int arrival, unsigned int span) : arrival(arrival), span(span){}
Process::~Process(){}

unsigned int Process::getArrivalTime() {
	return arrival;
}

unsigned int Process::getProcessSpan() {
	return span;
}
