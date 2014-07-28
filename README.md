Try 
make testSPLm


Why this fork?

Haplotype phase is only an occasional interest of mine, but I have been continually asked
to find ways of speeding it up. Mr. Stephen's implementation is not the only one, but it
has always seemed the most advanced certainly in terms of speed.

For a while it was available to academic users (such as I am) in 32 bit binary form
and I used python's multprocessing module to launch a pool of parallel instances on it.

Then it's source code was made available so I have forked it into my repository.
However, the primary aim of the fork is not to change any of the intricacies of the code at all,
but rather to annotate and allow me to do a least a clean compilation on 64-bit linux.

I also add my python multiprocessing script into a python subdir. And the Sun Grid Engine job array
invication in a subdirectory called SGE

Also I intend to make an inut file sanity checker, this is just for preprocessing
of the input files

ANother subdirectory called scritpfiles is merely for recording compilation sessions.

Notes:
Both tnt/vec.h and tnt/cmat.h try to printout a string (just once each) using istrstream. This comes from the extensionless strstream header
which is deprecated. You can use "#include<sstream>" instead, whose alternative function is "istringstream()"
