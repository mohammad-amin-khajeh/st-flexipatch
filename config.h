/* See LICENSE file for copyright and license details. */

/*
 * appearance
 *
 * font: see http://freedesktop.org/software/fontconfig/fontconfig-user.html
 */
static char *font = "firacode nerd font:pixelsize=17:antialias=true:autohint=true";
#if FONT2_PATCH
/* Spare fonts */
static char *font2[] = {
"noto color emoji:pixelsize=17",
"joyPixels:pixelsize=17:antialias=true:autohint=true",
"FontAwesome:pixelsize=17:antialias=true:autohint=true",
"Noto Sans CJK JP:pixelsize=17:antialias=true:autohint=true",
"Arial:pixelsize=17:antialias=true:autohint=true",
};
#endif // FONT2_PATCH

#if BACKGROUND_IMAGE_PATCH
/*
 * background image
 * expects farbfeld format
 * pseudo transparency fixes coordinates to the screen origin
 */
static const char *bgfile = "/path/to/image.ff";
static const int pseudotransparency = 0;
#endif // BACKGROUND_IMAGE_PATCH

#if RELATIVEBORDER_PATCH
/* borderperc: percentage of cell width to use as a border
 *             0 = no border, 100 = border width is same as cell width */
int borderperc = 20;
#else
static int borderpx = 0;
#endif // RELATIVEBORDER_PATCH

#if OPENURLONCLICK_PATCH
/* modkey options: ControlMask, ShiftMask or XK_ANY_MOD */
static uint url_opener_modkey = XK_ANY_MOD;
static char *url_opener = "xdg-open";
#endif // OPENURLONCLICK_PATCH

/*
 * What program is execed by st depends of these precedence rules:
 * 1: program passed with -e
 * 2: scroll and/or utmp
 * 3: SHELL environment variable
 * 4: value of shell in /etc/passwd
 * 5: value of shell in config.h
 */
static char *shell = "/bin/sh";
char *utmp = "zsh";
/* scroll program: to enable use a string like "scroll" */
char *scroll = NULL;
char *stty_args = "stty raw pass8 nl -echo -iexten -cstopb 38400";

/* identification sequence returned in DA and DECID */
#if SIXEL_PATCH
char *vtiden = "\033[?62;4c"; /* VT200 family (62) with sixel (4) */

/* sixel rgb byte order: LSBFirst or MSBFirst */
int const sixelbyteorder = LSBFirst;
#else
char *vtiden = "\033[?6c";
#endif

/* Kerning / character bounding-box multipliers */
static float cwscale = 1.0;
static float chscale = 1.0;

/*
 * word delimiter string
 *
 * More advanced example: L" `'\"()[]{}"
 */
wchar_t *worddelimiters = L" ";

#if KEYBOARDSELECT_PATCH && REFLOW_PATCH
/* Word delimiters for short and long jumps in the keyboard select patch */
wchar_t *kbds_sdelim = L"!\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~ ";
wchar_t *kbds_ldelim = L" ";
#endif // KEYBOARDSELECT_PATCH

/* selection timeouts (in milliseconds) */
static unsigned int doubleclicktimeout = 300;
static unsigned int tripleclicktimeout = 600;

/* alt screens */
int allowaltscreen = 1;

/* allow certain non-interactive (insecure) window operations such as:
   setting the clipboard text */
int allowwindowops = 0;

/*
 * draw latency range in ms - from new content/keypress/etc until drawing.
 * within this range, st draws when content stops arriving (idle). mostly it's
 * near minlatency, but it waits longer for slow updates to avoid partial draw.
 * low minlatency will tear/flicker more, as it can "detect" idle too early.
 */
static double minlatency = 20;
static double maxlatency = 30;

#if SYNC_PATCH
/*
 * Synchronized-Update timeout in ms
 * https://gitlab.com/gnachman/iterm2/-/wikis/synchronized-updates-spec
 */
static uint su_timeout = 200;
#endif // SYNC_PATCH

/*
 * blinking timeout (set to 0 to disable blinking) for the terminal blinking
 * attribute.
 */
static unsigned int blinktimeout = 500;

/*
 * thickness of underline and bar cursors
 */
static unsigned int cursorthickness = 1;

#if HIDECURSOR_PATCH
/* Hide the X cursor whenever a key is pressed. 0: off, 1: on */
int hidecursor = 1;
#endif // HIDECURSOR_PATCH

#if BOXDRAW_PATCH
/*
 * 1: render most of the lines/blocks characters without using the font for
 *    perfect alignment between cells (U2500 - U259F except dashes/diagonals).
 *    Bold affects lines thickness if boxdraw_bold is not 0. Italic is ignored.
 * 0: disable (render all U25XX glyphs normally from the font).
 */
const int boxdraw = 1;
const int boxdraw_bold = 1;

/* braille (U28XX):  1: render as adjacent "pixels",  0: use font */
const int boxdraw_braille = 0;
#endif // BOXDRAW_PATCH

/*
 * bell volume. It must be a value between -100 and 100. Use 0 for disabling
 * it
 */
static int bellvolume = 0;

/* default TERM value */
char *termname = "st-256color";

/*
 * spaces per tab
 *
 * When you are changing this value, don't forget to adapt the »it« value in
 * the st.info and appropriately install the st.info in the environment where
 * you use this st version.
 *
 *	it#$tabspaces,
 *
 * Secondly make sure your kernel is not expanding tabs. When running `stty
 * -a` »tab0« should appear. You can tell the terminal to not expand tabs by
 *  running following command:
 *
 *	stty tabs
 */
