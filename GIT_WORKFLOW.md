# git workflow cheatsheet

### assessing the current situation
git status
git status -v
git status --branch
git ls-files
git log
git show
git show <tagName>
git show <first5or10digitsOfCommitHash>
git diff
git tag
git version

### committing, sequential commands. For FUNCTIONAL code. Never broken code.
``` console
git status
git fetch
git pull
git add <path/to/your/files>
git commit -m "<Your commit message here>"
git push
```

### OH NOOOSSS! MERGE CONFLICT!
``` console
# try this first
git mergetool

# if you're stuck, abort takes you back to the initial state (as long as you committed before merging)
git merge --abort
```

### checking if the remote repo is different than your own
``` console
git fetch
git log HEAD..remotes/origin/<branchName>
```

### tagging, for completed features. Common use is after a merge commit. Note that tags are pushed seperately from commits.
``` console 
git tag -a v<tagNumberHereOrNameHere> -m "<your mandatory tag message here>"
git push --tag
```

############################ Danger zone, removing or unstaging files #########################

### COMPLETELY unstaging a file, leaves you with an untracked file. Does not remove from working directory.
``` console
git rm --cached <filePath>
```

### unstaging any changes since the last commit.
``` console
git reset -- <filePath>
```

### deleting a LOCAL branch
``` console
git branch -d <branchName>
git branch --delete --force <branchName>
```

### reverting to previous files/commits
``` console
<currently beyond the scope of this cheat sheet, ask for assistance and this will be updated if a standard workflow is discovered>
```

### tools for resolving merge conflicts
``` console
git status
git log --merge
git diff
git mergetool

# if you know vim, this is powerful
# uses :diffget REMOTE/LOCAL/?ORIGINAL? 
git mergetool tool=vimdiff

```
