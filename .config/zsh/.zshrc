# History

HISTSIZE=1000000
SAVEHIST=1000000
HISTFILE="${XDG_CACHE_HOME:-$HOME/.cache}/zsh/history"

# Sourcing aliases and cdable_vars if they are present on the system.

setopt cdable_vars
[ -f "${XDG_CONFIG_HOME:-$HOME/.config}/zsh/.zsh_cdvars" ] && source "${XDG_CONFIG_HOME:-$HOME/.config}/zsh/.zsh_cdvars"
[ -f "${XDG_CONFIG_HOME:-$HOME/.config}/zsh/.zsh_aliases" ] && source "${XDG_CONFIG_HOME:-$HOME/.config}/zsh/.zsh_aliases"

# Vi mode

bindkey -v
export KEYTIMEOUT=1
bindkey "^R" history-incremental-search-backward

setopt autocd           # Automatically cd into a typed path
stty stop undef         # Disable ctrl-s to freeze the terminal 



# Completion

autoload -Uz compinit 
compinit
zstyle ':completion:*' menu select

# Plugins
export PATH=$HOME/.local/bin:$PATH
source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh
eval "$(starship init zsh)"
