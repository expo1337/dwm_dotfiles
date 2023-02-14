# SÅM's build of st

St is the [suckless terminal](https://st.suckless.org/) from suckless. I've applied a few patches to implement features that I want.

**This build of st of part of SÅMDE, it's a shell script for arch based distros that installs my desktop setup. I highly recommend checking it out : [SÅMDE](https://gitlab.com/SamDenton/samde)**

## Patches

- alpha
- boxdraw
- dynamic-cursor-color
- font2
- glyph-wide-support-boxdraw
- scrollback
- scrollback-mouse
- xresources

## Installation
```
git clone --depth 1 https://gitlab.com/SamDenton/st.git
cd st
sudo make clean install
```
