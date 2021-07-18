///Replace with your name
///Replace with the date
///Replace with the purpose of the program


#include "ProgrammingAssignment4.h"

int main()
{
    footBallPlayerType bigGiants[MAX];
    int numberOfPlayers;

    int choice;
    string name;
    int playerNum;
    int numOfTouchDowns;
    int numOfcatches;
    int numOfPassingYards;
    int numOfReceivingYards;
    int numOfRushingYards;
    int ret;
    int num = 0;
   
    ifstream inFile;
    ofstream outFile;

    ret = openFile(inFile);
    if (ret)
      return 1;

    
    
     getData( inFile, bigGiants, num);
     
     
    do
    {
        
        showMenu();
        cin >> choice;
        cout << endl;
       

        switch (choice)
        {
        case 1:
            cout << "Enter player's name: ";
            cin >> name;
            cout << endl;

            playerNum = searchData(bigGiants, num, name);
            printPlayerData(bigGiants, num, playerNum);
            break;

        case 2:
            printData(bigGiants, num);
            break;

        case 3:
            cout << "Enter player name: ";
            cin >> name;
            cout << endl;

            playerNum = searchData(bigGiants, num, name);
            if (playerNum>=0)
            {
                  cout << "Enter number of touch downs to be added: ";
            cin >> numOfTouchDowns;
            cout << endl;
            updateTouchdowns(bigGiants, numOfTouchDowns, playerNum);

            }
            

          

            
            break;

        case 4:
            cout << "Enter player name: ";
            cin >> name;
            cout << endl;

            playerNum = searchData(bigGiants, num, name);

            cout << "Enter number of catches to be added: ";
            cin >> numOfcatches;
            cout << endl;

            updateCatches (bigGiants, numOfcatches , playerNum);
            break;

        case 5:
            cout << "Enter player name: ";
            cin >> name;
            cout << endl;

            playerNum = searchData(bigGiants, num, name);

            cout << "Enter number of passing yards to be added: ";
            cin >> numOfPassingYards;
            cout << endl;

/// replace with call to updatePassingYards from group 3
            break;

        case 6:
            cout << "Enter player name: ";
            cin >> name;
            cout << endl;

            playerNum = searchData(bigGiants, num, name);

            cout << "Enter number of receiving yards to be added: ";
            cin >> numOfReceivingYards;
            cout << endl;

 /// replace with call to update Receiving Yards from group 4
             break;

        case 7:
            cout << "Enter player name: ";
            cin >> name;
            cout << endl;

            playerNum = searchData(bigGiants, num, name);
            if(playerNum >= 0)
            {
                cout << "Enter number of rushing yards to be added: ";
                cin >> numOfRushingYards;
                cout << endl;
            }
            
            updateRushingYards(bigGiants, num, playerNum, numOfRushingYards);
            break;

        case 99:
            break;

        default:
            cout << "Invalid selection." << endl;
        }
    }
    while (choice != 99);

    char response;

    cout << "Would you like to save data: (y,Y/n,N) ";
    cin >> response;
    cout << endl;

    if (response == 'y' || response == 'Y')
        saveData(outFile, bigGiants, num);

    inFile.close();
    outFile.close();

    return 0;
}
/// Function requests file name from the user and opens file.
///  Precondition:  None
///  Post condition:  If no error encountered, file is opened.
///   If file cannot be opened, a 1 is returned.
///  Parameter:  ifstream
int openFile(ifstream& in) {
	string filename;
	cout << "Please enter football data file name: ";
	cin >> filename;
	in.open(filename);
    if (!in)
    {
        cout << filename << " input file does not exist. Program terminates!" << endl;
        return 1;
    }
    return 0;
}
/// Function requests file name from the user and opens file.
///  Precondition:  None
///  Post condition:  If no error encountered, file is opened.
///   If file cannot be opened, a 0 is returned.
///  Parameter:  ofstream
int openOutFile(ofstream& out) {
	string filename;
	cout << "Please enter the name of the output file: ";
	cin >> filename;

	out.open(filename);
    if (!out)
    {
        return 0;
    }
    return 1;
}
/// Function requests presents menu to user
///  Precondition:  None
///  Post condition:  None
///  Parameter:  None
void showMenu()
{
    cout << "Select one of the following options:" << endl;
    cout << "1: To print a player's data" << endl;
    cout << "2: To print the entire data" << endl;
    cout << "3: To update a player's touch downs" << endl;
    cout << "4: To update a player's number of catches" << endl;
    cout << "5: To update a player's passing yards" << endl;
    cout << "6: To update a player's receiving yards" << endl;
    cout << "7: To update a player's rushing yards" << endl;
    cout << "99: To quit the program" << endl;
}
/// Reads data into the structure array
///  Precondition: ifstream is open, howMany initialized to 0
///  Postcondition:  the structure array contains data from the input file
///                  the howMany parameter contains the number of rows read
/// Parameters:  ifstream, structure array, int file read counter
void getData(ifstream& inf, footBallPlayerType list[], int& howMany)
{
    
   while (inf) 
    {   
        inf>> list[howMany].name >> list[howMany].position >> list[howMany].touchDowns >> list[howMany].catches >> list[howMany].passingYards
           >> list[howMany].receivingYards >> list[howMany].rushingYards;
       if(!inf)
       {
           break;
       }
    howMany++;
     
    }
       

     
     
}// end of getdata.


