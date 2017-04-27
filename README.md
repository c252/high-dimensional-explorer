Copyright (C) 2008-2017  Cyrus Shaoul

Permission is granted to copy, distribute and/or modify this document
under the terms of the GNU Free Documentation License, Version 1.3
or any later version published by the Free Software Foundation;
with no Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts.
A copy of the license is included in the section entitled "GNU
Free Documentation License" at the end of this file.


****************************************************************************
			  How To Use HiDEx
****************************************************************************

by Cyrus Shaoul

cyrus.shaoul@uni-tuebingen.de

Document Version 0.092 for HiDEx v. 0.092

Updated on April 25th, 2017

Preface:
	 This document is split into two parts: Part 1 is the Quick Start
	 Guide. It is intended to be used by those who have extensive computer
	 experience who want to get HiDEx working as quickly as possible.
	 Part 2 is a detailed description of the software, and includes
	 step-by-step instructions on how to download, build, and use
	 HiDEx including all the settings and how to set them.
	 If you are at all unsure about your expertise, please jump
	 directly to Part 2.

****************************************************************************
Part 1: Quick Start Guide.
****************************************************************************

1A) Download the latest version of HiDEx from the HiDEx web site:

Install GIT and then type this command:

>  git clone https://github.com/cyrus/high-dimensional-explorer.git

NOTE: Make sure that you are on a supported platform and that you have all the
   required software packages.

1C) Compile the software using

	make hidex

and install it using the command: (Default location is ~/bin, so make sure to
add that to your path.)

	make install

1D) Get a corpus! There are a few on the Westbury Lab web site:

	http://www.psych.ualberta.ca/~westburylab/publications.html

or for a shortcut, use an example vector set, available at:

    http://www.psych.ualberta.ca/~westburylab/downloads/HiDEx.vectorset.download.html

1E) Go ahead! Start using HiDEx!

****************************************************************************
Part 2: User Manual
****************************************************************************

Table of Contents:

2A) What is HiDEx? What can I measure?
2B) What kind of hardware and software do I need to use HiDEx?
2C) How do I obtain HiDEx?
2D) How do I compile and install HiDEx?
2E) How do I prepare my data before running HiDEx?
2F) How do I use HiDEx to process my corpus?
2G) How do I use HiDEx once I have finished processing my corpus?
2H) How do I set up the configfile config.txt? What settings are available?
2I) How do I improve the performance of HiDEx?
Bib) Bibliography

****************************************************************************
2A) What is HiDEx? What can I measure?
****************************************************************************

HiDEx is a software system that implements a family word
co-occurrence models. These models are similar to those that were introduced by
Curt Burgess in 1996 as the HAL model and have been extensively studied since
(See the bibliography for a list of papers that will help you understand these models).

If you are unfamiliar with the ideas behind these models, I recommend that you
start by reading the following papers listed in the Bibliography:

Shaoul and Westbury, 2010
Shaoul and Westbury, 2006
Bullinaria and Levy, 2008
Bullinaria and Levy, 2012

HiDEx enables you to define the parameters of a general word-space
model and then process a corpus of text to create word vectors. It
also allows you to perform comparisons of these word vectors and other
calculations. HiDEx has been designed to handle very large corpora and
very large vectors, and to process them efficiently on systems with
large amounts of RAM and multiple CPUs.

NOTE: HiDEx has been tested on English, French, Spanish, Serbian,
Estonian, Japanese and Chinese, but it may work on other
languages as well. Any language that can be encoded in UTF8 and has spaces
between words should work. If there are no spaces between words, you
may need to use software to insert spaces. The authors are very interested in how
HiDEx works in other languages, so please let us know what you are doing!

Using HiDEx, it is possible to make the following measurements:

-Average Neighbor Similarity (ANS): [Note that in previous versions of
 HiDEx, this was called the ARC.] This is the average similarity between the
word and its neighbors, as defined by the neighborhood threshold. In
 the case that a word has zero neighbords within the threshold, the
 ANS will be taken as the similarity between the word and the most
 similar word outside the threshold.

-Inverse Neighbor Count (InvNCOUNT) The inverse of the number of
 neighbors.

HiDEx is free software released under the GNU Public License. This
means that you are free to change HiDEx to better suit your needs. If
you do make improvements, please send them to me so that I can add
them to my version of HiDEx and share the improvements with everyone.

****************************************************************************
2B) What kind of hardware and software do I need to use HiDEx?
****************************************************************************

HiDEx is not distributed as a pre-compiled program. It comes as many C++
files, and must be compiled by the user before it will work. Here are the
hardware and software requirements for parallel and serial operation.

HiDEx does not work well or at all on computers that are underpowered. Please
make sure that you have sufficient resources to run this program before
continuing with the installation process.

Abbreviations: +Req=Required, +Rec=Recommended

Hardware:
-----------------------------
CPU: (Types: PowerPC, Power5, and Intel/AMD x86 CPUs have been tested so far)
-For serial operation:
*Req:	A fast 64-bit CPU.
*Rec:	The fastest CPU you can get your hands on. HiDEx has not been
tested on 32-bit CPUs, but it might work.
-For parallel operation:
*Req:	A computer with more than one core/processor in it, the faster the better.
*Rec:	A computer with 4 or more cores/processors in it, the faster the better.

