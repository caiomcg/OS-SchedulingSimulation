CC = g++
INCLUDE_PATH = ../include/
SRC_PATH = ../src/
EXE = os-scheduling

Process.o: $(INCLUDE_PATH)Process.h $(SRC_PATH)Process.cpp
	$(CC) $(SRC_PATH)Process.cpp -c

Utils.o: $(INCLUDE_PATH)Utils.h $(SRC_PATH)Utils.cpp
	$(CC) $(SRC_PATH)Utils.cpp -c

FCFS.o: $(INCLUDE_PATH)FCFS.h $(SRC_PATH)FCFS.cpp
	$(CC) $(SRC_PATH)FCFS.cpp -c

SJF.o: $(INCLUDE_PATH)SJF.h $(SRC_PATH)SJF.cpp
	$(CC) $(SRC_PATH)SJF.cpp -c

RR.o: $(INCLUDE_PATH)RR.h $(SRC_PATH)RR.cpp
	$(CC) $(SRC_PATH)RR.cpp -c

all: Process.o Utils.o FCFS.o SJF.o RR.o
	$(CC) *.o $(SRC_PATH)main.cpp -o $(EXE)

.PHONY: clean

clean:
	rm -rf *.o