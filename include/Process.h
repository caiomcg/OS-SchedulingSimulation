#ifndef PROCESS_H_
#define PROCESS_H_

class Process {
private:
	unsigned int _arrival;
	unsigned int _span;
	unsigned int _programCounter;
public:
	Process(unsigned int arrival, unsigned int span, unsigned int programCounter);
	~Process();

	unsigned int getArrivalTime() const;
	unsigned int getProcessSpan() const;
	unsigned int getProgramCounter() const;
};

#endif // PROCESS_H_