Memory:
+Req:	2 Gb RAM (the more the better)
+Rec:	10 Gb or more of RAM (the more the better)

Hard Disk:
+Req:	100 Gb of disk
+Rec:	500 Gb or more of VERY FAST DISK (the faster the better)

Software:
-----------------------------
OS:
+Req:	MacOS X 10.4.11 or greater with XCode Tools installed.
+Req:	Linux 2.6.x or greater

Compiler:
+Req:    g++ 4.2 or greater with libgomp included (For Mac OS X, you
may need to download gcc using port, fink or brew)

Text Editor:
+Rec:     Mac OS X: TextWrangler, BBEdit or any other text editor.
+Rec:     Linux: emacs, vi or other text editor

Dependent Software Libraries:
The GNU Unicode String Libraries
On Linux and Mac, please install this package:

% sudo apt-get install libunistring-dev

****************************************************************************
2C) How do I obtain HiDEx?
****************************************************************************

Go to this web site and download the software:

   http://www.psych.ualberta.ca/~westburylab/projects/HDMoLS.html

Please make sure that you read and understand the restrictions that govern
your use of the software. Read the file COPYING.txt, as it is written in
English, not legal gobbledygook.

****************************************************************************
2D) How do I compile and install HiDEx?
****************************************************************************

Step 1: Move the TGZ file that you just downloaded to the correct directory.
(I recommend the ~/src directory).

Or get the latest version from the GIT repo:

>  git clone https://github.com/cyrus/high-dimensional-explorer.git

Step 2: Start up a terminal application (Mac OS X: Terminal, Linux:
xterm). Change to the correct directory:

	       cd ~/src

Step 3: Unpack the software in a good location
To unpack it, use this command:

	  tar xzf hidex.[version].tgz

Step 4: Change directory to the newly created directory:

	cd hidex

Step 5: Compile the program  (Make sure that your system has all the required
software listed in section 2B first, in particular, the new compiler).

 	make hidex

Step 6: Create a directory for the binary if you do not already have one. (I
recommend ~/bin)

	mkdir ~/bin

Step 7: Using a text editor, edit the file called "Makefile"
to have the correct value for
BINDIR (in this case, ~/bin). Then install the program using the
following command:

     make install

Step 8: Add the BINDIR to the PATH environment variable of your shell,
if it is not already included. Reload your PATH or start a new
terminal process.  If you don't much about the shell, and the PATH
environment variable, please read the following web page:

     http://en.wikipedia.org/wiki/Environment_variable

That is it! Take a break! Stretch out your tired finger muscles!

WARNING: This is the first public release of HiDEx, so there may still be some
bugs in the above process. If you get any error messages when doing the above
steps, please post your questions to Cyrus Shaoul using his web site:

       http://www.sfs.uni-tuebingen.de/~cshaoul/


****************************************************************************
2E) How do I prepare my data before running HiDEx?
****************************************************************************

There are two choices for getting co-occurrence data when using HiDEx: use your
own corpus or downloading a pre-built set of co-occurrence data. First
I will describe the process of using a corpus, and then I will explain
how download and install a set of vectors from the Internet.

The amount of processing power, hard disk and processing time required
to process a corpus is large, but feasible on a modern workstation or
server. On most computers I have tested it will take approximately
three days to process a 1 billion word corpus. The raw matrix that
HiDEx creates from that corpus will be 60Gb in size or larger. Once
this process is done once, it will not have to be done again for that corpus.

Step 1: Obtain or download a large corpus of text. I have created a very
large corpus of USENET text that is available freely under a Creative Commons
license. It is available here:

 http://www.psych.ualberta.ca/~westburylab/downloads/usenetcorpus.download.html

Step 2: If the corpus is not the above corpus, please change the corpus so
that it follows the following format :

     [Text]
     [Document Separator]
     [Text]
     [Document Separator]
     [Text]
     [Document Separator]

Choose a very uncommon string to act as your document separator. I recommend:

---END.OF.DOCUMENT---

Make sure that there is one of these between every document in your
corpus.  Do not worry about capitalization, punctuation, numbers or
other symbols, as they will be removed by HiDEx. Do make sure to
remove any markup (such as SGML, HTML or other markup language with
tags).

