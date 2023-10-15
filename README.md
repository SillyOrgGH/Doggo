<div align="center">
  <img src="https://codeberg.org/SOrg/RepoContent/raw/branch/content/svgs/DogGTKQT-Whatever.svg" width="120">
  <h1 align="center">Dog (GTK)</h1>
  <p align="center">GTK4 + LibAdwaita test. With a Dog which likes the GPL-3.0 license.</p>
</div>

<br/>

<div align="center">
  <a href="https://codeberg.org/SOrg/DogGTK/src/branch/main/COPYING" title="License: GPL v3">
    <img src="https://img.shields.io/badge/License-GPL--3.0-blue.svg?style=for-the-badge">
  </a>
  <a href="https://codeberg.org/SOrg/DogGTK" title="Codeberg Repo">
    <img src="https://img.shields.io/badge/Codeberg-2185D0?style=for-the-badge&logo=Codeberg&logoColor=white" alt="Codeberg Repo">
  </a>
  <a href="https://github.com/SOrg-GitHub/DogGTK" title="GitHub Repo (Mirror)">
    <img src="https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white" alt="GitHub Repo (Mirror)">
  </a>
  <a href="#install-create-bundle" title="Flatpak (Linux)">
    <img src="https://img.shields.io/static/v1?style=for-the-badge&message=Flatpak&color=4A90D9&logo=Flatpak&logoColor=FFFFFF&label=Build%20A" alt="GitHub Repo (Mirror)">
  </a>
  <br>
  <!--<a href="https://stopthemingmy.app" title="Please do not theme this app">
    <img src="https://stopthemingmy.app/badge.svg">
  </a>-->

  <hr />

  <a href="https://sorg.codeberg.page">Website</a> ·
  <a href="https://codeberg.org/SOrg/DogGTK/issues">Issue Tracker</a> · 
  <a href="#install-create-bundle">Install/Create Bundle</a> · 
  <a href="https://codeberg.org/SOrg/DogGTK/raw/branch/main/src/images/bjrunoada.jpg">Funny Dog (Bruno)</a>
</div>

<br/>

## Clone Repo?
1. Make sure git is installed.
2. Run ```git clone https://codeberg.org/SOrg/DogGTK.git``` in the directory you want to clone this repo to.

## Install/Create Bundle

1. Install Flatpak (if it isn't already, with the Flathub remote available) and flatpak-builder.

2. Download the ```page.codeberg.SOrg.DogGTK.json``` file and make a folder to put it in.

3. Open a terminal in that folder and run:
```
flatpak-builder build-dir page.codeberg.SOrg.DogGTK.json
```

4. If the command finishes successfully, now you have 2 options:
* 4a. Install Directly: 
```
flatpak-builder --user --install --force-clean build-dir page.codeberg.SOrg.DogGTK.json
```

* 4b. Build Bundle (Preferred): First, run: 
```
flatpak-builder --repo=repo --force-clean build-dir page.codeberg.SOrg.DogGTK.json
```
This will create a ```build-dir``` folder and create a repo. Next, run 
```
flatpak build-bundle repo page.codeberg.SOrg.DogGTK.flatpak page.codeberg.SOrg.DogGTK
``` 
This will create a bundle (.flatpak). Read more about single-file bundles [here](https://docs.flatpak.org/en/latest/single-file-bundles.html).

## Credits
[Google](https://about.google) - [Noto (& Color) Emoji](https://github.com/googlefonts/noto-emoji)\
[Bilal Elmoussaoui](https://belmoussaoui.com) - [Icon Library app](https://flathub.org/apps/org.gnome.design.IconLibrary) (used for repo avatar/icon)\
[Maximiliano Sandoval](https://gitlab.gnome.org/msandova) - [Emblem app](https://flathub.org/apps/org.gnome.design.Emblem) (used for background gradient of repo avatar/icon)\
[Bottles Devs](https://github.com/bottlesdevs) / [Codeberg Org](https://codeberg.org/bottlesdevs) - [README Base](https://github.com/bottlesdevs/Bottles/blob/main/README.md)