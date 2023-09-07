# Lab 1: Testing a g++ compiler

g++ is an open source compiler distribution based on the original linux GNU distribution. Simply speaking, it is a code compiling system to build and execute a c++ code into native host machine code.

Ubuntu comes in with a built in g++ code compiling system. Lets see an example of how to run a sample code from within the linux terminal.

1. Open up the terminal in the linux prompt.
2. Navigate to the desired folder. Alternatively, you can make one by the mkdir <filename> command.
3. ![](D:\BSCS\Fourth Semester\Operating Systems\labs\Lab2\IMG-20230128-WA0014.jpg)

The *touch* command followed by the filename creates the file in the desired folder.

4. Next up, open the .cpp file into some editor. Ubuntu provides a built in editor *gedit* to edit the code.![](D:\BSCS\Fourth Semester\Operating Systems\labs\Lab2\IMG-20230128-WA0015.jpg)
5. Write Some Code into the file and when done, save and exit the terminal. There is a way to simultaneously edit and execute the code. For that, the terminal needs to be opened *twice*, one for editing and the other for execution.
6. To compile the code into native machine code, the command syntax is *g++ FILENAME -o OUTPUT* .![](D:\BSCS\Fourth Semester\Operating Systems\labs\Lab2\IMG-20230128-WA0016.jpg)

7. To run the code, the command syntax is ./*OUTPUT* . For example, in the previous example, we created lab1 as the output file (see the end of the last command entered). This we will enter in the terminal in the above mentioned syntax.![](D:\BSCS\Fourth Semester\Operating Systems\labs\Lab2\IMG-20230128-WA0017.jpg)*

### Congratulations, that is the end of g++ compiling.