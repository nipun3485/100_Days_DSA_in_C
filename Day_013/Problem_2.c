int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int top=0;
    int bottom=matrixSize-1;
    int left=0;
    int right=matrixColSize[0]-1;
    int total=matrixSize*matrixColSize[0];
    int*result=(int*)malloc(sizeof(int)*total);
    int idx=0;
    while(top<=bottom && left<=right){
        for(int j=left;j<=right;j++)
        result[idx++]=matrix[top][j];
        top++;
        for(int i=top;i<=bottom;i++)
        result[idx++]=matrix[i][right];
        right--;
        if(top<=bottom){
            for(int j=right;j>=left;j--)
            result[idx++]=matrix[bottom][j];
            bottom--;

        }
        if (left<=right){
            for(int i=bottom;i>=top;i--)
            result[idx++]=matrix[i][left];
            left++;
        }
    }

    
    *returnSize=idx;
     return result;
    
}
