# Pac-Man 🎮 (Console Version)

A simplified version of the classic Pac-Man game built in C++, running directly in the terminal.

This project was created to practice object-oriented programming, game logic, and console-based interface design.

---

## 🧠 Game Features
- Console-based visual representation (ASCII)
- Player movement via keyboard
- Ghost enemies with basic movement
- Collectible dots (points)
- Walls and maze logic
- Score tracking

---

## 🛠️ Technologies Used
- C++
- Console I/O (no external libraries)
- OOP principles

---

## 🗂️ Project Structure


- **`include/`**: תיקיית ההגדרות (header files). כאן נמצאים קבצי ה־.h, שהם קבצים עם הכרזות של פונקציות, מחלקות ומבנים שמהם שאר הקבצים בפרויקט משתמשים. זו דרך לארגן ולהפריד את הקוד בצורה מסודרת.
  
- **`src/`**: תיקיית הקוד (implementation files). כאן נמצאים קבצי ה־.cpp, שהם קבצי הקוד שבם נמצא הלוגיקה של המשחק. כל קובץ אחראי על חלק מהמשחק, כמו לוח המשחק, השחקן, הרוחות, וכדומה.
  
- **`main.cpp`**: קובץ ה־entry point של הפרויקט. זהו הקובץ שבו מתחיל המשחק. הוא מאתחל את כל המרכיבים של המשחק (למשל לוח המשחק, השחקן, וכו') ומריץ את הלולאה הראשית של המשחק.

ה
## ▶️ How to Compile and Run

### 🔧 Requirements:
C++ compiler

### 🧪 Compilation:

```bash
g++ -o pacman main.cpp src/*.cpp -Iinclude


📚 What I Learned
Managing game state and logic

Using classes and separation of concerns

Console rendering using ASCII characters

Building a basic game engine loop

Keyboard input handling (platform-dependent)

🙋‍♀️ About Me
Hi! I'm Dunia Khanfa, a second-year Information Systems student with a passion for programming and game design.

This project was created as part of my learning journey in C++.
Feel free to fork, clone, or send me feedback!

📧 duniakhanfa@gmail.com
📱 054-2099827

