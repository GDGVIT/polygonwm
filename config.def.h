/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>
/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 7;        /* snap pixel */
static const unsigned int gappx     = 5;        /* gap pixel */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "DejaVu Sans Mono:size=9" };
static const char col_yorange[]     = "#ffe27a";
static const char col_orange[]      = "#ff4500";
static const char col_gray[]        = "#223322";
static const char col_white[]       = "#ffffff";

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
	{ "Firefox",  NULL,       NULL,       1 << 8,            0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",         spiral },    /* first entry is default */
	{ "><>",      NULL },
	{ "H",        honeycomb }, /* be sure to reflect chages in dwm.c in case of modifications */
	{ "D",        dewdrop },
	{ "M",        mountain },
	{ "N",        nonagon },
	{ "R",        roundbrilliant },
	{ "O",        planet },
	{ "B",        butterfly },
	{ "E",        emerald },
	{ NULL,       NULL },
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
static const char *dmenucmd[] = { "dmenu_run",  NULL }; /* dmenu is an application launcher */

static Key keys[] = {
	/* modifier                     key                       function        argument */
	{ MODKEY,                       XK_p,                     spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_b,                     togglebar,      {0} },
	{ MODKEY,                       XK_Right,                 focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Left,                  focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,                     incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,                     incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_j,                     setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_k,                     setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return,                zoom,           {0} },
	{ MODKEY,                       XK_Tab,                   view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,                     killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_s,                     setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,                     setlayout,      {.v = &layouts[1]} },
//	{ MODKEY|ShiftMask,             XK_h,                     setlayout,      {.v = &layouts[2]} },
//	{ MODKEY|ShiftMask,             XK_d,                     setlayout,      {.v = &layouts[3]} },
//	{ MODKEY|ShiftMask,             XK_m,                     setlayout,      {.v = &layouts[4]} },
//	{ MODKEY|ShiftMask,             XK_n,                     setlayout,      {.v = &layouts[5]} },
//	{ MODKEY|ShiftMask,             XK_r,                     setlayout,      {.v = &layouts[6]} },
//	{ MODKEY|ShiftMask,             XK_p,                     setlayout,      {.v = &layouts[7]} },
//	{ MODKEY|ShiftMask,             XK_b,                     setlayout,      {.v = &layouts[8]} },
//	{ MODKEY|ShiftMask,             XK_e,                     setlayout,      {.v = &layouts[9]} },
	{ MODKEY,                       XK_space,                 setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,                 togglefloating, {0} },
	{ MODKEY,                       XK_f,      				  togglefullscr,  {0} },
	{ MODKEY,                       XK_0,                     view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                     tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,                 focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,                focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,                 tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,                tagmon,         {.i = +1 } },
	{ MODKEY|ControlMask,           XK_comma,                 cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period,                cyclelayout,    {.i = +1 } },
	TAGKEYS(                        XK_1,                     			   	  0)			  
	TAGKEYS(                        XK_2,						  		   	  1)
	TAGKEYS(                        XK_3,                      				  2)
	TAGKEYS(                        XK_4,		                              3)
	TAGKEYS(                        XK_5,      		                		  4)
	TAGKEYS(                        XK_6,          		           			  5)
	TAGKEYS(                        XK_7,           	          			  6)
	TAGKEYS(                        XK_8,		              	        	  7)
	TAGKEYS(                        XK_9,       			        	      8)
	{ MODKEY|ShiftMask,             XK_BackSpace,      		   quit,          {0} }
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

