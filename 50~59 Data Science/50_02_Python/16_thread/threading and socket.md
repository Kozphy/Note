# threading and socket
###### tags: `python module`

## starting threads
```python=
import threading

def hello():
    print('hello world!')
t1 = threading.Thread(target=hello)
t1.start()
```

After we have defined the function, we create our first thread. For this, we use the class Thread of the imported threading module. As a parameter, we specify the target to be the hello function. Notice that we don’t put parentheses after our function name here, since we are not calling it but just referring to it. By using the start method we put our thread to work and it executes our function.

## start vs run
In this example, we used the function **start** to put our thread to work. Another alternative would be the function **run**.

When we use the **run** function to execute our threads, they run serially one after the other. They wait for each other to finish. 

The **start** function puts all of them to work simultaneously.

```python=
import threading

def function1():
    for x in range(1000):
        print('ONE')

def function2():
    for x in range(1000):
        print('TWO')

t1 = threading.Thread(target=function1)
t2 = threading.Thread(target=function2)

t1.start()
t2.start()
```

When you run this script, you will notice that the output alternates between *ONEs* and *TWOs* . Now if you use the run function instead of the start function, you will see 1000 times *ONE* followed by 1000 times *TWO*. This shows you that the threads are run serially and not in parallel.

One more thing that you should know is that the application itself is also the main thread, which continues to run in the background. So while your threads are running, the code of the script will be executed unless you wait for the threads to finish.

## Waiting for threads
If we want to wait for our threads to finish before we move on with the code, we can use the **join** function.
```python=
import threading

def function():
    for x in range(1000):
        print('hello world!')

t1 = threading.Thread(target=function)
t1.start()
t1.join()

print('this is the end')
```

## Thread classes
Another way to build our threads is to create a class that inherits the Thread class.

We can then modify the *run* function and implement our
functionality. The start function is also using the code from the run function so we don’t have to worry about that.
```python=
import threading

class MyThread(threading.Thread):
    def __init__(self, message):
        threading.Thread.__init__(self)
        self.message = message

    def run(self):
        for x in range(1000):
            print(self.message)

mt1 = MyThread('This is my thread message!')
mt1.start()
```
## synchronizing thread
Sometimes you are going to have multiple threads running that all try to access the same resource. This may lead to inconsistencies and problems. In order to prevent such things there is a concept called locking . Basically, one thread is locking all of the other threads and they can only continue to work when the lock is removed.
```python=
import threading
import time

x = 8192

def halve():
    global x
    while (x > 1):
        x /= 2
        print(x)
        time.sleep(1)

    print('END!')

def double():
    global x 
    while (x < 16384):
        x *= 2
        print(x)
        time.sleep(1)
    print('END!')

t1 = threading.Thread(target=halve)
t2 = threading.Thread(target=double)

t1.start()
t2.start()
```

When we now start two threads with these target functions, we will see that the script won’t come to an end. The *halve* function will constantly decrease the number and the *double* function will constantly increase it.

With **locking** we can now let one function finish before the next function starts. 
```python=
import threading
import time

x = 8192

lock = threading.Lock()

def halve():
    global x, lock
    lock.acquire()

    while (x > 1):
        x /= 2
        print(x)
        time.sleep(1)
    print('END')
    lock.release()

def double():
    global x, lock
    lock.acquire()
    while( x < 16384 ):
        x *= 2
        print(x)
        time.sleep(1)
    print('END!')
    lock.release()

t1 = threading.Thread(target=halve)
t2 = threading.Thread(target=double)

t1.start()
t2.start()
```

First of all we defined a *Lock* object. It is part of the *threading* module and we need this object in order to
manage the locking.

Now, when we want to try to lock the resource, we use the function *acquire*. If the lock was already locked by someone else, we wait until it is released again before we continue with the code. However, if the lock is free, we lock it ourselves and release it at the end using the *release* function.

## Semaphores
Sometimes we don’t want to completely lock a resource but just limit it to a certain amount of threads or accesses. In this case, we can use so-called *semaphores*.

