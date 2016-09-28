#ifndef SJF_H_
#define SJF_H_

#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "Process.h"
#include "Utils.h"

class SJF{
private:
	std::vector<Process> _queue;

	int _amountOfProcesses;

	double _avgResponse;
	double _avgReturn;
	double _avgWait;

	static bool sortPredicate(const Process& first, const Process& second);
 	void sortVector();

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
