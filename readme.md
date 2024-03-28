# ZSA's fork of QMK Firmware

[![Current Version](https://img.shields.io/github/tag/zsa/qmk_firmware.svg)](https://github.com/zsa/qmk_firmware/tags)
[![Build firmware](https://github.com/zsa/qmk_firmware/actions/workflows/build.yml/badge.svg)](https://github.com/zsa/qmk_firmware/actions/workflows/build.yml)
[![Unit Tests](https://github.com/zsa/qmk_firmware/actions/workflows/unit_test.yml/badge.svg)](https://github.com/zsa/qmk_firmware/actions/workflows/unit_test.yml)
[![GitHub contributors](https://img.shields.io/github/contributors/zsa/qmk_firmware.svg)](https://github.com/zsa/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/zsa/qmk_firmware.svg?style=social&label=Fork)](https://github.com/zsa/qmk_firmware/)

# Acas's QMK Config

This is my firmware config for the [Voyager](https://www.zsa.io/voyager), a split keyboard by ZSA with 52 keys. The number row goes unused, so my config is 40 keys (3x6+2).

My config uses a custom keyboard layout I call Vylet. It started out as a mod of [Wedlock](https://github.com/GGabi/wedlock) before evolving into its own layout. Vylet takes inspiration from [APTv3](https://github.com/Apsu/APT), [Workman](https://workmanlayout.org/), and [Magic Sturdy](https://github.com/Ikcelaks/keyboard_layouts/blob/main/magic_sturdy/magic_sturdy.md).

As I was creating and testing early versions of Vylet, I also took the time to create a keymap that fit my personal needs since I couldn't find anything that filled that niche for me. Maybe there's a similar keymap to this out there in the wild, I just never found it.

You can read more about Vylet, my keymap, and my thinking behind them [here](TODO). I also have it up on ZSA's website if you'd like to view it [there](https://configure.zsa.io/voyager/layouts/nPjjQ/latest). The only thing missing from there is my magic key; ZSA's QMK fork doesn't support that feature yet.

Anyway, this is what my layout/keymap currently looks like. Hope it can give you some inspiration in making your own!

<img src="img/magic_vylet_keymap_trans.svg" alt="acas's keymap layout graphical representation" width="100%" />

> Graphic made using [Keymap Drawer](/caksoylar/keymap-drawer). Color palette is [Catppuccin](https://github.com/catppuccin/catppuccin)'s Mocha flavor, I use it for everything I possibly can :)

---

This purpose of this fork is maintain a clean repo that only contains the keyboard code that we need, and as little else as possible.  This is to keep it lightweight, since we only need a couple of keyboards. This is the repo that the EZ Configurator will pull from.
## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [Docsify](https://docsify.js.org/) and hosted on [GitHub](/docs/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls), or by clicking the "Edit this page" link at the bottom of any page.


## Supported Keyboards

* [ErgoDox EZ](/keyboards/ergodox_ez/)
* [Planck EZ](/keyboards/planck/ez)
* [Moonlander Mark I](/keyboards/moonlander)
* [Voyager](keyboards/voyager)

## Building

To set up the local build environment to create the firmware image manually, head to the [Newbs guide from QMK](https://docs.qmk.fm/#/newbs).
And instead of using just `qmk setup`, you will want to run this instead:

```sh
qmk setup zsa/qmk_firmware -b firmware23
```

## Creating Firmware Based on a User-Configured Layout

1. To create or edit a layout, use [ZSA Oryx](https://configure.zsa.io/), a user-friendly keyboard configuration tool developed by ZSA.
2. If a layout is compiled, you should see a 'Download Source' link. If not, press 'Compile this layout,' and it should become available.
3. After downloading the archive, extract it. Inside, you'll find a folder named `yourlayoutname_source`. Keep the files within this folder and remove the rest.
4. Ensure that your environment is set up correctly by following the [QMK documentation on setting up your environment](https://docs.qmk.fm/#/newbs_getting_started?id=set-up-your-environment).
5. In a QMK firmware directory, run `make keyboard:yourlayoutname`. For example, to build firmware corresponding to the 'Lit Voyager' layout, run `make voyager:lit`.
6. Use any flashing tool to install the firmware on your keyboard.

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

# Update Process

1. Check out branch from ZSA's master branch:
    1. `git remote add zsa https://github.com/zsa/qmk_firmware.git`
    2. `git fetch --all`
    3. `git checkout -B branchname zsa/master`
    4. `git push -u zsa branchname`
2. Check for core changes:
    - [https://github.com/qmk/qmk_firmware/commits/master/quantum](https://github.com/qmk/qmk_firmware/commits/master/quantum)
    - [https://github.com/qmk/qmk_firmware/commits/master/tmk_core](https://github.com/qmk/qmk_firmware/commits/master/tmk_core)
    - [https://github.com/qmk/qmk_firmware/commits/master/util](https://github.com/qmk/qmk_firmware/commits/master/util)
    - [https://github.com/qmk/qmk_firmware/commits/master/drivers](https://github.com/qmk/qmk_firmware/commits/master/drivers)
    - [https://github.com/qmk/qmk_firmware/commits/master/lib](https://github.com/qmk/qmk_firmware/commits/master/lib)
    - These folders are the important ones for maintaining the repo and keeping it properly up to date. Most, but not all, changes on this list should be pulled into our repo.
4. `git merge (hash|tag)`
    - `git rm -rf docs users layouts .vscode` to remove the docs and user code that we don't want.
    - To remove all of the keyboard exept the ones we want:
      ```sh
      find ./keyboards -mindepth 1 -maxdepth 1 -type d -not -name ergodox_ez -not -name planck -not -name moonlander -not -name pytest -exec git rm -rf '{}' \;
      find ./keyboards/planck -mindepth 1 -maxdepth 1 -type d -not -name ez -not -name base -not -name glow -not -name keymaps -exec git rm -rf '{}' \;
      ```
    - To remove all of the keymaps from folder that we don't want:
      ```sh
      find ./keyboards/ -mindepth 3 -maxdepth 3 -type d -not -name default -not -name oryx -not -name webusb -not -name glow -not -name reactive -not -name shine -not -name keymaps -not -name halfmoon -exec git rm -rf '{}' \;
      ```
    - Restore necessary files/folders:
      ```sh
      git checkout HEAD -- keyboards/handwired/pytest
      git checkout HEAD -- layouts
      ```
    - Resolve merge conflicts, and commit.

4. Commit update
   * Include commit info in `[changelog.md](changelog.md)`
5. Open Pull request, and include information about the commit

## Strategy

To keep PRs small and easier to test, they should ideally be 1:1 with commits from QMK Firmware master. They should only group commits if/when it makes sense. Such as multiple commits for a specific feature (split RGB support, for instance)
