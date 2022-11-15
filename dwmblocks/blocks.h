static const Block blocks[] = {
//   Icon    Command                          Update Interval     Update Signal
    { "  ", "checkupdates | wc -l",                 60,               0 },
//  { "",    "/home/expo/.local/bin/brightness",                           2,                0 },
    { "",    "/home/expo/.local/bin/volume",                               2,                0 },
//  { "",    "/home/expo/.local/bin/battery",                              60,               0 },
    { "",    "/home/expo/.local/bin/mem",	     5,		       0 },
    { "",    "/home/expo/.local/bin/cpu",	     3,		       0 },
    { "",    "date '+ %d/%m/%Y   %H:%M%p'",        5,                0 },
};

// Sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 5;
