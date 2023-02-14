/* See LICENSE file for copyright and license details. */

/* appearance */
static unsigned int borderpx    = 2;  /* border pixel of windows */
static unsigned int gappx       = 8;  /* gaps between windows */
static unsigned int snap        = 16; /* snap pixel */
static int user_bh              = 40; /* 0 means that dwm will calculate bar height*/
static int vertpad              = 0;  /* vertical padding of bar */
static int sidepad              = 0;  /* horizontal padding of bar */
static int horizpadbar          = 0;  /* horizontal padding for statusbar */
static int vertpadbar           = 0;  /* vertical padding for statusbar */

static const int showbar        = 1;  /* 0 means no bar */
static const int topbar         = 1;  /* 0 means bottom bar */
static const int viewonrulestag = 1;  /* 1 means when open applications view will move to tags defined in rules*/
static const int colorfultag    = 1;  /* 0 means use SchemeSel for selected non vacant tag */

static char font[]              = { "Hack:size=14:antialias=true:autohint=true" };
static char icons[]             = { "SymbolsNerdFont:size=16:antialias=true:autohint=true" };
static const char *fonts[]      = { font, icons };

static char bgd[]               = "#000000";  /* Background  */
static char fgd[]               = "#ffffff";  /* Foreground */
static char col0[]              = "#000000";  /* Black */ 
static char col1[]              = "#cc0403";  /* Red */ 
static char col2[]              = "#19cb00";  /* Green */ 
static char col3[]              = "#cecb00";  /* Yellow */ 
static char col4[]              = "#001cd1";  /* Blue */ 
static char col5[]              = "#cb1ed1";  /* Magenta */ 
static char col6[]              = "#0dcdcd";  /* Cyan */ 
static char col7[]              = "#e5e5e5";  /* White */ 
static char col8[]              = "#4d4d4d";  /* Bright Black */ 
static char col9[]              = "#3e0605";  /* Bright Red */ 
static char col10[]             = "#23fd00";  /* Bright Green */ 
static char col11[]             = "#fffd00";  /* Bright Yellow */ 
static char col12[]             = "#0026ff";  /* Bright Blue */ 
static char col13[]             = "#fd28ff";  /* Bright Magenta */ 
static char col14[]             = "#14ffff";  /* Bright Cyan */ 
static char col15[]             = "#ffffff";  /* Bright White */ 

static char *termcolor[] = { col0, col1, col2, col3, col4, col5, col6, col7,
                             col8, col9, col10, col11, col12, col13, col14, col15, bgd, fgd };

static char *colors[][3] = {
       /*                     fg        bg       border   */
       [SchemeNorm]       = { col8,     bgd,     bgd  },
       [SchemeSel]        = { col15,    bgd,     col9 },
       [SchemeTitle]      = { col15,    bgd,     bgd  },
       [SchemeTag]        = { col8,     bgd,     bgd  },
       [SchemeTag1]       = { col9,     bgd,     bgd  },
       [SchemeTag2]       = { col10,    bgd,     bgd  },
       [SchemeTag3]       = { col11,    bgd,     bgd  },
       [SchemeTag4]       = { col12,    bgd,     bgd  },
       [SchemeTag5]       = { col13,    bgd,     bgd  },
       [SchemeLayout]     = { col14,    bgd,     bgd  },
};

/* tagging */
static const char *tags[] = { "爵", "", "", "", "", "", "", ""  };

static const int tagschemes[] = {
    SchemeTag1, SchemeTag2, SchemeTag3, SchemeTag4, SchemeTag5 };

