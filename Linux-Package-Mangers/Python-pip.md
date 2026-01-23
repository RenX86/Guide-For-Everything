# Python pip Package Management Guide

## Overview

pip is the standard package installer for Python. It allows you to install and manage additional packages that are not part of the Python standard library. pip works with PyPI (Python Package Index) by default but can also install from other sources.

## Installing pip

### For Python 2 (deprecated)
```bash
# Download get-pip.py
curl https://bootstrap.pypa.io/pip/2.7/get-pip.py -o get-pip.py
python get-pip.py
```

### For Python 3 (recommended)
Most modern Python installations include pip by default. If not installed:

```bash
# On Ubuntu/Debian
sudo apt install python3-pip

# On Fedora
sudo dnf install python3-pip

# On CentOS/RHEL
sudo yum install python3-pip

# On Arch Linux
sudo pacman -S python-pip

# On macOS with Homebrew
brew install python3  # includes pip

# Manual installation
curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
python3 get-pip.py
```

## Basic pip Commands

### Installing Packages
```bash
# Install a package
pip install package-name

# Install a specific version
pip install package-name==1.0.4

# Install minimum version
pip install "package-name>=1.0.4"

# Install from PyPI with pre-release
pip install --pre package-name

# Install without dependencies
pip install --no-deps package-name

# Install with confirmation prompts
pip install --confirm-conda-deps package-name  # conda environments
```

### Upgrading Packages
```bash
# Upgrade a package
pip install --upgrade package-name

# Upgrade with alias
pip install -U package-name

# Upgrade to a specific version
pip install package-name==2.0.0

# Upgrade to latest version
pip install package-name --upgrade --force-reinstall
```

### Uninstalling Packages
```bash
# Uninstall a package
pip uninstall package-name

# Uninstall with confirmation
pip uninstall package-name -y

# Uninstall multiple packages
pip uninstall package1 package2 package3
```

### Listing and Searching
```bash
# List installed packages
pip list

# List outdated packages
pip list --outdated

# Search for packages (search command is disabled as of 2020)
# Alternative methods for searching:
# Visit https://pypi.org/ to search packages in browser
# Use external tools like:
pip install pip-search  # Then use pip_search keyword
# Or use curl to search PyPI API:
curl "https://pypi.org/pypi/package-name/json"

# Show package information
pip show package-name

# List packages in requirements format
pip freeze

# Check for security vulnerabilities
pip install safety
safety check
```

## Advanced pip Usage

### Requirements Files
```bash
# Install from requirements file
pip install -r requirements.txt

# Generate requirements file
pip freeze > requirements.txt

# Generate requirements with comments
pip freeze --local | grep -v '^\-e' > requirements.txt

# Install from multiple requirements files
pip install -r requirements1.txt -r requirements2.txt
```

### Virtual Environments
```bash
# Create virtual environment
python -m venv myenv

# Activate virtual environment (Linux/macOS)
source myenv/bin/activate

# Activate virtual environment (Windows)
myenv\Scripts\activate

# Deactivate virtual environment
deactivate

# Create virtual environment with specific Python version
python3.9 -m venv myenv

# Create virtual environment without pip (install separately)
python -m venv myenv --without-pip
```

### Installing from Different Sources
```bash
# Install from a local directory
pip install /path/to/local/package

# Install from a git repository
pip install git+https://github.com/user/repo.git

# Install from a specific branch
pip install git+https://github.com/user/repo.git@branch-name

# Install from a tag
pip install git+https://github.com/user/repo.git@v1.0.0

# Install from a zip file
pip install https://example.com/package.zip

# Install from wheel file
pip install package.whl
```

## Package Configuration and Options

### Installing with Options
```bash
# Install user-only (not system-wide)
pip install --user package-name

# Install editable/development mode
pip install -e /path/to/local/package

# Install with optional dependencies
pip install package-name[extra1,extra2]

# Install with build-time dependencies
pip install package-name --install-option="--prefix=/opt/prefix"

# Install without cache
pip install --no-cache-dir package-name
```

### Configuration Management
```bash
# Show pip configuration
pip config list

# Set configuration
pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple/

# Get specific configuration
pip config get global.index-url

# Unset configuration
pip config unset global.index-url
```

