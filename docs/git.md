# Git Version Control Guide

A comprehensive guide from fundamental setup to advanced history manipulation and workflow optimization.

---

## 📥 Installation

Ensure Git is available on your local system.

### **Windows**

- Download the installer from [git-scm.com](https://git-scm.com/download/win).
- Recommended: Use **Git Bash** for a Unix-like terminal experience.

### **Linux**

```sh
# Arch Linux
sudo pacman -S git

# Ubuntu/Debian
sudo apt update && sudo apt install git
```

---

## ⚙️ Configuration

Set up your identity and global preferences.

### **User Identity**

```sh
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
```

### **Productivity Aliases**

Add these to your `~/.gitconfig` or run via CLI to speed up your workflow:

```sh
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.ci commit
git config --global alias.st status
git config --global alias.lg "log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold green)(%ar)%C(reset) %C(white)%s%C(reset) %C(dim white)- %an%C(reset)%C(bold yellow)%d%C(reset)' --all"
```

---

## 🚀 Advanced Workflow

### **1. Undoing Changes**

Git provides several ways to "go back in time" depending on where the changes are.

| Action | Command | Effect |
| :--- | :--- | :--- |
| **Unstage a file** | `git restore --staged <file>` | Moves file from "Staged" back to "Modified". |
| **Discard local changes** | `git restore <file>` | Reverts file to the last committed state. |
| **Amend last commit** | `git commit --amend --no-edit` | Adds staged changes to the previous commit. |
| **Soft Reset** | `git reset --soft HEAD~1` | Undoes the last commit but keeps changes staged. |
| **Hard Reset** | `git reset --hard HEAD~1` | **Destructive**: Deletes the last commit and all changes. |
| **Revert a commit** | `git revert <commit-hash>` | Creates a *new* commit that undoes a previous one. |

### **2. Stashing**

Temporarily shelf changes without committing them.

```sh
git stash push -m "work in progress"  # Save changes
git stash list                        # View saved stashes
git stash pop                         # Apply and remove the latest stash
git stash apply stash@{0}              # Apply specific stash without removing
```

---

## 🌿 Branching & History Management

### **Rebase vs. Merge**

- **Merge**: Creates a "merge commit". Preserves the exact chronological history but can become messy with many branches.
- **Rebase**: Moves your feature branch to the tip of the main branch. Results in a **linear history**.
  - *Rule of thumb: Never rebase branches that have been pushed to a shared repository.*

```sh
# Rebasing your feature branch onto main
git checkout feature/task
git rebase main
```

### **Interactive Rebase (Cleaning History)**

Use this to squash multiple small commits into one clean commit before merging.

```sh
git rebase -i HEAD~3  # Opens an editor for the last 3 commits
# Options: pick (keep), squash (combine), reword (change message), drop (remove)
```

### **Cherry-picking**

Apply a specific commit from one branch to another.

```sh
git cherry-pick <commit-hash>
```

---

## 🛠️ Conflict Resolution

Conflicts occur when Git cannot automatically merge changes.

1. **Identify**: `git status` shows files as `both modified`.
2. **Resolve**: Open the files and look for markers:

   ```text
   <<<<<<< HEAD
   Your changes
   =======
   Changes from the other branch
   >>>>>>> branch-name
   ```

3. **Stage**: `git add <file>`
4. **Continue**: `git merge --continue` or `git rebase --continue`

---

## 🔍 Investigation & Debugging

### **Reflog**

The "safety net". `reflog` tracks every single movement of `HEAD`, even if you deleted a branch or performed a hard reset.

```sh
git reflog
git reset --hard HEAD@{index} # Restore to any previous state
```

### **Bisect**

Find the exact commit that introduced a bug using binary search.

```sh
git bisect start
git bisect bad                 # Current version is broken
git bisect good <commit-hash>  # This old version was working
# Git will checkout commits in between; you test and mark them 'good' or 'bad'
git bisect reset               # Return to original state
```

---

## ✍️ Commit Message Conventions (Conventional Commits)

Maintain a readable history that tools can parse.

- `feat`: A new feature.
- `fix`: A bug fix.
- `docs`: Documentation changes.
- `refactor`: Code change that neither fixes a bug nor adds a feature.
- `chore`: Maintenance tasks (updating dependencies, etc.).
- `perf`: Code change that improves performance.

**Example**: `feat(auth): add OAuth2 provider support`
