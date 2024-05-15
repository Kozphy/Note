#OS 

## what is process, thread and race condition
在電腦科學中,進程(process)是正在執行的程式,執行緒(thread)是可以由`程序調度員(scheduler`,一個作業系統內的功能)獨立管理的輕量級進程。`一個 process 內部可以有多個 threads`。

## what is multi-threaded programming
由於絕大多數的時間,我們電腦的許多 CPU 都是閒置的狀態(因為threads 可能會需要等待 I/O,或是可能發生 CPU 正在忙碌,其他的 CPU 卻閒得發慌的情況),因此,我們可以寫出內部含有多個threads 的程式,讓 threads 被多個 CPU 並進執行,善用 CPU 資源,提高效率。這就是許多程式語言都支援的 `multi-threaded programming` °

## when occur race condition
避免 race condition 的發生當兩個以上的 `thread 訪問一個共享資源 (shared resource) 時,就會發生 race condition`。

Race condition 發生時,有可能造成難以預期的狀況或 bug。

要避免 Race Condition 的發生,我們可以透過劃分 critical region。

程式當中, 訪問 shared resource 的部分,被稱為 Critical Region。

每當我們要進去 Critical Region 之前,我們可以先把共享資源上鎖。上鎖期間, 任何其他的 thread 都無法訪問這個共享資源。離開 Critical Region 之後,再去做解鎖。

> Lock 也稱為 mutex (mutual exclusion lock)。
在進入 Critical Region 之前,mutex會檢查我們是否可以
進入。Mutex另一個名字是 binary semaphore。