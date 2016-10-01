/**
 * @brief The utils namespace implements useful functions for debugging
 *
 * The utils namespace is composed of functions used for extracting
 * data from files or printing the processes allocated in a std::vector. 
 *
 * @note Utils function may not be used on the algorithms implementation.
 *
 * @author Caio Marcelo Campoy Guedes <caiomcg@gmail.com>
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "Process.h"

namespace Utils {
	/**
	 * @brief Extract the data from a file and store in a std::vector of processes.
	 * @details Open a text file and fetch the data from it creating process objects and
	 * pushing them to the std::vector.
	 * 
	 * @param filePath The path where the file is located
	 * @param output The std::vetor where the objects will be pushed to.
	 * 
	 * @return True if no problem occured.
	 */
	bool extractData(const char* filePath, std::vector<Process>& output);
	/**
	 * @brief Print the processes from a std::vector.
	 * @details The output will be formatted as follows:
	 * Process - [Program counter] - arrival: arrival time span: process span. 
	 * 
	 * @param p The std::vector to be printed.
	 */
	void print(std::vector<Process>& p);
}

#endif // define Utils