unsigned int tabspaces = 4;

#if ALPHA_PATCH
/* bg opacity */
float alpha = 1.0;
#if ALPHA_GRADIENT_PATCH
float grad_alpha = 0.54; //alpha value that'll change
float stat_alpha = 0.46; //constant alpha value that'll get added to grad_alpha
#endif // ALPHA_GRADIENT_PATCH
#if ALPHA_FOCUS_HIGHLIGHT_PATCH
float alphaUnfocused = 0.6;
#endif // ALPHA_FOCUS_HIGHLIGHT_PATCH
#endif // ALPHA_PATCH

#if DRAG_AND_DROP_PATCH
/*
 * drag and drop escape characters
 *
 * this will add a '\' before any characters specified in the string.
 */
char *xdndescchar = " !\"#$&'()*;<>?[\\]^`{|}~";
#endif // DRAG_AND_DROP_PATCH

/* Terminal colors (16 first used in escape sequence) */
static const char *colorname[] = {
	/* 8 normal colors */
  "#15151e",
  "#f7768e",
  "#9ece6a",
  "#e0af68",
  "#7aa2f7",
  "#bb9af7",
  "#7dcfff",
  "#a9b1d6",

	/* 8 bright colors */
  "#414868",
  "#ff899d",
  "#9fe044",
  "#faba4a",
  "#8db0ff",
  "#c7a9ff",
  "#a4daff",
  "#c0caf5",

	[255] = 0,

	/* more colors can be added after 255 to use with DefaultXX */
  "#c0caf5", /* 256 -> cursor */
  "#15151e", /* 257 -> rev cursor*/
  "#15151e", /* 258 -> bg */
  "#c0caf5", /* 259 -> fg */
};


/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor
 */
#if ALPHA_PATCH && ALPHA_FOCUS_HIGHLIGHT_PATCH
unsigned int defaultbg = 0;
unsigned int bg = 17, bgUnfocused = 16;
#else
unsigned int defaultbg = 258;
#endif // ALPHA_FOCUS_HIGHLIGHT_PATCH
unsigned int defaultfg = 259;
unsigned int defaultcs = 256;
unsigned int defaultrcs = 257;
#if SELECTION_COLORS_PATCH
unsigned int selectionfg = 258;
unsigned int selectionbg = 259;
/* If 0 use selectionfg as foreground in order to have a uniform foreground-color */
/* Else if 1 keep original foreground-color of each cell => more colors :) */
static int ignoreselfg = 1;
#endif // SELECTION_COLORS_PATCH
#if KEYBOARDSELECT_PATCH && REFLOW_PATCH
/* Foreground and background color of search results */
unsigned int highlightfg = 15;
unsigned int highlightbg = 160;
#endif // KEYBOARDSELECT_PATCH

#if BLINKING_CURSOR_PATCH
/*
 * https://invisible-island.net/xterm/ctlseqs/ctlseqs.html#h4-Functions-using-CSI-_-ordered-by-the-final-character-lparen-s-rparen:CSI-Ps-SP-q.1D81
 * Default style of cursor
 * 0: Blinking block
 * 1: Blinking block (default)
 * 2: Steady block ("â–ˆ")
 * 3: Blinking underline
 * 4: Steady underline ("_")
 * 5: Blinking bar
 * 6: Steady bar ("|")
 * 7: Blinking st cursor
 * 8: Steady st cursor
 */
static unsigned int cursorstyle = 5;
static Rune stcursor = 0x2603; /* snowman (U+2603) */
#else
/*
 * Default shape of cursor
 * 2: Block ("█")
 * 4: Underline ("_")
 * 6: Bar ("|")
 * 7: Snowman ("☃")
 */
static unsigned int cursorshape = 6;
#endif // BLINKING_CURSOR_PATCH

/*
 * Default columns and rows numbers
 */

static unsigned int cols = 80;
static unsigned int rows = 24;

#if ANYGEOMETRY_PATCH
/*
 * Whether to use pixel geometry or cell geometry
 */

static Geometry geometry = CellGeometry; // or PixelGeometry to use the below size
static unsigned int width = 564;
static unsigned int height = 364;
#endif // ANYGEOMETRY_PATCH

#if THEMED_CURSOR_PATCH
/*
 * Default shape of the mouse cursor
 */
static char* mouseshape = "xterm";
#else
/*
 * Default colour and shape of the mouse cursor
 */
static unsigned int mouseshape = XC_xterm;
static unsigned int mousefg = 7;
static unsigned int mousebg = 0;
#endif // THEMED_CURSOR_PATCH

/*
 * Color used to display font attributes when fontconfig selected a font which
 * doesn't match the ones requested.
 */
static unsigned int defaultattr = 11;

