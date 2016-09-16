#include "../include/Utils.h"

bool Utils::extractData(const char* filePath, std::vector<Process>& output){
	std::ifstream input(filePath, std::ifstream::in);

	if (!input.is_open()) {
		return false;
	}

	unsigned int arrival = 0;
	unsigned int span = 0;
	unsigned int programCounter = 0;

	while (input >> arrival >> span) {
		output.push_back(Process(arrival, span, programCounter));
		programCounter++;
	}
	return true;
}

void Utils::print(std::vector<Process>& p) {
	for (int i = 0; i < p.size(); i++) {
		std::cout << "Process - [" << p[i].getProgramCounter() << "] - arrival: " << p[i].getArrivalTime() << " span: " << p[i].getProcessSpan() << std::endl;
	}
}
