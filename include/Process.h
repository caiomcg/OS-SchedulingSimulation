/**
 * @class Process
 *
 * @brief Process simulation class
 *
 * This Class is responsible for simulating a process. The
 * process concists of an arrival time, the process time span
 * and the program counter for the process.
 *
 * @author Caio Marcelo Campoy Guedes <caiomcg@gmail.com>
 */


#ifndef PROCESS_H_
#define PROCESS_H_

class Process {
private:
	unsigned int _arrival; /// Process arrival time.
	unsigned int _span; /// Process time span.
	unsigned int _programCounter; /// Process counter.
public:
	/**
	 * @brief Class constructor.
	 * @details Initialize the class attributes.
	 * 
	 * @param int Process arrival time.
	 * @param int Process time span.
	 * @param int Process counter(ID).
	 */
	Process(unsigned int arrival, unsigned int span, unsigned int programCounter);
	/**
	 * @brief Class destructor.
	 * @details Does base C++ cleanup.
	 */
	~Process();

	/**
	 * @brief Returns the process arrival time.
	 * 
	 * @return The arrival time.
	 */
	unsigned int getArrivalTime() const;
	/**
	 * @brief Returns the process time span.
	 * 
	 * @return The time span.
	 */
	unsigned int getProcessSpan() const;
	/**
	 * @brief Returns the process counter.
	 * 
	 * @return The process counter.
	 */
	unsigned int getProgramCounter() const;
};

#endif // PROCESS_H_