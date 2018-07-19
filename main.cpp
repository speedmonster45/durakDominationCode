#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>

using namespace std;

class CardDeck
{
  private:
    vector <string> cardSet;
    string numValue[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    string suit[4] = {"H","S","D","C"};
    vector<string> randDeck;
    vector<string> currentCards;

  public:
    void createDeck();
    void shuffleDeck();
    string getCard();
    bool isGreater(string& card1, string& card2);
};

void CardDeck::createDeck()
{
  int i = 0;
  int j = 0;
  int x;
  
  cout << "This is the UNSHUFFLED deck. \n \n"<< endl;

  for(int i = 0; i < 4; i++)
  {
    for(int f = 0; f < 13; f++)
    {
      cardSet.push_back(numValue[j] + suit[i]);
      j++; 
       
      cout << x+1 << "\t" << cardSet[x] << endl;
      x++;
    } 
    j = 0;  
  }

  cout << endl << endl;
}

void CardDeck::shuffleDeck()
{
  randDeck = cardSet;
  srand (time(NULL));
  random_shuffle (randDeck.begin(), randDeck.end());

  cout << "This the SHUFFLED deck. \n \n" << endl;
 for(int i = 0; i < 52; i++) 
  cout << i << "    " << randDeck[i] << endl; 
  cout << endl << endl;

}
string CardDeck::getCard()
{
  string card = randDeck[rand()%52];
  currentCards.push_back(card);
  return card;
}

bool CardDeck::isGreater(string& card1, string& card2)
{
  int x = 1 + distance(cardSet.begin(),find(cardSet.begin(), cardSet.end() , card1));

  int y = 1 + distance(cardSet.begin(),find(cardSet.begin(), cardSet.end() , card2));

  cout << "Cards position on the desk set." << endl;
  cout << x << "\t" << y << endl << endl;
  cout << "Remainder" << endl;
  cout << x%13  << "\t" << y%13 << endl << endl;

  if(x%13 == 0)
  {
    cout << card1 << "  >  " << card2 << endl;
    return true;
  }
  else if(y%13 == 0)
    return false;

  else if(x%13 > y%13)
  {
    cout << card1 << "  >  " << card2 << endl;
    return true;
  }
  else
  return false;
}

int main() {
  
  CardDeck d;
  string a, b;

  d.createDeck();
  d.shuffleDeck();
  a = d.getCard();
  b = d.getCard();

  cout << a << "\t" << b << endl << endl << endl;

if(d.isGreater(a,b))
  cout << "Yes" << endl;

}
