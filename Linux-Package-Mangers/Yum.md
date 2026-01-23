# YUM Package Manager Command Guide

YUM (Yellowdog Updater, Modified) is the package manager for older versions of Red Hat Enterprise Linux (RHEL), CentOS, and Fedora systems. While largely superseded by DNF in newer versions, YUM is still used in many enterprise environments.

## 1. Package Database Management

### Synchronization and Updates
- **Update package lists:**
  ```bash
  sudo yum check-update
  ```
- **Upgrade all packages:**
  ```bash
  sudo yum update
  ```
- **Upgrade a specific package:**
  ```bash
  sudo yum update package-name
  ```
- **Downgrade a package:**
  ```bash
  sudo yum downgrade package-name
  ```

## 2. Installing Packages

### Package Installation Commands
- **Install a package:**
  ```bash
  sudo yum install package-name
  ```
- **Install multiple packages:**
  ```bash
  sudo yum install package1 package2 package3
  ```
- **Install a package group:**
  ```bash
  sudo yum groupinstall "Development Tools"
  ```
- **Install a local package file:**
  ```bash
  sudo yum install /path/to/package.rpm
  ```
- **Enable a specific repository and install a package:**
  ```bash
  sudo yum install --enablerepo=repo-name package-name
  ```

## 3. Removing Packages

### Package Removal Commands
- **Remove a package:**
  ```bash
  sudo yum remove package-name
  ```
- **Remove multiple packages:**
  ```bash
  sudo yum remove package1 package2 package3
  ```
- **Remove a package group:**
  ```bash
  sudo yum groupremove "Development Tools"
  ```
- **Remove a package and dependencies that are no longer needed:**
  ```bash
  sudo yum autoremove
  ```

## 4. Querying and Searching

### Package Information Commands
- **Search for a package in repositories:**
  ```bash
  yum search package-name
  ```
- **List installed packages:**
  ```bash
  yum list installed
  ```
- **Show details of an installed package:**
  ```bash
  yum info package-name
  ```
- **List all available package groups:**
  ```bash
  yum grouplist
  ```
- **Find which package owns a file:**
  ```bash
  yum provides /path/to/file
  ```

## 5. Repository Management

### Managing Software Repositories
- **List all enabled repositories:**
  ```bash
  yum repolist
  ```
- **List all repositories (including disabled):**
  ```bash
  yum repolist all
  ```
- **Enable a repository:**
  ```bash
  sudo yum-config-manager --enable repo-name
  ```
- **Disable a repository:**
  ```bash
  sudo yum-config-manager --disable repo-name
  ```

## 6. Cleaning Up

### System Maintenance Commands
- **Remove cached packages:**
  ```bash
  sudo yum clean packages
  ```
- **Remove all cached data:**
  ```bash
  sudo yum clean all
  ```
- **List unused dependencies:**
  ```bash
  sudo yum autoremove --dry-run
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
  sudo yum check
  ```
- **Reinstall a package:**
  ```bash
  sudo yum reinstall package-name
  ```
- **Force install an RPM package:**
  ```bash
  sudo rpm -ivh --force package.rpm
  ```
- **Force remove an RPM package (use with caution):**
  ```bash
  sudo rpm -e --nodeps package-name
  ```

## 9. Advanced YUM Commands

### Additional Features and Options
- **View package history:**
  ```bash
  yum history
  ```
- **Undo a specific transaction:**
  ```bash
  sudo yum history undo transaction-id
  ```
- **Get information about a group:**
  ```bash
  yum groupinfo "group-name"
  ```
- **Check for updates without installing:**
  ```bash
  yum check-update
  ```

## 10. Best Practices and Security

### Recommended YUM Practices
- **Always update the system before installing new packages**
- **Use 'yum update' regularly to keep systems secure**
- **Verify package signatures before installation**
- **Keep repositories up-to-date and only use trusted sources**
- **Use 'yum list installed' to audit installed packages periodically**

## 11. Additional Resources

- [Red Hat YUM Guide](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/6/html/deployment_guide/ch-yum)
- [CentOS YUM Documentation](https://wiki.centos.org/PackageManagement/Yum)
- [YUM Command Reference](http://man7.org/linux/man-pages/man8/yum.8.html)