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
    unsigned int arrival        = 0;
    unsigned int span           = 0;
    unsigned int programCounter = 0;

    while(std::cin >> arrival >>span) {
        processes.push_back(Process(arrival, span, programCounter++));
    }

    FCFS* fcfs = new FCFS(processes);
    SJF*  sjf  = new SJF(processes);

    fcfs->init();
    sjf->init();

    std::cout << fcfs->toString() << std::endl;
    std::cout << sjf->toString() << std::endl;

    delete fcfs;
    delete sjf;
    return 0;
}
