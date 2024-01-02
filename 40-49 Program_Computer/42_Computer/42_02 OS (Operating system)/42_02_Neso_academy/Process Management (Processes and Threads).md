#OS
## Process vs Thread
![](https://i.imgur.com/aXuvijR.png)

![](https://i.imgur.com/LdMs0M9.png)

### Process 行程(進程)/處理(程)序
A process is an `independent` and self-contained unit of execution in an operating system. 

It can be considered as an instance of a running program. 

Each process has its own memory space, system resources, and program code. 

Processes are isolated from each other, meaning one process cannot directly access the memory or resources of another process.

#### Key characteristics of a process:
1.  **Memory Isolation:** Each process has its own memory space, preventing one process from directly accessing the memory of another process.
3.  **Independent Execution:** Processes run independently of each other. They have their own copy of data and resources.
3.  **Inter-Process Communication (IPC):** Processes can communicate with each other through mechanisms such as pipes, sockets, or shared memory.
4.  **Resource Management:** Each process has its own set of system resources, such as file descriptors, open network connections, and environment variables.
    

### Thread 執行續(線程)
A thread is the smallest unit of execution within a process. 

Threads are contained within a process and `share the same memory space and resources` of the process that created them. 

Threads within the same process can directly access and modify shared data, which allows for more efficient communication and coordination among tasks.

Key characteristics of a thread:
1. **Shared Memory:** Threads within the same process share the same memory space, allowing them to access shared data directly.
2. **Lightweight:** Creating and managing threads is generally more lightweight and faster than creating and managing processes.
3. **Concurrent Execution:** Threads within the same process can execute concurrently, meaning multiple threads can run at the same time on multi-core processors.
4. **Resource Sharing:** Since threads share the same resources of the parent process, care must be taken to synchronize access to shared data to avoid data inconsistencies.

