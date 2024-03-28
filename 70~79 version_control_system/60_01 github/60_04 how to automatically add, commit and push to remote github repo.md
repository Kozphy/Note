#github 

```git
#!/usr/bin/env bash

cd $(dirname ${BASH_SOURCE[0]})

current_time=$(date +"%T")

if [[ -n $(git status -s) ]]; then
    echo "Changes found. Pushing changes..."
    git add -A && git commit -m "update $current_time" && git push
else
    echo "No changes found. Skip pushing."
fi
```

