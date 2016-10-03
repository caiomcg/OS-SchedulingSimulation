#include <iostream>
#include <new>
#include <vector>
#include <fstream>

#include "../include/Process.h"
#include "../include/Utils.h"
#include "../include/FCFS.h"
#include "../include/SJF.h"
#include "../include/RR.h"

int main(void) {
	std::vector<Process> processes; // Processes that are passed through stdin

    unsigned int arrival        = 0; // Process arrival time
    unsigned int span           = 0; // Process time span.
    unsigned int programCounter = 0; // Process program counter.

    while (std::cin >> arrival >> span) { // Read two unsigned int from stdin.
        processes.push_back(Process(arrival, span, programCounter++)); // Create a process and append it to the vector.
    }

    FCFS* fcfs = new FCFS(processes); // Create an instace of FCFS
    SJF*  sjf  = new SJF(processes);  // Create an instace of SJF
    RR*   rr   = new RR(processes);   // Create an instace of RR

    fcfs->init(); // Run the algorithm
    sjf->init();  // Run the algorithm
    rr->init();   // Run the algorithm

    std::cout << fcfs->toString() << std::endl; // Print the results for FCFS
    std::cout << sjf->toString()  << std::endl; // Print the results for SJF
    std::cout << rr->toString()   << std::endl; // Print the results for RR

    delete fcfs; // Free allocated memory
    delete sjf;  // Free allocated memory
    delete rr;   // Free allocated memory

    return 0;
}
