#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void addRoutine();
void viewRoutine();
void addSeatPlan();
void checkSeatPlan();
void showSeatPlan();
void updateDeleteInfo();
void addTeacherInfo();
void checkteacherInfo();
int checkRoutInfo(int,char[20]);
int checkStdInfo(char id[20],char c[20]);
void deleteRoutine();
void deleteRoutineSpec();
void deleteRoutineBat();
void deleteSeatPlan();
void deleteTeacInfo();
void editRoutine();
void creatorsInfo();

FILE *fr,*ft,*fs,*fd;

struct Routine{
  int batch;
  float time;
  char zone[5];
  char examName[20];
  char date[20];
}r1;

struct SeatPlan{
  char id[20];
  char examName[20];
  int roomNumber;
  int coloumn;
  int benchNo;
}s1;

struct TeacherInfo{
  int roomNumber;
  char date[15];
  int totalStud;
  float time;
  char zone[5];
  char ini1[10];
  char ini2[10];
  char id1[20];
  char id2[20];
}t1;

int main()
{
  int i;
  system("clear");
  printf("\t MAIN MENU\t\n");
  printf("1.View Routine\n");
  printf("2.Teacher Info\n");
  printf("3.Check Seat Plan\n");
  printf("4.Update & Delete Info\n");
  printf("5.Creators Info\n");
  printf("6.Close Application\n");
  scanf("%d",&i);
  switch(i)
    {
        case 1:
        viewRoutine();
        break;
        case 2:
        checkteacherInfo();
        break;
        case 3:
        checkSeatPlan();
        break;
        case 4:
        updateDeleteInfo();
        break;
        case 5:
        creatorsInfo();
        break;
        case 6:
        {
        system("clear");
        printf("Thanks for using the Program..");
        printf("Exiting in 5 second...........>");
         exit(0);
        }
        default:
        {
        printf("\aWrong Entry!!Please re-entered correct option");
        }
    }
}
void addRoutine(){
  system("clear");
  int b;
  char d[20];
  fr=fopen("routine.dat","ab+");
  printf("\t\Add Routine\t\n");
  printf("\n\t-> Batch : ");
  scanf("%d",&b);
  printf("\n\t-> Exam date (dd-mm-yyyy) : ");
  scanf("%s",&d);
  if(checkRoutInfo(b,d)== 0)
    {
        printf("\t---schedule exist---");
        printf("\n\t press 'n' to UPDATE & DELETE INFO \n\tElse to Add routine\n");
        getchar();
        if(getchar()=='n'){
           updateDeleteInfo();
        }
        else{
            addRoutine();
       }
    }
  r1.batch = b;
  strcpy(r1.date,d);
  printf("\n\t-> Exam Time : ");
  scanf("%f",&r1.time);
  printf("\n\t-> AM/PM : ");
  scanf("%s",&r1.zone);
  printf("\n\t-> Course Code : ");
  scanf("%s",&r1.examName);
  fseek(fr,0,SEEK_END);
  fwrite(&r1,sizeof(r1),1,fr);
  fclose(fr);
  printf("\n\tThe record is sucessfully saved\n");
  printf("Save any more?(Y / N):");
  getchar();
  if(getchar()=='n'){
        updateDeleteInfo();
        }
  else{
     addRoutine();
  }
}
int checkRoutInfo(int b,char d[20])
{
    rewind(fr);
    while(fread(&r1,sizeof(r1),1,fr)==1){
    if((b==r1.batch) && (strcmp(d,r1.date)==0)){
    return 0;
    }
  }
  return 1;
}
void viewRoutine(){
   int b;
   system("clear");
   printf("\t--> Enter Batch: ");
   scanf("%d",&b);
   system("clear");
   printf("\t---------------- BATCH- %d -----------------\n",b);
   printf("\t----------------EXAM ROUTINE----------------\n");
   printf("\t--------------------------------------------\n");
   printf("\t COURSE CODE \t DATE \t\t TIME\n");
   printf("\t--------------------------------------------\n");
   fr=fopen("routine.dat","rb");
   while(fread(&r1,sizeof(r1),1,fr)==1){
   if((b == r1.batch)){
   printf("\t %s",r1.examName);
   printf("\t\t%s",r1.date);
   printf("\t %.2f %s",r1.time,r1.zone);
   printf("\n\n");
    }
   }
   fclose(fr);
   printf("\n\t press 'b' to goto MAIN MENU: ");
   getchar();
   if(getchar()=='b'){
       main();
   }
}
void addSeatPlan(){
  system("clear");
  char id[20];
  char c[20];
  fs=fopen("student.dat","ab+");
  printf("\t\Add Seat PLan\t\n");
  printf("\t-> Student ID:\t");
  scanf("%s",&id);
  printf("\n\t-> Exam Name:\t");
  scanf("%s",&c);
  if(checkStdInfo(id,c)== 0)
    {
        printf("\t---Seat plan updated already---");
        printf("\n\t press 'n' to UPDATE & DELETE INFO \n\tElse to Add Seat Plan\n");
        getchar();
        if(getchar()=='n'){
            updateDeleteInfo();
        }
        else{
            addSeatPlan();
       }
    }
  strcpy(s1.id,id);
  strcpy(s1.examName,c);
  printf("\n\t-> Room Number:\t");
  scanf("%d",&s1.roomNumber);
  printf("\n\t-> Coloumn No:\t");
  scanf("%d",&s1.coloumn);
  printf("\n\t-> Bench No:\t");
  scanf("%d",&s1.benchNo);
  fseek(fs,0,SEEK_END);
  fwrite(&s1,sizeof(s1),1,fs);
  fclose(fs);
  printf("\n\tThe record is sucessfully saved\n");
  printf("Save any more?(Y / N):");
  getchar();
  if(getchar()=='n'){
        updateDeleteInfo();
        }
  else{
     addSeatPlan();
  }
}

