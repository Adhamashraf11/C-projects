/*
 *  Name        : Clinic_Management_System.c
 *  Created on  : aug 27, 2023
 *  Description : this file contains the grogramming of Clinic Management System
 *  Version     : v1.0
 *  Author      : Adham
 */

#include "Clinic_Management_System.h"

                 /*      globle varible intilize  section           */
unsigned int Available_Slots = 5 ;    // No.available slots
unsigned int arr[5] = {1,2,3,4,5};  //array of available slots
struct st_Patient_Record *List_Head = NULL;



/*********************************** choose between admin mode and user mode ***********************************/
/*
	 Name        : Select_Mode
	 Returns     : void
	 Arguments   : void
	 brief       : Select between two modes Admin / User
*/
void Select_Mode(void)
{
    unsigned char userpassindex , Mode , done_mode = 0, counter = 0,x , flag = 0;
    int  trials = 0 ;
    printf("---------------------------------------------------------------------------------------------------------------\n\n");
    printf("**********                    Welcome To Clinic Management System                     **********\n\n");
    printf("---------------------------------------------------------------------------------------------------------------\n");

    printf("For Admin Mode press   : 1\n");
    printf("For User  Mode press   : 2\n");
    printf("Exit from Select Mode  : 3 \n\n\n");
    printf("Please Choise Your Mode ( 1 - 2 - 3 ) :  ");


        while ( counter < 3 )
        {
            scanf("%d",&Mode);
            printf("\n");
            printf("waiting");
                for ( userpassindex=0 ; userpassindex<15 ; userpassindex++ )
                {
                    printf(".");
                    Sleep(100);
                }
            printf("\n\n\n");
            switch(Mode)
            {
                case 1 :
                    Admin_Mode();// Call The Admin Mode Function
                    done_mode = 1 ;
                     break;
                case 2 :
                    User_Mode();// Call The User Mode Function
                     break;
                     done_mode = 1 ;
                case 3 :
                    flag = 1 ;   // Return to main program 
                    break;
                default :
                    counter ++ ;
                    printf("Invalid Choice                       \n");
                    printf("Please Choose The Right Mode ( 1 - 2 - 3 ) : ");
                     break;
            }

             if ( 1 == flag ){ break ; }

            if (1 == done_mode ){break;} /*when mode finish massion and wanna to exit */
        }
        if ( 3 == counter  )
        {
            printf("\n-------------------------------------------------\n");
            printf(" You have exceeded the maximum number of attempts .  \n");
            printf(" Please try agian after minute (60)");
            for (userpassindex=0;userpassindex<60;userpassindex++)
            {
                printf(".");
                Sleep(10);
            }
                printf("\n");
                printf("**********************************************\n");
                printf("\n");
                printf("IF You Wanna To Continue (1) ==> ");
                scanf("%d",&x);
                printf("\n");
            if( 1 == x ){Select_Mode();}
        }

}

/***************************************** In the user mode *****************************************/
    /*
     * In the user mode
     * There is no password. The system allows the following features:
     * 1. View patient record.
     *    By entering the patient ID, the system shall show the basic information for the patient.
     * 2. View today's reservations.
     *    In this view, the system shall print all reservations with the patient ID attached to each reservation slot.
     */
/*
	 Name        : User_Mode
	 Returns     : void
	 Arguments   : void
	 brief       : User Mode with options
*/
void User_Mode  (void)
{
    unsigned char features  ;
    printf("---------------------------------------------------------------------------------------------------------------\n\n");
    printf("**********                             User Mode Page                             **********\n");
    printf("---------------------------------------------------------------------------------------------------------------\n");


    /* The system allows the following features => Enter The Required Choice */
        printf(" 1- View Patient recording         \n");
        printf(" 2- View Today's Reservations      \n");
        printf(" 3- Return To The Select Mode Page \n");
        printf("-----------------------------------------\n");
    while (1)
    {
        printf("Please Select Number Your Choice ( 1 - 2 - 3 ) : ");
        scanf("%d",&features);
        printf("\n");
        switch (features)
            {
                case 1 :
                    View_Patient_Record();// Call The patient record
                     break;
                case 2 :
                    View_Reservations();// Call The today's reservations
                     break;
                case 3 :
                    Select_Mode();// Return to selection mode
                     break;
                default :
                    printf(" Invalid Choice  \n");
                    printf(" Please Choose The Right features \n");
                    printf("-----------------------------------------\n");
            }
    }
}

