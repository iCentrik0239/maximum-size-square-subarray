#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int temp_size,copy_of_i,copy_of_j,size_arr_row,size_arr_column,i,j,binary_array[MAX_SIZE][MAX_SIZE],max_size=0,size_of_subarray[MAX_SIZE][MAX_SIZE],max_size_temp;
    scanf("%d",&size_arr_row);
    scanf("%d",&size_arr_column);
    for(i=0;i<size_arr_row;i++)
        for(j=0;j<size_arr_column;j++)
            scanf("%d",&binary_array[i][j]);
    for(i=0;i<size_arr_row;i++) {
        for(j=0;j<size_arr_column;j++) {
            if(binary_array[i][j]==0) {
                size_of_subarray[i][j]=0;
                continue;
            }
            copy_of_i=i;
            copy_of_j=j;
            temp_size=1;
            while(binary_array[++copy_of_i][j]==1 && binary_array[i][++copy_of_j]==1 && copy_of_i<size_arr_row && copy_of_j<size_arr_column)
                temp_size++;
            size_of_subarray[i][j]=temp_size;
            if(temp_size==1) {
              max_size_temp=1;
              copy_of_i=i;
              copy_of_j=j;
              while(copy_of_i-->=0 && copy_of_j-->=0) {
                    if(size_of_subarray[copy_of_i][copy_of_j]==temp_size+1) {
                        temp_size+=1;
                        max_size_temp++;
                    }
                    else
                        break;
              }
              if(max_size_temp>max_size)
                max_size=max_size_temp;
            }
        }
    }
    printf("%d\n",max_size);

    return 0;
}
