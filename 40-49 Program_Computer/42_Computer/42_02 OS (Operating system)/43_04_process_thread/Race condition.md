#OS 

避免 race condition 的發生當兩個以上的 thread 訪問一個共享資源 (shared resource) 時,就會發生 race condition。
Race condition 發生時,有可能造成難以預期的狀況或 bug。
要避免 Race Condition 的發生,我們可以透過劃分 critical region。
程式當中, 訪問 shared resource 的部分,被稱為 Critical Region。每當我們要進去 Critical Region 之前,我們可以先把共享資源上鎖。上鎖期間,任何其他的 thread 都無法訪問這個共享資源。離開 Critical Region 之後,再去做解鎖。


> Lock 也稱為 mutex (mutual exclusion lock)。
在進入Critical Region之前,mutex會檢查我們是否可以
進入。Mutex另一個名字是binary semaphore。