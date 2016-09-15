#ifndef PROCESS_H_
#define PROCESS_H_

class Process {
private:
	unsigned int arrival;
	unsigned int span;
public:
	Process(unsigned int arrival, unsigned int span);
	~Process();

	unsigned int getArrivalTime();
	unsigned int getProcessSpan();
}

#endif // PROCESS_H_