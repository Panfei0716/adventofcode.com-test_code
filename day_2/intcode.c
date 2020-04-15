#include <stdio.h>

//#define __DEBUG__

#ifdef __DEBUG__
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif





void contain_init(int noun, int verb, int *contain)
{
    contain[1] = noun;
    contain[2] = verb;

    return;
}


/* function--- printf all contain value */
#if 0
void look_all_contain(void)
{
    int j = 0;
    for (j = 0; j < position; j++)
	printf("contain[%d]=%d\n", j, contain[j]);
}
#endif


int addition(int position, int *contain)
{
    int ret = 0;
    int position_a = contain[position + 1];
    int position_b = contain[position + 2];
    int position_c = contain[position + 3];
    ret = contain[position_a] + contain[position_b];
    debug("addition(%d[%d]+%d[%d]) contain[%d]=%d\n",
	  contain[position_a], position_a, contain[position_b],
	  position_b, position_c, ret);
    contain[position_c] = ret;
    return ret;
}

int multiplication(int position, int *contain)
{
    int ret = 0;
    int position_a = contain[position + 1];
    int position_b = contain[position + 2];
    int position_c = contain[position + 3];
    ret = contain[position_a] * contain[position_b];
    debug("multiplication(%d[%d] * %d[%d]) contain[%d]=%d\n",
	  contain[position_a], position_a, contain[position_b],
	  position_b, position_c, ret);
    contain[position_c] = ret;

    return ret;
}


int main(int argc, const char *argv[])
{
    int noun, verb;
    int i = 0, ret;
    int opcode, position = 0;
    int contain[1024];
    FILE *fw = fopen("input_2.txt", "r");
//      FILE *fw = fopen("test.txt", "r");
    if (fw == NULL) {
	printf("fopen puzzle.txt fail\n");
	return -1;
    }

    ret = fscanf(fw, "%d,", &contain[position]);
    debug("contain=%d,i=%d,ret=%d\n", contain[position], position, ret);
    while (ret > 0) {
	position++;
	ret = fscanf(fw, "%d,", &contain[position]);
	debug("contain=%d,i=%d,ret=%d\n", contain[position],
	      position, ret);
    }

/* replace position 1 with the value 12 and replace position 2 with the value
 * 2.*/
    noun = 12;
    verb = 2;
    contain_init(noun, verb, contain);
    debug("contain[1]=%d,contain[2]=%d,noun=%d, verb=%d\n", contain[1],
	  contain[2], noun, verb);

    while (i < position) {
	switch (contain[i]) {

	case 1:
	    ret = addition(i, contain);
	    debug("for1 contain=%d,i=%d,ret=%d\n", contain[i], i, ret);
	    break;
	case 2:
	    ret = multiplication(i, contain);
	    debug("for2 contain=%d,i=%d,ret=%d\n", contain[i], i, ret);
	    break;
	case 99:
	    printf("the program is finished contain[0]=%d\n", contain[0]);
	    //      look_all_contain();
	    fclose(fw);
	    return 0;
	default:
	    printf("opcode is error!\n");
	    return -1;

	}

	i += 4;
    }

    fclose(fw);
    return 0;
}
