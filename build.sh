#! /bin/bash

# -----------
# VARIABLES
# ----------------

OS=Doors
ISO_DIR=iso
DIST_DIR=dist
BOOT_DIR=$ISO_DIR/boot
GRUB_DIR=$BOOT_DIR/grub

# Check privileges
[ $EUID -ne 0 ] && sudo='sudo' || sudo=''

# -----------
# PREBUILD
# ----------------

# Check dependencies
dependencies=( build-essential gcc grub nasm xorriso )
for dep in ${dependencies[@]}; do
  if ! dpkg -l $dep &>/dev/null; then
    $sudo apt-get install -y $dep
  fi
done

if [ $EUID -eq 0 ]; then
 echo "ERROR: Try rerunning the script without privileges" 1>&2
 exit 1
fi

# Check DIST directory
[ -d $DIST_DIR ] || mkdir -vp $DIST_DIR

# Check GRUB directory
[ -d $GRUB_DIR ] || mkdir -vp $GRUB_DIR

# Check GRUB configuration file
[ -f $GRUB_DIR/grub.cfg ] || cat > $GRUB_DIR/grub.cfg << GRUB_CONFIG
set default=0
set timeout=0

menuentry $OS {
  set root=(hd96)
  multiboot /boot/kernel.bin
}
GRUB_CONFIG

# -----------
# BUILD
# ----------------

# Compile the files and link them
make || exit 1

# Create the ISO image
grub-mkrescue -o $DIST_DIR/$OS.iso $ISO_DIR

# -----------
# POSTBUILD
# ----------------

# Clean the build files
make clean

# Check if the script generated the ISO image
[ -f $DIST_DIR/$OS.iso ]
