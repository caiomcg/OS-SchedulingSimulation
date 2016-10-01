#include "../include/Process.h"

Process::Process(unsigned int arrival, unsigned int span, unsigned int programCounter) : _arrival(arrival), _span(span), _programCounter(programCounter) {}
Process::~Process(){}

unsigned int Process::getArrivalTime() const {
	return _arrival; // Return the process arrival time
}

unsigned int Process::getProcessSpan() const {
	return _span; // Return the process time span.
}

unsigned int Process::getProgramCounter() const {
	return _programCounter; // Return the process counter.
}
