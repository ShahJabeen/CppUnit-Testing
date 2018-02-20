

#ifndef INTVECTOR_H
#define INTVECTOR_H
#include <stdexcept>
#include <vector>

using namespace std;
/// The IntVector class is an extension of vector<int> together with
/// a binary search function.

class IntVector : public vector<int>
{

  public:
/// Given a sorted vector, it tries to find an item in the
/// the vector using binary search.
///
      
/// \param[in] item the item to search for
/// \param[out] index the index of the element if found, or the index
/// to insert the element if not found
/// \return true if item is found, and false otherwise.
/// \pre the vector is sorted
/// \post if the item is found, then (*this)[index] == item. If it is
/// not found, then index is the place item should be inserted into the
/// vector:
///
/// ie. (*this)[i] <= item for 0 <= i < index
///item < (*this)[i] for index <= i < size()
/// \throw invalid_argument if the vector is not sorted.

   bool binsearch(int item, size_type &index) const throw(invalid_argument);
};

#endif
