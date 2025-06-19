#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Self_Order{
private:
    int Order_No = 0;
    string eating_location;
    int product_Id;
    

public:
    Self_Order() 
    {
        cout << "WELCOME TO \"SLAYER'S DEN\" YOUR ALL IN ONE RESTAURANT" << endl;

        cout << "SELECT EATING LOCATION" << endl << "(a)IN" << endl << "(b)OUT" << endl << "ENTER 'IN' OR 'OUT': ";
        cin >> eating_location;

        while (eating_location != "IN" && eating_location != "OUT")
        {
            cout << "INVALID sINPUT! ENTER EATING LOCATION AGAIN: ";
            cin >> eating_location;
        }


        
    }
};

int main(){
    
    Self_Order order1;
    

    return 0;
}