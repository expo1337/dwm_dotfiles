#!/bin/bash
configs=(gtk-3.0 htop lf lvim mpd mpv ncmcpp neofetch nitrogen nvim papirus-folders picom starship.toml sxhkd Thunar tmux user-dirs.dirs user-dirs.locale wget x11 zsh xfce4)
utils=(dwm dmenu st slstatus dnote slock)
folders=(.local .config .cache/zsh .cache/mpd .local/share/themes .local/src)
bins=(dmenu-bluetooth dmenu_open fnkey lfub lvim papirus-folders plaunch power_menu rice_menu)
# Remove current .config
for i in "${configs[@]}"
do
    rm -rf $HOME/.config/$i
done

# Upadte scripts
for i in "${bins[@]}"
do
    rm $HOME/.local/bin/$i
done
cp .local/bin/* $HOME/.local/bin/

# Copy all folders in .config
cp -r .config/* $HOME/.config/

# Remove wallpapers and get new ones
rm $HOME/.wallpapers/*
cp wallpapers/* $HOME/.wallpapers

# Set Colorscheme + xresources
ln -sf $HOME/.config/x11/profiles/1080p.Xresources $HOME/.config/x11/xresources
ln -sf $HOME/.config/x11/colorschemes/Luna.Xresources $HOME/.config/x11/xcolors


# Move source of suckless stuff and compile
for i in "${utils[@]}"
do 
    rm -rf $HOME/.local/src/$i
done

for i in "${utils[@]}"
do
    cp -r .local/src/$i $HOME/.local/src/$i
    sudo make clean install -C $HOME/.local/src/$i
done

sudo rm /usr/share/xsessions/dwm.desktop
sudo rm /usr/share/xsessions/dwm-run
sudo cp dwm.desktop /usr/share/xsessions/
sudo cp dwm-run /usr/share/xsessions/
sudo chmod +x /usr/share/xsessions/dwm-run

clear
neofetch
printf "Phew! Done updating :3"
