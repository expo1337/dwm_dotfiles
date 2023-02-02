# Adds `~/.local/bin` to $PATH
export PATH="$PATH:${$(find ~/.local/bin -type d -printf %p:)%%:}"

#XDG base/home cleanup
export XDG_CONFIG_HOME="$HOME/.config"
export XDG_DATA_HOME="$HOME/.local/share"
export XDG_CACHE_HOME="$HOME/.cache"
export XDG_STATE_HOME="$HOME/.local/state"

export GTK2_RC_FILES="$XDG_CONFIG_HOME/gtk-2.0/gtkrc"
export ZDOTDIR="$HOME/.config/zsh"
export XINITRC="$XDG_CONFIG_HOME/x11/xinitrc"
export WGETRC="$XDG_CONFIG_HOME/wget/wgetrc"
export WINEPREFIX="$XDG_DATA_HOME/wine"
export XAUTHORITY="$XDG_RUNTIME_DIR/Xauthority"
export LESSHISTFILE="-"
export XCURSOR_PATH="/usr/share/icons:${XDG_DATA_HOME}/icons"
export NPM_CONFIG_USERCONFIG="$XDG_CONFIG_HOME/npm/npmrc"

#Default programs
export EDITOR="nvim"
export TERMINAL="st"
export BROWSER="librewolf"
export VIDEO="mpv"
export IMAGE="imv"
export WM="dwm"

#GTK/QT settings
export QT_QPA_PLATFORMTHEME="qt5ct"

#[ "$(tty)" = "/dev/tty1" ] && ! pidof -s Xorg >/dev/null 2>&1 && exec startx "$XINITRC"