If possible, remove any redundant, non-content text (such as "Courtesy
of the XYZ News Wire Service") if it is in all the documents.

NEW in version 0.06:

For Unicode support to work, all your corpora and word lists must be
encoded as UTF-8 in unix-type text files. Legacy encodings are not
supported. There are many tools for converting files to UTF-8, and I
have used iconv with some success.

Step 3: If you corpus is contained in many separate files, concatenate them
into one large file. For example the command:

     cat *.txt > corpus.txt

will concatenate all the files with the extension "txt" in a directory into a
new file.

Step 4: Put the corpus file in your working directory. I recommend creating a
new one for using with HiDEx. These commands will do it for you.

    mkdir ~/work
    mv corpus.txt ~/work

Step 5: Choose a lexicon to use with HiDEx. This is a file that contains all
the words that will be analyzed for co-occurrence. If you do not have one, and
need one for the English language, I recommend using one available here under
a Creative Commons License:

  http://www.psych.ualberta.ca/~westburylab/downloads/wlfreq.download.html

Make sure to remove the frequency data from this file before using the above
file.

I also recommend reducing the size of the lexicon to 30,000 to 70,000 words
for performance reasons. You can do this by removing the words with the n lowest
frequencies. Please see section 2I for information on how lexicon size
impacts HiDEx's performance.

Once your lexicon is ready, put it in your work directory like so:

     mv lexicon.txt ~/work

Now you are ready to process your corpus.

****************************************************************************
2F) How do I use HiDEx to process my corpus?
****************************************************************************

Intro: HiDEx is a program that has many different modes of operation. From
this point onwards you will be specifying the mode that you would like HiDEx
to use by typing "-m" and then the name of the mode.

Also, HiDEx has many parameters that change how it operates. These parameters
are set inside a text file called the configfile. A sample configfile is
provided with the software. Before doing any work, I recommend copying the
sample configfile to your work directory:

       cp ~/src/hidex/sample.config.txt ~/work/config.txt

If no configfile is specified on the command line, a file in the current directory called
config.txt is used. You can specify an alternate name and location of the
configfile by using the "-f" option. For example

	hidex -f special.config.txt

Step 1: Edit the configfile to make the correct settings. Edit the
"config.txt" file in your favorite text editor. The list of possible settings
and their implications are described in the documentation in the "config.txt"
file.

Step 2: Create an empty data-store using this command:

     cd ~/work
     hidex -m create

Step 3: Process the corpus. The "update" command will create a sparse matrix
representation of all the lexical co-occurrences in the corpus. WARNING:
depending on the size of your corpus and your parameter settings, this process
can take a long time. Please see section 2I for information on this topic.

    hidex -m update

ALTERNATIVE METHOD: Download a vector set.

If are unable to obtain and process a corpus, please download a vector set from
the following URL:

    http://www.psych.ualberta.ca/~westburylab/downloads/HiDEx.vectorset.download.html

To install this vector set, please read the instructions that are
included with the download.

****************************************************************************
2G) How do I use HiDEx once I have finished processing my corpus?
****************************************************************************

Once the corpus co-occurrence data has been collected, you can begin
analyzing it using several of HiDEx's other modes.

There are two types of calculations: vector aggregation and vector-based
metrics. Vector aggregation must take place before metric calculation, and can
be quite time-consuming. For this reason, HiDEx can save the results of
aggregation (called the Global Co-occurrence Matrix, or GCM) in the
work directory.

Each time a GCM is needed, HiDEx will seek and reuse a GCM saved in
the work directory. This feature is enabled by using the saveGCM
setting in the config file.  Please see the config file documentation
for more info.

Warning: On some computers it may be faster to NOT save the GCM and
recalculate the GCM each time. Please try both modes to compare.

Getting neighborhoods:

NOTE: The output of the following commands will depend on the settings
you have made in the configuration file. Please see section 2H for an
explanation of all the settings possible.

To get neighborhoods in a word space, use the "getneighbors" mode, as in the
following example:

	  hidex -m getneighbors

NOTE: There are two numbers reported for each word of interest: 1)
ANS: Average Neighbour Similarity (The average similarity between the
word and its neighbors that are defined by the threshold.  2)
InvNCOUNT: The inverse of the number of neighbors (+1).

To find the similarity between pairs of words, use the "getsimilarity":

	  hidex -m getsimilarity

To output specific vectors from the GCM in a dense matrix format text file, use
the "getvectors" mode:

           hidex -m getvectors

To run a large batch of models and find neighborhoods, use the
"batchneighbors" mode: [Currently under development. Please do not use!]

	  hidex -m batchneighbors

To  run  a  large batch  of  models  and  find  inter-word distances,  use  the
"batchsimilarity" mode: [Currently under development. Please do not use!]

	  hidex -m batchsimilarity

For all of these commands, the output will be saved in a new folder called
"output.date.time". This folder will be created in the current directory, or
if you have specified a different output directory in the configfile, in that
directory.

To add more text to your co-occurrence database, you can change the corpus
filename to the new corpus that you would like to add, and then run this
command again:

	hidex -m update

To remove a database and all the auxiliary files that are related to it use
the following command:

        hidex -m remove

WARNING: The above command is NOT reversible. Once you have removed the
database, it is gone forever. You have been warned! :-)

****************************************************************************
2H) How do I set up the configfile config.txt? What settings are available?
****************************************************************************

The section explains all the settings available in the configfile and what
options are possible for each setting. The default name of the config
file is "config.txt" and the default location is the current
directory. To specify the name and location of the configfile, use the
following command:

	  hidex -f alternate.config.file.txt -m getneighbors

