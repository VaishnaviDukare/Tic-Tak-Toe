#include<iostream>
using namespace std;
char space[3][3]={{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}
    };
int row,column;
char token='X';
bool tie;
string p1="";
string p2="";
void function1(){
   
    cout<<"     |       |    "<<endl;
    cout<<" "<<space[0][0]<<"   |  "<< space[0][1] <<"    |  "<<space[0][2]<<" "<<endl;
    cout<<" ____|_______|____"<<endl;
    cout<<"     |       |    "<<endl;
    cout<<" "<<space[1][0]<<"   |  "<< space[1][1] <<"    |  "<<space[1][2]<<" "<<endl;
    cout<<" ____|_______|____"<<endl;
    cout<<"     |       |    "<<endl;
    cout<<" "<<space[2][0]<<"   |  "<< space[2][1] <<"    |  "<<space[2][2]<<" "<<endl; 
    cout<<"     |       |    "<<endl;
    cout<<endl;
    cout<<endl;
}
void function2(){
    int digit;
    if(token=='X'){
        cout<<p1<<" Enter the digit:"<<endl;
        cin>>digit;
    }
    if(token=='0'){
        cout<<p2<<" Enter the digit:"<<endl;
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
    } else if(digit<1 && digit>9){
        cout<<"Invalid!! "<<endl;
    }
   

    if(token=='X' && space[row][column]!='X' && space[row][column]!='0'){
        space[row][column]='X';
        token='0';
    }
    else if(token=='0' && space[row][column]!='X' && space[row][column]!='0'){
        space[row][column]='0';
        token='X';
    }
    else{
        cout<<"There is no empty space!  "<<endl;
        function2();
    }
    function1();
}
bool function3(){
    for(int i=0;i<3;i++){
        if((space[i][0]==space[i][1] &&space[i][0]==space[i][2] )||
        (space[0][i]==space[1][i] &&space[0][i]==space[2][i] )){
            return true;
        }  
    }
    if((space[0][0]== space[1][1] && space[1][1]==space[2][2]) ||
     (space[0][2]== space[1][1] && space[1][1]==space[2][0]) ){
        return true;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j]!='X' && space[i][j]!='0'){
                return false;
            }
        }
    }
    tie=true;
    return false;
}
int main(){
    cout<<"Enter the name of the first player:"<<endl;
    getline(cin,p1);
    cout<<"Enter the name of the second player:"<<endl;
    getline(cin,p2);
    cout<<p1<<" is first Player so he/she will play first:"<<endl;
    cout<<p2<<" is second Player so he/she will play second:"<<endl;
    while(function3()==false){
        function1();
        function2();
        function3();

    }
    if(token=='X' && tie==false){
        cout<<p2<<" Wins!!"<<endl;
    }
    else if(token=='0' && tie==false){
        cout<<p1<<" Wins!!"<<endl;
    }
    else{
        cout<<"Its a Tie"<<endl;
    }
    return 0;
}