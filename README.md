<br />
<div align="center">
  <h1 align="center">Embedded Real Time Systems</h1>
  <h3 align="center">Aristotle University of Thessaloniki</h3>
  <h4 align="center">School of Electrical & Computer Engineering</h4>
  <p align="center">
    Contributors:Nikolaos Giannopoulos
    <br />
    Spring Semester 2021 - 2022
    <br />
    <br />
  </p>
</div>
<br />

# 1. Contents
- [1. Contents](#1-contents)
- [2. Assignment 1](#2-assignment-1)
  - [2.1. Introduction](#21-introduction)
  - [2.2. Waiting time statistics](#22-waiting-time-statistics)
  - [2.3. Average cost of the residence time](#23-average-cost-of-the-residence-time)
- [3. Assignment 2](#3-assignment-2)
- [4. Assignment 3](#4-assignment-3)

<br />

# 2. Assignment 1
To test the results you can run `make all` second `bash script.sh` and then `python3 calcWaitTime.py` at the linux command line.
## 2.1 Introduction
In this paper I used the Oracle VM VirtualBox program with the Ubuntu 20.04 LTS operating system which has 2 cores and 4 GB of memory available.
The system my system contains the Intel(R) Core(R) i5-8300H CPU @ 2.30 GHz with 16 GB of memory.
## 2.2 Waiting time statistics
In graph 1 we see the waiting time between producer and consumer with different sizes of the variable LOOP in the code provided in the e-learning. <br />

<img src="https://github.com/NikolaosGian/EmbeddedRealTimeSystems/blob/part_1_of_3/graphs/graph_1.PNG"> <br />

We notice that when we have threads of size 10,000 the time waiting time between producer and consumer is 0.9 us. As we increase to 20,000 threads it is 0.74 us but we observe
a particular behavior when the number of threads is 30,000 the the time between producer & consumer is 0.3 us. Then between the range {50,000, 500,000} threads the time remains almost the same.It shows a big improvement from 600,000 to 700,000 threads the time between producer & consumer is 0.24us and 0.23 us which is very attractive in applications that need fast response for various parameters.

<br />

## 2.3 Average cost of the residence time 
Graph 2 shows the average waiting time in each of the case. <br />

<img src="https://github.com/NikolaosGian/EmbeddedRealTimeSystems/blob/part_1_of_3/graphs/graph_2.PNG"> <br />

We note that for a size of 50,000 threads the average time waiting time is 3 the 2nd best in time is with size 600,000 threads and 1st and best at thread size equal to 500.000. As it leads us to the conclusion that the number of threads that minimizes the average waiting time is 500,000.

<br />

# 3. Assignment 2

# 4. Assignment 3

