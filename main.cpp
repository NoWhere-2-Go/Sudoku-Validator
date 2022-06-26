using namespace std;
#include <iostream>
#include <memory>
#include <fstream>

bool checkRow(shared_ptr<char>);
bool checkCol(shared_ptr<char>);
bool checkBox(shared_ptr<char>, int boxNum = 1);


int main() {
    string fileName; //string to take input
    shared_ptr<char> sudoku_SmartPtr(new char[81]);
    string line;

    //ask user for filename and initialize fileName variable
    cout << "Please enter a file name: ";
    cin >> fileName;

    ifstream ifile;//file stream for input only
    ifile.open(fileName, ios::binary);


    while (!ifile.eof())
    {
        string puzzleNum;
        getline(ifile, puzzleNum);//get the puzzle number
        cout << "\n" << puzzleNum;
        
        //go thru file and populate the array with the puzzle
        for (int i = 0; i < 9; ++i)
        {
            getline(ifile, line);
            for (int j = 0; j < 9; ++j)
            {
                sudoku_SmartPtr.get()[(i*9)+j] = line[j];
            }
        }

        if(checkRow(sudoku_SmartPtr))//if puzzle returns true in the checkRow function call checkColumn function
        {
            if (checkCol(sudoku_SmartPtr))//if puzzle returns true in checkCol function call checkBox function
            {
                //final check to see if puzzle is valid, solved or invalid.
                //will print out solved if function returns true
                checkBox(sudoku_SmartPtr);
            }
        }
        //if there is nothing else to read using getline break the loop
        if (!getline(ifile, line))
        {
            break;
        }
    }//end of while loop
    //delete sudokuArray;
    ifile.close();
    return 0;
}

