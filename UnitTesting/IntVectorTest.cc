#include "IntVector.h"
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <algorithm>

using namespace std;

class IntVectorTest : public CppUnit::TestFixture
{
private:
   CPPUNIT_TEST_SUITE(IntVectorTest);
   CPPUNIT_TEST(testException);
   CPPUNIT_TEST(testFound);
   CPPUNIT_TEST(testNotFound);
   CPPUNIT_TEST_SUITE_END();
   void testException();
   void testFound();
   void testNotFound();
};

// This function tests the binary search function to make sure that
// it throws exception on unsorted vectors correctly.
void IntVectorTest::testException()
{
   IntVector v;
   IntVector::size_type index;
   // test it on the boundary case: empty and 1-element vectors
   CPPUNIT_ASSERT_NO_THROW(v.binsearch(10, index));
   v.push_back(0);
   CPPUNIT_ASSERT_NO_THROW(v.binsearch(20, index));
// test it on some sorted vectors
   int v1[] = {1,2,3,4,5,6,7,8};
   int v2[] = {2,2,2,2,2,2,2,2}; // equal elements
   v.resize(8);
   copy(v1, v1+8, v.begin());
   CPPUNIT_ASSERT_NO_THROW(v.binsearch(10, index));


   //here
   CPPUNIT_ASSERT_NO_THROW(v.binsearch(2, index));
   copy(v2, v2+8, v.begin());
   CPPUNIT_ASSERT_NO_THROW(v.binsearch(10, index));
   CPPUNIT_ASSERT_NO_THROW(v.binsearch(2, index));
// test it on some unsorted vectors
   int v3[] = {2, 4, 5, 1, 4, 7, 9, 10};
   int v4[] = {3, 1, 2, 3, 4, 5, 6, 7}; // unsorted at beginning
   int v5[] = {1, 2, 3, 4, 5, 6, 7, 5}; // unsorted at end
   int v6[] = {1, 5, 2, 7, 3, 8, 4, 5}; // random unsorted
   
   copy(v3, v3+8, v.begin());
   CPPUNIT_ASSERT_THROW(v.binsearch(10, index), invalid_argument);
   CPPUNIT_ASSERT_THROW(v.binsearch(2, index), invalid_argument);
   
   copy(v4, v4+8, v.begin());
   CPPUNIT_ASSERT_THROW(v.binsearch(10, index), invalid_argument);
   CPPUNIT_ASSERT_THROW(v.binsearch(2, index), invalid_argument);
   copy(v5, v5+8, v.begin());
   CPPUNIT_ASSERT_THROW(v.binsearch(10, index), invalid_argument);
   CPPUNIT_ASSERT_THROW(v.binsearch(2, index), invalid_argument);
   copy(v6, v6+8, v.begin());
   CPPUNIT_ASSERT_THROW(v.binsearch(10, index), invalid_argument);
   CPPUNIT_ASSERT_THROW(v.binsearch(2, index), invalid_argument);
}

// This function tests the various cases in which the element is found
void IntVectorTest::testFound()
{
// test it on a 1-element vector
   IntVector v;
   IntVector::size_type index;
   v.push_back(10);
   CPPUNIT_ASSERT(v.binsearch(10, index) && index == 0);
// test it on a vector equal elements
   int v1[] = {2,2,2,2,2,2,2,2};
   v.resize(8);
   copy(v1, v1+8, v.begin());
   CPPUNIT_ASSERT(v.binsearch(2, index) && index == 7);
   int v2[] = {2,2,4,4,7,8,9,10};
   copy(v2, v2+8, v.begin());
   CPPUNIT_ASSERT(v.binsearch(4, index) && index == 3);
   // test some random array
   int v3[] = {1, 7, 10, 14, 37, 49, 52, 55};
   copy(v3, v3+8, v.begin());
// search for all elements. Note: this also searches for elements
// that occurs at boundaries.
   for (IntVector::size_type i = 0; i < 8; i++) {
      CPPUNIT_ASSERT(v.binsearch(v3[i], index) && index == i);
   }
}
// This function tests the various cases in which the element is not found
void IntVectorTest::testNotFound()
{
// test it on empty and 1-element vector
   IntVector v;
   IntVector::size_type index;
   CPPUNIT_ASSERT(!v.binsearch(10, index) && index == 0);
   v.push_back(10);
   CPPUNIT_ASSERT(!v.binsearch(9, index) && index == 0);
   CPPUNIT_ASSERT(!v.binsearch(11, index) && index == 1);
   
// test it on a vector equal elements
   int v1[] = {2,2,2,2,2,2,2,2};
   v.resize(8);
   copy(v1, v1+8, v.begin());
   CPPUNIT_ASSERT(!v.binsearch(1, index) && index == 0);
   CPPUNIT_ASSERT(!v.binsearch(3, index) && index == 8);
   
   int v2[] = {2,2,4,4,7,8,9,10};
   copy(v2, v2+8, v.begin());
   CPPUNIT_ASSERT(!v.binsearch(3, index) && index == 2);
   CPPUNIT_ASSERT(!v.binsearch(6, index) && index == 4);
   CPPUNIT_ASSERT(!v.binsearch(-6, index) && index == 0);
   
// test some random array
   int v3[] = {1, 7, 10, 14, 37, 49, 52, 55};
   copy(v3, v3+8, v.begin());
// search for all elements before and after. Note: this also
// searches for elements that occurs at boundaries.
   for (IntVector::size_type i = 0; i < 8; i++) {
      CPPUNIT_ASSERT(!v.binsearch(v3[i]-1, index) && index == i);
      CPPUNIT_ASSERT(!v.binsearch(v3[i]-2, index) && index == i);
      CPPUNIT_ASSERT(!v.binsearch(v3[i]+1, index) && index == i+1);
      CPPUNIT_ASSERT(!v.binsearch(v3[i]+2, index) && index == i+1);
   }
}
int main(void)
{
   CppUnit::TextTestRunner runner;
   runner.addTest(IntVectorTest::suite());
   runner.run();
   return 0;
}
