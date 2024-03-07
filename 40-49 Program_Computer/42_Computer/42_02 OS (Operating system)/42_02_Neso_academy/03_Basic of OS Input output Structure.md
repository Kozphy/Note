#OS 
![](https://i.imgur.com/uP7Z9Mw.png)

## IO structure
- device controller
- common bus
- device driver

## Working of an I/O Operation
![](https://i.imgur.com/JBmO4Z0.png)

### Start I/O operation
1. device driver loads registers within device controller.
2. device controller examines the contents of registers.
3. controller transfer data to `local buffer`
4. After transfer is complete, device controller informs device driver via interrupt.
5. device driver returns control to os.

Above step is fine for moving small data, so we use `DMA` (Direct Memory Access) instead.
### DMA
The first three steps are the same as above.

After completing the first three steps, we proceed with following steps to achieve `DMA`.
![](https://i.imgur.com/pMYunFJ.png)
