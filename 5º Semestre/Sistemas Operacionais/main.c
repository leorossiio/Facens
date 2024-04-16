#include <stdlib.h>
#include <stdio.h>

void pow2(int*a, int sz){
	int i;
	for(i=0;i<sz;i++){
		int tmp=*(a+i);
		*(a+i)=tmp*tmp;
	}
}

int main(int argc, char *argv) {
//	int *pointer;

	int values[5] = {1,2,3,4,5};
	int i;
	for(int i=0; i < 5; i++){
		printf("at %p %d\n", values + i, * (values + i));
	}
		printf("\n");
	pow2(values,5);
	for(int i=0; i < 5; i++){		
		printf("at %p %d\n", values + i, * (values + i));
	}

	return 0;
}
