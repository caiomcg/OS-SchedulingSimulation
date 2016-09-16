#include "../include/FCFS.h"

FCFS::FCFS(std::vector<Process> processes) : _queue(processes), _currentArrival(0), _cpuCycle(0), _avgResponse(0), _avgReturn(0), _avgWait(0) {
	_amountOfProcesses = processes.size();
}

FCFS::~FCFS() {}

bool FCFS::sortPredicate(const Process& first, const Process& second){ 
	if (first.getArrivalTime() == second.getArrivalTime()) {
		return first.getProgramCounter() > second.getProgramCounter();
	}

	return first.getArrivalTime() < second.getArrivalTime();
}

void FCFS::sortVector() {
	std::sort(_queue.begin(), _queue.end(), FCFS::sortPredicate);
}

void FCFS::calculateAverageResponseTime() {
	unsigned int sum = 0;
	unsigned int temp = 0;

	for (int i = 0; i < this->_queue.size() - 1; i++) {
		sum  += (this->_queue[i].getProcessSpan() + temp);
		temp += this->_queue[i].getProcessSpan();
	}

	this->_avgResponse = sum / (double)this->_queue.size();
}

void FCFS::init() {
	this->sortVector();
	this->calculateAverageResponseTime();
}

double FCFS::getAverageResponse() {
	return this->_avgResponse;
}