To demonstrate this concept, we will look at another very abstract example.
```python=
import threading
import time

semaphore = threading.BoundedSemaphore(value = 5)

def access(thread_number):
    print("{}: Trying access...".format(thread_number))

    semaphore.acquire()    

    print("{}: Access granted!".format(thread_number))
    print("{}: Waiting 5 seconds...".format(thread_number))
    time.sleep(5)
    semaphore.release()
    print("{}:Releasing!".format(thread_number))

for thread_number in range(10):
    t = threading.Thread(target=access, args=(thread_number,))
    t.start()


```

We first use the *BoundedSemaphore* class to create our *semaphore* object. The parameter value determines how many parallel accesses we allow. In this case, we choose five.

With our *access* function, we try to access the semaphore. Here, this is also done with the *acquire* function. If there are less than five threads utilizing the semaphore, we can acquire it and continue with the code. But when it’s
full, we need to wait until some other thread frees up one space.

When we run this code, you will see that the first five threads will immediately run the code, whereas the remaining five threads will need to wait five seconds until the first threads *release* the semaphore.

## Events
With *events* we can manage our threads even better. We can pause a thread and wait for a certain *event* to happen, in order to continue it.
```python=
import threading
event = threading.Event()

def function():
    print("Waiting for event...")
    event.wait()
    print("Continuing")

thread = threading.Thread(target=function)
thread.start()

x = input('Trigger event?')

if (x == "yes"):
    event.set()
```

To define an *event* we use the *Event* class of the threading module. Now we define our function which waits for our event. This is done with the *wait* function. So we start the thread and it waits.

Then we ask the user, if he wants to trigger the event. If the answer is yes, we trigger it by using the *set* function.

## Daemon threads
So-called *daemon* threads are a special kind of thread that runs in the background. This means that the program can be terminated even if this thread is still running. 

Daemon threads are typically used for background tasks like synchronizing, loading or cleaning up files that are not needed anymore. We define a thread as a daemon by setting the respective parameter in the constructor for *Thread* to *True*.

```python=
import threading
import time

path = 'text.txt'
text = ''

def readFile():
    global path, text
    while True:
        with open (path) as file:
            text = file.read()
        time.sleep(3)

def printloop():
    global text
    for x in range(30):
        print(text)
        time.sleep(1)
t1 = threading.Thread(target = readFile, daemon = True)
t2 = threading.Thread(target=printloop)

t1.start()
t2.start()
```

So, here we have two functions. The first one constantly reads in the text from a file and saves it into the **text** variable. This is done in an interval of three seconds. The second one prints out the content of **text** every second but only 30 times.

As you can see, we start the **readFile** function in a **daemon thread** and the **printloop** function in an ordinary thread. So when we run this script and change the content of the **text.txt** file while it is running, we will see that it prints the actual content all the time. Of course, we first need to create that file manually.

After it printed the content 30 times however, the whole script will stop, even though the daemon thread is still reading in the files. Since the ordinary threads are all finished, the program ends and the daemon thread just gets terminated.

## Queues
In Python, queues are structures that take in data in a certain order to then output it in a certain order. The default queue type is the so-called FIFO queue.
```python=
import queue

q = queue.Queue()

for x in range(5):
    q.put(x)

for x in range(5):
    print(q.get(x))
```

As you can see, we are using two functions here – **put** and **get** . The put function adds an element to the queue that can then be extracted by the **get** function.

## QUEUING RESOURCES
Let’s say we have a list of numbers that need to be processed. We decide to use multiple threads, in order to speed up the process. But there might be a problem. The threads don’t know which number has already been processed and they might do the same work twice, which would be unnecessary. Also, solving the problem with a counter variable won’t always work, because too many threads access the same variable and numbers might get skipped.

In this case we can just use queues to solve our problems. We fill up our queue with the numbers and every thread just uses the **get** function, to get the next number and process it.

```python=
import threading
import queue
import math

q = queue.Queue()
threads=[]

def worker():
    while True:
        item = q.get()
        if item is None:
            break
        print(math.factorial(item))
        q.task_done()

for x in range(5):
    t = threading.Thread(target=worker)
    t.start()
    threads.append(t)

zahlen = [134000, 14, 5, 300, 98, 88, 11, 23]

for item in zahlen:
    q.put(item)

q.join()

for i in range(5):
    q.put(None)

print(threads)
```

