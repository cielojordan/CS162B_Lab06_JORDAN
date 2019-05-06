|**********************************************************************;
* Project           : Lab 6b
*
* Program name      : Lab 6 B
*
* Author            : Cielo Jordan
*
* Date created      : 10 April 2016
*
* Purpose           : Concurrent Processes in Linux using fork() and exec()
|**********************************************************************;

1. void xClockFunction
	1.A The function has parameters and their corresponding values/functions:
		1.A.i. time_t currTime: current time
		1.A.ii. tm* localTime : local time struct instantiated with the system current time 
		1.A.iii. char dateBuffer: contains the current d1ate
		1.A.iv. char timeBuffer: contains the current time
		1.A.v. int i: index used for the loop in main function

2. Main Function
	2.A Other Variables
		2.A.i. pid_t processID: represents the process ID of the child(ren) process(es).
	2.B Output
		2.B.i. Program outputs the current date and time indefinitely until user exits the program with Ctrl+C.
	2.C Loop: Using a for-loop, the program outputs the current date and time.
		2.C.i. Error: If the fork gets an error, the program prints out an error message.
		2.C.ii. Child Process: The child process runs the xClockFunction to printout the current date and time. It also executes the xclock application to show the system time via a digital clock.
		2.C.iii. Parent Process: The parent process delays the execution of the child process by 10 seconds and also waits for the child process to finish executing before proceeding with the loop.
		2.C.iv. Exit: The loop runs forever (using INT8_MAX) and can only be interrupted by the user input Ctrl + C.
