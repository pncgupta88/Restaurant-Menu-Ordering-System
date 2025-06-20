#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Self_Order
{
public:
    string eating_location;
    double Total_Bill = 0;

    Self_Order()
    {
        cout << "WELCOME TO \"SLAYER'S DEN\" YOUR ALL IN ONE RESTAURANT" << endl;

        cout << "SELECT EATING LOCATION" << endl
             << "(a)IN" << endl
             << "(b)OUT" << endl
             << "ENTER 'IN' OR 'OUT': ";
        cin >> eating_location;

        while (eating_location != "IN" && eating_location != "OUT")
        {
            cout << "INVALID sINPUT! ENTER EATING LOCATION AGAIN: ";
            cin >> eating_location;
        }
        cout << endl;
        cout << "EATING LOCATION SUCESSFULLY SAVED!" << endl;
    }

    void displayMenu()
    {
        ifstream menuFile;
        menuFile.open("newMenu.txt"); 
        if (!menuFile.is_open())
        {
            cout << "Error! could not open menu file." << endl;
            return;
        }

        cout << "\n=============MENU=============\n\n";
        cout << "Id.  item Name       Price(Rs)" << endl << endl;

        string line;
        
        while (getline(menuFile, line))
        {
            cout << line << endl;
        }

        cout << "\n---------------------------\n\n";
        menuFile.close();
    }

    struct Menu_Items
    {
        int item_ID;        
        string item_Name;
        double item_Price;
    };

    struct saveOrder
    {
        string name;
        int quantity;
        double unit_Price;
        double item_Total;
    };
    

    /*This funcn makes copy of item details from menu.txt file
    and stores it in vector menuItems so they can be used to 
    take orders.*/ 
    vector<Menu_Items> copyMenuItems()
    {
        vector<Menu_Items> menuItems;
        ifstream menuFile;
        menuFile.open("newMenu.txt");
        if(!menuFile.is_open()){
            cout << "Error! could not open menu file." << endl;
            return menuItems;
        }

        Menu_Items temp_Item;
        while (menuFile >> temp_Item.item_ID >> temp_Item.item_Name >> temp_Item.item_Price)
        {
            menuItems.push_back(temp_Item);
        }
        menuFile.close();
        return menuItems;        
    }
    
    /*This funcn takes order of customer:
    1) Customer enters item id then the system checks the item id in menu that it is valid or not.
    2) If id is not valid then system asks customer item id again.
    3) If id is valid then system asks for item quantity.
    4) Then it calculate prices and saves item details in vector Ordered_Item for further uses.
    5) After getting details system asks user to order more items or not.*/
    void take_Order()
    {
        vector<Menu_Items> menuItems = copyMenuItems();
        vector<saveOrder> Ordered_Item;

        char add_More = 'y';

        while (add_More == 'y' || add_More == 'Y')
        {
            cout << "Enter the item ID you want to order: ";
            int entered_ID;
            cin >> entered_ID;

            bool valid_item = false;
            Menu_Items selected_item;

            for (int i = 0; i < menuItems.size(); i++)
            {
                if (menuItems[i].item_ID == entered_ID)
                {
                    selected_item = menuItems[i];
                    valid_item = true;
                    break;
                }                
            }

            if (!valid_item)
            {
                cout << "Invalid item ID. Please enter a valid item ID."<<endl;
                continue;
            }
            
            int qty;
            cout << "Enter " << selected_item.item_Name<<" quantity: ";
            cin >> qty;
            cout << endl;
            
            double subtotal = selected_item.item_Price * qty;
            Total_Bill += subtotal;

            saveOrder order;
            order.name = selected_item.item_Name;
            order.quantity = qty;
            order.unit_Price = selected_item.item_Price;
            order.item_Total = subtotal;
            Ordered_Item.push_back(order);

            cout << "Add more items? (y/n): ";
            cin >> add_More;
            cout << endl;
            
        }

        /*After taking order system asks customer to place or cancel the order for confermation
        1) If customer places order then system shows bill to customer and restarts again for next customer.
        2) If customer cancel order the system restares again for next customer.*/

        string confirmation;
        cout << "Enter 'P/p' to place order or 'C/c' to cancel the order: ";
        cin >> confirmation;
        cout << endl;

        if (confirmation == "P" || confirmation == "p")
        {
            cout << "Order Placed Sucessfully. Please wait a while your order is preparing..."<< endl <<endl;
            cout << "============Bill============"<<endl<<endl;
            cout << "        SLAYER'S DEN        "<<endl;
            cout << "|YOUR ALL IN ONE RESTAURANT|"<<endl<<endl;
            for (int i = 0; i < Ordered_Item.size(); i++)
            {
                cout << i+1<<")" <<"Item Name: " << Ordered_Item[i].name << endl;
                cout << "  Item Quantity: "<< Ordered_Item[i].quantity << endl;
                cout << "  Item Unit Price: "<< Ordered_Item[i].unit_Price << endl;
                cout << "  Item Total Price: "<< Ordered_Item[i].item_Total << endl << endl;
            }

            cout << "  Total bill: "<< Total_Bill << endl;
            cout << "  Eating Location: "<< eating_location<<endl;
            cout << "  Thank you! Visit again..."<< endl<<endl;
            cout << "============================="<<endl <<endl;            
        }else
        {
            cout << "Order Cancelled."<<endl << endl;
        }   
        
    }
};

int main()
{
    while (true)
    {
        Self_Order orders;
        orders.displayMenu();
        orders.take_Order();

        cout << "Restarting the system for next customer."<< endl;
        cout << "Restarting..."<< endl << endl;
    }    

    return 0;
}