#ifndef FCFS_H_
#define FCFS_H_

#include <pthread.h>
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

	pthread_t _timer;

	static void* timerThread(void* tid);
public:
	FCFS(std::vector<Process>& processes);
	~FCFS();

	void init();
};

#endif // define FCFS
