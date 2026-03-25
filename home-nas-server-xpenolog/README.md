# 🖥️ Side Quest: Turning an Old PC into a NAS Server

This project documents the process of converting an old desktop PC into a fully functional **Network Attached Storage (NAS)** system using **Xpenology (Synology DSM)**.

The goal was to create a **personal cloud + media server** that:
- Works on local network without internet
- Is accessible globally
- Uses old hardware efficiently
- Has remote access without complex networking

---

## 🚀 Features

- 📁 File storage & sharing (like Google Drive)
- 🌐 Remote access using Tailscale
- 🎬 Media streaming using Plex
- 📸 Phone photo backup
- 🧠 Runs on old hardware (Pentium G620, 4GB RAM)

---

## 🖥️ Hardware Used

- CPU: Intel Pentium G620
- RAM: 4GB
- Storage:
  - 320GB HDD
  - 500GB HDD
- Motherboard: HP OEM board (legacy BIOS limitations)
- Network: Ethernet (Realtek NIC)

---

## ⚙️ Software Stack

- **Bootloader**: ARC Loader
- **OS**: Synology DSM 7.1 (DS918+ model)
- **Remote Access**: Tailscale
- **Media Server**: Plex
- **File Sync**: Synology Drive

---

## 🛠️ Setup Overview

### 1. Installing DSM (Xpenology)

- Used ARC loader via USB
- Selected:
  - Model: `DS918+`
  - DSM Version: `7.1`
- Installed DSM via `find.synology.com`

---

### 2. Storage Configuration

Two drives configured as:

- Volume 1 → 320GB (important files)
- Volume 2 → 500GB (media)

File System:
- EXT4 (better for low-end hardware)

---

### 3. Network Setup

- Local Access: http://192.168.1.18:5000
  
- Fixed IP using router DHCP reservation

---

### 4. Remote Access (Tailscale)

Installed Tailscale and connected NAS to private network.

Access from anywhere: http://100.x.x.x:5000

No port forwarding required.

---

### 5. Media Server (Plex)

- Installed Plex Media Server
- Configured libraries:
  - Movies
  - TV Shows


---

### 6. File Access & Sync

- Synology Drive for cloud-like storage
- Accessible from:
  - Laptop
  - Phone
  - Anywhere via Tailscale

---

## ⚠️ Challenges Faced

- Bootloader errors (GRUB issues)
- PXE boot problems
- Disk not detected in DSM
- Compatibility issues with newer DSM versions
- WOL limitations due to hardware

---

## 🧩 Key Learnings

- Old hardware has hidden limitations (BIOS + power states)
- DSM model selection matters a lot (DS918+ worked best)
- Tailscale is the easiest remote access solution
- RAID is not always necessary for personal use
- Networking issues are often client-side (not server)

---

## 🔮 Future Improvements

- Add PCIe NIC for proper WOL support
- Automate media downloads (Sonarr/Radarr)
- Add UPS for safe shutdown
- Upgrade storage drives

---

## 🧠 Why this project matters

This project shows how to:

- Repurpose old hardware effectively
- Build a private cloud system
- Understand real-world system limitations
- Debug across hardware, OS, and network layers

---

## 📌 Final Result

A fully working:

- Personal Cloud ☁️  
- Media Server 🎬  
- Remote-access NAS 🌍  

Built from an old PC.

---

## 👤 Author

Harshvardhan Singh Tomar

---

## ⭐ Notes

This was a hands-on learning project focused on:
- problem solving
- system design
- real-world debugging
