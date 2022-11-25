# Docker tutorial(2)
###### tags: `Docker tutorial`

## Sharing our App

### Create a Repo
1. Go to Docker Hub and log in if you need to.
2. Click the Create Repository button.
3. For the repo name, use getting-started. Make sure the Visibility is Public.
4. Click the Create button!
![](https://i.imgur.com/AfVWf9x.png)

### Pushing out Image
- show image information
```
docker image ls
```
- Login to the Docker Hub
```
docker login -u Your-Uesr-Name
```
- gave docker getting-started image new name
```
docker tag getting-started YOUR-USER-NAME/getting-started
```
- push command. if you don't specify a tag, Docker will use a tag called `latest`
```
docker push YOUR-USER-NAME/getting-started
```

