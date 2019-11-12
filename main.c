#include "file.h"
void rand_funct(int * arr){ //it's a random function!! arr length should be 10
	int f = open("/dev/random", O_RDONLY);
	for (int i = 0; i<10; i++){
		read(f, (arr+i), sizeof(int));
		printf("Random %i: %i \n", i, arr[i]);
	}
	close(f);
}
int rand_int(){
	int f = open("/dev/random", O_RDONLY);
	int num;
	read(f, &num, sizeof(int));
	return num;
}
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int arr [10];
	rand_funct(arr);
	//printf("%i\n", errno);
	printf("\nwriting the numbers into the file rando_nums.txt... \n");
	int f = open("rando_nums.txt", O_WRONLY | O_CREAT, 0644);
	write(f, arr, sizeof(int)*10);
	close(f);

	printf("\nreading the numbers in rando_nums.txt: \n");
	f =  open("rando_nums.txt", O_RDONLY);
	int copy[10];
	read(f, copy, sizeof(int)*10);
	close(f);
	for (int i = 0; i<10; i++){
		printf("Random %i: %i\n", i, copy[i]);
	}
	return 0;

}
