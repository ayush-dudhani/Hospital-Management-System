#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>


void loginscreen();
void title();       //Display title
void MainMenu();    //display main menu
void LoginScreen(); //for login screen
void Add_new();     //to add record
void SearchRecord();
void SearchRecordByBloodGroup();
void EditRecord();
void DeleteRecord();
void Exit();
void list();
void gotoxy(short x, short y)
{
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct Data
{
  char FirstName[20];
  char LastName[20];
  char Gender[10];
  char ContactNo[11];
  char Age[5];
  char District[20];
  char Email[40];
  char BloodGroup[5];
};
struct Data p;


/************************RECORD FUNCTION********************************************/
void Record()
{
  system("cls");
}


/***************************INT MAIN FUNCTION***********************************/
int main(void)
{
  title();
  printf("\n\n\t\t\t  WELCOME TO \t\n\n\t\tPCET HOSPITAL MANAGEMENT SYSTEM\n\n\n");
  printf("***********************************************************************\n");

  loginscreen();
  printf("\n\nPress any key to continue...");
  getch();
  system("cls");
  MainMenu();

  return 0;
}



/***************...................LOGIN SCREEN................ *******************/
 void loginscreen()
{

  int try_no = 0;
  char username[10], password[10];
  char original_password[10] = "1234";
  char original_username[10] = "pcet";
  do
  {
    printf("\n\n\t\t\tUSERNAME:");
    gets(username);
    printf("\n\n\t\t\tPASSWORD:");
    gets(password);
    if (strcmp(username, original_username) == 0 && strcmp(password, original_password) == 0)
    {
      printf("\n\nLogged in Successfully!!!\n\n");
      break;
     
    }
    else
    {
      printf("\n\nEnter valid username or password :(\n TRY AGAIN\n");
      try_no++;
      printf("\n%d attempt left\n", 4 - try_no);
      printf("*************************************************\n");
    }
  } while (try_no <= 3);
  if (try_no > 3)
  {
    printf("\n\nYou have crossed the limit! You can't Login Now\n\n");
    exit(0);
  }
}


/***************************TITLE FUNCTION*****************************************/
void title()
{
  printf("**********************************************************************\n");
  printf("\n\t\t\t  PCET HOSPITAL\t\t\t\n\n");
  printf("**********************************************************************");
}

 /*****************************MAIN MENU*****************************/
void MainMenu()
{
  system("cls");
  int select;
  title();
  printf("\n\n\n\n\n\t\t1. Add New Patient's Information in the Record\n");
  printf("\n\t\t2. Display All Patient's Record\n");
  printf("\n\t\t3. Search Records\n");
  printf("\n\t\t4. Edit Record\n");
  printf("\n\t\t5. Delete Record\n");
  printf("\n\t\t6. Exit\n");
  printf("\n\n\n\n\t\tYour Choice: ");
  scanf("%d", &select);
  system("cls");


  /*******************----------------SWITCH CASE------------- ******************************/
  int search;
  switch (select)
  {
  case 1:
    Add_new();
    break;

  case 2:
    list();
    break;

  case 3:
    title();
    printf("\n\n***********.............SEARCH RECORD.........*************\n");
    label:{

    printf("\n\n\n\n\t\t1 - SEARCH BY FIRSTNAME\n\n");
    printf("\n\t\t2 - SEARCH BY BLOOD GROUP\n\n");
    
    printf("\n\t\tYOUR CHOICE :");
    scanf(" %d",&search);
    }
    if (search==1)
    {
      SearchRecord();
    }
    else if (search==2)
    {
      SearchRecordByBloodGroup();
    }
    else
    {
      printf("\nInvalid INPUT :( TRY AGAIN");
      goto label;
    }
    
    break;

  case 4:
    EditRecord();
    break;

  case 5:
    DeleteRecord();
    break;

  case 6:
    Exit();
    exit(0);
    break;

  default:
    printf("\t\t\tInvalid Input. Try Again!!\n\t\t\tEnter Again : \n");
    getch();
  }
}

/**********************................ADD NEW PATIENT RECORD..................*************************/
void Add_new()
{
  system("cls");
  title();

  char option;
  int valid;
  FILE *ek;
  ek = fopen("Record.dat", "a+");
  printf("\n\n\t*************** ADD PATIENT RECORD ***********\n");

label_1:
{
  printf("\n\t\t\tFirstName : ");
  scanf("%s", p.FirstName);
  p.FirstName[0] = toupper(p.FirstName[0]);
}
  if (strlen(p.FirstName) > 20 || strlen(p.FirstName) < 2)
  {
    printf("\n\t Invalid \t The max Range for first name is 20 and min range is 2\n");
    goto label_1;
  }
  else
  {
    for (int b = 0; b < strlen(p.FirstName); b++)
    {
      if (isalpha(p.FirstName[b]))
      {
        valid = 1;
      }

      else
      {
        valid = 0;
        break;
      }
    }

    if (!valid)
    {
      printf("\n\t\t First Name contains Invalid Character . Enter Again :\n");
      goto label_1;
    }
  }


label_3:
{
  printf("\n\t\t\tLast Name : ");
  scanf("%s", p.LastName);
  p.LastName[0] = toupper(p.LastName[0]);
}
  if (strlen(p.LastName) > 20 || strlen(p.LastName) < 2)
  {
    printf("\n\t Invalid \t The max Range for first name is 20 and min range is 2\n");
    goto label_3;
  }
  else
  {
    for (int b = 0; b < strlen(p.LastName); b++)
    {
      if (isalpha(p.LastName[b]))
      {
        valid = 1;
      }

      else
      {
        valid = 0;
        break;
      }
    }
  }

  if (!valid)
  {
    printf("\n\t\t Last Name contains Invalid Character . Enter Again :\n");
    goto label_3;
  }

  fputs("\n", ek);
  
  fputs(p.FirstName, ek);
  fputs(" ", ek);
  fputs(p.LastName, ek);


gen_switch:
{
  char gen;

  printf("\n\t\tGENDER (M/m OR F/f OR T/t) :");
  scanf(" %c", &gen);

  switch (gen)
  {
  case 'M':
  case 'm':
  strcpy(p.Gender,"MALE");
    break;
  case 'F':
  case 'f':
      strcpy(p.Gender,"FEMALE");
    break;
  case 'T':
  case 't':
    strcpy(p.Gender,"TRANS");
    break;
  default:
    printf("Invalid Input !\t Enter Again:\n");
    goto gen_switch;
    break;
  }
}

label_4:
{
  printf("\n\t\t\tContact Number : ");
  scanf("%s", p.ContactNo);
}

  if (strlen(p.ContactNo) != 10)
  {
    printf("\n\t Invalid \t Check the number once again!! 10 digit numbers required :)\n");
    goto label_4;
  }
  else
  {
    for (int b = 0; b < strlen(p.ContactNo); b++)
    {
      if (isdigit(p.ContactNo[b]))
      {
        valid = 1;
      }

      else
      {
        valid = 0;
        break;
      }
    }

    if (!valid)
    {
      printf("\n\t\tNumber contains character other than digits!!! Enter Again :\n");
      goto label_4;
    }
  }
label_5:
{
  printf("\n\t\t\tAge : ");
  scanf("%s", p.Age);
}
  if (strlen(p.Age) > 4)
  {
    printf("\n\t Invalid!\tEnter Again:\n");
    goto label_5;
  }
  else
  {
    for (int b = 0; b < strlen(p.Age); b++)
    {
      if (isdigit(p.Age[b]))
      {
        valid = 1;
      }

      else
      {
        valid = 0;
        break;
      }
    }

    if (!valid)
    {
      printf("\n\t\tAge contains character other than digits!!! Enter Again :\n");
      goto label_5;
    }
  }

label_8:
{
  printf("\n\t\t\tAddress :");
  scanf("%s", p.District);
}
  if (strlen(p.District) > 20 || strlen(p.District) < 2)
  {
    printf("\n\t Invalid \t The max Range for District name is 20 and min range is 2\n");
    goto label_8;
  }
  else
  {
    for (int b = 0; b < strlen(p.District); b++)
    {
      if (isalpha(p.District[b]))
        valid = 1;

      else
      {
        valid = 0;
        break;
      }
    }

    if (!valid)
    {
      printf("\n\t\t District Name contains Invalid Character . Enter Again :\n");
      goto label_8;
    }
  }

int flag1;
int flag2;
label_10:
{
  printf("\n\t\t\tE-mail :");
  scanf("%s", p.Email);
}
  if (strlen(p.Email) < 10)
  {
    printf("\n\t Invalid!! \n");
    goto label_10;
  }
  else
  {
    for (int b = 0; b < strlen(p.Email); b++)
    {
      if (p.Email[b]==64 )
        {
            flag1 = 1;
            break;
        }    
        else
        {
            flag1=0;
    
        }
        
    } 
    for (int b = 0; b < strlen(p.Email); b++)
    {
      if (p.Email[b]==46 )
      {
        flag2=1;
        break;
      }
      else
      {
          flag2=0;

      }
      
    } 

    if (flag1!=1 || flag2!=1)
    {
      printf("\n\t\t Email seems to be Invalid, Check and Try Again\t Enter Again :\n");
      goto label_10;
    }
  }
 
    printf("\n\t\t\tBLOOD GROUP:");
    scanf("%s",p.BloodGroup);

    for (int i = 0; i < strlen(p.BloodGroup); i++)
    {
      p.BloodGroup[i]=toupper(p.BloodGroup[i]);
    }
    
  
  p.District[0] = toupper(p.District[0]);
  
  for (int i = 0; i < strlen(p.Email); i++)
  {
    p.Email[i]=tolower(p.Email[i]);
  }
  
  fputs("\n", ek);
  fputs(p.Gender, ek);
  fputs("\n", ek);
  fputs(p.Age, ek);
  fputs("\n", ek);
  fputs(p.ContactNo, ek);
  
  
  fputs("\n", ek);
  fputs(p.District, ek);
  fputs("\n", ek);
  fputs(p.Email, ek);
  fputs("\n", ek);
  fputs(p.BloodGroup, ek);
  fputs("\n",ek);

  fclose(ek);
/******************************************************/
  FILE *two;
  two = fopen("Record2.dat", "a+");
  fputs("\n", two);
  fputs(p.BloodGroup, two);
  fputs("\n",two);
  fputs(p.FirstName, two);
  fputs(" ", two);
  fputs(p.LastName, two);
  fputs("\n",two);
  fputs(p.Gender, two);
  fputs("\n", two);
  fputs(p.Age, two);
  fputs("\n", two);
  fputs(p.ContactNo, two);
  fputs("\n", two);
  fputs(p.District, two);
  fputs("\n", two);
  fputs(p.Email, two);
  fputs("\n", two);

  fclose(two);
/**********------INSIDE ADD NEW OF FUNCTION ASKING FOR ADDING MORE RECORD------**************/
cbi:
{
  printf("\nDO YOU WANT TO ADD RECORD OF ANOTHER PATIENT? \n Y/y - YES \n N/n - NO \n");
  char ans;
  printf("Your choice:");
  scanf(" %c", &ans);
  if (ans == 'y' || ans == 'Y')
  {
    Add_new();
  }
  else if (ans == 'n' || ans == 'N')
  {
    printf("Thank-You\n");
    printf("\nPress any key to continue...");
    getch();
    MainMenu();
  }
  else
  {
    printf("Invalid INPUT!!");
    goto cbi;
  }
}
}
/*****************-----------DISPLAY RECORD FUNCTION------------***********************/
/************************........LIST ALL DATA.......************************/
void list()
{
  int row;
  system("cls");
  title();
  FILE *ek;
  ek = fopen("Record.dat", "r");

  printf("\n\n******************-----------Patients Record-----------******************");
  gotoxy(1, 8);
  printf("Full Name");
  gotoxy(20, 8);
  printf("Gender");
  gotoxy(32, 8);
  printf("Age");
  gotoxy(37, 8);
  printf("Contact No.");
  gotoxy(49, 8);
  printf("Address");
  gotoxy(64, 8);
  printf("E-mail");
  gotoxy(95, 8);
  printf("B. Group");

  printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
  row = 10;

  while (fscanf(ek, "%s %s \n%s \n%s \n%s \n%s \n%s \n%s \n", p.FirstName, p.LastName,p.Gender, p.Age, p.District, p.ContactNo, p.Email, p.BloodGroup) != EOF)

  {
    gotoxy(1, row);
    printf("%s %s", p.FirstName,p.LastName);
    gotoxy(20, row);
    printf("%s", p.Gender);
    gotoxy(32, row);
    printf("%s", p.Age);
    gotoxy(37, row);
    printf("%s", p.District);
    gotoxy(49, row);
    printf("%s", p.ContactNo);
    gotoxy(64, row);
    printf("%s", p.Email);
    gotoxy(95, row);
    printf("%s", p.BloodGroup);
    row++;
  }
  fclose(ek);
    printf("\nPress any key to continue...");

  getch();
  MainMenu();
}

/******************............SEARCH BY NAME FUNCTION...........*******************/
void SearchRecord()
{
  bool found = FALSE;
  char name[20], ans;
  int row = 10;
  system("cls");
  title();
  FILE *ek;
  ek = fopen("Record.dat", "r");
  printf("\n Enter Patient Name to be Searched : ");
  scanf("%s", name);
  fflush(stdin);
  name[0] = toupper(name[0]);

      gotoxy(1, 7);
      printf("Full Name");
      gotoxy(25, 7);
      printf("Gender");
      gotoxy(32, 7);
      printf("Age");
      gotoxy(37, 7);
      printf("Contact No.");
      gotoxy(52, 7);
      printf("Address");
      gotoxy(64, 7);
      printf("Email");
      gotoxy(95, 7);
      printf("B.Group");
  printf("\n-----------------------------------------------------------------------------------------------------------------------\n");


  while (fscanf(ek, "%s %s \n%s \n%s \n%s \n%s \n%s \n%s \n", p.FirstName, p.LastName, p.Gender, p.Age, p.District, p.ContactNo, p.Email, p.BloodGroup) != EOF)

  {
    if (strcmp(p.FirstName, name) == 0)
    {
        found=TRUE;
      

      gotoxy(1, row);
      printf("%s %s", p.FirstName, p.LastName);
      gotoxy(25, row);
      printf("%s", p.Gender);
      gotoxy(32, row);
      printf("%s", p.Age);
      gotoxy(37, row);
      printf("%s", p.District);
      gotoxy(52, row);
      printf("%s", p.ContactNo);
      gotoxy(64, row);
      printf("%s", p.Email);      
      gotoxy(95, row);
      printf("%s", p.BloodGroup);

      printf("\n");
        row++;
    }
  }

  if (found==FALSE)
  {
    
    gotoxy(40, 12);
    printf("Record Not Found!");
  }
  fclose(ek);
L:
  printf("\nPress any key to continue...");
  getch();
  printf("\n\n\t\t\tDo you want to view more[Y/N]:");
  scanf(" %c", &ans);
  if (toupper(ans) == 'Y')
  {
    SearchRecord();
  }
  else if (toupper(ans) == 'N')
  {
    printf("\n\t\t Thank you ");
    printf("\nPress any key to continue...");
    getch();
    MainMenu();
  }
  else
  {
    printf("\n\tInvalid Input!!!\n");
    goto L;
  }
}

/*********************........SEARCH BY BLOOD GROUP FUNCTION..............**************************************/

void SearchRecordByBloodGroup()
{
  bool found = FALSE;
  char bgroup[5], ans;
  int row = 10;
  system("cls");
  title();
  FILE *two;
  two = fopen("Record2.dat", "r");
  printf("\n Enter BloodGroup to be Searched : ");
  scanf("%s", bgroup);
  fflush(stdin);
  for (int i = 0; i < strlen(bgroup); i++)
  {
    bgroup[i]=toupper(bgroup[i]);
  }
  

      gotoxy(1, 7);
      printf("Full Name");
      gotoxy(25, 7);
      printf("Gender");
      gotoxy(32, 7);
      printf("Age");
      gotoxy(37, 7);
      printf("Contact No.");
      gotoxy(52, 7);
      printf("Address");
      gotoxy(64, 7);
      printf("Email");
      gotoxy(95, 7);
      printf("B.Group");
  printf("\n-----------------------------------------------------------------------------------------------------------------------\n");


  while (fscanf(two, "%s \n%s %s \n%s \n%s \n%s \n%s \n%s \n", p.BloodGroup, p.FirstName, p.LastName, p.Gender, p.Age, p.District, p.ContactNo, p.Email) != EOF)

  {
    if (strcmp(p.BloodGroup, bgroup) == 0)
    {
        found=TRUE;
      

      gotoxy(1, row);
      printf("%s %s", p.FirstName, p.LastName);
      gotoxy(25, row);
      printf("%s", p.Gender);
      gotoxy(32, row);
      printf("%s", p.Age);
      gotoxy(37, row);
      printf("%s", p.District);
      gotoxy(52, row);
      printf("%s", p.ContactNo);
      gotoxy(64, row);
      printf("%s", p.Email);      
      gotoxy(95, row);
      printf("%s", p.BloodGroup);

      printf("\n");
        row++;
    }
  }

  if (found==FALSE)
  {
    
    gotoxy(40, 12);
    printf("Record Not Found!");
  }
  fclose(two);
P:
  printf("\nPress any key to continue...");
  getch();
  printf("\n\n\t\t\tDo you want to view more[Y/N]:");
  scanf(" %c", &ans);
  if (toupper(ans) == 'Y')
  {
    SearchRecordByBloodGroup();
  }
  else if (toupper(ans) == 'N')
  {
    printf("\n\t\t Thank you ");
    printf("\nPress any key to continue...");
    getch();
    MainMenu();
  }
  else
  {
    printf("\n\tInvalid Input!!!\n");
    goto P;
  }
}



/************************...........EDIT RECORD FUNCTION...............*******************************/
void EditRecord()
{
  FILE *ek, *ft;
  FILE *don, *mt;
  int i,b,valid=0;
  char ch;
  char name[30];
  int row=14;
  char yes_no;
  system("cls");
  title();
  ft=fopen("temp.dat","w+");
  mt=fopen("temp2.dat","w+");
  ek=fopen("Record.dat","r");
  don=fopen("Record2.dat","r");

  if(ek==NULL || don==NULL)
  {
    printf("\n\t Can Not Open File!!");
    getch;
    MainMenu();
  }
  printf("\n\n\t\t\t**********EDIT RECORD************\n");
  gotoxy(12,9);
  printf("Enter The First Name Of the Patient : ");
  scanf(" %s",name);
  fflush(stdin);
  name[0]=toupper(name[0]);
  gotoxy(12,15);
  
      gotoxy(1, 12);
      printf("Full Name");
      gotoxy(25, 12);
      printf("Gender");
      gotoxy(32, 12);
      printf("Age");
      gotoxy(37, 12);
      printf("Contact No.");
      gotoxy(52, 12);
      printf("Address");
      gotoxy(64, 12);
      printf("Email");
      gotoxy(95, 12);
      printf("B.Group");
  printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
      
  while (fscanf(ek, "%s %s \n%s \n%s \n%s \n%s \n%s \n%s \n", p.FirstName, p.LastName, p.Gender, p.Age, p.ContactNo, p.District, p.Email, p.BloodGroup) != EOF)
  {
    if(strcmp(p.FirstName,name)==0)
    {
      valid=1;
      gotoxy(25,11);
      printf("***Existing Record***");
      
      gotoxy(1, row);
      printf("%s %s", p.FirstName, p.LastName);
      gotoxy(25, row);
      printf("%s", p.Gender);
      gotoxy(32, row);
      printf("%s", p.Age);
      gotoxy(37, row);
      printf("%s", p.District);
      gotoxy(52, row);
      printf("%s", p.ContactNo);
      gotoxy(64, row);
      printf("%s", p.Email);      
      gotoxy(95, row);
      printf("%s", p.BloodGroup);

      printf("\n");
        row++;
      edit_again:{
      printf(" \n\t\tIs this your required data to edit?? {Y/y OR N/n}");
      printf("\n\t\tYour Choice:");
      scanf(" %c",&yes_no);
      }


      if (yes_no=='Y' || yes_no=='y')
      {

      label_1:
{
  printf("\n\t\t\tUpdate First Name as: ");
  scanf("%s", p.FirstName);
  p.FirstName[0] = toupper(p.FirstName[0]);
}
  if (strlen(p.FirstName) > 20 || strlen(p.FirstName) < 2)
  {
    printf("\n\t Invalid \t The max Range for first name is 20 and min range is 2\n");
    goto label_1;
  }
  else
  {
    for (int b = 0; b < strlen(p.FirstName); b++)
    {
      if (isalpha(p.FirstName[b]))
      {
        valid = 1;
      }

      else
      {
        valid = 0;
        break;
      }
    }

    if (!valid)
    {
      printf("\n\t\t First Name contains Invalid Character . Enter Again :\n");
      goto label_1;
    }
  }
      label_3:
{
  printf("\n\t\t\tUpdated Last Name : ");
  scanf("%s", p.LastName);
  p.LastName[0] = toupper(p.LastName[0]);
}
  if (strlen(p.LastName) > 20 || strlen(p.LastName) < 2)
  {
    printf("\n\t Invalid \t The max Range for first name is 20 and min range is 2\n");
    goto label_3;
  }
  else
  {
    for (int b = 0; b < strlen(p.LastName); b++)
    {
      if (isalpha(p.LastName[b]))
      {
        valid = 1;
      }

      else
      {
        valid = 0;
        break;
      }
    }
  }

  if (!valid)
  {
    printf("\n\t\t Last Name contains Invalid Character . Enter Again :\n");
    goto label_3;
  }
      gen_switch:
{
  char gen;

  printf("\n\t\tGENDER (M/m OR F/f OR T/t) :");
  scanf(" %c", &gen);

  switch (gen)
  {
  case 'M':
  case 'm':
  strcpy(p.Gender,"MALE");
    break;
  case 'F':
  case 'f':
      strcpy(p.Gender,"FEMALE");
    break;
  case 'T':
  case 't':
    strcpy(p.Gender,"TRANS");
    break;
  default:
    printf("Invalid Input !\t Enter Again:\n");
    goto gen_switch;
    break;
  }
}
      label_5:
{
  printf("\n\t\t\t Age : ");
  scanf("%s", p.Age);
}
  if (strlen(p.Age) > 4)
  {
    printf("\n\t Invalid!\tEnter Again:\n");
    goto label_5;
  }
  else
  {
    for (int b = 0; b < strlen(p.Age); b++)
    {
      if (isdigit(p.Age[b]))
      {
        valid = 1;
      }

      else
      {
        valid = 0;
        break;
      }
    }

    if (!valid)
    {
      printf("\n\t\tAge contains character other than digits!!! Enter Again :\n");
      goto label_5;
    }
  }
      label_8:
{
  printf("\n\t\t\tAddress :");
  scanf("%s", p.District);
}
  if (strlen(p.District) > 20 || strlen(p.District) < 2)
  {
    printf("\n\t Invalid \t The max Range for District name is 20 and min range is 2\n");
    goto label_8;
  }
  else
  {
    for (int b = 0; b < strlen(p.District); b++)
    {
      if (isalpha(p.District[b]))
        valid = 1;

      else
      {
        valid = 0;
        break;
      }
    }

    if (!valid)
    {
      printf("\n\t\t District Name contains Invalid Character . Enter Again :\n");
      goto label_8;
    }
  }

  p.District[0] = toupper(p.District[0]);
      label_4:
{
  printf("\n\t\t\tContact Number : ");
  scanf("%s", p.ContactNo);
}

  if (strlen(p.ContactNo) != 10)
  {
    printf("\n\t Invalid \t Check the number once again!! 10 digit numbers required :)\n");
    goto label_4;
  }
  else
  {
    for (int b = 0; b < strlen(p.ContactNo); b++)
    {
      if (isdigit(p.ContactNo[b]))
      {
        valid = 1;
      }

      else
      {
        valid = 0;
        break;
      }
    }

    if (!valid)
    {
      printf("\n\t\tNumber contains character other than digits!!! Enter Again :\n");
      goto label_4;
    }
  }
      int flag1;
int flag2;
label_10:
{
  printf("\n\t\t\tE-mail :");
  scanf("%s", p.Email);
}
  if (strlen(p.Email) < 10)
  {
    printf("\n\t Invalid!! \n");
    goto label_10;
  }
  else
  {
    for (int b = 0; b < strlen(p.Email); b++)
    {
      if (p.Email[b]==64 )
        {
            flag1 = 1;
            break;
        }    
        else
        {
            flag1=0;
    
        }
        
    } 
    for (int b = 0; b < strlen(p.Email); b++)
    {
      if (p.Email[b]==46 )
      {
        flag2=1;
        break;
      }
      else
      {
          flag2=0;

      }
      
    } 

    

    if (flag1!=1 || flag2!=1)
    {
      printf("\n\t\t Email seems to be Invalid, Check and Try Again\t Enter Again :\n");
      goto label_10;
    }
  }

  for (int i = 0; i < strlen(p.Email); i++)
  {
    p.Email[i]=tolower(p.Email[i]);
  }
      printf("\n\t\t\tBLOOD GROUP:");
    scanf("%s",p.BloodGroup);

    for (int i = 0; i < strlen(p.BloodGroup); i++)
    {
      p.BloodGroup[i]=toupper(p.BloodGroup[i]);
    }

      printf("\nEnter C to confirm the changes : ");
      scanf(" %c",&ch);
              if(ch=='C' || ch=='c')
              {
              fputs("\n",ft);
              fprintf(ft,"%s %s \n%s \n%s \n%s \n%s \n%s \n%s \n",p.FirstName,p.LastName,p.Gender,p.Age,p.ContactNo,p.District,p.Email,p.BloodGroup);
              fputs("\n",mt);
              fprintf(mt, "%s \n%s %s \n%s \n%s \n%s \n%s \n%s \n", p.BloodGroup, p.FirstName, p.LastName, p.Gender, p.Age, p.ContactNo, p.District, p.Email);

              printf("\n\n\t\t\tRecord Updated Successfully.....");  
              }
              else
              {
                printf("\n\nPress any key to continue...");
                getch();
               MainMenu();
              }
      }
      else if(yes_no=='n'||yes_no=='N')
      {
      fputs("\n",ft);
      fprintf(ft,"%s %s \n%s \n%s \n%s \n%s \n%s \n%s \n",p.FirstName,p.LastName,p.Gender,p.Age,p.ContactNo,p.District,p.Email,p.BloodGroup);
      fputs("\n",mt);
      fprintf(mt, "%s \n%s %s \n%s \n%s \n%s \n%s \n%s \n", p.BloodGroup, p.FirstName, p.LastName, p.Gender, p.Age, p.ContactNo, p.District, p.Email);
      }
      else
      {
        printf("ENTER VALID INPUT : ( TRY AGAIN");
        goto edit_again;
      }
      
    }
    else
    {
      fputs("\n",ft);
      fprintf(ft,"%s %s \n%s \n%s \n%s \n%s \n%s \n%s \n",p.FirstName,p.LastName,p.Gender,p.Age,p.ContactNo,p.District,p.Email,p.BloodGroup);
      fputs("\n",mt);
      fprintf(mt, "%s \n%s %s \n%s \n%s \n%s \n%s \n%s \n", p.BloodGroup, p.FirstName, p.LastName, p.Gender, p.Age, p.ContactNo, p.District, p.Email);

    }
  }
  if(!valid)
  {
    printf("\n\t\tNO RECORDS FOUND......");
  }
  fclose(ft); fclose(ek);
  fclose(mt); fclose(don);
  remove("Record.dat");
  rename("temp.dat","Record.dat");
  remove("Record2.dat");
  rename("temp2.dat","Record2.dat");

  printf("\n\nPress any key to continue...");
  getch();
  MainMenu();
}
/********************...........DELETE RECORD FUNCTION...........*********************************/
void DeleteRecord()
{
  int row=14;
  char name [20];
  int found=0;
  char ch;
  system("cls");
  title();
  FILE *ek, *ft, *mt, *don;
  ft = fopen("temp3.dat","w+");
  ek = fopen("Record.dat","r");
  mt = fopen("temp4.dat","w+");
  don = fopen("Record2.dat","r");
  printf("\n\n\t\t\t************ Delete Patients Record *************\n");
  gotoxy(12,8);
  printf("\n Enter Patient's Name(to be Deleted) : ");
  fflush(stdin);
  gets(name);
  
  name[0]=toupper(name[0]);

  if(ek==NULL)
  {
    printf("\n\t Can Not Open File!!");
    getch;
    MainMenu();
  }

  while (fscanf(ek,"%s %s \n%s \n%s \n%s \n%s \n%s \n%s \n",p.FirstName,p.LastName,p.Gender,p.Age,p.District,p.ContactNo,p.Email,p.BloodGroup)!= EOF)
  {
    if(strcmp(p.FirstName,name) == 0)
    {
      found=1;
      printf("\n**********************.....DATA FOUND......********************\n\n");
      gotoxy(1, 12);
      printf("Full Name");
      gotoxy(25, 12);
      printf("Gender");
      gotoxy(32, 12);
      printf("Age");
      gotoxy(37, 12);
      printf("Contact No.");
      gotoxy(52, 12);
      printf("Address");
      gotoxy(64, 12);
      printf("Email");
      gotoxy(95, 12);
      printf("B.Group");
  printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
      gotoxy(1, row);
      printf("%s %s", p.FirstName, p.LastName);
      gotoxy(25, row);
      printf("%s", p.Gender);
      gotoxy(32, row);
      printf("%s", p.Age);
      gotoxy(37, row);
      printf("%s", p.District);
      gotoxy(52, row);
      printf("%s", p.ContactNo);
      gotoxy(64, row);
      printf("%s", p.Email);      
      gotoxy(95, row);
      printf("%s", p.BloodGroup);
      delete:{
  printf(" \n\n\nIs this your required data to DELETE?? {Y/y OR N/n}:");
  printf("\n\t\tYour Choice:");
  scanf(" %c",&ch);
      }

      if(ch=='Y' || ch=='y')
      {
        printf("\n\n\t\t\t Record Deleted Successfully ");
      }
      else if(ch=='N' || ch=='n')
      {
        fputs("\n",ft);
        fprintf(ft,"%s %s \n%s \n%s \n%s \n%s \n%s \n%s \n",p.FirstName,p.LastName,p.Gender,p.Age,p.ContactNo,p.District,p.Email,p.BloodGroup);
        fputs("\n",mt);
        fprintf(mt, "%s \n%s %s \n%s \n%s \n%s \n%s \n%s \n", p.BloodGroup, p.FirstName, p.LastName, p.Gender, p.Age, p.ContactNo, p.District, p.Email);

      }
      else{
        printf("ENTER VALID INPUT : ( TRY AGAIN");
        goto delete;
      }
    }
    else
    {
      fputs("\n",ft);
      fprintf(ft,"%s %s \n%s \n%s \n%s \n%s \n%s \n%s \n",p.FirstName,p.LastName,p.Gender,p.Age,p.ContactNo,p.District,p.Email,p.BloodGroup);
      fputs("\n",mt);
      fprintf(mt, "%s \n%s %s \n%s \n%s \n%s \n%s \n%s \n", p.BloodGroup, p.FirstName, p.LastName, p.Gender, p.Age, p.ContactNo, p.District, p.Email);
    }
  }
  if(!found)
  {
    printf("\n\n\t\t\tRECORD NOT FOUND!!!......");
    
  }
  
  
    fclose(ek); fclose(don);
    fclose(ft); fclose(mt);
    remove("Record.dat");
    rename("temp3.dat","Record.dat");
    remove("Record2.dat");
    rename("temp4.dat","Record2.dat");
    printf("\n\nPress any key to continue...");
    getch();
    MainMenu();
  
}
/************************............EXIT FUNCTION.......**************************************/
void Exit()
{
  system("cls");
  title();
  printf("\n\n\n\t\t\t Thanks for Visiting. Byee.......");
  getch();
}

/***************...................END OF CODE..................*******************/