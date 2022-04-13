#define A ".-"
#define B "-.."
#define C "-.-."
#define D "-.."
#define E "."
#define F "..-."
#define G "--."
#define H "...."
#define I ".."
#define J ".---"
#define K "-.-"
#define L ".-.."
#define M "--"
#define N "-."
#define O "---"
#define P ".--."
#define Q "--.-"
#define R ".-."
#define S "..."
#define T "-"
#define U "..-"
#define V "...-"
#define W ".--"
#define X "-..-"
#define Y "-.--"
#define Z "--.."

#define MORSE_GORILLA "--. --- .-. .. .-.. .-.. .-"
#define MORSE_SPINNER "... .--. .. -. -. . .-."
#define MORSE_RODENT ".-. --- -.. . -. -"
#define MORSE_MOTHER "-- --- - .... . .-."
#define MORSE_HOUSE ".... --- ..- ... ."
#define MORSE_BADMINTON "-... .- -.. -- .. -. - --- -."
#define MORSE_LEAGUE ".-.. . .- --. ..- ."
#define MORSE_ALARM ".- .-.. .- .-. --"
#define MORSE_PARK ".--. .- .-. -.-"
#define MORSE_RUN ".-. ..- -."
#define MORSE_SIT "... .. -"
#define MORSE_CHAIR "-.-. .... .- .. .-."
#define MORSE_PICO ".--. .. -.-. ---"
#define MORSE_PI ".--. .."
#define MORSE_MICROPROCESSOR "-- .. -.-. .-. --- .--. .-. --- -.-. . ... ... --- .-."
#define MORSE_DISCORD "-.. .. ... -.-. --- .-. -.."
#define MORSE_VSCODE "...- ... -.-. --- -.. ."
#define MORSE_LIFTING ".-.. .. ..-. - .. -. --."
#define MORSE_SQUAT "... --.- ..- .- -"
#define MORSE_DEADLIFT "-.. . .- -.. .-.. .. ..-. -"
#define MORSE_DOG "-.. --- --."
#define MORSE_CAT "-.-. .- -"
#define MORSE_FISH "..-. .. ... ...."
#define MORSE_BROTHER "-... .-. --- - .... . .-."
#define MORSE_DAD "-.. .- -.."
#define MORSE_IRELAND ".. .-. . .-.. .- -. -.."
#define MORSE_TRINITY "- .-. .. -. .. - -.--"
#define MORSE_JAMIE ".--- .- -- .. ."
#define MORSE_TOM "- --- --"
#define MORSE_ARSHAD ".- .-. ... .... .- -.."
#define MORSE_AMMAR ".- -- -- .- .-."
#define MORSE_KEVIN "-.- . ...- .. -."
#define MORSE_COLLEGE "-.-. --- .-.. .-.. . --. ."
#define MORSE_COW "-.-. --- .--"
#define MORSE_POT ".--. --- -"
#define MORSE_CLAY "-.-. .-.. .- -.--"
#define MORSE_ANTIDISESTABLISHMENTARIANISM ".- -. - .. -.. .. ... . ... - .- -... .-.. .. ... .... -- . -. - .- .-. .. .- -. .. ... --" 
#define MORSE_MOUSE "-- --- ..- ... ."
#define MORSE_MONKEY "-- --- -. -.- . -.--"
#define MORSE_JOSH ".--- --- ... ...."

#define ZERO "-----"
#define ONE ".----"
#define TWO "..---"
#define THREE "...--"
#define FOUR "....-"
#define FIVE "....."
#define SIX "-...."
#define SEVEN "--..."
#define EIGHT "---.."
#define NINE "----."


typedef struct {
    char AsciiChar;
    char * morseRepresentation;
    int morseLength;
} morseChar;

const morseChar a = {65, A, 3};
const morseChar b = {66, B, 5};
const morseChar c = {67, C, 5};
const morseChar d = {68, D, 4};
const morseChar e = {69, E, 2};
const morseChar f = {70, F, 5};
const morseChar g = {71, G, 4};
const morseChar h = {72, H, 5};
const morseChar i = {73, I, 3};
const morseChar j = {74, J, 5};
const morseChar k = {75, K, 4};
const morseChar l = {76, L, 5};
const morseChar m = {77, M, 3};
const morseChar n = {78, N, 3};
const morseChar o = {79, O, 4};
const morseChar p = {80, P, 5};
const morseChar q = {81, Q, 5};
const morseChar r = {82, R, 4};
const morseChar s = {83, S, 4};
const morseChar t = {84, T, 2};
const morseChar u = {85, U, 4};
const morseChar v = {86, V, 5};
const morseChar w = {87, W, 4};
const morseChar x = {88, X, 5};
const morseChar y = {89, Y, 5};
const morseChar z = {90, Z, 5};

const morseChar zero = {48, ZERO, 6};
const morseChar one = {49, ONE, 6};
const morseChar two = {50, TWO, 6};
const morseChar three = {51, THREE, 6};
const morseChar four = {52, FOUR, 6};
const morseChar five = {53, FIVE, 6};
const morseChar six = {54, SIX, 6};
const morseChar seven = {55, SEVEN, 6};
const morseChar eight = {56, EIGHT, 6};
const morseChar nine = {57, NINE, 6};

char * morseString;     //Declare array to store morse string in
int morseStringIndex = 0;
int currentLevel;

int lifeCount;
int correctInARow;
int randomArrayIndex;
int randomNumberOrder[36];
char currentCharacter;
int questionsCorrect;
int questionsIncorrect;
float correctPercentage;

char level1and2();
void changeLifeCount(bool upOrDown);

void asm_gpio_init(uint pin);
void asm_gpio_set_dir(uint pin, bool out);
bool asm_gpio_get(uint pin);
void asm_gpio_put(uint pin, bool value);
void asm_gpio_set_irq_fall(uint pin);
void asm_gpio_set_irq_rise(uint pin);
void morseStringAdd(char characterToAdd);
bool compareMorseStruct(char * inputMorse, int inputLength, char * patternMorse, int patternLength);
void readMorseString();





// printf("                   ooooo  oooo   ooooooo   ooooo  oooo    oooo     oooo ooooo oooo   oooo                     ");
// printf("                     888  88   o888   888o  888    88      88   88  88   888   8888o  88                      ");
// printf("ooooooooo ooooooooo    888     888     888  888    88       88 888 88    888   88 888o88  ooooooooo ooooooooo ");
// printf("                       888     888o   o888  888    88        888 888     888   88   8888                      ");
// printf("                      o888o      88ooo88     888oo88          8   8     o888o o88o    88                      ");
