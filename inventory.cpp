#include "inventory.h"
#include "product.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;


void inventory::Load(ifstream& infile)
{
    size = 0;
    int id, quantity, shelf, amount;
    char type, block;
    string name;
    double ppa;
    bool situation;
    while (!infile.eof()) {
        infile >> name;
        infile >> id;
        infile >> quantity;
        infile >> block;
        infile >> shelf;
        infile >> type;
        infile >> ppa;
        infile >> amount;
        infile >> situation;
        list[size]->setName(name);
        list[size]->setID(id);
        list[size]->setQuantity(quantity);
        list[size]->locate(block, shelf);
        list[size]->setPPA(ppa);
        list[size]->setAmount(amount);
        list[size]->setSituation(situation);
        size++;
    }
    infile.close();
}


void inventory::Save(ofstream& outfile)
{
    int i = 0;
    for ( i = 0; i < size; i++)
    {
        outfile << list[i]->getID() << " ";
        outfile << list[i]->getQuantity() << " ";
        outfile << list[i]->getBlock() << " ";
        outfile << list[i]->getShelf() << " ";
        outfile << list[i]->getType() << " ";
        outfile << list[i]->getPPA() << " ";
        outfile << list[i]->getAmount() << " ";
        outfile << list[i]->getSituation() << endl;
    }
    outfile.close();
}


void inventory::removeProduct(int id)
{
    int i, index = -1;
    for (i = 0; i < size; i++) {
        if (list[i]->getID() == id) {
            index = i;
        }
    }
    if (index == -1) {
        cout << "Not Found" << endl;
        return;
    }
    else {
        for (i = index; i < size; i++) {
            list[i] = list[i + 1];
        }
        size--;
    }
}

void inventory::add(Product& A)
{
    
    list[size]->setName(A.getName());
    list[size]->setID(A.getID());
    list[size]->setQuantity(A.getQuantity());
    list[size]->locate(A.getBlock(), A.getShelf());
    list[size]->setType(A.getType());
    list[size]->setPPA(A.getPPA());
    list[size]->setAmount(A.getAmount());
    list[size]->setSituation(A.getSituation());
    size++;
}

int inventory::getNewID()
{
    int ID;   int i = 0;
    ID = rand();
    for (i = 0; i < size ; i++)
    {
        if (list[i]->getID() == ID)
        {
            ID = rand();
            i = 0;
            continue;
        }
        else  continue;
    }return ID;
}



int inventory::getProductCount(int Id)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (list[i]->getID() == Id) return list[i]->getQuantity();
        continue;

    } return -1;
}



int inventory::getUnitCount()
{
    int a = 0, i;

    for (i = 0; i < size; i++)
    {
        a += list[i]->getQuantity();
    }return a;
}



float inventory::getInventoryValue()
{
    int a = 0, i;
    for (i = 0; i < size; i++)
    {
        a += list[i]->getQuantity() * list[i]->CalculateTotalPrice();
    }return a;
}


void inventory::ClearInventory()
{
    delete[]list;
}
