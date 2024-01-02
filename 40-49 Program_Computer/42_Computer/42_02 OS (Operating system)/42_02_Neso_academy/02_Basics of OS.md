#OS 

![](https://i.imgur.com/Am0QXlU.png)

- Each `device controller` is in charge of a specific type of device.
- The `CPU` and the `device controllers` can execute concurrently, competing for memory cycles.
- To ensure orderly access to the shared memory, a `memory controller` is provided whose function is synchronize access to the memory.

## Some important terms
1. Bootstrap Program
    - The `initial program` that runs when a computer is powerd up or rebooted.
    - It's stored in the `ROM`.
    - it must know how to load the OS and start executing that system.
    - It must locate and load into memory the OS Kernel.
2. Interrupt (usually use this in Hardware)
    - The occurence of an event is usually signalled by an Interrupt from Hardware or Software.
    - `Hardware` may trigger on interrupt at any time by sending a signal to the CPU, usually by the way of the system bus.
3. System Call (Monitor call)
    - `Software` may trigger an interrupt by executing a special operation called System Call.
