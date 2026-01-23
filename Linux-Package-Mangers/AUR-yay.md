# AUR (Arch User Repository) and Yay Package Manager Guide

## Introduction to AUR and Yay

The Arch User Repository (AUR) is a community-driven repository for Arch users. It contains package descriptions called PKGBUILDs that allow you to build and install packages from source. Yay (Yet Another Yogurt) is an AUR helper that simplifies the process of installing AUR packages.

## Installing Yay

### Prerequisites
Before installing Yay, ensure you have git and base-devel installed:
```bash
sudo pacman -S git base-devel
```

### Installation
```bash
git clone https://aur.archlinux.org/yay.git
cd yay
makepkg -si
```

Or install from the official repositories if available:
```bash
sudo pacman -S yay
```

## Basic AUR and Yay Commands

### Searching for Packages
- **Search for a package in both repositories and AUR:**
  ```bash
  yay -Ss package-name
  ```
- **Search for installed packages:**
  ```bash
  yay -Qs package-name
  ```
- **Search for packages from AUR only:**
  ```bash
  yay -As package-name
  ```

### Installing Packages
- **Install a package (from both repo and AUR):**
  ```bash
  yay -S package-name
  ```
- **Install a package from AUR only:**
  ```bash
  yay -S aur-package-name
  ```
- **Install multiple packages:**
  ```bash
  yay -S package1 package2 package3
  ```
- **Install a local package file:**
  ```bash
  yay -U /path/to/package.tar.zst
  ```

### Removing Packages
- **Remove a package:**
  ```bash
  yay -R package-name
  ```
- **Remove a package and its dependencies that are no longer needed:**
  ```bash
  yay -Rns package-name
  ```
- **Remove a package but keep dependencies:**
  ```bash
  yay -Rs package-name
  ```

### Updating Packages
- **Update all packages (both repo and AUR):**
  ```bash
  yay -Syu
  ```
- **Update only AUR packages:**
  ```bash
  yay -Sua
  ```
- **Update only repository packages:**
  ```bash
  yay -Su
  ```
- **Update without confirmation prompt:**
  ```bash
  yay -Syu --noconfirm
  ```

### Querying and Information
- **Get information about a package (from repo and AUR):**
  ```bash
  yay -Si package-name
  ```
- **Get information about an installed package:**
  ```bash
  yay -Qi package-name
  ```
- **List all installed packages:**
  ```bash
  yay -Q
  ```
- **List explicitly installed packages:**
  ```bash
  yay -Qe
  ```
- **List packages from AUR that are installed:**
  ```bash
  yay -Qm
  ```

## Advanced Yay Features

### Build and Installation Options
- **Edit PKGBUILD before building:**
  ```bash
  yay -S --editmenu package-name
  ```
- **Show diffs of PKGBUILD before building:**
  ```bash
  yay -S --diffmenu package-name
  ```
- **Build packages in a clean chroot:**
  ```bash
  yay -S --cleanafter package-name
  ```
- **Skip dependency checks:**
  ```bash
  yay -S --nodeps package-name
  ```

### Clean and Maintenance
- **Remove orphans (packages not required by any installed package):**
  ```bash
  yay -Yc
  ```
- **Clean package cache:**
  ```bash
  yay -Sc
  ```
- **Clean all package cache:**
  ```bash
  yay -Scc
  ```
- **Clean yay build directory:**
  ```bash
  yay -Sc --aur
  ```

### AUR-specific Commands
- **Download PKGBUILD without building:**
  ```bash
  yay --getpkgbuild package-name
  ```
- **Submit AUR vote for a package:**
  ```bash
  yay --aur --vote package-name
  ```
- **Remove AUR vote for a package:**
  ```bash
  yay --aur --unvote package-name
  ```

## Alternative AUR Helpers

While Yay is popular, there are other AUR helpers:
- **Paru**: A rewrite of Yay in Rust with similar functionality
- **AURMAN**: A simple AUR helper with pacman-like syntax
- **PACAUR**: A lightweight AUR helper

## Troubleshooting AUR Issues

### Common Problems and Solutions
- **Failed to build package:**
  - Ensure base-devel is installed: `sudo pacman -S base-devel`
  - Check if dependencies are satisfied
  - Look for errors in the build output

- **GPG signature errors:**
  ```bash
  gpg --recv-keys <key-id>
  ```

- **Out of disk space during build:**
  - Clean package cache: `yay -Scc`
  - Clean yay build directory: `rm -rf ~/.cache/yay/*`

- **Repository sync issues:**
  ```bash
  sudo pacman -Syy
  ```

### Safety Considerations
- **Always verify PKGBUILDs** before building packages from unfamiliar maintainers
- **Use `--diffmenu`** to review changes before installing
- **Be cautious with `--noconfirm`** flag as it skips verification steps
- **Keep system updated** to avoid dependency conflicts

## Configuration

### Yay Configuration File
Yay configuration is stored in `~/.config/yay/config.json`. You can edit it directly or use:
```bash
yay --gendb  # Generate config file if it doesn't exist
```

### Useful Configuration Options
- `--devel`: Include -git, -svn, -hg packages in updates
- `--topdown`: Show repository packages first in search results
- `--bottomup`: Show AUR packages first in search results
- `--cleanafter`: Clean up build files after installation

## Best Practices

1. **Check official repositories first** before installing from AUR
2. **Review PKGBUILDs** and .install files before installing
3. **Keep AUR packages updated** regularly with `yay -Syu`
4. **Periodically clean package cache** to save disk space
5. **Use AUR packages responsibly** - they're not officially supported

## Additional Resources

- [AUR Submission Guidelines](https://wiki.archlinux.org/index.php/AUR_submission_guidelines)
- [AUR Helpers Comparison](https://wiki.archlinux.org/index.php/AUR_helpers)
- [Yay GitHub Repository](https://github.com/Jguer/yay)
- [ArchWiki AUR Page](https://wiki.archlinux.org/index.php/Arch_User_Repository)