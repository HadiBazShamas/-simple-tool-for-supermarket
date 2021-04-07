#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
#include <string>
using namespace std;
class Product
{
    public:

	Product();
	string getName();
	int getID();
	int getQuantity();
	int getShelf();
	char getBlock();
	char getType();
	int getAmount();
	double getPPA();
	bool getSituation();
	void setPPA(double p);
	void setName(string S);
	void setID(int i);
	void setQuantity(int Q);
	void setType(char t);
	void setAmount(int a);
	void setSituation(bool s);
	void locate(char b, int s);
	bool is();           //if the product is flammable or is fragile return true else return false, according to the type
	double CalculateTotalPrice();   //return the total price of the product

    private:
	string name;
	int ID;
	int quantity;
	char block; //the block is a character, can be A, B, C
	int shelf;
	char type;    //if 'L' the product is liquid , if 'S' the product is Solid
	int amount;   //if the product is liquid then the amount is in littres else it is the number of pieces
	double ppa;   //price per littres for liquids and per piece for solids
	bool situation;  //if the product is liquid then the situation is true if flammable and false if not flammable
					 //if the product is solid the situation is true if fragile and false if not


};


#endif // PRODUCT_H_INCLUDED
