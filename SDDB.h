/* 
Copyright (C) 2004,2005,2006,2007,2008  Cyrus Shaoul and Geoff Hollis 

This file is part of HiDEx.

    HiDEx is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    HiDEx is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with HiDEx in the COPYING.txt file.
    If not, see <http://www.gnu.org/licenses/>.


*/

//
// This class handles the creation and maintenance
// of Semantic Distance databases.
//

#ifndef SDDB_H
#define SDDB_H

#include <algorithm>
#include <map>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>
#include "SDDBAccessor.h"
// #include "dict.h"



// ****************************************************************************
// Defines, typedefs, and macros
// ****************************************************************************
#define DBDIR_TAG                      ".data"
#define DICT_TAG                       ".dict"
#define ACCESSOR_TAG                   ".db"
#define DBINFO_TAG                     ".dbinfo"
#define GCM_TAG                        ".gcm"
#define CONTEXT_TAG                        ".context"
#define MIN_WORD_VAL                       0
#define UNRECOGNIZED_WORD                 -1
#define END_OF_DOCUMENT                   -2
#define NO_WORD                           -3
#define SCALEFACTOR                       10.0 
#define MAXNEIGHBOURS                     10000
#define BLOCKSIZE                         8
#define DOC_BATCH_SIZE                    100000
#define MIN_WORDS_PER_DOC                 40
//for preprocessor
#define MAX_WORDLEN                        30
#define NONWORD_MARKER                    -1

//typedef float Float;
typedef float Float;

//structs
struct resultdata {
  string word;
  Float LDRT;
  Float ARC;
  Float InverseNcount;
};

struct pairdata {
  string word1;
  string word2;
  Float distance;
  Float ARC1;
  Float ARC2;
  Float InverseNcount1;
  Float InverseNcount2;
};

struct wordpair
{
  string main;    // main word
  string possessive;     // posessive
};

/* class Numpair */
/* { */
/*  public: */
/*     int _x;  */
/*     int _y;  */

/*     Numpair(int x, int y) */
/*         : _x(x), */
/*           _y(y) */
/*     {         */
/*     } */

/*     bool operator<(const Numpair& num) const */
/*     { */
/*         return (_x < num._x || (!(num._x < _x) && _y < num._y)); */
/*     } */
/* }; */

typedef pair<unsigned int,unsigned int> Numpair;
typedef set<Numpair> numberpairset;
typedef map<Numpair,bool> numberpairmap;
typedef vector<Numpair> numberpairvector;

// Dictionary has keys of words and values of ID
typedef map<string, int> Dictionary;

// Maps word to their frequencies
typedef map<int, size_t> FrequencyMap;

//Frequency sorter is for sorting words by frequency
typedef pair<int, size_t> FrequencyEntry;
typedef vector<FrequencyEntry> FrequencySorter;

//idMap has keys of IDs and values of words (For reverse lookup)
typedef map<int,string> idMap;

// Vector of distances and words
typedef pair<Float, int> NeighborhoodEntry;
typedef vector<NeighborhoodEntry> NeighborsVector;

// Vector of distances and words
typedef pair<Float, int> NeighborhoodEntry;
typedef vector<NeighborhoodEntry> NeighborsVector;


//typedef vector<const DictPair *> DictVector;

//***************************************************

class RevSort
{
public:
    bool operator() (const NeighborhoodEntry & a, const NeighborhoodEntry & b) const
    {
        return a.first > b.first;
    }
};

class FreqSort
{
public:
    bool operator() (const NeighborhoodEntry & a, const NeighborhoodEntry & b) const
    {
        return a.first < b.first;
    }
};

class FreqSort2
{
public:
    bool operator() (const FrequencyEntry & a, const FrequencyEntry & b) const
    {
        return a.first > b.first;
    }
};

class SDDB
{
public:
  static const int WEIGHT_SCHEME_FLAT = 0;
  static const int WEIGHT_SCHEME_RAMPED_LINEAR = 1;
  static const int WEIGHT_SCHEME_RAMPED_EXPONENTIAL = 2;
  static const int FORWARD_RAMP = 3;
  static const int BACKWARD_RAMP = 4;
  static const int INVERSE_RAMP = 5;
  static const int INVERSE_EXPONENTIAL = 6;
  static const int SECOND_WORD = 7;
  static const int THIRD_WORD = 8;
  static const int FOURTH_WORD = 9;


  //
  // Instantiate the object
  //
  SDDB(const string dbname, const string dbpath);

  //
  // close everything down and delete everything from RAM
  //
  ~SDDB();

  //
  // Create an SDDB with these settings
  //
  //
  // Load the SDDB defined by this filename into memory
  //
  void load(const string eod, const size_t maxMemory);

  void initialize(const string& dictfile, const int windowLenAhead, const int windowLenBehind, const string& eod);
  //
  // Process the co-occurances in this file.
  // If this is a concatination of more than one file, we will stop processing
  // it as if it were one file as soon as eof is encountered
  //
  void update(istream& in, const int testmode);

  void process2(istream& in, string EOD);
  //
  // Return a Semantic distance matrix for the given word.
  //
  Matrix<int> *getMatrix(const char *word,
                         const int windowLenBehind,
                         const int windowLenAhead);


  //
  // How many entries are in this database?
  //
  int rows();


  //
  // How long is each vector?
  //
  int columns();


  //
  // What is the size of the behind sliding window?
  //
  int windowLenBehind();


