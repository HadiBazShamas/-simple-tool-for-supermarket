#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED
#include <string>
#include "product.h"
using namespace std;

class inventory
{
public:
	inventory();
	void removeProduct(int id);
	void add(Product& a);
	int getNewID();
	int getProductCount(int id);
	int getUnitCount();
	float getInventoryValue();
	void ClearInventory();
private:
	Product* list[1000];
	int size;
	void Load(ifstream& infile);
	void Save(ofstream& outfile);

};


#endif // INVENTORY_H_INCLUDED