/***************************************** In the admin mode *****************************************/
    /*
     * In admin mode
     * The system asks for password, the default password is 1234. The system allows 3 trails for the password
     * entry, if the entered password was incorrect for 3 consecutive times, the system shall close. After login
     * in the admin mode, the system shall provide the following features:
     * 1. Add new patient record:
     *    To add a new patient, the user shall admin shall enter these basic information: name, age, gender and
     *    ID. The ID shall be unique for the user, if the entered ID is already exists, the system shall reject the entry.
     * 2. Edit patient record
     *    By entering patient ID the system shall checks if the ID exists, the system shall allow the user to edit the
     *    patient information. If not, the system shall display incorrect ID message.
     * 3. Reserve a slot with the doctor
     *    By default there are 5 available slots, 2pm to 2:30pm, 2:30pm to 3pm, 3pm to 3:30pm, 4pm to 4:30pm
     *    and 4:30pm to 5pm. Upon opening of this window, the system shall display the available slots. The
     *    admin shall enter the patient ID and the desired slot. The reserved slot shall not appear again in the next
     *    patient reservation.
     * 4. Cancel reservation.
     *    The admin can cancel a reservation by entering the patient ID.
     *    This reservation shall be shown again in the available slots window.
     */
/*
	 Name        : Admin_Mode
	 Returns     : void
	 Arguments   : void
	 brief       : Admin Mode with options
*/
void Admin_Mode (void)
{
    unsigned char features ;
    printf("---------------------------------------------------------------------------------------------------------------\n\n");
    printf("**********                             Admin Mode Page                             **********\n\n");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    unsigned char Check_PassWord = PassWord ();
    if ( Check_PassWord == 0 )
    {
    /* The system allows the following features => Enter The Required Choice */
        printf(" 1- Add new patient record         \n");
        printf(" 2- Edit patient record            \n");
        printf(" 3- Reserve a slot with the doctor \n");
        printf(" 4- Cancel reservation             \n");
        printf(" 5- Return To The Select Mode Page \n");
        printf("-----------------------------------------\n");

        while (1)
        {
            printf("Please Select Number Your Choice ( 1 - 2 - 3 - 4 - 5 ) : ");
            scanf("%d",&features);
            printf("\n");
            switch (features)
            {
                case 1 :
                    Add_New_Patient_Record();// Call The patient record
                     break;
                case 2 :
                     Edit_Patient_Record();// Call The today's reservations
                     break;
                case 3 :
                     Reserve_Slot_with_Doctor();// Return to selection mode
                     break;
                case 4 :
                     Cancel_Reservation();// Return to selection mode
                     break;
                case 5 :
                    Select_Mode();// Return to selection mode
                     break;
                default :
                    printf(" Invalid Choice  \n");
                    printf(" Please Choose The Right features \n");
            }
        }
    }
    else // ( Check_PassWord == 1 )
    {
        printf("Excpected Error 'From password' !!!\n"); 
    }
    
}
/*
	 Name        : Admin_Mode
	 Returns     : unsigned char
	 Arguments   : void
	 brief       : Admin Mode with options
*/
unsigned char PassWord (void)
{
    unsigned int  pass = PASSWORD ;
    unsigned int  userpass ;
    unsigned char userpassindex , flag=0 , trials=0 ;

    while (trials < 3)
    {
        printf("\n");
        printf("please enter the password : ");
        scanf("%d",&userpass);
        printf("\n");
        printf("waiting");

        for ( userpassindex=0 ; userpassindex<15 ; userpassindex++ )
        {
            printf(".");
            Sleep(150);
        }
        printf("\n");

        if ( userpass == pass  )
        {
            flag = 0 ;
        }
        else
        {
            flag = 1;
            printf("wrong password !!!\n");
        }

        if (flag == 1)
        {
             if (trials <2)
            {
               flag = 0;
            }
            trials ++ ;
        }
        else
        {
            printf("\n");
            printf("\n");
            printf("               Welcome To Admin Page   ");
            printf("\n \n \n");
             break;
        }


    }
    return flag ;
}

