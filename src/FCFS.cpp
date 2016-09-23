#include "../include/FCFS.h"

FCFS::FCFS(std::vector<Process> processes) : _queue(processes), _currentArrival(0), _cpuCycle(0), _avgResponse(0), _avgReturn(0), _avgWait(0) {
	_amountOfProcesses = processes.size();
}

FCFS::~FCFS() {}

void FCFS::calculateAverageTime() {
	unsigned int sum = 0;
	unsigned int duration;
	unsigned int clock = _queue[0].getArrivalTime();

	for (int i = 0; i < _queue.size(); i++) {
		sum  += clock - _queue[i].getArrivalTime();
		clock += _queue[i].getProcessSpan();
		duration += _queue[i].getProcessSpan();
	}
	_avgResponse = sum / (double)_queue.size();
	_avgReturn   = duration / (double)_queue.size() + _avgResponse;
	_avgWait     = _avgResponse; 
}

void FCFS::init() {
	this->calculateAverageTime();
}

double FCFS::getAverageResponse() {
	return this->_avgResponse;
}

double FCFS::getAverageReturn() {
	return this->_avgReturn;
}

double FCFS::getAverageWait() {
	return this->_avgWait;
}

std::string FCFS::toString() {
	std::stringstream ss;
	ss << "FCFS " << std::fixed << std::setprecision(1) << _avgReturn << " " << _avgResponse << " " << _avgWait;
	return ss.str();
}