Fall 2007            CS 351 Programming Languages                  Shaun-inn Wu
Assignment #1                                                      Due: 09/04/07
        Write an interpreter in a programming language of your choice for a very
simple pseudo-code. The instructions on a one-accumulator virtual machine are as
follows:
Format        Meaning
1XXX          Load accumulator with contents of XXX
2XXX          Store accumulator into location XXX
3XXX          Add contents of XXX to accumulator
4XXX          Subtract contents of XXX from accumulator
5XXX          Branch to instruction XXX if accumulator is negative
6XXX          Stop
        The format of a pseudo-code program is as follows:
Initial Data Values
9999
Program consists of the above instructions
9999
        The memory of our virtual machine is 2000 words and each word holds an
integer less than or equal to +9999. The first half of the memory is used for data
and the second half is for program instructions. The initial data values should be
read into the beginning of the data area of the memory in that order. The validity of
the values in the memory should always be checked. The pseudo code instructions
should be read into the program instruction area of the memory before the program
execution starts.
        You will have to implement your program on our Unix system on
empress.csusm.edu. You are supposed to prepare a pseudo code test program as
the input to your pseudo-code interpreter. The output of your interpreter has to
demonstrate that at least one instruction of each format in your test program is
executed for at least once and both possibilities of the branch instruction are tested.
A shell script compiling and running your program should also be prepared.
        The documentation, implementation and testing of your program should be
done according to the Standards of Programming Assignments.

