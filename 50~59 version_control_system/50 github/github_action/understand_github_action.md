# [source](https://docs.github.com/en/actions/learn-github-actions/understanding-github-actions)

> Last updated 2022/10/07

## Overview

GitHub Actions is a `continuous integration and continuous delivery (CI/CD)` platform that allows you to `automate your build, test, and deployment pipeline`.

You can `create workflows` that `build and test every pull request to your repository, or deploy merged pull requests to production`.

GitHub Actions goes beyond just DevOps and lets you run workflows when other events happen in your repository. For example, `you can run a workflow to automatically add the appropriate labels whenever someone creates a new issue in your repository`.

GitHub provides `Linux, Windows, and macOS virtual machines` to run your workflows, or you can host your own `self-hosted runners` in your own `data center` or `cloud infrastructure`.

## The components of GitHub Actions

You can `configure` a GitHub Actions `workflow to be triggered` when an `event occurs in your repository`, such as a `pull request being opened` or `an issue being created`.

Your workflow contains `one or more jobs` which can run in `sequential order or in parallel`. `Each job` will `run inside its own virtual machine runner`, or `inside a container`, and `has one or more steps` that either `run a script that you define` or `run an action`, which is a `reusable` extension that can simplify your workflow.
![component of github action](component_of_github_action.drawio.svg)

## Workflows

A workflow is a `configurable automated process` that will run one or more jobs. Workflows are defined by a `YAML` file checked in to your repository and will run when `triggered by an event` in your repository, or they can be triggered manually, or at a defined schedule.

Workflows are defined in the `.github/workflows` directory in a repository, and a `repository can have multiple workflows`, each of which can perform a `different set of tasks`.

## Event

An `event` is a `specific activity` in a repository that `triggers a workflow run`.

## Jobs

`A job is a set of steps in a workflow` that execute `on the same runner`. Each step is either a shell script that will be executed, or an action that will be run.

Steps are executed in order and are dependent on each other. Since each step is executed on the same runner, `you can share data from one step to another`.

`You can configure a job's dependencies with other jobs`; by default, jobs have no dependencies and run in parallel with each other. When a job takes a dependency on another job, it will wait for the dependent job to complete before it can run.

## Actions

`An action is a custom application for the GitHub Actions platform` that performs a complex but `frequently repeated task`.

Use an action to help reduce the amount of repetitive code that you write in your workflow files. An action can pull your git repository from GitHub, set up the correct toolchain for your build environment, or set up the authentication to your cloud provider.

`You can write your own actions`, or you can find actions to use in your workflows in the GitHub Marketplace.

## Runners

`A runner is a server that runs your workflows when they're triggered`. Each runner can `run a single job at a time`.

GitHub provides Ubuntu Linux, Microsoft Windows, and macOS runners to run your workflows; each workflow run executes in a fresh, newly-provisioned virtual machine.

If you need a different operating system or require a specific hardware configuration, you can host your own runners.

## Create an example workflow

GitHub Actions uses `YAML` syntax to `define the workflow`. `Each workflow is stored as a separate YAML file` in your code repository, in a directory named `.github/workflows`

You can create an example `workflow` in your repository that `automatically triggers a series of commands whenever code is pushed`.

1. In your repository, create the `.github/workflows/` directory to store your workflow files.
2. In the `.github/workflows/` directory, create a new file called `learn-github-actions.yml` and add the following code.

```yaml
name: learn-github-actions
run-name: ${{ github.actor }} is learning GitHub Actions
on: [push]
jobs:
  check-bats-version:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
      - uses: actions/setup-node@v3
        with:
          node-version: '14'
      - run: npm install -g bats
      - run: bats -v
```

3. Commit these changes and push them to your GitHub repository.

Your new GitHub Actions workflow file is now installed in your repository and `will run automatically each time someone pushes a change to the repository`.

## Understanding workflow file

- name (`Optional`)
  - Workflow name will appear in the `Actions` tab.

- run-name (`Optional`)
    - Name for workflow runs generated from the workflow, which will appear in the list of workflow. In above example uses `github` context to display the `username of the actor who triggered the workflow run`.

- on: [push]
    - Specfying trigger for this workflow. In above example which `is triggered every time` someone pushes a change to the repository or merges a pull request.

- jobs
  - Grouping together all the jobs that run in the `learn-github-actions` workflow.

- check-bats-version
    - Defining job name. The child keys will define properties of the job.

- runs-on: ubuntu-lastest
    - This means that the job will execute on a fresh virtual machine hosted by GitHub.

- steps
    - Grouping all the steps that run in the `check-bats-version` job. Each item nested under this section is a separate action or shell script.

- uses: actions/checkout@v3
    - `uses` keywords specifies that this step will run `v3` of the `actions/checkout` action.
