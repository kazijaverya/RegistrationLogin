💻 C++ Login and Registration System 🔐  
This project is a simple and interactive login and registration system built using C++. It allows users to register new accounts and log into existing ones, all while managing user data through a text file. 📄✨

🧠 How It Works:
👥 User Structure:
It defines a User structure to store each person's username and password.

📂 Data Storage:
The program loads and saves user data from a file called users.txt, so user info stays safe even after closing the program.

🆕 Registration:

It asks the user to enter a new username and password.

Before registering, it checks if the username already exists (case-insensitive) ❌👤

If it's available, it adds the user and saves the info to the file. ✅💾

🔓 Login:

The user enters their username and password.

If both match an entry in the file, the system logs them in successfully. 🎉

If not, it shows a friendly error message. 🚫

📋 Menu System:

The program runs in a loop and gives users three choices:

Register

Login

Exit

It responds immediately based on the user's choice. 🧭

🌟 Features:
🔄 Persistent storage (via users.txt)

🔍 Case-insensitive username check

📚 Clean and modular code structure

🧹 Easy to understand and expand
