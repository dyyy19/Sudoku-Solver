#include <stdio.h>
#define true 1
#define false 0

int isValid(int mat[9][9], int k, int r, int c){
    for(int row = 0; row < 9; row++){
        if(mat[row][c] == k)
            return false;
    }
    
    for(int col = 0; col < 9; col++){
        if(mat[r][col] == k)
            return false;
    }
    
    int rowstart = r - (r%3);
    int colstart = c - (c%3);

    //check box
    for(int row = rowstart; row < rowstart + 3; row++){
        for(int col = colstart; col < colstart + 3; col++){
            if(mat[row][col] == k)
                return false;
        }
    }
    
    return true;
}

int solve(int mat[9][9], int r, int c){
    
    if(r == 9)
        return true;
    
    if(c == 9){
        r++;
        c = 0;
    }
    
    if(mat[r][c] != 0)
        return solve(mat, r, c+1);
        
    for(int i = 1; i <= 9; i++){
        if(isValid(mat, i, r, c)){
            mat[r][c] = i;
            if(solve(mat, r, c+1))
                return true;
        mat[r][c] = 0;
        }
    }
    
    return false;
}

void solveSudoku(int mat[9][9]) {
    solve(mat, 0, 0);
}

int main(){
    int mat[9][9] = { 
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    solveSudoku(mat);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
