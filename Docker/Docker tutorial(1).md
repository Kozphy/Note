# Docker tutorial(1)
###### tags: `Docker tutorial`

## Getting Started
### The command you just ran
-   `-d` \- run the container in detached mode (in the background)
-   `-p 80:80` \- map port 80 of the host to port 80 in the container
-   `docker/getting-started` \- the image to use
```
docker run -d -p 80:80 docker/getting-started
```
---
## Our Application
### Dockerfile
A Dockerfile is simply a text-based script of instructions that is used to create a container image.
```
FROM node:12-alpine
WORKDIR /app
COPY . .
RUN yarn install --production
CMD ["node", "src/index.js"]
```

### build
This command used the Dockerfile to build a new container image.

Finally, the `-t` flag tags our image. Think of this simply as a human-readable name for the final image. Since we named the image getting-started, we can refer to that image when we run a container.

The `.` at the end of the docker build command tells that Docker should look for the Dockerfile in the current directory.
```
docker build -t getting-started .
```

### Starting an App Container
Start your container using the `docker run` command and specify the name of the image we just created:
```
docker run -dp 3000:3000 getting-started
```

## Updating our Source Code
After updating our program, we need to replace our old container, otherwise the old container will still run on host's port.

Before replacing the old container, we need to remove it that first needs to be stopped. Once it has stopped, it can be removed.

We have two ways that we can remove the old container.
### Removing a container using the CLI
1. Get the ID of the container by using the docker ps command.
```
docker ps
```
2. Use the docker stop command to stop the container.
```
# Swap out <the-container-id> with the ID from docker ps
docker stop <the-container-id>
```
3. Once the container has stopped, you can remove it by using the docker rm command.
```
docker rm <the-container-id>
```

> ### Pro tips
>You can stop and remove a container in a single command by adding the "force" flag to the docker rm command. For example: `docker rm -f <the-container-id>`

### Removing a container using the Docker Dashboard
![](https://i.imgur.com/rYoSuUv.png)

## Starting out updated app container
```
docker run -dp 3000:3000 getting-started
```