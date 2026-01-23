Here’s a comprehensive **`wsl.md`** file that lists and explains all major **WSL (Windows Subsystem for Linux)** commands, including both common user commands and advanced management commands.

---

````markdown
# Windows Subsystem for Linux (WSL) Command Reference

This document lists all major **WSL (Windows Subsystem for Linux)** commands, options, and their descriptions.  
Applies to **WSL 1** and **WSL 2** (Windows 10, Windows 11).

---

## 🧭 Basic Commands

### Launch WSL
```bash
wsl
````

Starts your default Linux distribution.

### Run a Command in WSL

```bash
wsl [command]
```

Example:

```bash
wsl ls -la
```

### Specify a Distribution

```bash
wsl -d <DistroName> [command]
```

Example:

```bash
wsl -d Ubuntu pwd
```

### Exit WSL

```bash
exit
```

---

## ⚙️ Installation and Setup

### Install WSL

```bash
wsl --install
```

Installs WSL (with default Ubuntu distribution).

**Options:**

```bash
wsl --install -d <DistroName>
wsl --install --no-distribution
```

### List Available Distributions

```bash
wsl --list --online
```

or

```bash
wsl -l -o
```

### List Installed Distributions

```bash
wsl --list --verbose
```

or

```bash
wsl -l -v
```

---

## 🧱 Distribution Management

### Set Default Distribution

```bash
wsl --set-default <DistroName>
```

### Set Default Version

```bash
wsl --set-default-version <Version>
```

Versions:

* `1` → WSL 1
* `2` → WSL 2

Example:

```bash
wsl --set-default-version 2
```

### Set Distribution Version

```bash
wsl --set-version <DistroName> <Version>
```

Example:

```bash
wsl --set-version Ubuntu 2
```

### Unregister (Delete) a Distribution

```bash
wsl --unregister <DistroName>
```

⚠️ This deletes the distribution and all data.

### Export a Distribution

```bash
wsl --export <DistroName> <FileName.tar>
```

### Import a Distribution

```bash
wsl --import <DistroName> <InstallLocation> <FileName.tar> [--version <Version>]
```

---

## 🔧 Configuration and System Control

### Check WSL Status

```bash
wsl --status
```

### Update WSL

```bash
wsl --update
```

### Roll Back WSL Kernel Update

```bash
wsl --update rollback
```

### Shutdown All Running Distributions

```bash
wsl --shutdown
```

### Terminate a Specific Distribution

```bash
wsl --terminate <DistroName>
```

or

```bash
wsl -t <DistroName>
```

### Get WSL Version Information

```bash
wsl --version
```

---

## 🧩 Interoperability

### Run Windows Commands Inside WSL

Example:

```bash
notepad.exe
```

You can call any Windows executable from WSL.

### Run Linux Commands from PowerShell or CMD

Example:

```powershell
wsl ls ~
```

---

## 🧱 File System Paths

* **Windows → Linux:**
  `C:\Users\YourName` → `/mnt/c/Users/YourName`

* **Linux → Windows:**
  Use `/mnt/<drive-letter>/path`

---

## 🧰 Advanced

### Convert a Distribution from WSL 1 → WSL 2

```bash
wsl --set-version <DistroName> 2
```

### Get Help

```bash
wsl --help
```

---

## 📄 Example Workflows

### Export, Delete, and Reimport a Distro

```bash
wsl --export Ubuntu ubuntu_backup.tar
wsl --unregister Ubuntu
wsl --import Ubuntu C:\WSL\Ubuntu ubuntu_backup.tar --version 2
```

### Start a Specific Distro in CMD

```cmd
wsl -d Debian
```

### Change Default WSL Distro to Debian

```bash
wsl --set-default Debian
```

---

## 🧩 Useful Files

| File                       | Purpose                                             |
| -------------------------- | --------------------------------------------------- |
| `%USERPROFILE%\.wslconfig` | Global WSL configuration (memory, processors, etc.) |
| `/etc/wsl.conf`            | Per-distro configuration                            |

Example `.wslconfig`:

```ini
[wsl2]
memory=4GB
processors=2
swap=2GB
localhostForwarding=true
```

---

## 🧾 References

* [Microsoft Docs: WSL Command Reference](https://learn.microsoft.com/windows/wsl/reference)
* [WSL Configuration Files](https://learn.microsoft.com/windows/wsl/wsl-config)
* [WSL Troubleshooting](https://learn.microsoft.com/windows/wsl/troubleshooting)

---

© 2025 — Comprehensive WSL Command Guide

```

