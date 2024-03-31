# ssh connection

## [Source](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent)

- ssh
```git
# detect current os whether have ssh key and show
ls ~/.ssh

# create key 
# ssh-keygen == ssh-keygen tool
# -t rsa == type rsa
# -b 4096 == 4096byte
# -C == comment, just we want to identify what key this is for
ssh-keygen -t rsa -b 4096 -C "<what key you want to denote>"

# copy ssh key
cat ~/.ssh/<your public ssh key file>
```