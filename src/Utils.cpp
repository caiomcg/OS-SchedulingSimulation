#include "../include/Utils.h"

bool Utils::extractData(const char* filePath, std::vector<Process>& output){
	std::ifstream input(filePath, std::ifstream::in); // Try to open the input stream from the passed file path.

	if (!input.is_open()) { // Check if the file was successfully opened.
		return false;
	}

	unsigned int arrival = 0; 		 // Store the arrival time of a process.
	unsigned int span = 0; 			 // Store the process time span.
	unsigned int programCounter = 0; // Store the process counter.

	while (input >> arrival >> span) { // Read the data from the file.
		output.push_back(Process(arrival, span, programCounter)); // Create a Process object with the data and push it to the vector.
		programCounter++; // Increase the program counter.
	}

	input.close(); // Close the file stream.
	return true;
}

void Utils::print(std::vector<Process>& p) {
	for (int i = 0; i < p.size(); i++) { // Loops through the process queue.
		std::cout << "Process - [" << p[i].getProgramCounter() << "] - arrival: " << p[i].getArrivalTime() << " span: " << p[i].getProcessSpan() << std::endl; // Print the process to the standard output.
	}
}
