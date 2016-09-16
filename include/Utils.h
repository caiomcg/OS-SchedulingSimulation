#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "Process.h"

namespace Utils {
	bool extractData(const char* filePath, std::vector<Process>& output);
	void print(std::vector<Process>& p);
}

#endif