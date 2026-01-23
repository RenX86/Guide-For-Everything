# Chocolatey Package Management Guide

## Overview

Chocolatey is a package manager for Windows that provides a command-line interface for installing, upgrading, and managing software packages. It's often described as "apt-get for Windows" and simplifies software management on Windows systems.

## Installing Chocolatey

### Prerequisites
- Windows 7+ / Windows Server 2003+
- PowerShell v2+
- .NET Framework 4+

### Installation Steps

#### Method 1: Command Prompt (Admin)
```cmd
@"%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" -NoProfile -InputFormat None -ExecutionPolicy Bypass -Command " [System.Net.ServicePointManager]::SecurityProtocol = 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))" && SET "PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin"
```

#### Method 2: PowerShell (Admin)
```powershell
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```

#### Method 3: Alternative PowerShell (Admin)
```powershell
[System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```

### Verify Installation
```cmd
choco --version
```

## Basic Chocolatey Commands

### Searching for Packages
```cmd
# Search for a package
choco search packagename

# Search with exact match
choco search packagename --exact

# Search remotely (not just local)
choco search packagename --remote

# Limit results
choco search packagename --limit-output
```

### Installing Packages
```cmd
# Install a package
choco install packagename

# Install a package without confirmation
choco install packagename -y

# Install specific version
choco install packagename --version=1.0.0

# Install from a specific source
choco install packagename --source=https://source-url

# Install package to a specific directory
choco install packagename --install-directory="C:\MyPath"
```

### Upgrading Packages
```cmd
# Upgrade a specific package
choco upgrade packagename

# Upgrade with confirmation
choco upgrade packagename -y

# Upgrade all packages
choco upgrade all

# Upgrade specific version
choco upgrade packagename --version=2.0.0
```

### Removing Packages
```cmd
# Uninstall a package
choco uninstall packagename

# Uninstall with confirmation
choco uninstall packagename -y

# Uninstall all packages
choco uninstall all

# Uninstall without removing dependencies
choco uninstall packagename --remove-dependencies=false
```

## Advanced Chocolatey Commands

### Listing Packages
```cmd
# List installed packages
choco list --local-only

# List outdated packages
choco outdated

# List all packages from source
choco list

# List with detailed information
choco list --local-only --detail
```

### Package Information
```cmd
# Get package information
choco info packagename

# Get information from remote source
choco info packagename --source=https://chocolatey.org/api/v2/

# Get specific package version info
choco info packagename --version=1.0.0
```

### Package Sources Management
```cmd
# List sources
choco source list

# Add a source
choco source add -n=name -s="source-url"

# Remove a source
choco source remove -n=name

# Enable a source
choco source enable -n=name

# Disable a source
choco source disable -n=name

# Update source
choco source update -n=name -s="new-source-url"
```

## Chocolatey Configuration

### Get Configuration
```cmd
# Show all configuration
choco config list

# Show specific configuration
choco config get config-name
```

### Set Configuration
```cmd
# Set a configuration
choco config set config-name value

# Set proxy
choco config set proxy http://proxy-server:port
choco config set proxyUser username
choco config set proxyPassword password
```

### Feature Management
```cmd
# List features
choco feature list

# Enable a feature
choco feature enable -n=feature-name

# Disable a feature
choco feature disable -n=feature-name
```

## Managing Multiple Packages

### Bulk Operations
```cmd
# Install multiple packages
choco install package1 package2 package3

# Install from a file
choco install packages.config

# Install packages from text file
choco install -y -r < packages.txt
```

### Creating Package Lists
```cmd
# Export installed packages to file
choco list --local-only > installed-packages.txt

# Create packages.config file
choco export > packages.config
```

## Development Tools

### Creating Custom Packages
```cmd
# Create new package template
choco new packagename

# Pack .nuspec file
choco pack packagename.nuspec

# Install local package
choco install packagename.nupkg --source .
```

### Package Verification
```cmd
# Verify package
choco verify -whatif packagename
```

## Troubleshooting

### Common Issues and Solutions
```cmd
# Force reinstall a package
choco uninstall packagename
choco install packagename

# Skip packages that fail during all upgrades
choco upgrade all --ignore-unfound

# Install with forced dependencies
choco install packagename --force-dependencies

# Install with no progress
choco install packagename --no-progress
```

### Debugging
```cmd
# Verbose output
choco install packagename -dv

# Debug output
choco install packagename -d

# Trace output (most detailed)
choco install packagename -t
```

### Repairing Chocolatey
```cmd
# Reinstall Chocolatey
choco upgrade chocolatey

# Reset Chocolatey
# Uninstall and reinstall Chocolatey
```

## Security and Verification

### Package Verification
```cmd
# Verify package checksums
choco install packagename --force -dv

# Skip package verification (not recommended)
choco install packagename --ignore-checksums
```

### Security Best Practices
- Only install packages from trusted sources
- Verify package checksums
- Keep Chocolatey updated
- Regularly review installed packages

## Examples of Common Installations

```cmd
# Install development tools
choco install git nodejs python vscode

# Install productivity tools
choco install 7zip googlechrome firefox sumatrapdf

# Install system utilities
choco install ccleaner malwarebytes sysinternals

# Install specific versions
choco install nodejs --version=14.17.0
```

## Chocolatey Business Features (if licensed)

```cmd
# Install from internal repository
choco install packagename --source="internal-source-url"

# Use licensed features
choco feature enable -n=useChocolateyCentralManagement
```

## Best Practices

1. **Always run as Administrator** for package installations
2. **Use -y flag** for unattended installations
3. **Keep Chocolatey updated**: `choco upgrade chocolatey`
4. **Review packages** before installation
5. **Use internal repositories** for enterprise environments
6. **Regularly audit installed packages** with `choco list --local-only`

## Additional Resources

- [Chocolatey Official Website](https://chocolatey.org/)
- [Chocolatey Documentation](https://docs.chocolatey.org/)
- [Chocolatey Package Repository](https://chocolatey.org/packages)
- [Chocolatey GitHub Repository](https://github.com/chocolatey/choco)
- [Chocolatey Community Forum](https://github.com/chocolatey/choco/discussions)