#if XRESOURCES_PATCH
/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "font",         STRING,  &font },
		{ "color0",       STRING,  &colorname[0] },
		{ "color1",       STRING,  &colorname[1] },
		{ "color2",       STRING,  &colorname[2] },
		{ "color3",       STRING,  &colorname[3] },
		{ "color4",       STRING,  &colorname[4] },
		{ "color5",       STRING,  &colorname[5] },
		{ "color6",       STRING,  &colorname[6] },
		{ "color7",       STRING,  &colorname[7] },
		{ "color8",       STRING,  &colorname[8] },
		{ "color9",       STRING,  &colorname[9] },
		{ "color10",      STRING,  &colorname[10] },
		{ "color11",      STRING,  &colorname[11] },
		{ "color12",      STRING,  &colorname[12] },
		{ "color13",      STRING,  &colorname[13] },
		{ "color14",      STRING,  &colorname[14] },
		{ "color15",      STRING,  &colorname[15] },
		{ "background",   STRING,  &colorname[258] },
		{ "foreground",   STRING,  &colorname[259] },
		{ "cursorColor",  STRING,  &colorname[256] },
		{ "termname",     STRING,  &termname },
		{ "shell",        STRING,  &shell },
		{ "minlatency",   INTEGER, &minlatency },
		{ "maxlatency",   INTEGER, &maxlatency },
		{ "blinktimeout", INTEGER, &blinktimeout },
		{ "bellvolume",   INTEGER, &bellvolume },
		{ "tabspaces",    INTEGER, &tabspaces },
		#if RELATIVEBORDER_PATCH
		{ "borderperc",   INTEGER, &borderperc },
		#else
		{ "borderpx",     INTEGER, &borderpx },
		#endif // RELATIVEBORDER_PATCH
		{ "cwscale",      FLOAT,   &cwscale },
		{ "chscale",      FLOAT,   &chscale },
		#if ALPHA_PATCH
		{ "alpha",        FLOAT,   &alpha },
		#endif // ALPHA_PATCH
		#if ALPHA_FOCUS_HIGHLIGHT_PATCH
		{ "alphaUnfocused",FLOAT,  &alphaUnfocused },
		#endif // ALPHA_FOCUS_HIGHLIGHT_PATCH
		#if KEYBOARDSELECT_PATCH && REFLOW_PATCH
		{ "highlightfg",  INTEGER, &highlightfg },
		{ "highlightbg",  INTEGER, &highlightbg },
		#endif // KEYBOARDSELECT_PATCH
};
#endif // XRESOURCES_PATCH

/*
 * Force mouse select/shortcuts while mask is active (when MODE_MOUSE is set).
 * Note that if you want to use ShiftMask with selmasks, set this to an other
 * modifier, set to 0 to not use it.
 */
static uint forcemousemod = ShiftMask;

/*
 * Internal mouse shortcuts.
 * Beware that overloading Button1 will disable the selection.
 */
static MouseShortcut mshortcuts[] = {
	/* mask                 button   function        argument       release  screen */
	#if OPEN_SELECTED_TEXT_PATCH
	{ ControlMask,          Button2, selopen,        {.i = 0},      1 },
	#endif // OPEN_SELECTED_TEXT_PATCH
	#if CLIPBOARD_PATCH
	{ XK_ANY_MOD,           Button2, clippaste,      {.i = 0},      1 },
	#else
	{ XK_ANY_MOD,           Button2, selpaste,       {.i = 0},      1 },
	#endif // CLIPBOARD_PATCH
	#if SCROLLBACK_MOUSE_PATCH
	{ XK_ANY_MOD,           Button4, kscrollup,      {.i = 3},      0, S_PRI},
	{ XK_ANY_MOD,           Button5, kscrolldown,    {.i = 3},      0, S_PRI},
	#elif UNIVERSCROLL_PATCH
	{ XK_ANY_MOD,           Button4, ttysend,        {.s = "\033[5;2~"}, 0, S_PRI },
	{ XK_ANY_MOD,           Button5, ttysend,        {.s = "\033[6;2~"}, 0, S_PRI },
	#else
	{ ShiftMask,            Button4, ttysend,        {.s = "\033[5;2~"} },
	{ ShiftMask,            Button5, ttysend,        {.s = "\033[6;2~"} },
	#endif // SCROLLBACK_MOUSE_PATCH
	#if SCROLLBACK_MOUSE_ALTSCREEN_PATCH || REFLOW_PATCH
	{ XK_ANY_MOD,           Button4, kscrollup,      {.i = 1},      0, S_PRI },
	{ XK_ANY_MOD,           Button5, kscrolldown,    {.i = 1},      0, S_PRI },
	{ XK_ANY_MOD,           Button4, ttysend,        {.s = "\031"}, 0, S_ALT },
	{ XK_ANY_MOD,           Button5, ttysend,        {.s = "\005"}, 0, S_ALT },
	#else
	{ XK_ANY_MOD,           Button4, ttysend,        {.s = "\031"} },
	{ XK_ANY_MOD,           Button5, ttysend,        {.s = "\005"} },
	#endif // SCROLLBACK_MOUSE_ALTSCREEN_PATCH
};

/* Internal keyboard shortcuts. */
#define MODKEY Mod1Mask
#define TERMMOD (ControlMask|ShiftMask)

#if EXTERNALPIPE_PATCH // example command
static char *openurlcmd[] = { "/bin/sh", "-c",
	"xurls | dmenu -l 10 -w $WINDOWID | xargs -r open",
	"externalpipe", NULL };

#if EXTERNALPIPEIN_PATCH // example command
static char *setbgcolorcmd[] = { "/bin/sh", "-c",
	"printf '\033]11;#008000\007'",
	"externalpipein", NULL };
#endif // EXTERNALPIPEIN_PATCH
#endif // EXTERNALPIPE_PATCH

