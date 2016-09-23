#ifndef FCFS_H_
#define FCFS_H_

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

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

	void calculateAverageResponseTime();
	
public:
	FCFS(std::vector<Process> processes);
	~FCFS();

	void init();
	double getAverageResponse();

	std::string toString();
};

#endif // define FCFS
