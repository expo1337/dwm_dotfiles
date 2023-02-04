# SÅM's build of dwm
<img src="https://gitlab.com/SamDenton/screenshots/-/raw/master/luna.jpg">
[Dwm](https://dwm.suckless.org/) is a dynamic tiling window manager created by suckless. I have applied quite a few patches created by the suckless community and made some of my own modifications to the source code to implement the features that I want.

**This build of dwm of part of SÅMDE, it's a shell script for arch based distros that installs my desktop setup. I highly recommend checking it out : [SÅMDE](https://gitlab.com/SamDenton/samde)**

# Patches
Here is the full list of the patches I've applied

- actualfullscreen
- alwayscenter
- aspectresize
- attachbottom
- bar-height
- barpadding
- centretitle
- colorfultags
- fixborders
- fullgaps
- moveresize
- movetoedge
- pertag
- preserveonrestart
- scratchpad
- status2d
- statuspadding
- sticky
- stickyrule
- underlinetags
- viewonrulestag
- xresources

# Installation
```
git clone --depth 1 https://gitlab.com/SamDenton/dwm.git
cd dwm
sudo make install
```
