#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <climits>

using namespace std;

class RMOS
{
private:
    int first_choice;
    int insidefirst_choice;
    static int order_no;

public:
    RMOS()
    {
        cout << endl;
        cout << "|| WELCOME TO RESTAURANT MENU ORDERING SYSTEM ||" << endl
             << endl;
        cout << "CHOOSE AN OPTION:" << endl
             << "1) EDIT MENU." << endl
             << "2) VIEW MENU AND PLACE ORDER." << endl
             << "3) EXIT." << endl
             << endl;
        cout << "ENTER 1/2/3: ";

        while (!(cin >> first_choice) || (first_choice != 1 && first_choice != 2 && first_choice != 3))
        {
            cout << "INVALID INPUT! ENTER 1/2/3: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (first_choice == 1)
        {
            if (!verify_security_pass())
            {
                return;
            }
            else
            {
                cout << endl
                     << "CORRECT SECURITY PASS. YOU CAN ACCESS THIS FEATURE." << endl;
                cout << endl
                     << "SELECT WHAT YOU WANT TO EDIT IN MENU:" << endl;
                cout << "1) ADD AN ITEM." << endl;
                cout << "2) DELETE AN ITEM.(INCOMPLETE! NOT WORKING)" << endl;
                cout << "3) EDIT AN ITEM.(INCOMPLETE! NOT WORKING)" << endl;
                cout << "4) RETURN." << endl
                     << endl;
                cout << "ENTER 1/2/3/4: ";

                while (!(cin >> insidefirst_choice) || (insidefirst_choice != 1 && insidefirst_choice != 4)) //&& insidefirst_choice != 2 && insidefirst_choice != 3))
                {
                    cout << "INVALID INPUT! ENTER 1/2/3: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                if (insidefirst_choice == 1)
                {
                    char addmore = 'Y';

                    while (addmore == 'Y' || addmore == 'y')
                    {
                        cout << endl
                             << "ENTER NEW ITEM DETAILS" << endl
                             << endl;
                        add_newitem();
                        cout << endl
                             << "SUCESSFULLY ADDED NEW ITEM TO MENU." << endl
                             << endl;

                        cout << "DO YOU WANT TO ADD MORE ITEMS. ENTER Y/y FOR 'YES' OR N/n FOR 'NO': ";
                        while (!(cin >> addmore) || (addmore != 'y' && addmore != 'Y' && addmore != 'n' && addmore != 'N'))
                        {
                            cout << "INVALID INPUT! ENTER Y/y FOR 'YES' OR N/n FOR 'NO': ";
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }

                        if (addmore == 'N' || addmore == 'n')
                        {
                            cout << endl
                                 << "THANK YOU! FOR USING OUR SYSTEM. VISIT AGAIN BYII..." << endl
                                 << endl;
                        }
                    }
                }
                else if (insidefirst_choice == 4)
                {
                    return;
                }
            }
        }
        else if (first_choice == 2)
        {
            display_menu();

            cout << endl
                 << "PLACE YOUR ORDER: " << endl
                 << endl;
            take_order();
        }
        else if (first_choice == 3)
        {
            if (!verify_security_pass())
            {
                return;
            }
            else
            {
                cout << endl
                     << "EXITING..." << endl;
                exit(0);
            }
        }
    }

    bool verify_security_pass()
    {
        const int security_pass = 246810;
        int entered_pass;
        int i = 1; // ATTEMPT

        cout << endl
             << "ENTER SECURITY PASS TO ACCESS THIS FEATURE (ATTEMPT-" << i << " OF 3): ";
        while (!(cin >> entered_pass) || (entered_pass != security_pass))
        {
            cin.clear();
            cin.ignore(10000, '\n');

            i++;
            if (i > 3)
            {
                cout << endl
                     << "ATTEMPTS OVER.";
                return false;
            }

            cout << "INCORRECT SECURITY PASS! ENTER CORRECT SECURITY PASS TO ACCESS THIS FEATURE (ATTEMPT-" << i << " OF 3): ";
        }

        return true;
    }

    int auto_assign_new_itemID()
    {
        ifstream menu;
        menu.open("MENU.txt");
        int id;
        int max_id = 0;
        string name;
        double price;

        while (menu >> id >> name >> price)
        {
            if (id > max_id)
            {
                max_id = id;
            }
        }

        int new_id = max_id + 1;
        return new_id;
    }
    bool check_duplicate(const string &new_itemname)
    {
        ifstream menu;
        menu.open("MENU.txt");

        int id;
        string name;
        double price;

        while (menu >> id >> name >> price)
        {
            if (name == new_itemname)
            {
                return true;
            }
        }
        return false;
    }
    void add_newitem()
    {
        ofstream add("MENU.txt", ios::app);

        int new_itemid = auto_assign_new_itemID();
        string new_itemname;
        double new_itemprice;

        cout << "SYSTEM WILL ASSIGN ID TO NEW ITEM AUTOMATICALLY " << endl;

        while (true)
        {
            cout << "ENTER NEW ITEM'S NAME: ";
            cin >> new_itemname;

            if (check_duplicate(new_itemname))
            {
                cout << endl
                     << "ITEM ALREADY EXISTS IN MENU!" << endl
                     << endl;
            }
            else
            {
                break;
            }
        }

        cout << "ENTER NEW ITEM'S PRICE: ";
        cin >> new_itemprice;
        add << new_itemid << "   " << new_itemname << "        " << new_itemprice << endl;
    }

    // void delete_item()
    // {

    // }

    void display_menu()
    {
        ifstream item_menu;
        item_menu.open("MENU.txt");

        cout << "\n=============MENU=============\n\n";
        cout << "Id.  item Name       Price(Rs)" << endl
             << endl;

        string line;

        while (getline(item_menu, line))
        {
            cout << line << endl;
        }

        cout << "\n---------------------------\n\n";

        item_menu.close();
    }
    struct usable_menu
    {
        int item_id;
        string item_name;
        double item_price;
    };
    struct save_order
    {
        int save_id;
        string save_name;
        int save_qty;
        double save_unitprice;
        double save_itemtotal;
    };
    vector<usable_menu> copymenuitems()
    {
        vector<usable_menu> menutotakeorder;
        ifstream menu;
        menu.open("MENU.txt");

        usable_menu temp;
        while (menu >> temp.item_id >> temp.item_name >> temp.item_price)
        {
            menutotakeorder.push_back(temp);
        }
        menu.close();
        return menutotakeorder;
    }

    // int RMOS:: order_no = 0;

    void take_order()
    {
        vector<usable_menu> menu = copymenuitems();
        vector<save_order> order_details;

        char order_more = 'Y';
        double subtotal = 0;
        double total = 0;
        time_t now = time(0);
        tm *localTime = localtime(&now);

        string eating_location;
        cout << "ENTER EATING LOCATION. ENTER 'IN' FOR EAT IN OR 'OUT' FOR EAT OUT: ";
        while (!(cin >> eating_location) || (eating_location != "IN" && eating_location != "in" && eating_location != "OUT" && eating_location != "out"))
        {
            cout << "INVALID! EATING LOCATION.ENTER 'IN' FOR EAT IN OR 'OUT' FOR EAT OUT: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        while (order_more == 'Y' || order_more == 'y')
        {
            cout << "ENTER ITEM ID: ";
            int entered_id;
            while (!(cin >> entered_id))
            {
                cout << "INVALID INPUT! ENTER ITEM ID FROM MENU: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            bool valid_orderid = false;
            usable_menu selected_item;

            for (int i = 0; i < menu.size(); i++)
            {
                if (menu[i].item_id == entered_id)
                {
                    selected_item = menu[i];
                    valid_orderid = true;
                    break;
                }
            }
            if (!valid_orderid)
            {
                cout << "INVALID ITEM ID! ENTER VALID ITEM ID FROM MENU: ";
                continue;
            }

            int qty;
            cout << "ENTER QUANTITY OF " << selected_item.item_name << " : ";
            while (!(cin >> qty) || qty < 0)
            {
                cout << "INVALID INPUT! ENTER QUANTITY OF " << selected_item.item_name << " : ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            double item_total = selected_item.item_price * qty;
            subtotal += item_total;

            save_order order;
            order.save_id = selected_item.item_id;
            order.save_name = selected_item.item_name;
            order.save_qty = qty;
            order.save_unitprice = selected_item.item_price;
            order.save_itemtotal = item_total;
            order_details.push_back(order);

            cout << endl
                 << "DO YOU WANT TO ADD MORE ITEMS. ENTER Y/y FOR 'YES' OR N/n FOR 'NO': ";
            while (!(cin >> order_more) || (order_more != 'Y' && order_more != 'y' && order_more != 'N' && order_more != 'n'))
            {
                cout << "INVALID INPUT! ENTER Y/y FOR 'YES' OR N/n FOR 'NO': ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            cout << endl;

            if (order_more == 'N' || order_more == 'n')
            {
                cout << "ITEMS IS/ARE SUCESSFULLY ADDED. ENTER P/p TO PLACE ORDER OR C/c TO CANCEL THE ORDER: ";

                char final_confirmation;
                while (!(cin >> final_confirmation) || (final_confirmation != 'P' && final_confirmation != 'p' && final_confirmation != 'C' && final_confirmation != 'c'))
                {
                    cout << "INVALID INPUT! ENTER P/p TO PLACE ORDER OR C/c TO CANCEL THE ORDER: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                if (final_confirmation == 'P' || final_confirmation == 'p')
                {
                    RMOS::order_no++;
                    cout << endl
                         << "YOUR ORDER IS SUCESSFULLY PLACED! PLEASE WAIT A MOMENT, YOUR ORDER IS BEING PREPARED..." << endl
                         << endl;

                    cout << "-------------------------------" << endl;
                    cout << "          TAX INVOICE          " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "    SLAYER'S DEN RESTAURANT    " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "ORDER NO: " << order_no << endl;
                    cout << "DATE: " << (localTime->tm_mday) << "/"
                         << (localTime->tm_mon + 1) << "/"
                         << (1900 + localTime->tm_year) << endl;
                    cout << "TIME: " << (localTime->tm_hour) << ":"
                         << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << endl;
                    cout << "-------------------------------" << endl;
                    cout << "EATING LOCATION: DINE " << eating_location << endl;
                    cout << "-------------------------------" << endl;
                    for (int i = 0; i < order_details.size(); i++)
                    {
                        cout << i + 1 << ")ITEM ID: " << order_details[i].save_id << endl;
                        cout << "  ITEM NAME: " << order_details[i].save_name << endl;
                        cout << "  ITEM QUANTITY: " << order_details[i].save_qty << endl;
                        cout << "  ITEM UNIT PRICE: " << order_details[i].save_unitprice << endl;
                        cout << "  ITEM TOTAL: " << order_details[i].save_itemtotal << endl
                             << endl;
                    }

                    cout << "-------------------------------" << endl;
                    cout << "  SUBTOTAL: " << subtotal << endl;
                    cout << "  CGST @ 2.5%: " << (2.5 / 100) * subtotal << endl;
                    cout << "  SGST @ 2.5%: " << (2.5 / 100) * subtotal << endl;

                    cout << "-------------------------------" << endl;

                    total += subtotal + ((2.5 / 100) * subtotal) * 2;

                    cout << "  GRAND TOTAL: " << total << endl;
                    cout << "-------------------------------" << endl
                         << endl
                         << endl;

                    ofstream billout;
                    billout.open(("RECEIPT.txt"), ios::app);

                    billout << "-------------------------------" << endl;
                    billout << "          TAX INVOICE          " << endl;
                    billout << "-------------------------------" << endl;
                    billout << "    SLAYER'S DEN RESTAURANT    " << endl;
                    billout << "-------------------------------" << endl;
                    billout << "ORDER NO: " << order_no << endl;
                    billout << "DATE: " << (localTime->tm_mday) << "/"
                            << (localTime->tm_mon + 1) << "/"
                            << (1900 + localTime->tm_year) << endl;
                    billout << "TIME: " << (localTime->tm_hour) << ":"
                            << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << endl;
                    billout << "-------------------------------" << endl;
                    billout << "EATING LOCATION: DINE " << eating_location << endl;
                    billout << "-------------------------------" << endl;

                    for (int i = 0; i < order_details.size(); i++)
                    {
                        billout << i + 1 << ")ITEM ID: " << order_details[i].save_id << endl
                                << "  ITEM NAME: " << order_details[i].save_name << endl
                                << "  ITEM QUANTITY: " << order_details[i].save_qty << endl
                                << "  ITEM UNITPRICE: " << order_details[i].save_unitprice << endl
                                << "  ITEM TOTAL: " << order_details[i].save_itemtotal << endl
                                << endl;
                    }

                    billout << "-------------------------------" << endl;
                    billout << "  SUBTOTAL: " << subtotal << endl;
                    billout << "  CGST @ 2.5%: " << (2.5 / 100) * subtotal << endl;
                    billout << "  SGST @ 2.5%: " << (2.5 / 100) * subtotal << endl;
                    billout << "-------------------------------" << endl;
                    billout << "  GRAND TOTAL: " << total << endl;
                    billout << "-------------------------------" << endl
                            << endl
                            << endl;

                    billout.close();

                    cout << endl
                         << "  BILL SUSCESSFULLY SAVED IN RECEIPT.txt FILE." << endl;
                    cout << "  THANK YOU! VISIT AGAIN..." << endl
                         << endl;
                    cout << "=============================" << endl
                         << endl;
                }
                else
                {
                    cout << endl
                         << "YOUR ORDER HAS BEEN CANCELLED. THANK YOU FOR VISITING!" << endl;
                }
            }
        }
    }
};

int RMOS::order_no = 0;

int main()
{
    int orders = INT_MAX;
    for (int i = 1; i <= orders; i++)
    {
        RMOS new_order;
        cout << "RESTARTING...SYSTEM" << endl;
    }

    return 0;
}