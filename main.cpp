#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //Declare the variables for the first two inputs
    int task, nonZero;
    
    //Declare the Matrices that will be used in the program operations
    int MatrixX [5] [8];
    int MatrixY [5] [8];

    //Gets the first two inputs
    cin >> task;
    cin >> nonZero;
    
    int ArraySize = nonZero*3;
    
    // declares an input array for the effcient version of Matrix X and initilizes the efficiient representation of Matrix Y
    int InputArray [ArraySize];
    int ArrayY [30] =  {0,0,1,0,3,9,0,5,5,1,4,2,1,7,3,2,1,4,2,6,8,3,2,2,4,0,1,4,4,7};
    
    //Get the input for matrix X
    for(int i = 0; i < ArraySize ; i++){
        cin >> InputArray[i];
    }
    
    //initializes the sparce matrix for the program operations
    for(int i =0; i<5;i++ ){
        for(int j = 0; j<8;j++){
            MatrixX[i][j] = 0;
            MatrixY[i][j] = 0;
        }
    }
    
    //This for loop uses the efficient versions of the arrays to initialize the sparce matrix for X and Y
    for(int i =1; i <= ArraySize; i++){
        if(i%3 == 0){
            MatrixX [InputArray[i-3]] [InputArray[i-2]] = InputArray[i-1];
            MatrixY [ArrayY[i-3]] [ArrayY[i-2]] = ArrayY[i-1];
        }
    }
    
    //Define the Matrices the will store the result of the operations
    int Z1 [8] [5];
    int Z2 [5] [8];
    int Z3 [8] [8];
    
    //Initialize the Matrix Z1 and Z3 with zeros
    for(int i = 0;i<8;i++){
        for(int j=0;j<5;j++){
            Z1[i][j] = 0;
        }
    }
    
    for(int i =0;i<8;i++){
        for(int j = 0; j<8;j++){
            Z3[i][j] = 0;
        }
    }
    
    //Creates a switch based on the task given in the first input
    switch(task){
        case 1:{
            
            //This for loop switches rows and colums of the matrix X into matrix Z1
            for(int i = 0;i<5;i++){
                for(int j =0;j <8;j++){
                    if(MatrixX[i][j] != 0){
                        Z1[j][i] = MatrixX[i][j];
                    }
                }
            }
            
            //Prints Z1
            for(int i =0;i<8;i++){
                for(int j =0;j<5;j++){
                    if(Z1[i][j] != 0){
                        cout << i << " " << j << " " << Z1[i][j] << " ";
                    }
                }
            }
            
            break;
        }
        case 2: {
            
            //This loop goes row by row and colum by collum storing the addition into Z2
            for(int i =0;i < 5; i ++){
                for(int j = 0; j < 8; j++){
                    Z2 [i] [j] = MatrixX[i][j] + MatrixY[i][j];
                }
            }
            
            //Prints Z2
            for(int i =0; i<5;i++ ){
                for(int j = 0; j<8;j++){
                    if(Z2[i][j] != 0){
                        cout << i << " "<< j << " " << Z2[i][j] << " ";
                    }
                }
            }
    
            break;
        }
        case 3: {
            
            //Gets the transpose of Matrix X like in case 1
            for(int i = 0;i<5;i++){
                for(int j =0;j <8;j++){
                    if(MatrixX[i][j] != 0){
                        Z1[j][i] = MatrixX[i][j];
                    }
                }
            }

            //This for loop goes through both matrices doing multiplication and sum of the arrays
            for(int i = 0;i<8;i++){
                for(int j=0;j<8;j++){
                    for(int k = 0;k<5;k++){
                        Z3[i][j] += Z1[i][k] * MatrixY[k][j];
                    }
                }
            }
            
            //Prints Z3
            for(int i =0;i<8;i++){
                for(int j =0;j<8;j++){
                    if(Z3[i][j] != 0){
                        cout << i << " " << j << " " << Z3[i][j] << " ";
                    }
                }
            }
            break;
        }
        default:
            break;
    }

    return 0;
}

