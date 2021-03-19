Compilation {#compilation .unnumbered}
===========

In order to compile the code, open the terminal and go inside the
assesment folder , then proceed to the desired grade demonstration and
type:

``` {.bash language="bash"}
    $ make
    $ ./memorymake
```

Stage 3 {#stage-3 .unnumbered}
=======

After running the memorymake file from Stage 3 folder, the user will be
presented with a demonstration of all the funcionalities of the program.
Allocating memory with mymalloc freeing it with myfree and defragmenting
it with with mydefrag.

mymalloc() {#mymalloc .unnumbered}
----------

If it finds a unallocated segment of the exact same size as the desired
one it returns it. Otherwise it continues to look until it finds a
unallocated segment bigger than the requested size. It splits the
unallocated segment into a segment of the wanted size and segment of
free memory.

myfree() {#myfree .unnumbered}
--------

Looks for the pointer to free in the segmenttable linked list. And
cheanges the status from allocated to deallocated.

mydefrag() {#mydefrag .unnumbered}
----------

Looks trough the segmenttable linked list. For each pair of adjiacent
segments if the first one is unallocated and the second one is they are
swapped. If both are unallocated then they are compressed. This assures
that all allocated memory segments are at the begining of the memory
while all the free memory is in one segment. The pointers given in the
ptrlist will be modified so that they point to the right memory
location.

Running the demonstration {#running-the-demonstration .unnumbered}
-------------------------

The demonstration is only available for Stage 3.However it
includes all the features for the lower stages. The user is presented
with information about what the program has done or what it is going to
do. The user then presses the ENTER key in order to proceed to the next
step of the demonstration. getchar() is used in the implementation of
the next demonstration step mechanism.