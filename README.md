<p align="center">
<a href="https://dscvit.com">
	<img src="https://user-images.githubusercontent.com/30529572/72455010-fb38d400-37e7-11ea-9c1e-8cdeb5f5906e.png" />
</a>
	<h2 align="center">  PolygonWM  </h2>
	<h4 align="center">  An experimental window manager made purely for aesthetic pursposes.  <h4>
</p>

---
<!---
[![DOCS](https://img.shields.io/badge/Documentation-see%20docs-green?style=flat-square&logo=appveyor)](INSERT_LINK_FOR_DOCS_HERE) 
  [![UI ](https://img.shields.io/badge/User%20Interface-Link%20to%20UI-orange?style=flat-square&logo=appveyor)](INSERT_UI_LINK_HERE)
-->

## What is it, and why?  

PolygonWM is the answer for the question "Can windows be non-rectangular?". It is forked from DWM version 6.2, and tries to adhere to the suckless philosophy. It isn't meant to be better than any other WMs and doesn't claim to be. It's meant to break conventions; to be different. PolygonWM contains the following additional DWM patches which might not be in it's original form:  
- [fullscreen](https://dwm.suckless.org/patches/fullscreen/)
- [cyclelayouts](https://dwm.suckless.org/patches/cyclelayouts/)
- [gaps](https://dwm.suckless.org/patches/gaps/)
- [centeredmaster](https://dwm.suckless.org/patches/centeredmaster/)
- [fibonacci](https://dwm.suckless.org/patches/fibonacci/)

## Functionalities
- [X]  All features of DWM(Multiple Workspaces, Bar, Window Tagging).
- [X]  Gaps
- [X]  Honeycomb Layout
- [X]  Dewdrop Layout
- [X]  Mountain Layout
- [X]  Nonagon Layout
- [X]  Round Brilliant Layout
- [X]  Planet Layout
- [X]  Butterfly Layout
- [X]  Emerald Layout

<br>


## Instructions to run

* Pre-requisites:
	-  Unix-like OS
	-  X11

* How to Install:   
  First, clone this repo and extract the compressed file, and then cd into the extracted directory.
```bash
$ make
$ make install PREFIX=YOURDESIREDLOCATION
```

* Setting Polygonwm as the default WM:

```bash
$ echo "exec polygonwm" >> ~/.xinitrc
```
Restart X for the changes to take effect.  
Note: Polygonwm automatically checks for other WMs in case another WM is already running.  
Note: Polygonwm is EXPERIMENTAL. It may break some apps. Do not use this WM as a daily driver.  

## Usage  

All settings/configurations and customizations are done throught the config..def.h file. After every change, the source has to be recompiled. The default keybindings can be viewed/modified from the config.def.h file, including those for the different layouts.

## Contributors

<table>
<tr align="center">

<td>

Govind K

<p align="center">
</p>
<p align="center">
<a href = "https://github.com/Roidujeu"><img src = "http://www.iconninja.com/files/241/825/211/round-collaboration-social-github-code-circle-network-icon.svg" width="36" height = "36"/></a>
</p>
</td>


<td>

Angad Sharma

<p align="center">
</p>
<p align="center">
<a href = "https://github.com/L04DB4L4NC3R/"><img src = "http://www.iconninja.com/files/241/825/211/round-collaboration-social-github-code-circle-network-icon.svg" width="36" height = "36"/></a>
</p>
</td>



</tr>
  </table>

<br>
<br>

<p align="center">
	Made with :heart: by <a href="https://dscvit.com">DSC VIT</a>
</p>

