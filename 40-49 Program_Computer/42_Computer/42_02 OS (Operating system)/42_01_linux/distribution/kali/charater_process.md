# character process

## install snort

TODO: fix can't Unable to locate package snort

```cmd
apt-get install snort
```

## view file

- head
- tail
- nl
  - used to number line in view file
- sed
    - searching file filter through target words which will be replaced.
- more [file]
    - finding file display by pagination, you can type `ENTER` key to move to next page, typing `q` to exit.

- less [file]
    - it is similar to `"more"` except which cmd feature, you could use `/` to find target words which will be remarked in the first line, using `n` to find next target word.

### combine above

- `cat [file] | grep [what]`
- `nl [file] | grep [what]`
- `tail -n+[number] | head -n [number]`
- `sed s/[target word]/[replace word]/[g] [file] > [newfile]` where "s" means search and "g" means global which can be replaced by number, meaning how many target words you want to replace.