/*
	 Name        : Add_New_Patient_Record
	 Returns     : void
	 Arguments   : void
	 brief       :Add New Patient
*/
/*add new node in linkedlist by using Insert_Node_At_End */
void Add_New_Patient_Record  (void)
{
     /* Create New Node Containing The New Patient Informations */
    struct st_Patient_Record *Temp_Node = (struct st_Patient_Record*) malloc(sizeof(struct st_Patient_Record));

    if ( Temp_Node != NULL)
    {
        /* Scanning The Patient Informations From The Admin */   /*     node ==>   data   next     */
        printf("  Please Enter The Patient Informations \n");
        printf("=========================================\n");
        printf("\nPatient ID     : ");
        scanf("%d",&Temp_Node->id);    fflush(stdin);
        printf("\nPatient Name   : "); 
        scanf("%s",&Temp_Node->name);  fflush(stdin);
        printf("\nPatient Age    : ");
        scanf("%d",&Temp_Node->age);   fflush(stdin);
        printf("\nPatient Gender : "); //(Male - Female)
        scanf("%s",&Temp_Node->gender);fflush(stdin);
        printf("-----------------------------------------\n");

        /* Set The Intitial Value Of The Next Of The New Link Node To NULL */
        Temp_Node->next = NULL;
        if(List_Head == NULL)
        { /*If Head Pointer NULL And There Is No Linked List So Create A New Node In The Linked List */
            List_Head = Temp_Node;
        }
        else //head != NULL
        {
            struct st_Patient_Record *Last_Node , *Last_Node_Temp ;
            Last_Node = Last_Node_Temp = List_Head ; // first address in data base
            /*Check If the Input ID Is Already Exist Or Not And If it Exists Enter A New ID */
            while(Last_Node_Temp != NULL)   // Head --> Node1 --> Node2 --> Node3 --> Node4 --> Node5 --> NULL
            {
                if(Temp_Node->id == Last_Node_Temp->id)
                {
                    printf("\nThis ID already exists.\nPlease Enter New ID : ");
                    scanf("%d",&Temp_Node->id);

                    Last_Node_Temp = List_Head;
                }
                Last_Node = Last_Node_Temp ;
                Last_Node_Temp = Last_Node_Temp->next ;
            }
            Last_Node->next = Temp_Node ;
        }
    }
    else
    {
        printf("Sorry There Are No Available space \n");
    }
}

/*
	 Name        : Edit_Patient_Record
	 Returns     : void
	 Arguments   : void
	 brief       : Edit information of Patient 
*/
void Edit_Patient_Record(void)
{
    /*Local Pointer To Move Nodes and Search The Right ID Of The Patient To Edit Informations */
    struct st_Patient_Record *Search = List_Head;
    unsigned int ID , flag = 0 ;
    if ( List_Head == NULL )
    {
        printf(" There is No Patient to Edit \n Please Return and Add New Patient \n\n");
    }
    else
    {
        printf("\nPlease Enter the ID of the patient that you want to change Information : ");
        scanf("%d",&ID);fflush(stdin);
         /* Search For The Patient ID wanna To Edit Informations */
        while(Search != NULL)
        {
             if(ID == Search->id)
             {
            flag = 1 ;
                printf("\nPlease Enter the New Patient Name   : ");
                scanf("%s",&Search->name);   fflush(stdin);
                printf("\nPlease Enter the New patient age    : ");
                scanf("%d",&Search->age);    fflush(stdin);
                printf("\nPlease Enter the New patient gender : ");
                scanf("%s",&Search->gender); fflush(stdin);
                printf("\n---------------------------------------\n");
            break;
             }
        Search = Search->next; // to search in all nodes
        }
    /* If You Didn't Find The Patient ID Print A message For The User To Re Enter The Right ID */
        if ( 0 == flag)
        {
        printf("                           Invalid ID   !!!!!!!!!                 \n");
        printf("Didn't Find The Patient ID ..\n try agian or insert a new patient \n");
        printf("------------------------------------------------------------------\n");
        }
        else {/*flag = 1 no problem*/}
    } 
}
/*
	 Name        : Reserve_Slot_with_Doctor
	 Returns     : void
	 Arguments   : void
	 brief       : Reserve with Doctor
*/
void Reserve_Slot_with_Doctor(void)
{
    /*Local Pointer To Move  Nodes And Check The ID Until Finding The Requred Patient To Reserve A Slot For The Required Patient */
    struct st_Patient_Record *Ptr_Reserve;
    unsigned int Count_Slot , ID , Index_arry = 0 ;
    Ptr_Reserve = List_Head;

    /*Check if there is linked list with patients data or not */
    if(Ptr_Reserve == NULL)
    {
        printf("There are no patients In The Database \n");
    }
    else
    {
        printf("Please Enter The Patient ID That You Want To Make a Reservation : ");
        scanf("%d",&ID);fflush(stdin);
        printf("\n");
        /* Move The Ptr On All the Node Until You Find The Required Patient ID*/
        while(Ptr_Reserve!= NULL)
        {
            /*If You Find The Required Patient ID Then Print All The Availible Slots Timings */
            if(ID == Ptr_Reserve->id)
            {
                for( Count_Slot = 1 ; Count_Slot <= NO_OF_SLOTS ; Count_Slot++  ) // NO_OF_SLOTS = 5
                {
                    switch(arr[Index_arry]) 
                    {
                    case 1 :
                        printf("1- From 2:00 PM To 2:30 PM \n");
                        break;

                    case 2 :
                        printf("2- From 2:30 PM To 3:00 PM \n");
                        break;

                    case 3 :
                        printf("3- From 3:00 PM To 3:30 PM \n");
                        break;

                    case 4 :
                        printf("4- From 4:00 PM To 4:30 PM \n");
                        break;

                    case 5 :
                        printf("5- From 4:30 PM To 5:00 PM \n");
                        break;
                    }
                     Index_arry++;
                }
                /* Choose The Slot That You Want To Reserve And Delete from The Reservations */
                printf("Please Select The Slot That You Want To Reserve : ");
                scanf("%d",&Ptr_Reserve->slot);
                arr[Ptr_Reserve->slot-1] = 0;
                Available_Slots --; // Available_Slots => 5 - 4 -3 - 2 - 1 - 0 ; 
                return;
            }
            else
            {
                Ptr_Reserve = Ptr_Reserve->next ; // move in all nodes
            }
        }
        /* If The Admin Entered Wrong ID Print A Message To Re Enter The Right ID */
        printf("Incorrect ID Please Re Enter The Right ID : \n");
    }
}
/*
	 Name        : Cancel_Reservation
	 Returns     : void
	 Arguments   : void
	 brief       : Cancel the Reservation
*/

