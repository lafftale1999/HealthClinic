# Health Clinic
This program consists of several smaller tasks and our own modifications that we wanted to try out. Originally the group was tasked with the following:

**Task 1**
Use this template from our teacher [link](https://github.com/aspcodenet/calgo214515].
* A) Make the customer ID padded.
* B) Binary Search Algorithm
* C) Shuffle customers
* D) Sort using and STL algorithm

**Task 2**
Create a templated Queue class with a static array where we dont need to move all the values and the queue wont accept more than 10.

**Task 3**
Create a templated RingQueue class with a static array.

## The responsibilies of each member
**Juma Khan Gulami**
Created the templated Queue class.

**Samuel Embaye**
Created the binary search and advised Carl on threads and class creation.

**Rimsha Tauseef**
Created the way we generate and shuffel our customers. Also for writing and reading from file.

**Carl Broman**
Created relevant classes (except Queue), threading, RingQueue and assemble the code written by everyone.

### Program in it's whole
We have created a simulated Health Clinic where we have two thread working simultainously. One is responsible for generating new potential clients to the queue and the other is for "handling" the clients by looking for them in our customer system.