int checkStdInfo(char id[20],char c[20])
{
    rewind(fs);
    while(fread(&s1,sizeof(s1),1,fs)==1){
    if((strcmp(id,s1.id)==0) && (strcmp(c,s1.examName)==0)){
    return 0;
    }
  }
  return 1;
}

void checkSeatPlan(){
   system("clear");
   char id[20];
   char courseCode[20];
   int flag = 0;
   printf("\tEnter Id and Course code to Check Seat PLan\t\n");
   printf("\t-> Student ID:\t");
   scanf("%s",&id);
   printf("\n\t-> Exam Name:\t");
   scanf("%s",&courseCode);
   fs=fopen("student.dat","rb");
   rewind(fs);
   while(fread(&s1,sizeof(s1),1,fs)==1){
   if((strcmp(s1.id,(id)) == 0) && (strcmp(s1.examName,(courseCode)) == 0)){
     showSeatPlan();
     int flag=1;
    }
   }
   if(flag != 1){
     printf("\t----Invalid Student ID or COURSE CODE----\t");
     printf("\t----Search Again?(Y / N):\t");
     getchar();
     if(getchar()=='n'){
        main();
        }
    else{
        checkSeatPlan();
     }
   }
   fclose(fs);
}
void showSeatPlan(){
   system("clear");
   printf("\tShowing Seat PLan\t\n");
   printf("\n\t-> Course Code: %s\t",s1.examName);
   printf("\n\t-> Room Number: %d\t",s1.roomNumber);
   printf("\n\t-> Coloumn No: %d\t",s1.coloumn);
   printf("\n\t-> Bench No: %d\t",s1.benchNo);
   printf("\n\tPress 'n' to Go back to MAIN MENU:");
   getchar();
   if(getchar()=='n'){
        main();
    }
}
void addTeacherInfo(){
   system("clear");
   ft=fopen("teacher.dat","ab+");
   printf("\tEnter Teacher info\t\n");
   printf("\t-> Enter Room Number: ");
   scanf("%d",&t1.roomNumber);
   printf("\n\t-> Enter Date(dd-mm-yyyy): ");
   scanf("%s",&t1.date);
   printf("\n\t-> Duty time: ");
   scanf("%f",&t1.time);
   printf("\n\t-> AM/PM : ");
   scanf("%s",&t1.zone);
   printf("\n\t-> Enter total number of Student: ");
   scanf("%d",&t1.totalStud);
   printf("\n\t-> Invigilator 1: ");
   printf("\n\t-> ID:\t");
   scanf("%s",&t1.id1);
   printf("\n\t-> Teacher Initial:");
   scanf("%s",&t1.ini1);
   printf("\n\t-> Invigilator 2: ");
   printf("\n\t-> ID:\t");
   scanf("%s",&t1.id2);
   printf("\n\t-> Teacher Initial: ");
   scanf("%s",&t1.ini2);
   fseek(ft,0,SEEK_END);
   fwrite(&t1,sizeof(t1),1,ft);
   fclose(ft);
   printf("\n\tThe record is sucessfully saved\n");
   printf("Save any more?(Y / N):");
   getchar();
   if(getchar()=='n'){
        updateDeleteInfo();
        }
   else{
     addTeacherInfo();
   }
}

