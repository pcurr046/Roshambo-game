//Patricia Curry
//12/11/2019

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
string getdefinition(int sel);
void whoWon(int sel, int comp_sel, bool &is_tie);


int main(){
    int selection,
        compu_selection;
    bool what_is_tie=false;

    cout << "1-Rock | 2-Paper | 3-Scissors\nMake selection: ";
    cin >> selection;

//random computer generation;    
    int seed=time(NULL); //seed time to unix time
    srand(seed);
    int max_rand=3;
    int min_rand=1;
    compu_selection=random()%3+1;

    whoWon(selection, compu_selection, what_is_tie);

    while(what_is_tie){
        cout << "1-Rock | 2-Paper | 3-Scissors\nMake selection: ";
        cin >> selection;
        getdefinition(selection);
        what_is_tie=false;        
        compu_selection=random()%3+1;
        whoWon(selection, compu_selection, what_is_tie);
    }
return 0;
}

string getdefinition(int sel){
     const string sel1="Rock", 
                  sel2="Paper",
                  sel3="Scissors";
     string selection_player;
     switch(sel){
         case 1: selection_player=sel1;
                 break;
         case 2: selection_player=sel2;
                 break;
         case 3: selection_player=sel3;
                 break;
     }
     return selection_player;
}

void whoWon(int select, int comp_sel, bool &is_tie){
    switch(select){

      case 1: switch(comp_sel){
                  case 1: cout << "Computer chose Rock - Tie!\n";
                          is_tie = true;
                          break;
                  case 2: cout << "Computer chose Paper - Computer wins!\n";
                          break;
                  case 3: cout << "Computer chose Scissors - You win!\n";
                          break;
                          }
              break;
      case 2: switch(comp_sel){
                  case 1: cout << "Computer chose Rock - You win!\n";
                          break;
                  case 2: cout << "Computer chose Paper - Tie!\n";
                          is_tie = true;
                          break;
                  case 3:cout << "Computer chose Scissors - Computer wins!\n";
                          break;
                          }
              break;
      case 3: switch(comp_sel){
                  case 1: cout << "Computer chose Rock - Computer wins!\n";
                          break;
                  case 2: cout << "Computer chose Paper - You win!\n";
                          break;
                  case 3:cout << "Computer chose Scissors - Tie!\n";
                          is_tie=true;
                          break;
                          }
              break;
    }
}
