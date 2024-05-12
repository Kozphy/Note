#mssql 

## Source
https://www.youtube.com/watch?v=bs83hwFwdos

## What is locking
Database can be used by `many users` concurrenty. if these users `update the same data` at the same time, the `inconsistency` of  the data arises. Locking is a feature to `avoid` such inconsistencies.
## Why do we need locking?
In the real life, multiple users are connected at the same time and multiple transactions are executed in parallel.