/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>
/* appearance */
static const unsigned int borderpx  = 6;        /* border pixel of windows */
static const unsigned int snap      = 7;       /* snap pixel */
static const unsigned int cornerrad = 10;
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "DejaVu Sans Mono:size=9" };
static const char col_yorange[]     = "#ffe27a";
static const char col_orange[]      = "#ff4500";
static const char col_gray[]        = "#223322";
static const char col_white[]        = "#ffffff";
/*static const char col_black[]       = "#000000";
static const char col_orange[]      = "#ff4500";
static const char col_gray3[]       = "#cccccc";
static const char col_gray4[]       = "#ffffff";
*/
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray, col_yorange, col_yorange },
	[SchemeSel]  = { col_white, col_orange, col_orange  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Firefox",  NULL,       NULL,       9,            0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol       arrange function */
	{ "",           spiral },    /* first entry is default */
	{ "><>",        NULL },
	{ "_/^\\_",     mountain },
	{ "<^>",        petal },
	{ "<->",        honeycomb },
	/* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run",  NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *sLock[]  = { "slock", NULL };
static const char *backlitInc[]  = { "sudo", "brightnessctl", "set", "+2", NULL };
static const char *backlitDec[]  = { "sudo", "brightnessctl", "set", "2-", NULL };
static const char *volToggle[]  = { "pactl", "set-sink-mute", "0", "toggle", NULL };
static const char *volDown[]  = { "pactl", "set-sink-volume", "0", "-2%", NULL };
static const char *volUp[]  = { "pactl", "set-sink-volume", "0", "+1%", NULL };
static const char *audToggle[]  = { "cmus-remote", "-u", NULL };
static const char *audNext[]  = { "cmus-remote", "-n", NULL };
static const char *audPrev[]  = { "cmus-remote", "-r", NULL };
static const char *nnnSpawn[] = { "st", "nnn", NULL };
static const char *sudonnnSpawn[] = { "sudo", "st", "nnn", NULL };
static const char *alsamixer[] = { "st", "alsamixer", NULL };
static const char *cmusyo[] = { "st", "cmus", NULL };

static Key keys[] = {
	/* modifier                     key                       function        argument */
	{ MODKEY,                       XK_p,                     spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,                spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,                     togglebar,      {0} },
	{ MODKEY,                       XK_Right,                 focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Left,                  focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,                     incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_n,                  	  spawn,	      {.v = nnnSpawn } },
	{ MODKEY|ShiftMask,             XK_n,                  	  spawn,	      {.v = sudonnnSpawn } },
	{ MODKEY,                       XK_d,                     incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_j,                     setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_k,                     setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return,                zoom,           {0} },
	{ MODKEY,                       XK_Tab,                   view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,                     killclient,     {0} },
	{ MODKEY,                       XK_t,                     setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,                     setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,                     setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_v,                     setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_h,                     setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,                 setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,                 togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      				  togglefullscr,  {0} },
	{ MODKEY,                       XK_0,                     view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                     tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,                 focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,                focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_l,                     spawn,          {.v = sLock } },
	{ MODKEY|ShiftMask,             XK_comma,                 tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,                tagmon,         {.i = +1 } },
	{ 0,                            XF86XK_AudioRaiseVolume,  spawn,          {.v = volUp } },
	{ 0,                            XF86XK_AudioLowerVolume,  spawn,          {.v = volDown } },
	{ 0,                            XF86XK_AudioMute,         spawn,          {.v = volToggle } },
	{ 0,                            XF86XK_MonBrightnessUp,   spawn,          {.v = backlitInc } },
	{ 0,                            XF86XK_MonBrightnessDown, spawn,          {.v = backlitDec } },
	{ 0,                            XF86XK_AudioPlay,         spawn,          {.v = audToggle } },
	{ 0,                            XF86XK_AudioStop,         spawn,          {.v = audToggle } },
	{ 0,                            XF86XK_AudioNext,         spawn,          {.v = audNext } },
	{ 0,                            XF86XK_AudioPrev,         spawn,          {.v = audPrev } },
	{ 0,                            XF86XK_AudioPrev,         spawn,          {.v = audPrev } },
	{ MODKEY|ShiftMask,             XK_a,                     spawn,          {.v = alsamixer } },
	{ MODKEY|ShiftMask,             XK_F7,                    spawn,          {.v = cmusyo } },
	TAGKEYS(                        XK_1,                     			   	  0)			  
	TAGKEYS(                        XK_2,						  		   	  1)
	TAGKEYS(                        XK_3,                      				  2)
	TAGKEYS(                        XK_4,		                              3)
	TAGKEYS(                        XK_5,      		                		  4)
	TAGKEYS(                        XK_6,          		           			  5)
	TAGKEYS(                        XK_7,           	          			  6)
	TAGKEYS(                        XK_8,		              	        	  7)
	TAGKEYS(                        XK_9,       			        	      8)
	{ MODKEY|ShiftMask,             XK_BackSpace,      		   quit,          {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