///  Prints statistics for a selected player
///  Precondition:  structure array contains data, length contains number of
///   rows in structure array,  playernum contains the index of the player
///   returned from the search (by name)
///  Parameters:  structure array, int length of array, int number of player
void printPlayerData(footBallPlayerType list[], int length, int playerNum)
{
    if (0 <= playerNum)
        cout << "Name: " << list[playerNum].name
             << " Position: "<< list[playerNum].position << endl
             << "Touch Downs: " << list[playerNum].touchDowns
             << ";  Number of Catches: " << list[playerNum].catches << endl
             << "Passing Yards: " << list[playerNum].passingYards
             << ";  Receiving Yards: " << list[playerNum].receivingYards
             << ";  Rushing Yards: " << list[playerNum].rushingYards << endl << endl;
    else
        cout << endl << endl;
}
///  Prints statistics for all players
///  Precondition:  structure array contains data, length contains number of
///   rows in structure array
///  Parameters;  structure array, int length of array
void printData(footBallPlayerType list[], int length)
{
    
    cout << left << setw(15) << "Name"
         << setw(14) << "Position"
         << setw(12) << "Touch Downs"
         << setw(9) << "Catches"
         << setw(12) << "Pass Yards"
         << setw(10) << "Rec Yards"
         << setw(12) << "Rush Yards" << endl;

    for (int i = 0; i < length; i++)
         cout << left << setw(15) << list[i].name
             << setw(14) << list[i].position
             << right << setw(6) << list[i].touchDowns
             << setw(9) << list[i].catches
             << setw(12) << list[i].passingYards
             << setw(10) << list[i].receivingYards
             << setw(12) << list[i].rushingYards << endl;
     cout << endl << endl;
}
/// Saves updated data to file name entered by user
/// Precondition:  structure array contains data, length of array is filled
/// Postcondition:  If requested file is opened, updated data is written to the
///   output file
/// Parameters:  ofstream, structure array, int length of array
void saveData(ofstream& outF, footBallPlayerType list[], int length)
{
    int ret;
    ret = openOutFile(outF);
    if (!ret) {
        cout << "Output file did not open...data will not be output to a file. " << endl;
        return;
    }

    for (int i = 0; i < length; i++)
        outF << list[i].name
             << " " << list[i].position
             << " " << list[i].touchDowns
             << " " << list[i].catches
             << " " << list[i].passingYards
             << " " << list[i].receivingYards
             << " " << list[i].rushingYards<< endl;
}
/// Finds a football player by name
/// Precondition:  structure array contains data, length of array properly set,
///   string contains name of a football player
/// Postcondition:  if the player is found by name, the array index is returned.
///  otherwise, a -1 is returned
/// Parameters:  structure array, int length of array, string player name
int searchData(footBallPlayerType list[], int length, string n)
{
    for (int i = 0; i < length; i++)
        {if (list[i].name == n)
            {
            return i;
            }
        }
            cout << "Player not found" << endl;
            cout << endl;

    return -1;
}

/// replace with functions to:
void updateTouchdowns(footBallPlayerType list[], int downs, int number)
{  
    list[number].touchDowns= list[number].touchDowns + downs;
    
}
void updateCatches(footBallPlayerType list[], int c, int number)
{
    list[number].catches= list[number].catches + c;
}
///   update Catches
///   update Passing Yards
///   update Receiving Yards

void updateRushingYards(footBallPlayerType list[], int length, int playerNum, int yards){
	
		list[playerNum].rushingYards += yards;
	
		
}