//function to check whether each row inside the array/puzzle is valid
bool checkRow(shared_ptr<char> arr)
{
    int rowNum = 1; //will keep track of what row we are on
    
    /*counter variables to count how many times we use digits 1-9 each loop.
    If the counter is > than 1 there's duplicate digit, will reset the counter variables back to zero after each loop*/
    int num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    bool status = true;
    int i;
    //loop to iterate through row 1 of array
    for (i = 0; i <= 8; i++)
    {
        //count each occurence of digits 1-9 inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        
        //if i is at the last index of this row run these checks 
        if (i == 8)
        {
            /* several different checks using digit counter variables. 
             * each digit should only be used once, so if a digit is used more than once it'll go thru the check 
             * and print out the puzzle is invalid and the row number and the digit
            */
            if (num1Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 1s" << endl;
                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalidrow " << rowNum << " has multiple 2s" << endl;
                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 3s" << endl;
                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 4s" << endl;
                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 5s" << endl;
                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 6s" << endl;
                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 7s" << endl;
                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 8s" << endl;
                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 9s" << endl;
                return status;
            }
        }
    }//end of row 1 check

    //re-intialize the number counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;

    //loop to iterate through row 2
    for (int i = 9; i <= 17; i++)
    {
        rowNum = 2;
        //count each occurence of digits 1-9 inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        
        //if i is at the last index of this row run these checks
        if (i == 17)
        {
            
            if (num1Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 1s" << endl;
                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 2s" << endl;
                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 3s" << endl;
                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 4s" << endl;
                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 5s" << endl;
                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 6s" << endl;
                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 7s" << endl;
                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 8s" << endl;
                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 9s" << endl;
                return status;
            }
        }
    }//end of row 2 check

    //re-intialize the number counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;

    //loop to iterate through row 3
    for (int i = 18; i <= 26; i++)
    {
        rowNum = 3;
        //count each element inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        //if i is at the last index of this row run these checks
        if ( i == 26)
        {
            if (num1Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 1s" << endl;
                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 2s" << endl;
                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 3s" << endl;
                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 4s" << endl;
                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid row" <<     rowNum << "     has multiple 5s" << endl;
                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 6s" << endl;
                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 7s" << endl;
                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 8s" << endl;
                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 9s" << endl;
                return status;
            }
        }
    }//end of row3 check

    //re-intialize the number counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    
    //loop to iterate through row 4
    for (int i = 27; i <= 35; i++)
    {
        rowNum = 4;
        //count each element inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        //if i is at the last index of this row run these checks
        if (i == 35)
        {
            if (num1Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 1s" << endl;
                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 2s" << endl;

                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 3s" << endl;

                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 4s" << endl;

                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 5s" << endl;

                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 6s" << endl;

                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 7s" << endl;

                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 8s" << endl;

                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 9s" << endl;

                return status;
            }
        }
    }//end of row 4 check

    //re-intialize the number counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;

    //loop to iterate through row 5
    for (int i = 36; i <= 44; i++)
    {
        rowNum = 5;
        //count each element inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        //if i is at the last index of this row run these checks
        if (i == 44)
        {
            if (num1Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 1s" << endl;

                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 2s" << endl;

                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 3s" << endl;

                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 4s" << endl;

                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 5s" << endl;

                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 6s" << endl;

                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 7s" << endl;

                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 8s" << endl;

                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 9s" << endl;

                return status;
            }
        }
    }//end of row 5 check

    //re-intialize the number counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;

    //loop to iterate through row 6
    for (int i = 45; i <= 53; i++)
    {
        rowNum = 6;
        //count each element inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }

        //if i is at the last index of the row run these checks
        if (i == 53)
        {
            if (num1Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 1s" << endl;

                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 2s" << endl;

                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 3s" << endl;

                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 4s" << endl;

                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 5s" << endl;

                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 6s" << endl;

                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 7s" << endl;

                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 8s" << endl;

                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 9s" << endl;

                return status;
            }
        }
    }//end of row 6 loop & check

    //re-intialize the number counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;

    //loop to iterate through row 7
    for (int i = 54; i <= 62; i++)
    {
        rowNum = 7;
        //count each element inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        //if i is at last index of this row run these checks
        if (i == 62)
        {
            if (num1Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 1s" << endl;

                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 2s" << endl;

                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 3s" << endl;

                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 4s" << endl;

                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 5s" << endl;

                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 6s" << endl;

                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 7s" << endl;

                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 8s" << endl;

                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 9s" << endl;

                return status;
            }
        }
    }//end of row 7 loop & checks

    //re-intialize the number counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;

    //loop to iterate through row 8
    for (int i = 63; i <= 71; i++)
    {
        rowNum = 8;
        //count each element inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        //if i is at the last index of row run the checks
        if (i == 71)
        {
            if (num1Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 1s" << endl;

                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 2s" << endl;

                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 3s" << endl;

                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 4s" << endl;

                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 5s" << endl;

                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 6s" << endl;

                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 7s" << endl;

                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 8s" << endl;
                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 9s" << endl;
                return status;
            }
        }
    }//end of row 8 loop & checks

    //re-intialize the number counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;

    //loop to iterate through row 9
    for (int i = 72; i <= 80; i++)
    {
        rowNum = 9;
        //count each element inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        
        //if i is the last index of array run these checks
        if (i == 80)
        {
            if (num1Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 1s" << endl;

                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 2s" << endl;

                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 3s" << endl;
                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 4s" << endl;
                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 5s" << endl;
                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 6s" << endl;
                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid " << "  row "<<  rowNum << " has multiple 7s" << endl;
                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 8s" << endl;
                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid row " << rowNum << " has multiple 9s" << endl;
                return status;
            }
        }
    }//end of row 9 loop and checks
    return status; //if none of the checks return false, return true at end of function
}

