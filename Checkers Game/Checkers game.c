// 209488717 tslil sardam
// 315636753 ohad adi
#include <stdio.h>
#define BOARD_SIZE 8

void print_board(char board[][BOARD_SIZE]);
int play(char board[][BOARD_SIZE]);
int play_single_turn(char board[][BOARD_SIZE], char pawn);
int is_move_legal(char board[][BOARD_SIZE],char pawn, int row_l, int row_d, int col_l, int col_d);
int is_pawn_moveable(char board[][BOARD_SIZE], char pawn, int row, int col);
int X_check_step (char board[][BOARD_SIZE], int row_l, int col_l);
int X_check_eat (char board[][BOARD_SIZE], int row_l, int col_l);
int O_check_step (char board[][BOARD_SIZE], int row_l, int col_l);
int O_check_eat (char board[][BOARD_SIZE], int row_l,int col_l);
int arrange_board(char board[][BOARD_SIZE], char pawn, int row_l, int row_d, int col_l, int col_d);
int win(char board[][BOARD_SIZE], int x_score,int o_score);
void place_pawns(char board[][BOARD_SIZE]);
int is_location_legal(char board[][BOARD_SIZE], int row_l, int col_l,char pawn);
int condition(char board[][BOARD_SIZE]);
int is_pawn_moveable_X(char board[][BOARD_SIZE], int row_l, int col_l);
int is_pawn_moveable_O(char board[][BOARD_SIZE], int row_l, int col_l);


int main(){
    int main_flag;
    char board[BOARD_SIZE][BOARD_SIZE];
    main_flag =1;

    while(main_flag == 1){
        place_pawns(board);
        play(board);
        main_flag =condition(board);
    }
    return 0;
}

