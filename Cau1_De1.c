#include <stdio.h>
#include <conio.h>
#include <string.h>

int kiemtra(char *s)
{
    if (strlen(s) > 10) return 0;
    int dk1=0;  int dk2=0;
    int dk3=0;  int dk4=0;
    char kitudb[8] = "!@#$%^&*";
    for (int i=0; i<strlen(s); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z') dk1=1;
        else if (s[i] >= 'a' && s[i] <= 'z') dk2=1;
        else if (s[i] >= '0' && s[i] <= '9') dk3=1;
        else for (int j=0; j<strlen(kitudb); j++)
        {
            if (s[i] == kitudb[j])
            {
                dk4=1;
                break;
            }
        }
    }
    if (dk1 == 0 || dk2 == 0 || dk3 == 0 || dk4 == 0) return 0;
    else return 1;
}

void chuyendoi(char *s)
{
    for (int i=0; i<strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z') s[i]=s[i]-32;
        else if (s[i] >= 'A' && s[i] <= 'z') s[i]=s[i]+32;
    }
}

int main()
{
    char xau[100];
    printf("Nhap xau: ");
    gets(xau);
    while (kiemtra(xau) == 0)
    {
        printf("Nhap lai xau: ");
        gets(xau);
    }
    printf("Xau ban dau: %s",xau);
    chuyendoi(xau);
    printf("\nSau khi chuyen doi: %s",xau);
    return 0;
}
