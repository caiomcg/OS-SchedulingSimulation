#include "../include/SJF.h"


SJF::SJF(std::vector<Process> processes) : _queue(processes), _avgResponse(0), _avgReturn(0), _avgWait(0) {}

SJF::~SJF() {}

bool SJF::sortPredicate(const Process& first, const Process& second){  
	return first.getProcessSpan() < second.getProcessSpan(); // Swap elements if the first process time span is smaller than the second.
}

bool SJF::initialSortPredicate(const Process& first, const Process& second) {
 	if (first.getArrivalTime() == second.getArrivalTime()) { // Check if processes have the same arrival time.
 		return first.getProcessSpan() < second.getProcessSpan();  // Swap elements if the first process time span is smaller than the second.
 	}
	return first.getArrivalTime() < second.getArrivalTime(); // Swap elements if the first arrival time is smaller than the second.
}
 
void SJF::sortVector(std::vector<Process>& vector, unsigned int offset, Predicate predicate) {
	if (predicate == sort) { // Check the predicate to be used.
		std::sort(vector.begin() + offset, vector.end(), SJF::sortPredicate); // Sort vectors with predicate: sortPredicate.
	} else {
		std::sort(vector.begin() + offset, vector.end(), SJF::initialSortPredicate); // Sort vectors with predicate: initialSortPredicate.
	}
}

void SJF::removeFromVector(std::vector<Process>& vector, unsigned int distance) {
	vector.erase(vector.begin(), vector.begin() + distance); // Erase a determined amount of elements.
}

void SJF::calculateAverageTime(){
	unsigned int wait     = 0; // Store the sum of the waiting time for all processes.
	unsigned int running  = 0; // Store the current running process.
	unsigned int pushed   = 0; // Store the amount of elements that were pushed to the new queue.
	unsigned int duration = 0; // Store the sum of the duration time for all processes.
	unsigned int clock    = _queue[0].getArrivalTime(); //Stores the current clock time.

	while (!_queue.empty()) { // Runs until the queue is empty
		pushed = 0; // Resets the amount of pushed processes.

		for (int i = 0; i < _queue.size(); i++) { // Loops through the initial queue.
			if (_queue[i].getArrivalTime() == clock) { // Check if the current process have the same arrival time as the clock.
				_waiting.push_back(_queue[i]); //Push the process to the new queue.
				pushed++; // Increments the amount of pushed elements.
			} else {
				break; // Stop pushing element.
			}	
		}

		if (clock > _waiting[running].getProcessSpan()) { // Check if the processe has stopped its execution.
			running++; // Move the execution to a new process.
		}

		this->removeFromVector(_queue, pushed); // Remove the elements that were pushed from the main queue.
		this->sortVector(_waiting, running + 1, sort); // Sort the new queue based on the current running process.

		clock++; // Increments the clock time.
	}

	clock = _waiting[0].getArrivalTime(); // Restarts the clock.

	for (int i = 0; i < _waiting.size(); i++) { // Loop through the new sorted queue.
		wait  += clock - _waiting[i].getArrivalTime(); // Add the waiting time of a process.
		clock += _waiting[i].getProcessSpan();         // Update the clock.
		duration += _waiting[i].getProcessSpan();      // Update the total duration
	}
	_avgResponse = wait / (double)_waiting.size(); // Calculate the average response time: ART = (process from 1 to n wait) / amount of processes 
	_avgReturn   = duration / (double)_waiting.size() + _avgResponse; // Calculate the average return time: ART = processes span / amount of process + ART(Average response time)
	_avgWait     = _avgResponse; // Calculate the average wait time AWT = ART(Average Response time)
}

void SJF::init() {
	this->sortVector(_queue, 0, initialSort); // Pre sort the vector.
	this->calculateAverageTime(); // Call the member function that runs the algorithm.
}
	
double SJF::getAverageResponse() const {
	return this->_avgResponse; // Return the Average Response Time
}

double SJF::getAverageReturn() const {
	return this->_avgReturn; // Return the Average Return Time
}

double SJF::getAverageWait() const {
	return this->_avgWait; // Return the Average Wait Time
}

std::string SJF::toString() const {
	std::stringstream ss; // Creates a string stream.
	ss << "SJF  " << std::fixed << std::setprecision(1) << _avgReturn << " " << _avgResponse << " " << _avgWait; // Format the string.
	return ss.str(); // Return the strin.
}