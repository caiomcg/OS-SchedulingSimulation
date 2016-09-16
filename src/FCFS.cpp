#include "../include/FCFS.h"

FCFS::FCFS(std::vector<Process>& processes) : _waiting(processes), _currentArrival(0), _cpuCycle(0) {
	_amountOfProcesses = processes.size();
}

FCFS::~FCFS() {}

void FCFS::init() {
	int rc = pthread_create(&_timer, NULL, &FCFS::timerThread, NULL);
	if (rc) {
		//THROW EXCEPTION
	}
}

void* FCFS::timerThread(void* tid) {
	while (true) {
		//Do timer
	}
	pthread_exit(NULL);
}