/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar    = 1;    /* -b  option; if 0, dmenu appears at bottom */
static int fuzzy     = 1;    /* -F  option; if 0, dmenu doesn't use fuzzy matching */
static int centered  = 0;    /* -c option; centers dmenu on screen */
static int vertpad   = 6;    /* vertical padding of bar */
static int sidepad   = 6;    /* horizontal padding of bar */
static int min_width = 640;  /* minimum width when centered */
static unsigned int lines = 0;  /* -l option; number of vertical lines */
static unsigned int border_width  = 0;
static unsigned int center_border = 2;

/* -h option; minimum height of a menu line */
static unsigned int lineheight = 0;
static unsigned int min_lineheight = 8;

/* -fn option overrides fonts[0]; default X11 font or font set */
static char font[]   = "Hack:size=14:antialias=true:autohint=true";
static char icons[]  = "SymbolsNerdFont:size=16:antialias=true:autohint=true";
static const char *fonts[] = { font, icons };

static char *prompt  = NULL; /* -p  option; prompt to the left of input field */

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

static char normfgcolor[] = "#bbbbbb";
static char normbgcolor[] = "#222222";
static char selfgcolor[]  = "#eeeeee";
static char selbgcolor[]  = "#005577";
static char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { normfgcolor, normbgcolor },
	[SchemeSel]  = { selfgcolor,  selbgcolor  },
	[SchemeOut]  = { "#000000",   "#00ffff" },
};
/* Xresources preferences to load at startup */
ResourcePref resources[] = {
	{ "centered",   INTEGER, &centered },
	{ "fuzzy",      INTEGER, &fuzzy },
	{ "borderpx",   INTEGER, &center_border },
	{ "vertpad",    INTEGER, &vertpad },
	{ "sidepad",    INTEGER, &sidepad },
	{ "user_bh",    INTEGER, &lineheight },
	{ "min_width",  INTEGER, &min_width },
	{ "lines",      INTEGER, &lines },
	{ "font",       STRING,  &font  },
	{ "icons",      STRING,  &icons },
	{ "color7",     STRING,  &normfgcolor },
	{ "background", STRING,  &normbgcolor },
	{ "color15",    STRING,  &selfgcolor },
	{ "color9",     STRING,  &selbgcolor },
};
