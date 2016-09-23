#include "../include/SJF.h"


SJF::SJF(std::vector<Process> processes) : _queue(processes), _avgResponse(0), _avgReturn(0), _avgWait(0) {
	_amountOfProcesses = processes.size();
}
SJF::~SJF() {}

void SJF::calculateAverageTime(){

}

void SJF::init() {
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
	ss << "SJF " << _avgResponse < " " << _avgReturn << " " << _avgWait;
	return ss.str();
}