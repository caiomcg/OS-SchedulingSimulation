/**
 * @class FCFS
 *
 * @brief First-Come, First-Served algorithm simulation class
 *
 * This Class is responsible for receiving a std::vector of Processes
 * and run the FCFS algorithm over the input. The user can request the
 * average response time, the average return time and the average wait
 * time using getters or the toString method. 
 *
 * @note See Process Class implementation to create the std::vector.
 *
 * @author Caio Marcelo Campoy Guedes <caiomcg@gmail.com>
 */


#ifndef FCFS_H_
#define FCFS_H_

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

#include "Process.h"

class FCFS {
private:
	std::vector<Process> _queue; /// The Process queue that will be executed under the algorithm.
	
	int _amountOfProcesses; /// The amount of process on the process queue.

	double _avgResponse; /// Average response time.
	double _avgReturn; /// Average return time.
	double _avgWait; /// Average waiting time.

	/**
	 * @brief Calculate the average time.
	 * @details Calculate the average time and populate the 
	 * double variables so the user can access the resulting 
	 * data.
	 */
	void calculateAverageTime();
	
public:
	/**
	 * @brief Class constructor.
	 * @details Initialize the class attributes.
	 * 
	 * @param processes Process queue to be executed under the algorithm.
	 */
	FCFS(std::vector<Process> processes);
	/**
	 * @brief Class destructor.
	 * @details Does base C++ cleanup.
	 */
	~FCFS();

	/**
	 * @brief Called to run the algorithm.
	 * @details Calls the calculateAverageTime member function wich is responsible
	 * for executing the algorithm.
	 */
	void init();

	/**
	 * @brief Returns the average response time.
	 * 
	 * @return The average response time.
	 */
	double getAverageResponse() const;
	/**
	 * @brief Returns the average return time.
	 * 
	 * @return The average return time.
	 */
	double getAverageReturn() const;
	/**
	 * @brief Returns the average waiting time.
	 * 
	 * @return The average waiting time.
	 */
	double getAverageWait() const;

	/**
	 * @brief Return a formatted string with the algorithm average time.
	 * @details The string returned will be as follow: FCFS X.X X.X X.X
	 * where the first result is the average return time, the second is the
	 * average response time and the third is the average waiting time.
	 * 
	 * @return A formatted string.
	 */
	std::string toString() const;
};

#endif // define FCFS