//function to check whether each column inside the array/puzzle is valid
bool checkCol(shared_ptr<char> const arr)
{
    int i = 0, colNum;
    /*counter variables to count how many times we use digits 1-9 each loop.
    If the counter is > 1 there's duplicate digit, will reset the counter variables back to zero after each loop*/
    int num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    bool status = true;

    //first column at index 0 
    //loop thru each element of column 1 of array. the last element of column 0 is 72
    while(i <= 72)
    {
        colNum = 1;
        //count occurence of each digit inside index i of array, 
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        
        if (i == 72)
        {
            /* several different checks using digit counter variables. 
             * each digit should only be used once, so if a digit is used more than once itll print out
             * the puzzle is invalid and the column number and the digit
            */
            if (num1Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 1s" << endl;
                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 2s" << endl;

                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 3s" << endl;

                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 4s" << endl;

                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 5s" << endl;

                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 6s" << endl;

                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 7s" << endl;

                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 8s" << endl;

                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 9s" << endl;

                return status;
            }
        }
        i += 9;//each element of the index of the column is previous index plus 9
    }//end of column 1 loop and checks

    i = 1; //initialize i to 1 (since we are in column 2) so we can add it by 9
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;

    //loop thru col 2
    while(i <= 73)
    {
        colNum = 2;
        //count each element inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }

        if(i == 73)
        {
            if (num1Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 1s" << endl;

                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 2s" << endl;

                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 3s" << endl;

                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 4s" << endl;

                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 5s" << endl;

                return status;
            }
            if (num6Count > 1){
                cout << "   invalid column " << colNum << " has multiple 6s" << endl;

                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 7s" << endl;

                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 8s" << endl;

            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 9s" << endl;

                return status;
            }
        }
        i += 9;//each element of the index of the column is previous index plus 9
    }//end of column 2 loop and checks

    i = 2; //initialize i to 2 since we are now checking the 3rd column
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;

    while(i <= 74)
    {
        colNum = 3;
        //count each element inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        //if i is at last index of column run these checks 
        if(i == 74)
        {
            if (num1Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 1s" << endl;

                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 2s" << endl;

                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 3s" << endl;

                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 4s" << endl;

                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 5s" << endl;

                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 6s" << endl;

                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 7s" << endl;

                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 8s" << endl;

                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 9s" << endl;

                return status;
            }
        }
        i += 9;//each element of the index of the column is previous index plus 9
    }//end of column 3 loop and checks

    i = 3; //initialize i to 3 since we are now checking column 4
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    while(i <= 75)
    {
        colNum = 4;
        //count each element inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        //if i is at the last index of this column run these checks
        if(i == 75)
        {
            if (num1Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 1s" << endl;

                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 2s" << endl;

                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 3s" << endl;

                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 4s" << endl;

                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 5s" << endl;

                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 6s" << endl;

                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 7s" << endl;

                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 8s" << endl;

                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 9s" << endl;

                return status;
            }
        }
        i += 9;//each element of the index of the column is previous index plus 9
    }//end of col 4 loop and checks

    i = 4;//initialize i to 4 since we are now checking column 5

    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    while(i <= 76)
    {
        colNum = 5;
        //count each element inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        //if i is at the last index of this column run these checks
        if(i == 76)
        {
            if (num1Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 1s" << endl;

                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 2s" << endl;

                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 3s" << endl;

                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 4s" << endl;

                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 5s" << endl;

                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 6s" << endl;

                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 7s" << endl;

                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 8s" << endl;

            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 9s" << endl;

                return status;
            }
        }
        i += 9;//each element of the index of the column is last index plus 9
    }//end of column 5 loop and checks

    i = 5;//initialize i to 5 since we are working with column 6
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    while(i <= 77)
    {
        colNum = 6;
        //count each element inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        //if i is at the last index of these rows run these checks
        if(i == 77)
        {
            if (num1Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 1s" << endl;

                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 2s" << endl;

                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 3s" << endl;

                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 4s" << endl;

                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 5s" << endl;

                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 6s" << endl;

                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 7s" << endl;

                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 8s" << endl;

                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 9s" << endl;

                return status;
            }
        }
        i += 9;//each element of the index of the column is last index plus 9
    }//end of column 6 loop and checks

    i = 6; //initialize i to 6 since were working with column 7
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    while(i <= 78)
    {
        colNum = 7;
        //count each element inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        //if i is at the last index of this column run these checks
        if(i == 78)
        {
            if (num1Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 1s" << endl;

                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 2s" << endl;

                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 3s" << endl;

                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 4s" << endl;

                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 5s" << endl;

                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 6s" << endl;

                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 7s" << endl;

                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 8s" << endl;

                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 9s" << endl;

                return status;
            }
        }
        i += 9;//each element of the index of the column is last index plus 9
    }//end of column 7 loop and checks

    i = 7;//initialize i to 7 since were working with column 8
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    while(i <= 79)
    {
        colNum = 8;
        //count each element inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        //if i is at the last index of this row run these checks
        if(i == 79)
        {
            if (num1Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 1s" << endl;

                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 2s" << endl;

                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 3s" << endl;

                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 4s" << endl;

                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 5s" << endl;

                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 6s" << endl;

                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 7s" << endl;

                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 8s" << endl;

                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 9s" << endl;
                return status;
            }
        }
        i += 9;//each element of the index of the column is last index plus 9
    }//end of column 8 loop and checks

    i = 8;//initialize i to 8 since we are checking column 9
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    while(i <= 80)
    {
        colNum = 9;
        //count each element inside index i of array
        if (arr.get()[i] == '1'){
            num1Count+=1;
        }
        if (arr.get()[i] == '2'){
            num2Count+=1;
        }
        if (arr.get()[i] == '3'){
            num3Count+=1;
        }
        if (arr.get()[i] == '4'){
            num4Count+=1;
        }
        if (arr.get()[i] == '5'){
            num5Count+=1;
        }
        if (arr.get()[i] == '6'){
            num6Count+=1;
        }
        if (arr.get()[i] == '7'){
            num7Count+=1;
        }
        if (arr.get()[i] == '8'){
            num8Count+=1;
        }
        if (arr.get()[i] == '9'){
            num9Count+=1;
        }
        //if i is at the last index of this column run these checks
        if(i == 80)
        {
            if (num1Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 1s" << endl;

                return status;
            }
            if (num2Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 2s" << endl;

                return status;
            }
            if (num3Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 3s" << endl;

                return status;
            }
            if (num4Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 4s" << endl;

                return status;
            }
            if (num5Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 5s" << endl;

                return status;
            }
            if (num6Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 6s" << endl;

                return status;
            }
            if (num7Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 7s" << endl;

                return status;
            }
            if (num8Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 8s" << endl;
                return status;
            }
            if (num9Count > 1){
                status = false;
                cout << "   invalid column " << colNum << " has multiple 9s" << endl;
                return status;
            }
        }
        i += 9;//each element of the index of the column is last index plus 9
    }//end of column 9 loop and checks

    return status; //if none of the checks return false function will return true
}//end of column check function

