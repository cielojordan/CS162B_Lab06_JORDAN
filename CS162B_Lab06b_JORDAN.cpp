/**********************************************************************
* Project           : Lab 6b
*
* Program name      : Lab 6 B
*
* Author            : Cielo Jordan
*
* Date created      : 10 April 2016
*
* Purpose           : Concurrent Processes in Linux using fork() and exec()
**********************************************************************/

#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>

#define FOREVER_LOOP INT8_MAX

using namespace std;

void xClockFunction( time_t currTime, tm* localTime, char dateBuffer[100], char timeBuffer[100], int i ) {
	time(&currTime); // Gets and sets currTime to current time
	localTime = localtime(&currTime); // Converts currTime to tm struct for local timezone
	
	// Format time as strings
	strftime(dateBuffer, 50, "%Y-%m-%d", localTime); // Formats date as [YYYY-MM-DD]
	strftime(timeBuffer, 50, "%T", localTime); // Formats time as [hh:mm:ss]
	cout << dateBuffer << " " << timeBuffer << endl; // Print out date and time
	if ( i % 3 == 0 ) { 
		cout << "This program has gone on for far too long. Type Ctrl+C to abort this silly application." << endl; 
	}
}

int main() {
	time_t currTime; // current system based date/time
	tm* localTime; // tm struct local time
	char dateBuffer[100]; // date char array for string formatting
	char timeBuffer[100]; // time char array for string formatting

	for (int i=1; i<=FOREVER_LOOP; i++) {
		pid_t processID = fork();
		if ( processID < 0 ) {
			// Print fork error
			perror("fork() error");
			exit(1);
		} else if ( processID == 0 ) {
			// Child Process
			xClockFunction( currTime, localTime, dateBuffer, timeBuffer, i );
		} if ( processID == 0 ) {
			if ( i == 1 ) {
				execl("/usr/bin/xclock", "myXclock", NULL);
			}
		}
		
		// Parent Process
		sleep(10); // delay for 10 seconds
		wait(0); // wait for child process to finish execution
		
	}
	
	return 0;
}