static Shortcut shortcuts[] = {
	/* mask                 keysym          function         argument   screen */
	{ XK_ANY_MOD,           XK_Break,       sendbreak,       {.i =  0} },
	{ ControlMask,          XK_Print,       toggleprinter,   {.i =  0} },
	{ ShiftMask,            XK_Print,       printscreen,     {.i =  0} },
	{ XK_ANY_MOD,           XK_Print,       printsel,        {.i =  0} },
	{ TERMMOD,              XK_plus,        zoom,            {.f = +1} },
	{ ControlMask,          XK_minus,       zoom,            {.f = -1} },
	{ TERMMOD,              XK_Home,        zoomreset,       {.f =  0} },
	{ TERMMOD,              XK_C,           clipcopy,        {.i =  0} },
	{ TERMMOD,              XK_V,           clippaste,       {.i =  0} },
	#if ALPHA_PATCH
	{ TERMMOD,              XK_P,           changealpha,     {.f = +0.05} },
	{ TERMMOD,              XK_O,           changealpha,     {.f = -0.05} },
	#if ALPHA_FOCUS_HIGHLIGHT_PATCH
	//{ TERMMOD,              XK_,           changealphaunfocused, {.f = +0.05} },
	//{ TERMMOD,              XK_,           changealphaunfocused, {.f = -0.05} },
	#endif // ALPHA_FOCUS_HIGHLIGHT_PATCH
	#endif // ALPHA_PATCH
	#if FULLSCREEN_PATCH
	{ XK_NO_MOD,            XK_F11,         fullscreen,      {.i =  0} },
	{ MODKEY,               XK_Return,      fullscreen,      {.i =  0} },
	#endif // FULLSCREEN_PATCH
	#if SCROLLBACK_PATCH
	{ ShiftMask,            XK_Page_Up,     kscrollup,       {.i = -1}, S_PRI },
	{ ShiftMask,            XK_Page_Down,   kscrolldown,     {.i = -1}, S_PRI },
	#endif // SCROLLBACK_PATCH
	#if CLIPBOARD_PATCH
	{ TERMMOD,              XK_Y,           clippaste,       {.i =  0} },
	{ ShiftMask,            XK_Insert,      clippaste,       {.i =  0} },
	#else
	{ TERMMOD,              XK_Y,           selpaste,        {.i =  0} },
	{ ShiftMask,            XK_Insert,      selpaste,        {.i =  0} },
	#endif // CLIPBOARD_PATCH
	{ TERMMOD,              XK_Num_Lock,    numlock,         {.i =  0} },
	#if COPYURL_PATCH || COPYURL_HIGHLIGHT_SELECTED_URLS_PATCH
	{ MODKEY,               XK_l,           copyurl,         {.i =  0} },
	#endif // COPYURL_PATCH
	#if OPENCOPIED_PATCH
	{ MODKEY,               XK_o,           opencopied,      {.v = "xdg-open"} },
	#endif // OPENCOPIED_PATCH
	#if NEWTERM_PATCH
	{ TERMMOD,              XK_Return,      newterm,         {.i =  0} },
	#endif // NEWTERM_PATCH
	#if EXTERNALPIPE_PATCH
	{ TERMMOD,              XK_U,           externalpipe,    { .v = openurlcmd } },
	#if EXTERNALPIPEIN_PATCH
	{ TERMMOD,              XK_M,           externalpipein,  { .v = setbgcolorcmd } },
	#endif // EXTERNALPIPEIN_PATCH
	#endif // EXTERNALPIPE_PATCH
	#if KEYBOARDSELECT_PATCH
	{ TERMMOD,              XK_Escape,      keyboard_select, { 0 } },
	#endif // KEYBOARDSELECT_PATCH
	#if KEYBOARDSELECT_PATCH && REFLOW_PATCH
	{ TERMMOD,              XK_F,           searchforward,   { 0 } },
	{ TERMMOD,              XK_B,           searchbackward,  { 0 } },
	#endif // KEYBOARDSELECT_PATCH
	#if ISO14755_PATCH
	{ TERMMOD,              XK_I,           iso14755,        {.i =  0} },
	#endif // ISO14755_PATCH
	#if INVERT_PATCH
	{ TERMMOD,              XK_X,           invert,          { 0 } },
	#endif // INVERT_PATCH
	#if OSC133_PATCH
	{ ControlMask,          XK_Page_Up,     scrolltoprompt,  {.i = -1}, S_PRI },
	{ ControlMask,          XK_Page_Down,   scrolltoprompt,  {.i =  1}, S_PRI },
	#endif // OSC133_PATCH
};

/*
 * Special keys (change & recompile st.info accordingly)
 *
 * Mask value:
 * * Use XK_ANY_MOD to match the key no matter modifiers state
 * * Use XK_NO_MOD to match the key alone (no modifiers)
 * appkey value:
 * * 0: no value
 * * > 0: keypad application mode enabled
 * *   = 2: term.numlock = 1
 * * < 0: keypad application mode disabled
 * appcursor value:
 * * 0: no value
 * * > 0: cursor application mode enabled
 * * < 0: cursor application mode disabled
 *
 * Be careful with the order of the definitions because st searches in
 * this table sequentially, so any XK_ANY_MOD must be in the last
 * position for a key.
 */

#if !FIXKEYBOARDINPUT_PATCH
/*
 * If you want keys other than the X11 function keys (0xFD00 - 0xFFFF)
 * to be mapped below, add them to this array.
 */
static KeySym mappedkeys[] = { -1 };
#endif // FIXKEYBOARDINPUT_PATCH

/*
 * State bits to ignore when matching key or button events.  By default,
 * numlock (Mod2Mask) and keyboard layout (XK_SWITCH_MOD) are ignored.
 */
static uint ignoremod = Mod2Mask|XK_SWITCH_MOD;

#if !FIXKEYBOARDINPUT_PATCH
/*
 * This is the huge key array which defines all compatibility to the Linux
 * world. Please decide about changes wisely.
 */
