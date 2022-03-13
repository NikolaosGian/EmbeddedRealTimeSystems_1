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
## 2.1 Introduction
In this paper I used the wsl program with the Ubuntu 20.04 LTS operating system. My system contains the Intel(R) Core(R) i5-8300H CPU @ 2.30 GHz with 16 GB memory.
## 2.2 Waiting time statistics

In Figure 1 we see the waiting time between producer and consumer with different sizes of consumers. However, the size of producer remained constant with 4 threads for each execution.
 <br />

<img src="https://github.com/NikolaosGian/EmbeddedRealTimeSystems/blob/main/graphs/graph_1.PNG"> <br />

We note that when we have yarns of size 50 to 200 waiting time between producer and consumer is uneven. As we increase to 500 threads we find that 0.171 ms but there is a particular behavior when the number of threads from 1000 to 7000 the time remains approximately constant.


<br />

## 2.3 Average cost of the residence time 
Graph 2 shows the average waiting time in each of the case. <br />

<img src="https://github.com/NikolaosGian/EmbeddedRealTimeSystems/blob/main/graphs/graph_2.PNG"> <br />

We note that the average waiting time is about constant when the consumer threads are 4000 threads in number to 7000.

<br />

# 3. Assignment 2

# 4. Assignment 3

