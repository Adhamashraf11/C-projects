/**
 * 
 * summy of file that make data_base.txt file to write/read data like jason.json file 
 * by using   <string.h>    FILE   fopen    fgets   fclose 
*/

/***********          project work without it , we will use in version 2       ***************/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct  st_Patient_Record
{
    unsigned char name   [31]      ;
    unsigned char gender [10]      ;
    unsigned int  id               ;
    unsigned int  slot             ;
    unsigned char age              ;
    struct st_Patient_Record *next ;
}st_Patient_Record;


#define PATIENT_ID_SIZE       (  8 )
#define PATIENT_NAME_SIZE     ( 30 )
#define PATIENT_AGE_SIZE      (  2 )
#define PATIENT_GENDER_SIZE   (  6 )

#define PATIENT_ID_INFO_START_INDEX            (  9 )
#define PATIENT_NAME_INFO_START_INDEX          ( 32 )
#define PATIENT_AGE_SIZE_INFO_START_INDEX      ( 75 )
#define PATIENT_GENDER_SIZE_INFO_START_INDEX   ( 93 )

#define PATIENT_CAL_START_INDEX(Patient_Arr , Start_Index) (Patient_Arr + Start_Index)

#define PATIENT_ID_INDEX_POS     (PATIENT_CAL_START_INDEX(read_patient_data , PATIENT_ID_INFO_START_INDEX))
#define PATIENT_NAME_INDEX_POS   (PATIENT_CAL_START_INDEX(read_patient_data , PATIENT_NAME_INFO_START_INDEX))
#define PATIENT_AGE_INDEX_POS    (PATIENT_CAL_START_INDEX(read_patient_data , PATIENT_AGE_SIZE_INFO_START_INDEX))
#define PATIENT_GENDER_INDEX_POS (PATIENT_CAL_START_INDEX(read_patient_data , PATIENT_GENDER_SIZE_INFO_START_INDEX))

FILE *my_file = NULL ;

st_Patient_Record patient ;

unsigned char read_patient_data [105] ;


void featch_student_data (st_Patient_Record *ptr_patient , unsigned char *patient_data);
void print_infro_student (st_Patient_Record *ptr_patient                              );
void Func_Write_Data     (st_Patient_Record *ptr_patient );
int main()
{
    unsigned char flag , counter = 0 ,ret;
    
    my_file = fopen("Data_Base.txt","r");
    if ( NULL != my_file)
    {
       for (counter=0 ; counter<(5+3);counter++)
       {
          fgets(read_patient_data , 105 , my_file);
            if ( counter==0 || counter==1 || counter==2 || counter==3 )
            {
                continue;
            }
          featch_student_data(&patient,read_patient_data); // store in struct from array

       }
        print_infro_student (&patient);

    }
    else
    {
        printf("Error !! \n");
    }
     Func_Write_Data     (&patient);

    flag = fclose(my_file);
    if ( 0 == flag )
    {
      //  printf("file secuss to close \n");
    }
    else
    {
        printf("ERROR file can't close \n");
    }
    printf("Hello world!\n");
    return 0;
}


void featch_student_data (st_Patient_Record *ptr_patient , unsigned char *patient_data)
{
    unsigned char patient_id_str     [9]  = {0}; /*Arry store id as string*/
    unsigned char patient_name_str   [31] = {0}; /*Arry store id as string*/
    unsigned char patient_age_str    [3]  = {0}; /*Arry store id as string*/
    unsigned char patient_gender_str [10] = {0}; /*Arry store id as string*/



    strncpy(patient_id_str     ,  PATIENT_ID_INDEX_POS    , PATIENT_ID_SIZE);
    printf("id     => %s \n",patient_id_str);
    strncpy(patient_name_str   ,  PATIENT_NAME_INDEX_POS  , PATIENT_NAME_SIZE);
    printf("name   => %s \n",patient_name_str);
    strncpy(patient_age_str    , PATIENT_AGE_INDEX_POS   , PATIENT_AGE_SIZE);
    printf("age    => %s \n",patient_age_str);
    strncpy(patient_gender_str , PATIENT_GENDER_INDEX_POS , PATIENT_GENDER_SIZE);
    printf("gender => %s \n",patient_gender_str);

    ptr_patient->id     = (unsigned int )atoi(patient_id_str);
    ptr_patient->age    = (unsigned char)atoi(patient_age_str);
    strncpy(ptr_patient->name   , patient_name_str   , 30);
    strncpy(ptr_patient->gender , patient_gender_str , 10);

    printf("--------------------------------\n");



}
void print_infro_student (st_Patient_Record *ptr_patient)
{
    printf("==============================\n");
    printf("Patient ID     : %i   \n",ptr_patient->id     );
    printf("Patient NAME   : %s   \n",ptr_patient->name   );
    printf("Patient AGE    : %i   \n",ptr_patient->age    );
    printf("Patient GENDER : %s   \n",ptr_patient->gender );
    printf("==============================\n");
}


void Func_Write_Data (st_Patient_Record *ptr_patient )
{
    unsigned char flag = 0, counter = 0,ret;
    my_file = fopen("Data_Base.txt","w");
    if ( NULL != my_file)
    {
        printf("File has been created \n ");
        for (counter=1 ; counter<=1 ; counter++)
        {
            printf("\nplease enter the ID     : ");
            scanf("%i",&patient.id);fflush(stdin);
            printf("\nplease enter the AGE    : ");
            scanf("%i",&patient.age);fflush(stdin);
            printf("\nplease enter the Name   : ");
            gets(patient.name);fflush(stdin);
            printf("\nplease enter the gender : ");
            gets(patient.gender);fflush(stdin);
        ret=fprintf(my_file,"\nID     : &i  -   Name   : %s  -   Age    : %i   -   gender : %s   \n----------------------------------\n "
                           , patient.id   , patient.name  , patient.age ,patient.gender );fflush(stdin);
        printf("ret = %d \n",ret);
        }

    }
    else
    {
        printf("Error !! \n");
    }
     flag = fclose(my_file);
    if ( 0 == flag )
    {
        printf("file secuss to close \n");
    }
    else
    {
        printf("ERROR file can't close \n");
    }
}
