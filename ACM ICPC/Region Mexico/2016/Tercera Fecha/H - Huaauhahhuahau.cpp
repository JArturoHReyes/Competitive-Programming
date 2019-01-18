#include<stdio.h>
#include<string.h>
int main(void)
{

    char line[128];
    fflush(stdin);
    gets(line);
    char vocalesnormales[128];
    char vocalesinversas[128];
    int i, pos1 = 0, b = 0, pos2 = 0;
    for(i = 0; i < strlen(line) ; i++)
    {
        if(line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u')
        {
            vocalesnormales[pos1] = line[i];
            pos1++;
        }
    }
    for(i = strlen(line) - 1; i >=0 ;i--)
    {
        if(line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u')
        {
            vocalesinversas[pos2] = line[i];
            pos2++;
        }
    }
       for(i = 0; i < pos1; i++)
        {
            if(vocalesinversas[i] != vocalesnormales[i])
            {
                b = 1;
                i = pos1 + 1;
            }
        }
    if(b == 0)
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }


return 0;
}
