//
//  Shape.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018-2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the Shape class below
#include <string>
#include "Shape.h"


Shape::Shape(string n, string t, int x_loc, int y_loc, int x_sz, int y_sz){
    setName(n);
    setType(t);
    setXlocation(x_loc);
    setXsize(x_sz);
    setYlocation(y_loc);
    setYsize(y_sz);
}
    
// Accessors
std::string Shape::getType(){                      // Returns the type
    return type;
}            

std::string Shape::getName(){                     // Returns the name of the shape
    return name;
}             

int Shape::getXlocation(){                  // Returns location of the shape on the x-axis
    return x_location;
}            

int Shape::getYlocation(){                   // Returns location of the shape on the y-axis
    return y_location;
}           

int Shape::getXsize(){                       // Returns the size of the shape in the x-dimension
    return x_size;
}           

int Shape::getYsize(){
    return y_size;                           // Returns the size of the shape in the y-dimension
}               
    
// Mutators
void Shape::setType(string t){              // Sets the type (see globals.h)
    type = t;                               // No error checking done inside the method
    return;                                 // The calling program must ensure the type
}                                           // is correct  
                                                       
                              
void Shape::setName(string n){              // Sets the name of the shape
    name = n;
    return;
}        
void Shape::setXlocation(int x_loc){  // Sets location of the shape on the x-axis
    x_location = x_loc;
    return;
}

void Shape::setYlocation(int y_loc){  // Sets location of the shape on the y-axis
    y_location = y_loc;
    return;
}
void Shape::setXsize(int x_sz){       // Sets size of the shape in the x-dimension
    x_size = x_sz;
    return;
}
void Shape::setYsize(int y_sz){       // Sets size of the shape in the y-dimension
    y_size = y_sz;
    return;
}
    
void Shape::setRotate(int angle){     // sets the rotation of the shape
    rotation = angle;
    return;
}
    
// Utility methods                  // Draws a shape; for this assignment it
void Shape::draw(){                 // only prints the information of the shape
    cout << name << ": " << type << " " << x_location 
         << " " << y_location << " " << x_size << " " 
         << y_size << endl;
    return;
}                 
