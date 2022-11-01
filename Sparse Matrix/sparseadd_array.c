#include<stdio.h>
void printSparse(int sparse[][3],int size){
    for (int i=0; i<size; i++)
	{
		for (int j=0; j<3; j++)
			printf("%d ", sparse[i][j]);

		printf("\n");
	}
}

void addSparse(int sparse1[][3],int sparse2[][3],int size1,int size2,int r,int c){

    int res[size1+size2-1][3];
    for (int i=0; i<size1+size2-1; i++)
	{
		for (int j=0; j<3; j++){
            res[i][j]=0;
        }
			
	}
    
    int i=1,j=1,k=1;
    while(i<size1&&j<size2){
        if(sparse1[i][0]>sparse2[j][0]){
            res[k][0]=sparse2[j][0];
            res[k][1]=sparse2[j][1];
            res[k][2]=sparse2[j][2];
            k++;
            j++;
        }
        else if (sparse1[i][0]<sparse2[j][0]){
            res[k][0]=sparse1[i][0];
            res[k][1]=sparse1[i][1];
            res[k][2]=sparse1[i][2];
            k++;
            i++;
        }
        else{
            if(sparse1[i][1]>sparse2[j][1]){
            res[k][0]=sparse2[j][0];
            res[k][1]=sparse2[j][1];
            res[k][2]=sparse2[j][2];
            k++;
            j++;
            }
            else if(sparse1[i][1]<sparse2[j][1]){
            res[k][0]=sparse1[i][0];
            res[k][1]=sparse1[i][1];
            res[k][2]=sparse1[i][2];
            k++;
            i++;
            }
            else{
            res[k][0]=sparse1[i][0];
            res[k][1]=sparse1[i][1];
            res[k][2]=sparse1[i][2]+sparse2[j][2];
            k++;
            i++;
            j++;
            }
        }
    }
    while(i<size1){
        res[k][0]=sparse1[i][0];
        res[k][1]=sparse1[i][1];
        res[k][2]=sparse1[i][2];
        k++;
        i++;
    }
    while(j<size2){
        res[k][0]=sparse2[j][0];
        res[k][1]=sparse2[j][1];
        res[k][2]=sparse2[j][2];
        k++;
        j++;
    }
    int size=0;
     for (int i=0; i<size1+size2-1; i++)
	{
		if(res[i][2]!=0){
            size++;
        }
			
	}
    res[0][0]=r;
    res[0][1]=c;
    res[0][2]=size;
    printf("Resultant Sparse matrix:\n");
    printSparse(res,size+1);


}

int main()
{
    int m,n,p,q;
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d",&m,&n);
	int mat[m][n];
    printf("Enter first matrix elements: ");
    for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			scanf("%d",&mat[i][j]);
        }
    }

	int size1 = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (mat[i][j] != 0){
				size1++;
            }
        }
    }
    
	
	int sparse1[size1+1][3];
    sparse1[0][0] = m;
	sparse1[0][1] = n;
    sparse1[0][2] = size1;
	int k = 1;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (mat[i][j] != 0)
			{
				sparse1[k][0] = i;
				sparse1[k][1] = j;
				sparse1[k][2] = mat[i][j];
				k++;
			}
        }
    }
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d",&p,&q);
	int mat2[p][q];
    printf("Enter second matrix elements: ");
    for (int i = 0; i < p; i++){
		for (int j = 0; j < q; j++){
			scanf("%d",&mat2[i][j]);
        }
    }

	int size2 = 0;
	for (int i = 0; i < p; i++){
		for (int j = 0; j < q; j++){
			if (mat2[i][j] != 0){
				size2++;
            }
        }
    }
	
	int sparse2[size2+1][3];
    sparse2[0][0] = p;
	sparse2[0][1] = q;
    sparse2[0][2] = size2;
	int k2 = 1;
	for (int i = 0; i < p; i++){
		for (int j = 0; j < q; j++){
			if (mat2[i][j] != 0)
			{
				sparse2[k2][0] = i;
				sparse2[k2][1] = j;
				sparse2[k2][2] = mat2[i][j];
				k2++;
			}
        }
    }
    // printf("%d",size2);
    printf("Sparse matrix of first matrix:\n");
    printSparse(sparse1,size1+1);
    printf("Sparse matrix of second matrix:\n");
    printSparse(sparse2,size2+1);
    if(m==p&&n==q){
        addSparse(sparse1,sparse2,size1+1,size2+1,m,n);
    }
	return 0;
}
