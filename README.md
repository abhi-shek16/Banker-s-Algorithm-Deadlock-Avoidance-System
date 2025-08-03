
# 🏦 Banker's Algorithm – Deadlock Avoidance System

## 💡 Description

Developed a command-line tool in C++ to simulate the Banker's Algorithm for deadlock avoidance in operating systems. The system calculates the Need matrix and determines if a safe execution sequence exists based on resource allocation and maximum demands. Utilized dynamic memory structures (`std::vector`) and implemented user-driven input to handle varying numbers of processes and resources.

## 🛠️ Technologies Used
- C++
- STL (`vector`)
- Operating Systems Concepts
- Safe Sequence Detection Logic

## 📋 Features
- Takes user input for:
  - Allocation matrix
  - Maximum demand matrix
  - Available resources
- Dynamically calculates the Need matrix
- Checks system safety using the Banker's safety algorithm
- Displays safe execution sequence if possible

## 🚀 Sample Usage

```bash
g++ bankers_algorithm.cpp -o bankers
./bankers