[General Options]
dbname: This is the name to use for the database and all of its auxiliary
files. You can store multiple databases in one directory and pick which one to
by changing this parameter.

(dbpath): (Optional setting). Used to specify an absolute path for the database.
Avoid using this setting unless you need to.

dictFilename: Name of the lexicon file, assumed to be in the Working Directory.
Format is a text file with one word per line.

[Corpus Processing Options]
maxWindowBehind: Maximum size of word window behind target word.
maxWindowAhead: Maximum size of word window ahead of target word.
These two parameters change the size of the database, as they limit how much
context information is saved. The actual size of the window used
during vector aggregation is set using the windowLenBehind setting below.

corpusFilename: The filename of the corpus. Assumed to be in the
Working Directory. The format is described in section 2E of this manual.

stepsize: The number of vectors to collect per pass through the corpus. If
you run out of memory during an "update", reduce this value. If you find
 that you have more RAM to spare when running update, increase this
 value. A rough guide to help you set this: a stepsize of 5000 will
 use 4Gb of RAM, and RAM usage increases linearly as stepsize increases.

eod: End of Document marker. Used when processing the corpus. HiDEx does not
count co-occurrence accross document boundaries. See section 2E for details.

(outputpath): (Optional!) An absolute path for program output. HiDEx defaults to
the Working Directory is this is not set.

metric: Choose your similarity metric here. If it is blank, HiDEx will
default to using (inverse) Euclidean distance. Other possible values are
Cosine, CityBlock and Correlation. For more information on these
metrics, please see the references listed in the Bibliography.

normalization: Choose your method for vector normalization
here. Default is co-occurrence divided by target word frequency. Other
possibilities are PPMI (Positive Pointwise Mutual Information) and
Correlation.  For more information on these normalization methods,
please see the references listed in the Bibliography.

weightingScheme: Code number to choose a weighting scheme. The names are
fairly self explanatory! The original HAL model used #1, Ramped Linear
Weighting.

  FLAT = 0
  RAMPED LINEAR = 1
  RAMPED QUADRATIC = 2
  FORWARD RAMP = 3
  BACKWARD RAMP = 4
  INVERSE RAMP = 5
  INVERSE QUADRATIC = 6
  SECOND WORD = 7
  THIRD WORD = 8
  FOURTH WORD = 9

contextSize: The number of dimensions to use in the co-occurrence
vector. If contextSize is set to N, only the N most frequent word's
vectors are included in the final GCM.

windowLenBehind: Size of the window behind the target word. Can be any
number from 1 to MaxWindowLenBehind.

windowLenAhead: Size of the window behind the target word. Can be any
number from 1 to MaxWindowLenAhead.

useThreshold: Setting to turn on z-score based neighborhood membership
thresholds (words more that 1 standard deviation similar than the average
similarity. 1 means it is ON, 0 means it is OFF.

percenttosample: When using thresholds, the percent of pairs to sample
during the calculation of the z-scores. 0.1 means 10%.

neighbourhoodSize: When not using neighborhood thresholds, the number of
neighbors to find.

separate: Enables separate forward and backward vectors when set to 1. When
set to 0, Forward and Backward vectors are combined, halving the context size.

wordlistfilename: List of words to analyze (it will usually be a list
of words, one per line. Only when using getsimilarity mode will you
need to proved a list of word pairs, two words per line, separated by tabs.)

wordlistsize: Used for picking random sub-samples from a word list. If
this number is smaller than the number of words in the wordlist, HiDEx
will pick a random subset of the words in the wordlistfile to use. If
this number is larger than the number of words in the wordlistfile, or
if the setting is left blank, HiDEx will use all the words in the file
set by wordlistfilename.

saveGCM: If this is set to "1", HiDEx will create a large text file
called "dbname.gcm" in the working directory. This file will be
automatically detected the next time a GCM is required, and
loaded. Depending on the speed of your computer, this may be faster or
slower than building the GCM on the fly.

With the addition of Unicode support, there are two new options

normCase: Apply case normalization globally. This option will take any
Unicode character than can have a lower-case glyph, and replace it
with that glyph. The default mode is 1 (true). To stop case
normalization, set this to 0 (false). There is one more important
factor to correct case normalization: your shell's environment
variable settings for the LANG variable. HiDEx will check this setting
and appy the correct normalization only if this is set to the correct
language. For example, if you are processing German, your LANG setting
should be set to de_DE.UTF-8

englishContractions: In English, the string "'s" is a contraction
that can make it difficult for the model to recognize words that
are possessives.  This defaults to 1 (true), which means that words
like "ball's" will be split into two words, "ball" and "'s" and
"can't" will become "can" and "'nt".
englishContractions=1

NEW OPTIONS in vesion 0.07:
---------------------------

useVariance: In previous versions of HiDEx, the context was created
from the N most frequent words in the corpus. In the original HAL
paper (Lund & Burgess, 1996), the vectors for the N most variant words
were used instead. This feature implements the method from Lund &
Burgess (1996).

The default value for this is "0", meaning that variance will not be
used. If it is set to "1", it must be enabled at the time of creation
of the co-occurrence database. It will not work with databases created
with versions of HiDEx before version 0.06, or with new databases that
were not created with useVariance = 1.


****************************************************************************
2I) How do I improve the performance of HiDEx?
****************************************************************************

