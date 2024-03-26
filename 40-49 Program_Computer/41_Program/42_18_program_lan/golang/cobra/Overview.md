# Overview
###### tags: `golang cobra`

## Concept
Cobra is built on a structure of commands, **arguments & flags**.

**Commands** represent actions, **Args** are things and **Flags** are modifiers for those actions.

The pattern to follow is `APPNAME VERB NOUN --ADJECTIVE`. or `APPNAME COMMAND ARG --FLAG`

In the following example, 'server' is a command, and 'port' is a flag:
```bash=
hugo server --port=1313
```

In this command we are telling Git to clone the url bare.
```bash=
git clone URL --bare
```

## Command
Command is the central point of the application. Each interaction that the application supports will be contained in a Command. 

A command can have children commands and optionally run an action.

In above, 'server' is the command

## Flags
A flag is a way to modify the behavior of a command. 

In above , 'port' is the flag

## install
```bash=
go get -u github.com/spf13/cobra@latest
```

```bash=
import "github.com/spf13/cobra"
```

## Usage
`cobra-cli` is a command line program to generate cobra applications and command files. It will bootstrap your application scaffolding to rapidly develop a Cobra-based application.

It can be installed by running:
```bash=
go install github.com/spf13/cobra-cli@latest
```

