#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

bool isInt(char str[]);  /* this function checks whether the number entered is a integer or not. */
int stringToInteger(char str[]);  /* this fuction convert string to integer */
int makeSecretNumber(int number);  /* this function is used to produce the number of digits desired. */
bool isItValid(int secretNumber);  /* this function checks whether the number created or the number entered is uniqe. */
int calculateDigitofNumber(int number);  /* this function allows the game to be played until the game is over. */
int playGame(int secretNumber, int digitNumber); /* this function plays the game */
int calculateFirstCount(int secretNumber, int guessNumber);  /* this function calculates the first count. */
int calculateSecondCount(int secretNumber, int guessNumber);  /* this function calculates the second count. */

int main(int argc, char** argv)
{
    srand(time(0));  /* for random number. */
    bool result;
    int secretNumber, digitNumber, gameResult;   /* these are my variables. */
    if(argc != 3){
        cout << "E0\n";  /* if the inputs number not equal the 3 writes E0 and exit. */
        exit(1);
    }
    int length = strlen(argv[2]);
    if(length > 9){
        cout << "E0\n";   /* if the entered number greater than 9 then writes E0 and exit. */
        exit(1);
    }
    char number[15];
    strcpy(number, argv[2]);
    if(!isInt(number)){
        cout << "E0\n";  /* if the user enters the excluding integer writes E2 and exit. */
        exit(1);
    }
    int cmp1 = strcmp(argv[1], "-r");
    int cmp2 = strcmp(argv[1], "-u");
    if((cmp1 != 0) && (cmp2 != 0)){
        cout << "E0\n";   /* if the option is not -r or -u then writes E0 and exit. */
        exit(1);
    }
    else if(cmp1 == 0){   /* if the option is -r the this block is works. */
        digitNumber = stringToInteger(number);  /* convert string to integer. */
        if((digitNumber < 1) || (digitNumber > 9)){
            cout << "E0\n";  /* if the number of digits less then 0 or greater than 9 then writes E0 and exit. */
            exit(1);
        }
        while(1){  /* while make a secret number this block is works. */
            secretNumber = makeSecretNumber(digitNumber);  /* makes secret number. */
            result = isItValid(secretNumber);  /* checks the number is valid or not. */
            if(result == true)
                break;  /* leaves the loop. */
        }
    }
    else if(cmp2 == 0){  /* if the option is -u the this block is works. */
        if(number[0] == '0'){
            cout << "E0\n";  /* if the number starts with 0 then writes E0 and exit. */
            exit(1);
        }
        digitNumber = strlen(number);  /* calculate digit of a number. */
        secretNumber = stringToInteger(number);  /* convert string to integer. */
        result = isItValid(secretNumber);  /* checks the number is valid or not. */
        if(result == false){
            cout << "E0\n";  /* if the number is not valid then writes E0 and exit. */
            exit(1);
        }
    }
    gameResult = playGame(secretNumber, digitNumber);  /* plays the game. */
    if(gameResult > 0){
        cout << "FOUND " << gameResult << endl;  /* if the user found the number then writes found and number. */
        exit(1);
    }
    else if(gameResult == 0){
        cout << "FAILED";  /* if the user can not found the number then writes the failed and exit. */
        exit(1);
    }
}

int playGame(int secretNumber, int digitNumber)
{
    int guessNumber, count = 0, digit;  /* these are my variables. */
    int firstCount, secondCount;
    char str[15];
    while(count < 100){  /* if the user can not found 100 iterators returns 0 */
        cin >> str;
        if(!isInt(str)){
            cout << "E2\n";  /* checks the number is integer or not. */
            exit(1);
        }
        guessNumber = stringToInteger(str);
        digit = calculateDigitofNumber(guessNumber);  /* calculate the number of digit */
        if(digit != digitNumber){
            cout << "E1\n";  /* if the digits are different from each other writes E1 and exit. */
            exit(1);
        }
        if(!isItValid(guessNumber)){  /* if the enterd numbr is not unique write E0 and exit. */
            cout << "E1\n";
            exit(1);
        }
        firstCount = calculateFirstCount(secretNumber, guessNumber);  /* calculate the first count. */
        if(firstCount == digitNumber)  /* if the first count equal the digit of the number returns the count+1 */
            return (count + 1);
        secondCount = calculateSecondCount(secretNumber, guessNumber);  /* calculate the second count */
        cout << firstCount << " " << secondCount << endl;  /* writes the hints */
        count++;
    }
    return 0;
}

