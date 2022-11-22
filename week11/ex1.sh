fallocate --length 50M lofs.img
sudo losetup -fP lofs.img
sudo mkfs.ext4 /dev/loop0
mkdir lofsdisk
sudo mount --types ext4 /dev/loop0 lofsdisk
