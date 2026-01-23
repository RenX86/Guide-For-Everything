# Conda Cheat Sheet

## Overview
Conda is a powerful command-line package and environment manager that allows you to install, run, and update packages and their dependencies. It also enables you to create, save, load, and switch between different project environments.

> **TIP**: Anaconda Navigator is a graphical interface to use conda. Double-click the Navigator icon on your desktop or, in a Terminal or at the Anaconda prompt, type `anaconda-navigator`.

## Conda Basics

### Installation and Information
- **Verify conda is installed, check version number:**
  ```bash
  conda info
  ```
- **Update conda to the current version:**
  ```bash
  conda update conda
  ```
- **Command line help:**
  ```bash
  conda install --help
  # or more generally
  COMMANDNAME --help
  ```

### Installing and Updating Packages
- **Install a package included in Anaconda:**
  ```bash
  conda install PACKAGENAME
  ```
  Example: `conda install spyder`
- **Run a package after install:**
  ```bash
  PACKAGENAME
  ```
  Example: `spyder`
- **Update any installed program:**
  ```bash
  conda update PACKAGENAME
  ```

## Package Management

### Finding Conda Packages
- **Use conda to search for a package:**
  ```bash
  conda search PACKAGENAME
  ```
- **See list of all packages in Anaconda:**
  ```bash
  conda search
  ```
- **Online documentation:** https://docs.anaconda.com/anaconda/packages/pkg-docs

### Installing Packages
- **Install a new package in the active environment:**
  ```bash
  conda install jupyter
  # or
  conda install PACKAGENAME
  ```
- **Run an installed package:**
  ```bash
  jupyter-notebook
  # or
  PACKAGENAME
  ```
- **Install a new package in a different environment:**
  ```bash
  conda install --name bio-env toolz
  ```
- **Update a package in the current environment:**
  ```bash
  conda update scikit-learn
  ```
- **Install a package from a specific channel:**
  ```bash
  conda install --channel conda-forge boltons
  ```
- **Install a package directly from PyPI into the current active environment using pip:**
  ```bash
  pip install boltons
  ```
- **Remove one or more packages from a specific environment:**
  ```bash
  conda remove --name bio-env toolz boltons
  ```

## Version Specifications

When using `conda create` or `conda install` commands, you can specify version numbers with these constraints:

| Constraint Type | Specification | Result |
|----------------|---------------|---------|
| Fuzzy | `numpy=1.11` | 1.11.0, 1.11.1, 1.11.2, 1.11.18, etc. |
| Exact | `numpy==1.11` | 1.11.0 |
| Greater than or equal to | `"numpy>=1.11"` | 1.11.0 or higher |
| OR | `"numpy=1.11.1\|1.11.3"` | 1.11.1, 1.11.3 |
| AND | `"numpy>=1.8,<2"` | 1.8, 1.9, not 2.0 |

> **NOTE**: Quotation marks must be used when your specification contains a space or any of these characters: > < \| *

## Environment Management

### Creating Environments
- **Create a new environment with a specific Python version:**
  ```bash
  conda create --name py35 python=3.5
  ```
- **Stack commands: create a new environment and install packages:**
  ```bash
  conda create --name bio-env biopython
  ```
- **Make exact copy of an environment:**
  ```bash
  conda create --clone py35 --name py35-2
  ```

### Activating Environments
- **On Windows:**
  ```bash
  activate py35
  ```
- **On Linux/macOS:**
  ```bash
  source activate py35
  ```

### Deactivating Environments
- **On Windows:**
  ```bash
  deactivate
  ```
- **On macOS/Linux:**
  ```bash
  source deactivate
  ```

### Environment Information and Management
- **Get a list of all environments (active environment is shown with *):**
  ```bash
  conda env list
  ```
- **List all packages and versions installed in active environment:**
  ```bash
  conda list
  ```
- **List the history of each change to the current environment:**
  ```bash
  conda list --revisions
  ```
- **Restore environment to a previous revision:**
  ```bash
  conda install --revision 2
  ```
- **Save environment to a text file:**
  ```bash
  conda list --explicit > bio-env.txt
  ```
- **Create environment from a text file:**
  ```bash
  conda env create --file bio-env.txt
  ```
- **Delete an environment and everything in it:**
  ```bash
  conda env remove --name bio-env
  ```

## Managing Multiple Python Versions

### Installing Different Python Versions
```bash
conda create --name py34 python=3.4
```

### Switching Between Python Versions
- **Activate the new environment:**
  - Windows: `activate py34`
  - Linux/macOS: `source activate py34`

- **Show locations of all Python versions in the path:**
  - Windows: `where python`
  - Linux/macOS: `which -a python`
  > NOTE: The first version of Python in the list will be executed.

- **Show version information for the current active Python:**
  ```bash
  python --version
  ```

## Advanced Conda Commands

### Configuration Management
- **List conda configuration:**
  ```bash
  conda config --show
  ```
- **Add a channel:**
  ```bash
  conda config --add channels channel-name
  ```
- **Remove a channel:**
  ```bash
  conda config --remove channels channel-name
  ```

### Package Management Beyond Conda
- **Update all packages in current environment:**
  ```bash
  conda update --all
  ```
- **Install packages from environment file:**
  ```bash
  conda env update --file environment.yml
  ```

## Best Practices

1. **Create separate environments** for different projects to avoid dependency conflicts
2. **Use explicit environment files** for reproducible environments
3. **Regularly update conda** itself with `conda update conda`
4. **Use channels carefully** - prefer conda-forge for community packages
5. **Keep environments clean** by removing unused packages

## Resources and Support

### Documentation
- [Conda Documentation](conda.io/docs)
- [Command Reference](conda.io/docs/commands)

### Support
- **Free Community Support:** groups.google.com/a/continuum.io/forum/#!forum/conda
- **Paid Support Options:** anaconda.com/support
- **Anaconda Onsite Training Courses:** anaconda.com/training
- **Anaconda Consulting Services:** anaconda.com/consulting

### Learn More
- Learn to use conda in 30 minutes: [bit.ly/tryconda](bit.ly/tryconda)
- Join the community: anaconda.com/community
- Follow on Twitter: @anacondainc #AnacondaCrew

---

*Conda Cheat Sheet Version 4.3.24 - 8/20/2017*