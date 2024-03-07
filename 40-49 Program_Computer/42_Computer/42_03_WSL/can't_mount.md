# Fix: “An error occurred mounting one of your file systems” on WSL

## [Source](https://appuals.com/an-error-occurred-mounting-one-of-your-file-systems/)

## first step

The first thing that you should do when you encounter the problem in question is to try to update Windows Subsystem for Linux which in turn will essentially update your Linux kernel.

In windows `open the terminal with administrator privileges` and type following.

```cmd
wsl --update
```