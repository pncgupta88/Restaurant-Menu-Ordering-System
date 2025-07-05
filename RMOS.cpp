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
        cout << "Choose an option:" << endl
             << "1) View menu and place order." << endl
             << "2) Search item in menu." << endl
             << "3) Sort menu (price low to high)." << endl
             << "4) Sort menu (price high to low)." << endl
             << "5) Sort menu (alphabetical order)." << endl
             << "6) Settings." << endl
             << endl;
        cout << "Enter 1/2/3/4/5/6: ";

        while (!(cin >> first_choice) || (first_choice != 1 && first_choice != 2 && first_choice != 3 && first_choice != 4 && first_choice != 5 && first_choice != 6))
        {
            cout << "INVALID INPUT! ENTER 1/2/3/4/5/6: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (first_choice == 1) // first_choice (View Menu And Place Order) == 1 => Start
        {
            display_menu();
            char g_OR_y;
            cout << "Do you want to give order or return to home screen (g/r): ";
            while (!(cin >> g_OR_y) || (g_OR_y != 'g' && g_OR_y != 'G' && g_OR_y != 'r' && g_OR_y != 'R'))
            {
                cout << "Invalid input! Do you want to give order or return to home screen (g/r): ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            if (g_OR_y == 'g' || g_OR_y == 'G')
            {
                cout << endl
                     << "Give your order: " << endl
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
            char searchmore = 'Y';

            while (searchmore == 'Y' || searchmore == 'y')
            {
                cout << endl;
                display_menu();

                search_menu_item();
                cout << endl
                     << "Do you want to search more items? (Y/N): ";

                while (!(cin >> searchmore) || (searchmore != 'y' && searchmore != 'Y' && searchmore != 'n' && searchmore != 'N'))
                {
                    cout << "Invalid input! Do you want to search more items? (Y/N): ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                if (searchmore == 'N' || searchmore == 'n')
                {
                    char g_OR_y;
                    cout << endl
                         << "Do you want to give order or return to home screen (g/r): ";
                    while (!(cin >> g_OR_y) || (g_OR_y != 'g' && g_OR_y != 'G' && g_OR_y != 'r' && g_OR_y != 'R'))
                    {
                        cout << "Invalid input! Do you want to give order or return to home screen (g/r): ";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }

                    if (g_OR_y == 'g' || g_OR_y == 'G')
                    {
                        cout << endl
                             << "Give your order: " << endl
                             << endl;
                        take_order();
                    }
                    else
                    {
                        return;
                    }
                }
            } 
        }
        // first_choice (SEARCH ITEM IN MENU AND PLACE ORDER.) => End

        else if (first_choice == 3) // first_choice (SORT MENU (PRICE LOW TO HIGH).) => Start
        {
            vector<usable_menu> sorted_menu = sort_menu_pricelowtohigh();
            cout << "\n==========SORTED MENU==========\n\n";
            cout << "Id.  item Name       Price(Rs)" << endl
                 << endl;
            for (int i = 0; i < sorted_menu.size(); i++)
            {
                const usable_menu &item_details = sorted_menu[i];

                cout << item_details.item_id << "    " << item_details.item_name << "     " << item_details.item_price << endl;
            }

            char g_OR_y;
            cout << endl
                 << "Do you want to give order or return to home screen (g/r): ";
            while (!(cin >> g_OR_y) || (g_OR_y != 'g' && g_OR_y != 'G' && g_OR_y != 'r' && g_OR_y != 'R'))
            {
                cout << "Invalid input! Do you want to give order or return to home screen (g/r): ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            if (g_OR_y == 'g' || g_OR_y == 'G')
            {
                cout << endl
                     << "Give your order: " << endl
                     << endl;
                take_order();
            }
            else
            {
                return;
            }
        }
        // first_choice (SORT MENU (PRICE LOW TO HIGH).) => End

        else if (first_choice == 4) // first_choice (SORT MENU (PRICE HIGH TO LOW).) => Start
        {
            vector<usable_menu> sorted_menu = sort_menu_pricehightolow();
            cout << "\n==========SORTED MENU==========\n\n";
            cout << "Id.  item Name       Price(Rs)" << endl
                 << endl;
            for (int i = 0; i < sorted_menu.size(); i++)
            {
                const usable_menu &item_details = sorted_menu[i];

                cout << item_details.item_id << "    " << item_details.item_name << "     " << item_details.item_price << endl;
            }

            char g_OR_y;
            cout << endl
                 << "Do you want to give order or return to home screen (g/r): ";
            while (!(cin >> g_OR_y) || (g_OR_y != 'g' && g_OR_y != 'G' && g_OR_y != 'r' && g_OR_y != 'R'))
            {
                cout << "Invalid input! Do you want to give order or return to home screen (g/r): ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            if (g_OR_y == 'g' || g_OR_y == 'G')
            {
                cout << endl
                     << "Give your order: " << endl
                     << endl;
                take_order();
            }
            else
            {
                return;
            }
        }
        // first_choice (SORT MENU (PRICE HIGH TO LOW).) => End

        else if (first_choice == 5) // first_choice (SORT MENU (ALPHABETICAL ORDER).) => Start
        {
            vector<usable_menu> sorted_menu = sort_menu_alphabaticalorder();
            cout << "\n==========SORTED MENU==========\n\n";
            cout << "Id.  item Name       Price(Rs)" << endl
                 << endl;
            for (int i = 0; i < sorted_menu.size(); i++)
            {
                const usable_menu &item_details = sorted_menu[i];

                cout << item_details.item_id << "    " << item_details.item_name << "     " << item_details.item_price << endl;
            }

            char g_OR_y;
            cout << endl
                 << "Do you want to give order or return to home screen (g/r): ";
            while (!(cin >> g_OR_y) || (g_OR_y != 'g' && g_OR_y != 'G' && g_OR_y != 'r' && g_OR_y != 'R'))
            {
                cout << "Invalid input! Do you want to give order or return to home screen (g/r): ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            if (g_OR_y == 'g' || g_OR_y == 'G')
            {
                cout << endl
                     << "Give your order: " << endl
                     << endl;
                take_order();
            }
            else
            {
                return;
            }
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
                     << "Correct security pass. You can access this feature." << endl;
                cout << endl
                     << "Select an option:" << endl;
                cout << "1) Edit Menu." << endl
                     << "2) View All Time Order History." << endl
                     << "3) Close System." << endl
                     << endl;

                int inside_settings;
                cout << "Enter 1/2/3: ";
                while (!(cin >> inside_settings) || (inside_settings != 1 && inside_settings != 2 && inside_settings != 3 ))
                {
                    cout << "Invalid input! Enter 1/2/3: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                if (inside_settings == 1) // inside_settings (Edit Menu) => Start
                {
                    cout << endl
                         << "Select what you want to edit in menu:" << endl;
                    cout << "1) Add Items." << endl;
                    cout << "2) Delete Items." << endl;
                    cout << "3) Edit Items." << endl;
                    cout << "4) Return." << endl
                         << endl;
                    cout << "Enter 1/2/3/4: ";

                    while (!(cin >> inside_editmenu) || (inside_editmenu != 1 && inside_editmenu != 2 && inside_editmenu != 3 && inside_editmenu != 4)) //))
                    {
                        cout << "Invalid input! Enter 1/2/3/4: ";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }

                    if (inside_editmenu == 1) // inside_editmenu (Add Items) => Start
                    {
                        char addmore = 'Y';

                        while (addmore == 'Y' || addmore == 'y')
                        {
                            cout << endl
                                 << "Enter new item details." << endl;
                            ;
                            add_newitem();
                            cout << endl
                                 << "Successfully added new item to menu." << endl
                                 << endl;

                            cout << "Do you want to add more items? (Y/N): ";
                            while (!(cin >> addmore) || (addmore != 'y' && addmore != 'Y' && addmore != 'n' && addmore != 'N'))
                            {
                                cout << "Invalid input! Do you want to add more items? (Y/N): ";
                                cin.clear();
                                cin.ignore(10000, '\n');
                            }

                            if (addmore == 'N' || addmore == 'n')
                            {
                                cout << endl
                                     << "Thank you for using our system. Visit again soon!" << endl
                                     << endl;
                            }
                        }
                    }

                    // inside_editmenu (Add Items) => End

                    else if (inside_editmenu == 2) // inside_editmenu (Delete Items) => Start
                    {
                       display_menu();

                        vector<usable_menu> menu = copymenuitems();
                        while (true)
                        {
                            cout << "\nEnter Item ID: ";
                            int entered_id_to_delete;
                            while (!(cin >> entered_id_to_delete))
                            {
                                cout << "Invalid Input! Enter Item ID From Menu: ";
                                cin.clear();
                                cin.ignore(10000, '\n');
                            }

                            // checking for valid id
                            bool valid_orderid = false;

                            // editing in usable_menu
                            for (int i = 0; i < menu.size(); i++)
                            {
                                if (menu[i].item_id == entered_id_to_delete)
                                {
                                    cout << "\nItem Found: " << menu[i].item_name;

                                    char confirm;
                                    cout << "Are You Sure You Want To Delete This Item? (Y/N): ";
                                    while (!(cin >> confirm) || (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n'))
                                    {
                                        cout << "Invalid Input! Enter Y/y OR N/n: ";
                                        cin.clear();
                                        cin.ignore(10000, '\n');
                                    }

                                    if (confirm == 'Y' || confirm == 'y')
                                    {
                                        menu.erase(menu.begin() + i);
                                        cout << "Item Deleted Successfully.\n";
                                    }
                                    else
                                    {
                                        cout << "Item Not Deleted.\n";
                                    }

                                    valid_orderid = true;
                                    break;
                                }
                            }

                            if (!valid_orderid)
                            {
                                cout << "Invalid Item ID! ";
                                continue;
                            }

                            // deleting more than one items
                            char choice;
                            cout << "Do You Want To Delete More Items? (Y/N): ";
                            while (!(cin >> choice) || (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'))
                            {
                                cout << "Invalid Input! Enter Y/y Or N/n: ";
                                cin.clear();
                                cin.ignore(10000, '\n');
                            }

                            if (choice == 'N' || choice == 'n')
                            {
                                break;
                            }
                        }

                        // deleting in menu
                        ofstream out;
                        out.open("MENU.txt");
                        for (const auto &item : menu)
                        {
                            out << item.item_id << "   " << item.item_name << "        " << item.item_price << endl;
                        }
                        out.close();

                        cout << "\nMenu Updated Successfully.\n";
                        return;
                    }
                    // inside_editmenu (Delete Items) => End

                    else if (inside_editmenu == 3) // inside_editmenu (Edit Items) => Start
                    {
                        display_menu();

                        vector<usable_menu> menu = copymenuitems();
                        while (true)
                        {
                            cout << "Enter Item ID: ";
                            int entered_id_to_modify;
                            while (!(cin >> entered_id_to_modify))
                            {
                                cout << "Invalid Input! Enter Item ID From Menu: ";
                                cin.clear();
                                cin.ignore(10000, '\n');
                            }

                            // checking for valid id
                            bool valid_orderid = false;
                            usable_menu selected_item;

                            for (int i = 0; i < menu.size(); i++)
                            {
                                if (menu[i].item_id == entered_id_to_modify)
                                {
                                    selected_item = menu[i];
                                    valid_orderid = true;
                                    break;
                                }
                            }

                            if (!valid_orderid)
                            {
                                cout << "Invalid Item ID! ";
                                continue;
                            }
                            // checked for valid id

                            while (true)
                            {
                                cout << "\nWhat Do You Want To Edit?" << endl
                                     << "1. Item ID" << endl
                                     << "2. Item Name" << endl
                                     << "3. Item Price" << endl
                                     << "Enter 1/2/3: ";

                                int edit_data;

                                while (!(cin >> edit_data) || (edit_data != 1 && edit_data != 2 && edit_data != 3))
                                {
                                    cout << "Invalid Input! Enter Item ID From Menu: ";
                                    cin.clear();
                                    cin.ignore(10000, '\n');
                                }

                                // editing in usable_menu
                                for (int i = 0; i < menu.size(); i++)
                                {
                                    if (menu[i].item_id == entered_id_to_modify)
                                    {
                                        selected_item = menu[i];
                                        valid_orderid = true;
                                        break;
                                    }
                                }

                                if (!valid_orderid)
                                {
                                    cout << "Invalid Item ID! ";
                                    continue;
                                }

                                // function for editing id
                                if (edit_data == 1)
                                {
                                    int new_id;
                                    cout << "\nEnter The New Item ID: ";
                                    cin >> new_id;

                                    // Check for duplicate
                                    bool new_valid_id = false;

                                    for (int i = 0; i < menu.size(); i++)
                                    {
                                        if (menu[i].item_id == new_id)
                                        {
                                            new_valid_id = true;
                                            break;
                                        }
                                    }

                                    if (new_valid_id)
                                    {
                                        cout << "Item ID already exists! ";
                                        continue;
                                    }

                                    // Assign the new id
                                    for (int i = 0; i < menu.size(); i++)
                                    {
                                        if (menu[i].item_id == entered_id_to_modify)
                                        {
                                            menu[i].item_id = new_id;
                                            cout << "Item Edited Successfully.\n";
                                            break;
                                        }
                                    }
                                }

                                // function for editing name
                                else if (edit_data == 2)
                                {
                                    string new_name;
                                    cout << "\nEnter The New Item Name: ";
                                    cin >> new_name;

                                    // Check for duplicate
                                    bool name_exists = false;
                                    for (int i = 0; i < menu.size(); i++)
                                    {
                                        if (menu[i].item_name == new_name)
                                        {
                                            name_exists = true;
                                            break;
                                        }
                                    }

                                    if (name_exists)
                                    {
                                        cout << "Item Name Already Exists! Please Choose A Different Name.\n";
                                        continue;
                                    }

                                    // Assign the new name
                                    for (int i = 0; i < menu.size(); i++)
                                    {
                                        if (menu[i].item_id == entered_id_to_modify)
                                        {
                                            menu[i].item_name = new_name;
                                            cout << "Item Edited Successfully.\n";
                                            break;
                                        }
                                    }
                                }

                                // function for editing price
                                else if (edit_data == 3)
                                {
                                    double new_price;
                                    cout << "\nEnter The New Item Price: \n";
                                    cin >> new_price;

                                    for (int i = 0; i < menu.size(); i++)
                                    {
                                        if (menu[i].item_id == entered_id_to_modify)
                                        {
                                            menu[i].item_price = new_price;
                                            cout << "Item Edited Successfully.\n";
                                            break;
                                        }
                                    }
                                }

                                // editing more than one items
                                char choice;
                                cout << "\nEdit More Fields Of This Item? (Y/N): ";
                                while (!(cin >> choice) || (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'))
                                {
                                    cout << "Invalid Input! Enter Y/y Or N/n: ";
                                    cin.clear();
                                    cin.ignore(10000, '\n');
                                }

                                if (choice == 'N' || choice == 'n')
                                {
                                    break;
                                }

                                else
                                {
                                    continue;
                                }
                            }

                            char edit_another;
                            cout << "Edit another item? (Y/N): ";

                            while (!(cin >> edit_another) || (edit_another != 'Y' && edit_another != 'y' && edit_another != 'N' && edit_another != 'n'))
                                {
                                    cout << "Invalid Input! Enter Y/y Or N/n: ";
                                    cin.clear();
                                    cin.ignore(10000, '\n');
                                }

                                if (edit_another == 'N' || edit_another == 'n')
                                {
                                    break;
                                }

                                else
                                {
                                    continue;
                                }
                        }

                        // editing in menu
                        ofstream out;
                        out.open("MENU.txt");
                        for (const auto &item : menu)
                        {
                            out << item.item_id << "   " << item.item_name << "        " << item.item_price << endl;
                        }
                        out.close();

                        cout << "\nMenu Updated Successfully.\n";
                        return;
                    }
                    // inside_editmenu (Edit Items) => End

                    else if (inside_editmenu == 4) // inside_editmenu (Return) => Start
                    {
                        return;
                    }
                    // inside_editmenu (Return) => End
                }else if (inside_settings == 2)
                {
                    cout << endl << "Order History:" << endl << endl;
                    view_order_history();

                }
                

                else if (inside_settings == 3)
                {
                    cout << endl
                         << "Exiting..." << endl
                         << endl;
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
             << "Enter security pass to access this feature (Attempt-" << attempt << " of 3): ";
        while (!(cin >> entered_pass) || (entered_pass != security_pass))
        {
            cin.clear();
            cin.ignore(10000, '\n');

            attempt++;
            if (attempt > 3)
            {
                cout << endl
                     << "Attempts over.";
                return false;
            }

            cout << "Incorrect security pass! Enter correct security pass to access this feature (Attempt-" << attempt << " of 3): ";
        }

        return true;
    }
    // Security check funcn => End

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
    // Auto assign new item id funcn => End

    // Function to format names of menu items.
    string final_menu_itemname(string itemname) // Format menu items funcn => Start
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
            }
            else
            {
                if (new_word)
                {
                    final_itemname += toupper(itemname[i]);
                }
                else
                {
                    final_itemname += tolower(itemname[i]);
                }
                new_word = false;
            }
        }
        return final_itemname;
    }
    // Format menu items funcn => End

    // Function to check that entered new item is previously available or not
    bool check_duplicate_menu_items(const string &new_itemname) // Check duplicate menu items funcn => Start
    {
        ifstream menu;
        menu.open("MENU.txt");

        // if (!menu)
        // {
        //     cout << "MENU FILE IS MISSING." << endl;
        //     return;
        // }

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

        if (!add)
        {
            cout << "Menu file missing." << endl;
            return;
        }

        cin.ignore(1000000, '\n');

        // int new_itemid = auto_assign_new_itemID();
        string entered_new_itemname;
        double new_itemprice;

        cout << "System will assign ID to new item automatically." << endl
             << endl;

        // cin.ignore(1000000, '\n');

        while (true)
        {
            cout << "Enter new item's name (only alphabets and underscores are allowed): ";
            // cin.ignore(1000000, '\n');
            // cin.clear();
            getline(cin, entered_new_itemname);

            if (entered_new_itemname.empty())
            {
                cout << "Invalid item name! Name cannot be blank.\n\n";
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
                cout << "Invalid item name! ";
                continue;
            }

            if (check_duplicate_menu_items(entered_new_itemname))
            {
                cout << endl
                     << "Item already exists in menu!" << endl
                     << endl;
            }
            else
            {
                break;
            }
        }

        string new_itemname = final_menu_itemname(entered_new_itemname);

        cout << "Enter new item's price: ";

        while (!(cin >> new_itemprice))
        {
            cout << "Invalid price! Enter new item's price: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        add << new_itemid << "   " << new_itemname << "        " << new_itemprice << endl;
        add.close();
    }
    // Add new item funcn => End

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

        // if (!menu)
        // {
        //     cout << "MENU FILE IS MISSING." << endl;
        //     return;
        // }

        usable_menu temp;
        while (menu >> temp.item_id >> temp.item_name >> temp.item_price)
        {
            menutotakeorder.push_back(temp);
        }
        menu.close();
        return menutotakeorder;
    }
    // copymenuitems funcn => End

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
    // Merge menu item funcn => End

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

        string entered_eating_location;
        cout << "Enter eating location (in/out): ";
        while (!(cin >> entered_eating_location) || (entered_eating_location != "IN" && entered_eating_location != "in" && entered_eating_location != "OUT" && entered_eating_location != "out"))
        {
            cout << "Invalid eating location! Enter eating location (in/out): ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        string eating_location = final_menu_itemname(entered_eating_location);

        cin.ignore(10000, '\n');

        while (order_more == 'Y' || order_more == 'y')
        {
            cout << "Enter item ID: ";
            int entered_id;
            while (!(cin >> entered_id))
            {
                cout << "Invalid item ID! Enter item ID from menu: ";
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
                cout << "Invalid item ID! ";
                continue;
            }

            cin.ignore(10000, '\n');

            int qty;
            cout << "Enter quantity of " << selected_item.item_name << " : ";
            while (!(cin >> qty) || qty < 0)
            {
                cout << "Invalid quantity! Enter quantity of " << selected_item.item_name << " : ";
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
                 << "Do you want to add more items? (y/n): ";
            while (!(cin >> order_more) || (order_more != 'Y' && order_more != 'y' && order_more != 'N' && order_more != 'n'))
            {
                cout << "Invalid input! Do you want to add more items? (y/n): ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            cout << endl;

            if (order_more == 'N' || order_more == 'n')
            {
                cout << "Items added successfully. Do you want to confirm your order? (p to place order, c to cancel): ";

                char final_confirmation;
                while (!(cin >> final_confirmation) || (final_confirmation != 'P' && final_confirmation != 'p' && final_confirmation != 'C' && final_confirmation != 'c'))
                {
                    cout << "Invalid input! Do you want to confirm your order? (p to place order, c to cancel): ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                if (final_confirmation == 'P' || final_confirmation == 'p')
                {
                    RMOS::order_no++;
                    merge_duplicate_order_items(order_details);

                    cout << endl
                         << "Your order is successfully placed! Please wait a moment, your order is being prepared..." << endl
                         << endl;

                    cout << "-------------------------------" << endl;
                    cout << "          TAX INVOICE          " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "    SLAYER'S DEN RESTAURANT    " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Order No: " << order_no << endl;
                    cout << "Date: " << (localTime->tm_mday) << "/"
                         << (localTime->tm_mon + 1) << "/"
                         << (1900 + localTime->tm_year) << endl;
                    cout << "Time: " << (localTime->tm_hour) << ":"
                         << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Eating Location: Dine " << eating_location << endl;
                    cout << "-------------------------------" << endl;
                    for (int i = 0; i < order_details.size(); i++)
                    {
                        cout << i + 1 << ")Item ID: " << order_details[i].save_id << endl;
                        cout << "  Item Name: " << order_details[i].save_name << endl;
                        cout << "  Item Quantity: " << order_details[i].save_qty << endl;
                        cout << "  Item Unit Price: " << order_details[i].save_unitprice << endl;
                        cout << "  Item Total: " << order_details[i].save_itemtotal << endl
                             << endl;
                    }

                    cout << "-------------------------------" << endl;
                    cout << "  Subtotal: " << subtotal << endl;
                    cout << "  CGST @ 2.5%: " << (2.5 / 100) * subtotal << endl;
                    cout << "  SGST @ 2.5%: " << (2.5 / 100) * subtotal << endl;

                    cout << "-------------------------------" << endl;

                    total += subtotal + ((2.5 / 100) * subtotal) * 2;

                    cout << "  Grand Total: " << total << endl;
                    cout << "-------------------------------" << endl;
                    cout << "     THANK YOU VISIT AGAIN     " << endl;
                    cout << "-------------------------------" << endl
                         << endl
                         << endl;

                    ofstream receiptout;
                    receiptout.open(("RECEIPT.txt"));

                    if (!receiptout)
                    {
                        cout << "Menu file missing." << endl;
                        return;
                    }

                    receiptout << "-------------------------------" << endl;
                    receiptout << "          TAX INVOICE          " << endl;
                    receiptout << "-------------------------------" << endl;
                    receiptout << "    SLAYER'S DEN RESTAURANT    " << endl;
                    receiptout << "-------------------------------" << endl;
                    receiptout << "Order No: " << order_no << endl;
                    receiptout << "Date: " << (localTime->tm_mday) << "/"
                               << (localTime->tm_mon + 1) << "/"
                               << (1900 + localTime->tm_year) << endl;
                    receiptout << "Time: " << (localTime->tm_hour) << ":"
                               << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << endl;
                    receiptout << "-------------------------------" << endl;
                    receiptout << "Eating Location: Dine " << eating_location << endl;
                    receiptout << "-------------------------------" << endl;

                    for (int i = 0; i < order_details.size(); i++)
                    {
                        receiptout << i + 1 << ")Item ID: " << order_details[i].save_id << endl
                                   << "  Item Name: " << order_details[i].save_name << endl
                                   << "  Item Quantity: " << order_details[i].save_qty << endl
                                   << "  Item Unit Price: " << order_details[i].save_unitprice << endl
                                   << "  Item Total: " << order_details[i].save_itemtotal << endl
                                   << endl;
                    }

                    receiptout << "-------------------------------" << endl;
                    receiptout << "  Subtotal: " << subtotal << endl;
                    receiptout << "  CGST @ 2.5%: " << (2.5 / 100) * subtotal << endl;
                    receiptout << "  SGST @ 2.5%: " << (2.5 / 100) * subtotal << endl;
                    receiptout << "-------------------------------" << endl;
                    receiptout << "  Grand Total: " << total << endl;
                    receiptout << "-------------------------------" << endl;
                    receiptout << "     THANK YOU VISIT AGAIN     " << endl;
                    receiptout << "-------------------------------" << endl
                               << endl
                               << endl;

                    receiptout.close();

                    ofstream orderout;
                    orderout.open(("ORDER.txt"), ios::app);

                    if (!orderout)
                    {
                        cout << "Menu file missing." << endl;
                        return;
                    }

                    orderout << "-------------------------------" << endl;
                    orderout << "          TAX INVOICE          " << endl;
                    orderout << "-------------------------------" << endl;
                    orderout << "    SLAYER'S DEN RESTAURANT    " << endl;
                    orderout << "-------------------------------" << endl;
                    orderout << "Order No: " << order_no << endl;
                    orderout << "Date: " << (localTime->tm_mday) << "/"
                             << (localTime->tm_mon + 1) << "/"
                             << (1900 + localTime->tm_year) << endl;
                    orderout << "Time: " << (localTime->tm_hour) << ":"
                             << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << endl;
                    orderout << "-------------------------------" << endl;
                    orderout << "Eating Location: Dine " << eating_location << endl;
                    orderout << "-------------------------------" << endl;

                    for (int i = 0; i < order_details.size(); i++)
                    {
                        orderout << i + 1 << ")Item ID: " << order_details[i].save_id << endl
                                 << "  Item Name: " << order_details[i].save_name << endl
                                 << "  Item Quantity: " << order_details[i].save_qty << endl
                                 << "  Item Unit Price: " << order_details[i].save_unitprice << endl
                                 << "  Item Total: " << order_details[i].save_itemtotal << endl
                                 << endl;
                    }

                    orderout << "-------------------------------" << endl;
                    orderout << "  Subtotal: " << subtotal << endl;
                    orderout << "  CGST @ 2.5%: " << (2.5 / 100) * subtotal << endl;
                    orderout << "  SGST @ 2.5%: " << (2.5 / 100) * subtotal << endl;
                    orderout << "-------------------------------" << endl;
                    orderout << "  Grand Total: " << total << endl;
                    orderout << "-------------------------------" << endl;
                    orderout << "     THANK YOU VISIT AGAIN     " << endl;
                    orderout << "-------------------------------" << endl
                             << endl
                             << endl;

                    orderout.close();

                    cout << endl
                         << "  Bill successfully saved in RECEIPT.txt file." << endl;
                    cout << "  Thank you! Visit again." << endl;
                    cout << "=============================" << endl
                         << endl;
                }
                else
                {
                    cout << endl
                         << "Your order has been cancelled. Thank you for visiting!" << endl;
                }
            }
        }
    }
    // Take order funcn => End

    // Search items by name
    void search_menu_item() // Search menu item funcn => Start
    {
        ifstream menu;
        menu.open("MENU.txt");

        cin.ignore(1000000, '\n');

        string searched_word;

        while (true)
        {
            cout << "Search: ";
            getline(cin, searched_word);

            if (searched_word.empty())
            {
                cout << "Invalid input! Search cannot be blank." << endl;
                continue;
            }

            bool validate_search = true;

            for (int i = 0; i < searched_word.size(); i++)
            {
                if (!isalpha(searched_word[i]) && searched_word[i] != '_')
                {
                    validate_search = false;
                    break;
                }
            }

            if (!validate_search)
            {
                cout << "Invalid search!";
                continue;
            }

            string formated_searched_word = final_menu_itemname(searched_word);

            int id;
            string name;
            float price;
            bool found = false;

            cout << endl
                 << "Id.  item Name       Price(Rs)" << endl
                 << endl;

            while (menu >> id >> name >> price)
            {
                bool match = false;

                for (int i = 0; i <= name.size() - formated_searched_word.size(); i++)
                {
                    int j;
                    for (j = 0; j < formated_searched_word.size(); j++)
                    {
                        if (name[i + j] != formated_searched_word[j])
                        {
                            break;
                        }
                    }
                    if (j == formated_searched_word.size())
                    {
                        match = true;
                        break;
                    }
                }

                if (match)
                {
                    cout << id << "    " << name << "     " << price << endl;
                    found = true;
                }
            }

            if (!found)
            {
                cout << "Item not found." << endl;
            }
            else
            {
                break;
            }
        }
        menu.close();
    }
    // Search menu item funcn => End

    // Function to sort menu items by price low to high
    vector<usable_menu> sort_menu_pricelowtohigh() // sort_menu_pricelowtohigh funcn => Start
    {
        vector<usable_menu> sorted_menu;
        ifstream menu;
        menu.open("MENU.txt");

        usable_menu temp;
        while (menu >> temp.item_id >> temp.item_name >> temp.item_price)
        {
            sorted_menu.push_back(temp);
        }

        sort(sorted_menu.begin(), sorted_menu.end(), [](const usable_menu &a, const usable_menu &b)
             { return a.item_price < b.item_price; });

        return sorted_menu;
    }
    // sort_menu_pricelowtohigh funcn => End


    // Function to sort menu items by price high to low
    vector<usable_menu> sort_menu_pricehightolow() // sort_menu_pricehightolow funcn => Start
    {
        vector<usable_menu> sorted_menu;
        ifstream menu;
        menu.open("MENU.txt");

        usable_menu temp;
        while (menu >> temp.item_id >> temp.item_name >> temp.item_price)
        {
            sorted_menu.push_back(temp);
        }

        sort(sorted_menu.begin(), sorted_menu.end(), [](const usable_menu &a, const usable_menu &b)
             { return a.item_price > b.item_price; });

        return sorted_menu;
    }
    // sort_menu_pricehightolow funcn => End


    // Function to sort menu items in alphabetical order
    vector<usable_menu> sort_menu_alphabaticalorder() // sort_menu_alphabaticalorder funcn => Start
    {
        vector<usable_menu> sorted_menu;
        ifstream menu;
        menu.open("MENU.txt");

        usable_menu temp;
        while (menu >> temp.item_id >> temp.item_name >> temp.item_price)
        {
            sorted_menu.push_back(temp);
        }

        sort(sorted_menu.begin(), sorted_menu.end(), [](const usable_menu &a, const usable_menu &b)
             { return a.item_name < b.item_name; });

        return sorted_menu;
    } 
    // sort_menu_alphabaticalorder funcn => End

    // Function to view order history    
    void view_order_history() // view_order_history funcn => Start
    {
        ifstream order_history;
        order_history.open("ORDER.txt");

        string line;

        while (getline(order_history, line))
        {
            cout << line <<endl;
        }        
    }
    // view_order_history funcn => End
};

// Static int for order num
int RMOS::order_no = 0;

int main() 
{
    int orders = INT_MAX; // Maximum number of orders can be set to INT_MAX for continuous operation
    for (int i = 1; i <= orders; i++) // Loop for each order
    {
        RMOS new_order;
        cout << "Restarting..." << endl;
    }

    return 0;
}
