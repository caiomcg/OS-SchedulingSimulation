#include "../include/FCFS.h"

FCFS::FCFS(std::vector<Process> processes) : _queue(processes), _currentArrival(0), _cpuCycle(0), _avgResponse(0), _avgReturn(0), _avgWait(0) {
	_amountOfProcesses = processes.size();
}

FCFS::~FCFS() {}

void FCFS::calculateAverageResponseTime() {
	unsigned int sum = 0;
	unsigned int clock = this->_queue[0].getArrivalTime();

	for (int i = 0; i < this->_queue.size(); i++) {
		sum  += clock - this->_queue[i].getArrivalTime();
		clock += this->_queue[i].getProcessSpan();
	}

	this->_avgResponse = sum / (double)this->_queue.size();
}

void FCFS::init() {
	this->calculateAverageResponseTime();
}

double FCFS::getAverageResponse() {
	return this->_avgResponse;
}

std::string FCFS::toString() {
	std::stringstream ss;
	ss << "FCFS " << std::fixed << std::setprecision(1) << _avgReturn << " " << _avgResponse << " " << _avgWait;
	return ss.str();
}