We start out with an empty queue and an empty list for threads. Our function has an endless loop that gets numbers from the list and calculates the factorial of them. 

At the end, we use the function **task_done** of the queue, in order to signal that the element was processed.

We start out with an empty queue and an empty list for threads. Our function has an endless loop that gets numbers from the list and calculates the factorial of them.

The method **join** of the **queue** waits for all elements to be extracted and processed. Basically, it waits for all the **task_done** functions. After that, we put **None** elements into the queue, so that our loops break.

## LIFO Queues
An alternative to the FIFO queues would be the LIFO queues . That stands for last in first out . You can imagine this queue like some sort of stack. The element you put last on top of the stack is the first that you can get from it.
```python=
import queue
q = queue.LifoQueue()

numbers = [ 1 , 2 , 3 , 4 , 5 ]

for x in numbers:
    q.put(x)

while not q.empty():
    print (q.get())
```

By using the LifoQueue class from the queue module, we can create an instance of this type. When we now put in the numbers one to five in ascending order, we will get them back in descending order.
```python=
The result would be:
5 4 3 2 1
```

## Prioritizing queues
What we can also do in Python, is creating prioritized queues . In these, every element gets assigned a level of priority that determines when they will leave the queue.
```python=
import queue
q = queue.PriorityQueue()
q.put(( 8 , "Some string" ))
q.put(( 1 , 2023 ))
q.put(( 90 , True ))
q.put(( 2 , 10.23 ))

while not q.empty():
print (q.get())
```

Here, we create a new instance of the class **PriorityQueue** . When we put a new element into this queue, we need to pass a tuple as a parameter. The first element of the tuple is the level of importance (**the lower the number, the higher the priority**) and the second element is the actual object or value that we want to put into the queue.

When we execute the print statement of the loop, we get the following results:
```
(1, 2023)
(2, 10.23)
(8, 'Some string')
(90, True)
```

As you can see, the elements got sorted by their priority number. If you only want to access the actual value, you need to address the index one because it is the second value of the tuple.
```python=
while not q.empty():
    print(q.get()[1])
```

## Network programming
### Socket
What’s important is that in Python we have different access levels for the network services. At the lower layers, we can access the simple sockets that allow us to use the connection-oriented and connectionless protocols like TCP or UDP, whereas other Python modules like *FTP* or *HTTP* are working on a higher layer – the **application layer**.

### creating Socket
In order to work with sockets in Python, we need to import the module *socket*.

```python=
import socket
```

Now, before we start defining and initializing our socket, we need to know a couple of things in advance:
- Are we using an internet socket or a UNIX socket?
- Which protocol are we going to use?
- Which IP-address are we using?
- Which port number are we using?

The first question can be answered quite simply. Since we want to communicate over a network instead of the operating system, we will stick with the **internet socket**.

The next question is a bit trickier. We choose between the protocols TCP (Transmission Control Protocol) and UDP ( User Datagram Protocol). TCP is connection-oriented and more trustworthy than UDP. The chances of losing data are minimal in comparison to UDP. On the other hand, UDP is
much faster than TCP. So the choice depends on the task we want to fulfil.

The IP-address should be the address of the host our application will run on. For now, we will use **127.0.0.1** which is the localhost address. This applies to every machine. But notice that this only works when you are running your scripts locally.

For our port we can basically choose any number we want. But be careful with low numbers, since all numbers up to 1024 are **standardized** and all numbers from 1024 to 49151 are **reserved** . If you choose one of these numbers, you might have some conflicts with other applications or your operating system
```python=
import socket

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
```

Here we created our first socket, by initializing an instance of the class socket . Notice that we passed two parameters here. The first one **AF_INET** states that we want an internet socket rather than a **UNIX socket**. The
second one **SOCK_STREAM** is for the protocol that we choose. In this case it stands for **TCP** . If we wanted **UDP** , we would have to choose **SOCK_DGRAM**.

## Client-Server Architecture
In a nutshell, the server is basically the one who provides information and serves data, whereas the clients are the ones who request and receive the data from the server.

