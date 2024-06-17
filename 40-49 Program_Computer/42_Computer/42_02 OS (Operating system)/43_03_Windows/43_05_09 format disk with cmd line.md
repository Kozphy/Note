#windows 

## Source
https://www.tomshardware.com/news/format-hard-drive-command-prompt,37632.html

https://www.seagate.com/tw/zh/support/kb/how-to-diskpart-eraseclean-a-drive-through-the-command-prompt-005929en/#:~:text=From%20the%20command%20prompt%2C%20type,appear%20in%20a%20text%20format.

https://4ddig.tenorshare.com/windows-recovery-solutions/windows-cannot-run-disk-checking-on-this-volume-because-it-is-write-protected.html

## How to Fix Windows Cannot Run Disk Checking on This Volume Because It is Write Protected?
![](Pasted%20image%2020240605170646.png)

### type following command in cmd line
```cmd
reg add "HKEY_LOCAL_MACHINE\SYSTEM\
CurrentControlSet\
Control\StorageDevicePolicies" /v WriteProtect 
/t REG_DWORD /d 0 /f
```


## how to fix diskpart doesn't detect new SSD in cmd?
![](Pasted%20image%2020240605170406.png)
