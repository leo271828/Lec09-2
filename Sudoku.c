
void check_sudoku(int a[][NUM]){
    int answer[NUM][NUM];
    for(int i=0;i<NUM;i++)
        for(int j=0;j<NUM;j++)
            answer[i][j] = 0;
    
    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){

            int square_list[9];
            for(int k=0;k<9;k++){
                int square_num = a[i+k/3][j+k%3];
                square_list[k] = square_num;

                for(int t=0;t<k;t++){
                    if (square_num == square_list[t]){
                        answer[i+k/3][j+k%3] = 1;
                        answer[i+t/3][j+t%3] = 1;
                    }
                }
            }

        }
    }
    // row check
    for(int i=0;i<NUM;i++){ // row
        int column_list[9], row_list[9];
        for(int j=0;j<NUM;j++){
            column_list[j] = 0;
            row_list[j] = 0;
        }
        
        // every column & row
        for(int j=0;j<NUM;j++){
            int column_num = a[i][j];
            int row_num = a[j][i];

            column_list[j] = column_num;
            row_list[j] = row_num;

            for(int k=0;k<j;k++){
                if (column_num == column_list[k]){
                    answer[i][k] = 1;
                    answer[i][j] = 1;
                }
                if (row_num == row_list[k]){
                    answer[k][i] = 1;
                    answer[j][i] = 1;
                }
            }
        }

    }
    // result
    for(int i=0;i<NUM;i++)
        for(int j=0;j<NUM;j++)
            if(answer[i][j] == 1)
                printf("(%d,%d)\n", i, j);
            // printf("%d ", answer[i][j]);
}
