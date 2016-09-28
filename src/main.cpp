#include <iostream>
#include <new>
#include <vector>
#include <fstream>

#include "../include/Process.h"
#include "../include/Utils.h"
#include "../include/FCFS.h"
#include "../include/SJF.h"


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

    FCFS* fcfs = new FCFS(processes);
    SJF*  sjf  = new SJF(processes);
    fcfs->init();
    sjf->init();

    std::cout << fcfs->toString() << std::endl;

    delete fcfs;
    delete sjf;
    return 0;
}
