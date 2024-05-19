//Ian Leuty ileuty@pdx.edu May 5 2024 CS162-001
/*This file contains the menu function and any others needed to call directly from main
without having to create a class instance 
*/
#include "calendar.h"

using namespace std;

//display a welcome message to the user and explain the program's purpose.
void welcome(){
    cout << "\033[2J\033[1;1H" << endl;
    cout << R"(
             ███████╗██╗   ██╗███████╗███╗   ██╗████████╗
             ██╔════╝██║   ██║██╔════╝████╗  ██║╚══██╔══╝
             █████╗  ██║   ██║█████╗  ██╔██╗ ██║   ██║   
             ██╔══╝  ╚██╗ ██╔╝██╔══╝  ██║╚██╗██║   ██║   
             ███████╗ ╚████╔╝ ███████╗██║ ╚████║   ██║   
             ╚══════╝  ╚═══╝  ╚══════╝╚═╝  ╚═══╝   ╚═╝   
                                                                           
      ██████╗ █████╗ ██╗     ███████╗███╗   ██╗██████╗  █████╗ ██████╗     
     ██╔════╝██╔══██╗██║     ██╔════╝████╗  ██║██╔══██╗██╔══██╗██╔══██╗    
     ██║     ███████║██║     █████╗  ██╔██╗ ██║██║  ██║███████║██████╔╝    
     ██║     ██╔══██║██║     ██╔══╝  ██║╚██╗██║██║  ██║██╔══██║██╔══██╗    
     ╚██████╗██║  ██║███████╗███████╗██║ ╚████║██████╔╝██║  ██║██║  ██║    
      ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ 
               This program stores events and their details.
                           Get out and do stuff. 
             Don't spend your whole life sitting behind a desk.)" << endl;
}

/*display a menu of the program's capabilities 
allow the user to make a selection and excecute the desired proccess by making 
a call to the function(s)
Retrun false if user chooses to quit, so that menu can be offered in a loop from main.
*/
bool menu(cal &events){
    char choice{'\0'};
    bool repeat{true};
    cout << "\nChoose from the following options by entering the first letter:\n\n"
         << "-(E)nter a new item\n"
         << "-(S)earch for an item by *field tbd* \n"
         << "-(D)isplay all items in the inventory\n"
         << "-(Q)uit\n\n" << '>';
    cin >> choice;
    cin.ignore(100, '\n');

        if('E' == toupper(choice)){ //Enter an item
            cout << endl;
            events.get_events();
        }
        else if('S' == toupper(choice)){ //Search for an item
            cout << endl;
            if(!events.search())
                cout << "\nNo matches found for that event." << endl;
        }
        else if('D' == toupper(choice)){ //Display All
            cout << endl;
            events.display_events();
        }
        else if('Q' == toupper(choice)){ //Quit
            cout << "Goodbye." << endl;
            repeat = false;
        }
        else{ //Re-prompt for correct choice
            cout << "Please make a valid selection ('E', 'S', 'D', or 'Q')\n" << endl;
        } 
    return repeat;
}

