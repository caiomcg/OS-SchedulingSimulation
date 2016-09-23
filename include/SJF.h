#ifndef SJF_H_
#define SJF_H_

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

#include "Process.h"

class SJF{
private:
	std::vector<Process> _queue;
	std::vector<Process> _tmpQueue;

	int _amountOfProcesses;

	double _avgResponse;
	double _avgReturn;
	double _avgWait;

	void calculateAverageTime();
public:
	SJF(std::vector<Process> processes);
	~SJF();

	void init();
	
	double getAverageResponse();
	double getAverageReturn();
	double getAverageWait();

	std::string toString();
};

#endif // define SJF