The simplest way to improve performance is to run HiDEx on a computer with
more CPUs and faster CPUs, more memory and faster disk. Make sure to use
OpenMP, and set the number of threads equal to the number of cores available.

Certain configuration options have a very strong influence on the performance
of HiDEx. Here is a summary of the most important ones:

Lexicon Size: The larger the lexicon, the larger the matrix (Each
extra word in the lexicon adds an extra dimension to the
representation). A lexicon with double the number of words in it can
cause a 400% increase in storage space needed for the raw
co-occurrence data. Also, the lexicon size will increase the size of
the GCM, which will slow down all metric calculations. I normally use
a lexicon of around 50,000 words in size.

maxWindowBehind and maxWindowAhead: Large values for these variable will
greatly slow down the processing of the corpus and the aggregation of the GCM.

stepsize: This is a memory-usage tuning setting, and must be set
carefully. During corpus processing, large amounts of data must be kept in
RAM. There is no way that I know to predict the sparseness of the database,
and that means there is no way to predict the memory usage of HiDEx when
processing a corpus. The default setting is very conservative, and should work
for computers that have 4Gb of RAM. If you have more RAM than 4Gb, please try
larger values, but be careful to monitor the memory usage of the HiDEx
process. If HiDEx tries to use more memory than your computer has, it will
begin using virtual memory (and cause enormous amounts of swapping) and your
corpus processing will take months instead of hours.

contextSize: The larger the context size, the greater the memory usage, and
the greater the computation required. I recommend using context sizes of
10,000 or greater.

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Thanks for reading the manual. If you any comments about it, please send them
to cyrus.shaoul@uni-tuebingen.de
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


****************************************************************************
Bibliography:
****************************************************************************

Buchanan, L., Westbury, C., & Burgess, C. (2001). Characterizing semantic
space: Neighborhood effects in word recognition. Psychonomic Bulletin & Review,
8, 531-544.

Bullinaria, J., & Levy, J. (2007). Extracting semantic representations from word
co-occurrence statistics: A computational study. Behavior Research Methods,
39, 510-526.

Bullinaria, J.A. & Levy, J.P. (2012). Extracting Semantic
Representations from Word Co-occurrence Statistics: Stop-lists,
Stemming and SVD. Behavior Research Methods, 44, 890-907.

Lund, K., & Burgess, C. (1996). Producing high-dimensional semantic spaces
from lexical co-occurrence. Behavior Research Methods, Instrumentation,
and Computers, 28, 203-208.

Rohde, D. L. T., Gonnerman, L., and Plaut, D. C. (submitted). An
improved model of semantic similarity based on lexical
co-Occurrence. Cognitive Science.
http://www.cnbc.cmu.edu/~plaut/papers/abstracts/RohdeGonnermanPlautSUB-CogSci.COALS.html

Shaoul, C., & Westbury, C. (2006). Word frequency effects in high-dimensional
co-occurrence models: A new approach. Behavior Research Methods, 38,
190-195.

Shaoul, C., & Westbury, C. (2007). A usenet corpus (2005-2008)
(Tech. Rep.). Edmonton, AB: University of Alberta. Downloaded from
http://www.psych.ualberta.ca/~westburylab/downloads/usenetcorpus.download.html

Shaoul, C. & Westbury, C. (2010). Exploring lexical co-occurrence space using
HiDEx. Behavior Research Methods, 42:2, 393-413.




























                GNU Free Documentation License
                 Version 1.3, 3 November 2008


 Copyright (C) 2000, 2001, 2002, 2007, 2008 Free Software Foundation, Inc.
     <http://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.

0. PREAMBLE

The purpose of this License is to make a manual, textbook, or other
functional and useful document "free" in the sense of freedom: to
assure everyone the effective freedom to copy and redistribute it,
with or without modifying it, either commercially or noncommercially.
Secondarily, this License preserves for the author and publisher a way
to get credit for their work, while not being considered responsible
for modifications made by others.

This License is a kind of "copyleft", which means that derivative
works of the document must themselves be free in the same sense.  It
complements the GNU General Public License, which is a copyleft
license designed for free software.

We have designed this License in order to use it for manuals for free
software, because free software needs free documentation: a free
program should come with manuals providing the same freedoms that the
software does.  But this License is not limited to software manuals;
it can be used for any textual work, regardless of subject matter or
whether it is published as a printed book.  We recommend this License
principally for works whose purpose is instruction or reference.


1. APPLICABILITY AND DEFINITIONS

This License applies to any manual or other work, in any medium, that
contains a notice placed by the copyright holder saying it can be
distributed under the terms of this License.  Such a notice grants a
world-wide, royalty-free license, unlimited in duration, to use that
work under the conditions stated herein.  The "Document", below,
refers to any such manual or work.  Any member of the public is a
licensee, and is addressed as "you".  You accept the license if you
copy, modify or distribute the work in a way requiring permission
under copyright law.

