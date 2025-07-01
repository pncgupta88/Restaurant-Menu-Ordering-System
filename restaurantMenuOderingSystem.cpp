#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <climits>
#include <algorithm>
#include <cctype>

using namespace std;

class RMOS // Class
{
private:
    int first_choice;
    int inside_editmenu;
    static int order_no;
    const int security_pass = 246810;

public:
    RMOS() // Constructor
    {
        cout << endl;
        cout << "|| WELCOME TO RESTAURANT MENU ORDERING SYSTEM ||" << endl
             << endl;
        cout << "CHOOSE AN OPTION:" << endl
             << "1) VIEW MENU AND PLACE ORDER." << endl
             << "2) SEARCH ITEM IN MENU." << endl
             << "3) SORT MENU (PRICE LOW TO HIGH)." << endl
             << "4) SORT MENU (PRICE HIGH TO LOW)." << endl
             << "5) SORT MENU (ALPHABETICAL ORDER)." << endl
             << "6) SETTINGS." << endl
             << endl;
        cout << "ENTER 1/2/3/4/5/6: ";

        while (!(cin >> first_choice) || (first_choice != 1 && first_choice != 2 && first_choice != 3 && first_choice != 4 && first_choice != 5 && first_choice != 6))
        {
            cout << "INVALID INPUT! ENTER 1/2/3: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (first_choice == 1) // first_choice (View Menu And Place Order) == 1 => Start
        {
            display_menu();
            char g_OR_y;
            cout << "ENTER g/G TO GIVE ORDER OR r/R TO RETURN TO HOME SCREEN: ";
            while (!(cin >> g_OR_y) || (g_OR_y != 'g' && g_OR_y != 'G' && g_OR_y != 'r' && g_OR_y != 'R'))
            {
                cout << "INVALID INPUT! ENTER g/G TO GIVE ORDER OR r/R TO RETURN TO HOME SCREEN: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            if (g_OR_y == 'g' || g_OR_y == 'G')
            {
                cout << endl
                     << "GIVE YOUR ORDER: " << endl
                     << endl;
                take_order();
            }
            else
            {
                return;
            }
        }
        // first_choice (View Menu And Place Order) == 1 => End

        else if (first_choice == 2) // first_choice (SEARCH ITEM IN MENU AND PLACE ORDER.) => Start
        {
            cout << endl << "WORK IN PROGERSS" << endl;
            return;
        }
        // first_choice (SEARCH ITEM IN MENU AND PLACE ORDER.) => End

        else if (first_choice == 3) // first_choice (SORT MENU (PRICE LOW TO HIGH).) => Start
        {
            cout << endl << "WORK IN PROGERSS" << endl;
            return;
        }
        // first_choice (SORT MENU (PRICE LOW TO HIGH).) => End

        else if (first_choice == 4) // first_choice (SORT MENU (PRICE HIGH TO LOW).) => Start
        {
            cout << endl << "WORK IN PROGERSS" << endl;
            return;
        }
        // first_choice (SORT MENU (PRICE HIGH TO LOW).) => Start

        else if (first_choice == 5) // first_choice (SORT MENU (ALPHABETICAL ORDER).) => Start
        {
            cout << endl << "WORK IN PROGERSS" << endl;
            return;
        }
        // first_choice (SORT MENU (ALPHABETICAL ORDER).) => End

        else if (first_choice == 6) // first_choice (Edit Menu) => Start
        {
            if (!verify_security_pass()) // Security Check
            {
                return;
            }
            else
            {
                cout << endl
                     << "CORRECT SECURITY PASS. YOU CAN ACCESS THIS FEATURE." << endl;
                cout << endl
                     << "SELECT AN OPTION:" << endl;
                cout << "1)EDIT MENU." << endl
                     << "2)CLOSE SYSTEM." << endl
                     << endl;

                int inside_settings;
                cout << "ENTER 1/2: ";
                while (!(cin >> inside_settings) || (inside_settings != 1 && inside_settings != 2))
                {
                    cout << "INVALID INPUT! ENTER 1/2: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                if (inside_settings == 1)
                {
                    cout << endl
                         << "SELECT WHAT YOU WANT TO EDIT IN MENU:" << endl;
                    cout << "1) ADD ITEMS." << endl;
                    cout << "2) DELETE ITEMS.(INCOMPLETE! NOT WORKING)" << endl;
                    cout << "3) EDIT ITEMS.(INCOMPLETE! NOT WORKING)" << endl;
                    cout << "4) RETURN." << endl
                         << endl;
                    cout << "ENTER 1/2/3/4: ";

                    while (!(cin >> inside_editmenu) || (inside_editmenu != 1 && inside_editmenu != 2 && inside_editmenu != 3 && inside_editmenu != 4)) //))
                    {
                        cout << "INVALID INPUT! ENTER 1/2/3/4: ";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }

                    if (inside_editmenu == 1) // inside_editmenu (Add Items) => Start
                    {
                        char addmore = 'Y';

                        while (addmore == 'Y' || addmore == 'y')
                        {
                            cout << endl
                                 << "ENTER NEW ITEM DETAILS." << endl;
                            ;
                            add_newitem();
                            cout << endl
                                 << "SUCESSFULLY ADDED NEW ITEM TO MENU." << endl
                                 << endl;

                            cout << "DO YOU WANT TO ADD MORE ITEMS. ENTER Y FOR 'YES' OR N FOR 'NO': ";
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

                    // inside_editmenu (Add Items) => End

                    else if (inside_editmenu == 2) // inside_editmenu (Delete Items) => Start
                    {
                        cout << endl << "WORK IN PROGERSS" << endl; 
                        return;
                    }
                    // inside_editmenu (Add Items) => End

                    else if (inside_editmenu == 3) // inside_editmenu (Edit Items) => Start
                    {
                        cout << endl << "WORK IN PROGERSS" << endl;
                        return;
                    }
                    // inside_editmenu (Add Items) => End

                    else if (inside_editmenu == 4) // inside_editmenu (Return) => Start
                    {
                        return;
                    }
                    // inside_editmenu (Return) => End
                }

                else if (inside_settings == 2)
                {
                    cout << endl
                         << "EXITING..." << endl << endl;
                    exit(0);
                }
            }

            // first_choice (Edit Menu) == 6 => End
        }
    }

    // Member functions start from here.

    // Security check function to differentiate access to features between the owner and the customer.
    bool verify_security_pass() // Secutity check funcn => Start
    {
        int entered_pass;
        int attempt = 1;

        cout << endl
             << "ENTER SECURITY PASS TO ACCESS THIS FEATURE (ATTEMPT-" << attempt << " OF 3): ";
        while (!(cin >> entered_pass) || (entered_pass != security_pass))
        {
            cin.clear();
            cin.ignore(10000, '\n');

            attempt++;
            if (attempt > 3)
            {
                cout << endl
                     << "ATTEMPTS OVER.";
                return false;
            }

            cout << "INCORRECT SECURITY PASS! ENTER CORRECT SECURITY PASS TO ACCESS THIS FEATURE (ATTEMPT-" << attempt << " OF 3): ";
        }

        return true;
    }
    // Secutity check funcn => End

    // Function that auto assign item id to newly added item.
    int auto_assign_new_itemID() // Auto assign new item id funcn => Start
    {
        ifstream menu;
        menu.open("MENU.txt");
        int id;
        int max_id = 0;
        string name;
        double price;

        while (menu >> id)
        {
            if (id > max_id)
            {
                max_id = id;
            }
            menu.ignore(10000, '\n');
        }

        int new_id = max_id + 1;
        return new_id;
    }
    // Secutity check funcn => End

    // Function to make names of menu items uppercase
    string final_menu_itemname(string itemname) // Make menu items uppercase funcn => Start
    {
        string final_itemname;
        bool new_word = true;

        for (int i = 0; i < itemname.size(); i++)
        {
            if (isspace(itemname[i]) || itemname[i] == '_')
            {
                if (!final_itemname.empty() && final_itemname.back() != '_')
                {
                    final_itemname += '_';
                    
                }         
                new_word = true;
            }else 
            {
                if (new_word)
                {
                   final_itemname += toupper(itemname[i]); 
                }else
                {
                    final_itemname += tolower(itemname[i]);
                }
                new_word = false;
            } 
        }
        return final_itemname;
    }
    // Make menu items uppercase funcn => End

    // Function to check that entered new item is previously available or not
    bool check_duplicate_menu_items(const string &new_itemname) // Check duplicate menu items funcn => Start
    {
        ifstream menu;
        menu.open("MENU.txt");

        int id;
        string name;
        double price;

        string entered_newitem = final_menu_itemname(new_itemname);

        while (menu >> id >> name >> price)
        {
            if (final_menu_itemname(name) == entered_newitem)
            {
                return true;
            }
        }
        return false;
    }
    // Check duplicate menu items funcn => End

    // Function to add new food item in menu
    void add_newitem() // Add new item funcn => Start
    {
        int new_itemid = auto_assign_new_itemID();
        ofstream add("MENU.txt", ios::app);

        cin.ignore(1000000, '\n');

        // int new_itemid = auto_assign_new_itemID();
        string entered_new_itemname;
        double new_itemprice;

        cout << "SYSTEM WILL ASSIGN ID TO NEW ITEM AUTOMATICALLY " << endl
             << endl;

        // cin.ignore(1000000, '\n');

        while (true)
        {
            cout << "ENTER NEW ITEM'S NAME (ONLY LETTERS AND SPACES ARE ALLOWED): ";
            // cin.ignore(1000000, '\n');
            // cin.clear();
            getline(cin, entered_new_itemname);

            if (entered_new_itemname.empty())
            {
                cout << "INVALID ITEMNAME! NAME CANNOT BE BLANK.\n\n";
                continue;
            }

            bool valid_itemname = true;

            for (int i = 0; i < entered_new_itemname.size(); i++)
            {
                if (!isalpha(entered_new_itemname[i]) && entered_new_itemname[i] != '_')
                {
                    valid_itemname = false;
                    break;
                }
            }

            if (!valid_itemname)
            {
                cout << "INVALID ITEMNAME! ";
                continue;
            }

            if (check_duplicate_menu_items(entered_new_itemname))
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

        string new_itemname = final_menu_itemname(entered_new_itemname);

        cout << "ENTER NEW ITEM'S PRICE: ";

        while (!(cin >> new_itemprice))
        {
            cout << "INVALID INPUT! ENTER NEW ITEM'S PRICE: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        add << new_itemid << "   " << new_itemname << "        " << new_itemprice << endl;
    }
    // Add new item funcn => End

    // void delete_item()
    // {

    // }

    // Function to display menu.
    void display_menu() // Display Menu funcn => Start
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
    // Display Menu funcn => End

    // User defined data type to store item ID, name, and price of a menu item
    struct usable_menu // Start
    {
        int item_id;
        string item_name;
        double item_price;
    };
    // End

    // User defined data type to store item details of ordered item
    struct save_order // Start
    {
        int save_id;
        string save_name;
        int save_qty;
        double save_unitprice;
        double save_itemtotal;
    };
    // End

    // Function to replicate menu items into a usable format for customer orders
    vector<usable_menu> copymenuitems() // copymenuitems funcn => Start
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
    // copymenuitems funcn => End

    // Function to search menu item with name
    void search_menu_item() // Search menu item funcn => Start
    {
        vector<usable_menu> menu = copymenuitems();

        string searched_itemname;
    }
    // Search menu item funcn => End

    // Function that check's and merge's duplicate ordered items
    void merge_duplicate_order_items(vector<save_order> &orders) // Merge duplicate order items funcn => Start
    {
        for (int i = 0; i < orders.size(); ++i)
        {
            int j = i + 1;
            while (j < orders.size())
            {
                if (orders[i].save_id == orders[j].save_id)
                {
                    orders[i].save_qty += orders[j].save_qty;
                    orders[i].save_itemtotal += orders[j].save_itemtotal;
                    orders.erase(orders.begin() + j); // no need to increment j
                }
                else
                {
                    j++; // only increment if no erase happened
                }
            }
        }
    }
    // Search menu item funcn => End

    // Function to take order, save each ordered item, made bill
    void take_order() // Take order funcn => Start
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
                cout << "INVALID ITEM ID! ";
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
                    merge_duplicate_order_items(order_details);

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
                    cout << "-------------------------------" << endl;
                    cout << "     THANK YOU VISIT AGAIN     " << endl;
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
                    billout << "-------------------------------" << endl;
                    billout << "     THANK YOU VISIT AGAIN     " << endl;
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
    // Take order funcn => Start
};

// Static int for order num
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