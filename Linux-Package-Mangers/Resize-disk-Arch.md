# Resizing Disk Partitions in Arch Linux

This guide provides instructions for resizing disk partitions in Arch Linux systems. This is often necessary when expanding virtual disk space or when extending partitions on physical systems.

## Pre-Resizing Steps

Before resizing any partitions, it's crucial to follow these safety steps:

1. **Create a backup** of your important data
2. **Check available disk space** with `df -h`
3. **Identify your disk and partition** with `lsblk` or `fdisk -l`

## Standard Resizing Process

### Method 1: Using cfdisk (Recommended for beginners)

1. **Shut down the Virtual Machine completely** or ensure no processes are using the partition
2. **Boot from a live environment** (if resizing root partition)
3. **Launch cfdisk**:
   ```bash
   sudo cfdisk /dev/sdX  # Replace X with your disk letter
   ```
4. **Select the partition** you want to resize
5. **Choose Resize** option and specify the new size
6. **Write the changes** and quit cfdisk
7. **Resize the filesystem** to use the new partition space:
   ```bash
   sudo resize2fs /dev/sdXN  # Replace X with disk letter, N with partition number
   ```
8. **Reboot** the system to ensure everything works correctly:
   ```bash
   sudo reboot
   ```

### Method 2: Using parted (Advanced users)

1. **Launch parted**:
   ```bash
   sudo parted /dev/sdX
   ```
2. **Print current partition table**:
   ```
   (parted) print
   ```
3. **Resize the partition**:
   ```
   (parted) resizepart N unit size  # N is partition number
   ```
4. **Exit parted and resize filesystem**:
   ```bash
   sudo resize2fs /dev/sdXN
   ```

## Post-Resizing Steps

1. **Verify the partition was resized**:
   ```bash
   lsblk
   ```
2. **Check filesystem integrity**:
   ```bash
   sudo fsck /dev/sdXN
   ```
3. **Verify available space**:
   ```bash
   df -h
   ```

## Important Notes

- **Always backup data** before resizing partitions
- **Root partitions** require booting from a live environment
- **Ext2/3/4 filesystems** can be resized online (growing) or offline (shrinking)
- **Swap partitions** need to be recreated after resizing
- **LVM setups** require different commands (lvextend, pvresize)

## Troubleshooting

### If the filesystem doesn't recognize the new size:
```bash
sudo resize2fs /dev/sdXN
```

### If partition table is inconsistent:
```bash
sudo partprobe /dev/sdX
```

### If the partition is mounted:
- Unmount before resizing: `sudo umount /dev/sdXN`
- Or boot from a live environment

## Additional Resources

- [ArchWiki Partitioning](https://wiki.archlinux.org/index.php/Partitioning)
- [ArchWiki File Systems](https://wiki.archlinux.org/index.php/File_systems)
- [GNU Parted Manual](https://www.gnu.org/software/parted/manual/)