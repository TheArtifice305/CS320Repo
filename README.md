# CS320Repo
This is a repository for my CS320 Operating Systems class.

Entry Report for Project 3: Scheduler -
All the files that were updated for this project are as follows:

proc.c - within function allocproc(), initiallized tickets and ticks,
       - within function fork(), child tickets are set to inherit from parents
       - within function scheduler(), updated function to collect total
       - number of tickets, generate a random number using scaled_random() function,
       - and select winning process including winning ticket.

proc.h - added tickets and ticks to struct proc{}.

pstat.h (added file) - added pstat.h to pass results to user space.

syscall.c - added system calls getpinfo() and settickets().

syscall.h - added system call numbers for getpinfo() and settickets().

sysproc.c - created the functions for system calls getpinfo() and settickets().

user.h - added settickets() and getpinfo() to system calls.

getpinfo.c (added file) - created getpinfo to display ticks and tickets for the user in
                        - the command line.

usys.pl - added entrys for getpinfo() and settickets().

Makefile - added random number generator to OBJS and hardwork.c test code to UPROGS.

hardwork.c (added file) added file for test code 

random.c (added file) added random number generator that was provided.

random.h (added file) creates uses for scaled_random() and rand_init().

FOR PROJECT 5:
Here's the commands to help run the code for all the parts:
PART 1:
gcc -pthread -o dining_philosophers dining_philosophers.c (For compiler)
./dining_philosophers [Number of Philosophers] [Algorithm #]

PART 2:
gcc -pthread -o barbershop barbershop_problem.c
./barbershop <# of barbers>

PART 3:
gcc -pthread -o barbershop3 barbershop_part_3.c
./barbershop3 <# of barbers>

These are just some examples of how to run the code for each specific Part.
