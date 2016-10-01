#include "../include/FCFS.h"

FCFS::FCFS(std::vector<Process> processes) : _queue(processes), _avgResponse(0), _avgReturn(0), _avgWait(0) {
	_amountOfProcesses = processes.size(); // Initialize amountOfProcesses with the vector size.
}

FCFS::~FCFS() {}

void FCFS::calculateAverageTime() {
	unsigned int wait     = 0; // Store the sum of the waiting time for all processes.
	unsigned int duration = 0; // Store the sum of the duration time for all processes.
	unsigned int clock    = _queue[0].getArrivalTime(); //Stores the current clock time.

	for (int i = 0; i < _queue.size(); i++) { //loops through the processes queue.
		wait  += clock - _queue[i].getArrivalTime(); // Add the waiting time of a process.
		clock += _queue[i].getProcessSpan();         // Update the clock.
		duration += _queue[i].getProcessSpan();      // Update the total duration
	}
	_avgResponse = wait / (double)_amountOfProcesses; // Calculate the average response time: ART = (process from 1 to n wait) / amount of processes 
	_avgReturn   = duration / (double)_amountOfProcesses + _avgResponse; // Calculate the average return time: ART = processes span / amount of process + ART(Average response time)
	_avgWait     = _avgResponse; // Calculate the average wait time AWT = ART(Average Response time)
}

void FCFS::init() {
	this->calculateAverageTime(); // Call the member function that runs the algorithm.
}

double FCFS::getAverageResponse() const {
	return this->_avgResponse; // Return the Average Response Time.
}

double FCFS::getAverageReturn() const {
	return this->_avgReturn; // Return the Average Return Time.
}

double FCFS::getAverageWait() const {
	return this->_avgWait; // Return the Average Wait Time.
}

std::string FCFS::toString() const {
	std::stringstream ss; // Creates a string stream.
	ss << "FCFS " << std::fixed << std::setprecision(1) << _avgReturn << " " << _avgResponse << " " << _avgWait; // Format the string.
	return ss.str(); // Return the strin.
}