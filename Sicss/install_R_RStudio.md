# Install RStudio and R

[Hands-On Programming with R](https://rstudio-education.github.io/hopr/starting.html)

## In os

[install RStudio and R on os](https://cloud.r-project.org/)

### What are R and CRAN?

`R` is ‘GNU S’, a freely available language and environment for statistical computing and graphics which provides a wide variety of statistical and graphical techniques: linear and nonlinear modelling, statistical tests, time series analysis, classification, clustering, etc.

`CRAN` is a network of ftp and web servers around the world that store identical, up-to-date, versions of code and documentation for R.

### In ubuntu

Run these lines (if root, remove sudo) to tell Ubuntu about the R binaries at CRAN.

```cmd
# update indices
sudo apt update -qq
# install two helper packages we need
sudo apt install --no-install-recommends software-properties-common dirmngr
# add the signing key (by Michael Rutter) for these repos
# To verify key, run gpg --show-keys /etc/apt/trusted.gpg.d/cran_ubuntu_key.asc 
# Fingerprint: E298A3A825C0D65DFD57CBB651716619E084DAB9
wget -qO- https://cloud.r-project.org/bin/linux/ubuntu/marutter_pubkey.asc | sudo tee -a /etc/apt/trusted.gpg.d/cran_ubuntu_key.asc
# add the R 4.0 repo from CRAN -- adjust 'focal' to 'groovy' or 'bionic' as needed
sudo add-apt-repository "deb https://cloud.r-project.org/bin/linux/ubuntu $(lsb_release -cs)-cran40/"
```

Here we use lsb_release -cs to access which Ubuntu flavor you run: one of “jammy”, impish”, “focal”, “bionic”, …

```cmd
sudo apt install --no-install-recommends r-base
```

#### Get 5000+ CRAN Packages

```cmd
sudo add-apt-repository ppa:c2d4u.team/c2d4u4.0+
```

## In vscode

[R in vscode](https://code.visualstudio.com/docs/languages/r)

### intro

The `R extension` for Visual Studio Code supports extended syntax highlighting, code completion, linting, formatting, interacting with R terminals, viewing data, plots, workspace variables, help pages, managing packages and working with `R Markdown` documents.

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

// FIXME: fail to launch
`languageserver` is released on CRAN and can be easily installed by

```
install.packages("languageserver")
```
