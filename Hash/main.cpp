//
//  main.cpp
//  Hash
//
//  Created by Rodolphe Nemr on 1/5/22.
//  Using chaining principle


#include <iostream>
#include "Header.h"
using namespace std;

int main(){
  
    Hash obj;
    obj.PrintTable();
    obj.AddItem("Rodmack", "Cola");
    obj.AddItem("Rodmack", "Cola");
    
    return 0;
}