void checkteacherInfo(){
   system("clear");
   char id[20];
   char date[15];
   int flag=0;
   printf("\tEnter Id and Date to Check info\t\n");
   printf("\t-> ID: ");
   scanf("%s",&id);
   printf("\n\t-> Date(dd-mm-yyyy): ");
   scanf("%s",&date);
   ft=fopen("teacher.dat","rb");
   system("clear");
   while(fread(&t1,sizeof(t1),1,ft)==1){
      if(((strcmp(id,t1.id1)==0) || (strcmp(id,t1.id2)==0)) && (strcmp(date,t1.date)==0)){
        printf("\t\Showing Teacher INFO\t\n");
        printf("\n\t-> Date: %s\t",t1.date);
        printf("\n\t-> Room Number: %d\t",t1.roomNumber);
        printf("\n\t-> Duty Time: %.2f %s\t",t1.time,t1.zone);
        if(strcmp(id,t1.id1)==0){
        printf("\n\t-> Invigilator Partner: %s\t",t1.ini2);
        }
        else{
        printf("\n\t-> Invigilator Partner: %s\t",t1.ini1);
        }
        printf("\n\t-> Total Student: %d\t",t1.totalStud);
        printf("\n\n");
        flag = 1;
      }
    }
    if(flag == 1){
         printf("\n\tPress 'n' to Go back to MAIN MENU:");
         getchar();
         if(getchar()=='n'){
          main();
        }
     }
    if(flag != 1){
     printf("\t----Sorry sir you don't have any Duty today----\t");
     printf("\t----Search Again?(Y / N):\t");
     getchar();
     if(getchar()=='n'){
        main();
        }
    else{
        checkteacherInfo();
     }
   }
   fclose(ft);
}
void updateDeleteInfo(){
  int i;
  system("clear");
  printf("\t UPDATE & DELETE INFO\t\n");
  printf("1.Add Routine\n");
  printf("2.Delete Routine\n");
  printf("3.Edit Routine\n");
  printf("4.Add Teacher Info\n");
  printf("5.Delete Teacher Info\n");
  printf("6.Add Seat Plan\n");
  printf("7.Delete Seat Plan\n");
  printf("8.Back to MAIN MENU\n");
  scanf("%d",&i);
  switch(i)
    {
        case 1:
        addRoutine();
        break;
        case 2:
        deleteRoutine();
        break;
        case 3:
        editRoutine();
        break;
        case 4:
        addTeacherInfo();
        break;
        case 5:
        deleteTeacInfo();
        break;
        case 6:
        addSeatPlan();
        break;
        case 7:
        deleteSeatPlan();
        break;
        case 8:
        main();
        break;
        default:
        updateDeleteInfo();

     }
}