int calculateFirstCount(int secretNumber, int guessNumber)
{
    int count = 0, digit1, digit2;
    while(secretNumber > 0){
        digit1 = secretNumber % 10;  /* takes the last digit of the number. */
        digit2 = guessNumber % 10;   /* takes the last digit of the number. */
        if(digit1 == digit2)
            count++;  /* if the digits are equal then count++ */
        secretNumber = secretNumber/10;  /* get out of the last digit. */
        guessNumber = guessNumber/10;  /* get out of last digit. */
    }
    return count;
}

int calculateSecondCount(int secretNumber, int guessNumber)
{
    int tempNumber, digit1, digit2, count=0, i=0, j;
    while(secretNumber > 0){
        tempNumber = guessNumber;  /* equal to temp variable for do not lost real number */
        digit1 = secretNumber % 10;  /* takes the last digit of the number. */
        i++;
        j = 0;
        while(tempNumber > 0){    /* for every step it compare different digits of the number. */
            digit2 = tempNumber % 10;  /* takes the last digit of the number. */
            j++;
            if((digit1 == digit2) && (i != j))  /* if the numbers are equal and digits number are not equal then count increase. */
                count++;
            tempNumber = tempNumber/10;  /* get out of last digit. */
        }
        secretNumber = secretNumber/10;  /* get out of last digit. */
    }
    return count;
}

int calculateDigitofNumber(int number)
{
    int digit = 0;
    while(number > 0){
        number = number/10;  /* get out of last digit. */
        digit++;
    }
    return digit;  /* returns the digits number. */
}

bool isItValid(int secretNumber)
{
    int tempNumber, j;
    for(int i=0; i<10; i++){
        j = 0;
        tempNumber = secretNumber;  /* equals the secret number each step. */
        while(tempNumber > 0){  /* while temp number greater than 0 */
            if(tempNumber % 10 == i)  /* if the digits equal the j increases. */
                j++;
            if(j > 1)  /* if j increases more than one returns false */
                return false;
            tempNumber = tempNumber/10;  /* get out of the last digit. */
        }
    }
    return true;  /* if everything is okey then returns true. */
}

int makeSecretNumber(int number)
{
    int n=0, temp, secretNumber=0, tempCount=1;
    for(int i=1; i<number; i++)
        tempCount = tempCount * 10;  /* if the number is 3 the the temp count will be 100 */
    while(n < number){
        temp = rand()%10;  /* makes random number 0-9 */
        if((n == 0) && (temp != 0)){  /* if the first digit is not 0 this block works. */
            secretNumber = secretNumber + (temp * tempCount);  /* calculate secret number. */
            tempCount = tempCount/10;  /* it decrease one digit. */
        }
        else if(n > 0){
            secretNumber = secretNumber + (temp * tempCount);  /* calculate secret number. */
            tempCount = tempCount/10;  /* it decrease one digit. */
        }
        n++;
    }
    return secretNumber;
}

int stringToInteger(char str[])
{
    int tempCount = 1, number = 0, temp;
    int count = strlen(str);  /* calculate the number of digit. */
    for(int i=1; i<count; i++)
        tempCount = tempCount * 10;  /* it calculates 10 times digit. */
    for(int i=0; i<count; i++){
        temp = str[i] - '0';   /* for chat to integer. */
        number = number + (temp * tempCount);  /* for example the digit is 3 and digit number is 3 the it summing 0 + (3*100) and it goes on */
        tempCount = tempCount / 10;  /* and then upper calculate 100 becomes 10 and goes on. */
    }
    return number;  /* returns integer value. */
}

bool isInt(char str[])
{
    int count = strlen(str);
    for(int i=0; i<count; ++i){
        if(isdigit(str[i]) == false)  /* if the number is not equal integer the returns false. */
           return false;
    }        
    return true;  /* if everything is okey then returns true. */
}