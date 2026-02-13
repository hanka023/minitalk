This project has been created as partof the 42 curriculum by haskalov (Hana Skalova)


Description

This project is about sending chars and words from client to server. 
Every char is sended from client to server bit by bit, after server must complete char from bits and print it to the terminal.


Compilation

Compile program use make (or make re)


use:

You have 2 terminals, one for server and one for client. 

First you have to open server:
Open terminal 1. and write "./server". Server have to print Server PID (Server PID is  number which is different for every time, for example 221717)

Now you have to open terminal 2. and write "./client" and copy server PID (for example 221717) and write something (for example "Hello!")

Server now shoul obtain your "Hello!" and print it in terminal. 


example:

./server
Server PID: 221717

./client 221717 Hello!

./server
Server PID: 221717
Hello!


Resources


https://github.com/Surfi89/minitalk/tree/main
https://github.com/hanshazairi/42-minitalk/tree/master

https://42-cursus.gitbook.io/guide/2-rank-02/minitalk

https://medium.com/@Kr1sNg/step-by-step-guide-to-minitalk-project-at-school-42-deacf16369ec


AI - chatgpt used as an advisor for explaining terms which I don't undrstand

testers



valgrind checker used for checking memory leaks https://valgrind.org/