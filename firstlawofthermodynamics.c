#include <stdio.h>
#include <stdlib.h>

struct system_body
{
    int *change_in_internal_energy;         // Pointer to the change in internal energy
    int *change_in_heat;                    // Pointer to the change in heat
    int *work_done;                         // Pointer to the work done
} default_system_body = {NULL, NULL, NULL}; // Initializing default values for the system body

typedef struct system_body system_body; // Creating a typedef for struct system_body

int findUnknownParameter(system_body body)
{
    // Checking if more than one parameter is missing
    int check = 0;
    if (body.change_in_heat == NULL) // If change_in_heat is not provided then value of check will increase
        check++;
    else if (body.change_in_internal_energy == NULL) // If change_in_internal_energy is not provided then value of check will increase
        check++;
    else if (body.work_done == NULL) // If work_done is not provided then value of check will increase
        check++;

    // If more than one parameter is missing value of check will become 2 or more & we will exit the program
    if (check >= 2)
    {
        printf("values cannot be found as only two or more parameters are missing");
        exit(1);
    }

    int result; // Declaring result variable to return with result later

    if (body.change_in_internal_energy == NULL) // If change_in_internal_energy is not provided
    {
        result = *(body.change_in_heat) + *(body.work_done); // Calculate the result by adding change_in_heat and work_done
    }
    else if (body.change_in_heat == NULL) // If change_in_heat is not provided
    {
        result = *(body.change_in_internal_energy) - *(body.work_done); // Calculate the result by subtracting work_done from change_in_internal_energy
    }
    else // If both change_in_internal_energy and change_in_heat are provided
    {
        result = *(body.change_in_internal_energy) - *(body.change_in_heat); // Calculate the result by subtracting change_in_heat from change_in_internal_energy
    }
    return result; // Return the calculated result
}

int main()
{
    int del_internal_energy = 34; // Define the change in internal energy
    int del_heat = 22;            // Define the change in heat

    system_body body_one = default_system_body;                // Create a system_body object and initialize it with default values
    body_one.change_in_heat = &del_heat;                       // Assign the address of del_heat to change_in_heat pointer
    body_one.change_in_internal_energy = &del_internal_energy; // Assign the address of del_internal_energy to change_in_internal_energy pointer

    printf("%d", findUnknownParameter(body_one)); // Call the findUnknownParameter function with body_one as argument and print the result

    return 0; // Return 0 to indicate successful execution of the program
}