#include<stdio.h>
#include<string.h>


void generateSquare(int n){
	int magicSquare[n][n];
	int magic;
	int r, c, num;
	memset(magicSquare, 0, sizeof(magicSquare));
	
	r = n/2;
	c = n-1;
	
	for(num=1; num<n*n;){
		if(r<0 && c==n){
			r = 0;
			c = n-2;
		}
		
		else{
			if(r<0)
				r = n-1;
			if(c==n)
				c = 0;
		}
		
		if(magicSquare[r][c]){
			r++;
			c -= 2;
			continue;
		}
		
		else{
			magicSquare[r][c] = num++;
		}
		
		r--;
		c++;
	}
	
	magic = n*(n*n+1)/2;
	printf("Magic constant is: %d\nx", magic);
	for(r=0; r<n; r++){
		for(c=0; c<n; c++)
			printf("%d ", magicSquare[r][c]);
		printf("\n");
	}
}


int main(){
	
	
	int n;	
	printf("Enter the number: ");
	scanf("%d", &n);
	generateSquare(n);
	
	return 0;
}
