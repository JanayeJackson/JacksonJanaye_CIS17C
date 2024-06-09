/* 
 * File:   LnkdLst.cpp
 * Author: nayen
 *
 * Created on April 21, 2024, 5:17 PM
 */

#include <cstdlib>
#include "LnkdLst.h"

using namespace std;

LnkdLst::~LnkdLst(){
    //Delete all the allocated memory
    destroy();
}

void LnkdLst::fillLst(int n){
    //Initially create the front pointer/beginning pointer
    Link *front=new Link;
    front->data=1;
    front->lnkNext=NULL;
    front->lnkPvs = NULL;
    //If n>1 then fill with the data and links to the next
    Link *temp=front;
    for(int i=2;i<=n;i++){
        Link *nxtLink=new Link;
        nxtLink->data=i;
        temp->lnkNext=nxtLink;
        temp=nxtLink;
    }
    temp->lnkNext=NULL;
    //Return the front of the list
    lnk1=front;
    
}

void LnkdLst::prntLst(){
    Link *temp = lnk1;
    
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->lnkNext;
    }
}

void LnkdLst::destroy(){
    while(lnk1!=NULL){
        Link *temp=lnk1;
        lnk1=lnk1->lnkNext;
        delete temp;
    }
}
//Create a Link with Data
//Link *create(int){
    
//} 

//Push a link to the front
void LnkdLst::pshFrnt(Link *link){
     //Initially create the front pointer/beginning pointer
    Link *front=link;
    
    //If n!=0 then fill with the data and links to the next
    Link *temp=front;
    while(lnk1!=NULL){
        Link *nxtLink=lnk1;
        temp->lnkNext=nxtLink;
        temp=nxtLink;
        lnk1=lnk1->lnkNext;
    }
    temp->lnkNext=NULL;
    
    //Return the front of the list
    lnk1=front;
}

//Push a link to the end
void LnkdLst::pshBack(Link * link){
    //Initially create the front pointer/beginning pointer
    Link *front=lnk1;
    
    //If link empty then fill with the link and links to null
    Link *temp=front;
    lnk1 = lnk1->lnkNext;
    while(lnk1!=NULL){
        Link *nxtLink=lnk1;
        temp->lnkNext=nxtLink;
        temp=nxtLink;
        lnk1 = lnk1->lnkNext;
    }
    temp->lnkNext=link;
    temp = link;
    temp->lnkNext = NULL;
    
    //Return the front of the list
    lnk1=front;
}

//Pull/pop a link from the front
Link * LnkdLst::popFrnt(){
    //Initially create the front pointer/beginning pointer and return value
    Link *remove = lnk1;
    lnk1 = lnk1->lnkNext;
    Link *front = lnk1;
    
    //If link empty then remove nothing
    Link *temp = front;
    lnk1 = lnk1->lnkNext;
    while(lnk1!=NULL){
        Link *nxtLink=lnk1;
        temp->lnkNext=nxtLink;
        temp=nxtLink;
        lnk1 = lnk1->lnkNext;
    }
    temp->lnkNext = NULL;
    
    //set link to the front of the list
    lnk1=front;
    //return removed link
    return remove;
    
}  

//Pull/pop a link from the back
Link * LnkdLst::popBack(){
    //Initially create the front pointer/beginning pointer
    Link *front=lnk1;
    Link *remove;
    
    //If link empty then pop nothing
    Link *temp=front;
    lnk1 = lnk1->lnkNext;
    while(lnk1->lnkNext!=NULL){
        Link *nxtLink=lnk1;
        temp->lnkNext=nxtLink;
        temp=nxtLink;
        lnk1 = lnk1->lnkNext;
    }
    remove = temp->lnkNext;
    temp->lnkNext = NULL;
    
    //Return the front of the list
    lnk1=front;
    
    return remove;
    
}    

LnkdLst::LnkdLst(){
    int num;
    cout<<"How many elements do you want in your list:";
    cin>>num;
    fillLst(num);
}
