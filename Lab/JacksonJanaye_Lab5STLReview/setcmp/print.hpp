
/* 
 * File:   print.hpp
 * Author: Nicolai M. Josuttis, Addison-Wesley
 *
 * Created on April 9, 2024, 7:06 PM
 */

#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>

/* PRINT_ELEMENTS()
 * - prints optional C-string optcstr followed by
 * - all elements of the collection coll
 * - separated by spaces
 */
template <class T>
inline void PRINT_ELEMENTS (const T& coll, const char* optcstr="")
{
    typename T::const_iterator pos;

    std::cout << optcstr;
    for (pos=coll.begin(); pos!=coll.end(); ++pos) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}



#endif /* PRINT_HPP */

