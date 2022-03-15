<br />
<div align="center">
  <h1 align="center">Embedded Real Time Systems Assignment 1</h1>
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

<br />

# 2. Assignment 1

## 2.1 Introduction
In this work I used the wsl program with the Ubuntu 20.04 LTS operating system. My system contains Intel(R) Core(TM) i5-8300H CPU @ 2.30 GHz with 16 GB of memory. Moreover to generate the data due to consumer's while(1) reason I had to run it manually to get the results and giving as input the number consumer That is: by compiling with the command
`gcc ESPX_1.c -lpthread -o ESPX_1.out`
and counts running for each result shown below 
`./ESPX_1.out i ` , where i is the number of threads for the consumer.

## 2.2 Waiting time statistics
In Figure 1 we see the waiting time between producer and consumer with different sizes of consumers; however, the size of producer remained constant with 4 threads for each execution. <br />

<img src="https://github.com/NikolaosGian/EmbeddedRealTimeSystems/blob/main/graphs/graph_1.PNG"> <br />

We notice that when we have thread sizes 50 to 200 the waiting time between producer and consumer is uneven. As we increase to 500 threads we get 0.171 ms but there is a particular behavior when the number of threads from 1000 to 7000 the time remains approximately constant.

<br />

## 2.3 Average cost of the residence time 
Graph 2 shows the average waiting time in each case. <br />

<img src="https://github.com/NikolaosGian/EmbeddedRealTimeSystems/blob/main/graphs/graph_2.PNG"> <br />

We observe that the average waiting time is approximately constant when the consumer threads are between 4000 and 7000

<br />
