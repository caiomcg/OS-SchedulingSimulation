/**
 * @class SJF
 *
 * @brief Short Job First algorithm simulation class
 *
 * This Class is responsible for receiving a std::vector of Processes
 * and run the SJF algorithm over the input. The user can request the
 * average response time, the average return time and the average wait
 * time using getters or the toString method. 
 *
 * @note See Process Class implementation to create the std::vector.
 *
 * @author Caio Marcelo Campoy Guedes <caiomcg@gmail.com>
 */


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

typedef enum {
	sort,
	initialSort
} Predicate; /// Predicate selection enumeration.

class SJF{
private:
	std::vector<Process> _queue; /// The Process queue that will be executed under the algorithm.
	std::vector<Process> _waiting; /// The Sorted Process queue that will be executed under the algorithm.

	double _avgResponse; /// Average response time.
	double _avgReturn; /// Average return time.
	double _avgWait; /// Average waiting time.

	/**
	 * @brief The sort predicate for std::sort
	 * @details Order the process by process time span.
	 * 
	 * @param first The first process.
	 * @param second The second process.
	 * 
	 * @return True if sort is needed.
	 */
	static bool sortPredicate(const Process& first, const Process& second);
	/**
	 * @brief The sort predicate for std::sort
	 * @details Order the process by process time span or arrival time.
	 * 
	 * @param first The first process.
	 * @param second The second process.
	 * 
	 * @return True if sort is needed.
	 */
	static bool initialSortPredicate(const Process& first, const Process& second);

	/**
	 * @brief Sort a std::vector of process.
	 * @details Sort the std::vector of process depending on the sorting offset
	 * and the sort predicate to be used.
	 * 
	 * @param vector The std::vector that will be sorted
	 * @param int The offset from the beginning of the vector.
	 * @param predicate The sort predicate to use. See Predicate enum for further
	 * information.
	 */
 	void sortVector(std::vector<Process>& vector, unsigned int offset, Predicate predicate);

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
	SJF(std::vector<Process> processes);
	/**
	 * @brief Class destructor.
	 * @details Does base C++ cleanup.
	 */
	~SJF();

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
	double getAverageResponse();
	/**
	 * @brief Returns the average return time.
	 * 
	 * @return The average return time.
	 */
	double getAverageReturn();
	/**
	 * @brief Returns the average waiting time.
	 * 
	 * @return The average waiting time.
	 */
	double getAverageWait();

	/**
	 * @brief Return a formatted string with the algorithm average time.
	 * @details The string returned will be as follow: SJF X.X X.X X.X
	 * where the first result is the average return time, the second is the
	 * average response time and the third is the average waiting time.
	 * 
	 * @return A formatted string.
	 */
	std::string toString();
};

#endif // define SJF