void deleteRoutine()
{
    int i;
    system("clear");
    printf("\t DELETE STUDENT INFO\t\n");
    printf("1.Delete Whole Batch Routine\n");
    printf("2.Delete Specific Routine\n");
    printf("3.Back To MAIN MENU\n");
    scanf("%d",&i);
    switch(i)
    {
        case 1:
        deleteRoutineBat();
        break;
        case 2:
        deleteRoutineSpec();
        break;
        case 3:
        main();
        break;
        default:
        updateDeleteInfo();
    }

}

void deleteRoutineBat(){
        int d;
        int flag = 0;
        system("clear");
        printf("\t ->Enter the Batch: ");
        scanf("%d",&d);
        fr=fopen("routine.dat","rb+");
        rewind(fr);
        while(fread(&r1,sizeof(r1),1,fr)==1)
       {
            printf("\t---------------- BATCH- %d -----------------\n",d);
            printf("\t----------------EXAM ROUTINE----------------\n");
            printf("\t--------------------------------------------\n");
            printf("\t COURSE CODE \t DATE \t\t TIME\n");
            printf("\t--------------------------------------------\n");
            if(r1.batch == d)
           {
                printf("\t %s",r1.examName);
                printf("\t\t%s",r1.date);
                printf("\t %.2f %s",r1.time,r1.zone);
                printf("\n\n");
                flag = 1;
           }
        }
    if(flag != 1)
        {
          printf("\n\tNo schedule is found modify the search");
          printf("\n\tpress 'y' to goto UPDATE DELETE INFO");
          getchar();
          if(getchar()=='y'){
           updateDeleteInfo();
          }
        }
    if(flag == 1)
    {
           printf("\n\tDo you want to delete it?(Y/N):");
           getchar();
           if(getchar() =='y')
           {
             fd=fopen("test.dat","wb+");
             rewind(fr);
             while(fread(&r1,sizeof(r1),1,fr)==1)
             {
                   if(r1.batch != d)
                  {
                    fseek(fd,0,SEEK_CUR);
                    fwrite(&r1,sizeof(r1),1,fd);
                  }
             }
             fclose(fd);
             fclose(fr);
             remove("routine.dat");
             rename("test.dat","routine.dat");
             fr=fopen("routine.dat","rb+");
             printf("\nThe record is sucessfully deleted");
             printf("\nDelete another record?(Y/N)");
             getchar();
             if(getchar()=='n'){
             updateDeleteInfo();
              }
             else{
             deleteRoutine();
              }
           }
           else{
            updateDeleteInfo();
          }
     }
}

void deleteRoutineSpec(){
        int d;
        char c[20];
        int flag = 0;
        system("clear");
        printf("\t ->Enter the Batch: ");
        scanf("%d",&d);
        printf("\n\t ->Enter the Course Code: ");
        scanf("%s",&c);
        fr=fopen("routine.dat","rb+");
        rewind(fr);
        while(fread(&r1,sizeof(r1),1,fr)==1)
        {
              if((r1.batch == d) && (strcmp(c,r1.examName) == 0))
               {
                 printf("\n\tSchedule for %s is available", r1.examName);
                 printf("\n\tDate is %s",r1.date);
                 printf("\n\tTime is %.2f %s",r1.time,r1.zone);
                 flag = 1;
               }
         }
        if(flag != 1)
        {
           printf("\n\tNo schedule is found modify the search");
           printf("\n\tpress 'y' to goto UPDATE AND DELETE INFO");
           getchar();
           if(getchar()=='y'){
              updateDeleteInfo();
           }
        }
        if(flag == 1)
        {
           printf("\n\tDo you want to delete it?(Y/N):");
           getchar();
           if(getchar() =='y')
           {
             fd=fopen("test.dat","wb+");
             rewind(fr);
              while(fread(&r1,sizeof(r1),1,fr)==1)
             {
                if((r1.batch != d) || (strcmp(c,r1.examName) != 0))
                {
                  fseek(fd,0,SEEK_CUR);
                  fwrite(&r1,sizeof(r1),1,fd);
                }
             }
               fclose(fd);
               fclose(fr);
               remove("routine.dat");
               rename("test.dat","routine.dat");
               fr=fopen("routine.dat","rb+");
               printf("\nThe record is sucessfully deleted");
               printf("\nDelete another record?(Y/N)");
               getchar();
            if(getchar()=='n'){
               updateDeleteInfo();
              }
            else{
              deleteRoutine();
             }
          }
          else{
           updateDeleteInfo();
        }
     }
}

