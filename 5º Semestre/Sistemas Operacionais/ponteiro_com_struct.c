#include <stdlib.h>
#include <stdio.h>

struct my_data
{
	int value_a;
	int value_b;
};

int main(int argc, char *argv[]){
	struct my_data data1 = {.value_a=2, .value_b=5};
	printf("data1 @ %p\n", &data1);
	printf("data1.value_a (%d) @ %p\n", data1.value_a,&data1.value_a);
	printf("data1.value_b (%d) @ %p\n", data1.value_b,&data1.value_b);
	printf("\n");
	
	
	struct my_data *ptr = &data1;
	int *member_ptr = &data1.value_a;
	
	printf("data1.value_a %d (%p)\n",data1.value_a, &data1.value_a);

	printf("ptr->value.a %d (%p)\n", ptr->value_a,&ptr->value_a);
	
	return 0;
}