A "Modified Version" of the Document means any work containing the
Document or a portion of it, either copied verbatim, or with
modifications and/or translated into another language.

A "Secondary Section" is a named appendix or a front-matter section of
the Document that deals exclusively with the relationship of the
publishers or authors of the Document to the Document's overall
subject (or to related matters) and contains nothing that could fall
directly within that overall subject.  (Thus, if the Document is in
part a textbook of mathematics, a Secondary Section may not explain
any mathematics.)  The relationship could be a matter of historical
connection with the subject or with related matters, or of legal,
commercial, philosophical, ethical or political position regarding
them.

The "Invariant Sections" are certain Secondary Sections whose titles
are designated, as being those of Invariant Sections, in the notice
that says that the Document is released under this License.  If a
section does not fit the above definition of Secondary then it is not
allowed to be designated as Invariant.  The Document may contain zero
Invariant Sections.  If the Document does not identify any Invariant
Sections then there are none.

The "Cover Texts" are certain short passages of text that are listed,
as Front-Cover Texts or Back-Cover Texts, in the notice that says that
the Document is released under this License.  A Front-Cover Text may
be at most 5 words, and a Back-Cover Text may be at most 25 words.

A "Transparent" copy of the Document means a machine-readable copy,
represented in a format whose specification is available to the
general public, that is suitable for revising the document
straightforwardly with generic text editors or (for images composed of
pixels) generic paint programs or (for drawings) some widely available
drawing editor, and that is suitable for input to text formatters or
for automatic translation to a variety of formats suitable for input
to text formatters.  A copy made in an otherwise Transparent file
format whose markup, or absence of markup, has been arranged to thwart
or discourage subsequent modification by readers is not Transparent.
An image format is not Transparent if used for any substantial amount
of text.  A copy that is not "Transparent" is called "Opaque".

Examples of suitable formats for Transparent copies include plain
ASCII without markup, Texinfo input format, LaTeX input format, SGML
or XML using a publicly available DTD, and standard-conforming simple
HTML, PostScript or PDF designed for human modification.  Examples of
transparent image formats include PNG, XCF and JPG.  Opaque formats
include proprietary formats that can be read and edited only by
proprietary word processors, SGML or XML for which the DTD and/or
processing tools are not generally available, and the
machine-generated HTML, PostScript or PDF produced by some word
processors for output purposes only.

The "Title Page" means, for a printed book, the title page itself,
plus such following pages as are needed to hold, legibly, the material
this License requires to appear in the title page.  For works in
formats which do not have any title page as such, "Title Page" means
the text near the most prominent appearance of the work's title,
preceding the beginning of the body of the text.

The "publisher" means any person or entity that distributes copies of
the Document to the public.

A section "Entitled XYZ" means a named subunit of the Document whose
title either is precisely XYZ or contains XYZ in parentheses following
text that translates XYZ in another language.  (Here XYZ stands for a
specific section name mentioned below, such as "Acknowledgements",
"Dedications", "Endorsements", or "History".)  To "Preserve the Title"
of such a section when you modify the Document means that it remains a
section "Entitled XYZ" according to this definition.

The Document may include Warranty Disclaimers next to the notice which
states that this License applies to the Document.  These Warranty
Disclaimers are considered to be included by reference in this
License, but only as regards disclaiming warranties: any other
implication that these Warranty Disclaimers may have is void and has
no effect on the meaning of this License.

2. VERBATIM COPYING

You may copy and distribute the Document in any medium, either
commercially or noncommercially, provided that this License, the
copyright notices, and the license notice saying this License applies
to the Document are reproduced in all copies, and that you add no
other conditions whatsoever to those of this License.  You may not use
technical measures to obstruct or control the reading or further
copying of the copies you make or distribute.  However, you may accept
compensation in exchange for copies.  If you distribute a large enough
number of copies you must also follow the conditions in section 3.

You may also lend copies, under the same conditions stated above, and
you may publicly display copies.


3. COPYING IN QUANTITY

If you publish printed copies (or copies in media that commonly have
printed covers) of the Document, numbering more than 100, and the
Document's license notice requires Cover Texts, you must enclose the
copies in covers that carry, clearly and legibly, all these Cover
Texts: Front-Cover Texts on the front cover, and Back-Cover Texts on
the back cover.  Both covers must also clearly and legibly identify
you as the publisher of these copies.  The front cover must present
the full title with all words of the title equally prominent and
visible.  You may add other material on the covers in addition.
Copying with changes limited to the covers, as long as they preserve
the title of the Document and satisfy these conditions, can be treated
as verbatim copying in other respects.

If the required texts for either cover are too voluminous to fit
legibly, you should put the first ones listed (as many as fit
reasonably) on the actual cover, and continue the rest onto adjacent
pages.

