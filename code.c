#include <stdio.h>
#include<ctype.h>
#define SUBOR "sifra.txt"

int main()
{
    int i=0, o=1, p=0, k, b=0, h=0, g=0;
    int povodny[1000], uprava[1000];
    int c,i2,d;
    FILE *fr;
    char menu;
    
    do{
        scanf (" %c", &menu);
        
        if (menu != 'k') //ak vstup z klávesnice je 'k' switch menu sa ukončí
        {
            switch(menu)
            {
                case 'n': //načítanie správy zo súboru
                
                if((fr = fopen(SUBOR, "r")) == NULL) {
                printf("Spravu sa nepodarilo nacitat\n");
                return 1;
                }
                
                while ((c =getc(fr)) != EOF) { 
                
                povodny[i] = c;
                i++;
                o=0;
                }
                //printf("%c",hist[3]);
                
                if(fclose(fr) == EOF) {
                printf("Spravu sa nepodarilo nacitat\n");
                return 1;
                }
                break;
                
                case 'v': //výpis správy zo súboru
                if(o==0)
                {
                    while(o<i)
                    {
                       printf("%c",povodny[o]);
                       o++;
                    }
                    o=0;
                    printf("\n");
                }
                else
                {
                    printf("Sprava nie je nacitana\n");
                }
                //printf("%d",o);
                break;
                
                case 'u': //úprava načítanej správy
                //printf("%d",o);
                //printf("%d",i);
                if(o==0)
                {
                    while(o<i)
                    {
                        if(povodny[o]>='A'&&povodny[o]<='Z')
                        {
                            uprava[p] = povodny[o];
                            //printf("%c",uprava[o]);
                            p++;
                        }
                        else if(povodny[o]>='a'&&povodny[o]<='z')
                        {
                            uprava[p] = povodny[o] - 32;
                            //printf("%c",uprava[o]);
                            p++;
                        }
                        o++;
                    }
                    o=0;
                }
                else
                {
                    printf("Sprava nie je nacitana\n");
                }
                break;
                
                case 's': //výpis načítanej správy
                if(p!=0)
                {
                    while(o<i)
                    {
                    printf("%c",uprava[o]);
                    o++;
                    }
                    o=0;
                    printf("\n");
                }
                else
                {
                    printf("Nie je k dispozicii upravena sprava\n");
                }
                break;
                
                case 'd': //výpis všetkých slov danej dĺžky načítanej správy
                scanf("%d",&k);
                if(k<=100 && k>=1)
                {
                    if(o==0)
                    {
                        while(o<i)
                        {
                            if(povodny[o+k] == ' ' && o-1 == -1)
                            {
                                while(o<k)
                                {   
                                    printf("%c",povodny[o]);
                                    o++;
                                }
                                printf("\n");
                            }
                            
                            else if(povodny[o+k] == ' ' && povodny[o-1] == ' ')
                            {
                                b = o+k;
                                while(o<b)
                                {   
                                    printf("%c",povodny[o]);
                                    o++;
                                }
                                printf("\n");
                            }

                            else if(povodny[o+k] == '\0' && povodny[o-1] == ' ')
                            {
                                b = o+k;
                                while(o<b)
                                {   
                                    printf("%c",povodny[o]);
                                    o++;
                                }
                                printf("\n");
                            }
                            o++;
                        }
                        o=0;
                    }
                    else
                    {
                        printf("Sprava nie je nacitana\n");
                    }
                }
                else
                {
                    printf("Cislo od 1 do 100\n");
                }
                break;
                
                case 'h': //vytvorenie histogramu z upravenej správy
                //c=0;
                //if(p!=0)
                //{
                //    while (uprava[c] != '\0') 
                //    {
                //        if (uprava[c] >= 'A' && uprava[c] <= 'Z') 
                //        {
                //            x = uprava[c] - 'A';
                //            uprava[x]++;
                //        }
                //        c++;
                //    }
                //    for (c = 0; c < 26; c++)
                //    printf("%c je %d\n", c + 'A', uprava[c]);
                //}
                printf("h\n");
                break;
                
                case 'c':
                printf("c\n");
                break;

                case 'p': //výpis počtu všetkých znakov abecedy a ostatných
                if(o==0)
                  {
                    while(o<i)
                    {
                        if(povodny[o]>='A'&&povodny[o]<='Z')
                        {
                            h++;
                        }
                        else if(povodny[o]>='a'&&povodny[o]<='z')
                        {
                            h++;
                        }
                        else
                        {
                            g++;
                        }
                        o++;
                    }
                    printf("%d:%d\n",h,g);
                    o=0;
                  }
                else
                {
                    printf("Sprava nie je nacitana\n");
                }
                break;

                case 'z': //zmazanie reťazca od daného miesta až po danú lokáciu
                scanf("%d %d",&i2,&d);
                if(p!=0)
                {
                    if((i2+d)<p)
                    {
                        //printf("%d %d %d\n", i2, d, o);
                        //printf("%c %c %c\n",uprava[i2],uprava[d],uprava[o]);
                        while(o<i)
                        {
                        uprava[i2]=uprava[i2+d];
                        //printf("%c",uprava[o]); vypis zmazaneho retazca
                        i2++;
                        o++;
                        }
                        printf("Retazec sa zmazal\n");
                    }
                    else
                    {
                        printf("Retazec nie je mozne zmazat\n");
                    }
                    o=0;
                }
                else
                {
                    printf("Nie je k dispozicii upravena sprava\n");
                }
                break;
                
                default:
                printf("Nespravny znak\n");
                break;
           }
        }
     } while(menu!= 'k'); //ak vstup z klávesnice je 'k' cyklus do-while sa ukončí

    return 0;
}
