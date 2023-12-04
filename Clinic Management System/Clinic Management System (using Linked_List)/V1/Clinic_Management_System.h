/*
 *  Name        : Clinic_Management_System.h
 *  Created on  : aug 27, 2023
 *  Description : this file contains the header file of Clinic Management System
 *  Version     : v1.0
 *  Author      : Adham
 */

 /* File Guard */
#ifndef CLINIC_MANAGEMENT_SYSTEM_H_
#define CLINIC_MANAGEMENT_SYSTEM_H_

                 /*      Include Section                     */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
//#include "STD_TYPES.h"

				 /*      Macros Defination Section           */
#define PASSWORD    ( 1234 )
#define DEBUDING_MODE
#define NO_OF_SLOTS 5
                 /*      User Defination Type Section        */

typedef struct  st_Patient_Record
{
    unsigned char name   [30]      ;
    unsigned char gender [10]      ;
    unsigned int  id               ;
    unsigned int  slot             ;
    unsigned char age              ;
    struct st_Patient_Record *next ;
}st_Patient_Record;

                 /*      Function Decleration Section        */

void Select_Mode(void);// beginning of the system it asks the user to choose between admin mode and user mode
///////////////////////////////////
void User_Mode          (void);
void View_Patient_Record(void);
void View_Reservations  (void);
///////////////////////////////////
unsigned char PassWord (void);
///////////////////////////////////
void Admin_Mode              (void);
void Add_New_Patient_Record  (void);
void Edit_Patient_Record     (void);
void Reserve_Slot_with_Doctor(void);
void Cancel_Reservation      (void);


#endif //CLINIC_MANAGEMENT_SYSTEM_H_





