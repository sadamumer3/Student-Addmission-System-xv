 
#include <conio.h> 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>


/* 
char* timings[n of data][n of columns] = 
[
    'sNo','startTime','limit'
];
*/
int timings[][3] = 
{ 
    { 1, 01, 400 },
    { 2, 02, 400 },
    { 3, 03, 400 },
    { 4, 04, 400 },
    { 5, 05, 400 }	 	
};

// duration of exam in hours
int duration = 01;

/* 
int rooms[n of data][n of columns] = 
[
    'sNo','roomNo','facultyId'
];
*/
int room[][3] = 
{ 
    { 1, 1001, 1 },
    { 2, 1002, 2 },
    { 3, 1003, 3 },
    { 4, 1004, 4 },	
    { 5, 1004, 5 },	
};

/* 
char* invigilator[n of data][n of columns] = 
[
    'sNo','invigilator','facultyId'
];
*/
char* invigilator[200][3]= 
{ 
    {"1","Sir Imtiaz Sheikh","1"},
    {"2","Sir Saad latif","2"},
    {"3","Sir Naseem Zulfikar","3"},
    {"4","Sir Saif ur rehman","4"},
    {"5","Sir Sadam Umer","5"},
    {"6","Sir Naeed Balooch","6"}
 }; 


/*
char* faculty[n of data][n of columns] = 
[
    'sNo','name'
];
*/
char* faculty[200][2]= 
{ 
    {"1","Software Engineering"}, 
    {"2","Computer Science"}, 
    {"3","Aritifical Intelligence"},
    {"4","Environmental Science"},
    {"5","Media Science"},
    {"6","Cyber Security"},
 }; 

// csv file name
char csvFileName[50] = "studentsData.csv";


// number of maximum students
#define MAX_STUDENTS 2000;

int maxStudents = MAX_STUDENTS;

int ids[2000];
char names[2000][100];
char fathers[2000][100];
char passwords[2000][100];
int facultsId[2000];
long long int cnics[2000];

// last Sno in csv file
int lastId = 0;


// to get next index in students array
int getCrrentIndex()
{
    int i =0;       
    int j = 0;

 for(int i=0;i<maxStudents;i++)
    {
        if(ids[i]!=0)
        {
            j = j+1;
        }
    }
    return j+1;
}

void red () {
  printf("\033[1;31m");
}
void green () {
  printf("\033[1;32m");
}
void reset () {
  printf("\033[0m");
}

// to assign time to students if limit>0
int availTiming()
{
    for(int i=0;i<maxStudents;i++)
    {
          printf("\n");

        if(timings[i][0]==NULL)
        {
            continue;
        }
        else
        {
            // if limit>0 --> assign and break loop
            if(timings[i][2]>0)
            {
            	timings[i][2]= timings[i][2]-1;
            	
               return i;

               break;

            }
        }
    }
}

// to print single student
void tableStudent(int id)
{

        int sNo = ids[id];


        char studentName[50]; 
    sprintf(studentName, "%s", names[id]);

        char fatherName[50];
    sprintf(fatherName, "%s", fathers[id]);

        long long int cnic= cnics[id];

        char password[50]; 
    sprintf(password, "%s",passwords[id]);
       

        char facultyName[50]; 

    sprintf(facultyName, "%s",faculty[(facultsId[id]-1)][1] );


    // int timing_id = facultsId[id];

    char invigilatorName[50]; 
    sprintf(invigilatorName, "%s",invigilator[(facultsId[id]-1)][1] );


     int roomNo = room[(facultsId[id]-1)][1] ; 
    // sprintf(roomNo, "%d",room[(facultsId[id]-1)][1] );

        printf("%d \t %s \t\t %s \t\t %s \t %s \t %lld \t %s \t %d",sNo,studentName,fatherName,password,facultyName,cnic,invigilatorName,roomNo);

}

// to print all students
void viewStudent()
{
	
    printf("S.no \t Student Name \t Father Name \t password \t Faculty \t Cnic \t Invigilator \t Room No");

    for(int i=0;i<maxStudents;i++)
    {
        if(ids[i]==0 )
        {
            continue;
        }
        else
        {
            int id = i;

        printf("\n");
        tableStudent(i);

        }
    }
        printf("\n");
}

