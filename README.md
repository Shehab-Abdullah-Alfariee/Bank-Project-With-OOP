# 🏦 Bank Management System – OOP (C++)

A full-featured console-based **Bank Management System** developed in **C++** using **Object-Oriented Programming (OOP)** principles.  
The project simulates real-world banking operations including client management, user authentication, financial transactions, and currency exchange.

---

## 📌 Key Features

### 👥 Client Management
- Add, update, delete, and search clients
- Display full client list
- Persistent client data storage using text files

### 🔐 User Management
- Secure user login system
- Add, update, and delete users
- User permissions management
- List all registered users

### 💰 Banking Operations
- Deposit money
- Withdraw money with balance validation
- Transfer money between accounts
- View total bank balances

### 💱 Currency Exchange
- List and search currencies
- Update exchange rates (admin only)
- Currency calculator
- Currency data stored in `Currencies.txt`

---

## 🧾 Data Storage
- Client data stored in `Clients.txt`
- User data stored in `Users.txt`
- Currency data stored in `Currencies.txt`
- Transaction logs saved in dedicated log files
- Custom delimiter used: `#//#`

---

## 🏷 Data Format Examples

### Data Format (Clients.txt)

AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance<br>
A150#//#197008#//#Shehab Abdullah#//#0536242467#//#20000<br>

 ### Data Format (Users.txt)

FirstName#//#LastName#//#Email#//##//#Phone#//#PasswordWithEncription#//#Permissions<br>
Shehab#//#Al-Fariee#//#shehab.a.alfariee@gmail.com#//#536242467#//#Sh#//#y};<=>#//#-1<br>

---

## 🧱 OOP Concepts Applied
- Encapsulation  
- Inheritance  
- Polymorphism  
- Abstraction  
- Abstract Classes / Interfaces  
- Separation of Concerns using multiple classes  

---

## 🧰 Technologies Used
- **Language:** C++
- **Programming Paradigm:** Object-Oriented Programming (OOP)
- **Storage:** Text files
- **Application Type:** Console Application
- **Compiler:** g++ or any modern C++ compiler

---

## ⚙️ How to Run

```bash
git clone https://github.com/your-username/your-repo-name.git
cd your-repo-name
g++ main.cpp -o bank_system
./bank_system



---
📸 Some Of Screenshots Of Interfaces <br>

## 🖥 Interface (Menu Preview)<br>
===========================================<br>
            Login Screen<br>
===========================================<br>
<img width="1512" height="563" alt="image" src="https://github.com/user-attachments/assets/b355d6e1-ed71-46aa-8825-45bf59010f13" /><br>

===========================================<br>
             Login Register Screen<br>
===========================================<br>
<img width="1223" height="517" alt="image" src="https://github.com/user-attachments/assets/3d2146e7-9436-480e-83d2-dec7ecc2f14d" />

===========================================<br>
            Main Menu Screen<br>
===========================================<br>
<img width="1253" height="649" alt="image" src="https://github.com/user-attachments/assets/018a83ae-ac4b-4a46-85d9-aeeb772ea172" /><br>

===========================================<br>
            Client List Screen<br>
===========================================<br>
<img width="1270" height="639" alt="image" src="https://github.com/user-attachments/assets/d9e8b56b-5b14-4b1e-92f7-3275a411fbe7" /><br>

===========================================<br>
            Find Client Screen<br>
===========================================<br>
<img width="1162" height="680" alt="image" src="https://github.com/user-attachments/assets/55ee62d6-bf0f-49c8-afcc-06daafa290c1" /><br>

===========================================<br>
            Transactions Menue Screen<br>
===========================================<br>
<img width="1308" height="610" alt="image" src="https://github.com/user-attachments/assets/85393f14-6c95-4f34-b200-1fc3af8c869c" /><br>

===========================================<br>
            Deposit Screen<br>
===========================================<br>
<img width="1073" height="722" alt="image" src="https://github.com/user-attachments/assets/3ba39754-704a-42cb-ac2a-8c19e4cf6150" /><br>

===========================================<br>
             Withdraw Screen<br>
===========================================<br>
<img width="1078" height="716" alt="image" src="https://github.com/user-attachments/assets/44ccb429-db64-43f4-a95a-8705a79e4247" /><br>

===========================================<br>
             Total Balances Screen<br>
===========================================<br>
<img width="1210" height="706" alt="image" src="https://github.com/user-attachments/assets/8cf12b1a-9705-49cd-a44d-0b6b37fb9035" /><br>

===========================================<br>
             Transfare Screen<br>
===========================================<br>
<img width="1177" height="971" alt="image" src="https://github.com/user-attachments/assets/77f989d8-0f39-437b-9d9d-3fc952fd4735" /><br>

===========================================<br>
             Transfare Log List Screen<br>
===========================================<br>
<img width="1193" height="514" alt="image" src="https://github.com/user-attachments/assets/76be2f3f-9ec0-4951-aa7f-d30e724d0cb5" /><br>








