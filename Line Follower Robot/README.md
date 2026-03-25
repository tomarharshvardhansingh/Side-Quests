# Line Follower Robot

A simple line follower robot built using Arduino, IR sensors , and motor driver — with focus on real-world debugging and improvements.

---

## 🧠 Goal

## 🎓 Context

This project was originally part of my coursework for the subject **Basics of Robotics Design**.

I used it as a starting point, but extended it beyond the classroom by debugging issues, improving performance, and experimenting with different approaches.

To build a robot that can:
- detect a black line on a surface  
- follow it smoothly  
- handle turns and small errors  

---

## ⚙️ Components Used

- Arduino Uno  
- IR Sensor Module x5
- Motor Driver  
- DC Motors + Wheels  
- Chassis  
- Battery pack  

---

## 🚧 Build Journey

This project was not straightforward. Most of the work involved debugging and improving behavior.

### 🔴 Initial Issues

- Short circuit due to VCC and GND touching  
- Motor driver heating up  
- Sensors giving unstable readings  
- Robot moving in wrong direction  

---

### 🟡 Sensor Problems

- Sensors were very far from the tyre resulting in missed turns
- Sensors not giving correct readings due to faulty wires 
- Digital readings were unreliable  

**Fix:**
- Switched to analog readings  
- Adjusted sensor height (~5 mm)  
- Improved surface contrast (black vs white)

---

### 🔵 Movement Issues

- Robot turning in opposite direction  
- Zig-zag motion at higher speeds  
- Missing turns  

**Fix:**
- Corrected motor direction logic  
- Adjusted turning functions  
- Tuned speed values  

---

### 🟢 Final Behavior

- Moves forward smoothly  
- Follows line with small corrections  
- Handles turns reasonably well  
- Uses analog input for better detection  

---

## 🧪 What I Learned

- Hardware issues can look like software bugs  
- Sensor placement matters more than expected  
- Debugging step-by-step is more effective than guessing  
- Small logic mistakes can completely break behavior  

---

## 📁 Code

Code is available in the `code/` folder.

---

## 📸 Media (optional)

Add images or videos of the robot here.

---

## 🚀 Future Direction

- Upgrade this robot into a **maze solving robot** using the same hardware setup  
- Implement more advanced logic for path memory and decision making  
- Improve speed and accuracy further  
- Experiment with PID control for smoother motion  
