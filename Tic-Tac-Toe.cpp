#include<iostream>
#include<random>
#include<ctime>

using namespace std;

char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void show_board();
void get_x_player_choice();
void get_o_player_choice();
void get_computer_choice();
int count_board(char symbol);
char check_winner();
void computer_vs_player();
void player_vs_player();

void show_board(){
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<board[0]<<"   |   "<<board[1]<<"   |   "<<board[2]<<endl;
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<board[3]<<"   |   "<<board[4]<<"   |   "<<board[5]<<endl;
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<board[6]<<"   |   "<<board[7]<<"   |   "<<board[8]<<endl;
    cout<<"   "<<"    |   "<<"    |   "<<endl;
}

void get_computer_choice(){
    srand(time(0));
    int choice;
    //Validate choice of the computer to check there position is previously occupied
    do{
        choice = rand()%10;
    }while(board[choice] != ' ');
    board[choice] = 'O';
}

void get_x_player_choice(){
    while(1){
        cout<< " select your position 1 to 9: "<<endl;
        int choice;
        cin>>choice;
        choice--;
        if( choice < 0 || choice > 8){
            cout<< " Please select your choice";
        }
        else if(board[choice] != ' '){
           cout<<" Please select an empty position"<<endl; 
        }
        else{
            board[choice] = 'X';
            break;
        }

    }
}

void get_o_player_choice(){
    while(1){
        cout<< " Select your position 1 to 9: ";
        int choice;
        cin>>choice;
        choice--;
        if( choice < 0 || choice > 8){
            cout<< " Please select your choice";
        }
        else if(board[choice] != ' '){
           cout<<" Please select an empty position"<<endl; 
        }
        else{
            board[choice] = 'O';
            break;
        }

    }
}

int count_board(char symbol){
    int total = 0;
    for(int i = 0; i < 9; i++){
        if(board[i] == symbol)
            total++;
    }
    return total;
}

char check_winner(){
    //checking row condition
    if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
        return board[0];
    if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
        return board[3];
    if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        return board[6];

    //checking column condition
    if(board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
        return board[0];
    if(board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
        return board[1];
    if(board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
        return board[2];
    
    //checking Diagonal condition
    if(board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
        return board[0];
    if(board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
        return board[2];
    
    if(count_board('X') + count_board('O'))
        return 'C';
    else
        return 'D';
}

void computer_vs_player(){
    string player_name;
    cout<<" Enter your name: ";
    cin>>player_name;
    while(true){
        cout<<flush;
        show_board();
        if(count_board('X') == count_board('O')){
            cout<<player_name<< "'s turn "<<endl;
            get_x_player_choice();
        }
        else{
            get_computer_choice();
        }
        char winner = check_winner();
        if(winner == 'X'){
            cout<<flush;
            show_board();
            cout<<player_name<< " won the game";
            break;
        }
        else if(winner == 'O'){
            cout<<flush;
            show_board();
            cout<<"Computer won the game";
            break;
        }
        else if(winner == 'D'){
            cout<<flush;
            show_board();
            cout<<" Game is draw!";
            break;
        }
    }
}

void player_vs_player(){
    string x_player_name, o_player_name;
    cout<<" Enter X player name: ";
    cin>>x_player_name;
    cout<<" Enter O player name: ";
    cin>>o_player_name;
    while(true){
        cout<<flush;
        show_board();
        if(count_board('X') == count_board('O')){
            cout<<x_player_name<<"'s turn "<<endl;
            get_x_player_choice();
        }
        else{
            cout<<o_player_name<<"'s turn "<<endl;
            get_o_player_choice();
        }
        char winner = check_winner();
        if(winner == 'X') {
            cout<<flush;
            show_board();
            cout<<x_player_name<< " is the winner!"<<endl;
            break;
        }
        else if(winner == 'O') {
            cout<<flush;
            show_board();
            cout<<o_player_name<< " is the winner!"<<endl;
            break;
        }
        else if(winner == 'D') {
            cout<<flush;
            show_board();
            cout<<" Game is draw!"<<endl;
            break;
        }    
    }
}

int main(){
    int mode;
    cout<<" Please select Game mode "<<endl;
    cout<< " 1. Computer VS Player "<<endl;
    cout<< " 2. Player VS Player "<<endl;
    cin>>mode;
    switch(mode){
        case 1:
            computer_vs_player();
            break;
        case 2:
            player_vs_player();
            break;
        
        default:
            cout<<" Please enter valid mode to play"<<endl;
    }
    
    return 0;
}


















