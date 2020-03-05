#include<stdio.h>

int main(int argc, char **argv)
{
	if(argc != 4){
		printf("Usage: ./fileXOR [file1] [file2] [output file]\n");
		return 0; 
	}
	
	FILE *f1;
	FILE *f2;
	FILE *output;

	f1 = fopen(argv[1], "rb");
	f2 = fopen(argv[2], "rb");
	output = fopen(argv[3], "wb");

	if(f1 == NULL || f2 == NULL || output == NULL){
		printf("Failed to open files.\n");
		return 0;
	}

	int cur_f1, cur_f2, cur_out;

	while(!feof(f1) && !feof(f2)){
		cur_f1 = fgetc(f1);
		cur_f2 = fgetc(f2);
		cur_out = (cur_f1 ^ cur_f2);
		fputc(cur_out,output);
	}

	printf("Completed XOR transformation.\n");

	return 0;
}