# OS-SchedulingSimulation

[![Build Status](https://travis-ci.org/caiomcg/OS-SchedulingSimulation.svg?branch=master)](https://travis-ci.org/caiomcg/OS-SchedulingSimulation)
<a href="https://scan.coverity.com/projects/caiomcg-os-schedulingsimulation"> <img alt="Coverity Scan Build Status" src="https://scan.coverity.com/projects/10188/badge.svg"/> </a>
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/caiomcg/OS-SchedulingSimulation/master/LICENSE)

A C++ simulation of FCFS(First-Come, First-Served), SJF(Short Job First) and RR(Round Robin) scheduling algorithms.

## Requirements ##

* C++ Compiler.

## Build Instructions ##

* Clone the project.
* Move to the debug folder.
* Invoke the makefile.

```
$> git clone https://github.com/caiomcg/OS-SchedulingSimulation.git
$> cd debug
$> make all
```

## Execution Instructions ##

### With a file ###
* Move to the debug folder.
* Run the created executable file and pipe a file to it.

```
$> cd debug
$> ./main < ../extra/example1.txt
```

### Directly to the application ###
* Move to the debug folder.
* Run the created executable file and type the input.
* Send EOF signal

```
$> cd debug
$> ./main
$> 0 20
$> 0 10
$> 4 6
$> 4 8
$> CTRL + D
```
