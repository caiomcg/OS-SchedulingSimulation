#include "../include/SJF.h"


SJF::SJF(std::vector<Process> processes) : _queue(processes), _avgResponse(0), _avgReturn(0), _avgWait(0) {
	_amountOfProcesses = processes.size();
}

SJF::~SJF() {}

bool SJF::sortPredicate(const Process& first, const Process& second){  
 	if (first.getArrivalTime() == second.getArrivalTime()) {
 		return first.getProcessSpan() < second.getProcessSpan();
 	}

	return first.getArrivalTime() < second.getArrivalTime();
 }
 
 void SJF::sortVector() {
 	std::sort(_queue.begin(), _queue.end(), SJF::sortPredicate);
 }

void SJF::calculateAverageTime(){
	unsigned int sum = 0;
	unsigned int duration;
	unsigned int clock = _queue[0].getArrivalTime();

	for (int i = 0; i < _queue.size(); i++) {
		sum  += clock - _queue[i].getArrivalTime();
		clock += _queue[i].getProcessSpan();
		duration += _queue[i].getProcessSpan();
	}
}

void SJF::init() {
	this->sortVector();
	Utils::print(_queue);
}
	
double SJF::getAverageResponse() {
	return this->_avgResponse;
}

double SJF::getAverageReturn() {
	return this->_avgReturn;
}

double SJF::getAverageWait() {
	return this->_avgWait;
}

std::string SJF::toString() {
	std::stringstream ss;
	ss << "SJF " << std::fixed << std::setprecision(1) << _avgReturn << " " << _avgResponse << " " << _avgWait;
	return ss.str();
}