static unsigned int ulinepad      = 3;    /* horizontal padding between the underline and tag */
static unsigned int ulinestroke   = 3;    /* thickness / height of the underline */
static unsigned int ulinevoffset  = 0;    /* how far above the bottom of the bar the line should appear */
static const int ulineall         = 0;    /* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
        /* xprop(1):
         *      WM_CLASS(STRING) = instance, class
         *      WM_NAME(STRING) = title
         */
        /* class          instance title         tags mask float sticky mon */
        { "LibreWolf",     NULL,  NULL,          1 << 0,   0,    0,     -1 },
        { "Brave-browser", NULL,  NULL,          1 << 0,   0,    0,     -1 },
        { "ST",            NULL,  NULL,          1 << 1,   0,    0,     -1 },
        { "Lf",            NULL,  NULL,          1 << 2,   0,    0,     -1 },
        { "Thunar",        NULL,  NULL,          1 << 2,   0,    0,     -1 },
        { "Virt-manager",  NULL,  NULL,          1 << 3,   0,    0,     -1 },
        { "Blender",       NULL,  NULL,          1 << 3,   0,    0,     -1 },
        {  NULL,           NULL,  "Ardour",      1 << 3,   0,    0,     -1 },
        { "kdenlive",      NULL,  NULL,          1 << 3,   0,    0,     -1 },
        { "obs",           NULL,  NULL,          1 << 4,   0,    0,     -1 },
        { "Guitarix",      NULL,  NULL,          1 << 4,   0,    0,     -1 },
        { "krita",         NULL,  NULL,          1 << 4,   0,    0,     -1 },
        { "Gimp",          NULL,  NULL,          1 << 4,   0,    0,     -1 },
        { "Steam",         NULL,  NULL,          1 << 4,   0,    0,     -1 },
        { "dolphin-emu",   NULL,  NULL,          1 << 4,   0,    0,     -1 },
        { "retroarch",     NULL,  NULL,          1 << 4,   0,    0,     -1 },
        { "AppRun.wrapped",NULL,  NULL,          1 << 4,   0,    0,     -1 },
        { "mupen64plus-qt",NULL,  NULL,          1 << 4,   0,    0,     -1 },

        /* Floating windows */
        { "mpv",           NULL, NULL,                0,   1,    1,     -1 },
        { "imv",           NULL, NULL,                0,   1,    1,     -1 },
        { "qt5ct",         NULL, NULL,                0,   1,    1,     -1 },
        { "Lxappearance",  NULL, NULL,                0,   1,    1,     -1 },
        { "LibreWolf",     NULL, "Picture-in-Picture",0,   1,    1,     -1 },
        { "LibreWolf",     NULL, "Library",           0,   1,    0,     -1 },
        { "net-runelite-launcher-Launcher",NULL, NULL,0,   1,    1,     -1 },
        { "Thunar",   NULL, "File Operation Progress",0,   1,    0,     -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
        /* symbol     arrange function */
        { "[]=",      tile },    /* first entry is default */
        { "><>",      NULL },    /* no layout function means floating behavior */
        { "[M]",      monocle },
};

/* key definitions */
#define M Mod4Mask
#define A Mod1Mask
#define S ShiftMask
#define C ControlMask
#define TAGKEYS(KEY,TAG) \
        { M,     KEY,  view,       {.ui = 1 << TAG} }, \
        { M|C,   KEY,  toggleview, {.ui = 1 << TAG} }, \
        { M|S,   KEY,  tag,        {.ui = 1 << TAG} }, \
        { M|C|S, KEY,  toggletag,  {.ui = 1 << TAG} },

/* commands */
static const char scratchpadname[] = "Scratchpad";
static const char *scratchpadcmd[] = { "st","-c", "SP,SP","-t", scratchpadname, NULL };

/* Xresources preferences to load at startup */

ResourcePref resources[] = {
		{ "borderpx",      INTEGER,  &borderpx },
		{ "user_bh",       INTEGER,  &user_bh },
		{ "gappx",         INTEGER,  &gappx },
		{ "vertpad",       INTEGER,  &vertpad },
		{ "sidepad",       INTEGER,  &sidepad },
		{ "vertpadbar",    INTEGER,  &vertpadbar },
		{ "horizpadbar",   INTEGER,  &horizpadbar },
		{ "ulinepad",      INTEGER,  &ulinepad },
		{ "ulinestroke",   INTEGER,  &ulinestroke },
		{ "ulinevoffset",  INTEGER,  &ulinevoffset },
		{ "font",           STRING,  &font },
		{ "icons",          STRING,  &icons },
		{ "foreground",     STRING,  &fgd },
		{ "background",     STRING,  &bgd },
		{ "color0",         STRING,  &col0 },
		{ "color1",         STRING,  &col1 },
		{ "color2",         STRING,  &col2 },
		{ "color3",         STRING,  &col3 },
		{ "color4",         STRING,  &col4 },
		{ "color5",         STRING,  &col5 },
		{ "color6",         STRING,  &col6 },
		{ "color7",         STRING,  &col7 },
		{ "color8",         STRING,  &col8 },
		{ "color9",         STRING,  &col9 },
		{ "color10",        STRING,  &col10 },
		{ "color11",        STRING,  &col11 },
		{ "color12",        STRING,  &col12 },
		{ "color13",        STRING,  &col13 },
		{ "color14",        STRING,  &col14 },
		{ "color15",        STRING,  &col15 },
};