  //
  // What is the size of the ahead sliding window?
  // 
  int windowLenAhead();

  //
  // Return a copy of every dictionary entry we have.
  // sets num to the number of entries returned
  //
  //  vector<string> getEntries(int &num);

  //
  // Flush all pending actions
  //
  void flush();

  //
  // Close the SDDB
  // 
  void close();

  //
  // Set the minimum vector num we are collecting co-occruance
  // counts for
  // 
  void setCurrentStep(const int step);


  //
  // Set the maximum vector num we are collecting co-occurance
  // counts for, where max = currentStep + stepsize - 1
  //
  void setStepSize(const int stepsize);


  // sets the end of document marker
  void setEOD(const string EOD);


  //
  // Increment to the next step of vectors. Returns true if there
  // is another step to work on, and returns false otherwise
  //
  bool stepUp();
  
  //
  // Ahhh, at long last! This is what we've been waiting for!
  // Print all of the SDs for all of our words, plus neighbours,
  // to our output directory
  //
  void printPairs(istream &in,
                  const int context_size, int weightingScheme, 
                  const int windowLenBehind, const int windowLenAhead,
                  const int separate, 
                  const string outputpath,
		  const string metric, 
		  const string normalization,
		  const int saveGCM);

  int printSDs(istream &in,
	       const int context_size, 
	       int weightingScheme, 
	       const string metric, 
	       const string normalization,
	       const int windowLenBehind, 
	       const int windowLenAhead,
	       const size_t neighbourhood_size,
	       const int usezscore,
	       //	       const int useldrt,
	       const int separate,
	       const double percenttosample, 
	       const int wordlistsize, 
	       const string outputpath,
	       const int saveGCM
	       ); 

  int printVects(istream &in,
                 const int context_size, 
                 int weightingScheme, 
                 const int windowLenBehind, const int windowLenAhead,
                 const int wordlistsize, 
                 const int separate, const string outputpath,
		 const string normalization,		     
		 const int saveGCM);
  
  Float GenerateStandardDev(const Float percenttosample, 
                            const vector<Float*> &vectors, Float &average, Float &stddev,
			    const string metric);
  
  vector<int> GenerateContext(const size_t context_size, const bool separate);
  
  void AggregateVectors(vector<Float*> &vectors, const bool separate, vector<int>& context, const int behind, const int ahead, const vector<int> weightScheme, const string normalization);
  
  // Reads in a new document from the corpus file.
  bool ConvertADocument(istream& in, vector<int>& wordsInDocument, const size_t behind, const size_t ahead, const int testmode);
  
  //get a set of N documents from the corpus
  void GetDocuments(istream &in, const int number, vector<string> &documents);

  // tests a document to see if it is empty
  bool documentIsNotEmpty(vector<int>& wordsInDocument, size_t ahead) ;
  
  //  make the window when there is no window
  void makeWindow(vector<int>& window, vector<int>& wordsInDocument) ;
  
  // slide the window over one word.
  void slideWindow(vector<int>& window, vector<int>& wordsInDocument) ;
  
  // Adds Cooccurences to raw cooccrence database
  void addCooccurrences(vector<int>& window, size_t target) ;

  // creates Directories needed for output of results.
  pair<string,string> createDirectories (const string outputpath);
  
  // nornamlizes vectors
  Float* normalizeRawVector(int TargetWord, Float cooccurenceVector[], const string normalization, 
			  vector<int> &context );

  // calculates the similarity between two vectors
  Float CalcSimilarity(const vector<Float*> &vectors, int w1, int w2, const string algorithm);

  // Saves a copy of the GCM to disk.
  void SaveMatrix(const vector<Float*> &vectors);

  // Loads a copy of the GCM to disk.
  void LoadMatrix(vector<Float*> &vectors);

 private:
  string _dbname;
  string _dbpath;
  
  /** The accessor for all of the words */
  SDDBAccessor* _accessor;
  
  /** The dictionary we use to hold word - id key-value mappings */
  Dictionary _dict;
  
  /** Frequency counts for all of the words */
  FrequencyMap _frequency;
  
  // map from ID back to word.
  idMap _idMap;
  
  /** How many words have we processed so far? */
  int _wordNum;
  
  /** What step are we working on? */
  int _currStep;

  /** How big are our steps? */
  int _stepsize;
  
  /** How big is our corpus? */
  int _corpussize;
  
  /** How many words are there in our lexicon? */
  size_t _numwords;

  /** How many context dimensions will we use? */
  size_t _numdimensions;

  /** What is the DB Forw window available */

  int _realAhead;

  /** What is the DB Back window available */
  int _realBehind;
  
  // End of Document string
  string _eod;

  //possessive
  string _possessive;

  //private functions for preprocessing
  bool acceptable_word_char(char& ch, bool alphaOnly);
  string strip_non_alpha(string& word, bool sidesOnly);
  wordpair extractWord(string& localword);
  vector<int> preprocess(string& word);
  vector<string> iscompound(string& localword);
};

void removeAllFiles(const string& dbname, const string& dbpath);


template <class T>
Float * collapseMatrix(Matrix<T> *M, 
                        const int *weight_scheme,
                        const int realBehind, const int behind,
                        const int realAhead,  const int ahead,
                        const int *context, const int context_size, const int num_dimensions, 
                        const Float wordfrequency, const int separate);


/* 
void addtoresults(vector<resultdata> &results, string word, double ARC, int Ncount);
std::string getcorrelation(vector<resultdata> &results);
*/

#endif // SDDB_H