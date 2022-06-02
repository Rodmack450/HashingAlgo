//
//  Header.h
//  Header
//
//  Created by Rodolphe Nemr on 1/5/22.
//  Using chaining principle

#ifndef Header_h
#define Header_h
using namespace std;

class Hash{

private:
    static const int TableSize = 10;
    
    struct item{
      
        string namePerson;
        string personFavDrink;
        item* next;
        
    };
    
    item* HashTable[TableSize];

public:
    Hash();
    int hash (string key);
    void AddItem(string name, string drink);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
    void FindDrink(string name);
};


#endif /* Header_h */
