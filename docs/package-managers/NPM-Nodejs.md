# NPM (Node Package Manager) and Node.js Package Management Guide

## Overview

NPM (Node Package Manager) is the default package manager for Node.js. It allows you to install, update, and manage JavaScript packages and their dependencies. NPM consists of a command-line client and an online registry of public and private packages.

## Installing Node.js and NPM

### Installation Methods

#### Using Node Version Manager (NVM) - Recommended

```bash
# Install NVM (Linux/macOS)
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.0/install.sh | bash
source ~/.bashrc

# Install latest Node.js
nvm install node
nvm use node

# Install specific version
nvm install 18.17.0
nvm use 18.17.0
```

#### On Ubuntu/Debian

```bash
# Using apt
sudo apt update
sudo apt install nodejs npm

# Or using NodeSource repository
curl -fsSL https://deb.nodesource.com/setup_lts.x | sudo -E bash -
sudo apt-get install -y nodejs
```

#### On Fedora

```bash
sudo dnf install nodejs npm
```

#### On Arch Linux

```bash
sudo pacman -S nodejs npm
```

#### On Windows (using Chocolatey)

```cmd
choco install nodejs
```

#### On macOS (using Homebrew)

```bash
brew install node
```

### Verify Installation

```bash
node --version
npm --version
```

## Basic NPM Commands

### Initializing Projects

```bash
# Initialize a new project
npm init

# Initialize with default settings (skip questions)
npm init -y

# Initialize with specific name
npm init --scope=@username
```

### Installing Packages

```bash
# Install a package locally (in current project)
npm install package-name

# Install with alias
npm i package-name

# Install globally (available system-wide)
npm install -g package-name
npm i -g package-name

# Install as dependency (production)
npm install --save package-name
npm i package-name  # Default behavior

# Install as dev dependency
npm install --save-dev package-name
npm i -D package-name

# Install as optional dependency
npm install --save-optional package-name
npm i -O package-name

# Install specific version
npm install package-name@1.0.0

# Install latest version
npm install package-name@latest

# Install beta version
npm install package-name@beta
```

### Removing Packages

```bash
# Remove a package
npm uninstall package-name
npm remove package-name
npm rm package-name

# Remove dev dependency
npm uninstall --save-dev package-name
npm rm -D package-name

# Remove global package
npm uninstall -g package-name
```

### Updating Packages

```bash
# Update a specific package
npm update package-name

# Update all packages
npm update

# Update globally installed packages
npm update -g

# Show outdated packages
npm outdated

# Update to latest version (may break dependencies)
npm install package-name@latest
```

## Package Management

### Working with package.json

```bash
# View package information
npm list
npm list --depth=0  # Top-level only

# View global packages
npm list -g --depth=0

# Install packages from package.json
npm install

# Install production dependencies only
npm install --production
npm ci  # Clean install from package-lock.json

# View package information
npm info package-name
npm view package-name
```

### Scripts Management

```bash
# Run scripts defined in package.json
npm run script-name

# Run pre-defined scripts (test, start, stop)
npm test
npm start
npm stop

# Run package executable (if available)
npx package-name
```

### Dependencies Management

```bash
# Install exact version (no semver)
npm install --save-exact package-name
npm i --save-exact package-name@1.0.0

# Install from GitHub
npm install username/repo
npm install github:username/repo

# Install from GitHub with specific branch/tag
npm install github:username/repo#branch-name

# Install from tarball
npm install https://github.com/user/project/tarball/branch
```

## Advanced NPM Usage

### Configuration Management

```bash
# View all configuration settings
npm config list

# Set configuration
npm config set key value
npm config set init-author-name "Your Name"

# Get specific configuration
npm config get key

# Delete configuration
npm config delete key

# Edit configuration file
npm config edit

# Get npm root directory
npm root

# Get global npm root directory
npm root -g
```

### Registry Management

```bash
# View current registry
npm config get registry

# Set custom registry
npm config set registry https://registry.npmjs.org/

# Use different registry for installation
npm install --registry https://registry.npmjs.org/

# Login to registry
npm login

# Add user to registry
npm adduser

# Logout from registry
npm logout

# Publish to registry
npm publish
```

### Working with Lock Files

```bash
# Generate package-lock.json
npm install

# Install from package-lock.json only
npm ci

# Audit security vulnerabilities
npm audit

# Audit with report
npm audit --audit-level high

# Fix security vulnerabilities
npm audit fix

# Fix with more aggressive approach
npm audit fix --force
```

## NPM Scripts and Execution

### Creating and Running Scripts

