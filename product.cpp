#include "product.h"
#include <string>
#include <iostream>
#include<istream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

string Product::getName()
{
    return name;
}

int Product::getID()
{
    return ID;
}

int Product::getQuantity()
{
    return quantity;
}

int Product::getShelf()
{
    return shelf;
}

char Product::getBlock()
{
    return block;
}

char Product::getType()
{
    return type;
}

int Product::getAmount()
{
    return amount;
}

double Product::getPPA()
{
    return ppa;
}

bool Product::getSituation()
{
    return situation;
}

void Product::setName(string S)
{
    name = S;
}

void Product::setID(int i)
{
    ID = i;
}

void Product::setQuantity(int Q)
{
    quantity = Q;
}

void Product::setType(char t)
{
    type = t;
}

void Product::setAmount(int a)
{
    amount = a;
}

void Product::setPPA(double p)
{
    ppa = p;
}

void Product::setSituation(bool s)
{
    situation = s;
}

void Product::locate(char b, int s)
{
    block = b;
    shelf = s;
}

bool Product::is()
{
    if (situation == 1) return 1;
    else return 0;
}

double Product::CalculateTotalPrice()
{
    return ppa * amount;
}


Product::Product()
{
    name = " ";
    ID = 0;
    quantity = 0;
    block = ' ';
    shelf = -1;
    type = ' ';
    amount = 0;
    ppa = 0;
    situation = 0;
}

