#include <stdio.h>

int main(int argc, const char *argv[])
{
	struct puzzle_t {
		int mass;
		int fuel_value;
	};

	struct puzzle_t puzzle[1024];
	int ret = 0, i = 0;
	int fuel_values = 0;
	int fuel_self = 0;

	FILE *fw = fopen("puzzle.txt", "r");
	if (fw == NULL)
		printf("fopen puzzle.txt fail\n");

	for (i = 0; i < 1024; i++) {
		ret = fscanf(fw, "%d", &puzzle[i].mass);
		if (ret == -1)
			break;
		fuel_self = (puzzle[i].mass / 3) - 2;
		while (fuel_self > 0) {
			puzzle[i].fuel_value += fuel_self;
			//      printf("after puzzle[i].fuel_value=%d,  fuel_self=%d\n",puzzle[i].fuel_value, fuel_self);
			fuel_self = (fuel_self / 3) - 2;
			//      printf("later fuel_self=%d\n",fuel_self);

		}
		printf("fscanf mass=%d,fuel_value=%d, return ret=%d\n",
		       puzzle[i].mass, puzzle[i].fuel_value, ret);
		fuel_values += puzzle[i].fuel_value;

	}
	printf("fuel_values is %d\n", fuel_values);


	fclose(fw);
	return 0;
}
