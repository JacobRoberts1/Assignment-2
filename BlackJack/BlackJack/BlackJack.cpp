// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class card
{
public:
    int score;
    int dScore;
    char face;
    string symbol;
    void printCard()
    {
        cout << face << " of " << symbol << endl;

        // Value of first card given
        if (face == 'A')
        {
            score = 11;
        }
        else if (face == '2')
        {
            score = 2;
        }
        else if (face == '3')
        {
            score = 3;
        }
        else if (face == '4')
        {
            score = 4;
        }
        else if (face == '5')
        {
            score = 5;
        }
        else if (face == '6')
        {
            score = 6;
        }
        else if (face == '7')
        {
            score = 7;
        }
        else if (face == '8')
        {
            score = 8;
        }
        else if (face == '9')
        {
            score = 9;
        }
        else
        {
            score = 10;
        }
        cout << "Score: " << score << endl;
    }
    void printDealerCard()
    {
        cout << face << " of " << symbol << endl;

        // Value of first card given
        if (face == 'A')
        {
            dScore = 11;
        }
        else if (face == '2')
        {
            dScore = 2;
        }
        else if (face == '3')
        {
            dScore = 3;
        }
        else if (face == '4')
        {
            dScore = 4;
        }
        else if (face == '5')
        {
            dScore = 5;
        }
        else if (face == '6')
        {
            dScore = 6;
        }
        else if (face == '7')
        {
            dScore = 7;
        }
        else if (face == '8')
        {
            dScore = 8;
        }
        else if (face == '9')
        {
            dScore = 9;
        }
        else
        {
            dScore = 10;
        }
        cout << "Score: " << dScore << endl;
    }
};
card deck[52], temp; // Global array of 52 cards



void shuffle()
{
    int n, m;
    for (n = 0; n < 52; n++) // Switches the 1st position of the deck to a random number
    {
        m = rand() % 52; // Generates random number from 0 to 51;
        temp = deck[n];
        deck[n] = deck[m];
        deck[m] = temp;
    }
}

void printDeck()
{
    int k;
    for (k = 0; k < 1; k++) // How many cards you want to display
    {
        deck[k].printCard();
        cout << endl;
    }
}

void printDealerDeck()
{
    int o;
    for (o = 0; o < 1; o++) // How many cards you want to display
    {
        deck[o].printDealerCard();
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    char face[]{ 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' }; //Array of card values
    string symbol[]{ "Hearts", "Diamonds", "Spades", "Clubs" }; // Array of card classes

    int i, j, l{};

    for (i = 0; i < 4; i++) // How many symbols there are
    {
        for (j = 0; j < 13; j++) // How many faces there are
        {
            deck[l].face = face[j];
            deck[l].symbol = symbol[i];
            l++;
        }
    }

    card calcScore;
    int chips = 100;
    int bet;

    // Start of the game

    cout << "---------------------" << endl;
    cout << "|     BLACKJACK     |" << endl;
    cout << "---------------------" << endl;

    cout << "In this game you will be playing against the dealer" << endl;
    cout << "You start with 100 chips, use them wisely" << endl << endl;

    cout << "Welcome, take a seat" << endl;
playAgain:
    cout << "Ok, place your bets" << endl;
    cin >> bet;
    chips = chips - bet;
    cout << endl << "You have bet " << bet << " chips, you have " << chips << " left" << endl;

    int c1score;
    int c2score;
    int plrScore;

    int d1score;
    int d2score;
    int dealerScore;

    cout << "Your cards are:" << endl;
    shuffle(); // Call the shuffle function
    printDeck(); // Call the print deck function
    c1score = calcScore.score; // Get the score from the card class
    shuffle();
    printDeck();
    c2score = calcScore.score;

    plrScore = c1score + c2score;

    cout << endl << "Your score is " << plrScore << endl;

tryAgain:

    cout << "Would you like another card?" << endl << "Answer with 'yes' or 'no'" << endl;

    string hit;
    cin >> hit;

    if (hit == "yes") // Give another card and calculate score again
    {
        cout << "Your new card is the ";
        shuffle();
        printDeck();
    }
    else if (hit == "no") // Reveal dealers cards and check win state
    {
        cout << "The dealers cards are:" << endl;
        shuffle();
        printDealerDeck();
        d1score = calcScore.dScore;
        shuffle();
        printDealerDeck();
        d2score = calcScore.dScore;

        dealerScore = d1score + d2score;

        cout << "The dealer scored " << dealerScore << " points" << endl;

        if (plrScore > dealerScore) // Player has won
        {
            if (plrScore == 21) // Player got blackjack
            {
                cout << "Congrats, you got blackjack" << endl;
                cout << "You now have " << bet * 2.5 << " chips" << endl;
            }
            else
            {
                cout << "Well done, you beat the house" << endl;
                cout << "You now have " << bet * 0.5 << " chips" << endl; // Gives extra chips for winning
            }
        }
        else if (plrScore < dealerScore) // Player has lost
        {
            cout << "The house has won, better luck next time" << endl;
            cout << "You have " << chips << " chips" << endl;
        }
        else if (plrScore == dealerScore) // Player and dealer tie
        {
            cout << "There has been a tie" << endl;
            cout << "You are back to " << chips + bet << " chips" << endl; // Give chips back
        }
    }
    else
    {
        cout << "Wront input detected" << endl;
        cout << "Try again" << endl;
        goto tryAgain; // Repeats the question
    }

    cout << "Do you want to make another bet?" << endl;
    string playAgain;
    cin >> playAgain;

    if (playAgain == "yes")
    {
        goto playAgain;
    }
    else if (playAgain == "no")
    {
        cout << "Ok, thanks for playing" << endl;
        cout << "You finished with " << chips << " chips";
        return 0;
    }
}