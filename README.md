<img style="vertical-align: middle;" src="https://codeberg.org/SOrg/RepoContent/raw/branch/content/svgs/DogGTKQT-Whatever.svg" width="120" height="120" align="left">

# Dog (GTK)
GTK4 + Libadwaita test, with a Dog which likes the GPL-3.0 license,
only Flatpak is officialy supported.

[Website](https://sorg.codeberg.page) ·
[Issue Tracker](https://codeberg.org/SOrg/DogGTK/issues) ·
[Install/Create Bundle](#install-create-bundle) ·
[Funny Dog (Bruno)](https://codeberg.org/SOrg/DogGTK/raw/branch/main/src/images/bjrunoada.jpg)

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
flatpak-builder --repo=repo --force-clean build-dir page.codeberg.SOrg.DogGTK.json
```

4. If the command finishes successfully, now you have 2 options:
* 4a. Install Directly: 
```
flatpak-builder --user --install --force-clean build-dir page.codeberg.SOrg.DogGTK.json
```

* 4b. Build Bundle (Preferred): Run: 
```
flatpak build-bundle repo page.codeberg.SOrg.DogGTK.flatpak page.codeberg.SOrg.DogGTK
``` 
This will create a bundle (.flatpak). Read more about single-file bundles [here](https://docs.flatpak.org/en/latest/single-file-bundles.html).

## Credits
[Google](https://about.google) - [Noto (& Color) Emoji](https://github.com/googlefonts/noto-emoji)\
[Bilal Elmoussaoui](https://belmoussaoui.com) - [Icon Library app](https://flathub.org/apps/org.gnome.design.IconLibrary) (used for repo avatar/icon)\
[Maximiliano Sandoval](https://gitlab.gnome.org/msandova) - [Emblem app](https://flathub.org/apps/org.gnome.design.Emblem) (used for background gradient of repo avatar/icon)\