If you publish or distribute Opaque copies of the Document numbering
more than 100, you must either include a machine-readable Transparent
copy along with each Opaque copy, or state in or with each Opaque copy
a computer-network location from which the general network-using
public has access to download using public-standard network protocols
a complete Transparent copy of the Document, free of added material.
If you use the latter option, you must take reasonably prudent steps,
when you begin distribution of Opaque copies in quantity, to ensure
that this Transparent copy will remain thus accessible at the stated
location until at least one year after the last time you distribute an
Opaque copy (directly or through your agents or retailers) of that
edition to the public.

It is requested, but not required, that you contact the authors of the
Document well before redistributing any large number of copies, to
give them a chance to provide you with an updated version of the
Document.


4. MODIFICATIONS

You may copy and distribute a Modified Version of the Document under
the conditions of sections 2 and 3 above, provided that you release
the Modified Version under precisely this License, with the Modified
Version filling the role of the Document, thus licensing distribution
and modification of the Modified Version to whoever possesses a copy
of it.  In addition, you must do these things in the Modified Version:

A. Use in the Title Page (and on the covers, if any) a title distinct
   from that of the Document, and from those of previous versions
   (which should, if there were any, be listed in the History section
   of the Document).  You may use the same title as a previous version
   if the original publisher of that version gives permission.
B. List on the Title Page, as authors, one or more persons or entities
   responsible for authorship of the modifications in the Modified
   Version, together with at least five of the principal authors of the
   Document (all of its principal authors, if it has fewer than five),
   unless they release you from this requirement.
C. State on the Title page the name of the publisher of the
   Modified Version, as the publisher.
D. Preserve all the copyright notices of the Document.
E. Add an appropriate copyright notice for your modifications
   adjacent to the other copyright notices.
F. Include, immediately after the copyright notices, a license notice
   giving the public permission to use the Modified Version under the
   terms of this License, in the form shown in the Addendum below.
G. Preserve in that license notice the full lists of Invariant Sections
   and required Cover Texts given in the Document's license notice.
H. Include an unaltered copy of this License.
I. Preserve the section Entitled "History", Preserve its Title, and add
   to it an item stating at least the title, year, new authors, and
   publisher of the Modified Version as given on the Title Page.  If
   there is no section Entitled "History" in the Document, create one
   stating the title, year, authors, and publisher of the Document as
   given on its Title Page, then add an item describing the Modified
   Version as stated in the previous sentence.
J. Preserve the network location, if any, given in the Document for
   public access to a Transparent copy of the Document, and likewise
   the network locations given in the Document for previous versions
   it was based on.  These may be placed in the "History" section.
   You may omit a network location for a work that was published at
   least four years before the Document itself, or if the original
   publisher of the version it refers to gives permission.
K. For any section Entitled "Acknowledgements" or "Dedications",
   Preserve the Title of the section, and preserve in the section all
   the substance and tone of each of the contributor acknowledgements
   and/or dedications given therein.
L. Preserve all the Invariant Sections of the Document,
   unaltered in their text and in their titles.  Section numbers
   or the equivalent are not considered part of the section titles.
M. Delete any section Entitled "Endorsements".  Such a section
   may not be included in the Modified Version.
N. Do not retitle any existing section to be Entitled "Endorsements"
   or to conflict in title with any Invariant Section.
O. Preserve any Warranty Disclaimers.

If the Modified Version includes new front-matter sections or
appendices that qualify as Secondary Sections and contain no material
copied from the Document, you may at your option designate some or all
of these sections as invariant.  To do this, add their titles to the
list of Invariant Sections in the Modified Version's license notice.
These titles must be distinct from any other section titles.

You may add a section Entitled "Endorsements", provided it contains
nothing but endorsements of your Modified Version by various
parties--for example, statements of peer review or that the text has
been approved by an organization as the authoritative definition of a
standard.

You may add a passage of up to five words as a Front-Cover Text, and a
passage of up to 25 words as a Back-Cover Text, to the end of the list
of Cover Texts in the Modified Version.  Only one passage of
Front-Cover Text and one of Back-Cover Text may be added by (or
through arrangements made by) any one entity.  If the Document already
includes a cover text for the same cover, previously added by you or
by arrangement made by the same entity you are acting on behalf of,
you may not add another; but you may replace the old one, on explicit
permission from the previous publisher that added the old one.

The author(s) and publisher(s) of the Document do not by this License
give permission to use their names for publicity for or to assert or
imply endorsement of any Modified Version.


5. COMBINING DOCUMENTS

You may combine the Document with other documents released under this
License, under the terms defined in section 4 above for modified
versions, provided that you include in the combination all of the
Invariant Sections of all of the original documents, unmodified, and
list them all as Invariant Sections of your combined work in its
license notice, and that you preserve all their Warranty Disclaimers.

The combined work need only contain one copy of this License, and
multiple identical Invariant Sections may be replaced with a single
copy.  If there are multiple Invariant Sections with the same name but
different contents, make the title of each such section unique by
adding at the end of it, in parentheses, the name of the original
author or publisher of that section if known, or else a unique number.
Make the same adjustment to the section titles in the list of
Invariant Sections in the license notice of the combined work.

