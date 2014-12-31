Download Raspian Image from 
http://www.raspberrypi.org/documentation/installation/installing-images/README.md

Raspbian install guide.
http://www.raspberrypi.org/documentation/installation/installing-images/README.md

Linux install guide 
http://www.raspberrypi.org/documentation/installation/installing-images/linux.md

Linux headless install of wifi
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
 * ssh pi@192.168.1.12 
