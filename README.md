<!-- Definitions -->
[flathub]: https://flathub.org/apps/page.codeberg.SOrg.DogGTK
<!-- End Defenitions -->
<!--
> **Warning*
> <br/>**Doggo as of now is in maintenance mode.**
-->
[![Flathub](https://img.shields.io/flathub/v/page.codeberg.SOrg.DogGTK?logo=flathub&logoColor=white&label=Flathub)][flathub]
[![Flathub Installs](https://img.shields.io/flathub/downloads/page.codeberg.SOrg.DogGTK?logo=flathub&logoColor=white&label=Installs)][flathub]
[![Please do not theme this app](https://stopthemingmy.app/badge.svg)](https://stopthemingmy.app)
[![Please don't upload to GitHub](https://codeberg.org/SOrg/RepoContent/raw/branch/content/svgs/NoGitHubBadgeORIGINAL.svg)](https://nogithub.codeberg.page)
[![License: GPL-3.0-or-later](https://codeberg.org/SOrg/RepoContent/raw/branch/content/svgs/GPLv3OrLaterBadge.svg)](https://codeberg.org/SOrg/DogQt/src/branch/main/LICENSE)
[![Flatpak (Linux)](https://img.shields.io/static/v1?message=Flatpak&color=4A90D9&logo=Flatpak&logoColor=FFFFFF&label=Build%20A)](#install)

<img style="vertical-align: middle;" src="https://codeberg.org/SOrg/Doggo/raw/branch/main/data/icons/hicolor/scalable/apps/page.codeberg.SOrg.DogGTK.svg" width="120" height="120" align="left">

# Doggo
GTK4 + Libadwaita Actions &amp; AdwNavigationView demo, also kind of a game.</br>[Silly Org Website](https://sorg.codeberg.page) · [Issue Tracker](https://codeberg.org/SOrg/Doggo/issues) · [Install](#install) · [Credits](#credits) · [Funny Dog (Bruno)](https://codeberg.org/SOrg/Doggo/raw/branch/main/data/ui/images/bjrunoada.jpg)
</div>

## Screenshots
![Main Window](data/screenshots/screenshot-1.png) | ![Dog Is Friendly Page](data/screenshots/screenshot-2.png) | ![Dog Is Unfriendly Page](data/screenshots/screenshot-3.png)
-------------------------------------------- | -------------------------------------- | ----------------------------------------------

## Clone Repo?
1. Make sure git is installed.
2. Run ```git clone https://codeberg.org/SOrg/Doggo.git``` in the directory you want to clone this repo to.

## Install

> #### **Warning**
> Flatpak is the **only officially supported** way of distributing this app, **any issues by people which use a non-flatpak version will be closed.**

### Install (Stable Version via Flathub)

[![Download on Flathub](https://dl.flathub.org/assets/badges/flathub-badge-en.svg)](https://flathub.org/apps/page.codeberg.SOrg.DogGTK)

### Install (Development Version)

**1.** Install Flatpak (if it isn't installed already, **with [Flathub](https://flathub.org) and the [GNOME Nightly remote](https://wiki.gnome.org/Apps/Nightly)**) and flatpak-builder.

**2.** Make sure you have ```runtime/org.gnome.Platform/x86_64/master``` &amp; ```runtime/org.gnome.Sdk/x86_64/master``` installed, you can install the platform with:

```
flatpak install runtime/org.gnome.Platform/x86_64/master
```

And the SDK with:

```
flatpak install runtime/org.gnome.Platform/x86_64/master
```


**3.** Download the [Flatpak Manifest](build-aux/flatpak/page.codeberg.SOrg.DogGTK.Devel.json) and make a folder to put it in.
* Where is the original manifest? [[Jump]](#original-manifest-non-devel)

**4.** Open a terminal in that folder and choose one of the following to run:

* **4a.** Install Directly: 
```
flatpak-builder --install --force-clean build-dir page.codeberg.SOrg.DogGTK.Devel.json
```

* **4b.** Build Bundle: 

```
flatpak-builder --repo=repo --force-clean build-dir page.codeberg.SOrg.DogGTK.Devel.json
```

Then run:

```
flatpak build-bundle repo page.codeberg.SOrg.DogGTK.Devel.flatpak page.codeberg.SOrg.DogGTK.Devel
``` 
This will create a bundle (*.flatpak). Read more about single-file bundles [here](https://docs.flatpak.org/en/latest/single-file-bundles.html).

## Credits
[Google](https://about.google) - [Noto (& Color) Emoji](https://github.com/googlefonts/noto-emoji)\
[Bilal Elmoussaoui](https://belmoussaoui.com) - [Icon Library app](https://flathub.org/apps/org.gnome.design.IconLibrary) (used for repo avatar/icon)\
[Maximiliano Sandoval](https://gitlab.gnome.org/msandova) - [Emblem app](https://flathub.org/apps/org.gnome.design.Emblem) (used for background gradient of repo avatar/icon)\
[Libadwaita Demo](https://gitlab.gnome.org/GNOME/libadwaita/-/blob/main/demo) - [Debug Information/Troubleshooting for about window](https://gitlab.gnome.org/GNOME/libadwaita/-/blob/main/demo/adw-demo-debug-info.c)
