#define MAX_NOTIFICATIONS 10
#define MAX_IMAGE_MEM 5 /* max number of recent images to keep in memory */

static const unsigned int def_expire = 2;                /* seconds until window disapears */
static unsigned int def_min_width = 500;                    /* minimum window width */
static const int def_center_text = 1;                     /* center text in window */
static unsigned int border_width = 2;                     /* size of the window border */
static unsigned int text_padding = 30;               /* cosmetic padding between lines of text */
static unsigned int contents_padding_vertical = 4;  /* vertical cosmetic padding between window edge and window contents */
static int bar_outer_padding = 12;                /* cosmetic padding between window edge and progress bar background */
static int bar_inner_padding = 7;                /* cosmetic padding between progress bar background and foreground */
static int border_padding = 150;                     /* cosmetic padding between notifications and screen border */
static int inter_padding = 20;                      /* cosmetic padding between notifications */

/* def_location values correspond to these positions on your screen
	|---+---+---|
	| 6 | 5 | 4 |
	|---+---+---|
	| 7 | 0 | 3 |
	|---+---+---|
	| 8 | 1 | 2 |
	|---+---+---|
*/
static const unsigned int def_location = 4;

/* default X11 font or font set */
static char font[]  = "Hack:size=16";
static char icons[] = "SymbolsNerdFont:size=22";
static const char *fonts[] = { font, icons };

static char normfgcolor[] = "#bbbbbb";
static char normbgcolor[] = "#222222";
static char selfgcolor[]  = "#eeeeee";
static char selbgcolor[]  = "#005577";
static char barfgcolor[]  = "#eeeeee";
static char barbgcolor[]  = "#005577";

/* color schemes */
static const char *colors[SchemeLast][2] = {
	             /*     fg         bg       */
	[SchemeNorm] = { selfgcolor, normbgcolor },
	[SchemeSel]  = { selfgcolor, selbgcolor },
	[SchemeBar]  = { barfgcolor, barbgcolor },
};

/* Xresources preferences to load at startup */
ResourcePref resources[] = {
	{ "dnotedfont",                STRING,  &font },
	{ "dnotedicons",               STRING,  &icons },
        { "color15",                   STRING,  &normfgcolor },
	{ "background",                STRING,  &normbgcolor },
	{ "color15",                   STRING,  &selfgcolor },
	{ "color9",                    STRING,  &selbgcolor },
	{ "color9",                    STRING,  &barfgcolor },
	{ "color8",                    STRING,  &barbgcolor },
	{ "borderpx",                  INTEGER, &border_width },
	{ "def_min_width",             INTEGER, &def_min_width  },
	{ "text_padding",              INTEGER, &text_padding  },
	{ "contents_padding_vertical", INTEGER, &contents_padding_vertical  },
	{ "bar_outer_padding",         INTEGER, &bar_outer_padding  },
	{ "bar_inner_padding",         INTEGER, &bar_inner_padding  },
	{ "border_padding",            INTEGER, &border_padding  },
	{ "inter_padding",             INTEGER, &inter_padding  },
};
