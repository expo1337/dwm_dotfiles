#!/bin/bash

utils=(dwm dmenu st slstatus dnote slock)
folders=(.local .config .cache/zsh .cache/mpd .local/share/themes .local/src)

# Checks for folders and creates them if absent
for i in "${folders[@]}"; do [ -d $HOME/$i ] || mkdir -p $HOME/$i; done

# Enables Color, ParallelDownloads, ILoveCandy and adds the number of cpu threads in makepkg.conf
sudo sed -i "/Color/s/^#//;/Parallel/s/^#//;/#VerbosePkgLists/a ILoveCandy" /etc/pacman.conf
sudo sed -i "s/-j2/-j$(nproc)/;/^#MAKEFLAGS/s/^#//" /etc/makepkg.conf

# Installs programs in pkg.txt
sudo pacman -Syu --noconfirm
sudo pacman --noconfirm --needed -S - < pkgs.txt || error "Failed to install packages"

# Makes zsh the default shell
sudo usermod -s /bin/zsh $USER
echo "export ZDOTDIR=\"\$HOME\"/.config/zsh" | sudo tee -a /etc/zsh/zshenv
touch $HOME/.cache/zsh/history

# Copy all folders in .config
cp -r .config/* $HOME/.config/
# Set Colorscheme + xresources
ln -sf $HOME/.config/x11/profiles/1080p.Xresources $HOME/.config/x11/xresources
ln -sf $HOME/.config/x11/colorschemes/Luna.Xresources $HOME/.config/x11/xcolors
#
# Clone wallpapers
#git clone --depth 1 https://gitlab.com/samdenton/wallpapers.git $HOME/.local/share/wallpapers
#ln -sf $HOME/.local/share/wallpapers/Luna.png $HOME/.config/x11/wall
mkdir $HOME/.wallpapers
mv wallpapers/* $HOME/.wallpapers

# Move source of suckless stuff and compile
for i in "${utils[@]}"
do
    cp -r .local/src/$i $HOME/.local/src/$i
    sudo make install -C $HOME/.local/src/$i
done

# Install yay aur helper
git clone https://aur.archlinux.org/yay-bin
cd yay-bin && makepkg -si && cd .. && rm -rf yay-bin
yay -S devour nsxiv librewolf-bin

# Installs papirus icon theme and folder colors
wget -qO- https://git.io/papirus-icon-theme-install | DESTDIR="$HOME/.local/share/icons" sh
wget -qO- https://git.io/papirus-folders-install | env PREFIX=$HOME/.local sh
$HOME/.local/bin/papirus-folders -C indigo

# Installs GTK themes
git clone --depth 1 https://github.com/Fausto-Korpsvart/Rose-Pine-GTK-Theme.git
mv Rose-Pine-GTK-Theme/themes/*BL $HOME/.local/share/themes
rm -rf Rose-Pine-GTK-Theme

git clone --depth 1 https://github.com/Fausto-Korpsvart/Everforest-GTK-Theme.git
mv Everforest-GTK-Theme/themes/Everforest-Dark-BL $HOME/.local/share/themes
rm -rf Everforest-GTK-Theme

# Installs vim-plug
sh -c 'curl -fLo "${XDG_DATA_HOME:-$HOME/.local/share}"/nvim/site/autoload/plug.vim --create-dirs \
       https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'
nvim -c "PlugInstall|q|q"

printf "Phew! Done installing :3"
