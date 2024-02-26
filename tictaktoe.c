#include<stdio.h> 
//Tic Tak Toe game code(proggram by roki vai)
void printmaze(char arr[]){
     printf("\n _____ _____ _____ \n\n|  %c  |  %c  |  %c  |\n|    1|    2|    3|\n _____ _____ _____ \n\n|  %c  |  %c  |  %c  |\n|    4|    5|    6|\n _____ _____ _____ \n\n|  %c  |  %c  |  %c  |\n|    7|    8|    9|\n _____ _____ _____ \n\n_____________________________________",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8]);

}

int playerinput(int *ptr){
    int input;
    if(*ptr==1)*ptr=2;
    else *ptr=1;
    if(*ptr==1) printf("[X]  "); else printf("[O]  ");
    printf("Player%d Turn -->", *ptr);
    scanf("%d",&input);
    if(input<1 || input>9) return 0;//invalid input
    return input;
}
void updatemaze(int user , int num, char arr[]){
  if(user==1){
    arr[num-1]='X';
  } else {
    arr[num-1]='O';
  } return;
}
int winnerchach(char arr[],int user,int i){
    //row win
    if((arr[0]==arr[1])&&(arr[1]==arr[2])&& arr[2]!=' ' || (arr[3]==arr[4])&&(arr[4]==arr[5]) && arr[5]!=' ' || (arr[6]==arr[7])&&(arr[7]==arr[8])&& arr[8]!=' ' ) return 1;
    //colume win
    else if((arr[0]==arr[3])&&(arr[3]==arr[6])&& arr[6]!=' '  || (arr[1]==arr[4])&&(arr[4]==arr[7])&& arr[7]!=' '  || (arr[2]==arr[5])&&(arr[5]==arr[8])&& arr[8]!=' ' ) return 1;
    //diagonal win
    else if((arr[0]==arr[4])&&(arr[4]==arr[8])&& arr[8]!=' '  || (arr[2]==arr[4])&&(arr[4]==arr[6])&& arr[6]!=' ' ) return 1;
    //draw
    else if(i==8) return 2;
    else return 0;
}
void printwinner(int chack,int user){
    if(chack==1){
        printf("Game over\n The Winner Is Player%d\n  ",user);
    } else if(chack==2) {
        printf("Game is Draw, play again.....");
    }
    return;
}


int main(){
    char arr[9];
    int user=2;
    int *ptr=&user;
    for(int i=0;i<9;i++){
        arr[i]=' ';
    }
    printf("\n\n*********************\n*****WELLCOME TO*****\n*****TIC TAK TOE*****\n*********************");
    printmaze(arr);
    
    for(int i=0; i<9;i++){
    int num=playerinput(ptr);

    if(num==0 || arr[num-1]!=' ') {
        printf("INvalide Input");
        break;
    }

    updatemaze(user,num,arr);
    printmaze(arr);

    if(i>=4){
        int chack=winnerchach(arr,*ptr,i);
        printwinner(chack,user);
        if(chack==1 || chack==2) break;
    }
    }
    
    return 0;
}
