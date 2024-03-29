# R Packages

[Source](https://rstudio-education.github.io/hopr/packages2.html)

## intro

Many of R’s most useful functions do `not come preloaded` when you start R, but reside in packages that can be installed on top of R.

An `R package bundles together useful functions, help files, and data sets`.

> Base R
> You may hear R users (or me) refer to “base R.” What is base R? It is just the > collection of R functions that gets loaded every time you start R.

## Installing Packages

To `use an R package`, you must first install it on your computer and then load it in your current R session.

```text
install.packages("<package name>")
```

This will search for the specified package, hosted on the CRAN site. When R finds the package, it will download it into a libraries folder on your computer.

`R can access the package` here in future R sessions `without reinstalling it`.

### install multiple packages at once

`c` is R’s concatenate function, which will link packages names.

```R
install.packages(c("ggplot2", "reshape2", "dplyr"))
```

If this is your first time installing a package, R will prompt you to choose an online mirror of to install from.

If you want to download a newest package, try the Austria mirror first.

## Loading Packages

Installing a package doesn’t immediately place its functions at your fingertips. It just places them on your computer.

To use an R package, you next have to load it in your R session with the command:

```R
library(<package name>)
```