void viewStuByCat()
{
    //  printf("S.no \t Student Name \t Father Name \t password \t Faculty \t Cnic \t Invigilator");

    int total_students = 1;

    for(int i=0;i<200;i++)
    {
        // USELESS CONDITION
        if(i==1000)
        {
              continue;
        }
        else
        {
            int temp = atoi( faculty[i][0] ) ;

            // printf("\n %s \n",faculty[i][0]);
            int last_Id = 0;

            for(int j=0;j<maxStudents;j++)
                {
                    if(facultsId[j]==0 )
                    {
                        continue;

                    }
                    else
                    {

                        if(facultsId[j]==temp)
                        {

                           int id = j;
                           int facultyId = facultsId[id] -1;

                            char facultyName[50]; 
                            sprintf(facultyName, "%s",faculty[facultyId][1] );
                            // printf("\n %s: \n",facultyName);

                            
                            if (last_Id!=facultsId[id])
                            {
                                printf("\n");
                                printf("%s: \n",facultyName);
                            }

                            last_Id = temp;
                            


                                int sNo = ids[id];

                                char studentName[50]; 
                            sprintf(studentName, "%s", names[id]);

                                char fatherName[50];
                            sprintf(fatherName, "%s", fathers[id]);

                                long long int cnic= cnics[id];

                                char password[50]; 
                            sprintf(password, "%s",passwords[id]);
                            
                            //     char facultyName[50]; 
                            // sprintf(facultyName, "%s",faculty[(facultsId[id]-1)][1] );


                            // int timing_id = facultsId[id];

                            char invigilatorName[50]; 
                            sprintf(invigilatorName, "%s",invigilator[(facultsId[id]-1)][1] );


                            int roomNo = room[(facultsId[id]-1)][1] ; 


                                // printf("%d \t %s \t\t %s \t\t %s  ",sNo,studentName,fatherName,password);

  //printf("name\t fname\tcnic\tpassword\tinvigilatorname\troomno");

                                printf(" \n");
                               // printf(" %d)",total_students); 
                                total_students = total_students + 1;
                                printf("Name : %s,",studentName);
                                printf(" Father Name : %s,",fatherName);
                                printf(" Cnic : %lld,",cnic);
                                printf(" Password : %s,",password);
                                // printf(" Faculty: %s \n",facultyName);
                                printf(" Invigilator : %s,",invigilatorName);
                                printf(" Room NO. : %d",roomNo);
                                printf(" \n");
                                // tableStudent(j);
                        }

                    }
                }

        }
    }
        printf("\n");

}
// to print all students
void viewStuByCatX()
{
	
    printf("S.no \t Student Name \t Father Name  \t Cnic \t Faculty \t password");

    int faculties[200];


    for(int i=0;i<maxStudents;i++)
    {
        if(ids[i]==0 )
        {
            continue;
        }
        else
        {

        

            int id = i;
            int facultyId = facultsId[id];

            int index = 0;
            int isFound = 0;
            for(int j=0;j<maxStudents;j++)
            {
                printf("\n %d",j);
                if(faculties[j]!=NULL)
                {
                
                    if(faculties[j]!=facultyId)
                    {
                        // faculties[j] = facultyId;
                        isFound = 0;
                        continue;
                    }
                    else if(faculties[j]==facultyId)
                    {
                        isFound = 1;
                        break;
                    }

                    index = j;
                }
                
            }

            if(isFound==0)
            {
                faculties[index] = facultyId;


             int sNo = ids[id];

            char studentName[50]; 
        sprintf(studentName, "%s", names[id]);

            char fatherName[50];
        sprintf(fatherName, "%s", fathers[id]);

            long long int cnic= cnics[id];

            char password[50]; 
        sprintf(password, "%s",passwords[id]);
        

            char facultyName[50]; 

        sprintf(facultyName, "%s",faculty[(facultyId-1)][1] );


        printf(" %s \n",facultyName);
        printf("%d \t %s \t\t %s \t\t %lld \t\t %s \t %s ",sNo,studentName,fatherName,cnic,password,facultyName);


            }
            
            
    

        }
    }
        printf("\n");
}

