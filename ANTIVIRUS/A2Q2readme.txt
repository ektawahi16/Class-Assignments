Assignment 2  - readme.txt
A2Q2 - "MyAntivirus"

-------
 INPUT
-------
Files in which virus is to be detected.

--------
 OUTPUT
--------
Checks and displays whether virus is detected or not.

-------------
 DESCRIPTION
-------------

Programs violating the specification are considered anomalous and usually, malicious. Techniques used for detecting malware can be categorized broadly into two 
categories: 
	1.anomaly-based detection and 
	2.Signature-based detection.
An anomaly-based detection technique uses its knowledge of what constitutes normal behavior to decide the maliciousness of a program under inspection. 
Signature-based detection uses its characterization of what is known to be malicious to decide the maliciousness of a program under inspection. Each of the 
detection techniques can employ one of three different approaches: static, dynamic, or hybrid. In general, a static approach attempts to detect malware before 
the program under inspection executes. Conversely, a dynamic approach attempts to detect malicious behavior during program execution or after program execution. 
Here we are using static approach in our code.

Making a working antivirus is hard because of several reasons:
	1.You need to get virus/malware sample which is not easy to get.
	2.Most virus infect the executable file and some use polymorphism making it harder to detect.
	3.Most antivirus use heuristics scan which analyze the file and if the file look suspicious it will flag it and ask the user what to do. This is hard to 
	  implement and poor heuristics scan can result many false-positive.
	4.Need a driver which will monitor the system like file read/write and so on.

We have tried to make a simple malware scanner (not antivirus) in C++ . This methods works on some examples that we have provided like infinite loop, buffer 
overflow attack, etc.


----------
 APPROACH
----------

We have taken a few small virus/attack programs and used our malware scanner(antivirus) to detect them.

INFINITE LOOP:-
	while(true){}
	for(; ; ;);
	for(int i=0; ; i++);

A loop that repeats indefinitely and never terminates is called an Infinite loop. The above peice of code will cause infinite loop as the test condition is 
always 'true' and the loop will never exit. It would easily bring down the computer memory in minutes, making it slow and unresponsive.

SYSTEM CALL:-
	system( );

A system call is the programmatic way in which a computer program requests a service from the kernel of the operating system it is executed on. This may 
include hardware-related services, creation and execution of new processes, and communication with integral kernel services such as process scheduling.

REMOVE CALL:-
 	remove( );

Deletes the file whose name is specified in filename.This is an operation performed directly on a file identified by its filename; No streams are involved in 
the operation.


BUFFER OVERFLOW ATTACK:-
	int arr[10]
	arr[20]

In the above example, ‘arr’ represents an array of 10 integers. Now assuming that the size of integer is 4 bytes, the total buffer size of ‘arr’ is 10*4 = 40 
bytes. Now, arr[0] refers to the left boundary while arr[9] refers to the right boundary. A buffer is said to be overflown when the data (meant to be written 
into memory buffer) gets written past the left or the right boundary of the buffer. This way the data gets written to a portion of memory which does not belong 
to the program variable that references the buffer.








