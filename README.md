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

4. Run `./main` to run the program. You will be prompted to provide an input file on which to run the cache replacement algorithms. To use the provided input files, type `../tests/inputN.txt` where N = 1, 2, or 3 and hit enter. If you are using a custom input file, type the path of the file relative to src and hit enter.



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


## Written Component

<b>Question 1: Empirical Comparison</b>

<table>
  <tr>
    <th>Input File</th>
    <th>k</th>
    <th>m</th>
    <th>FIFO</th>
    <th>LRU</th>
    <th>OPTFF</th>
  </tr>
  <tr>
    <td>input1.txt</td>
    <td>3</td>
    <td>100</td>
    <td>61</td>
    <td>61</td>
    <td>44</td>
  </tr>
  <tr>
    <td>input2.txt</td>
    <td>2</td>
    <td>100</td>
    <td>54</td>
    <td>50</td>
    <td>38</td>
  </tr>
  <tr>
    <td>input3.txt</td>
    <td>5</td>
    <td>75</td>
    <td>29</td>
    <td>37</td>
    <td>20</td>
  </tr>
</table>

<hr>
<i>Does OPTFF have the fewest misses?</i>
Yes, it has the fewest misses on all input files. This will be proven to always be the case in question 3.
<hr>
<i>How does FIFO compare to LRU?</i>
As demonstrated by the above data, LRU can have fewer, more, or the same number of misses compared to FIFO depending on the input.
<hr>

<b>Question 2: Bad Sequence for LRU or FIFO</b>

This is possible. Consider the following input file:

```
3 5
1 2 3 4 1
```

<p>This input will result in 5 cache misses for both LRU and FIFO. Clearly, the first 3 requests miss as the cache is initially empty. The request for 4 misses because the cache contains 1, 2, and 3. At this step, 1 is evicted as it is both the first in and the least recently accessed. Hence, when there is another request for 1, it is another miss.</p>

<p>The input results in 4 cache misses with OPTFF. The first 3 requests miss as the cache is initially empty. The request for 4 misses because the cache contains 1, 2, and 3. However, 2 or 3 is evicted instead of 1 because there are no more requests for 2 or 3 later in the sequence. Hence, 1 stays in the cache and hits on the last request.</p>



<b>Question 3: Prove OPTFF is Optimal</b>

Let $A_i$ denote an optimal algorithm that matches the decisions of OPTFF for the first $i$ requests. We will show that there exists an algorithm $A_{i+1}$ that matches the decisions of OPTFF for the first $i+1$ requests and the number of misses for $A_{i+1}$ is less than or equal to the number of misses for $A_i$.

Consider what happens on the (i+1)th request. If we have a hit for both $A_i$ and OPTFF or the same page is evicted, then they match already so nothing has to be done to produce $A_{i+1}$. So consider the case where OPTFF evicts page A and $A_i$ evicts a different page, B. 

We now define $A_{i+1}$ as follows: $A_{i+1}$ evicts page A at step $i+1$ like OPTFF. After that, $A_{i+1}$ follows $A_i$.

Now consider future requests to page A or B. If B is requested, then $A_{i+1}$ hits because B was not evicted. $A_i$ misses though because it evicts B. So $A_{i+1}$ has one fewer miss than $A_i$. If A is requested, then $A_i$ hits because it evicted B, and $A_{i+1}$ misses because it already evicted A. However, because A is the farthest-in-future request as specified by OPTFF, the request for B must occur before the request for A. Hence, the number of misses for $A_{i+1}$ cannot exceed the number of misses for $A_i$. 

This shows that we can transform an arbitrary algorithm A that agrees with OPTFF on some number of requests, into an algorithm that agrees on all steps (which means A is transformed into OPTFF) where the number of misses for OPTFF is bounded above by the number of misses for A. Since A is arbitrary, OPTFF is optimal.
