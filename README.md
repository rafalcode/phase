Try 
make testSPLm


* Fork
Haplotype phase is only an occasional interest of mine, but I have been continually asked
to find ways of speeding it up. Mr. Stephen's implement is not the only one, but it
has always seemed the most advanced in terms of speed.

For a while it was available to academic users (such as I am) in 32 bit binary form
and I used python's multprocessing module to launch a pool of parallel instances on it.

Then it's source code was made available so I have forked it into my repository.
However, the primary aim of the fork is not to change any of the intricacies of the code at all,
but rather to annotate and allow me to do a least a clean compilation on 64-bit linux.

I also add my python multiprocessing script into a python subdir.
