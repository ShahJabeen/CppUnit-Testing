//MAIN.CC

#include <iostream>
#include "IntVector.h"

int main(void)
{
  int x;
IntVector v;
while (cin >> x) {
IntVector::size_type index;
try {
if (!v.binsearch(x, index)) {
v.insert(v.begin()+index, x);
}
cout << "List:";
for (IntVector::size_type i = 0; i < v.size(); i++)
 {
cout << " " << v[i];
if (i == index) {
cout << "*";
}
}
cout << endl;
}
catch (invalid_argument &e) {
cout << "Programming error: " << e.what() << endl;
cout << "Continuing." << endl;
}
}
return 0;
}
