#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>

struct contact
{
  long ph;
  char name[100],address[100],email[100];
} list;

char query[20],name[20];
FILE *fp, *ft;
int i,n,ch,l,found;

//add contact
void AddContact()
{
   fp=fopen("contact.dat","a");
   for (;;)
   {
     fflush(stdin);
     printf("To exit enter blank space in the name input\nEnter the Name:");
     scanf("%[^\n]",&list.name);//searches for string until line break or enter
     if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
     {
       break;
     }
     fflush(stdin);
     printf("Enter the Phone Number: ");
     scanf("%ld",&list.ph);
     fflush(stdin);
     printf("Enter the Address: ");
     fflush(stdin);
     gets(list.address);
     printf("Enter the Email-id: ");
     fflush(stdin);
     gets(list.email);
     printf("\n");
     fwrite(&list,sizeof(list),1,fp);
     printf("Successfully saved the Contact. \n");

   }
     fclose(fp);

}

//list all contacts
void ListContacts()
{
  system("cls");
  printf("\n\t\t\n\t\t\tLIST OF CONTACTS\n\t\t");
  for(i=97; i<=122; i=i+1)
  {
    fp=fopen("contact.dat","r");
    fflush(stdin);
    found=0;
    while(fread(&list,sizeof(list),1,fp)==1)
    {
        if(list.name[0]==i || list.name[0]==i-32)
        {
            printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name,list.ph,list.address,list.email);
            found++;
        }
    }
  if(found!=0)
  {
    printf("[%c]-(%d)\n\n",i-32,found);
    getch();
  }
    
  
fclose(fp);
}
}

//search contact
void searchContact()
{
  system("cls");
  printf("\n\t\t\n\t\t\tSEARCH CONTACT\n\t\t");
  fflush(stdin);
  printf("Enter the name of the contact to be searched: ");
  scanf("%[^\n]",&query);
  fp=fopen("contact.dat","r");
  fflush(stdin);
  found=0;
  while(fread(&list,sizeof(list),1,fp)==1)
  {
    if(stricmp(list.name,query)==0)
    {
      printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name,list.ph,list.address,list.email);
      found++;
    }
  }
  if(found==0)
  {
    printf("\n\nContact not found.\n");
  }
  fclose(fp);
  getch();
}

//edit contact
void editContact()
{
  system("cls");
  fp=fopen("contact.dat","r");
  ft=fopen("temp.dat","w");
  fflush(stdin);
  printf("Edit contact\n\n\n\tEnter the name of contact to edit:");
  scanf("%[^\n]",name);
  while(fread(&list,sizeof(list),1,fp)==1)
  {
    if(stricmp(name,list.name)!=0)
    fwrite(&list,sizeof(list),1,ft);
  }
  fflush(stdin);
  printf("\n\nEditing '%s'\n\n",name);
  printf("Name: ");
  scanf("%[^\n]",&list.name);
  fflush(stdin);
  printf("Phone: ");
  scanf("%ld",&list.ph);
  fflush(stdin);
  printf("Address: ");
  scanf("%[^\n]",&list.address);
  fflush(stdin);
  printf("Email-id: ");
  gets(list.email);
  printf("\n");
  fwrite(&list,sizeof(list),1,ft);
  fclose(fp);
  fclose(ft);
  remove("contact.dat");
  rename("temp.dat","contact.dat");
}

//delete contact
void deleteContact()
{
  system("cls");
  fp=fopen("contact.dat","r");
  ft=fopen("temp.dat","w");
  fflush(stdin);
  printf("\n\n\tEnter the name of contact to delete:");
  scanf("%[^\n]",name);
  while(fread(&list,sizeof(list),1,fp)==1)
  {
    if(stricmp(name,list.name)!=0)
    fwrite(&list,sizeof(list),1,ft);
  }
  fclose(fp);
  fclose(ft);
  remove("contact.dat");
  rename("temp.dat","contact.dat");
}
  
int showMenu()
{
  int choice = 0;
  printf("\n");
  printf("\t\t\tContact Management System\n");
  printf("\n");
  printf("\t\t\t\tMAIN MENU\n\n\t\t\t[1] Add a new Contact\n\t\t\t[2] List all Contacts\n\t\t\t[3] Search for contact\n\t\t\t[4] Edit a Contact\n\t\t\t[5] Delete a Contact\n\t\t\t[0] Exit\n");
  printf("\n");
  printf("\t\t\tEnter the choice:");
  scanf("%d",&choice);
  return choice;
}

int main()
{
 system("cls");
 int ch = 0;
 while (1)
  {
    ch = showMenu();
    switch(ch)
    {
      case 0:
      {
        printf("\n");
        printf("Logging Out from the Contact Management System.\n");
        exit(0);
      }
      case 1:
      {
        AddContact();
        break;
      }
      case 2:
      {
        ListContacts();
        break;
      }
      case 3:
      {
        searchContact();
        break;
      }
      case 4:
      {
        editContact();
        break;
      }
      case 5:
      {
        deleteContact();
        break;
      }
      default: 
      {
        printf("\n");
        printf("Invalid Input\n");
        break;
      }
    }
  }
}
