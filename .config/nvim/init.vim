call plug#begin('~/.local/share/nvim/plugged')
"Plug 'neovim/nvim-lspconfig'
Plug 'junegunn/goyo.vim'
Plug 'itchyny/lightline.vim'
Plug 'ap/vim-css-color'
Plug 'junegunn/fzf.vim'

call plug#end()

set expandtab
set relativenumber
set nohlsearch
set smartindent
set nu
set ignorecase
set smartcase
set title
set nobackup
set wildmode=longest,list,full
set mouse=a

let g:lightline = { 'colorscheme': '16color', }

let mapleader = " "

noremap <leader>w :w<cr>
noremap <leader>s :setlocal spell!<cr>
noremap <leader>e :Ex<cr>
noremap <leader>f :FZF<cr>
noremap <leader>g :Goyo<cr>

inoremap " ""<left>
inoremap ( ()<left>
inoremap [ []<left>
inoremap { {}<left>

ab SH #!/bin/sh
