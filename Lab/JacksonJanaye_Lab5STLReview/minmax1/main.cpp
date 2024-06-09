
/* 
 * File:   main.cpp
 * Author: Nicolai M. Josuttis, Addison-Wesley
 *
 * Created on April 9, 2024, 7:12 PM
 */

#include <cstdlib>
#include "algostuff.hpp"
using namespace std;

bool absLess (int elem1, int elem2)
{
    return abs(elem1) < abs(elem2);
}

int main()
{
    deque<int> coll;

    INSERT_ELEMENTS(coll,2,8);
    INSERT_ELEMENTS(coll,-3,5);

    PRINT_ELEMENTS(coll);

    // process and print minimum and maximum
    cout << "minimum: "
         << *min_element(coll.begin(),coll.end())
         << endl;
    cout << "maximum: "
         << *max_element(coll.begin(),coll.end())
         << endl;

    // process and print minimum and maximum of absolute values
    cout << "minimum of absolute values: "
         << *min_element(coll.begin(),coll.end(),
                         absLess)
         << endl;
    cout << "maximum of absolute values: "
         << *max_element(coll.begin(),coll.end(),
                         absLess)
         << endl;
}