# Docker 

###### tags: `docker`

docker not running on Ubuntu WSL due to error cannot connect to the Docker daemon at unix:///var/run/docker.sock. Is the docker daemon running?
## Problem
![](https://i.imgur.com/HWuQeyG.png)

[link](https://docs.docker.com/engine/install/ubuntu/)
### Solve my problem
#### Uninstall old versions
**The contents of /var/lib/docker/, including images, containers, volumes, and networks, are preserved. If you do not need to save your existing data, and want to start with a clean installation.**

remove all file in /var/lib/docker, will fix it.
