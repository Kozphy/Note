#program 


https://learn.microsoft.com/en-us/windows/win32/ipc/interprocess-communications#using-pipes-for-ipc	

## From gpt
1. **Separate Executables**:
    - If you want to keep the C# and Go parts separate but still have them in the same project, you can create two separate executables (one for each language).
    - Each executable can communicate with the other using inter-process communication (IPC) mechanisms like `pipes, sockets, or HTTP APIs`.
    - This approach allows you to maintain the distinct nature of both languages while achieving integration.