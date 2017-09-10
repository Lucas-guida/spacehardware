# spacehardware Basic Git Commands

**Requires git to be installed** ask me if you need help

## Copy Repo
To download the files using the git terminal you will first need to clone the repo. To do this type:

```
git clone https://github.com/Lucas-guida/spacehardware.git
```

You will now have all the files stored on git.

Whenever you have make a small change to your code and your code is still working please use the following commands:

This line of code will add all your recent changes to the current commit
```
git add .
```

This is commiting your recently added changes... Think of it as a snapshot of your current code instance for archiving.
```
git commit -m "ENTER A SHORT DISCRIPTION OF YOUR CHANGES HERE"
```

To publish your **WORKING** code (from the master branch) to github type the following.
```
git push origin master
```
To obtain someones updated code (from the master branch) from github type the following.
```
git pull origin master
```

If your are not comfortable with terminal or git please install one of the desktop GUI that are avaiable:

https://git-scm.com/download/gui/win
