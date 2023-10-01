<div align="center">
  <img src="https://codeberg.org/sungsphinx/Dog/raw/branch/main/data/icons/hicolor/scalable/apps/page.codeberg.sungsphinx.DogGTK.svg" width="120">
  <h1 align="center">Dog (GTK)</h1>
  <p align="center">GTK4 + LibAdwaita test. With a Dog which likes the GPL-3.0 license.</p>
</div>

<br/>

<div align="center">
  <a href="https://codeberg.org/sungsphinx/DogGTK/src/branch/main/COPYING" title="License: GPL v3">
    <img src="https://img.shields.io/badge/License-GPL--3.0-blue.svg">
  </a>
  <br>
  <!--<a href="https://stopthemingmy.app" title="Please do not theme this app">
    <img src="https://stopthemingmy.app/badge.svg">
  </a>-->

  <hr />

  <a href="https://sungsphinx.codeberg.page">Website</a> ·
  <a href="https://codeberg.org/sungsphinx/RepoIssues/issues">Issue Tracker (All Projects)</a> · 
  <a href="https://codeberg.org/sungsphinx/RepoIssues/issues?labels=150453">Issue Tracker (This Project)</a> · 
  <a href="https://codeberg.org/sungsphinx/DogGTK#install-create-bundle">Install/Create Bundle</a> · 
  <a href="https://codeberg.org/sungsphinx/DogGTK/raw/branch/main/src/images/bjrunoada.jpg">Funny Dog (Bruno)</a>
</div>

<br/>

## Clone Repo?
1. Make sure git is installed.
2. Run ```git clone https://codeberg.org/sungsphinx/DogGTK.git``` in the directory you want to clone this repo to.

## Install/Create Bundle

1. Install Flatpak (if it isn't already, with Flathub available) and flatpak-builder.

2. Download the ```page.codeberg.sungsphinx.DogGTK.json``` file and make a folder to put it in.

3. Open a terminal in that folder and run:
```
flatpak-builder build-dir page.codeberg.sungsphinx.DogGTK.json
```

4. If the command finishes successfully, now you have 2 options:
* 4a. Install Directly: 
```
flatpak-builder --user --install --force-clean build-dir page.codeberg.sungsphinx.DogGTK.json
```

* 4b. Build Bundle (Preferred): First, run: 
```
flatpak-builder --repo=repo --force-clean build-dir page.codeberg.sungsphinx.DogGTK.json
```
This will create a ```build-dir``` folder and create a repo. Next, run 
```
flatpak build-bundle repo page.codeberg.sungsphinx.DogGTK.flatpak page.codeberg.sungsphinx.DogGTK
``` 
This will create a bundle (.flatpak). Read more about single-file bundles [here](https://docs.flatpak.org/en/latest/single-file-bundles.html).

## Credits
[Google](https://about.google) - [Noto (& Color) Emoji](https://github.com/googlefonts/noto-emoji)\
[Bilal Elmoussaoui](https://belmoussaoui.com) - [Icon Library app](https://flathub.org/apps/org.gnome.design.IconLibrary) (used for repo avatar/icon)\
[Maximiliano Sandoval](https://gitlab.gnome.org/msandova) - [Emblem app](https://flathub.org/apps/org.gnome.design.Emblem) (used for background gradient of repo avatar/icon)