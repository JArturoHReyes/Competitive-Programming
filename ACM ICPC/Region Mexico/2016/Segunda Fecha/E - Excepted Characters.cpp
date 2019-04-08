#include<stdio.h>
int main(void)
{
  char line[1000001];
  int query , a , b, x;
  while(scanf("%s %d",line,&query) != EOF)
  {
      x = strlen(line);
      while(query--)
      {
        scanf("%d %d",&a,&b);
        a = (a + b - 2) % x;
        printf("%c\n",line[a]);
      }
  }
return 0;
}
