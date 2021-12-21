//
//  parser.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018-2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"

// This is the shape array, to be dynamically allocated
Shape** shapesArray;

// The number of shapes in the database, to be incremented 
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

int checkCommand(string name){
    int commandIndex;
    for (int i = 1; i < 7; i++){
        if (name == keyWordsList[i]){
            commandIndex = i;
            return commandIndex;
        }else{
            commandIndex = 10;
        }
    }
    return commandIndex;
}

int findShape(string name, int maxShapes, Shape* shapesArray[]){
    int shapeLoc;
    for (int i = 0; i < maxShapes; i++){
        if (name == shapesArray[i]->getName()){
            shapeLoc = i;
            return shapeLoc;
        }else
            shapeLoc = 0;
    }   
    return shapeLoc;
}

bool checkReservation(string name){
    bool check = true;
    for (int i = 0; i < 7; i++){
        if (name == keyWordsList[i]){
            check = false;
            return check;
        }else
            check = true;
    }
    for (int i = 0; i < 4; i++){
        if (name == shapeTypesList[i]){
            check = false;
            return check;
        }else
            check = true;
    }
    return check;
}

bool checkNameFind(string name, int maxShapes, Shape** shapesArray){
    bool check = false;
    for (int i = 0; i < maxShapes; i++){
        if (name == shapesArray[i]->getName()){
            check = true;
            return check;
        }else
            check = false;
    }
    return check;
}
bool checkNameCreate(string name, int maxShapes, Shape** shapesArray){
    bool check = true;
    for (int i = 0; i < maxShapes; i++){
        if (name == shapesArray[i]->getName()){
            check = false;
            return check;
        }else
            check = true;
    }
    return check;
}

