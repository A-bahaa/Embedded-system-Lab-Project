# Embedded-system-Lab-Project
## Race-game

## How to run it ?
- Simply , download the [KEIL](https://www.keil.com/download/product/) software on your machine along with the project files in this repo and your good to go.

## What components do you need?
- push-button (switch) x 3
- Breadboard
- Nokia 5110 Blue Screen
- 20x male to male wires
- 10x male to female wires
- ADC Slider 
- 10kΩ resistors x 5
- LEDs x 5
- 470Ω resistors x 5

## How it works?

![8257e94d-1b15-410e-bcb8-daa1d07c5664](https://user-images.githubusercontent.com/65967989/169586318-ddde70b7-6a2d-48d5-8fd1-ccd955de39d8.jpg)

- **First of all**, we split the Nokia 5110 into five tracks as illustrated in the photo above. The player's car is always in the bottom row and it only moves horizontally while the enemies cars come randomly in the five tracks and move only vertically down towards the player’s car trying to crash.

- **How the enemies are generated?** Using the random module we randomly generate two integers each representing a group of enemies. Using modular arithmetics (%31) along with the rand function we make sure that the randomly generated integer is always between 0 (00000) and 30 (11110), so when we use the binary representation of that integer to generate the enemies (if the ith bit is set then the ith tracker has an enemy, otherwise it’s empty) we make sure that at least one track is empty so the player can escape crashing.We make sure the two groups of enemies come one after the other by initializing the vertical position of them separated by the car height `vertical_pos1 = CARH, vertical_pos2 =  CARH - 24 ` so we’d never have the conflict of a cell being occupied by two cars at the same time.

- **How to survive (How the ADC is working)?**  As stated before the player always has at least one empty cell so the player should use the ADC slider to change the horizontal position of his/her car to avoid crashing. But how the ADC manages to do that? By setting `ADC0_EMUX_R = (0XF<<12)`, the Sample-Sequencer-3 is set to run continuously checking if there's a new input signal issued by the player and if finds any, an interrupt is raised and the new slider position is reassigned into the addData variable `addData = ADC0_SSFIFO3_R`. then this new value updates the position of the player. If the player manages to survive a group of the enemy(the group of the enemy reached the bottom of the screen without crashing ), then this group of the enemy is erased and a new random one is generated and the player's score is increased by 1.

- **How to crach?** The player’s car has a fixed vertical position and its region begins after the 37th bit on the y-axis, so whenever a group of the enemy is beneath that level we check if a car of that enemy group is currently on the same track as the car’s player with ± 4-bit range . If the condition is met then the game over screen is displayed along with the player’s score and level which is `score/10` .

![photo5782785543074069054 (1)](https://user-images.githubusercontent.com/65967989/169593194-4008d0f6-d088-4b93-adb2-17d2a0e687e8.jpg)

- **How to wire the project ?**
// Blue Nokia 5110

// ---------------

// Signal        (Nokia 5110) LaunchPad pin

// Reset         (RST, pin 1) connected to PA7

// SSI0Fss       (CE,  pin 2) connected to PA3

// Data/Command  (DC,  pin 3) connected to PA6

// SSI0Tx        (Din, pin 4) connected to PA5

// SSI0Clk       (Clk, pin 5) connected to PA2

// 3.3V          (Vcc, pin 6) power

// back light    (BL,  pin 7) not connected, consists of 4 white LEDs which draw ~80mA total

// Ground        (Gnd, pin 8) ground

## Demo video


https://user-images.githubusercontent.com/65967989/169593994-3844bdc2-c691-49c1-9aa7-e1062d40c6e0.mp4

