# Programming Assignment 2 - Greedy Algorithms
**Isaac Wachsman (UFID: 28099694)**

**Aarav Bejjinki (UFID: 40331589)** 

## Project Structure Overview

- **src/main.cpp**: main file, computes number of cache misses for 3 different replacement algorithms.
- **src/parser.cpp**: parse text files to obtain cache size and request sequence.
- **src/parser.h**: parser header file
- **src/driver.cpp**: implements FIFO, LRU, and OPTFF page replacement algorithms.
- **src/driver.h**: driver header file

  
- **tests/inputN.txt**: the Nth input file
- **tests/outputN.txt**: the Nth output file

## Compilation and Execution Instructions 

(Please note that the commands given are for Windows Powershell. Similar commands can be run for other terminals.)

1. Navigate to a folder of your choice on your terminal and run `git clone https://github.com/isaac-wachsman/Programming-Assignment-2-Greedy-Algorithms.git` to clone the repository to the folder.

2. Run `cd Programming-Assignment-2-Greedy-Algorithms` , then `cd src` to navigate to the src directory.

3. Run `g++ -o main main.cpp driver.cpp parser.cpp` to compile the program.

4. Run `./main` to run the main program. You will be prompted to provide an input file on which to run the cache replacement algorithms. To use the provided input files, type '../tests/inputN.txt' where N = 1, 2, or 3 and hit enter. If you are using a custom input file, type the path of the file relative to src and hit enter.



## Input / Output

Input is expected to come from txt files in the following form:

```
k m
r1 r2 r3 ... rm
```
The first line contains two positive integers. The first integer, k, represents the capacity of the cache. The following integer, m, is the number of requests. The following line contains m integers separated by spaces which represent the ids of the cache pages being requested. As an example, consider the following input file:

```
3 7
1 2 3 4 3 2 1
```

Above, the cache size is 3 and there are 7 requests made.


**NOTE:** Input files that do not match this specified format will result in undefined behavior.


The matcher output is printed in the terminal in the form:
```
FIFO:  <number of misses>
LRU:   <number of misses>
OPTFF: <number of misses>
```



