#include <stdio.h>
#include <string.h>
int main(void) {
    int r[26]={0,};
    char s[1000001]={0,};
    int max=-1,f;
    scanf("%s",s);
    int leng = strlen(s);
    for(int i=0;i<leng;++i) {
        if(s[i]<=90) 
            r[s[i]-'A']++;
        else
            r[s[i]-'a']++;
    }

    for(int i=0;i<26;++i) {
        if(r[i]>max) {
            max = r[i];
            f=i;
        }
    }
    int d=0;
    for(int i=f+1;i<26;++i) {
        if(r[i] == max)
            d++;
    }
    if(d == 0)
        printf("%c",f+'A');
    if(d != 0)
        printf("?");
    return 0;
}