void place_pawns(char board[][BOARD_SIZE]){
    int i,j;
    char init_board[BOARD_SIZE][BOARD_SIZE] = {{' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
                                               {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
                                               {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
                                               {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                                               {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                                               {'O', ' ', 'O', ' ', 'O', ' ', 'O', ' '},
                                               {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'},
                                               {'O', ' ', 'O', ' ', 'O', ' ', 'O', ' '}};
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = init_board[i][j];
        }
    }
}

void print_board(char board[][BOARD_SIZE]){
    int i,j;
    printf(" |0 1 2 3 4 5 6 7\n");
    printf(" *----------------\n");
    for(i=0; i<8; i++){
        printf("%d|",i);
        for(j=0; j<8; j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

int play(char board[][BOARD_SIZE]){
    int i, x_score, o_score, eat;
    char pawn;
    i = 1;
    x_score = 0;
    o_score = 0;

    printf("Lets play Draughts!\n");
    while(1){
        if(i%2)
            pawn ='X';
        else
            pawn = 'O';

        if (i != 1) {
            printf("X score:%d       O score:%d\n", x_score, o_score);
        }
        printf("----------Play number:%d----------\n",i);
        print_board(board);
        eat =play_single_turn(board,pawn);
        if (eat ==999) {
            printf("Player %c decided to quit!\n", pawn);
            return 1;
        }
        if(i%2)
            x_score =x_score+eat;
        else
            o_score= o_score+ eat;
        if (eat){
            printf("Ho nice move! you got him...\n");
        }
        if (win(board,x_score,o_score)!=0) {
            if (win(board, x_score, o_score) == 1) {
                printf("Wooohooo! player X Won!\n");
                getchar();  //solution to buffer problem
            }
            else {
                printf("Wooohooo! player O Won!\n");
                getchar();  //solution to buffer problem
             }
            return 0;
        }
        i++;
    }
}

int play_single_turn(char board[][BOARD_SIZE], char pawn){
    int row_l, col_l, row_d, col_d;
    if(pawn=='X'){
        printf("Player X - Please enter pawn's location (row number followed by column number):\n");
        scanf("%d%d%*c", &row_l, &col_l );
        if (row_l == 999 || col_l == 999)
            return 999;

        while(!is_pawn_moveable(board, pawn, row_l, col_l) || (!is_location_legal(board,row_l,col_l,pawn))){ // Check if the player can move or location legal
            if ((!is_pawn_moveable(board, pawn, row_l, col_l)) && (is_location_legal(board, row_l, col_l, pawn))) // player can't move
                printf("This pawn has nowhere to move!\n");
            printf("Player X - Bad pawn's selection please enter pawn's location again:\n");
            scanf("%d%d*c", &row_l,&col_l);
            if (row_l==999 || col_l==999)
                return 999;
        }

        printf("Player X - Please enter pawn's destination (row number followed by column number):\n");
        scanf("%d%d", &row_d,&col_d);
        while (!is_move_legal(board,pawn,row_l,row_d,col_l,col_d)){
            printf("Player X - Bad pawn's destination please enter pawn's destination again:\n");
            scanf("%d %d", &row_d,&col_d);
        }
    }
    if(pawn=='O'){
        printf("Player O - Please enter pawn's location (row number followed by column number):\n");
        scanf("%d%d", &row_l,&col_l);
        if (row_l==999 || col_l==999)
            return 999;

        while(!is_pawn_moveable(board, pawn, row_l, col_l) || (!is_location_legal(board,row_l,col_l,pawn))) { //Check if the player can move or location legal
            if ((!is_pawn_moveable(board, pawn, row_l, col_l)) && (is_location_legal(board, row_l, col_l, pawn))) // player can't move
                printf("This pawn has nowhere to move!\n");
            printf("Player O - Bad pawn's selection please enter pawn's location again:\n");
            scanf("%d%d*c", &row_l, &col_l);
            if (row_l == 999 || col_l == 999)
                return 999;
        }

        printf("Player O - Please enter pawn's destination (row number followed by column number):\n");
        scanf("%d%d", &row_d,&col_d);
        while (!is_move_legal(board,pawn,row_l,row_d,col_l,col_d)) {
            printf("Player O - Bad pawn's destination please enter pawn's destination again:\n");
            scanf("%d %d", &row_d, &col_d);
        }
    }
    return arrange_board(board,pawn,row_l,row_d,col_l,col_d);
}

int is_location_legal(char board[][BOARD_SIZE], int row_l, int col_l, char pawn){
    //This function check if the input location is legal
    if (pawn =='X'){
        if (board[row_l][col_l] == 'X')
            return 1; // legal
        else
            return 0; // illegal
    }
    else{
        if (board[row_l][col_l] == 'O')
            return 1; // legal
        else
            return 0; // illegal

    }
}

int is_move_legal(char board[][BOARD_SIZE], char pawn, int row_l, int row_d, int col_l, int col_d) {
    if (row_d > 7 || row_d < 0 || col_d > 7 || col_d < 0) {
        return 0;
    }

    if (board[row_d][col_d] != '.')
        return 0;

    if (pawn == 'X') {
        if (row_d - row_l == 1 && ((col_l - col_d == 1) || (col_l - col_d == -1)) ||
            (row_d - row_l == 2 && (col_d - col_l == 2) && board[row_d - 1][col_l + 1] == 'O') ||
            (row_d - row_l == 2 && (col_d - col_l == -2) && board[row_d - 1][col_l - 1] == 'O')) {
            return 1;
        }
        else {
            return 0;
        }
    }

    if (pawn == 'O') {
        if (row_d - row_l == -1 && ((col_l - col_d == 1) || (col_l - col_d == -1)) ||
            (row_d - row_l == -2 && (col_d - col_l == 2) && board[row_l - 1][col_l + 1] == 'X') ||
            (row_d - row_l == -2 && (col_d - col_l == -2) && board[row_l - 1][col_l - 1] == 'X')){
            return 1;
        }
        else {
            return 0;
        }
    }
    return 0;
}


int arrange_board(char board[][BOARD_SIZE], char pawn, int row_l, int row_d, int col_l, int col_d){
    //This function is responsible for reordering the board after the move and returning as output whether the opponent has been eaten
    if (pawn == 'X') {
        board[row_d][col_d]= 'X';
        board[row_l][col_l]= '.';
        if (row_d - row_l == 2 && (col_d - col_l == 2) && board[row_d - 1][col_l + 1] == 'O') {
            board[row_d - 1][col_l + 1] = '.' ;
            return 1;
        }
        else if (row_d - row_l == 2 && (col_d - col_l == -2) && board[row_d - 1][col_l - 1] == 'O') {
            board[row_d - 1][col_l - 1] = '.';
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (pawn == 'O') {
        board[row_d][col_d] = 'O';
        board[row_l][col_l] = '.';
        if ((row_d - row_l == -2) && (col_d - col_l == 2) && board[row_l - 1][col_l + 1] == 'X') {
            // eat to right
            board[row_l - 1][col_l + 1] = '.';
            return 1;
        }
        else if (row_d - row_l == -2 && (col_d - col_l == -2) && board[row_l - 1][col_l - 1] == 'X') {
            // eat to left
            board[row_l - 1][col_l - 1] = '.' ;
            return 1;
        }
        else {
            return 0;
        }
    }
    return 0;
}

int is_pawn_moveable(char board[][BOARD_SIZE], char pawn, int row_l, int col_l){

    // check if X can move
    if (pawn == 'X') {
        return is_pawn_moveable_X(board, row_l, col_l);
    }

    // check if O can move
    if (pawn == 'O') {
        return is_pawn_moveable_O(board, row_l, col_l);
        }

    return 0; //not available
}

int is_pawn_moveable_X(char board[][BOARD_SIZE], int row_l, int col_l) {
    // check if reg step is available
    if (X_check_step(board, row_l, col_l) == 1){
        return 1; // available
    }

    // check if eat step is available
    if (X_check_eat(board, row_l , col_l) == 1){
        return 1; // available
    }
    return 0;
}

int is_pawn_moveable_O(char board[][BOARD_SIZE], int row_l, int col_l) {
    // check if reg step is available
    if (O_check_step(board, row_l, col_l) == 1){
        return 1; // available
    }

    // check if eat step is available
    if (O_check_eat(board, row_l , col_l) == 1){
        return 1; // available
    }
    return 0;
}

int X_check_step (char board[][BOARD_SIZE], int row_l, int col_l){
    // reg step to left
    if (col_l - 1 >= 0 && row_l + 1 < BOARD_SIZE) {
        if (board[row_l + 1][col_l - 1] == '.') {
            return 1; //available
        }
    }

    // reg step to right
    if (col_l + 1 < BOARD_SIZE  && row_l + 1 < BOARD_SIZE) {
        if (board[row_l + 1][col_l + 1] == '.') {
            return 1; //available
        }
    }
    return 0; // not available
}

int X_check_eat (char board[][BOARD_SIZE], int row_l, int col_l) {
    // available to eat to left
    if (row_l + 2 < BOARD_SIZE && col_l - 2 >= 0) {
        if (board[row_l + 1][col_l - 1] == 'O') {
            if (board[row_l + 2][col_l - 2] == '.') {
                return 1; //available
            }
        }
    }

    // available to eat to right
    if (row_l + 2 < BOARD_SIZE && col_l + 2 < BOARD_SIZE){
        if (board[row_l + 1][col_l + 1] == 'O') {
            if (board[row_l + 2][col_l + 2] == '.') {
                return 1; //available
            }
        }
    }
    return 0; // not available
}


int O_check_step (char board[][BOARD_SIZE], int row_l, int col_l){
    // reg step to left
    if (col_l - 1 >= 0 && row_l - 1 >= 0) {
        if (board[row_l - 1][col_l - 1] == '.') {
            return 1; //available
        }
    }

    // reg step to right
    if (col_l + 1 < BOARD_SIZE  && row_l - 1 >= 0) {
        if (board[row_l - 1][col_l + 1] == '.') {
            return 1; //available
        }
    }
    return 0; // not available
}

int O_check_eat (char board[][BOARD_SIZE], int row_l, int col_l){
    // available to eat to left
    if (row_l - 2 >= 0 && col_l - 2 >= 0) {
        if (board[row_l - 1][col_l - 1] == 'X') {
            if (board[row_l - 2][col_l - 2] == '.') {
                return 1; //available
            }
        }
    }

    // available to eat to right
    if (row_l - 2 >= 0 && col_l + 2 < BOARD_SIZE){
        if (board[row_l - 1][col_l + 1] == 'X') {
            if (board[row_l - 2][col_l + 2] == '.') {
                return 1; //available
            }
        }
    }
    return 0; //not available
}

int win(char board[][BOARD_SIZE], int x_score, int o_score){ //returns 1: X wins, 2: O wins, 0: nobody won
    int i;
    for(i=0 ; i<8; i++){
        if (board[0][i] == 'O')
            return 2;
        if (board[BOARD_SIZE-1][i] == 'X')
            return 1;
    }

    if (x_score == 12)
        return 1;
    else if (o_score == 12)
        return 2;
    else
        return 0;
}

int condition(char board[][BOARD_SIZE]){
    int ans;
    print_board(board);
    printf("Would you like to play another game?(y\\n)\n");
    ans = getchar();

    while((ans != 'y')&&(ans != 'Y')&&(ans != 'n')&&(ans != 'N')){  //while answer isn't y/n
        while (getchar() != '\n');  //clear buffer
        printf("Would you like to play another game?(y\\n)\n");
        ans = getchar();
    }

    while (getchar() != '\n'); //clear buffer
    if ((ans == 'n')||(ans == 'N')) {
        return 0;
    }
    //if ((ans == 'y')||(ans == 'Y'))
    else
        return 1;
}






