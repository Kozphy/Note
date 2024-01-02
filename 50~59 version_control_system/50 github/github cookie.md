# github cookie
###### tags: `github note`

## clone the repository
Click on the clone button and click the copy to clipboard icon.
![](https://i.imgur.com/OpAL538.png)
```git=
git clone "url you just copied"
```

## Create a branch for your edits.
Branching exists to help you manage the different ideas or features in progress. When you create a branch, you're creating an environment where you can try new ideas without affecting the master branch. Therefore, experiment and commit changes, as these won't be merged until they're ready to be reviewed by other collaborator.

```python=
git checkout -b <add-your-name>
```

## Make changes and commit them
Whenever you add, edit or delete a file, you're making a commit, and adding them to your branch. This process keeps track of your progress as you work on a feature branch.

Commit also create a transparent history of your work that other can follow to understand what you've done and why.

For ex, you open a Contibutes.md file in a text editor, add your name and save it. Go to the project directory and execute `git status`, you'll see there the changes. Add those changes to the branch, with command `git add`

```git=
git add.
```

And commit them using `git commit`
```git=
git commit -m "Add <your-name> to Contributors list"
```

**Push** the changes to Github
```git=
git push origin <add-your-name>
```

Now, let's **pull request**
What we are doing here is basically propose and collaborate on changes to a repository.

1. Navigate to the main page of the repository.
2. In the **Branch** menu, choose the branch that contains your commits.
![](https://i.imgur.com/XPlBfVa.png)

3. To the right of the Branch menu, click **New Pull Request**
![](https://i.imgur.com/2mvaDWe.png)
4. Use the base branch dropdown menu to select the branch you'd like to merge your changes into, then use the compare branch drowpdown menu to choose the topic branch you made your changes in.
![](https://i.imgur.com/ZsQkuaM.png)
