Download Raspian Image
----------------------
http://www.raspberrypi.org/documentation/installation/installing-images/README.md

Copy raspbian to sdcard
-----------------------
http://www.raspberrypi.org/documentation/installation/installing-images/README.md

Linux install guide 

http://www.raspberrypi.org/documentation/installation/installing-images/linux.md
I did just right click on the expanded file and used write to usb-stick on Linux Mint

Linux headless install of wifi
------------------------------
http://blog.self.li/post/63281257339/raspberry-pi-part-1-basic-setup-without-cables

Modyfy the /etc/network/interfaces

    auto lo
    iface lo inet loopback
    iface eth0 inet dhcp
    auto wlan0
    allow-hotplug wlan0
    iface wlan0 inet dhcp
    wpa-ssid "your-network-name"
    wpa-psk "password-here"

To login
First time pw is raspbian, change this!

    ssh pi@192.168.1.12 
    

Configure pi
-----------

    sudo raspi-config

 * Expand file sysyem    
 * Change PW
 * boot to console
 * change locale ( [*] sv_SE.ISO-8859-15 ISO-8859-15 )
 * Memory split 16Mb
 * reboot 
 
Samba setup
-----------
Most is taken from:
http://raspberrywebserver.com/serveradmin/share-your-raspberry-pis-files-and-folders-across-a-network.html

    sudo apt-get update
    sudo apt-get upgrade
    sudo apt-get install samba samba-common-bin
    sudo nano /etc/samba/smb.conf
    
Add the following to smb.conf

    [pihome]
    comment= Pi Home
    path=/home/pi
    browseable=Yes
    writeable=Yes
    only guest=no
    create mask=0777
    directory mask=0777
    public=no
    
Set a new samba pw

    sudo smbpasswd -a pi
    sudo service samba restart
    
Mount the pihome to local filesystem
------------------------------------
I did this in the filebrowser on mint