In the combination, you must combine any sections Entitled "History"
in the various original documents, forming one section Entitled
"History"; likewise combine any sections Entitled "Acknowledgements",
and any sections Entitled "Dedications".  You must delete all sections
Entitled "Endorsements".


6. COLLECTIONS OF DOCUMENTS

You may make a collection consisting of the Document and other
documents released under this License, and replace the individual
copies of this License in the various documents with a single copy
that is included in the collection, provided that you follow the rules
of this License for verbatim copying of each of the documents in all
other respects.

You may extract a single document from such a collection, and
distribute it individually under this License, provided you insert a
copy of this License into the extracted document, and follow this
License in all other respects regarding verbatim copying of that
document.


7. AGGREGATION WITH INDEPENDENT WORKS

A compilation of the Document or its derivatives with other separate
and independent documents or works, in or on a volume of a storage or
distribution medium, is called an "aggregate" if the copyright
resulting from the compilation is not used to limit the legal rights
of the compilation's users beyond what the individual works permit.
When the Document is included in an aggregate, this License does not
apply to the other works in the aggregate which are not themselves
derivative works of the Document.

If the Cover Text requirement of section 3 is applicable to these
copies of the Document, then if the Document is less than one half of
the entire aggregate, the Document's Cover Texts may be placed on
covers that bracket the Document within the aggregate, or the
electronic equivalent of covers if the Document is in electronic form.
Otherwise they must appear on printed covers that bracket the whole
aggregate.


8. TRANSLATION

Translation is considered a kind of modification, so you may
distribute translations of the Document under the terms of section 4.
Replacing Invariant Sections with translations requires special
permission from their copyright holders, but you may include
translations of some or all Invariant Sections in addition to the
original versions of these Invariant Sections.  You may include a
translation of this License, and all the license notices in the
Document, and any Warranty Disclaimers, provided that you also include
the original English version of this License and the original versions
of those notices and disclaimers.  In case of a disagreement between
the translation and the original version of this License or a notice
or disclaimer, the original version will prevail.

If a section in the Document is Entitled "Acknowledgements",
"Dedications", or "History", the requirement (section 4) to Preserve
its Title (section 1) will typically require changing the actual
title.


9. TERMINATION

You may not copy, modify, sublicense, or distribute the Document
except as expressly provided under this License.  Any attempt
otherwise to copy, modify, sublicense, or distribute it is void, and
will automatically terminate your rights under this License.

However, if you cease all violation of this License, then your license
from a particular copyright holder is reinstated (a) provisionally,
unless and until the copyright holder explicitly and finally
terminates your license, and (b) permanently, if the copyright holder
fails to notify you of the violation by some reasonable means prior to
60 days after the cessation.

Moreover, your license from a particular copyright holder is
reinstated permanently if the copyright holder notifies you of the
violation by some reasonable means, this is the first time you have
received notice of violation of this License (for any work) from that
copyright holder, and you cure the violation prior to 30 days after
your receipt of the notice.

Termination of your rights under this section does not terminate the
licenses of parties who have received copies or rights from you under
this License.  If your rights have been terminated and not permanently
reinstated, receipt of a copy of some or all of the same material does
not give you any rights to use it.


10. FUTURE REVISIONS OF THIS LICENSE

The Free Software Foundation may publish new, revised versions of the
GNU Free Documentation License from time to time.  Such new versions
will be similar in spirit to the present version, but may differ in
detail to address new problems or concerns.  See
http://www.gnu.org/copyleft/.

Each version of the License is given a distinguishing version number.
If the Document specifies that a particular numbered version of this
License "or any later version" applies to it, you have the option of
following the terms and conditions either of that specified version or
of any later version that has been published (not as a draft) by the
Free Software Foundation.  If the Document does not specify a version
number of this License, you may choose any version ever published (not
as a draft) by the Free Software Foundation.  If the Document
specifies that a proxy can decide which future versions of this
License can be used, that proxy's public statement of acceptance of a
version permanently authorizes you to choose that version for the
Document.

11. RELICENSING

"Massive Multiauthor Collaboration Site" (or "MMC Site") means any
World Wide Web server that publishes copyrightable works and also
provides prominent facilities for anybody to edit those works.  A
public wiki that anybody can edit is an example of such a server.  A
"Massive Multiauthor Collaboration" (or "MMC") contained in the site
means any set of copyrightable works thus published on the MMC site.

"CC-BY-SA" means the Creative Commons Attribution-Share Alike 3.0
license published by Creative Commons Corporation, a not-for-profit
corporation with a principal place of business in San Francisco,
California, as well as future copyleft versions of that license
published by that same organization.

"Incorporate" means to publish or republish a Document, in whole or in
part, as part of another Document.

An MMC is "eligible for relicensing" if it is licensed under this
License, and if all works that were first published under this License
somewhere other than this MMC, and subsequently incorporated in whole or
in part into the MMC, (1) had no cover texts or invariant sections, and
(2) were thus incorporated prior to November 1, 2008.

The operator of an MMC Site may republish an MMC contained in the site
under CC-BY-SA on the same site at any time before August 1, 2009,
provided the MMC is eligible for relicensing.



