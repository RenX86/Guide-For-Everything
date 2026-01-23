# Arch Linux Installation Guide

## Pre-installation

Before starting the installation, ensure your system is ready for Arch Linux installation and verify all necessary connections are working properly.
1. **Internet Connection**: Verify that you have a stable internet connection for package installation. Test connectivity with `ping -c 3 archlinux.org`.
2. **Update System Clock**: Synchronize the system clock with `timedatectl set-ntp true` for accurate time during installation.
3. **Verify Boot Mode**: Check that your system is booted in UEFI mode with `ls /sys/firmware/efi/efivars` (directory exists if booted in UEFI mode).

## Partitioning

1. Open `cfdisk` and create the following partitions:
   - Select **GPT** as the partition table.
2. Create partitions:
   - `/dev/sda1` = **300M** (EFI System Partition)
   - `/dev/sda2` = **4G** (Swap Partition)
   - `/dev/sda3` = **Remaining space** (Root Partition)

## Formatting Partitions

1. Format partitions:
   ```sh
   mkfs.ext4 /dev/sda3
   mkfs.fat -F 32 /dev/sda1
   mkswap /dev/sda2
   ```

## Mounting

1. Mount the partitions:
   ```sh
   mount /dev/sda3 /mnt
   mkdir -p /mnt/boot/efi
   mount /dev/sda1 /mnt/boot/efi
   swapon /dev/sda2
   ```

## Installing Essential Packages

1. Install the base system:
   ```sh
   pacstrap /mnt base linux linux-firmware sof-firmware base-devel grub efibootmgr nano networkmanager
   ```

## Generate fstab

1. Generate the fstab file:
   ```sh
   genfstab -U /mnt >> /mnt/etc/fstab
   cat /mnt/etc/fstab
   ```

## Chroot into the System

1. Change root into the new system:
   ```sh
   arch-chroot /mnt
   ```

## System Configuration

### Timezone

1. Set the timezone:
   ```sh
   ln -sf /usr/share/zoneinfo/Asia/Kolkata /etc/localtime
   hwclock --systohc
   ```

### Locale

1. Configure the locale:
   ```sh
   nano /etc/locale.gen  # Uncomment en_US.UTF-8
   locale-gen
   echo "LANG=en_US.UTF-8" > /etc/locale.conf
   echo "KEYMAP=us" > /etc/vconsole.conf
   ```

### Hostname & Network

1. Set hostname:
    ```sh
    echo "arch" > /etc/hostname
    ```

2. Enable NetworkManager:
    ```sh
    systemctl enable NetworkManager
    ```

### Root Password & User Creation

1. Set root password:
    ```sh
    passwd
    ```

2. Create a user:
    ```sh
    useradd -m -g users -G wheel -s /bin/bash Ren
    passwd Ren
    ```

3. Grant sudo privileges:
    ```sh
    EDITOR=nano visudo  # Uncomment %wheel ALL=(ALL) ALL
    ```

## Bootloader Installation

1. Install and configure GRUB:
    ```sh
    grub-install --target=x86_64-efi --efi-directory=/boot/efi --bootloader-id=GRUB
    grub-mkconfig -o /boot/grub/grub.cfg
    ```

## Hardware-Specific Configurations

After basic installation, you may need to install additional drivers and configurations based on your hardware:

### Microcode for CPU

- **Intel CPUs**: `sudo pacman -S intel-ucode`
- **AMD CPUs**: `sudo pacman -S amd-ucode`
- After installation, regenerate GRUB config with: `sudo grub-mkconfig -o /boot/grub/grub.cfg`

### Graphics Drivers

- **Intel Integrated**: `sudo pacman -S xf86-video-intel mesa`
- **NVIDIA**: 
  - For newer cards: `sudo pacman -S nvidia nvidia-utils`
  - For older cards: `sudo pacman -S nvidia-390xx-dkms nvidia-390xx-utils`
- **AMD**: `sudo pacman -S xf86-video-amdgpu mesa`
- After installation, consider adding `nvidia` or `amdgpu` to `/etc/mkinitcpio.conf` HOOKS if using dedicated GPU

### Audio Configuration

- Install audio system: `sudo pacman -S alsa-utils pulseaudio pulseaudio-alsa`
- Add your user to audio group: `sudo usermod -a -G audio Ren`

## Security Configurations

For basic system security, consider implementing these measures:

### Firewall Setup

- Install UFW: `sudo pacman -S ufw`
- Enable UFW: `sudo systemctl enable --now ufw`
- Set default policies: `sudo ufw default deny incoming` and `sudo ufw default allow outgoing`
- Enable firewall: `sudo ufw enable`

### SSH Configuration (if needed)

- Install SSH: `sudo pacman -S openssh`
- Enable SSH service: `sudo systemctl enable --now sshd`
- Configure SSH: Edit `/etc/ssh/sshd_config` to disable root login and change default port if needed
- Restart SSH: `sudo systemctl restart sshd`

## Post-Installation Essentials

After your first boot into the new system, consider installing these additional packages:

### AUR Helper (Optional but Recommended)

- Install Git: `sudo pacman -S git`
- Download and build an AUR helper like `yay`:
  ```sh
  git clone https://aur.archlinux.org/yay.git
  cd yay
  makepkg -si
  ```

### Additional Repositories

- Enable multilib repository by uncommenting `[multilib]` section in `/etc/pacman.conf`
- Update package database: `sudo pacman -Sy`

### Commonly Used Utilities

- System monitoring: `sudo pacman -S htop bpytop iotop`
- File management: `sudo pacman -S ranger`
- Network tools: `sudo pacman -S wget curl dnsutils`
- Text editor: `sudo pacman -S vim`
- Compression: `sudo pacman -S p7zip unrar zip unzip`

### Additional Fonts and Theming

- TTF fonts: `sudo pacman -S ttf-dejavu ttf-liberation noto-fonts`
- Emoji support: `sudo pacman -S noto-fonts-emoji`

## Finalizing Installation

1. Exit chroot and reboot:
    ```sh
    exit
    umount -a
    reboot
    ```

## Installing KDE Plasma (Optional)

1. Install KDE Plasma:
    ```sh
    sudo pacman -S plasma sddm kde-applications
    sudo systemctl enable --now sddm
    ```

## Troubleshooting

If you encounter issues during or after installation, try these solutions:

### Boot Issues

- If system won't boot, enter BIOS/UEFI settings and ensure the correct drive/OS is set as default boot option
- Boot from installation media and chroot into your system to reinstall GRUB: `grub-install` and `grub-mkconfig -o /boot/grub/grub.cfg`

### Network Issues

- Check NetworkManager status: `systemctl status NetworkManager`
- Restart NetworkManager: `sudo systemctl restart NetworkManager`
- If using WiFi, install and use `iwctl` for connection setup

### Audio Issues

- Check if audio services are running: `systemctl status alsa-state.service`
- Start audio service: `sudo systemctl start alsa-state.service`

### Display/Graphic Issues

- Reinstall graphics drivers if experiencing display problems
- Check Xorg logs for errors: `/var/log/Xorg.0.log`
- For NVIDIA systems, ensure nouveau driver is blacklisted if using proprietary driver

### Additional Resources

- ArchWiki: https://wiki.archlinux.org/
- Arch Forums: https://bbs.archlinux.org/
- IRC: #archlinux on Libera.Chat
    
