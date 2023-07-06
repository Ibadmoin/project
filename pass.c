#include<stdio.h>
#include<conio.h>
#include<string.h>

#define Max_Pass_length 20
int authenticate(){
        char pass[Max_Pass_length +1];
    char user[10];
    int length = 5;
    printf("Enter User name: ");
    scanf("%s", &user);
    if (strcmp(user, "Admin") != 0 ) {
    return 0;
}else {
    int i = 0;
    for (int i = 0; i < length; i++)
    {
        pass[i] = getch();
        printf("%c", '*');
    }
    pass[i] = '\0';
    if (strcmp(pass, "Admin") != 0)
    {
        return 0;
    }
    

}
return 1;
}
int main(){
int isWorking = authenticate();

    if (isWorking)
    {
    printf("Success!");
        /* code */
    }else {
        printf("is invalid");
    }
    

    return 0;
}