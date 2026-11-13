## Features Added

- Added a tire wear penalty that increases lap times as tire condition decreases. This gives players a reason to consider changing tires during the race.
    
- Added player pit stops that restore fuel and tires and add a 15 second penalty to total race time.
    
- Added randomized AI pit laps so opponents can stop on different laps.
    

## System Design Updates

- Continued connecting the Race, Driver, and Car classes. Race manages race progression, Driver tracks total race time, and Car manages fuel and tire condition.
    
- Used the mDrivers vector to process the player and AI drivers through the same lap simulation.
    

## Refactoring Improvements

- Moved lap time calculations into CalculateLapTimes. The race loop now passes the driver and base lap time to this function, keeping the tire wear calculation separate from race progression.
    
- Moved the console output for each driver’s lap into DisplayLapResult. This keeps the formatting in one place and makes the main lap loop easier to read.
    
- Replaced several numeric values in Race::Run with named constants for fuel usage, tire wear, pit stop time, and menu choices. These names make the values easier to understand and adjust.
    

## What Changed and Why

- Corrected the AI pit lap range after an invalid upper limit caused the program to stop in the debugger. The range now allows valid pit laps before the race finishes.
    
- Fixed the menu choice check that returned the player to the main menu when choosing to keep racing.
    
- Worked on separating individual lap time from total race time in the pit stop output so players can understand how the penalty affects their race.
    
- Resolved variable scope issues encountered while reorganizing the race code.
    

These changes make the race more interactive and make its calculations and output easier to maintain. Remaining work includes track selection, further input validation improvements, and additional testing of race resets and pit stop behavior.