#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//rubic encryption, put message in 3d array and preform random maxtrix transformations

//change size of 3d array
int csize = 4;
int main() {
    

    int size = csize*csize*csize;
    char message[size];
    char cube[csize][csize][csize];
    //list of possible entries to salt message with
    char alpha[79] = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`~!@#$%^&*()_+-="+' ';
    char buffer[csize*csize*csize];
    int iter=0;

    //get input and put into cube
    printf("input message\n");
    scanf("%[^\n]",buffer);
    srand(time(NULL));
    int salt =0;
    for(int i=0; i<csize; i++){
        for(int j=0;j<csize;j++){
            for(int k=0; k<csize;k++){
                if(buffer[iter]==NULL || salt ==1){
                salt =1;
                cube[i][j][k] = alpha[rand() %(sizeof(alpha) -1)];
            }
            else{
                cube[i][j][k] = buffer[iter];
                iter++;
            }
            }      
        }
    }
    //test cube susseffully built
    for(int i=0; i<csize; i++){
        for(int j=0;j<csize;j++){
            for(int k=0;k<csize;k++){
                printf("%c ",cube[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    
}

//rotates a 2d slice of the cube either + or - 90 degrees by transposing and reversing rows
char * rotate(char flip[csize][csize], int forward){
    char temp[csize][csize];
    temp = flip;
    if(forward ==0){//-90 reverse then transpose
        for(int i=0; i<csize;i++){

        }

        for(int i=0;i<csize;i++){
            for(int j=0;j<csize;i++){
                temp[i][j] = flip[j][i];
            }
        }
    }
    else{//+90 transpose then reverse
        for(int i=0;i<csize;i++){
            for(int j=0;j<csize;i++){
                temp[i][j] = flip[j][i];
            }
        }
    }
    return temp;
}

//create series of instruction to mix up cube of message
char * createKey(){
    srand(time(NULL));
    int Rkey =rand() %(sizeof(pow(csize,pow(csize,csize))));
    int Fkey =rand() %(sizeof(pow(csize,pow(csize,csize))));
    int Tkey =rand() %(sizeof(pow(csize,pow(csize,csize))));
    int len = floor(log10(abs(Rkey))) + 1;
    char key[len*3];
    int 
    for(int i=0;i<len;i++){

        if(){

        }
    }
}
