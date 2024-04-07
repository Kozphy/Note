#wsl


## list wsl
```cmd
wsl --list
```

## export wsl distribution
```cmd
wsl --export Ubuntu-20.04 ubuntubackup.tar
```

## import wsl distribution
```cmd
wsl --import (distribution) (install location) (file location and filename)
```

### implement import
```cmd
wsl --import Ubuntu-20.04 C:\WSL\Ubuntu-20.04 ubuntubackup.tar
```
