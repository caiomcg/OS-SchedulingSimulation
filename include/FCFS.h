#ifndef FCFS_H_
#define FCFS_H_

#include <vector>
#include <algorithm>
#include <iostream>
#include "Process.h"

class FCFS {
private:
	std::vector<Process> _queue;

	int _currentArrival;
	int _cpuCycle;
	int _amountOfProcesses;

	double _avgResponse;
	double _avgReturn;
	double _avgWait;

	static bool sortPredicate(const Process& first, const Process& second);

	void calculateAverageResponseTime();
	void sortVector();
	
public:
	FCFS(std::vector<Process> processes);
	~FCFS();

	void init();
	double getAverageResponse();
};

#endif // define FCFS
