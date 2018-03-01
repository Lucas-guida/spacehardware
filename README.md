# Spacehardware Basic Git Commands

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

# Check to see if Anaconda is connected to OM
```
from OMPython import OMCSessionZMQ
omc = OMCSessionZMQ()
```

# The file unittest is used to test the code
## 1) Remember to import the function at the top of the file
```
from filename import functionname
```
## 2) Create a test case
```
def test_functionName(self):
  self.assertEqual(function(paramater),Expexted Answer)
```

# Creating the coverage report
## 1) open anaconda prompt and type
```
pip install coverage
```
## 2) navitage to directory and run
```
coverage run unittest.py
```
This runs the unittester and checks the code coverage of all supporting functions and the unittester itself

## 3) Generate command line report
```
coverage report
```
