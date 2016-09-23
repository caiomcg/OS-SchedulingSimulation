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
	
	int _amountOfProcesses;

	double _avgResponse;
	double _avgReturn;
	double _avgWait;

	void calculateAverageTime();
	
public:
	FCFS(std::vector<Process> processes);
	~FCFS();

	void init();
	
	double getAverageResponse();
	double getAverageReturn();
	double getAverageWait();

	std::string toString();
};

#endif // define FCFS
