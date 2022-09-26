#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

FILE *saves;

typedef struct block{
    int index;
    struct block *next;
}block;

typedef struct order{
    int ch1, ch2;
    struct order *next;
}order;

void addHistory(order *history, int ch1, int ch2){
    order *new = malloc(sizeof(order));
    printw("1");
    new->ch1 = ch1;
    new->ch2 = ch2;
    new->next = history->next;
    history->next = new;
    printw("2");
}

block *newblock(int index){
    block *new = malloc(sizeof(block));
    new->index = index;
    new->next = NULL;
    return new;
}

void init(block *head, int n){
    for(int i = 1; i <= n; i++){
        head->next = newblock(i);
        head = head->next;
    }
}

int moveBlock(block *first, block *second){
    block *temp = first->next;
    if(first->next == NULL){
        return 1;
    }
    if(second->next != NULL){
        if(first->next->index > second->next->index)
            return 2;
    }
    first->next = first->next->next;
    temp->next = second->next;
    second->next = temp;
    return 0;
}

int blockHeight(block *head){
    int i = 0;
    while(head->next != NULL){
        i++;
        head = head->next;
    }
    return i;
}

int displayMenu(){
    int ch;
    printw("P to play\nS to load save\nQ to exit\n");
    while(1){
        noecho();
        ch = getch();
        switch(ch){
            case 'p':
                clear();
                refresh();
                return 1;
                break;
            case 'q':
                return 0;
                break;
            case 's':
                clear();
                refresh();
                return 2;
                break;
        }
    }
}

void deleteList(block *head){
    head->next = NULL;
}

int displayChoice(block *left, block *mid, block *right){
    int ch, n = 3;
    deleteList(mid);
    deleteList(right);
    while(1){
        printw("Press W and S to choose number of blocks: %d\nPress ENTER to confirm\n", n);
        noecho();
        ch = getch();
        switch(ch){
            case 'w':
                n++; break;
            case 's':
                n--; break;
            case 10:
                clear();
                refresh();
                init(left, n);
                return n;
        }
        if(n < 3)n = 3;
        if(n > 25)n = 25;
        clear();
        refresh();
    }
}

void displayTowers(int n, block *left, block *mid, block *right, int returnValue){
    int x = 6 * n + 2;
    int y = n + 2;
    char *display[y];
    for(int i = 0; i < y; i++){
        display[i] = malloc(x * sizeof(char));
    }
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            display[i][j] = ' ';
        }
    }
    int heightLeft = blockHeight(left),
    heightMid = blockHeight(mid),
    heightRight = blockHeight(right);
    x = n + 1;
    for(int i = 0; i <= n; i++){
        display[i][x] = '|';
    }
    for(int i = 0; i < heightLeft; i++){
        left = left->next;
        for(int j = 0; j < left->index; j++){
            display[y - 1 - heightLeft + i][x + j] = display[y - 1 - heightLeft + i][x - j]= '#';
        }
    }
    display[y - 1][x] = '1';
    x = 3 * n + 1;
    for(int i = 0; i <= n; i++){
        display[i][x] = '|';
    }
    for(int i = 0; i < heightMid; i++){
        mid = mid->next;
        for(int j = 0; j < mid->index; j++){
            display[y - 1 - heightMid + i][x + j] = display[y - 1 - heightMid + i][x - j]= '#';
        }
    }
    display[y - 1][x] = '2';
    x = 5 * n + 1;
    for(int i = 0; i <= n; i++){
        display[i][x] = '|';
    }
    for(int i = 0; i < heightRight; i++){
        right = right->next;
        for(int j = 0; j < right->index; j++){
            display[y - 1 - heightRight + i][x + j] = display[y - 1 - heightRight + i][x - j]= '#';
        }
    }
    display[y - 1][x] = '3';
    x = 6 * n + 3;
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x - 1; j++){
            if(display[i][j] == '#'){
                attron(COLOR_PAIR(1));
                printw("#");
                attroff(COLOR_PAIR(1));
            }else
            printw("%c", display[i][j]);
        }
        printw("\n");
    }
    switch(returnValue){
        default:
            printw("\n");
            break;
        case 1:
            printw("This tower does not have any blocks\n");
            break;
        case 2:
            printw("You can't put this block here\n");
            break;
    }
    printw("U to undo\nR to restart\nS to save\nQ to go back to menu\n\n");
    for(int i = 0; i < y; i++){
        free(display[i]);
    }
}

void fprintno(FILE *saves, int index){
    if(index < 10){
        fprintf(saves, "0%d", index);
    }else
    fprintf(saves, "%d",index);
}

