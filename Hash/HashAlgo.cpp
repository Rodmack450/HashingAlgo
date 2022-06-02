//
//  HashAlgo.cpp
//  HashAlgo
//
//  Created by Rodolphe Nemr on 1/5/22.
//  Using chaining principle


#include "HashAlgo.hpp"
#include <iostream>
#include "Header.h"
using namespace std;

//Constructor
Hash::Hash(){
    //Initilise a constructor, how it looks like
    for(int i=0;i<TableSize;i++){
        HashTable[i] = new item;
        HashTable[i]->namePerson = "empty";
        HashTable[i]->personFavDrink = "empty";
        HashTable[i]->next = NULL;
    }
}


//add some items to the hashtbale
void Hash::AddItem(string name, string drink){
    //pass name in  the hash function
    int index = hash(name);
    
    //we have an index now so in the hashtable check if where is empty overwrite it
    if(HashTable[index]->namePerson == "empty"){
        HashTable[index]->namePerson = name;
        HashTable[index]->personFavDrink = drink;
        
    }
    
    else{
        item* Ptr = HashTable[index];
        item* n = new item;
        n->namePerson = name;
        n->personFavDrink = drink;
        n->next = NULL;
        
        while(Ptr != NULL){
            Ptr= Ptr->next;
        }
        Ptr->next = n;
    }
    
}

int Hash::NumberOfItemsInIndex(int index){
    
    int count = 0;
    
    if(HashTable[index]->namePerson == "empty"){
        return count;
    }
    
    else{
        count++;
     
        item *Ptr = HashTable[index];
        while (Ptr != NULL) {
            count++;
            Ptr = Ptr->next;
        }
    }
    return count;
}

void Hash::PrintTable(){
    
    int nbr;
    for(int i=0;i<TableSize;i++){
        nbr = NumberOfItemsInIndex(i);
        cout<<"----------\n";
        cout<<"index: "<<i<<endl;
        cout<<HashTable[i]->namePerson<<endl;
        cout<<HashTable[i]->personFavDrink<<endl;
        cout<<nbr<<endl;
        cout<<"----------\n";

    }
}

void Hash::PrintItemsInIndex(int index){
    item* Ptr = HashTable[index];

    if(Ptr->namePerson == "empty"){

        cout<<"Empty in this index"<<endl;

    }
    
    else{
        cout<<"Contains the following"<<endl;
       
        while(Ptr != NULL){
            cout<< Ptr->namePerson<<endl;
            cout<< Ptr->personFavDrink<<endl;

            Ptr = Ptr->next;
            
        }
    }
}

void Hash::FindDrink(string name){
    int index = hash(name);
    bool FoundName = false;
    string drink;
    
    item* Ptr = HashTable[index];
    
    
    
}

int Hash::hash(string key){
    
    int hash = 0;
    int index;
    
        
    for(int i=0;i<key.length();i++){
        hash = hash+(int)key[i];
    }
    
    //the hash we got modulos tablesize in the constructor :D
    index = hash % TableSize;
    
//    ASCII Code
//    cout<<"Key 0" << (int) key[0] << endl;
//    cout<<"Key 1" << (int) key[1] << endl;
//    cout<<"Key 2" << (int) key[2] << endl;
//    cout<<"Key 3" << (int) key[3] << endl;

    
    
    return index;
    
}

