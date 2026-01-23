# Flatpak Package Management Guide

## Overview

Flatpak is a universal package management system for Linux that allows applications to be installed and run in a sandboxed environment, independent of the underlying distribution. It provides better security and compatibility by bundling applications with their dependencies.

## Installing Flatpak

### On Ubuntu/Debian:
```bash
sudo apt install flatpak
```

### On Fedora:
```bash
sudo dnf install flatpak
```

### On Arch Linux:
```bash
sudo pacman -S flatpak
```

### On CentOS/RHEL:
```bash
sudo dnf install flatpak
```

## Setting Up Repositories

### Adding Flathub Repository (recommended)
```bash
flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
```

### Adding GNOME Nightly Repository
```bash
flatpak remote-add --if-not-exists gnome-nightly https://nightly.gnome.org/gnome-nightly.flatpakrepo
```

### Listing configured repositories
```bash
flatpak remote-list
```

## Installing Applications

### Installing from Flathub
```bash
flatpak install flathub org.gimp.GIMP
```

### Installing specific version/branch
```bash
flatpak install flathub org.gimp.GIMP//stable
```

### Installing from other repositories
```bash
flatpak install gnome-nightly org.gnome.Builder
```

## Managing Applications

### Listing installed applications
```bash
flatpak list
```

### Getting application information
```bash
flatpak info org.gimp.GIMP
```

### Running applications
```bash
flatpak run org.gimp.GIMP
```

### Updating applications
```bash
# Update specific application
flatpak update org.gimp.GIMP

# Update all applications
flatpak update

# Update from specific remote
flatpak update --system flathub
```

### Uninstalling applications
```bash
flatpak uninstall org.gimp.GIMP
```

### Uninstalling unused dependencies
```bash
flatpak uninstall --unused
```

## Managing Permissions

### Checking permissions
```bash
flatpak override --show org.gimp.GIMP
```

### Granting permissions
```bash
# Allow access to home directory
flatpak override org.gimp.GIMP --filesystem=home

# Allow access to specific directories
flatpak override org.gimp.GIMP --filesystem=/path/to/directory

# Remove access to home directory
flatpak override org.gimp.GIMP --filesystem=home:delete

# Allow network access
flatpak override org.gimp.GIMP --socket=network

# Allow system D-Bus access
flatpak override org.gimp.GIMP --system-talk-name=*
```

## Advanced Management

### Installing application without running
```bash
flatpak install --app --noninteractive flathub org.gimp.GIMP
```

### Exporting applications to system
```bash
flatpak install --user flathub org.gimp.GIMP  # Install for current user only
```

### Managing system-wide vs user installations
```bash
# System installation (all users)
flatpak install flathub org.gimp.GIMP

# User installation (current user only)
flatpak install --user flathub org.gimp.GIMP

# List user installations
flatpak list --user

# List system installations
flatpak list --system
```

## Managing Runtimes

### Listing installed runtimes
```bash
flatpak list --runtime
```

### Installing runtimes
```bash
flatpak install flathub org.gnome.Platform//42
flatpak install flathub org.gnome.Sdk//42
```

### Updating runtimes
```bash
flatpak update --runtime
```

### Uninstalling unused runtimes
```bash
flatpak uninstall --unused
```

## Troubleshooting

### Reset application permissions
```bash
flatpak override --reset org.gimp.GIMP
```

### Repair Flatpak installation
```bash
flatpak repair
```

### Getting verbose output for debugging
```bash
flatpak install --verbose flathub org.gimp.GIMP
```

### Checking Flatpak version
```bash
flatpak --version
```

## Performance and Maintenance

### Cleaning up unused files
```bash
flatpak uninstall --unused
```

### Checking disk usage
```bash
flatpak repair --dry-run
```

### Managing updates automatically
```bash
# Enable automatic updates
flatpak update --assumeyes
```

## Creating Flatpak Applications

### Installing development tools
```bash
flatpak install flathub org.gnome.Sdk//42
```

### Building applications
```bash
flatpak run org.flatpak.Builder --help
```

## Best Practices

1. **Use Flathub** as the primary repository for most applications
2. **Keep runtimes updated** to ensure security and compatibility
3. **Check permissions** regularly to maintain security
4. **Uninstall unused applications** to save disk space
5. **Use system installations** for applications all users need
6. **Consider user installations** for personal applications

## Additional Commands

### Getting detailed information
```bash
flatpak --help
flatpak install --help
flatpak update --help
```

### Remote management
```bash
# Remove remote
flatpak remote-delete flathub

# Update remote information
flatpak remote-modify --enable flathub
```

## Resources

- [Flatpak Documentation](https://docs.flatpak.org/)
- [Flathub Application Repository](https://flathub.org/)
- [Flatpak GitHub Repository](https://github.com/flatpak/flatpak)