// to assign faculty to student
int selectFaculty()
{
    printf("\n\nSelect A Faculty:\n\n");

    for(int i=0;i<100;i++)
    {
        if(faculty[i][0]==NULL)
        {
            continue;
        }
        else
        {  
            printf(" (%s) %s \n",faculty[i][0],faculty[i][1]);
        }
    }

    char input[50];
    printf("\n\nEnter Your Choice:");
    scanf("%s",&input);

    int isValid = 0;

    for(int i=0;i<100;i++)
    {
        if(faculty[i][0]==NULL)
        {
            continue;
        }
        else
        {
            if(strcmp(input,faculty[i][0])==0)
            {
                isValid = 1;
                break;
            }

        }
    }

    if(isValid==1)
    {
        // sprintf(faculty_id, "%s", input);
        char faculty_name[50];

        sprintf(faculty_name, "%s", faculty[atoi(input)-1][1]);

        printf("\n");
            green();
        printf("Faculty Selected: %s \n",faculty_name);
          reset();
        return atoi(input);


    }
    else
    {
        printf("\n");
        red();
        printf("Invalid Faculty Selected: %s \n",input);
            reset();
        printf("\n");
        selectFaculty();
    }
        // selectFaculty();
}

// to print admit card
void getAdmitCard(int id)
{

    // printf("\n %d",id);
    
         char sNo[50]; 
    sprintf(sNo, "%d", ids[id]);

        char studentName[50]; 
    sprintf(studentName, "%s", names[id]);

        char fatherName[50];
    sprintf(fatherName, "%s", fathers[id]);

        char password[50]; 
    sprintf(password, "%s",passwords[id]);
       
       long long int cnic= cnics[id]; 

        char facultyName[50]; 
    sprintf(facultyName, "%s",faculty[(facultsId[id])-1][1] );


   int timing = availTiming();

        char timingString[50]; 
    sprintf(timingString, "%d to %d",timings[timing][1],timings[timing][1]+duration);

    // int timing_id = timings[timing][0];

    // char invigilatorName[50]; 
    // sprintf(invigilatorName, "%s",invigilator[(timing_id)-1][1] );


     printf(" \n");
     printf(" Name: %s \n",studentName);
     printf(" Son of: %s \n",fatherName);
     printf(" Cnic: %lld \n",cnic);
     printf(" Faculty: %s \n",facultyName);
     printf(" Timing: %s \n",timingString);
    //  printf(" Invigilator: %s \n",invigilatorName);
     //printf(" Cnic: %d \n",cnic);
     printf(" \n");

    // tableStudent(id);
}

// to authenticate student
void auth()
{
	    printf("\n\n");
//	    printf("\t\t\t\t ADMIT CARD");
 green();
	    printf("=============================================================================== ADMIT CARD ================================================================================");
	    reset();
        printf("\n\n\nEnter your name:");
        char name[20];
        scanf("%s",name); 

        printf("\nEnter Password:");
        char password[20];
        scanf("%s",password);

    int isValid = 0;

    for(int i=0;i<maxStudents;i++)
        {
            if(ids[i]==NULL)
            {
                continue;
            }
            else
            {
                if(strcmp(names[i],name)==0 && strcmp(passwords[i],password)==0)
                {
                    // printf("found");
                    isValid = 1;
                    getAdmitCard(i);
                    break;
                }
            }
        }

        if(isValid==0)
        {
                red();
            printf("\n Could not find you in our database \n");
            reset();
			Sleep(1000);
            
        }
}


