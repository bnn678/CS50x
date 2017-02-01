#include <cs50.h>
#include <stdio.h>
#include <string.h>

string promptAndValidate(string fieldname);

int main(void)
{
    printf("Hello, thank you for signing up for: The United States\n");
    printf("I'll need to get some info from you please...\n\n");

    // TODO replace lines 14 - 44 with something much nicer

    // get first name and make sure it's valid
    string firstname = "";
    firstname = promptAndValidate( firstname );
    


    // get last name and make sure it's valid
    string lastname = "";
    while( strlen(lastname) < 2 ) 
    lastname = promptAndValidate( lastname );

    // get state and make sure it's valid
    string state = "";
    state = promptAndValidate( state );

    // get email and make sure it's valid
    string email = "";
    email = promptAndValidate( email );

    printf("\nGreat thanks, lemme just enter that into my system here...\n");
    printf("%s %s from %s, at %s\n", firstname, lastname, state, email);
    printf("Excellent! Please pay your taxes in April, or you'll be hearing from us (check your spam folder).\n");
}

string promptAndValidate(string fieldname)
{
    string answer = "";
    int minimumlength = 2;
    while( strlen(answer) < minimumlength ) 
    {
        printf("%s (must be at least %i characters long):\n", fieldname, minimumlength);
        answer = GetString();
    }  
    return answer;
}