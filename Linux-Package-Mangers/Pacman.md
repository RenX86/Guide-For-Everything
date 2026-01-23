# Pacman Package Manager Command Guide

Pacman is the default package manager for Arch Linux and its derivatives. This guide provides comprehensive commands for managing packages, repositories, and system maintenance.

## 1. Package Database Management

### Synchronization and Updates
- **Update package lists:**
  ```bash
  sudo pacman -Sy
  ```
- **Upgrade all packages:**
  ```bash
  sudo pacman -Syu
  ```
- **Force database refresh and upgrade:**
  ```bash
  sudo pacman -Syyu
  ```
- **Downgrade a package (requires cached package):**
  ```bash
  sudo pacman -U /var/cache/pacman/pkg/package-name-version.pkg.tar.zst
  ```

## 2. Installing Packages

### Package Installation Commands
- **Install a package:**
  ```bash
  sudo pacman -S package-name
  ```
- **Install multiple packages:**
  ```bash
  sudo pacman -S package1 package2 package3
  ```
- **Install a package group:**
  ```bash
  sudo pacman -S gnome
  ```
- **Install a local package file:**
  ```bash
  sudo pacman -U /path/to/package.pkg.tar.zst
  ```
- **Install a package from a specific repository:**
  ```bash
  sudo pacman -S extra/package-name
  ```

## 3. Removing Packages

### Package Removal Commands
- **Remove a package (keeping dependencies):**
  ```bash
  sudo pacman -R package-name
  ```
- **Remove a package and unused dependencies:**
  ```bash
  sudo pacman -Rns package-name
  ```
- **Remove a package but keep its dependencies:**
  ```bash
  sudo pacman -R package-name
  ```
- **Remove a package and its dependencies, but keep required ones:**
  ```bash
  sudo pacman -Rsc package-name
  ```

## 4. Querying and Searching

### Package Information Commands
- **Search for a package in the database:**
  ```bash
  pacman -Ss package-name
  ```
- **Search for an installed package:**
  ```bash
  pacman -Qs package-name
  ```
- **List all installed packages:**
  ```bash
  pacman -Q
  ```
- **Show details of an installed package:**
  ```bash
  pacman -Qi package-name
  ```
- **Show files installed by a package:**
  ```bash
  pacman -Ql package-name
  ```
- **Find which package owns a file:**
  ```bash
  pacman -Qo /path/to/file
  ```

## 5. Cleaning Up

### System Maintenance Commands
- **Remove orphaned packages:**
  ```bash
  sudo pacman -Rns $(pacman -Qdtq)
  ```
- **Clear package cache (except latest 3 versions):**
  ```bash
  sudo paccache -r
  ```
- **Clear entire package cache:**
  ```bash
  sudo pacman -Scc
  ```

## 6. Handling Keys and Verification Issues

### Keyring Management
- **Manually refresh keyring:**
  ```bash
  sudo pacman-key --init
  sudo pacman-Key --populate archlinux
  ```
- **Manually import a specific key:**
  ```bash
  sudo pacman-key --recv-keys key-ID
  ```
- **Sign a key manually:**
  ```bash
  sudo pacman-key --lsign-key key-ID
  ```

## 7. Working with AUR (Arch User Repository)

Pacman does not support AUR by default. You need an AUR helper like yay or paru.

### AUR Helper Commands
- **Install a package from AUR using yay:**
  ```bash
  yay -S package-name
  ```
- **Search for an AUR package:**
  ```bash
  yay -Ss package-name
  ```
- **Upgrade AUR packages:**
  ```bash
  yay -Syu
  ```
- **Remove an AUR package:**
  ```bash
  yay -Rns package-name
  ```

## 8. Troubleshooting

### Common Issues and Solutions
- **Fix a locked database:**
  ```bash
  sudo rm /var/lib/pacman/db.lck
  ```
- **Check for broken dependencies:**
  ```bash
  pacman -Qkk
  ```
- **Manually reinstall a package:**
  ```bash
  sudo pacman -S package-name --overwrite '*'
  ```
- **Force install even if files exist:**
  ```bash
  sudo pacman -S package-name --overwrite '*'
  ```

## 9. Additional Resources

- [ArchWiki Pacman](https://wiki.archlinux.org/index.php/Pacman)
- [ArchWiki Pacman Tips](https://wiki.archlinux.org/index.php/Pacman_tips)