void deleteSeatPlan(){
        char id[20];
        char c[20];
        int flag = 0;
        system("clear");
        printf("\t ->Enter ID: ");
        scanf("%s",&id);
        printf("\n\t ->Enter the Course Code: ");
        scanf("%s",&c);
        fs=fopen("student.dat","rb+");
        rewind(fs);
        while(fread(&s1,sizeof(s1),1,fs)==1)
        {
              if((strcmp(id,s1.id) == 0) && (strcmp(c,s1.examName) == 0))
               {
                 printf("\n\tSeat Plan for ID : %s is available", s1.id);
                 printf("\n\tCourse Code is %s",s1.examName);
                 printf("\n\tRoom No is %d",s1.roomNumber);
                 printf("\n\tColoumn No is %d",s1.coloumn);
                 printf("\n\tBench No is %d",s1.benchNo);
                 flag = 1;
               }
         }
        if(flag != 1)
        {
           printf("\n\tNo Seat Plan is found modify the search");
           printf("\n\tpress 'y' to goto UPDATE AND DELETE INFO");
           getchar();
           if(getchar()=='y'){
              updateDeleteInfo();
           }
        }
        if(flag == 1)
        {
           printf("\n\tDo you want to delete it?(Y/N):");
           getchar();
           if(getchar() =='y')
           {
             fd=fopen("test.dat","wb+");
             rewind(fs);
              while(fread(&s1,sizeof(s1),1,fs)==1)
             {
                if((strcmp(id,s1.id) != 0) || (strcmp(c,s1.examName) != 0))
                {
                  fseek(fd,0,SEEK_CUR);
                  fwrite(&s1,sizeof(s1),1,fd);
                }
              }
               fclose(fd);
               fclose(fs);
               remove("routine.dat");
               rename("test.dat","student.dat");
               fs=fopen("student.dat","rb+");
               printf("\nThe record is sucessfully deleted");
               printf("\nDelete another record?(Y/N)");
               getchar();
               if(getchar()=='n'){
                   updateDeleteInfo();
                }
               else{
                   deleteSeatPlan();
                }
          }
          else{
           updateDeleteInfo();
        }
     }
}