## Virtual Environment Managers

### Using venv (built-in)
```bash
# Create environment
python -m venv project_env

# Activate
source project_env/bin/activate  # Linux/macOS
project_env\Scripts\activate     # Windows

# Deactivate
deactivate
```

### Using virtualenv (third-party)
```bash
# Install virtualenv
pip install virtualenv

# Create environment
virtualenv project_env

# Create with specific Python version
virtualenv -p python3.9 project_env
```

### Using conda environments with pip
```bash
# Create conda environment
conda create -n myenv python=3.9

# Activate environment
conda activate myenv

# Install packages with pip inside conda environment
pip install package-name
```

## Dependency Management

### Creating Requirements Files
```bash
# Basic requirements
pip freeze > requirements.txt

# Requirements with only top-level packages
pip install pip-tools
pip-compile requirements.in

# Development requirements
pip freeze | grep -E "(dev|test|lint)" > dev-requirements.txt
```

### Using pip-tools
```bash
# Install pip-tools
pip install pip-tools

# Create requirements from requirements.in
pip-compile requirements.in

# Create requirements with hashes for security
pip-compile --generate-hashes requirements.in

# Sync installed packages with requirements
pip-sync requirements.txt
```

## Troubleshooting

### Common Issues and Solutions
```bash
# Permission denied error
pip install --user package-name

# SSL certificate errors
pip install --trusted-host pypi.org --trusted-host pypi.python.org --trusted-host files.pythonhosted.org package-name

# Upgrade pip itself
python -m pip install --upgrade pip

# Clear pip cache
pip cache purge

# Show verbose output for debugging
pip install -v package-name

# Install with no cache (useful for debugging)
pip install --no-cache-dir package-name
```

### Checking Package Integrity
```bash
# Verify installed packages
pip check

# Show package files
pip show --files package-name

# Download packages without installing
pip download package-name
```

## Security Best Practices

### Secure Installation
```bash
# Verify package signatures (when available)
pip install --require-hashes -r requirements.txt

# Install from trusted sources only
pip install --index-url https://pypi.org/simple/ package-name

# Check for vulnerabilities
pip install safety
safety check --full-report
```

### Pinning Versions
```bash
# In requirements.txt, pin versions
Django==4.1.0
requests>=2.25.0,<3.0.0
```

## Advanced pip Configuration

### Using Configuration Files
Create `pip.conf` (Linux/macOS) or `pip.ini` (Windows) in:
- Linux/macOS: `$HOME/.pip/pip.conf` or `$HOME/pip/pip.conf`
- Windows: `%APPDATA%\pip\pip.ini`

Example configuration:
```
[global]
index-url = https://pypi.org/simple/
trusted-host = pypi.org
               pypi.python.org
               files.pythonhosted.org
timeout = 60

[install]
user = true
```

### Using Different Package Indexes
```bash
# Use a different index
pip install -i https://alternative-index.com/simple/ package-name

# Configure a mirror
pip install -i https://pypi.douban.com/simple/ package-name
```

## pipx - Installing Python Applications

For running Python applications in isolated environments:

```bash
# Install pipx
pip install pipx

# Install an application
pipx install package-name

# Install with specific Python version
pipx install --python python3.9 package-name

# Run an application without installing
pipx run package-name

# Upgrade all pipx installed packages
pipx upgrade-all

# List installed packages
pipx list

# Uninstall
pipx uninstall package-name
```

## Best Practices

1. **Use virtual environments** for each project
2. **Pin package versions** in production
3. **Keep pip updated**: `python -m pip install --upgrade pip`
4. **Use requirements files** for reproducible environments
5. **Install packages in order**: base packages first, then others
6. **Use pip-tools** for complex dependency management
7. **Regularly audit** for security vulnerabilities
8. **Document your environment** with `pip freeze`

## Resources

- [pip Documentation](https://pip.pypa.io/)
- [PyPI - The Python Package Index](https://pypi.org/)
- [Python Packaging User Guide](https://packaging.python.org/)
- [pip GitHub Repository](https://github.com/pypa/pip)
- [Python Virtual Environments Guide](https://docs.python.org/3/tutorial/venv.html)