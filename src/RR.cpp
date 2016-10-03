#include "../include/RR.h"


RR::RR(std::vector<Process> processes) : _queue(processes), _avgResponse(0), _avgReturn(0), _avgWait(0) {}

RR::~RR() {}

void RR::removeFromVector(std::vector<Process>& vector, unsigned int distance) {
	vector.erase(vector.begin(), vector.begin() + distance); // Erase a determined amount of elements.
}

void RR::calculateAverageTime(){
	unsigned int wait     = 0; // Store the sum of the waiting time for all processes.
	unsigned int running  = 0; // Store the current running process.
	unsigned int pushed   = 0; // Store the amount of elements that were pushed to the new queue.
	unsigned int duration = 0; // Store the sum of the duration time for all processes.
	unsigned int clock    = 0; // Store the current clock time.
	unsigned int amountOfProcesses = _queue.size(); // The amount of process passed by the user.

	for (int i = 0; i < _queue.size(); i++) { // Loops through the initial queue.
		processRunning += _queue[i].getProcessSpan(); // Store the total time of process running
	}

	while (!_queue.empty()) { // Runs until the queue is empty
		clock   = _queue[0].getArrivalTime(); // Initiates the clock with the first process arrival time.
		pushed = 0; // Resets the amount of pushed processes.

		for (int i = 0; i < _queue.size(); i++) { // Loops through the initial queue.
			if (_queue[i].getArrivalTime() <= clock) { // Check if the current process have the same arrival time as the clock.
				_waiting.push_back(_queue[i]); //Push the process to the new queue.
				pushed++; // Increments the amount of pushed elements.
			} else {
				break; // Stop pushing element.
			}	
		}

		this->removeFromVector(_queue, pushed); // Remove the elements that were pushed from the main queue.

		while (!_waiting.empty()) { // Loops until there are process on the queue.
			Process p = _waiting[running]; // Get the first element so we can process over it.
			this->removeFromVector(_waiting, 1); // Removes the first element so we can process over it.

			if (p.getRun()) { // Check if process already ran.
				wait += clock - p.getArrivalTime(); // Increments the waiting time for the processes.
				p.setRun(false); // Indicate that process already ran.
			}

			if (p.getProcessSpan() < quantum) { // If the time that takes the process to run is lower than the quantum.
				clock += p.getProcessSpan(); // Update the clock with the remaining running time.
				p.setProcessSpan(0); // Finish the process.
			} else {
				clock += quantum; // Increments the clock with the value of the quantum.
				p.setProcessSpan(p.getProcessSpan() - quantum); // Removes one quantum from the process.
			}

			pushed = 0; // Resets the amount of pushed processes.
			for (int i = 0; i < _queue.size(); i++) { // Loops through the initial queue.
				if (_queue[i].getArrivalTime() <= clock) { // Check if the current process have the same arrival time as the clock.
					_waiting.push_back(_queue[i]); //Push the process to the new queue.
					pushed++; // Increments the amount of pushed elements.
				} else {
					break; // Stop pushing element.
				}	
			}
			this->removeFromVector(_queue, pushed); // Remove the elements that were pushed from the main queue.

			if (p.getProcessSpan() > 0) { // If there is still process to run.
				_waiting.push_back(p); //Put the process on the back.
			} else {
				duration += clock - p.getArrivalTime(); // Store the duration of the processes.
			}
		}
	}

	_avgReturn   = duration / (double)amountOfProcesses; // Calculate the average return.
	_avgResponse = wait / (double)amountOfProcesses; // Calculate the average response.
	_avgWait     = (duration - processRunning) / (double)amountOfProcesses; // Calculate the average wait.
}
void RR::init() {
	this->calculateAverageTime(); // Call the member function that runs the algorithm.
}
	
double RR::getAverageResponse() const {
	return this->_avgResponse; // Return the Average Response Time
}

double RR::getAverageReturn() const {
	return this->_avgReturn; // Return the Average Return Time
}

double RR::getAverageWait() const {
	return this->_avgWait; // Return the Average Wait Time
}

std::string RR::toString() const {
	std::stringstream ss; // Creates a string stream.
	ss << "RR   " << std::fixed << std::setprecision(1) << _avgReturn << " " << _avgResponse << " " << _avgWait; // Format the string.
	return ss.str(); // Return the strin.
}