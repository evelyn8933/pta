#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ); /* 裁判提供，细节不表 */
int main()
{
    char s[MAXS], t[MAXS], *pos;
    
    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
char *search(char *s, char *t)
{   if(t[0]=='\0') return NULL; //如果t是空串 
	for(int i=0;s[i]!='\0';i++)
	{  int start=i;
      if(s[i]==t[0])
		{ int j=0;
		  for(j=0;s[i]!='\0'&&t[j]!='\0';j++,i++)
		   {
			if(s[i]!=t[j])	break;
		   }
		   if(t[j]=='\0') return &s[start];
		   i=start;
	    }
    }
    return NULL;
}