int read()
{
     // Substitute the full file path
    // for the string file_path
    FILE* fp = fopen(csvFileName, "r");
 

    if (!fp)
    {
        FILE* fp = fopen(csvFileName, "w");

        fprintf(fp, "Sno, Name, Father Name, Password, Faculty Id, Cnic \n"); 
        fclose(fp);
        
        read();
    }
    else {

        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;
  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
   
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
            // {
                continue;
            // }
            // else
            // {
  
            // Splitting the data
            char* value = strtok(buffer, ", ");
            
            while (value) {         //value==NULL;

                int id=row-2;     // once reading from file once from char arry that is way -2, id= is a location in your temp arry.

                // Column 0 = Sno
                if (column == 0)  
                {
                    ids[id] = atoi(value);
                    lastId = atoi(value);
                }

                // Column 1 = Name
                if (column == 1) 
                {
                    strcpy(names[id], value);
                }
  
                // Column 2 = Father Name
                if (column == 2) 
                {
                    strcpy(fathers[id], value);
                }
  
                // Column 3 = Password
                if (column == 3) 
                {
                    strcpy(passwords[id], value);
                }

                 // Column 4 = Faculty
                if (column == 4) 
                {
                    facultsId[id] = atoi(value);
                }
                 // Column 5 = cnic
                if (column == 5) 
                {
                    cnics[id] = atoll(value);
                }
  
                value = strtok(NULL, ", ");

                column++;
            }
            
//            printf("\n");
            // }
        }
  
        // Close the file
        fclose(fp);
    }

    return 0;
}


int write()
{
      // Substitute the file_path string
    // with full path of CSV file
    FILE* fp = fopen(csvFileName, "a+");
  
    char name[50],father_name[50],password[50];
    long long int cnic;
    
    if (!fp) {
        // Error in file opening
        printf("Can't open file\n");
        return 0;
    }
  
    // Asking user input for the
    // new record to be added


    /*
     use this to assign the last id according to number of records in csv file
     */
     int sno = getCrrentIndex();

    /*  
     use this to assign the last id according to the last sno in csv file
     */
//    int sno = lastId+1;

    printf("\n");
   // printf("\t\t\t\t ADMISSION FORM ENTRY PORTAL"); 
    green();
    printf("================================================================= ADMISSION FORM ENTRY PORTAL =============================================================================");         
            reset();         
             
    printf("\n\nEnter Your Name:");
    scanf("%s", &name); 
    
    printf("\nEnter Father Name:");
    scanf("%s", &father_name); 
    
    //printf("\nEnter Password \n");
    //scanf("%s", &password);
     
    printf("\nEnter Your Cnic Number:");
    scanf("%lld",&cnic);
    
     printf("\nEnter Password:");
    scanf("%s", &password);

    int faculty_id = selectFaculty();
  
    // Saving data in file
    fprintf(fp, "\n%d, %s, %s, %s, %d, %lld \n",sno, name, father_name, password, faculty_id, cnic); 
         
         green();
    printf("\nNew Account added to record");
          reset();
          
    fclose(fp);
    return 0;
}
 

// Our sacred main function 
 int main () 
{ 
    system("cls");
    read();
    
    
    

    printf("\n");

    
    
    printf("Select an Option\n");
    printf("1. Submit Form\t\n");
    printf("2. Admit Card\n");
    printf("3. student stored data\n");
    
     red();
    printf("4. Exit\n");
    reset();

    int choice;
    printf("\n\nEnter Your Choice:");
    scanf("%d",&choice);


	system("cls");
        
    if(choice==1)
    {
        write();        // for sign up
    }
    else if(choice==2)
    {
        auth();          // to get admit card
    }
    else if(choice==4)
    {
        printf("\n Exiting... \n");

        Sleep(2000);
        system("cls");

       green();
        printf("\n ___ Exit Successful ___ \n");
       reset();

        Sleep(1000);

        system("cls");
        exit(0);

    }else if(choice==3)
    {
    	printf("\n");
    //	printf("\t\t\t\t\t\t STUDENTS LIST");
    green();
    	printf("=================================================================================== STUDENTS LIST =========================================================================");
    	reset();
    	printf("\n");
        // viewStudent();
        viewStuByCat();
    }
    
    else
    {
        printf("Invalid Choice\n");
    }

    printf("\n\n Press any key to Return to Main Menu. \n");
    getch();

    main();
    
   return 0; 
}

//  g++ std-admsn-sys-xv.c -o std-admsn-sys-xv && std-admsn-sys-xv.exe
