# wsl install docker without docker desktop
###### tags: `docker`

[setup wsl](https://docs.microsoft.com/en-us/windows/wsl/install)

[The regular Docker for Linux can work properly in WSL2. Please follow Docker's official document to install.](https://docs.docker.com/engine/install/ubuntu/#installation-methods)

WSL2 has an issue of the Docker daemon service not being started by default. Please put this line to ~/.bashrc to automatically start it when login:
```bash=
wsl.exe -u root service docker status > /dev/null || wsl.exe -u root service docker start > /dev/null
```
also for DNS resolution:
https://gist.github.com/coltenkrauter/608cfe02319ce60facd76373249b8ca6