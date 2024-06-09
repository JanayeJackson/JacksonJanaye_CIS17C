

/* 
 * File:   main.cpp
 * Author: Nicolai M. Josuttis, Addison-Wesley
 *
 * Created on April 9, 2024, 7:11 PM
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;

int main()
{
    /* create a string set
     * - initialized by all words from standard input
     */
    set<string> coll((istream_iterator<string>(cin)),
                     istream_iterator<string>());

    // print all elements
    copy (coll.begin(), coll.end(),
          ostream_iterator<string>(cout, "\n"));
}