# setting R in vscode

> last updated: 2022/10/25

- [setting R in vscode](#setting-r-in-vscode)
  - [Source](#source)
  - [Getting Started](#getting-started)
    - [setting R bin in settings.json](#setting-r-bin-in-settingsjson)
    - [install languageservers in R](#install-languageservers-in-r)
    - [radian](#radian)
      - [install and run](#install-and-run)
    - [VSCorde-R-Debugger](#vscorde-r-debugger)
    - [httpgd](#httpgd)
  - [Running R code](#running-r-code)
  - [Using self-managed R terminals](#using-self-managed-r-terminals)
  - [Linting](#linting)
    - [install](#install)
    - [Usage](#usage)
  - [Workspace viewer](#workspace-viewer)
    - [Webpage viewer](#webpage-viewer)
      - [install](#install-1)

## Source

[R in vscode marketplace](https://code.visualstudio.com/docs/languages/r)
[R in vscode with linux install full guide](https://github.com/REditorSupport/vscode-R/wiki/Installation:-Linux)

## Getting Started

The `R extension` for Visual Studio Code supports extended syntax highlighting, code completion, linting, formatting, interacting with R terminals, viewing data, plots, workspace variables, help pages, managing packages and working with `R Markdown` documents.

### setting R bin in settings.json

```json
"r.rterm.linux": "/usr/bin/R"
```

> If your R installation is from [CRAN](https://cran.r-project.org/mirrors.html), then the default settings should work out of the box. Otherwise, you may have to change **r.rterm.linux** to the path to your R executable, which will be executed on command **Create R Terminal**.

### install languageservers in R

A few dependencies are required beforehand:

```cmd
# On Debian, Ubuntu, etc.
apt install --assume-yes --no-install-recommends build-essential libcurl4-openssl-dev libssl-dev libxml2-dev r-base

# On Fedora, Centos, etc.
dnf install --assumeyes --setopt=install_weak_deps=False @development-tools libcurl-devel libxml2-devel openssl-devel R

# On Alpine
apk add --no-cache curl-dev g++ gcc libxml2-dev linux-headers make R R-dev
```

In R file run following to install `languageserver`

```R
install.packages("languageserver")
```

if you have install [issues](https://stackoverflow.com/questions/34201742/installation-of-packages-stringr-and-stringi-had-non-zero-exit-status) about languageserver, try following in terminal

```R
sudo -i R
```

and

```R
install.packages('languageserver')
```

### radian

radian is an alternative console for the R program with multiline editing and rich syntax highlight.

#### install and run

```cmd
# install released version in gobal
pip3 install -U radian
# to run radian
raidan
```

using `which radian` to see where your `radian` executable is located.

`Setting` following in VS Code `settings.json`  to properly `use radian as the default terminal`. If your `radian` is installed `only for user`:

```json
{
  "r.bracketedPaste": true,
  "r.rterm.linux": "/home/user/.local/bin/radian"
}
```

### VSCorde-R-Debugger

`VSCode-R-Debugger` is a VS Code extension that implements R debugging capabilities. It depends on `vscDebugger`.

1. Install VSCode-R-Debugger extension in VS Code.
2. Install vscDebugger package via

```R
remotes::install_github("ManuelHentschel/vscDebugger")
```

### httpgd

`httpgd` is an R package to `provide` a graphics device that asynchronously serves `SVG graphics via HTTP and WebSockets`. It enables the plot viewer based on httpgd in VS Code.

1. Install `httpgd` from CRAN

```R
install.packages("httpgd")
```

2. Enable `r.plot.useHttpgd` in VS Code settings.

## Running R code

Running R code is simply `sending code to the R terminal`. Before running R code, you could `create an R terminal` via command R: Create R terminal in the `Command Palette` (type F1 to open).

Pressing `(Ctrl+Enter)` code will be sent to the active R terminal.

If you want to run an entire R file, open the file in the editor, and press `Ctrl+Shift+S` and the file will be sourced in the active R terminal.

## Using self-managed R terminals

Self-managed R terminals could be useful if one `needs one or more R sessions` to be preserved so that closing the VS Code window does not terminate the R sessions. On Linux and macOS, both **[screen](https://www.gnu.org/software/screen/)** and **[tmux](https://github.com/tmux/tmux/wiki)** could be used to preserve any number of R sessions or any other terminal programs in a customizable layout.

To make self-managed R sessions behave like those created by "R: Create R terminal", the following code should be added to `~/.Rprofile`:

```bash
if (interactive() && Sys.getenv("RSTUDIO") == "") {
  Sys.setenv(TERM_PROGRAM = "vscode")
  source(file.path(Sys.getenv(
    if (.Platform$OS.type == "windows") "USERPROFILE" else "HOME"
  ), ".vscode-R", "init.R"))
}
```

## Linting

Linting is a feature that `checks the code for warnings and potential errors`. R code linting is provided by **[lintr](https://github.com/r-lib/lintr)** package. You can customize it by choosing from the list of available linters via the configuration file.

### install

```R
install.packages("lintr")
```

### Usage

```R
# in a project:
lintr::use_lintr(type = "tidyverse")
usethis::use_github_action("lint-project")
lintr::lint_dir()

# in a package:
lintr::use_lintr(type = "tidyverse")
usethis::use_github_action("lint")
lintr::lint_package()
```

## Workspace viewer

The workspace viewer is located in the side bar in VS Code and contains the packages in use and global variables in the active R session. `Select the R icon in the Activity bar and the workspace viewer and help pages viewer will show up`.

It is a `convenient way to view the R workspace, preview existing R objects, find help topics, and read help pages interactively`.

Besides the workspace viewer, there is also a data viewer, a plot viewer, and a widget viewer. Read [Interactive viewers](https://github.com/REditorSupport/vscode-R/wiki/Interactive-viewers) for more details.

### Webpage viewer

interactive graphics created by [plotly](https://github.com/plotly/plotly.R)

#### install

```text
install.packages("plotly")
```