![](https://i.imgur.com/mvcXctj.png)


A server opens up a session with every client that connects to it. This way, servers are able to serve multiple clients at once and individually.

## Server Socket methods
There are three methods of the socket class that are of high importance for the servers.

![](https://i.imgur.com/K79bGMo.png)
![](https://i.imgur.com/6mw9uCI.png)

## Client socket methods
For the client, there is only one specific and very important method, namely **connect** . With this method the client attempts to connect to a server which then has to accept this with the respective method.

## Other socket methods
Also, there are some other socket methods that are quite important in general.
![](https://i.imgur.com/bpFEhlF.png)

## Creating a server
Now that we understand the client-server architecture, we are going to implement our server. We decided that we want to use TCP and an internet socket. For the address we will use the localhost address 127.0.0.1 and as a port, we will choose 9999.

```python=
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.bind(("127.0.0.1", 9999))
s.listen()
print("Listening")
```

We use the method **bind**, in order to assign the IP-address and the port we chose. Notice that we are passing a tuple as a parameter here. Last but not least, we put our socket to listening mode by using the method **listen**. After that, we just have to create a loop that accepts the client requests that will eventually come in.

```python=
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.bind(("127.0.0.1",9999))

s.listen()

print("Listening...")

while True:
    client,  address = s.accept()
    print("Connected to {}".format(address))

    message = "Hello Client!"

    client.send(message.encode('ascii'))

    client.close()
```

The method **accept** waits for a connection attempt to come and accepts it. It then returns a **client** for responses and the **address** of the client that is connected. We can then use this client object in order to send the message. But it's important that we encode the message first, because otherwise we can't send it properly. At the end, we **close** the client because we don't need it anymore.

## creating a client
For our client we also need a socket but this time it will not use the function **bind** but the function **connect**.
```python=
import socket

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

s.connect(('127.0.0.1', 9999))
```

We just create an ordinary internet socket that uses TCP and then connect it to the localhost IP-address at the port 9999.

To not get the message from the server and decode it, we will use the **recv** function.
```python=
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.connect(('127.0.0.1',9999))

message = s.recv(1024)
s.close()
print(message.decode('ascii'))
```

After we connect to the server, we try to receive up to 1024 bytes from it. We then save the message into our variable and then we decode and print it.

## Connecting server and client
After that, we can run our client.py script many times and they will all connect to the server. The results will look like this:
### Server
```
Listening...
Connected to ('127.0.0.1', 4935)
Connected to ('127.0.0.1', 4942)
Connected to ('127.0.0.1', 4943)
Connected to ('127.0.0.1', 4944)
Connected to ('127.0.0.1', 4945)
```
### Client
```
Hello Client!
```

## Port scanner
What a port scanner basically does is: It tries to connect to certain ports at a host or a whole network, in order to find loopholes for future attacks. Open ports mean a security breach. And with our skills, we can already code our own penetration testing tool.

**WARNING**: Port scanning is not allowed on any hosts or networks which you don’t have explicit permission for. Only scan your own networks or networks for which you were given permission. I don’t take any liability for what you do with this knowledge, since I warned you!
```python=
import socket

target = '10.0.0.5'

def portscan(port):
    try:
        s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

        conn = s.connect((target, port))

        return True
    
    except:
        return False
    
for x in range(1, 501):
    if (portscan(x)):
        print("Port {} is open!".format(x))
    
    else:
        print('Port {} is closed!'.format(x))
```
Just choose a target address and run this script. You will see that it works.
```
Port 21 is closed!
Port 22 is open!
Port 23 is closed!
Port 24 is closed!
Port 25 is open!
```

But you will also notice that it is extremely slow. That’s because we serially scan one port after the other. And I think we have already learned how to handle that.

## threaded prot scanner
In order to speed up the scanning process, we are going to use **multithreading** . And to make sure that every port gets scanned and also that no port is scanned twice, we will use **queues**.
```python=
from concurrent.futures import thread
import socket
from queue import Queue
import threading

target = '10.0.0.5'

q = Queue()

for x in range(1, 501):
    q.put(x)

def portscan(port):
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        conn = s.connect((target, port))
        return True
    except:
        return False

def worker():
    while True:
        port = q.get()
        if portscan(port):
            print('Port {} is open!'. format(port))
        else:
            print('Port {} is close!'.format(port))
        

for x in range(30):
    t = threading.Thread(target=worker)
    t.start()
```

