#include<stdio.h>
#include<string.h>

struct ubudehe
{
    int id;
    char name[20];
    int members;
    int category;
    int amount;
} bu;
void Record(){
    FILE*p;
    p=fopen("ubudeherecord.txt","a");
    printf("\n\t Enter ID:");
    scanf("%d",&bu.id);

    printf("\n\t Enter First Name:");
    scanf("%s",&bu.name);

    printf("\n\t Enter Members Of Family:");
    scanf("%d",&bu.members);

    printf("\n\t Enter Category of Ubudehe:");
    scanf("%d",&bu.category);

    if(bu.category==1){
        bu.amount=0;
    }else if(bu.category==2){
        bu.amount=3000;
    }else if(bu.category==3){
        bu.amount=7000;
    }else if(bu.category==4){
        bu.amount=14000;
    }


    fprintf(p,"%d\t%s\t%d\t%d\t%d\n\n",bu.id,bu.name,bu.members,bu.category,bu.amount);

    printf("REGISTERED SUCCESSFULL\n");


    fclose(p);
    int reset;
    printf("Press Any Number to Return To Main Menu/...");
    scanf("%d",&reset);
    main(reset);
}
void Dispaly(){
    FILE*p;
    p=fopen("ubudeherecord.txt","r");
    printf("Id\tNames\tMembers of family\tUbudehe Category\tAmount\n\n");
    while(!feof(p)){
        fscanf(p,"%d%s%d%d%d",&bu.id,bu.name,&bu.members,&bu.category,&bu.amount);
        printf("%d\t%s\t%d\t\t\t\t%d\t\t%d\t\n\n",bu.id,bu.name,bu.members,bu.category,bu.amount);
    }
    fclose(p);
    int reset;
    printf("Press Any Number to Return To Main Menu/...");
    scanf("%d",&reset);
    main(reset);
}
void Search(){
    int x;
    FILE*p;
    p=fopen("ubudeherecord.txt","r");
    printf("Enter the category of Ubudehe");
    scanf("%d",&x);
    while(!feof(p)){
        fscanf(p,"%d%s%d%d%d",&bu.id,bu.name,&bu.members,&bu.category,&bu.amount);
        if(bu.category==x){
            printf("%d\t%s\t%d\t%d\t%d",bu.id,bu.name,bu.members,bu.category,bu.amount);
        }else{
            printf("the family has not found");
        }


    }
    fclose(p);
    int reset;
    printf("Press Any Number to Return To Main Menu/...");
    scanf("%d",&reset);
    main(reset);
}
main(){
    int x;
    do{
    printf("press 1 to record\n");
    printf("press 2 to dispaly\n");
    printf("press 3 to search\n");
    printf("press 0 to Exit\n");
    scanf("%d",&x);
    switch(x){
        case 1:Record();
        break;
        case 2:Dispaly();
        break;
        case 3:Search();
        break;
        case 0:
        printf("Thank you to use our system");
        break;
        default:
        printf("Wrong Choice choose again\n\n");
    }
    }while(x!=0);


}
