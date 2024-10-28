//CPP program for Tic Tac Toe Game

#include <iostream>
using namespace std;

string p1=" ",p2=" ";
char nums[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int digit,row,column;
char token='X';
bool draw=false;

void structure(){
cout<< "\t       |        |      \n";
cout<< "\t  " << nums[0][0]<< "    |  "<< nums[0][1]<< "     |  "<< nums[0][2]<< "  \n  ";
cout<<"\t ______|________|______\n";
cout<< "\t       |        |      \n";
cout<< "\t  " << nums[1][0]<< "    |  "<< nums[1][1]<< "     |  "<< nums[1][2]<< "  \n  ";
cout<<"\t ______|________|______\n";
cout<< "\t       |        |      \n";
cout<< "\t  " << nums[2][0]<< "    |  "<< nums[2][1]<< "     |  "<< nums[2][2]<< "  \n  ";
cout<< "\t       |        |      \n";
cout<< "\t       |        |      \n";
}

void moves(){   
   if(token=='X'){
      cout<<p1 <<",Enter the place you want: ";
      cin>>digit;
   }
   if(token=='O'){
      cout<<p2 <<",Enter the place you want: ";
      cin>>digit;
   }

   if(digit==1){
      row=0;
      column=0;
   }
   if(digit==2){
      row=0;
      column=1;
   }
   if(digit==3){
      row=0;
      column=2;
   }
   if(digit==4){
      row=1;
      column=0;
   }
   if(digit==5){
      row=1;
      column=1;
   }
   if(digit==6){
      row=1;
      column=2;
   }
   if(digit==7){
      row=2;
      column=0;
   }
   if(digit==8){
      row=2;
      column=1;
   }
   if(digit==9){
      row=2;
      column=2;
   }
   else if(digit<1 || digit>9)
      cout<<"Invalid number! \n";

   if(token=='X' && nums[row][column]!='X' &&  nums[row][column]!='O' ){
      nums[row][column]='X' ;
      token='O';
   }
   else if(token=='O' && nums[row][column]!='O' &&  nums[row][column]!='X' ){
      nums[row][column]='O' ;
      token='X';
   }
   else{
      cout<<"No empty space \n";
      //moves();
   }
   structure();
}

bool checkCondition(){
   for(int i=0;i<3;i++){

      if(nums[0][i]==nums[1][i] && nums[0][i]==nums[2][i]  ||            
      nums[i][0]==nums[i][1] && nums[i][0]==nums[i][2] )
      return true;

      if(nums[0][0]==nums[1][1] && nums[1][1]==nums[2][2] || 
      nums[0][2]==nums[1][1] && nums[0][2]==nums[2][0])
      return true;
   }
   for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         if(nums[i][j]!='X' && nums[i][j]!='O')
            return false;
      }
   }
   draw=true;
   return false;
}

int main(){
   cout<<"====================Tic Tac Toe Game====================\n";
   cout<<"Enter Player1[X] name: ";
   cin>> p1;
   cout<<"Enter Player2[O] name: ";
   cin>>p2;

   while(!checkCondition()){
      structure();
      moves();
      // checkCondition();
   }

   if(token=='O' && draw==false)
   cout<<p1 <<" Wins!!!";
   else if(token=='X' && draw==false)
   cout<<p2 <<" Wins!!!";
   else
   cout<<"It's a draw!!";

   return 0;
}