static Key key[] = {
	/* keysym           mask            string      appkey appcursor */
	{ XK_KP_Home,       ShiftMask,      "\033[2J",       0,   -1},
	{ XK_KP_Home,       ShiftMask,      "\033[1;2H",     0,   +1},
	{ XK_KP_Home,       XK_ANY_MOD,     "\033[H",        0,   -1},
	{ XK_KP_Home,       XK_ANY_MOD,     "\033[1~",       0,   +1},
	{ XK_KP_Up,         XK_ANY_MOD,     "\033Ox",       +1,    0},
	{ XK_KP_Up,         XK_ANY_MOD,     "\033[A",        0,   -1},
	{ XK_KP_Up,         XK_ANY_MOD,     "\033OA",        0,   +1},
	{ XK_KP_Down,       XK_ANY_MOD,     "\033Or",       +1,    0},
	{ XK_KP_Down,       XK_ANY_MOD,     "\033[B",        0,   -1},
	{ XK_KP_Down,       XK_ANY_MOD,     "\033OB",        0,   +1},
	{ XK_KP_Left,       XK_ANY_MOD,     "\033Ot",       +1,    0},
	{ XK_KP_Left,       XK_ANY_MOD,     "\033[D",        0,   -1},
	{ XK_KP_Left,       XK_ANY_MOD,     "\033OD",        0,   +1},
	{ XK_KP_Right,      XK_ANY_MOD,     "\033Ov",       +1,    0},
	{ XK_KP_Right,      XK_ANY_MOD,     "\033[C",        0,   -1},
	{ XK_KP_Right,      XK_ANY_MOD,     "\033OC",        0,   +1},
	{ XK_KP_Prior,      ShiftMask,      "\033[5;2~",     0,    0},
	{ XK_KP_Prior,      XK_ANY_MOD,     "\033[5~",       0,    0},
	{ XK_KP_Begin,      XK_ANY_MOD,     "\033[E",        0,    0},
	{ XK_KP_End,        ControlMask,    "\033[J",       -1,    0},
	{ XK_KP_End,        ControlMask,    "\033[1;5F",    +1,    0},
	{ XK_KP_End,        ShiftMask,      "\033[K",       -1,    0},
	{ XK_KP_End,        ShiftMask,      "\033[1;2F",    +1,    0},
	{ XK_KP_End,        XK_ANY_MOD,     "\033[4~",       0,    0},
	{ XK_KP_Next,       ShiftMask,      "\033[6;2~",     0,    0},
	{ XK_KP_Next,       XK_ANY_MOD,     "\033[6~",       0,    0},
	{ XK_KP_Insert,     ShiftMask,      "\033[2;2~",    +1,    0},
	{ XK_KP_Insert,     ShiftMask,      "\033[4l",      -1,    0},
	{ XK_KP_Insert,     ControlMask,    "\033[L",       -1,    0},
	{ XK_KP_Insert,     ControlMask,    "\033[2;5~",    +1,    0},
	{ XK_KP_Insert,     XK_ANY_MOD,     "\033[4h",      -1,    0},
	{ XK_KP_Insert,     XK_ANY_MOD,     "\033[2~",      +1,    0},
	{ XK_KP_Delete,     ControlMask,    "\033[M",       -1,    0},
	{ XK_KP_Delete,     ControlMask,    "\033[3;5~",    +1,    0},
	{ XK_KP_Delete,     ShiftMask,      "\033[2K",      -1,    0},
	{ XK_KP_Delete,     ShiftMask,      "\033[3;2~",    +1,    0},
	#if DELKEY_PATCH
	{ XK_KP_Delete,     XK_ANY_MOD,     "\033[3~",      -1,    0},
	#else
	{ XK_KP_Delete,     XK_ANY_MOD,     "\033[P",       -1,    0},
	#endif // DELKEY_PATCH
	{ XK_KP_Delete,     XK_ANY_MOD,     "\033[3~",      +1,    0},
	{ XK_KP_Multiply,   XK_ANY_MOD,     "\033Oj",       +2,    0},
	{ XK_KP_Add,        XK_ANY_MOD,     "\033Ok",       +2,    0},
	{ XK_KP_Enter,      XK_ANY_MOD,     "\033OM",       +2,    0},
	{ XK_KP_Enter,      XK_ANY_MOD,     "\r",           -1,    0},
	{ XK_KP_Subtract,   XK_ANY_MOD,     "\033Om",       +2,    0},
	{ XK_KP_Decimal,    XK_ANY_MOD,     "\033On",       +2,    0},
	{ XK_KP_Divide,     XK_ANY_MOD,     "\033Oo",       +2,    0},
	{ XK_KP_0,          XK_ANY_MOD,     "\033Op",       +2,    0},
	{ XK_KP_1,          XK_ANY_MOD,     "\033Oq",       +2,    0},
	{ XK_KP_2,          XK_ANY_MOD,     "\033Or",       +2,    0},
	{ XK_KP_3,          XK_ANY_MOD,     "\033Os",       +2,    0},
	{ XK_KP_4,          XK_ANY_MOD,     "\033Ot",       +2,    0},
	{ XK_KP_5,          XK_ANY_MOD,     "\033Ou",       +2,    0},
	{ XK_KP_6,          XK_ANY_MOD,     "\033Ov",       +2,    0},
	{ XK_KP_7,          XK_ANY_MOD,     "\033Ow",       +2,    0},
	{ XK_KP_8,          XK_ANY_MOD,     "\033Ox",       +2,    0},
	{ XK_KP_9,          XK_ANY_MOD,     "\033Oy",       +2,    0},
	{ XK_Up,            ShiftMask,      "\033[1;2A",     0,    0},
	{ XK_Up,            Mod1Mask,       "\033[1;3A",     0,    0},
	{ XK_Up,         ShiftMask|Mod1Mask,"\033[1;4A",     0,    0},
	{ XK_Up,            ControlMask,    "\033[1;5A",     0,    0},
	{ XK_Up,      ShiftMask|ControlMask,"\033[1;6A",     0,    0},
	{ XK_Up,       ControlMask|Mod1Mask,"\033[1;7A",     0,    0},
	{ XK_Up,ShiftMask|ControlMask|Mod1Mask,"\033[1;8A",  0,    0},
	{ XK_Up,            XK_ANY_MOD,     "\033[A",        0,   -1},
	{ XK_Up,            XK_ANY_MOD,     "\033OA",        0,   +1},
	{ XK_Down,          ShiftMask,      "\033[1;2B",     0,    0},
	{ XK_Down,          Mod1Mask,       "\033[1;3B",     0,    0},
	{ XK_Down,       ShiftMask|Mod1Mask,"\033[1;4B",     0,    0},
	{ XK_Down,          ControlMask,    "\033[1;5B",     0,    0},
	{ XK_Down,    ShiftMask|ControlMask,"\033[1;6B",     0,    0},
	{ XK_Down,     ControlMask|Mod1Mask,"\033[1;7B",     0,    0},
	{ XK_Down,ShiftMask|ControlMask|Mod1Mask,"\033[1;8B",0,    0},
	{ XK_Down,          XK_ANY_MOD,     "\033[B",        0,   -1},
	{ XK_Down,          XK_ANY_MOD,     "\033OB",        0,   +1},
	{ XK_Left,          ShiftMask,      "\033[1;2D",     0,    0},
	{ XK_Left,          Mod1Mask,       "\033[1;3D",     0,    0},
	{ XK_Left,       ShiftMask|Mod1Mask,"\033[1;4D",     0,    0},
	{ XK_Left,          ControlMask,    "\033[1;5D",     0,    0},
	{ XK_Left,    ShiftMask|ControlMask,"\033[1;6D",     0,    0},
	{ XK_Left,     ControlMask|Mod1Mask,"\033[1;7D",     0,    0},
	{ XK_Left,ShiftMask|ControlMask|Mod1Mask,"\033[1;8D",0,    0},
	{ XK_Left,          XK_ANY_MOD,     "\033[D",        0,   -1},
	{ XK_Left,          XK_ANY_MOD,     "\033OD",        0,   +1},
	{ XK_Right,         ShiftMask,      "\033[1;2C",     0,    0},
	{ XK_Right,         Mod1Mask,       "\033[1;3C",     0,    0},
	{ XK_Right,      ShiftMask|Mod1Mask,"\033[1;4C",     0,    0},
	{ XK_Right,         ControlMask,    "\033[1;5C",     0,    0},
	{ XK_Right,   ShiftMask|ControlMask,"\033[1;6C",     0,    0},
	{ XK_Right,    ControlMask|Mod1Mask,"\033[1;7C",     0,    0},
	{ XK_Right,ShiftMask|ControlMask|Mod1Mask,"\033[1;8C",0,   0},
	{ XK_Right,         XK_ANY_MOD,     "\033[C",        0,   -1},
	{ XK_Right,         XK_ANY_MOD,     "\033OC",        0,   +1},
	{ XK_ISO_Left_Tab,  ShiftMask,      "\033[Z",        0,    0},
	{ XK_Return,        Mod1Mask,       "\033\r",        0,    0},
	{ XK_Return,        XK_ANY_MOD,     "\r",            0,    0},
	{ XK_Insert,        ShiftMask,      "\033[4l",      -1,    0},
	{ XK_Insert,        ShiftMask,      "\033[2;2~",    +1,    0},
	{ XK_Insert,        ControlMask,    "\033[L",       -1,    0},
	{ XK_Insert,        ControlMask,    "\033[2;5~",    +1,    0},
	{ XK_Insert,        XK_ANY_MOD,     "\033[4h",      -1,    0},
	{ XK_Insert,        XK_ANY_MOD,     "\033[2~",      +1,    0},
	{ XK_Delete,        ControlMask,    "\033[M",       -1,    0},
	{ XK_Delete,        ControlMask,    "\033[3;5~",    +1,    0},
	{ XK_Delete,        ShiftMask,      "\033[2K",      -1,    0},
	{ XK_Delete,        ShiftMask,      "\033[3;2~",    +1,    0},
	#if DELKEY_PATCH
	{ XK_Delete,        XK_ANY_MOD,     "\033[3~",      -1,    0},
	#else
	{ XK_Delete,        XK_ANY_MOD,     "\033[P",       -1,    0},
	#endif // DELKEY_PATCH
	{ XK_Delete,        XK_ANY_MOD,     "\033[3~",      +1,    0},
	{ XK_BackSpace,     XK_NO_MOD,      "\177",          0,    0},
	{ XK_BackSpace,     Mod1Mask,       "\033\177",      0,    0},
	{ XK_Home,          ShiftMask,      "\033[2J",       0,   -1},
	{ XK_Home,          ShiftMask,      "\033[1;2H",     0,   +1},
	{ XK_Home,          XK_ANY_MOD,     "\033[H",        0,   -1},
	{ XK_Home,          XK_ANY_MOD,     "\033[1~",       0,   +1},
	{ XK_End,           ControlMask,    "\033[J",       -1,    0},
	{ XK_End,           ControlMask,    "\033[1;5F",    +1,    0},
	{ XK_End,           ShiftMask,      "\033[K",       -1,    0},
	{ XK_End,           ShiftMask,      "\033[1;2F",    +1,    0},
	{ XK_End,           XK_ANY_MOD,     "\033[4~",       0,    0},
	{ XK_Prior,         ControlMask,    "\033[5;5~",     0,    0},
	{ XK_Prior,         ShiftMask,      "\033[5;2~",     0,    0},
	{ XK_Prior,         XK_ANY_MOD,     "\033[5~",       0,    0},
	{ XK_Next,          ControlMask,    "\033[6;5~",     0,    0},
	{ XK_Next,          ShiftMask,      "\033[6;2~",     0,    0},
	{ XK_Next,          XK_ANY_MOD,     "\033[6~",       0,    0},
	{ XK_F1,            XK_NO_MOD,      "\033OP" ,       0,    0},
	{ XK_F1, /* F13 */  ShiftMask,      "\033[1;2P",     0,    0},
	{ XK_F1, /* F25 */  ControlMask,    "\033[1;5P",     0,    0},
	{ XK_F1, /* F37 */  Mod4Mask,       "\033[1;6P",     0,    0},
	{ XK_F1, /* F49 */  Mod1Mask,       "\033[1;3P",     0,    0},
	{ XK_F1, /* F61 */  Mod3Mask,       "\033[1;4P",     0,    0},
	{ XK_F2,            XK_NO_MOD,      "\033OQ" ,       0,    0},
	{ XK_F2, /* F14 */  ShiftMask,      "\033[1;2Q",     0,    0},
	{ XK_F2, /* F26 */  ControlMask,    "\033[1;5Q",     0,    0},
	{ XK_F2, /* F38 */  Mod4Mask,       "\033[1;6Q",     0,    0},
	{ XK_F2, /* F50 */  Mod1Mask,       "\033[1;3Q",     0,    0},
	{ XK_F2, /* F62 */  Mod3Mask,       "\033[1;4Q",     0,    0},
	{ XK_F3,            XK_NO_MOD,      "\033OR" ,       0,    0},
	{ XK_F3, /* F15 */  ShiftMask,      "\033[1;2R",     0,    0},
	{ XK_F3, /* F27 */  ControlMask,    "\033[1;5R",     0,    0},
	{ XK_F3, /* F39 */  Mod4Mask,       "\033[1;6R",     0,    0},
	{ XK_F3, /* F51 */  Mod1Mask,       "\033[1;3R",     0,    0},
	{ XK_F3, /* F63 */  Mod3Mask,       "\033[1;4R",     0,    0},
	{ XK_F4,            XK_NO_MOD,      "\033OS" ,       0,    0},
	{ XK_F4, /* F16 */  ShiftMask,      "\033[1;2S",     0,    0},
	{ XK_F4, /* F28 */  ControlMask,    "\033[1;5S",     0,    0},
	{ XK_F4, /* F40 */  Mod4Mask,       "\033[1;6S",     0,    0},
	{ XK_F4, /* F52 */  Mod1Mask,       "\033[1;3S",     0,    0},
	{ XK_F5,            XK_NO_MOD,      "\033[15~",      0,    0},
	{ XK_F5, /* F17 */  ShiftMask,      "\033[15;2~",    0,    0},
	{ XK_F5, /* F29 */  ControlMask,    "\033[15;5~",    0,    0},
	{ XK_F5, /* F41 */  Mod4Mask,       "\033[15;6~",    0,    0},
	{ XK_F5, /* F53 */  Mod1Mask,       "\033[15;3~",    0,    0},
	{ XK_F6,            XK_NO_MOD,      "\033[17~",      0,    0},
	{ XK_F6, /* F18 */  ShiftMask,      "\033[17;2~",    0,    0},
	{ XK_F6, /* F30 */  ControlMask,    "\033[17;5~",    0,    0},
	{ XK_F6, /* F42 */  Mod4Mask,       "\033[17;6~",    0,    0},
	{ XK_F6, /* F54 */  Mod1Mask,       "\033[17;3~",    0,    0},
	{ XK_F7,            XK_NO_MOD,      "\033[18~",      0,    0},
	{ XK_F7, /* F19 */  ShiftMask,      "\033[18;2~",    0,    0},
	{ XK_F7, /* F31 */  ControlMask,    "\033[18;5~",    0,    0},
	{ XK_F7, /* F43 */  Mod4Mask,       "\033[18;6~",    0,    0},
	{ XK_F7, /* F55 */  Mod1Mask,       "\033[18;3~",    0,    0},
	{ XK_F8,            XK_NO_MOD,      "\033[19~",      0,    0},
	{ XK_F8, /* F20 */  ShiftMask,      "\033[19;2~",    0,    0},
	{ XK_F8, /* F32 */  ControlMask,    "\033[19;5~",    0,    0},
	{ XK_F8, /* F44 */  Mod4Mask,       "\033[19;6~",    0,    0},
	{ XK_F8, /* F56 */  Mod1Mask,       "\033[19;3~",    0,    0},
	{ XK_F9,            XK_NO_MOD,      "\033[20~",      0,    0},
	{ XK_F9, /* F21 */  ShiftMask,      "\033[20;2~",    0,    0},
	{ XK_F9, /* F33 */  ControlMask,    "\033[20;5~",    0,    0},
	{ XK_F9, /* F45 */  Mod4Mask,       "\033[20;6~",    0,    0},
	{ XK_F9, /* F57 */  Mod1Mask,       "\033[20;3~",    0,    0},
	{ XK_F10,           XK_NO_MOD,      "\033[21~",      0,    0},
	{ XK_F10, /* F22 */ ShiftMask,      "\033[21;2~",    0,    0},
	{ XK_F10, /* F34 */ ControlMask,    "\033[21;5~",    0,    0},
	{ XK_F10, /* F46 */ Mod4Mask,       "\033[21;6~",    0,    0},
	{ XK_F10, /* F58 */ Mod1Mask,       "\033[21;3~",    0,    0},
	{ XK_F11,           XK_NO_MOD,      "\033[23~",      0,    0},
	{ XK_F11, /* F23 */ ShiftMask,      "\033[23;2~",    0,    0},
	{ XK_F11, /* F35 */ ControlMask,    "\033[23;5~",    0,    0},
	{ XK_F11, /* F47 */ Mod4Mask,       "\033[23;6~",    0,    0},
	{ XK_F11, /* F59 */ Mod1Mask,       "\033[23;3~",    0,    0},
	{ XK_F12,           XK_NO_MOD,      "\033[24~",      0,    0},
	{ XK_F12, /* F24 */ ShiftMask,      "\033[24;2~",    0,    0},
	{ XK_F12, /* F36 */ ControlMask,    "\033[24;5~",    0,    0},
	{ XK_F12, /* F48 */ Mod4Mask,       "\033[24;6~",    0,    0},
	{ XK_F12, /* F60 */ Mod1Mask,       "\033[24;3~",    0,    0},
	{ XK_F13,           XK_NO_MOD,      "\033[1;2P",     0,    0},
	{ XK_F14,           XK_NO_MOD,      "\033[1;2Q",     0,    0},
	{ XK_F15,           XK_NO_MOD,      "\033[1;2R",     0,    0},
	{ XK_F16,           XK_NO_MOD,      "\033[1;2S",     0,    0},
	{ XK_F17,           XK_NO_MOD,      "\033[15;2~",    0,    0},
	{ XK_F18,           XK_NO_MOD,      "\033[17;2~",    0,    0},
	{ XK_F19,           XK_NO_MOD,      "\033[18;2~",    0,    0},
	{ XK_F20,           XK_NO_MOD,      "\033[19;2~",    0,    0},
	{ XK_F21,           XK_NO_MOD,      "\033[20;2~",    0,    0},
	{ XK_F22,           XK_NO_MOD,      "\033[21;2~",    0,    0},
	{ XK_F23,           XK_NO_MOD,      "\033[23;2~",    0,    0},
	{ XK_F24,           XK_NO_MOD,      "\033[24;2~",    0,    0},
	{ XK_F25,           XK_NO_MOD,      "\033[1;5P",     0,    0},
	{ XK_F26,           XK_NO_MOD,      "\033[1;5Q",     0,    0},
	{ XK_F27,           XK_NO_MOD,      "\033[1;5R",     0,    0},
	{ XK_F28,           XK_NO_MOD,      "\033[1;5S",     0,    0},
	{ XK_F29,           XK_NO_MOD,      "\033[15;5~",    0,    0},
	{ XK_F30,           XK_NO_MOD,      "\033[17;5~",    0,    0},
	{ XK_F31,           XK_NO_MOD,      "\033[18;5~",    0,    0},
	{ XK_F32,           XK_NO_MOD,      "\033[19;5~",    0,    0},
	{ XK_F33,           XK_NO_MOD,      "\033[20;5~",    0,    0},
	{ XK_F34,           XK_NO_MOD,      "\033[21;5~",    0,    0},
	{ XK_F35,           XK_NO_MOD,      "\033[23;5~",    0,    0},
};
#endif // FIXKEYBOARDINPUT_PATCH

