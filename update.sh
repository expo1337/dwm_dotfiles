#!/bin/bash
configs=(gtk-3.0 htop lf lvim mpd mpv ncmcpp neofetch nitrogen nvim papirus-folders picom starship.toml sxhkd Thunar tmux user-dirs.dirs user-dirs.locale wget x11 zsh xfce4)
utils=(dwm dmenu st slstatus dnote slock)
folders=(.local .config .cache/zsh .cache/mpd .local/share/themes .local/src)

# Remove current .config
for i in "${configs[@]}"
do
    rm -rf $i
done

# Copy all folders in .config
cp -r .config/* $HOME/.config/

# Remove wallpapers and get new ones
rm $HOME/.wallpapers/*
mv wallpapers/* $HOME/.wallpapers

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

# Install yay aur helper
git clone https://aur.archlinux.org/yay-bin
cd yay-bin && makepkg -si && cd .. && rm -rf yay-bin
yay -S devour nsxiv librewolf-bin

printf "Phew! Done installing :3"
