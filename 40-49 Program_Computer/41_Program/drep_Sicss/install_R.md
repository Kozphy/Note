# Install R

> last updated: 2022/10/25

- [Install R](#install-r)
  - [Source](#source)
  - [What are R and CRAN?](#what-are-r-and-cran)
    - [In ubuntu](#in-ubuntu)
      - [Ubuntu Packages For R - Full Instructions](#ubuntu-packages-for-r---full-instructions)
      - [Get 5000+ CRAN Packages](#get-5000-cran-packages)
      - [Maintenance of R Packages](#maintenance-of-r-packages)

## Source

[Hands-On Programming with R](https://rstudio-education.github.io/hopr/starting.html)

[install RStudio and R on os](https://cloud.r-project.org/)

## What are R and CRAN?

`R` is ‘GNU S’, a freely available language and environment for statistical computing and graphics which provides a wide variety of statistical and graphical techniques: linear and nonlinear modelling, statistical tests, time series analysis, classification, clustering, etc.

`CRAN` is a network of `ftp and web servers` around the world that store identical, up-to-date, versions of code and documentation for R.

---

### In ubuntu

#### [Ubuntu Packages For R - Full Instructions](https://cloud.r-project.org/bin/linux/ubuntu/fullREADME.html)

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

Here we use `lsb_release -cs` to access which Ubuntu flavor you run: one of “jammy”, impish”, “focal”, “bionic”, …

```cmd
sudo apt install --no-install-recommends r-base
```

#### Get 5000+ CRAN Packages

```cmd
sudo add-apt-repository ppa:c2d4u.team/c2d4u4.0+
```

#### Maintenance of R Packages

The R packages part of the Ubuntu r-base and r-recommended packages are installed into the directory `/usr/lib/R/library`. These can be updated using apt-get with

```cmd
sudo apt-get update
sudo apt-get upgrade
```

The other r-cran-* packages shipped with Ubuntu are installed into the directory `/usr/lib/R/site-library`.

Installing R packages not provided with Ubuntu first requires tools to `compile the packages from source`. These tools are installed via the R development package with

```cmd
sudo apt-get install r-base-dev
```

This `pulls in the basic requirements for compiling R packages`.

R packages may then be installed by the local `user/admin` from the CRAN source packages, typically from inside R using the

```R
install.packages()
```

or using following  from a shell.

```cmd
R CMD INSTALL
```

from a shell. If you have proper write permissions in `/usr/local/lib/R/site-library/`, and you `have not set R_LIBS_USER manually`, they will be installed there.

---
