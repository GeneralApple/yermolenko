//
//  main.cpp
//  Vector
//
//  Created by Mykhailo Nehelia on 05.12.17.
//  Copyright © 2017 Mykhailo Nehelia. All rights reserved.
//
#include <iostream>
#include "vector.h"

using namespace std;


int main(){
    //Create new vector
    Vector<double> vector;
    
    //Create vector of 10 elements from 0 to 9
    for(int i=0; i < 10; i++) {
        vector.push(i);
    }
    
    //Print created vector
    for(int i=0; i< vector.getLength(); i++) {
        cout << vector.getElementByIndex(i) << " ";
    }
    
    cout << "Vector length: " << vector.getLength() << endl;
    cout << "Element at index=5: " << vector.getElementByIndex(5) << endl;
    
    //If index is out of range getElementByIndex() returns false
    if(!vector.getElementByIndex(55))
        cout << "Element at index=55 does not exit " << endl;
    
    
    return 0;
}

