/* 
 * File:   LnkdLst.h
 * Author: Janaye Jackson
 *
 * Created on April 21, 2024, 5:17 PM
 */

#ifndef LNKDLST_H
#define LNKDLST_H

#include<iostream>
#include <cstdlib>     //NULL pointer

#include "Link.h"

class LnkdLst{
private:
    Link *lnk1;
    
public:
    LnkdLst();   //constructor
    ~LnkdLst();  //deconstructor
    void fillLst(int);
    void prntLst();
    void destroy();

    //Prototype function you are to consider for Wednesday
    Link *create(int);    //Create a Link with Data
    void pshFrnt(Link *); //Push a link to the front
    void pshBack(Link *); //Push a link to the end
    Link *popFrnt();      //Pull/pop a link from the front
    Link *popBack();      //Pull/pop a link from the back
};


#endif /* LNKDLST_H */

