#include <iostream>
#include <fstream>

using namespace std;

class Shop
{
private:                                          //Encapsulation : data hiding 
	string username, password;
	string product, brand, size, gender, color, discount;
	int reference_num, quantity, price;

public:
	
	void Products();
	void Identity();
    void Table();
	void List();
	void Range();
};

void Identity() // Identity of the user to access the system
{
	string username;
	string password;
	system("CLS");
	while (1)
	{
		cout << "\n\t\t\t**************************\n";
		cout << "\n\t\t\t* 1.LOG IN               *\n ";
		cout << "\n\t\t\t* * * * * * * * * * * * * * ";
		cout << "\n\t\t\t  1. Enter the username : ";
		cin >> username;
		cout << "\n\t\t\t  2. Enter the password : ";
		cin >> password;
		cout << "\n\t\t\t* * * * * * * * * * * *\n";
		if (username == "admin" && password == "basicsop")
		{
			cout << "\n\t\t\t Username and password are corrects" << endl;
			break;
		}
		else
		{
			cout << "\n\t\t\t WRONG username/password. Please try again.\n";
		}
	}
}



void Shop::Products() // enter a new product to the database
{
	system("CLS");
	cout << "\n\t\t\t* * * * * * * * * * * * * *\n";
	cout << "\n\t\t\t* Add the product         *\n";
	cout << "\n\t\t\t* * * * * * * * * * * * * *\n";
	cout << "Enter the product :\n";   // 
	cin >> product;
	cout << "Enter the brand :\n";   // 
	cin >> brand;
	cout << "Enter the size :\n";   // 
	cin >> size;
	cout << "Enter the gender :\n";   //  
	cin >> gender;
	cout << "Enter the color :\n"; // LOG IN 
	cin >> color;
	try                                  // Exception handling : it doesn't accept unlogic inputs: 
	{                                    //       negative integers for our case
		cout << "Enter the price :\n";   
		cin >> price;
		if (price < 0)                              // the price cannnot be negative
			throw price;
	}
	catch (int price)
	{
		cout << "Negative input! Try again with a positive input" << endl;
		cin >> price;
	}
	try
	{
		cout << "Enter the reference number:\n";   // the reference number cannnot be negative
		cin >> reference_num;
		if (reference_num < 0)
			throw reference_num;
	}
	catch (int reference_num)
	{
		cout << "Negative input! Try again with a positive input" << endl;
		cin >> reference_num;
	}

	try
	{
		cout << "Enter the quantity :\n";   // the quantity cannnot be negative
		cin >> quantity;
		if (quantity < 0)
			throw quantity;
	}
	catch (int quantity)
	{
		cout << "Negative input! Try again with a positive input" << endl;
		cin >> quantity;
	}

	cout << "Discount availability :\n";   // 
	cin >> discount;
	system("CLS");
	cout << "\n \t\t\t **All details are saved** \n";
	cout << "\n";

}

void Shop::Table() // display the saved items in the database
{
	system("CLS");
	cout << "Product" << "\t" << "Brand" << "\t" << "Size" << "\t" << "Gender" << "\t" << "Color" << "\t" << "Price" << "\t" << "Reference number" << "\t" << "Quantity" << "\t" << "Discount";
	cout << "\n";
	cout << product << "\t" << brand << "\t" << size << "\t" << gender << "\t" << color << "\t" << price << "\t" << reference_num << "\t\t\t" << quantity << "\t\t" << discount;
	cout << "\n";

	ofstream File;                  //     File handling contains the saved items in the database
	File.open("items.txt");
	File << "Product" << "\t" << "Brand" << "\t" << "Size" << "\t" << "Gender" << "\t" << "Color" << "\t" << "Price" << "\t" << "Reference number" << "\t" << "Quantity" << "\t" << "Discount\n";
	File << product << "\t" << brand << "\t" << size << "\t" << gender << "\t" << color << "\t" << price << "\t" << reference_num << "\t\t\t" << quantity << "\t\t" << discount;
	File.close();
}


void Shop::Range() // dynamic memory management : allocate an array 
{                            
	int num_prod;
	int temp;
	cout << "Enter the number of products:";
	cin >> num_prod;
	int* price = new int[num_prod];

	for (int i = 0; i < num_prod; i++)
	{
			cout << "price [" << i << "]";
			cin >> price[i];
}

	for (int i = 0; i < num_prod; i++) {                   // displaying the prices in acsending order 
		for (int j = 1 + i; j < num_prod; j++) {
			if (price[i] > price[j]) {
				temp = price[i];
				price[i] = price[j];
				price[j] = temp;
			}
		}
	}
	cout << "The prices are between : \n";
	for (int i = 0; i < num_prod; i++)
	{
		cout << price[i] << " ";
	}
			}

void Shop::List()           // List contains all our functions that we can use 
{                            //    press each suitable number for every function to open them.
ListStart:
	int a;
	cout << "\n";
	cout << "\n\t\t\t* * * * * * * * * * * * * * * * *\n";
	cout << "\n\t\t\t* 1.LIST                        *\n";
	cout << "\n\t\t\t* * * * * * * * * * * * * * * * *\n\n";
	cout << "\n\t\t\t  1. Add a new product : ";
	cout << "\n\t\t\t  2. Show available products: ";
	cout << "\n\t\t\t  3. Show range of prices  : ";
	cout << "\n\t\t\t  4.Exit  : ";
	cout << "\n\t\t\t* * * * * * * * * * * * * * * * *\n";
	cout << "\n\t\t\t  Enter your choice : ";
	cin >> a;
	switch (a)
	{
	case 1: Products();
		break;
	case 2: Table();
		break;
	case 3: Range();
		break;
	case 4: exit(0);
		break;

	default:
		cout << "\n\t\t\t  Try again ";
		break;
	}
	goto ListStart;
}

	
int main()
{
	int choice;
	char  username[15];
	char password[15];
	cout << "\n\t\t\t* * * * * * * * * * * * * *\n";
	cout << "\n\t\t\t* CLOTHING SHOP MANAGEMENT Database  *\n";
	cout << "\n\t\t\t* * * * * * * * * * * * * *\n\n";
	cout << "\n\t\t\t  1. LOG IN";
	cout << "\n\t\t\t  2. EXIT";
	cout << "\n\t\t\t* * * * * * * * * * * * * *\n";
	cout << "\n\t\t\t Enter Your choice: ";
	cin >> choice;
	switch (choice) {
	case 1:
		Identity();
		break;
	case 2:
		exit(0);
		break;
	}
	
	system("CLS");
	Shop Management;
	Management.List();
	Management.Table();


        return 0;
	}