//function to check whether or not the 3x3 box inside the puzzle is valid
//boxNum will increment everytime we verify a box/
bool checkBox(shared_ptr<char> const arr, int boxNum)
{
    int spaces = 0;
    bool status = true;
    int counter; //use to iterate on last row of each 
    string boxLoc; //a string to indicate what box/ we are in
    int num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;

    counter = 17;//change counter to 18 so we can use to increment on the row 3 loop of upper left
    //while loop to keep us inside of box/ 1 and keep us out of it once we move onto different box
    while(boxNum == 1) {
        boxLoc = "upper left"; //we are in the upper left box/; only exists inside while loop
        //loop through row 1 of 3x3 box 1
        for (int i = 0; i < 3; ++i) {
            //count each of occurence of digits & spaces inside row 1 of box 1
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;

            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }//end of row 1 of first box
        //loop to iterate through row 2 of box 1
        for (int i = 9; i < 12; ++i) {
            //count each of occurence of digits & spaces inside row 2 of box 1
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }//end of row 2 box 1 loop
        for (int i = 18; i < 21; ++i) {
            //count each of occurence of digits & spaces inside row 3 of box 1
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
            counter++;
        }//end of row 3 box 1 loop
        //check if box 1 violates rules
        if (num1Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 1s" << endl;
        }
        if (num2Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 2s" << endl;
        }
        if (num3Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 3s" << endl;
        }
        if (num4Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 4s" << endl;
        }
        if (num5Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 5s" << endl;
        }
        if (num6Count > 1) {
            status = false;
            cout << "`  invalid" <<     boxLoc << " has multiple 6s" << endl;
        }
        if (num7Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 7s" << endl;
        }
        if (num8Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 8s" << endl;
        }
        if (num9Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 9s" << endl;
        }
        if (!status){//if statement to check if status is false end function and return false
            return false;
        }
        if (counter == 20){
            boxNum++;//increment boxNum to 2 since we are now in box/ 2
        }
    }//end of while loop for box 1

    counter = 20;
    //re-initialize digit counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    //while loop to keep us inside middle upper box when boxNum is 2 and to keep us out of it when boxNum isn't 2
    while(boxNum == 2)
    {
        boxLoc = "upper middle"; //location of box/ we are working with
        //loop thru row 1 of box 2
        for (int i = 3; i < 6; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }//end of row 1 loop of box 2
        //loop to iterate thru row 2 of box 2
        for (int i = 12; i < 15; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }//end of loop for row 2 of box 2
        //loop thru row 3 of box 2
        for (int i = 21; i < 24; ++i) {
            (counter)++;
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }//end of row 3 loop for box 2
        if (num1Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 1s" << endl;
        }
        if (num2Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 2s" << endl;
        }
        if (num3Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 3s" << endl;
        }
        if (num4Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 4s" << endl;
        }
        if (num5Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 5s" << endl;
        }
        if (num6Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 6s" << endl;
        }
        if (num7Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 7s" << endl;
        }
        if (num8Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 8s" << endl;
        }
        if (num9Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 9s" << endl;
        }
        if (!status){//if statement to check if status is false end function and return false
            return false;
        }
        if (counter == 23) {
            boxNum++;//increment boxNum to 3 since we are now in box/ 3
        }
        
    }//end of while loop for upper middle/box 2

    counter = 23;
    //re-initialize digit counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    //while loop for box 3/ upper right
    while (boxNum == 3){
        boxLoc = "upper right";
        for (int i = 6; i <= 8; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }//end of for loop for row 1 of box 3
        for (int i = 15; i <= 17; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;

            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }//end of for loop for row 2 of box 3
        for (int i = 24; i <= 26; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            (counter)++;
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;

            }
            if (arr.get()[i] == '4') {
                num4Count += 1;

            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }//end of for loop for row 3 of box 3
        //check if box 3 is valid
        if (num1Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 1s" << endl;
        }
        if (num2Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 2s" << endl;
        }
        if (num3Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 3s" << endl;
        }
        if (num4Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 4s" << endl;
        }
        if (num5Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 5s" << endl;
        }
        if (num6Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 6s" << endl;
        }
        if (num7Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 7s" << endl;
        }
        if (num8Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 8s" << endl;
        }
        if (num9Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 9s" << endl;
        }
        if (!status){//if statement to check if status is false end function and return false
            return false;
        }
        if (counter == 26) {
            boxNum++;//increment boxNum to 4 since we are now in box/ 4
        }
        
    }//end of while loop for box 3
    counter = 44;
    //re-initialize digit counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    //while loop for box 4/section middle left
    while (boxNum == 4){
        boxLoc = "left";
        //loop thru row 1 of left box
        for (int i = 27; i < 30; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }
        //loop thru row 2 of left box
        for (int i = 36; i < 39; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }
        //loop thru row 3 of left box
        for (int i = 45; i < 48; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            (counter)++;
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }//end of for loop for row 3 of left box
        //check if left box (box 4) is valid
        if (num1Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 1s" << endl;
        }
        if (num2Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 2s" << endl;
        }
        if (num3Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 3s" << endl;
        }
        if (num4Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 4s" << endl;
        }
        if (num5Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 5s" << endl;
        }
        if (num6Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 6s" << endl;
        }
        if (num7Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 7s" << endl;
        }
        if (num8Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 8s" << endl;
        }
        if (num9Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 9s" << endl;
        }
        if (!status){//if statement to check if status is false end function and return false
            return false;
        }
        if (counter == 47) {
            boxNum++;//increment boxNum to 5 since we are now in box/ 5
        }
    }//end of box 4/left box while loop

    counter = 47;
    //re-initialize digit counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    //while loop for middle  (box 5)
    while (boxNum == 5){
        boxLoc = "middle";
        //loop thru row 1 of middle 
        for (int i = 30; i < 33; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }
        //loop thru row 2 of middle 
        for (int i = 39; i < 42; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }
        //loop thru row 3 of middle 
        for (int i = 48; i < 51; ++i) 
        {
            (counter)++;
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }//end of for loop for row 3 of middle 
        //check if middle  is valid
        if (num1Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 1s" << endl;
        }
        if (num2Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 2s" << endl;
        }
        if (num3Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 3s" << endl;
        }
        if (num4Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 4s" << endl;
        }
        if (num5Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 5s" << endl;
        }
        if (num6Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 6s" << endl;
        }
        if (num7Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 7s" << endl;
        }
        if (num8Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 8s" << endl;
        }
        if (num9Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 9s" << endl;
        }
        if (!status){//if statement to check if status is false end function and return false
            return false;
        }
        if (counter == 50) {
            boxNum++;//increment boxNum to 6 since we are now in box/ 6
        }
        
    }//end of while loop for middle  (box 5)
    counter = 51;
    //re-initialize digit counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    //while loop for right  (box 6)
    while (boxNum == 6){
        boxLoc = "right";
        //for loop for row 1 of right 
        for (int i = 33; i <= 35; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }
        //for loop for row 2 of right 
        for (int i = 42; i <= 44; ++i)
        { 
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }
        //for loop for row 3 of right 
        for (int i = 51; i < 53; ++i) 
        {
            (counter)++;
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }//end of for loop for row 3 of right 
        //check if right  is valid
        if (num1Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 1s" << endl;
        }
        if (num2Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 2s" << endl;
        }
        if (num3Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 3s" << endl;
        }
        if (num4Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 4s" << endl;
        }
        if (num5Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 5s" << endl;
        }
        if (num6Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 6s" << endl;
        }
        if (num7Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 7s" << endl;
        }
        if (num8Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 8s" << endl;
        }
        if (num9Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 9s" << endl;
        }
        if (!status){//if statement to check if status is false end function and return false
            return false;
        }
        if (counter == 53) {
            boxNum++;//increment boxNum to 7 since we are now in box/ 7 and to exit while loop
        }
        
    }//end of while loop for right  (box 6)

    counter = 71;
    //re-initialize digit counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    //while loop for lower left (box 7)
    while (boxNum == 7){
        boxLoc = "lower left";
        //loop thru row 1 of lower left  (box 7)
        for (int i = 54; i < 57; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }
        //loop thru row 2 of lower left  (box 7)
        for (int i = 63; i < 66; ++i)
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }
        //loop thru row 3 of lower left  (box 7)
        for (int i = 72; i < 75; ++i) {
            (counter)++;
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }//end of for loop for row 3 of lower left  (box 7)
        //check if lower left  is valid 
        if (num1Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 1s" << endl;
        }
        if (num2Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 2s" << endl;
        }
        if (num3Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 3s" << endl;
        }
        if (num4Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 4s" << endl;
        }
        if (num5Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 5s" << endl;
        }
        if (num6Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 6s" << endl;
        }
        if (num7Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 7s" << endl;
        }
        if (num8Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 8s" << endl;
        }
        if (num9Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 9s" << endl;
        }
        if (!status){//if statement to check if status is false end function and return false
            return false;
        }
        if (counter == 74) {
            boxNum++;//increment boxNum to 8 since we are now in box/ 8 and to exit while loop
        }

    }//end of while loop for lower left  (box 7)
    counter = 74;
    //re-initialize digit counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    //while loop for lower middle (box 8)
    while (boxNum == 8){
        boxLoc = "lower middle";
        //loop thru row 1 of lower middle  (box 8)
        for (int i = 57; i < 60; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }
        //loop thru row 2 of lower mid  (box 8)
        for (int i = 66; i < 69; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }
        //loop thru row 3 of lower mid  (box 8)
        for (int i = 75; i < 78; ++i) 
        {
            (counter)++;
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }//end of for loop for lower mid 
        //check if lower mid  is valid
        if (num1Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 1s" << endl;
        }
        if (num2Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 2s" << endl;
        }
        if (num3Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 3s" << endl;
        }
        if (num4Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 4s" << endl;
        }
        if (num5Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 5s" << endl;
        }
        if (num6Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 6s" << endl;
        }
        if (num7Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 7s" << endl;
        }
        if (num8Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 8s" << endl;
        }
        if (num9Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 9s" << endl;
        }
        if (!status){//if statement to check if status is false end function and return false
            return false;
        }
        if (counter == 77) {
            boxNum++;//increment boxNum to 9 since we are now in box/ 9 and to exit while loop
        }
        
    }// end of while loop for lower mid  (box 8)
    counter = 77;
    //re-initialize digit counters
    num1Count=0, num2Count=0, num3Count=0, num4Count=0,
    num5Count=0, num6Count=0, num7Count=0, num8Count=0, num9Count=0;
    //while loop for lower left  (box 9)
    while (boxNum == 9){
        boxLoc = "lower right";
        //for loop to go thru row 1 of lower right  (box 9)
        for (int i = 60; i <= 62; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }
        //for loop to go thru row 2 of lower right  (box 9)
        for (int i = 69; i <= 71; ++i) 
        {
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }
        //for loop to go thru row 3 of lower right  (box 9)
        for (int i = 78; i <= 80; ++i) {
            (counter)++;
            if (isspace(arr.get()[i])){
                spaces++;
            }
            if (arr.get()[i] == '1') {
                num1Count += 1;
            }
            if (arr.get()[i] == '2') {
                num2Count += 1;
            }
            if (arr.get()[i] == '3') {
                num3Count += 1;
            }
            if (arr.get()[i] == '4') {
                num4Count += 1;
            }
            if (arr.get()[i] == '5') {
                num5Count += 1;
            }
            if (arr.get()[i] == '6') {
                num6Count += 1;
            }
            if (arr.get()[i] == '7') {
                num7Count += 1;
            }
            if (arr.get()[i] == '8') {
                num8Count += 1;
            }
            if (arr.get()[i] == '9') {
                num9Count += 1;
            }
        }//end of for loop for lower right  (box 9)
        //check if lower right  is valid
        if (num1Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 1s" << endl;
        }
        if (num2Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 2s" << endl;
        }
        if (num3Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 3s" << endl;
        }
        if (num4Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 4s" << endl;
        }
        if (num5Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 5s" << endl;
        }
        if (num6Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 6s" << endl;
        }
        if (num7Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 7s" << endl;
        }
        if (num8Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 8s" << endl;
        }
        if (num9Count > 1) {
            status = false;
            cout << "   invalid" <<     boxLoc << " has multiple 9s" << endl;
        }
        if (!status){//if statement to check if status is false end function and return false
            return false;
        }
        if (counter == 80) {
            boxNum++;//increment boxNum to 9 since we are now in box/ 9 and to exit while loop
        }
        
    }//end of while loop for lower right  (box 9)
    //cout << "spaces: " << spaces << endl;
    //check if there were any spaces inside the boxes. If there is and the puzzle is valid run code underneath
    if (spaces > 0){
        cout << "   valid";
        return status;
    } //if theres no spaces and all puzzle s are valid then the puzzle is solved
    cout << "   solved" << endl;
    return status;
}