void deleteTeacInfo(){
        int room;
        char date[15];
        float time;
        int flag = 0;
        system("clear");
        printf("\t ->Room No: ");
        scanf("%d",&room);
        printf("\n\t ->Enter Date: ");
        scanf("%s",&date);
        printf("\t ->Time: ");
        scanf("%f",&time);
        ft=fopen("teacher.dat","rb+");
        rewind(ft);
        while(fread(&t1,sizeof(t1),1,ft)==1)
        {
              if((room == t1.roomNumber) && (time == t1.time) && (strcmp(date,t1.date)==0)){
                     system("clear");
                     printf("\t\Schedule is Availabe\t\n");
                     printf("\n\t-> Date: %s\t",t1.date);
                     printf("\n\t-> Room Number: %d\t",t1.roomNumber);
                     printf("\n\t-> Duty Time: %.2f %s\t",t1.time,t1.zone);
                     printf("\n\t-> Invigilator Partner: %s\t",t1.ini2);
                     printf("\n\t-> Invigilator Partner: %s\t",t1.ini1);
                     printf("\n\t-> Total Student: %d\t",t1.totalStud);
                     flag = 1;
               }
         }
        if(flag != 1)
        {
           printf("\n\tNo Schedule is found modify the search");
           printf("\n\tpress 'y' to goto UPDATE AND DELETE INFO");
           getchar();
           if(getchar()=='y'){
              updateDeleteInfo();
           }
        }
        if(flag == 1)
        {
           printf("\n\tDo you want to delete it?(Y/N):");
           getchar();
           if(getchar() =='y')
           {
             fd=fopen("test.dat","wb+");
             rewind(ft);
              while(fread(&t1,sizeof(t1),1,ft)==1)
             {
                if((room != t1.roomNumber) || (time != t1.time) || (strcmp(date,t1.date)!=0))
                {
                  fseek(fd,0,SEEK_CUR);
                  fwrite(&t1,sizeof(t1),1,fd);
                }
              }
               fclose(fd);
               fclose(ft);
               remove("routine.dat");
               rename("test.dat","teacher.dat");
               ft=fopen("teacher.dat","rb+");
               printf("\nThe record is sucessfully deleted");
               printf("\nDelete another record?(Y/N)");
               getchar();
               if(getchar()=='n'){
                   updateDeleteInfo();
                }
               else{
                   deleteTeacInfo();
                }
          }
          else{
           updateDeleteInfo();
        }
     }
}

void editRoutine(){
        int d;
        char c[20];
        int flag = 0;
        system("clear");
        printf("\t ->Enter the Batch: ");
        scanf("%d",&d);
        printf("\n\t ->Enter Exam date: ");
        scanf("%s",&c);
        fr=fopen("routine.dat","rb+");
        //rewind(fr);
        system("clear");
        while(fread(&r1,sizeof(r1),1,fr)==1)
        {
              if((r1.batch == d) && (strcmp(c,r1.date) == 0))
               {
                 printf("\n\tSchedule is Available for Batch %d and Course Code %s is available", d, r1.examName);
                 printf("\n\tEnter New Date: ");scanf("%s",r1.date);
                 printf("\n\tEnter New Course Code: ");scanf("%s",r1.examName);
                 printf("\n\tEnter New Time: ");scanf("%f",r1.time);
                 printf("\n\tEnter New AM/PM: ");scanf("%s",r1.zone);
                 printf("\nThe record is modified");
                 fseek(fr,ftell(fr)-sizeof(r1),0);
                 fwrite(&r1,sizeof(r1),1,fr);
                 fclose(fr);
                 flag = 1;
                 printf("\nThe record is sucessfully Modified");
                 printf("\nModify another record?(Y/N)");
                 getchar();
                 if(getchar()=='n'){
                  updateDeleteInfo();
                 }
                 else{
                  editRoutine();
                 }
               }
         }
        if(flag != 1)
        {
           printf("\n\tNo schedule is found modify the search");
           printf("\n\tpress 'y' to goto UPDATE AND DELETE INFO");
           getchar();
           if(getchar()=='y'){
              updateDeleteInfo();
           }
        }

}

void creatorsInfo(){
   system("clear");
   printf("\tZahir Hossain Dipto \t\t\t\t BIO\n");
   printf("\tID: 222-35-1144\n");
   printf("\tStudent \t\t\t\t \"I Hate Myself -_-\"\n");
   printf("\tDepartment of Software Engineering\n");
   printf("\tDaffodil International University\n");

   printf("\n\n\n\n");

   printf("\tTahmid Shah Tamim \t\t\t\t BIO\n");
   printf("\tID: 222-35-1141\n");
   printf("\tStudent \t\t\t\t\"I'am a former child Journalist\"\n");
   printf("\tDepartment of Software Engineering\n");
   printf("\tDaffodil International University\n");

   printf("\n\n\n\t\tThanks for using our system");
   printf("\n\t\tGoto MAIN MENU?(Y/N)");
   getchar();
   if(getchar()=='y'){
    main();
    }
   else{
    creatorsInfo();
    }

}
