# Ubuntu Package Management Guide (APT)

## Introduction to APT

APT (Advanced Package Tool) is the default package management system for Ubuntu and other Debian-based distributions. It provides a high-level interface for managing packages, dependencies, and repositories.

## Basic APT Commands

### Updating Package Lists
- **Update package lists:**
  ```bash
  sudo apt update
  ```
- **Update package lists and upgrade packages:**
  ```bash
  sudo apt update && sudo apt upgrade
  ```

### Installing Packages
- **Install a package:**
  ```bash
  sudo apt install package-name
  ```
- **Install multiple packages:**
  ```bash
  sudo apt install package1 package2 package3
  ```
- **Install a specific version of a package:**
  ```bash
  sudo apt install package-name=version
  ```
- **Install a local .deb package:**
  ```bash
  sudo dpkg -i /path/to/package.deb
  sudo apt install -f  # Fix any dependency issues
  ```

### Removing Packages
- **Remove a package (keep configuration files):**
  ```bash
  sudo apt remove package-name
  ```
- **Remove a package and configuration files:**
  ```bash
  sudo apt purge package-name
  ```
- **Remove a package and unused dependencies:**
  ```bash
  sudo apt autoremove package-name
  ```
- **Remove unused dependencies:**
  ```bash
  sudo apt autoremove
  ```

### Searching and Information
- **Search for a package:**
  ```bash
  apt search package-name
  ```
- **Show detailed information about a package:**
  ```bash
  apt show package-name
  ```
- **List installed packages:**
  ```bash
  apt list --installed
  ```
- **List available updates:**
  ```bash
  apt list --upgradable
  ```
- **Show dependencies of a package:**
  ```bash
  apt depends package-name
  ```
- **Show reverse dependencies:**
  ```bash
  apt rdepends package-name
  ```

## Advanced APT Commands

### Upgrading System
- **Upgrade all packages:**
  ```bash
  sudo apt upgrade
  ```
- **Upgrade packages with smart dependency handling:**
  ```bash
  sudo apt full-upgrade
  # Alternative: sudo apt dist-upgrade
  ```
- **Upgrade to a new Ubuntu release:**
  ```bash
  sudo do-release-upgrade
  ```

### Package Hold and Configuration
- **Hold a package to prevent updates:**
  ```bash
  sudo apt-mark hold package-name
  ```
- **Remove hold on a package:**
  ```bash
  sudo apt-mark unhold package-name
  ```
- **List held packages:**
  ```bash
  apt-mark showhold
  ```
- **Configure a package:**
  ```bash
  sudo dpkg-reconfigure package-name
  ```

### Cache Management
- **Clean package cache:**
  ```bash
  sudo apt autoclean
  ```
- **Remove all cached packages:**
  ```bash
  sudo apt clean
  ```
- **Download package without installing:**
  ```bash
  apt download package-name
  ```

## Snap Package Management

Ubuntu also supports Snap packages, which are containerized software packages. Snaps are self-contained applications that bundle all their dependencies, ensuring consistent behavior across different Ubuntu releases and other Linux distributions.

### Installing and Managing Snaps
- **Install a snap:**
  ```bash
  sudo snap install snap-name
  ```
- **Install a snap from a specific channel:**
  ```bash
  sudo snap install snap-name --channel=channel-name  # e.g., --channel=beta
  ```
- **Install a snap with classic confinement (if needed):**
  ```bash
  sudo snap install snap-name --classic
  ```
- **Remove a snap:**
  ```bash
  sudo snap remove snap-name
  ```
- **List installed snaps:**
  ```bash
  snap list
  ```
- **Get information about a snap:**
  ```bash
  snap info snap-name
  ```
- **Find snaps in the store:**
  ```bash
  snap find search-term
  ```

### Snap Updates and Maintenance
- **Update all snaps:**
  ```bash
  sudo snap refresh
  ```
- **Update specific snap:**
  ```bash
  sudo snap refresh snap-name
  ```
- **Update specific snap to a specific channel:**
  ```bash
  sudo snap refresh snap-name --channel=channel-name
  ```
- **Rollback a snap to previous version:**
  ```bash
  sudo snap revert snap-name
  ```
- **Check for available updates:**
  ```bash
  snap refresh --list
  ```
- **Hold updates for a snap (pause updates for up to 90 days):**
  ```bash
  sudo snap refresh snap-name --hold
  ```
- **Resume updates for a snap:**
  ```bash
  sudo snap refresh snap-name --unhold
  ```

### Snap Services and Configuration
- **List snap services:**
  ```bash
  snap services
  ```
- **Start a snap service:**
  ```bash
  sudo snap start snap-name.service-name
  ```
- **Stop a snap service:**
  ```bash
  sudo snap stop snap-name.service-name
  ```
- **Restart a snap service:**
  ```bash
  sudo snap restart snap-name.service-name
  ```
- **Get snap configuration:**
  ```bash
  snap get snap-name
  ```
