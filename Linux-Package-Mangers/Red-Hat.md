# Red Hat Package Manager Command Guide

This guide provides comprehensive commands for DNF (Dandified YUM), the default package manager for Red Hat Enterprise Linux (RHEL), Fedora, and CentOS. DNF is the successor to YUM and offers improved performance and dependency resolution.

## 1. Package Database Management

### Synchronization and Updates
- **Update package lists:**
  ```bash
  sudo dnf check-update
  ```
- **Upgrade all packages:**
  ```bash
  sudo dnf upgrade
  ```
- **Upgrade a specific package:**
  ```bash
  sudo dnf upgrade package-name
  ```
- **Downgrade a package:**
  ```bash
  sudo dnf downgrade package-name
  ```

## 2. Installing Packages

### Package Installation Commands
- **Install a package:**
  ```bash
  sudo dnf install package-name
  ```
- **Install multiple packages:**
  ```bash
  sudo dnf install package1 package2 package3
  ```
- **Install a package group:**
  ```bash
  sudo dnf groupinstall "Development Tools"
  ```
- **Install a local package file:**
  ```bash
  sudo dnf install /path/to/package.rpm
  ```
- **Enable a specific repository and install a package:**
  ```bash
  sudo dnf install --enablerepo=repo-name package-name
  ```

## 3. Removing Packages

### Package Removal Commands
- **Remove a package:**
  ```bash
  sudo dnf remove package-name
  ```
- **Remove multiple packages:**
  ```bash
  sudo dnf remove package1 package2 package3
  ```
- **Remove a package group:**
  ```bash
  sudo dnf groupremove "Development Tools"
  ```
- **Remove a package and dependencies that are no longer needed:**
  ```bash
  sudo dnf autoremove
  ```

## 4. Querying and Searching

### Package Information Commands
- **Search for a package in repositories:**
  ```bash
  dnf search package-name
  ```
- **List installed packages:**
  ```bash
  dnf list installed
  ```
- **Show details of an installed package:**
  ```bash
  dnf info package-name
  ```
- **List all available package groups:**
  ```bash
  dnf grouplist
  ```
- **Find which package owns a file:**
  ```bash
  dnf provides /path/to/file
  ```

## 5. Repository Management

### Managing Software Repositories
- **List all enabled repositories:**
  ```bash
  dnf repolist
  ```
- **List all repositories (including disabled):**
  ```bash
  dnf repolist all
  ```
- **Enable a repository:**
  ```bash
  sudo dnf config-manager --set-enabled repo-name
  ```
- **Disable a repository:**
  ```bash
  sudo dnf config-manager --set-disabled repo-name
  ```
- **Add a new repository:**
  ```bash
  sudo dnf config-manager --add-repo https://example.com/repo.repo
  ```

## 6. Cleaning Up

### System Maintenance Commands
- **Remove cached packages:**
  ```bash
  sudo dnf clean packages
  ```
- **Remove all cached data:**
  ```bash
  sudo dnf clean all
  ```
- **List unused dependencies:**
  ```bash
  sudo dnf autoremove --dry-run
  ```

## 7. Handling RPM Packages Manually

### Advanced RPM Commands
- **Install a local RPM package:**
  ```bash
  sudo rpm -ivh package.rpm
  ```
- **Upgrade an RPM package:**
  ```bash
  sudo rpm -Uvh package.rpm
  ```
- **Remove an RPM package:**
  ```bash
  sudo rpm -e package-name
  ```
- **Query information about an installed RPM package:**
  ```bash
  rpm -qi package-name
  ```
- **List files installed by a package:**
  ```bash
  rpm -ql package-name
  ```
- **Check which package owns a specific file:**
  ```bash
  rpm -qf /path/to/file
  ```

## 8. Troubleshooting

### Common Issues and Solutions
- **Fix broken dependencies:**
  ```bash
  sudo dnf check
  ```
- **Reinstall a package:**
  ```bash
  sudo dnf reinstall package-name
  ```
- **Force install an RPM package:**
  ```bash
  sudo rpm -ivh --force package.rpm
  ```
- **Force remove an RPM package (use with caution):**
  ```bash
  sudo rpm -e --nodeps package-name
  ```

## 9. Performance and Optimization

### Advanced DNF Features
- **Run DNF with minimal output:**
  ```bash
  sudo dnf -q install package-name
  ```
- **Test run without making changes:**
  ```bash
  sudo dnf install --assumeno package-name
  ```
- **Skip broken packages during update:**
  ```bash
  sudo dnf update --skip-broken
  ```

## 10. Additional Resources

- [DNF Documentation](https://dnf.readthedocs.io/)
- [Fedora DNF Guide](https://docs.fedoraproject.org/en-US/quick-docs/dnf/)
- [Red Hat Package Management Guide](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/8/html/package_manifest/index)