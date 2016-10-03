/**
 * @class RR
 *
 * @brief Round Robin algorithm simulation class
 *
 * This Class is responsible for receiving a std::vector of Processes
 * and run the RR algorithm over the input. The user can request the
 * average response time, the average return time and the average wait
 * time using getters or the toString method. 
 *
 * @note See Process Class implementation to create the std::vector.
 *
 * @author Caio Marcelo Campoy Guedes <caiomcg@gmail.com>
 */

#ifndef RR_h_
#define RR_h_

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

#include "Process.h"
#include "Utils.h"

class RR {
	std::vector<Process> _queue; /// The Process queue that will be executed under the algorithm.
	std::vector<Process> _waiting; /// The Sorted Process queue that will be executed under the algorithm.

	static const unsigned int quantum = 2; /// The quantum used for every process execution

	double _avgResponse; /// Average response time.
	double _avgReturn; /// Average return time.
	double _avgWait; /// Average waiting time.

	 /**
 	 * @brief Remove an amount of elements from the std::vector.
 	 * @details Removes the elements based on the distance parameter, which means
 	 * that it will remove from the first to first + distance elements.
 	 * 
 	 * @param vector The std::vector that the element will be taken from.
 	 * @param int The distance from the beginning to remove.
 	 */
 	void removeFromVector(std::vector<Process>& vector, unsigned int distance);

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
	RR(std::vector<Process> processes);
	/**
	 * @brief Class destructor.
	 * @details Does base C++ cleanup.
	 */
	~RR();

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
	 * @details The string returned will be as follow: RR X.X X.X X.X
	 * where the first result is the average return time, the second is the
	 * average response time and the third is the average waiting time.
	 * 
	 * @return A formatted string.
	 */
	std::string toString() const;
};

#endif //define RR.h
