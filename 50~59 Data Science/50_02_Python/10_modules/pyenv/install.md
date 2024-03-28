# pyenv

## Source

[github](https://github.com/pyenv/pyenv#automatic-installer)

## How it works

**At a high level, pyenv intercepts Python commands using shim executables injected into your** `PATH`, determines which Python version has been specified by your application, and passes your commands along to the correct Python installation.

## Understanding Shims

pyenv works by inserting a directory of shims at the front of your `PATH`:

```python
$(pyenv root)/shims:/usr/local/bin:/usr/bin:/bin
```

## Using pyenv installer

[pyenv installer](https://github.com/pyenv/pyenv-installer)

## Basic github checkout

**This will get you going with the latest version of Pyenv** and **make it easy to fork** and contribute any changes back upstream.

### install pyenv in $HOME/.pyenv with last version

```cmd
git clone https://github.com/pyenv/pyenv.git ~/.pyenv
```

#### For bash

The **most reliable way to get Pyenv in all environments** is to append Pyenv configuration commands to both `.bashrc` (for interactive shells) and the profile file that Bash would use (for login shells).

Add the commands to `~/.bashrc` by running the following in your terminal:

```cmd
echo 'export PYENV_ROOT="$HOME/.pyenv"' >> ~/.bashrc
echo 'command -v pyenv >/dev/null || export PATH="$PYENV_ROOT/bin:$PATH"' >> ~/.bashrc
echo 'eval "$(pyenv init -)"' >> ~/.bashrc
```

To take affect:

```cmd
source ~/.bashrc
```

## show pyenv version

```cmd
pyenv version
```

## pyenv install

### list all python version whicy you can install

```cmd
pyenv install --list
```

### pyenv install python

```cmd
pyenv install <version>
```

## pyenv whence

```cmd
pyenv whence
```
