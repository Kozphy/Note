# User Guide
###### tags: `golang cobra`

## typical cobra-based structure
```text=
  ▾ appName/
    ▾ cmd/
        add.go
        your.go
        commands.go
        here.go
      main.go
```


## In a Cobra app, typically the main.go file is very bare. It serves one purpose: initializing Cobra.
```go=
package main

import (
  "{pathToYourApp}/cmd"
)

func main() {
  cmd.Execute()
}
```

## Using the Cobra Generator
To manually implement Cobra you need to create a bare main.go file and a rootCmd file. You will optionally provide additional commands as you see fit.

### Create rootCmd
Cobra doesn't require any special constructors. Simply create your commands.

Ideally you place this in app/cmd/root.go:
```go=
var rootCmd = &cobra.Command{
  Use:   "hugo",
  Short: "Hugo is a very fast static site generator",
  Long: `A Fast and Flexible Static Site Generator built with
                love by spf13 and friends in Go.
                Complete documentation is available at https://gohugo.io/documentation/`,
  Run: func(cmd *cobra.Command, args []string) {
    // Do Stuff Here
  },
}

func Execute() {
  if err := rootCmd.Execute(); err != nil {
    fmt.Fprintln(os.Stderr, err)
    os.Exit(1)
  }
}
```
### Returning and handling errors
if you wish to return an error to the caller of a command, `RunE` can be used.
```go=
package cmd

import (
  "fmt"
  "github.com/spf13/cobra"
)

func init() {
  rootCmd.AddCommand(tryCmd)
}

var tryCmd = &cobra.Command{
  Use:   "try",
  Short: "Try and possibly fail at something",
  RunE: func(cmd *cobra.Command, args []string) error {
    if err := someFunc(); err != nil {
	return err
    }
    return nil
  },
}
```
## Working with Flags
Flags provide modifiers to control how the action command operates.

