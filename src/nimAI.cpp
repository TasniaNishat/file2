#include <iostream>
#include<math.h>
using namespace std;

//changes are made


//flag for no good move
const int No_Good_Move=-1;

void takeLegalUserMove(int &nTake);

//recursive Functions
int findGoodMove(int nCoins);
bool isBadPosition(int nCoins);


int main() {

    int nCoins = 13;
    int take;
    int x;

    bool computerTurn = false;

    cout<<"There are "<<nCoins<<" coins on an imaginary table"<<endl;
    cout<<"We will both take turns taking either 1,2 or 3 coins."<<endl;
    cout<<"The person who is forced to take the last coin loses"<<endl;



    while(nCoins>1){

        cout<<"There are "<<nCoins<<" coins"<<endl;

        if(computerTurn){
            take = findGoodMove(nCoins);

            if(take==-1)
                take=1;

            cout<<"I'll take "<<take<<" coins"<<endl;

            computerTurn=false;
        }
        else{
            cout<<"How many do you wish to take?: ";
            takeLegalUserMove(take);
            computerTurn=true;


        }

        nCoins -= take;

    }

    cout<<"There is "<<nCoins<<" left";

    if(computerTurn)
        cout<<" I lose"<<endl;
    else
        cout<<" I win !"<<endl;



    cout<<"Thank you for playing Any key + return to exit";
    cin>>x;


    return 0;




}

int findGoodMove(int nCoins){

    for(int ntaken = 1; ntaken<=3; ntaken++){

        if(isBadPosition(nCoins-ntaken))
            return ntaken;
    }


    return No_Good_Move;
}


bool isBadPosition(int nCoins){


    if(nCoins==1)
        return true;

    return findGoodMove(nCoins) == No_Good_Move;

}

void takeLegalUserMove(int &nTake){

    while(true){

        cin>>nTake;

        if(nTake>=1 && nTake<=3)
            break;


        else{
            cout<<"Eisob KI!? You have to take numbers in between 1 to 3!"<<endl;
            cout<<"How many do you wish to take?: ";

        }
    }



}