bool checkType(string type){
    bool check = false;
    for(int i = 0; i < 4; i++){
        if (type == shapeTypesList[i]){
            check = true;
            break;
        }else{
            check = false;
        }
    }
    return check;
}
int main() {

    string line;
    string command;
    cout << "Commands include: all, maxShapes, create, move, rotate, draw, and delete\n";
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream(line);
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;
        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        
        string shapeName;
        string typeName;
        int x_loc;
        int y_loc;
        int x_sz;
        int y_sz;
        int rot;
        
        switch(checkCommand(command)){
            case 1 :
                if(lineStream.peek() == -1){
                    cout << "Error: too few arguments\n";
                    break;
                }else{
                int pre_max_shapes; 
                pre_max_shapes = max_shapes;
                lineStream >> max_shapes;
                if (lineStream.fail()){
                    cout << "Error: invalid argument\n"; 
                    max_shapes = pre_max_shapes;
                    break;
                }else if (max_shapes < 0){
                    cout << "Error: invalid value\n";
                    max_shapes = pre_max_shapes;
                    break;
                }else if (lineStream.peek() == -1){
                    for (int i = 0; i < pre_max_shapes; i++){
                        delete shapesArray[i];
                        shapesArray[i] = NULL;
                        delete [] shapesArray;
                        shapesArray = NULL;
                        shapeCount = 0;
                    }
                    shapesArray = new Shape* [max_shapes];
                    for (int i = 0; i < max_shapes; i++){
                        shapesArray[i] = new Shape("0", "0", 0, 0, 0, 0);
                    }
                    cout << "New database: max shapes is " << max_shapes << endl;
                    break;
                }else {
                    cout << "Error: too many arguments\n";
                    max_shapes = pre_max_shapes;
                    break;
                }
            }
            
            case 2 :
                if(lineStream.peek() == -1){
                    cout << "Error: too few arguments\n";
                    break;
                }else{
                //input shapeName
                    lineStream >> shapeName;
                    if (lineStream.fail()){
                        cout << "Error: invalid argument\n";
                        break;
                    }else if (checkReservation(shapeName) == 0){
                        cout << "Error: invalid shape name\n";
                        break;
                    }else if(checkNameCreate(shapeName, max_shapes, shapesArray) == 0){
                        cout << "Error: shape name exists\n";
                        break;
                    }else if(lineStream.peek() == -1){
                        cout << "Error: too few arguments\n";
                        break;
                    }
                //input typeName;
                    lineStream >> typeName;
                    if (lineStream.fail()){
                        cout << "Error: invalid argument\n";
                        break;
                    }else if(checkType(typeName) == 0){
                        cout << "Error: invalid shape type\n";
                        break;
                    }else if(lineStream.peek() == -1){
                        cout << "Error: too few arguments\n";
                        break;
                    }  
                //input x_loc;
                    lineStream >> x_loc;
                    if (lineStream.fail()){
                        cout << "Error: invalid argument\n";
                        break;
                    }else if(x_loc < 0){
                        cout << "Error: invalid value\n";
                        break;
                    }else if(lineStream.peek() == -1){
                        cout << "Error: too few arguments\n";
                        break;
                    }
                //input y_loc;
                    lineStream >> y_loc;
                    if (lineStream.fail()){
                        cout << "Error: invalid argument\n";
                        break;
                    }else if(y_loc < 0){
                        cout << "Error: invalid value\n";
                        break;
                    }else if(lineStream.peek() == -1){
                        cout << "Error: too few arguments\n";
                        break;
                    }
                //input x_sz;
                    lineStream >> x_sz;
                    if (lineStream.fail()){
                        cout << "Error: invalid argument\n";
                        break;
                    }else if(x_sz < 0){
                        cout << "Error: invalid value\n";
                        break;
                    }else if(lineStream.peek() == -1){
                        cout << "Error: too few arguments\n";
                        break;
                    }
                //input y_sz;
                    lineStream >> y_sz;
                    if (lineStream.fail()){
                        cout << "Error: invalid argument\n";
                            break;
                    }else if(y_sz < 0){
                        cout << "Error: invalid value";
                        break;
                    }else if(lineStream.peek() != -1){
                        cout << "Error: too many arguments\n";
                        break;
                    }else{
                        if((typeName == "circle") && (x_sz != y_sz)){
                            cout << "Error: invalid value\n";
                            break;
                        }else if (shapeCount == max_shapes){
                            cout << "Error: shape array is full\n";
                            break;
                        }else{
                        *shapesArray[shapeCount] = Shape(shapeName, typeName, x_loc, y_loc, x_sz, y_sz);
                        shapeCount = shapeCount + 1;
                         cout << "Created " << shapeName << ": " << typeName << " " << x_loc << " " << y_loc
                        << " " << x_sz << " " << y_sz << endl; 
                         break;
                        }
                    }
                }
       
            
            case 3 :
                if(lineStream.peek() == -1){
                    cout << "Error: too few arguments\n";
                    break;
                }else{
                //input shapeName
                    lineStream >> shapeName;
                    if (lineStream.fail()){
                        cout << "Error: invalid argument\n";
                        break;
                    }else if(checkNameFind(shapeName, max_shapes, shapesArray)==0){
                        cout << "Error: shape " << shapeName << " not found\n";
                        break;
                    }else if(lineStream.peek() == -1){
                        cout << "Error: too few arguments\n";
                        break;
                    }
                //input x_loc
                    lineStream >> x_loc;
                    if (lineStream.fail()){
                        cout << "Error: invalid argument\n";
                        break;
                    }else if(x_loc < 0){
                        cout << "Error: invalid value\n";
                        break;
                    }else if(lineStream.peek() == -1){
                        cout << "Error: too few arguments\n";
                        break;
                    }
                //input y_loc    
                    lineStream >> y_loc;
                    if (lineStream.fail()){
                        cout << "Error: invalid argument\n";
                        break;
                    }else if(y_loc < 0){
                        cout << "Error: invalid value\n";
                        break;
                    }else if(lineStream.peek() != -1){
                        cout << "Error: too many arguments\n";
                        break;
                    }else{
                        shapesArray[findShape(shapeName, max_shapes, shapesArray)]->setXlocation(x_loc);
                        shapesArray[findShape(shapeName, max_shapes, shapesArray)]->setYlocation(y_loc);
                        cout << "Moved " << shapeName << " to " << x_loc << " " << y_loc << endl;
                        break;
                    }
                }
            
            
            case 4:
                if(lineStream.peek() == -1){
                    cout << "Error: too few arguments\n";
                    break;
                }else{
                //input shapeName
                    lineStream >> shapeName;
                    if (lineStream.fail()){
                        cout << "Error: invalid argument\n";
                        break;
                    }else if(checkNameFind(shapeName, max_shapes, shapesArray) == 0){
                        cout << "Error: shape " << shapeName << " not found\n";
                        break;
                    }else if(lineStream.peek() == -1){
                        cout << "Error: too few arguments\n";
                        break;
                    }  
                //input rot;
                    lineStream >> rot;
                    if (lineStream.fail()){
                        cout << "Error: invalid argument\n";
                        break;
                    }else if(rot < 0 || 360 < rot){
                        cout << "Error: invalid value\n";
                        break;
                    }else if(lineStream.peek() != -1){
                        cout << "Error: too many arguments\n";
                        break;
                    }else{
                        shapesArray[findShape(shapeName, max_shapes, shapesArray)]->setRotate(rot);
                        cout << "Rotated " << shapeName << " by " << rot << " degrees\n";
                        break;
                    }
                }
            case 5:
                if(lineStream.peek() == -1){
                    cout << "Error: too few arguments\n";
                    break;
                }else{
                //input shapeName;
                lineStream >> shapeName;
                    if(shapeName == "all"){
                        if (lineStream.peek() != -1){
                            cout << "Error: too many arguments\n";
                            break;
                        }else{
                            cout << "Drew all shapes \n";
                            for(int i = 0; i < shapeCount; i++){
                                cout << shapesArray[i]->getName() << ": "
                                     << shapesArray[i]->getType() << " "
                                     << shapesArray[i]->getXlocation() << " "
                                     << shapesArray[i]->getYlocation() << " "
                                     << shapesArray[i]->getXsize() << " "
                                     << shapesArray[i]->getYsize() << endl;
                            }
                            break;
                        } 
                    }else if (checkNameFind(shapeName, max_shapes, shapesArray)){
                        if (lineStream.peek() != -1){
                            cout << "Error: too many arguments\n";
                            break;
                        }else{
                            cout <<"Drew "
                            << shapesArray[findShape(shapeName, max_shapes, shapesArray)]->getName() << ": "
                            << shapesArray[findShape(shapeName, max_shapes, shapesArray)]->getType() << " "
                            << shapesArray[findShape(shapeName, max_shapes, shapesArray)]->getXlocation() << " "
                            << shapesArray[findShape(shapeName, max_shapes, shapesArray)]->getYlocation() << " "
                            << shapesArray[findShape(shapeName, max_shapes, shapesArray)]->getXsize() << " "
                            << shapesArray[findShape(shapeName, max_shapes, shapesArray)]->getYsize() << endl;
                            break;
                        }
                    }else if (lineStream.fail()){
                        cout << "Error: invalid argument\n";
                        break;
                    }else if(checkNameFind(shapeName, max_shapes, shapesArray) == 0){
                        cout << "Error: shape " << shapeName << " not found\n";
                        break;
                    }
                }
            case 6:
                if(lineStream.peek() == -1){
                    cout << "Error: too few arguments\n";
                    break;
                }else{
                //input shapeName;
                lineStream >> shapeName;
                    if(shapeName == "all"){
                        if (lineStream.peek() != -1){
                            cout << "Error: too many arguments\n";
                            break;
                        }else{
                            cout << "Deleted: all shapes \n";
                            for(int i = 0; i < max_shapes; i++){
                                delete shapesArray[i];
                            }
                            shapeCount = 0;
                            break;
                        } 
                    }else if (checkNameFind(shapeName, max_shapes, shapesArray)){
                        if (lineStream.peek() != -1){
                            cout << "Error: too many arguments\n";
                            break;
                        }else{
                            cout <<"Deleted shape "<< shapeName << endl;
                            delete shapesArray[findShape(shapeName, max_shapes, shapesArray)];
                            shapeCount = shapeCount - 1;
                            break;
                        }
                    }else if (lineStream.fail()){
                        cout << "Error: invalid argument\n";
                        break;
                    }else if(checkNameFind(shapeName, max_shapes, shapesArray) == 0){
                        cout << "Error: shape " << shapeName << " not found\n";
                        break;
                    }
                }
               
            default:
                cout << "Error: invalid command\n";
                break;
        }
            
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    return 0;
}

