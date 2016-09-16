#include "../include/FCFS.h"

FCFS::FCFS(std::vector<Process>& processes) : _waiting(processes), _currentArrival(0), _cpuCycle(0) {
	_amountOfProcesses = processes.size();
}

FCFS::~FCFS() {}

void FCFS::init() {
	
}