void Cancel_Reservation(void)
{
    struct st_Patient_Record *Ptr_Reservation;
    unsigned int ID;
    Ptr_Reservation = List_Head;
    /* Check If There Is Patient Informations In The Database Or Not If Not Print This Message For The Admin */
    if(Ptr_Reservation == NULL)
    {
        printf("There are no patients In The Database \n");
    }
    else     /* Ask The Admin To Enter The ID Of The Patient That Want To Cancel A Reservation   */
    {
        printf("Please Enter The Patient ID That you want to Cancel The Reservation : ");
        scanf("%d",&ID);
        while(Ptr_Reservation!= NULL)
        { /*Delete slot of list */
            if(Ptr_Reservation->id == ID)
            {
                arr[Ptr_Reservation->slot-1] = Ptr_Reservation->slot;
                Available_Slots++;
                return;
            }
            else
            {
                /* Set The Pointer To The Following Node To Check For The ID Till You Find */
                Ptr_Reservation = Ptr_Reservation->next;
            }
        }
        /*If Entered Wrong ID  */
        printf(" Incorrect ID Please Enter The Right ID :\n");
    }
}


/*
	 Name        : View_Patient_Record
	 Returns     : void
	 Arguments   : void
	 brief       : View information of Patient
*/

void View_Patient_Record(void)
{   /* Create A Pointer To Move On All The Patients Nodes To Print Every Patient Node Informations*/
    struct st_Patient_Record *View;
    unsigned int ID;
    View = List_Head;
    if(View == NULL)
    {
        /* Check If There Is Patients Informations In The Database Or Not If Not Print This Message For The User */
        printf("There are no patients.\n");
    }
    else
    {
        printf("Enter patient ID : ");
        scanf("%d",&ID);
        /*Make A Loop On All The Nodes And Print Every Patient Informations */
        while(View!= NULL)
        {
            if(ID == View->id)
            {
                printf("\nPatient Name   : %s",View->name);
                printf("\nPatient Gender : %s",View->gender);
                printf("\nPatient Age    : %d",View->age);
                printf("\nPatient ID     : %d",View->id);
                printf("\n-----------------------------------------\n");
                return;
            }
            else
            {
                View = View->next; // to search in all nodes
            }
        }
        printf("\nIncorrect ID Please Enter The Right ID : \n");
    }

}

/*
	 Name        : View_Reservations
	 Returns     : void
	 Arguments   : void
	 brief       : View information of Reservations
*/
void View_Reservations(void)
{
    /* Create A Pointer To Move On All The Patients Nodes To Print All The Patients Reservations  */
    struct st_Patient_Record *View_Reservations;
    unsigned int slot;
    View_Reservations = List_Head;
    if(View_Reservations == NULL)
    {
        /* Check If There Is Patients Informations In The Database Or Not If Not Print This Message For The User */
        printf("\nThere are no patients.\n");
    }
    else
    {
        while(View_Reservations != NULL)
        {
            switch(View_Reservations->slot)
            {
            case 1 :
                printf("ID : %d is reserve in 2:00 PM : 2:30 PM.\n",View_Reservations->id);
                break;
            case 2 :
                printf("ID : %d is reserve in 2:30 PM : 3:00 PM.\n",View_Reservations->id);
                break;
            case 3 :
                printf("ID : %d is reserve in 3:00 PM : 3:30 PM.\n",View_Reservations->id);
                break;
            case 4 :
                printf("ID : %d is reserve in 4:00 PM : 4:30 PM.\n",View_Reservations->id);
                break;
            case 5 :
                printf("ID : %d is reserve in 4:30 PM : 5:00 PM.\n",View_Reservations->id);
                break;
            default :
                break;
            }
            View_Reservations = View_Reservations->next;
        }
    }
}










