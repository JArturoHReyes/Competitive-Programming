#include<stdio.h>
int main(void)
{
    char line[100000];
    while(fgets(line,100000,stdin))
    {
        int i, mod = 0;
        for(i = 0; i < strlen(line) - 1; i++)
        {
            mod = mod * 16;
            if (line[i] >= '0'&&line[i] <= '9')
            {
                mod += line[i] - '0';
            }
			else
            {
                mod += line[i] - 'A' + 10;
            }
            mod = mod % 17;
        }
        if(mod)
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }

    }
return 0;
}