- **Set snap configuration:**
  ```bash
  snap set snap-name key=value
  ```
- **Connect snap interfaces (plugs and slots):**
  ```bash
  sudo snap connect snap-name:plug interface-name:slot
  ```
- **Disconnect snap interfaces:**
  ```bash
  sudo snap disconnect snap-name:plug interface-name:slot
  ```

### Snap System Management
- **Enable a snap:**
  ```bash
  sudo snap enable snap-name
  ```
- **Disable a snap:**
  ```bash
  sudo snap disable snap-name
  ```
- **View snap logs:**
  ```bash
  sudo snap logs snap-name
  ```
- **Check snap system status:**
  ```bash
  snap version
  ```
- **Repair broken snap connections:**
  ```bash
  sudo snap repair run
  ```
- **Check snap repair status:**
  ```bash
  snap repair status
  ```

### Snap Channels and Revisions
- **List available channels for a snap:**
  ```bash
  snap info snap-name | grep channel
  ```
- **Switch a snap to a different channel:**
  ```bash
  sudo snap refresh snap-name --channel=channel-name
  ```
- **List snap revisions:**
  ```bash
  snap list --all snap-name
  ```
- **Switch to a specific revision:**
  ```bash
  sudo snap revert snap-name --revision=revision-number
  ```

## Flatpak Package Management

Flatpak is another universal package format supported on Ubuntu.

### Flatpak Commands
- **Install Flatpak:**
  ```bash
  sudo apt install flatpak
  ```
- **Add Flathub repository:**
  ```bash
  flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
  ```
- **Install a Flatpak:**
  ```bash
  flatpak install flathub app-id
  ```
- **Uninstall a Flatpak:**
  ```bash
  flatpak uninstall app-id
  ```
- **List installed Flatpaks:**
  ```bash
  flatpak list
  ```
- **Update Flatpaks:**
  ```bash
  flatpak update
  ```

## Repository Management

### Adding/Removing Repositories
- **Add a repository:**
  ```bash
  sudo add-apt-repository ppa:repository-name
  ```
- **Remove a repository:**
  ```bash
  sudo add-apt-repository --remove ppa:repository-name
  ```
- **Add a repository with key:**
  ```bash
  curl -fsSL https://repo-url/gpg | sudo gpg --dearmor -o /usr/share/keyrings/repo.gpg
  echo "deb [signed-by=/usr/share/keyrings/repo.gpg] https://repo-url/ $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/repo.list
  ```

### Managing Keys
- **List keys:**
  ```bash
  apt-key list
  ```
- **Add a key:**
  ```bash
  sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys KEY_ID
  ```
- **Remove a key:**
  ```bash
  sudo apt-key del KEY_ID
  ```

## Troubleshooting

### Common Issues and Solutions
- **Fix broken packages:**
  ```bash
  sudo apt --fix-broken install
  ```
- **Reinstall a package:**
  ```bash
  sudo apt remove package-name
  sudo apt install package-name
  ```
- **Force overwrite of files during installation:**
  ```bash
  sudo apt -o Dpkg::Options::="--force-confold" install package-name
  ```
- **Clean and update if APT is locked:**
  ```bash
  sudo rm /var/lib/dpkg/lock-frontend
  sudo rm /var/lib/dpkg/lock
  sudo dpkg --configure -a
  sudo apt update
  ```

### Dependency Issues
- **Identify unmet dependencies:**
  ```bash
  apt-cache depends package-name
  ```
- **Simulate installation to check for conflicts:**
  ```bash
  apt install --dry-run package-name
  ```

### System Recovery
- **Reinstall Ubuntu desktop environment:**
  ```bash
  sudo apt install --reinstall ubuntu-desktop
  ```
- **Reinstall GRUB bootloader:**
  ```bash
  sudo apt install --reinstall grub-pc
  ```

## Package Policy and Security

### Security Updates
- **Check for security updates only:**
  ```bash
  apt list --upgradable | grep -i security
  ```
- **Apply only security updates:**
  ```bash
  sudo unattended-upgrade
  ```

### Package Verification
- **Check MD5 sums of packages:**
  ```bash
  apt-ftparchive packages directory/ | grep package-name
  ```

## Performance Tips

- **Use apt-fast for faster downloads:**
  ```bash
  sudo apt install aria2
  # Install apt-fast from GitHub
  ```
- **Limit bandwidth usage:**
  ```bash
  sudo apt -o Acquire::http::Dl-Limit=50 update  # Limit to 50KB/s
  ```

## Additional Resources

- [Ubuntu Package Management Guide](https://help.ubuntu.com/community/PackageManagerGuide)
- [APT Manual](https://manpages.ubuntu.com/manpages/latest/man8/apt.8.html)
- [Ubuntu PPA Guide](https://launchpad.net/ubuntu/+ppas)
- [Snapcraft Documentation](https://snapcraft.io/docs)
- [Ubuntu Repositories Guide](https://help.ubuntu.com/community/Repositories/Ubuntu)