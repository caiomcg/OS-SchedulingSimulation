#ifndef PROCESS_H_
#define PROCESS_H_

class Process {
private:
	unsigned int _arrival;
	unsigned int _span;
public:
	Process(unsigned int arrival, unsigned int span);
	~Process();

	unsigned int getArrivalTime() const;
	unsigned int getProcessSpan() const;
};

#endif // PROCESS_H_