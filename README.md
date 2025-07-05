# 🍽️ RMOS – Restaurant Menu Ordering System By Team Slayers

RMOS is a console-based Restaurant Menu Ordering System written in C++. It allows customers to browse, search, and place orders, while also providing admin-level settings for editing the menu and viewing order history. Built with attention to input validation, streamlined UX, and a modular structure.

## Team Members

Built collaboratively by a team of 3:
- **Prince Kumar Gupta** 
- **Tanvi Shekhawat** 
- **Shiv Kumar Yadav**

---

## Features

### For Customers:
- View complete menu
- Search menu items
- Sort menu by:
  - Price (Low to High)
  - Price (High to Low)
  - Alphabetical Order
- Place orders with quantity selection
- Generate invoice with CGST & SGST
- Save bill to `RECEIPT.txt`
- Continuous ordering flow

### For Restaurant Owner (via Security Pass):
- Add new items to menu
- Delete existing items
- Edit item ID, name, or price
- View all-time order history from `ORDER.txt`

## Sample Bill Format

```plaintext
-------------------------------
          TAX INVOICE          
-------------------------------
    SLAYER'S DEN RESTAURANT    
-------------------------------
Order No: 1
Date: 5/7/2025
Time: 13:42
-------------------------------
Eating Location: Dine In
-------------------------------
1)Item ID: 1
  Item Name: Water_Bottle
  Item Quantity: 1
  Item Unit Price: 20
  Item Total: 20

-------------------------------
  Subtotal: 20
  CGST @ 2.5%: 0.5
  SGST @ 2.5%: 0.5
-------------------------------
  Grand Total: 21
-------------------------------
     THANK YOU VISIT AGAIN     
-------------------------------
```

## File Structure

- `MENU.txt` – Stores current menu items  
- `ORDER.txt` – Logs all customer orders  
- `RECEIPT.txt` – Saves last generated bill  
- `RMOS.cpp` – Main source file

## Security & Access

Owner features require a security pass to unlock protected settings and history viewing, ensuring safe access for authorized users only.

## 🛠️ Technologies

- Language: C++ 

## Let's Connect

- Connect with Prince Kumar Gupta
on [LinkedIn](https://www.linkedin.com/in/prince-kumar-gupta88) 
and Visit [GitHub](https://github.com/pncgupta88) to explore more projects!
- Connect with Tanvi Shekhawat
on [LinkedIn](https://www.linkedin.com/in/yourprofile) 
and Visit [GitHub](https://github.com/yourusername) to explore more projects!
- Connect with Shiv Yadav
on [LinkedIn](https://www.linkedin.com/in/yourprofile) 
and Visit [GitHub](https://github.com/yourusername) to explore more projects!

---