int playTowers(int n, block *left, block *mid, block *right){
    int ch1, ch2, returnValue, key = 1;
    order *history = malloc(sizeof(order));
    while(key){
        displayTowers(n, left, mid, right, returnValue);
        echo();
        ch1 = getch();
        switch(ch1){
        case 49:
            ch2 = getch();
            if(ch2 == 50){
                returnValue = moveBlock(left, mid);
                if(!returnValue)
                addHistory(history, ch1, ch2);
            }
            if(ch2 == 51){
                returnValue = moveBlock(left, right);
                if(!returnValue)
                addHistory(history, ch1, ch2);
            }
            break;
        case 50:
            ch2 = getch();
            if(ch2 == 49){
                returnValue = moveBlock(mid, left);
                if(!returnValue)
                addHistory(history, ch1, ch2);
            }
            if(ch2 == 51){
                returnValue = moveBlock(mid, right);
                if(!returnValue)
                addHistory(history, ch1, ch2);
            }
            break;
        case 51:
            ch2 = getch();
            if(ch2 == 49){
                returnValue = moveBlock(right, left);
                if(!returnValue)
                addHistory(history, ch1, ch2);
            }
            if(ch2 == 50){
                returnValue = moveBlock(right, mid);
                if(!returnValue)
                addHistory(history, ch1, ch2);
            }
            break;
        case 'q':
            key = 0;
            deleteList(left);
            deleteList(mid);
            deleteList(right);
            break;
        case 'u':
            if(history->next == NULL)break;
            ch1 = history->next->ch2;
            ch2 = history->next->ch1;
            history->next = history->next->next;
            switch(ch1){
                case 49:
                    if(ch2 == 50)moveBlock(left, mid);
                    if(ch2 == 51)moveBlock(left, right);
                    break;
                case 50:
                    if(ch2 == 49)moveBlock(mid, left);
                    if(ch2 == 51)moveBlock(mid, right);
                    break;
                case 51:
                    if(ch2 == 49)moveBlock(right, left);
                    if(ch2 == 50)moveBlock(right, mid);
                    break;
            }
            break;
        case 'r':
            deleteList(left);
            deleteList(mid);
            deleteList(right);
            init(left, n);
            break;
        case 's':
            history->next = NULL;
            key = 0;
            saves = fopen("saves.txt", "w");
            fprintno(saves, n);
            while(left->next != NULL){
                left = left->next;
                fprintno(saves, left->index);
            }
            fprintf(saves, ",");
            while(mid->next != NULL){
                mid = mid->next;
                fprintno(saves, mid->index);
            }
            fprintf(saves, ",");
            while(right->next != NULL){
                right = right->next;
                fprintno(saves, right->index);
            }
            fprintf(saves, ",");
            fclose(saves);
            break;
        }
        clear();
        refresh();
    }
    return 0;
}

int returnInt(char a, char b){
    a -= 48;
    b -= 48;
    return ((int)a) * 10 + (int)b;
}

int displaySaves(FILE *saves, block *left, block *mid, block *right){
    saves = fopen("saves.txt", "r");
    char *text = malloc(100 *sizeof(char));
    //rewind(saves);
    fscanf(saves, "%s", text);
    if(!strlen(text)){
        printw("Save one game first!!!\n\nPress any key to continue\n\n");
        return 1;
    }
    int n = returnInt(text[0], text[1]), index;
    int i = 2;
    while(text[i] != ','){
        index = returnInt(text[i], text[i + 1]);
        left->next = newblock(index);
        left = left->next;
        i += 2;
    }
    i++;
    while(text[i] != ','){
        index = returnInt(text[i], text[i + 1]);
        mid->next = newblock(index);
        mid = mid->next;
        i += 2;
    }
    i++;
    while(text[i] != ','){
        index = returnInt(text[i], text[i + 1]);
        right->next = newblock(index);
        right = right->next;
        i += 2;
    }
    fclose(saves);
    free(text);
    return n;
}

int main(){
    block *left = malloc(sizeof(block)),
    *mid = malloc(sizeof(block)),
    *right = malloc(sizeof(block));
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    int n;
    int ch = 1;
    while(1){
        ch = displayMenu();
        if(ch == 1){
            n = displayChoice(left, mid, right);
            playTowers(n, left, mid, right);
        }else
        if(ch == 2){
            n = displaySaves(saves, left, mid, right);
            if(n == 1){
                getch();
                refresh();
                clear();
            }else
            playTowers(n, left, mid, right);
        }
        else break;
    }
    endwin();
    return 0;
}