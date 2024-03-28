#github

## Source
[Git Restore and Git Reset (academind.com)](https://academind.com/tutorials/git-restore-and-git-reset)
[How to Remove Files from Git Commit | Git Remove File from Commit Stage – Junos Notes](https://www.junosnotes.com/git/how-to-remove-files-from-git-commit/#:~:text=In%20order%20to%20remove%20a,that%20you%20want%20to%20remove.&text=When%20you%20are%20done%20with%20the%20modifications%2C%20your%20file%20will,back%20in%20the%20staging%20area.)
## proper noun
- working tree => Git directory where you edit your files, before adding them to the stagning area or committing them to the repository.
## Type of undo changes
- `Unstaged changes` (change working tree file to last commit)
- `Staged changes` (stage to unstaged)
- `Commits` (commit to uncommits)

## git restore (Undo `Unstaged` Changes)
It will restore the file to the `last committed version`.
```git
git restore <filename>
```

or
```git
git restore .
```

## git reset (Undo `Staged` changes)
```git
git reset <filename>
```

or 

```git
git reset .
```

##  Undo Commits (UnCommit)
### step 1
This will jump back to earlier commit and file changes are still kept as unstaged changes.
```git
git reset HEAD~1
```

### step 2
if we want to delete a newly commit, executing following git cmd will accomplish it.
```git
git restore .
```

We can combine above two step by using following git cmd. 
```git
git reset --hard HEAD~1
```

## Remove Specific file from git stage
```git
git reset HEAD <file>
```

## Remove Specific file from git local repository [git rm](https://www.git-tower.com/learn/git/commands/git-rm#:~:text=The%20"rm"%20command%20helps%20you,editor%2C%20IDE%20or%20file%20browser.)
```git
git rm <file>
git add .
```
![](Pasted%20image%2020240307100123.png)