static const Key keys[] = {
      /*  mod    key              function        argument */
        { M,     XK_t,            togglescratch,  {.v = scratchpadcmd } },
        { M,     XK_b,            togglebar,      {0} },
        { M,     XK_f,            togglefullscr,  {0} },
        { M,     XK_space,        togglefloating, {0} },
        { M,     XK_BackSpace,    togglesticky,   {0} },
        { M,     XK_semicolon,    zoom,           {0} },
        { M,     XK_Tab,          view,           {0} },
        { M,     XK_q,            killclient,     {0} },
        { M,     XK_j,            focusstack,     {.i = +1 } },
        { M,     XK_k,            focusstack,     {.i = -1 } },
        { M,     XK_n,            setmfact,       {.f = -0.05} },
        { M,     XK_period,       setmfact,       {.f = +0.05} },
        { M,     XK_h,            focusmon,       {.i = -1 } },
        { M,     XK_l,            focusmon,       {.i = +1 } },
        { M|S,   XK_h,            tagmon,         {.i = -1 } },
        { M|S,   XK_l,            tagmon,         {.i = +1 } },
        { M,     XK_comma,        incnmaster,     {.i = +1 } },
        { M,     XK_m,            incnmaster,     {.i = -1 } },
	{ M,     XK_minus,        setgaps,        {.i = -5 } },
	{ M,     XK_equal,        setgaps,        {.i = +5 } },
	{ M|S,   XK_equal,        setgaps,        {.i =  0 } },
	{ M|C,   XK_h,	          moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ M|C,   XK_j,	          moveresize,     {.v = "0x 25y 0w 0h" } },
	{ M|C,   XK_k,	          moveresize,     {.v = "0x -25y 0w 0h" } },
        { M|C,   XK_l,            moveresize,     {.v = "25x 0y 0w 0h" } },
	{ M|A,   XK_h,            movetoedge,     {.v = "-1 1" } },
	{ M|A,   XK_j,            movetoedge,     {.v = "1 1" } },
	{ M|A,   XK_k,            movetoedge,     {.v = "-1 -1" } },
	{ M|A,   XK_l,            movetoedge,     {.v = "1 -1" } },
	{ M|A,   XK_semicolon,    movetoedge,     {.v = "0 0" } },
	{ M,     XK_t,            setlayout,      {.v = &layouts[0]} },
        { M,     XK_c,            setlayout,      {.v = &layouts[1]} },
        { M,     XK_m,            setlayout,      {.v = &layouts[2]} },
        { M,     XK_F5,           xrdb,           {.v = NULL } },
        { M,     XK_0,            view,           {.ui = ~0 } },
        { M|S,   XK_0,            tag,            {.ui = ~0 } },
        TAGKEYS( XK_1,                            0)
        TAGKEYS( XK_2,                            1)
        TAGKEYS( XK_3,                            2)
        TAGKEYS( XK_4,                            3)
        TAGKEYS( XK_5,                            4)
        TAGKEYS( XK_6,                            5)
        TAGKEYS( XK_7,                            6)
        TAGKEYS( XK_8,                            7)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
        /* click                event mask      button          function        argument */
        { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
        { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
        { ClkWinTitle,          0,              Button2,        zoom,           {0} },
        { ClkStatusText,        0,              Button2,        spawn,          {.v = scratchpadcmd } },
        { ClkClientWin,         M,              Button1,        movemouse,      {0} },
        { ClkClientWin,         M,              Button2,        togglefloating, {0} },
        { ClkClientWin,         M,              Button3,        resizemouse,    {0} },
        { ClkTagBar,            0,              Button1,        view,           {0} },
        { ClkTagBar,            0,              Button3,        toggleview,     {0} },
        { ClkTagBar,            M,              Button1,        tag,            {0} },
        { ClkTagBar,            M,              Button3,        toggletag,      {0} },
};
