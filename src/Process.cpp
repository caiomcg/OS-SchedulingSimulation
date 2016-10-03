#include "../include/Process.h"

Process::Process(unsigned int arrival, unsigned int span, unsigned int programCounter) : _arrival(arrival), _span(span), _programCounter(programCounter), _run(true) {}
Process::~Process(){}

unsigned int Process::getArrivalTime() const {
	return _arrival; // Return the process arrival time
}

unsigned int Process::getProcessSpan() const {
	return _span; // Return the process time span.
}

void Process::setProcessSpan(const unsigned int span) {
	_span = span;
}

unsigned int Process::getProgramCounter() const {
	return _programCounter; // Return the process counter.
}

bool Process::getRun() const {
	return _run;
}
void Process::setRun(const bool run){
	_run = run;
}