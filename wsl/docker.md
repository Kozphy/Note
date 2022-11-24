# Docker

## start docker

[Source](https://stackoverflow.com/questions/44678725/cannot-connect-to-the-docker-daemon-at-unix-var-run-docker-sock-is-the-docker)

when you encounter `unix:/var/run/docker.sock.` in wsl, attempting typing following in terminal to fix problems.

```cmd
sudo service docker start
```
