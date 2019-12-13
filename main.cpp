#include <iostream>
using namespace std;
bool AvailabilityX(int X, int Y, char array[3][3]){
    if(array[Y][X] == ' '){
        array[Y][X] = 'X';
        return false;
    } else {
        cout << "This place is taken. Try again. " << endl;
        return true;
    }
}
bool AvailabilityO(int X, int Y, char array[3][3]){
    if(array[Y][X] == ' '){
        array[Y][X] = 'O';
        return false;
    } else {
        cout << "This place is taken. Try again. " << endl;
        return true;
    }
}
int AssignX(){
    int X;
    cout << "Enter coordinate X: ";
    cin >> X;
    while(!(X == 0 || X == 1 || X == 2)){
        cout << "Enter valid coordinate X: ";
        cin >> X;
    }
    return X;
} // ПРИСВОЕНИЕ КООРДИНАТЫ ИКСУ
int AssignY(){
    int Y;
    cout << "Enter coordinate Y: ";
    cin >> Y;
    while(!(Y == 0 || Y == 1 || Y == 2)){
        cout << "Enter valid coordinate X: ";
        cin >> Y;
    }
    return Y;
} // ПРИСВОЕНИЕ КООРДИНАТЫ ИГРИКУ
void MoveX(){
    cout << endl << "Move X" << endl;
}  // ТУПО ВЫВОД СООБЩЕНИЯ
void MoveO(){
    cout << endl << "Move O" << endl;
}  // ТУПО ВЫВОД СООБЩЕНИЯ
void Display(char array[3][3], int size){
    cout << "-------------------------------" << endl << endl;
    for (int i = 0; i < size; ++i) {
        cout << "\t";
        for (int j = 0; j < size; ++j) {
            cout << "|" << array[i][j] << "| ";
        }
        cout << endl;
    }
    cout << endl << "-------------------------------";
} // ВЫВОД ПОЛЯ
bool CheckWin(char array[3][3]){
    if((array[0][0] == 'X' && array[0][1] == 'X' && array[0][2] == 'X') ||
       (array[1][0] == 'X' && array[1][1] == 'X' && array[1][2] == 'X') ||
       (array[2][0] == 'X' && array[2][1] == 'X' && array[2][2] == 'X') ||
       (array[0][0] == 'X' && array[1][0] == 'X' && array[2][0] == 'X') ||
       (array[0][1] == 'X' && array[1][1] == 'X' && array[2][1] == 'X') ||
       (array[0][2] == 'X' && array[1][2] == 'X' && array[2][2] == 'X') ||
       (array[0][0] == 'X' && array[1][1] == 'X' && array[2][2] == 'X') ||
       (array[0][2] == 'X' && array[1][1] == 'X' && array[2][0] == 'X')){
        cout << endl << "Congratulations! X wins!!!!!!!!!!";
        return false;
    }
    else if((array[0][0] == 'O' && array[0][1] == 'O' && array[0][2] == 'O') ||
            (array[1][0] == 'O' && array[1][1] == 'O' && array[1][2] == 'O') ||
            (array[2][0] == 'O' && array[2][1] == 'O' && array[2][2] == 'O') ||
            (array[0][0] == 'O' && array[1][0] == 'O' && array[2][0] == 'O') ||
            (array[0][1] == 'O' && array[1][1] == 'O' && array[2][1] == 'O') ||
            (array[0][2] == 'O' && array[1][2] == 'O' && array[2][2] == 'O') ||
            (array[0][0] == 'O' && array[1][1] == 'O' && array[2][2] == 'O') ||
            (array[0][2] == 'O' && array[1][1] == 'O' && array[2][0] == 'O')){
        cout << endl << "Congratulations! O wins!!!!!!!!!!";
        return false;
    } else return true;
}


int main() {
    const int SIZE = 3;
    char gameBoard[SIZE][SIZE] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
    };
    int coordinateX,  coordinateY;


    Display(gameBoard, SIZE);
    do {
        MoveX();
        coordinateX = AssignX();
        coordinateY = AssignY();
        while (AvailabilityX(coordinateX, coordinateY, gameBoard)) {
            coordinateX = AssignX();
            coordinateY = AssignY();
        }
        Display(gameBoard, SIZE);

        MoveO();
        coordinateX = AssignX();
        coordinateY = AssignY();
        while (AvailabilityO(coordinateX, coordinateY, gameBoard)) {
            coordinateX = AssignX();
            coordinateY = AssignY();
        }
        Display(gameBoard, SIZE);
    } while (CheckWin(gameBoard));
}
