#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    char tenhang[10];
    char tenmay[15];
    int ram;
    char chip[15];
    double gia;
}DT;

void nhap(DT &x)
{
    printf("\nHang: ");  scanf("%s",x.tenhang);
    while (strlen(x.tenhang) > 10 )
    {
        printf("\nNhap lai ten hang: ");  scanf("%s",x.tenhang);
    }
    printf("\nMay: ");  scanf("%s",x.tenmay);
    while (strlen(x.tenmay) > 15 )
    {
        printf("\nNhap lai ten may: ");  scanf("%s",x.tenmay);
    }
    printf("\nRAM: ");  scanf("%d",&x.ram);

    while ((x.ram%4 != 0) || (x.ram == 0))
    {
        printf("\nNhap lai RAM: ");  scanf("%d",&x.ram);
    }
    int chon;
    printf("Danh sach chip:\n1. Exynos   2. SnapDragon\n3. M1       4. M2\nChip cua may: ");
    scanf("%d",&chon);
    switch (chon)
    {
        case 1:
        {
            strcpy(x.chip,"EXynos");
            break;
        }
        case 2:
        {
            strcpy(x.chip,"SnapDragon");
            break;
        }
        case 3:
        {
            strcpy(x.chip,"M1");
            break;
        }
        case 4:
        {
            strcpy(x.chip,"M2");
            break;
        }

    }
    printf("Gia tien: "); scanf("%lf",&x.gia);
}

void in(DT x, int i)
{
    printf("| %3d | %-10s | %-9s | %2dGB  | %-10s | %10.1lf |\n",i+1,x.tenhang,x.tenmay,x.ram,x.chip,x.gia);
}

void xuatDanhSach(DT ds[], int n)
{
    printf("| %3s | %-10s | %-9s |  %2s  | %-10s | %10s |\n","STT","Ten hang","Ten may","RAM","Chip","Gia");
    for (int i=0; i<n; i++)
    {
        in(ds[i],i);
    }
}

void sapXep(DT ds[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (strcmp(ds[i].tenmay,ds[j].tenmay)>0)
            {
                DT temp;
                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void timkiem(DT ds[], int n, int x, double y, double z)
{
    printf("| %3s | %-10s | %-9s |  %2s  | %-10s | %10s |\n","STT","Ten hang","Ten may","RAM","Chip","Gia");
    int dem = 0;
    for (int i=0; i<n; i++)
    {
        if ((ds[i].ram == x) && (ds[i].gia >= y && ds[i].gia <= z))
        {
            dem = 1;
            in(ds[i],i);
        }
    }
    if (dem == 0) printf("Khong co san pham phu hop");
}

int main()
{
    int n;
    printf("Tong so dien thoai: ");
    scanf("%d",&n);
    while (n <= 0)
    {
        printf("Khong hop le, moi nhap lai: ");
        scanf("%d",&n);
    }
    DT ds[100];
    for (int i=0; i<n; i++)
    {
        printf("Nhap thong tin dien thoai so %d",i+1);
        nhap(ds[i]);
    }
    xuatDanhSach(ds,n);
    sapXep(ds,n); xuatDanhSach(ds,n);
    int a;
    double b,c;
    printf("Lua chon dung luong RAM: ");
    scanf("%d",&a);
    while (a%4 != 0)
    {
        printf("Khong co muc RAM nay, moi nhap lai: ");
        scanf("%d",&a);
    }
    printf("Muc gia ban muon tim\nTu: ");  scanf("%lf",&b);
    printf("Den: ");  scanf("%lf",&c);
    printf("Ket qua sau khi tim kiem:\n");
    timkiem(ds,n,a,b,c);
    return 0;
}
