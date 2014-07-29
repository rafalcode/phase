#ifndef CLASS_HAPLOTYPE_H
#define CLASS_HAPLOTYPE_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace::std;

class Haplotype
{
  vector<float> h;
  string locus_type; //stores whether ith locus is SNP or MS .... would have been better being a plural. FOr every there will be a type 'S' (SNP) or 'M' micsat.
public:
  Haplotype(string lt=""); // Constructor
  Haplotype(Haplotype const &); // Copy constructor
  ~Haplotype(); // Destructor    

  Haplotype(const Haplotype &, int firstlocus, int lastlocus); // haplotype between firstlocus and lastlocus
  Haplotype(const Haplotype &h1, const Haplotype &h2); // concatenation

  const Haplotype &operator=(Haplotype const & b);

  void set_allele(int locus, int allele);
  //void set_haplotype( CIndividual ind, int chr);
  unsigned get_allele(int locus) const;
  float get_fuzzyallele(int locus) const;
  
  void print_haplotype(ostream &ostr, const vector<int> *coding) const;
  
  bool operator==(const Haplotype &) const; //inline
  bool operator!=(const Haplotype &) const; //inline
  bool Matches(const Haplotype &, const vector<int> &) const; // inline
  bool const operator<(const Haplotype &) const;//inline
  bool const operator<=(const Haplotype &) const; //inline
  bool const operator>=(const Haplotype &) const;
  string get_locus_type() const; //inline
  unsigned Nloci() const; // inline
  unsigned get_nloci() const; // inline (as above)
  int get_printedlen() const; // inline
};

inline void Haplotype::set_allele (int locus, int a) // Set allelic types
{
  h[locus] = a; /* but h is a vector of floats ...? */
}

inline unsigned Haplotype::get_allele(int locus) const
{
  // cout << "allele = " << h[locus] << endl;
//   int ret = (int) (h[locus]+0.49);
//   cout << "returned allele = " << (int) (h[locus]+0.49) << endl;
//   if(((int) h[locus]) != ret){
//     cout << "Here!" << endl;
//     exit(1);
//   }
  return (unsigned)floor(h[locus]+0.5);
  
}

inline float Haplotype::get_fuzzyallele(int locus) const /* return a float, do not integerise */
{
  return h[locus];
}

inline bool Haplotype::operator==( const Haplotype &b) const
{
  return h == b.h;
}

inline bool Haplotype::operator!=(const Haplotype &b) const
{
   return h!=b.h;
}

inline bool Haplotype::Matches( const Haplotype & b, const vector<int> & uselist) const
{
  for(vector<int>::const_iterator u = uselist.begin(); u!=uselist.end(); u++)
    if(h[*u] != b.h[*u])
      return false;

  return true;
}

inline const bool Haplotype::operator<(const Haplotype & b ) const
{
  return h<b.h;
}

inline const bool Haplotype::operator<=(const Haplotype & b ) const
{
  return h<=b.h;
}

inline const bool Haplotype::operator>=(const Haplotype & b) const
{
  return h>=b.h;
}

inline string Haplotype::get_locus_type() const
{
  return locus_type;
}

inline unsigned Haplotype::Nloci() const /* the exact same as get_nloci ... see next one */
{
  return locus_type.size();
}

inline unsigned Haplotype::get_nloci() const
{
  return locus_type.size();
}

inline int Haplotype::get_printedlen() const
{
  int l=0;
  for(unsigned i=0;i<locus_type.size(); i++) {
    if(locus_type[i]=='S')
      l++;
    else
      l+=3;
  }
  return l;
}

//void print(Haplotype & h){
//  h.print_haplotype(cout, coding);
//}

//  inline void Haplotype::set_haplotype ( CIndividual ind, int chr)
//  { 
//    if(phase[locus]==0){
//      phenotype[chr][locus] = allele;
//      orig_phenotype[chr][locus] = allele;  
//    }
//    else{
//      phenotype[1-chr][locus] = allele;
//      orig_phenotype[1-chr][locus] = allele;  
//    }
//  }

int NDiff(Haplotype h1, Haplotype h2);

#endif
