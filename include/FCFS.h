#ifndef FCFS_H_
#define FCFS_H_

#include <vector>
#include <iostream>
#include "Process.h"

class FCFS {
private:
	std::vector<Process> _waiting;
	std::vector<Process> _processing;

	int _currentArrival;
	int _cpuCycle;
	int _amountOfProcesses;
	
public:
	FCFS(std::vector<Process>& processes);
	~FCFS();

	void init();
};

#endif // define FCFS
