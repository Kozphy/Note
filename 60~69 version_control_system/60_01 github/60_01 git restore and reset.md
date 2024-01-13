#github

## Source
[Git Restore and Git Reset (academind.com)](https://academind.com/tutorials/git-restore-and-git-reset)

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




