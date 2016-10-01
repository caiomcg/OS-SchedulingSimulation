#include "../include/SJF.h"


SJF::SJF(std::vector<Process> processes) : _queue(processes), _avgResponse(0), _avgReturn(0), _avgWait(0) {
	_amountOfProcesses = processes.size();
}

SJF::~SJF() {}

bool SJF::sortPredicate(const Process& first, const Process& second){  
	return first.getProcessSpan() < second.getProcessSpan();
}

bool SJF::initialSortPredicate(const Process& first, const Process& second) {
 	if (first.getArrivalTime() == second.getArrivalTime()) {
 		return first.getProcessSpan() < second.getProcessSpan();
 	}

	return first.getArrivalTime() < second.getArrivalTime();
}
 
void SJF::sortVector(std::vector<Process>& vector, unsigned int offset) {
	std::sort(vector.begin() + offset, vector.end(), SJF::sortPredicate);
}

void SJF::removeFromVector(std::vector<Process>& vector, unsigned int distance) {
	vector.erase(vector.begin(), vector.begin() + distance);
}

void SJF::calculateAverageTime(){
	unsigned int sum      = 0;
	unsigned int running  = 0;
	unsigned int pushed   = 0;
	unsigned int duration = 0;
	unsigned int clock    = _queue[0].getArrivalTime();

	while (!_queue.empty()) {
		pushed = 0;

		for (int i = 0; i < _queue.size(); i++) {
			if (_queue[i].getArrivalTime() == clock) {
				_waiting.push_back(_queue[i]);
				pushed++;
			} else {
				break;
			}	
		}

		if (clock > _waiting[running].getProcessSpan()) {
			running++;
		}

		this->removeFromVector(_queue, pushed);
		this->sortVector(_waiting, running + 1);

		clock++;
	}

	clock = _waiting[0].getArrivalTime(); //Restarts the clock

	for (int i = 0; i < _waiting.size(); i++) {
		sum  += clock - _waiting[i].getArrivalTime();
		clock += _waiting[i].getProcessSpan();
		duration += _waiting[i].getProcessSpan();
	}
	_avgResponse = sum / (double)_waiting.size();
	_avgReturn   = duration / (double)_waiting.size() + _avgResponse;
	_avgWait     = _avgResponse;
}

void SJF::init() {
	std::sort(_queue.begin(), _queue.end(), SJF::initialSortPredicate); //CHANGE TO FUNCTION
	this->calculateAverageTime();
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