/*
 * Selection types' masks.
 * Use the same masks as usual.
 * Button1Mask is always unset, to make masks match between ButtonPress.
 * ButtonRelease and MotionNotify.
 * If no match is found, regular selection is used.
 */
static uint selmasks[] = {
	[SEL_RECTANGULAR] = Mod1Mask,
};

/*
 * Printable characters in ASCII, used to estimate the advance width
 * of single wide characters.
 */
static char ascii_printable[] =
	" !\"#$%&'()*+,-./0123456789:;<=>?"
	"@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
	"`abcdefghijklmnopqrstuvwxyz{|}~";

#if RIGHTCLICKTOPLUMB_PATCH
/*
 * plumb_cmd is run on mouse button 3 click, with argument set to
 * current selection and with cwd set to the cwd of the active shell
 */
static char *plumb_cmd = "plumb";
#endif // RIGHTCLICKTOPLUMB_PATCH

#if UNDERCURL_PATCH
/**
 * Undercurl style. Set UNDERCURL_STYLE to one of the available styles.
 *
 * Curly: Dunno how to draw it *shrug*
 *  _   _   _   _
 * ( ) ( ) ( ) ( )
 *	 (_) (_) (_) (_)
 *
 * Spiky:
 * /\  /\   /\	/\
 *   \/  \/	  \/
 *
 * Capped:
 *	_     _     _
 * / \   / \   / \
 *    \_/   \_/
 */
// Available styles
#define UNDERCURL_CURLY 0
#define UNDERCURL_SPIKY 1
#define UNDERCURL_CAPPED 2
// Active style
#define UNDERCURL_STYLE UNDERCURL_SPIKY
#endif // UNDERCURL_PATCH
