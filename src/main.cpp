#include <iostream>
#include <vector>
#include <fstream>

#include "../include/Process.h"
#include "../include/Utils.h"

int main(int argc, char** argv) {
	std::vector<Process> processes;

    if (argc == 1 || argc > 2) {
    	//add usage
    	return 1;
    }

    if (!Utils::extractData(argv[1], processes)) {
    	//show error
    	return 1;
    }

    Utils::print(processes);
    //call agorithms

    return 0;
}
