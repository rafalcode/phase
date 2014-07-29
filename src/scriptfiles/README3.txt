The mk0.scr 
was a first attempt to compile
the PHASE executable cam out OK, but I couldn't run the test


the warnings are from vec.h an antique usage of strstream it would seem.
I saw all it needed was a symlink.

So, with the symlink in place 
I could go ahead to script file mk1.scr
 ....
The program outputs
percetns progress in this way.
i.e.
  99% done[A
etc.
Which is too verbose.

So in the script file I have deleted all but hte 100%

It takes about 5 of the test file sand runs them together with a perl check type script.
Happily, thought, it works fine, though I shall take optimization soff and get warnings on the PHASE exectuable compilation.

ANother thing to note about the Makefile in "src" and then the Makefile in the Phase211src
is that they are practivcally identical.

Another incongruity is why the executable "phase" is often referred to while it's the upper-case version that is actually produced.
i.e. witness make ultraclean .. it deletes the "phase" but not "PHASE".

After fixing the sistringstream functions in cmat.h and vec.h,
there's the issue of comparing ints and unsigned types ..quite alot otf these.

OK: things collapsed later. There were few incidents with stream except my mod in indnode.cpp+
seemed to fail.

Horribly the compiler is not being specific about which error.

Ok.. sorry it did identify it:

indnode.cpp:316:46: error: invalid conversion from ‘int’ to ‘std::ios_base::openmode {aka std::_Ios_Openmode}’ [-fpermissive]
     ostringstream ostr ( idstring, NMAXD + 3 );

So I had to return it to the ostrstream() function - and it did compile,
so this simple replacement of ostrstream with ostringstream is not so straightforward.

But also, it's pretty hard to see what's being done, because ostrstream is just discarded pretty much. The value of interest is idstring, which is a normal char*o
the incredible thing is, that the delcaration/function seems to operate on idstring. COde looks flimsy.


Well I'd got to a fairly low level of warnings, 
and went about cleaning up Haplotype.{h,c}pp
and things were OK.

Then suddenly I hit something that had occurred before and had never been able to work out.
It's the TNT habit of including tnt/version.h
when version.h is in the current directory.

Well maybe when it's included form the directory above it.
but I wasn't even touching this!


Indeed! I wne tover to an untouched version, and all of a sudden this error is rearign its head!
But the truth is I don't know how these relative paths ont he include actuallyworked in the firt place!
What's going on?
