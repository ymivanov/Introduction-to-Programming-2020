/*
    As this is a more interesting task that requires more than one case to be covered,
    I would like some of the students attending the 3rd group exercises to provide a 
    solution to discuss and upload here. :)
    
*/
/**
 * @file   playing-cards.cpp
 * @author Victor Nolev
 * @date   19.11.2020
 * @brief  Solution for task 9 from practice 4.
 */

#include <iostream>

const char FINISH_CHAR = 'f';

const char ACE_CHAR = 'A';
const char JACK_CHAR = 'J';
const char QUEEN_CHAR = 'Q';
const char KING_CHAR = 'K';

const int ACE_POSITION = 0;
const int JACK_POSITION = 10;
const int QUEEN_POSITION = 11;
const int KING_POSITION = 12;

// Symbols count from A to K from one color [Ex: There are 13 cards from spades]
const int TOTAL_SYMBOLS_COUNT = 13;

const int CLUBS_POSITION = 0;
const int DIAMONDS_POSITION = 1;
const int HEARTS_POSITION = 2;
const int SPADES_POSITION = 3;


const int FIRST_VALID_POSITION = ACE_POSITION;
const int LAST_VALID_POSITION = 51;

void printSymbolOfChosenCard(short positionEntered, const short SELECTED_COLOR);
void printColorOfChosenCard(const short SELECTED_COLOR);

int main() {

    char consoleChar = 'F'; // Assign any other symbol different than FINISH_CHAR

    unsigned short positionEntered = 0;
     do {
         std::cout << "Enter card position [0; 51]: ";
         std::cin >> positionEntered;

         if (positionEntered < FIRST_VALID_POSITION
             || positionEntered > LAST_VALID_POSITION) {

             std::cout << "Invalid position!" << std::endl;
             std::cout << "Try again?" << std::endl;

             std::cout << "Type:" << std::endl;
             std::cout << "f - to finish the game and terminate the program" << std::endl;
             std::cout
                     << "or press any other key (except for the power button :D) on the keyboard to enter a new position"
                     << std::endl;
             std::cin >> consoleChar;
         } else {
             // Position is valid and we can determine the card from the deck
             // Exit from the do-while cycle
             break;
         }
     } while (consoleChar != FINISH_CHAR);

    if (consoleChar == FINISH_CHAR) {
        std::cout << "You chose to finish the game!" << std::endl;
        return 1; // Terminate the program
    }

    // Color of the card
    // Determine color by the remainder
    const short SELECTED_COLOR =
            positionEntered / TOTAL_SYMBOLS_COUNT; // Remainders: 0-Clubs, 1-Diamonds, 2-Hearts, 3-Spades

    printSymbolOfChosenCard(positionEntered, SELECTED_COLOR);
    printColorOfChosenCard(SELECTED_COLOR);

    return 0;
}

void printSymbolOfChosenCard(short positionEntered, const short SELECTED_COLOR) {
    // Determine and print symbol of the chosen card from the deck
    // We iterate only the first card positions from 0 to 12
    // The other positions (>12) can be reduced to a position [0; 12]
    unsigned short currentPosition = 0;
    bool isSymbolFound = false;

    for (int position = FIRST_VALID_POSITION; position < TOTAL_SYMBOLS_COUNT; ++position) {

        if (isSymbolFound) {
            break; // There is no need for more iterations when we already found the symbol
        }

        // Position of clubs is 0 and thus we prevent division by zero
        currentPosition = SELECTED_COLOR == CLUBS_POSITION ?
                          positionEntered - position :
                          positionEntered - (TOTAL_SYMBOLS_COUNT * SELECTED_COLOR);

        switch (currentPosition) {
            case ACE_POSITION:
                isSymbolFound = true;
                std::cout << ACE_CHAR << " ";
                break;
            case JACK_POSITION:
                isSymbolFound = true;
                std::cout << JACK_CHAR << " ";
                break;
            case QUEEN_POSITION:
                isSymbolFound = true;
                std::cout << QUEEN_POSITION << " ";
                break;
            case KING_POSITION:
                isSymbolFound = true;
                std::cout << KING_CHAR << " ";
                break;
            default:
                isSymbolFound = true;
                const short INTEGER_SYMBOL = currentPosition + 1; // Integer from the set [2; 10]
                std::cout << INTEGER_SYMBOL << " ";
                break;
        }
    }
}

void printColorOfChosenCard(const short SELECTED_COLOR) {
    switch (SELECTED_COLOR) {
        case CLUBS_POSITION:
            std::cout << "Clubs" << std::endl;
            break;
        case DIAMONDS_POSITION:
            std::cout << "Diamonds" << std::endl;
            break;
        case HEARTS_POSITION:
            std::cout << "Hearts" << std::endl;
            break;
        case SPADES_POSITION:
            std::cout << "Spades" << std::endl;
            break;
        default:
            std::cout << "???" << std::endl;
            std::cout << "Error occurred while determining the suit of chosen card!" << std::endl;
            break;
    }
}
