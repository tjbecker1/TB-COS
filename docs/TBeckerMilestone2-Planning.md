> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name:**
→   Console Stock Car Racing
  
**What does your program currently do? (1–3 sentences)**   
→ My program is a C++ console stock car racing game with a main menu where players can start a race, read about the game, or exit. Players enter their name and choose a car number before running a basic five lap race that displays lap times and tracks their total race time.

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   The Main Menu, About screen, and Exit option are working. Players can enter their name and select a car number, with input validation for invalid entries. The basic five lap race also runs, displays lap times, and tracks the player’s total race time.
  
**What is NOT working or incomplete?**   
→   The race simulation is still basic and needs more testing and development for AI competition, varied lap times, and final standings. Fuel consumption, tire wear, driving strategies, and pit stops are not implemented yet.
  
**What feels confusing or messy in your code?**   
→ Connecting the Game, Race, and Driver classes still feels confusing, especially deciding which class should handle each task. Keeping track of the drivers and updating their race times can also get messy. I want to organize these responsibilities more clearly so adding new features is easier.

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   
→   AI involvement
  
**What does this feature do?**   
→   Allows the player to compete against computer controlled drivers with varying lap times. Each driver’s total race time is tracked throughout the race.
  
**Why is this feature important?**   
→   It adds competition and makes races less predictable than using the same lap time every lap.
  
---
### Feature 2  
**Name:**   
→   Final Race Standings
  
**What does this feature do?**   
→   Ranks all drivers by their total race time and displays their finishing positions, with the fastest driver winning.
  
**Why is this feature important?**   
→   It gives the race a clear result and lets the player see how they performed against the AI opponents.
  
---
  
### Feature 3 (optional)  
**Name:**   
→   
  
**What does this feature do?**   
→   
  
**Why is this feature important?**   
→   
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   No new classes are needed for these two features. I can use my existing Game, Race, Driver, and Car classes.
  
**Will you modify any existing classes? How?**   
→   I will update the Race class to manage AI opponents, generate varied lap times, and sort and display final standings. I will use the Driver class’s existing functions to reset and update each driver’s total race time. I will adjust the Game class as needed to connect player setup to the race.
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   I will use a vector of Driver objects to store the player and AI opponents. This lets me loop through all drivers during each lap and sort them by total race time for the final standings.
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   Displays the main menu with Start Race, About, and Exit options.
2. User chooses →   Choosing Start Race prompts the user to enter their name and an available car number.
3. Program responds →   Runs the five lap race against AI opponents, displays lap times.
4. Loop/next step →   Returns to the main menu so the user can race again, read about the game, or exit. Invalid input prompts the user to try again.
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   Clearly explain valid menu choices and car numbers, and label lap times and final standings so the results are easy to read.
  
- Better error handling:   
→   Display specific messages for blank names, invalid numbers, or car numbers already taken by AI drivers, then let the user try again.
  
- Improved menu/navigation:   
→   Make returning to the main menu clear after viewing About or finishing a race, so the user can easily race again or exit.
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   The hardest part will be tracking each driver’s lap times correctly and sorting the final standings. I will also need to make sure every driver’s total time resets when starting another race.
  
**What is your plan if you get stuck?**   
→   I will break the feature into smaller steps and test one part at a time. I will use breakpoints and print statements to check values, review class examples, and ask for help if I still cannot find the problem.
  
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→   I am focusing on using vectors to manage multiple objects and understanding how my Race and Driver classes work together.
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   I will practice looping through the drivers, updating their race times, and sorting the results. I will review class examples and use breakpoints to check that each driver’s information updates correctly.
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [ ]   Variable Lap times - not every lap is the same.
- [ ]   Different Tracks - adds variety to the game.
- [ ]   Car upgrade system - career mode implementation
- [ ]   Save and load progress - continuation and not just a start and stop
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [ ] Do I know what I’m building this week?   
- [ ] Do I know where to start?   
- [ ] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
My goal this week is to make the game feel more like a race by improving AI competition and adding clear finishing results. I want to build and test one feature at a time while getting more comfortable connecting my classes and working with vectors.