Microprocessor Systems
Assignment 2
This was originally made as an assignment for module at Trinity College Dublin called 'Microprocessor Systems' 




In order to install this game, you must first set up a Raspberry Pi Pico. 
Its probably not a bad idea to refer to the Pi Pico documentation https://www.raspberrypi.com/documentation/microcontrollers/raspberry-pi-pico.html.




# Documentation 

Group 28:


AMMAR MAGOMADOV
JAMES MERRINS PRYCE
ARSHAD MOHAMMED
KEVIN MORLEY
THOMAS PATRICK MORONEY

Introduction
The objective of this project is to create a game that teaches players how to use morse code. The player will be able to choose a difficulty level, and based on their chosen level  it will determine whether or not the morse code is provided.  The levels are as follows:


Required:
* Level #1: Individual characters with their equivalent Morse code provided.
* Level #2: Individual characters without their equivalent Morse code provided.
Optional:
* Level #3: Individual words with their equivalent Morse code provided.
* Level #4: Individual words without their equivalent Morse code provided.


The player starts the game with three lives and the LED should be green. If the player inputs an incorrect sequence, then a life is taken away and the LED colour is changed to match. If the player inputs a correct sequence, then a life is added back on, up to a maximum of three, and the LED colour is changed appropriately. If the player loses all three of their lives  the game ends.


The player can start the game at any of the  levels 1-4 and they must get 5 fully correct answers in a row to progress to the next level. The player can work their way up to level 4 at which point, if they get 5 fully correct answers in a row, a message will appear congratulating them on the completion of the game.


The morse code will be input using the GP21 button. Pressing the button equates to a dot and holding the button equates to a dash.Waiting for one second before inputting the next dot or dash will insert a space character before the inputted dot or dash. If no button is pressed for a further 1 second, then the input is considered to be complete. 
Workflow
Team Roles:
Ammar - Project documentation owner:
Responsible for compiling the required documentation and final project report from your team.
Arshad - Gitlab workflow owner:
Responsible for creating a new shared GitLab project repository for your team, providing access to your project team members, and managing code merge requests to the repository.
Jamie - Project workflow owner:
Responsible for the overall organisation of how the project should be run.
Kevin - Project code owner:
Responsible for ensuring that the overall application functions as expected.
Tom - Project demonstration owner:
Responsible for creating a short (90 sec max) video demonstration of the completed code running on a MAKER-PI-PICO project board.




Task Breakdown:
Ammar:
* Set up the document
* Coded the watchdog timer to reset the application after 9 seconds of inactivity
* Co-wrote and debugged level 3 and 4
* Commented the code






Arshad:
* Set up the repository on the scss gitlab
* Got all of the members set up and working with git version control
* Resolved conflicts when merging different branches
* Co-wrote and debugged level 3 and 4


Jamie: 
* Setup the GPIO interrupts
* Created the morse input system
* Created levels 1 and 2
* Co-wrote and debugged level 3 and 4
* Debugged the final product


Kevin:
* Set up Discord server for cooperation and collaboration
* Created welcome message, how to play, other semantic changes
* Various minor changes
* Aided in debugging the final product


Tom:
* Co-wrote and debugged levels 1, 2, 3 and 4
* Created alarm isr interrupt that null terminates the string after 2 seconds of inactivity
* Setup RGB LED and made function to change colour to red, orange, blue or green
* Co-wrote character detection and pattern matching logic
* Recorded Demo video


GitLab 
During our first meeting we decided that Arshad was going to be the person in charge of everything to do with Gitlab. He set up the private repository for everyone and added everyone as a collaborator so that we were all able to commit to it. Our group used separate branches to implement any new feature to the project so as not to add anything that may potentially break the program. We tested each new feature and made sure it worked before merging it to main. We also agreed on an optional yet (highly recommended) approval system. Arshad and some other team members maintained the conflict when merging.  We did not make use of the Gitlab issues feature but instead opted to use Discord as a medium to communicate and assign tasks. We found Discord to be much more efficient for this task. 


Code
Designing a program that fulfilled the specifications turned out to be a challenging and fun task. We knew that the GPIO interrupts that would serve as user input only interrupted the program when executing arm instructions, and some quick tests proved this to be true. This meant that we would always need to branch back to the assign02.S file to handle user input. We started off by printing the welcome banner. The ARM team which consisted of Jamie and Tom began the task of implementing the morse input system. Since we knew this was critical to the function of the final application, the other group members were told to hold back on their respective sections until it was completed. This proved to be a wise decision. Once the morse input system in arm had been implemented, we set about figuring out how to integrate it into the C portion of the project. Thus the readMorseString() function was created.


At the start of the program, we had a problem. We knew how to branch C functions, but we weren’t fully sure how to branch to ARM subroutines. We essentially thought that once we went into main_asm()  from the main function in assign02.c we would be ‘stuck’ there in a way. This was because our ARM file was an infinite loop that waited for interrupts to occur. We had morse input working and debugged, but didn’t know what to do with it. Tom then had the idea of having one C function that ARM would branch to every time a morse sequence was inputted, and this function would do different things depending on the context. This concept was very fruitful and it essentially became the core of our application.


We had a number of global variables in our main C file, and through manipulation of these variables we could implement almost our morse game in readMorseString(). The first thing this function does is check if the game is over. This prevents further input once the user has either lost or won the game. It then decodes the morseString input into either a character or a word, again depending on the global variable ‘isWord’; From there the function is essentially a simple set of nested if statements to deal with the different levels, getting an answer right or wrong, and checking if the user has gotten 5 correct answers in a row.


We used a number of other functions to support readMorseString() and to try to declutter it, (though If we are honest it is still fairly cluttered). All of these were simple to implement and do exactly what the name of the function would suggest. However, there is one other design decision that I would like to discuss. When we were doing levels 1 and 2, we knew we would just define 36 constants in the header file that would decode to the respective alphanumeric characters’ morse representations.
We actually made a struct that would store the alphanumeric characters ASCII code, character and morse string length. Though this proved to not be as useful as we thought it would, we implemented levels 1 and 2 quickly enough. Levels 3 and 4 however proved to be a different story. 


These two levels required us to use whole words instead of single characters. Immediately we were presented with the problem of there not really being a conveniently finite number of options to present to the player. We considered a few options on how to implement the words. Arshad suggested we read in a large number of words, but we quickly decided against it since even if we knew how to do it it just seemed excessive and tedious. Not to mention we would need to make a function to represent all of those words in morse, along with a whole host of other implementation issues.


Jamie put forward an idea of a random generator for words that would essentially put different alphanumeric characters together (“The brief never specified that the words had to be actual legible ones!”). An improvement was suggested where we then compare these words to a dictionary library in C or something along those lines. Ultimately it wasn’t feasible.


The idea we then settled on was a simple one. Everyone selects a number of words to put into a list, and we hardcode the list and their respective morse representations into the program. It was very basic and simple to implement. Also, the idea was put forward that since the aim of the game was to support a player learning morse code, some repeated words may actually reinforce some of the patterns in the players head. This decision was the last major one of the project.


All of the characters and words in the program are given to the player randomly. We figured this was the best way to actually ‘test’ the player, as otherwise the player would quickly learn the first five characters we give them and easily pass level 1 and 2 every time. This makes level 4 particularly hard, as we threw in some very long words in our list as somewhat of a challenge. If a player does manage to complete this level though, they are treated to a nice “You Win!” before the program resets.
