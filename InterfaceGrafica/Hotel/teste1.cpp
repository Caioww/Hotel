#include <Stdio.h>




void multimatriz(int M[2][3] , int T[2][3]){
	
	int i, j, S[2][3], k;

for(i = 0; i <2; i++)
	for(j = 0; j <3; i++){
		
 S[i][j] = 0;
 
 for(k = 0; k <2; k++)
		
	S[i][j] = M[k][j]*T[i][k] +S[i][j];	

	
	
}


for(i = 0; i <2; i++){
	for(j = 0; j <3; i++){
	printf("%d ",S[i][j]);

}
printf("\n");
}
	
	

}

int main (){
	
	
	
	int M[2][3] = {{1,2,3},{3,2,1}};
	int T[2][3] = {{1,2,3},{3,2,1}};
	
 multimatriz(M, T);
 
 
 return 0;
 
}