```bash
# Run script from package.json
npm run build
npm run test
npm run start

# Run script with arguments
npm run test -- --verbose

# Run pre and post scripts automatically
# NPM runs pre<command> and post<command> automatically

# Example package.json scripts:
# {
#   "scripts": {
#     "prebuild": "npm run clean",
#     "build": "webpack",
#     "postbuild": "echo 'Build complete!'"
#   }
# }
```

### Using npx

```bash
# Run package without installing
npx create-react-app my-app

# Run latest version of package
npx package-name@latest

# Execute locally installed package
npx package-name
```

## Security and Best Practices

### Security Auditing

```bash
# Check for vulnerabilities
npm audit

# Generate audit report
npm audit --json > audit-report.json

# Install security updates
npm audit fix

# Force install security updates (may break compatibility)
npm audit fix --force

# Check for only high severity issues
npm audit --audit-level high
```

### Package Verification

```bash
# Verify packages integrity
npm doctor

# Check if everything is working properly
npm doctor
```

## Publishing Packages

### Preparing for Publication

```bash
# Check if package is ready for publication
npm pack  # Creates .tgz file for testing

# Validate package information
npm init  # If needed

# Check for publication readiness
npm publish --dry-run
```

### Publishing

```bash
# Publish package to npm registry
npm publish

# Publish specific tag
npm publish --tag beta

# Publish with access level (for scoped packages)
npm publish --access public
```

### Version Management

```bash
# View current version
npm version

# Bump version
npm version patch    # 1.0.0 -> 1.0.1
npm version minor    # 1.0.1 -> 1.1.0
npm version major    # 1.1.0 -> 2.0.0
npm version 1.2.3   # Set specific version

# Pre-release versions
npm version prerelease
npm version prepatch
npm version preminor
npm version premajor
```

## Troubleshooting

### Common Issues and Solutions

```bash
# Clear npm cache
npm cache clean --force

# Reinstall all packages
rm -rf node_modules
npm install

# Fix permissions issues (Linux/macOS)
sudo chown -R $(whoami) ~/.npm
# Or using nvm to avoid permission issues

# Check for missing dependencies
npm ls

# Install with no optional dependencies
npm install --no-optional

# Install with no save
npm install --no-save

# Install with production flag
npm install --production
NODE_ENV=production npm install
```

### Debugging

```bash
# Verbose output
npm install --verbose

# Silent output (minimal)
npm install --silent

# Dry run (show what would be done)
npm install --dry-run
```

## Working with Workspaces

### Monorepo Setup

```bash
# Example package.json with workspaces:
# {
#   "name": "my-monorepo",
#   "workspaces": [
#     "packages/*",
#     "apps/*"
#   ]
# }

# Install dependencies for all workspaces
npm install

# Run script in all workspaces
npm run build --workspaces

# Run script in specific workspace
npm run build --workspace=package-name
```

## Environment-Specific Installations

### Development vs Production

```bash
# Install only production dependencies
npm install --production
NODE_ENV=production npm install

# Install including dev dependencies
npm install
NODE_ENV=development npm install
```

### Platform-Specific Dependencies

```bash
# Install only for specific OS
npm install --os=linux
npm install --cpu=x64
```

## NPM Security Best Practices

1. **Regularly audit** with `npm audit`
2. **Use exact versions** for critical dependencies
3. **Avoid installing** packages with known vulnerabilities
4. **Use npm ci** for production deployments
5. **Keep dependencies** updated
6. **Review packages** before installing
7. **Use private registries** for sensitive projects

## Common npm Commands Summary

| Command | Description |
|---------|-------------|
| `npm init` | Initialize a new project |
| `npm install` | Install packages from package.json |
| `npm install pkg` | Install a package |
| `npm install -g pkg` | Install globally |
| `npm install --save-dev pkg` | Install as dev dependency |
| `npm uninstall pkg` | Remove a package |
| `npm update` | Update packages |
| `npm run script` | Run a script |
| `npm audit` | Check for vulnerabilities |
| `npm cache clean --force` | Clear cache |
| `npm list` | List installed packages |
| `npm info pkg` | Get package information |

## Resources

- [NPM Documentation](https://docs.npmjs.com/)
- [NPM Website](https://www.npmjs.com/)
- [Node.js Documentation](https://nodejs.org/en/docs/)
- [NPM Registry](https://registry.npmjs.org/)
- [NPM CLI Documentation](https://docs.npmjs.com/cli/)
- [Security Audits](https://docs.npmjs.com/auditing-package-dependencies-for-security-vulnerabilities)