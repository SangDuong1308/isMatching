#include "UI.h"

int Rand(int l, int r)
{
    return rand() % (r - l + 1) + l;
}
struct Node
{
    int data;
    Node *next;
};

typedef struct Node *node;

node makeNode(int x)
{
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

struct position
{
    int x;
    int y;
};

struct pikachu
{
    position pos;
    position pre_pos;
    char value = ' ';
    int turn = 0;
    bool status = true;
};

void Push(queue <pikachu> q[101], int size, int i, int j, pikachu temp)
{
    if (temp.status == false)
    {
        temp.pre_pos.x = i;
        temp.pre_pos.y = j;
        q[i * size + j].push(temp);
    }
}

void Build(pikachu** board, int size, queue<pikachu> q[101])
{
    for (int i = 0; i < size + 2; i++)
    {
        for (int j = 0; j < size + 2; j++)
        {
            if (i - 1 >= 0)
            {
                Push(q, size + 2, i, j, board[i - 1][j]);
            }
            if (i + 1 <= size + 1)
            {
                Push(q, size + 2, i, j, board[i + 1][j]);
            }
            if (j - 1 >= 0)
            {
                Push(q, size + 2, i, j, board[i][j - 1]);
            }
            if (j + 1 <= size + 1)
            {
                Push(q, size + 2, i, j, board[i][j + 1]);
            }
        }
    }
}

int Turn(int x, int y, pikachu p)
{
    if (x == p.pos.x || y == p.pos.y)
    {
        return 0;
    }
    else
    {
        return 1;
    }    
}

// GenerateBoard
pikachu** SetMapPointer(int size)
{
    pikachu** board = new pikachu * [size + 2];
    for (int i = 0; i < size + 2; i++)
    {
        board[i] = new pikachu[size + 2];
    }

    //  Create the border
    for (int i = 0; i < size + 2; i++)
    { 
        for (int j = 0; j < size + 2; j++)
        {
            board[i][j].value = ' ';
            board[i][j].pos.x = i;
            board[i][j].pos.y = j;
            if (i == 0 || j == 0 || i == size + 1 || j == size + 1) // Border
            {
                board[i][j].status = false;
            }
        }
    }

    srand((int)time(0));

    // Generate Board
    int count = 0;
    while (count != size * size)
    {
        int column, row;
        char a = char('A' + char(rand() % 26));
        for (int i = 1; i <= 2; i++)
        {
            do
            {
                column = rand() % size + 1;
                row = rand() % size + 1;

            } while (board[column][row].value != ' ');
            board[column][row].value = a;
            count++;
        }
    }
    return board;

}

bool isMatching(pikachu **&board, int size, int I_x, int I_y, int F_x, int F_y)
{
    if (board[I_x][I_y].status == 0 || board[F_x][F_y].status == 0)
    {
        return 0;
    }
    if (board[I_x][I_y].value != board[F_x][F_y].value || (I_x == F_x && I_y == F_y))
    {
        return 0;
    }
    board[F_x][F_y].status = 0;

    queue<pikachu> q[65];
    Build(board, size, q);

    int *dd = new int[(size + 2) * (size + 2)];
    for (int i = 0; i < (size + 2) * (size + 2); i++)
    {
        dd[i] = 0;
    }
    while (!q[I_x * (size + 2) + I_y].empty())
    {
        pikachu temp = q[I_x * (size + 2) + I_y].front();
        if (!temp.status)
        {
            if (temp.pos.x == F_x && temp.pos.y == F_y && temp.turn <= 2)
            {
                board[I_x][I_y].status = 0;
                return 1;
            }
            q[I_x * (size + 2) + I_y].pop();

            int u = temp.pos.x;
            int v = temp.pos.y;
            int pre_x = temp.pre_pos.x;
            int pre_y = temp.pre_pos.y;
            dd[u * (size + 2) + v] = 1;
            int N = q[u * (size + 2) + v].size();
            for (int i = 0; i < N; i++)
            {
                pikachu p = q[u * (size + 2) + v].front();

                if (dd[p.pos.x * (size + 2) + p.pos.y] == 0)
                {

                    if (p.status == 0)
                    {
                        p.turn = temp.turn + Turn(pre_x, pre_y, p);

                        if (p.turn <= 2)
                        {

                            q[I_x * (size + 2) + I_y].push(p);
                        }
                    }
                }
                q[u * (size + 2) + v].pop();
            }
        }
    }
    delete[] dd;
    board[F_x][F_y].status = 1;
    return 0;
}

void printBoard(pikachu**& board, int size)
{
    for (int i = 0; i < size + 2; i++)
    {
        for (int j = 0; j < size + 2; j++)
        {
            if (board[i][j].status)
            {
                ui.printbox(j, i, board[i][j].value);
            }
        }
    }
}

void playGame(pikachu**& board, int size)
{
    int current_x = 0, current_y = 0;
    int chosen_x = -1, chosen_y = -1;
    int pikachu_unchecked = size * size;
    printBoard(board, size);
    console.SetColor(7, 0);
    ui.printbox(current_x + 1, current_y + 1, board[current_y + 1][current_x + 1].value);
    console.SetColor(0, 7);
    while (pikachu_unchecked)
    {
        char c = sp;
        int temp_x = current_x, temp_y = current_y;
        if (chosen_x != -1 && chosen_y != -1)
        {
            console.SetColor(9, 0);
            ui.printbox(chosen_x + 1, chosen_y + 1, board[chosen_y + 1][chosen_x + 1].value);
            console.SetColor(0, 7);
        }

        if (board[current_y + 1][current_x + 1].status == 0)
            ui.printEmptyBox(current_x + 1, current_y + 1);

        switch (c)
        {
        case 'A':
        case 'a':
        case KEY_LEFT:
            if (current_x - 1 >= 0)
            {
                current_x--;
            }
            if (board[temp_y + 1][temp_x + 1].status == 0)
            {
                ui.printEmptyBox(temp_x + 1, temp_y + 1);
            }
            else
            {
                console.SetColor(0, 7);
                ui.printbox(temp_x + 1, temp_y + 1, board[temp_y + 1][temp_x + 1].value);
            }

            if (board[current_y + 1][current_x + 1].status != 0)
            {
                console.SetColor(7, 0);
                ui.printbox(current_x + 1, current_y + 1, board[current_y + 1][current_x + 1].value);
                console.SetColor(0, 7);
            }
            else
            {
                console.SetColor(7, 0);
                ui.printEmptyBox(current_x + 1, current_y + 1);
                console.SetColor(0, 7);
            }

            break;
        case 'D':
        case 'd':
        case KEY_RIGHT:
            if (current_x + 1 <= size - 1)
                current_x++;
            if (board[temp_y + 1][temp_x + 1].status == 0)
                ui.printEmptyBox(temp_x + 1, temp_y + 1);
            else
            {
                console.SetColor(0, 7);
                ui.printbox(temp_x + 1, temp_y + 1, board[temp_y + 1][temp_x + 1].value);
            }
            if (board[current_y + 1][current_x + 1].status != 0)
            {
                console.SetColor(7, 0);
                ui.printbox(current_x + 1, current_y + 1, board[current_y + 1][current_x + 1].value);
                console.SetColor(0, 7);
            }
            else
            {
                console.SetColor(7, 0);
                ui.printEmptyBox(current_x + 1, current_y + 1);
                console.SetColor(0, 7);
            }

            break;
        case 'S':
        case 's':
        case KEY_DOWN:
            if (current_y + 1 <= size - 1)
                current_y++;

            if (board[temp_y + 1][temp_x + 1].status == 0)
                ui.printEmptyBox(temp_x + 1, temp_y + 1);
            else
            {
                console.SetColor(0, 7);
                ui.printbox(temp_x + 1, temp_y + 1, board[temp_y + 1][temp_x + 1].value);
            }

            if (board[current_y + 1][current_x + 1].status != 0)
            {
                console.SetColor(7, 0);
                ui.printbox(current_x + 1, current_y + 1, board[current_y + 1][current_x + 1].value);
                console.SetColor(0, 7);
            }
            else
            {
                console.SetColor(7, 0);
                ui.printEmptyBox(current_x + 1, current_y + 1);
                console.SetColor(0, 7);
            }

            break;
        case 'W':
        case 'w':
        case KEY_UP:
            if (current_y - 1 >= 0)
                current_y--;

            if (board[temp_y + 1][temp_x + 1].status == 0)
                ui.printEmptyBox(temp_x + 1, temp_y + 1);
            else
            {
                console.SetColor(0, 7);
                ui.printbox(temp_x + 1, temp_y + 1, board[temp_y + 1][temp_x + 1].value);
            }

            if (board[current_y + 1][current_x + 1].status != 0)
            {
                console.SetColor(7, 0);
                ui.printbox(current_x + 1, current_y + 1, board[current_y + 1][current_x + 1].value);
                console.SetColor(0, 7);
            }
            else
            {
                console.SetColor(7, 0);
                ui.printEmptyBox(current_x + 1, current_y + 1);
                console.SetColor(0, 7);
            }

            break;
        case KEY_ENTER:
            if (board[current_y + 1][current_x + 1].status)
            {
                console.SetColor(9, 0);
                ui.printbox(current_x + 1, current_y + 1, board[current_y + 1][current_x + 1].value);
                console.SetColor(0, 7);
            }
            else
            {
                console.SetColor(7, 0);
                ui.printEmptyBox(current_x + 1, current_y + 1);
                console.SetColor(0, 7);
                break;
            }

            if (chosen_x != -1 && chosen_y != -1)

                if (isMatching(board, size, current_y + 1, current_x + 1, chosen_y + 1, chosen_x + 1) && board[current_y + 1][current_x + 1].value == board[chosen_y + 1][chosen_x + 1].value && !(current_x == chosen_x && chosen_y == current_y))
                {
                    Sleep(400);
                    pikachu_unchecked -= 2;
                    console.SetColor(2, 0);
                    ui.printbox(chosen_x + 1, chosen_y + 1, board[chosen_y + 1][chosen_x + 1].value);
                    ui.printbox(current_x + 1, current_y + 1, board[current_y + 1][current_x + 1].value);
                    console.SetColor(0, 7);

                    Sleep(200);
                    ui.printEmptyBox(chosen_x + 1, chosen_y + 1);
                    ui.printEmptyBox(current_x + 1, current_y + 1);

                    board[current_y + 1][current_x + 1].status = board[chosen_y + 1][chosen_x + 1].status = 0;
                    chosen_x = chosen_y = -1;

                    console.SetColor(7, 0);
                    ui.printEmptyBox(current_x + 1, current_y + 1);
                    console.SetColor(0, 7);
                    if (!pikachu_unchecked)
                    {
                        system("cls");
                        ui.PrintAfterCompleteGame();
                        cout<<endl;
                    }
                }
                else
                {
                    Sleep(200);

                    console.SetColor(4, 0);
                    ui.printbox(chosen_x + 1, chosen_y + 1, board[chosen_y + 1][chosen_x + 1].value);
                    ui.printbox(current_x + 1, current_y + 1, board[current_y + 1][current_x + 1].value);
                    console.SetColor(0, 7);

                    Sleep(800);

                    ui.printbox(chosen_x + 1, chosen_y + 1, board[chosen_y + 1][chosen_x + 1].value);
                    console.SetColor(7, 0);
                    ui.printbox(current_x + 1, current_y + 1, board[current_y + 1][current_x + 1].value);
                    console.SetColor(0, 7);

                    chosen_x = chosen_y = -1;
                }
            else
            {
                chosen_x = current_x;
                chosen_y = current_y;
            }
            break;
        default:
            if (board[current_y + 1][current_x + 1].status != 0)
            {
                console.SetColor(7, 0);
                ui.printbox(current_x + 1, current_y + 1, board[current_y + 1][current_x + 1].value);
                console.SetColor(0, 7);
            }
            else
            {
                console.SetColor(7, 0);
                ui.printEmptyBox(current_x + 1, current_y + 1);
                console.SetColor(0, 7);
            }
            break;
        }
    }
    system("cls");
    ui.PrintAfterCompleteGame();
    cout<<endl;
}

void LevelMenu(pikachu **&board)
{
    int choice = 1;
    console.SetColor(6,0);
    ui.printEasy();
    console.SetColor(0,7);
    ui.printMedium();
    ui.printHard();
    ui.printExit2();
    while (true)
    {
        if (choice == 1)
        {
            console.SetColor(6,0);
            ui.printEasy();
            console.SetColor(0,7);
            ui.printMedium();
            ui.printHard();
            ui.printExit2();
        }
        if (choice == 2)
        {
            console.SetColor(6,0);
            ui.printMedium();
            console.SetColor(0,7);
            ui.printEasy();
            ui.printHard();
            ui.printExit2();
        }
        if (choice == 3)
        {
            console.SetColor(6,0);
            ui.printHard();
            console.SetColor(0,7);
            ui.printEasy();
            ui.printMedium();
            ui.printExit2();
        }
        if (choice == 4)
        {
            console.SetColor(6,0);
            ui.printExit2();
            console.SetColor(0,7);
            ui.printEasy();
            ui.printMedium();
            ui.printHard();
        }

        char c = sp;
        switch (c)
        {
        case 'S':
        case 's':
        case KEY_DOWN:
            if (choice == 1)
            {
                console.SetColor(6, 0);
                ui.printMedium();
                console.SetColor(0, 7);
                choice = 2;
                break;
            }
            if (choice == 2)
            {
                console.SetColor(6, 0);
                ui.printHard();
                console.SetColor(0, 7);
                choice = 3;
                break;
            }
            if (choice == 3)
            {
                console.SetColor(6, 0);
                ui.printExit2();
                console.SetColor(0, 7);
                choice = 4;
                break;
            }
            if (choice == 4)
            {
                console.SetColor(6, 0);
                ui.printEasy();
                console.SetColor(0, 7);
                choice = 1;
                break;
            }
            break;
        case 'W':
        case 'w':
        case KEY_UP:
            if (choice == 1)
            {
                console.SetColor(6, 0);
                ui.printExit2();
                console.SetColor(0, 7);
                choice = 4;
                break;
            }
            if (choice == 2)
            {
                console.SetColor(6, 0);
                ui.printEasy();
                console.SetColor(0, 7);
                choice = 1;
                break;
            }
            if (choice == 3)
            {
                console.SetColor(6, 0);
                ui.printMedium();
                console.SetColor(0, 7);
                choice = 2;
                break;
            }
            if (choice == 4)
            {
                console.SetColor(6, 0);
                ui.printHard();
                console.SetColor(0, 7);
                choice = 3;
                break;
            }
            break;
        case 13:
            if (choice == 1)
            {
                system("cls");
                pikachu** board= SetMapPointer(4);
                playGame(board,4);
                return;
            };
            if (choice == 2)
            {
                system("cls");
                pikachu** board= SetMapPointer(6);
                playGame(board,6);
                return;      
            }
            if (choice == 3)
            {
                system("cls");
                pikachu** board= SetMapPointer(8);
                playGame(board,8);
                return;
            }
            if (choice == 4)
            {
                system("cls");
                ui.printWhenExit();
                system("pause");
                return;
            }
            break;
        }
    }
}

void Menu(pikachu **&board)
{
    ui.PrintTheGameName();
    int choice = 1;
    while (true)
    {
        ui.printStart();
        ui.printExit();
        if (choice == 1)
        {
            console.SetColor(6, 0);
            ui.printStart();
            console.SetColor(0, 7);
            ui.printExit();
        }
        if (choice == 2)
        {
            console.SetColor(6, 0);
            ui.printExit();
            console.SetColor(0, 7);
            ui.printStart();
        }
        char c = sp;
        switch (c)
        {
        case 'S':
        case 's':
        case 80:
            if (choice == 1)
            {
                console.SetColor(6, 0);
                ui.printExit();
                console.SetColor(0, 7);
                choice = 2;
                break;
            }
            if (choice == 2)
            {
                console.SetColor(6, 0);
                ui.printStart();
                console.SetColor(0, 7);
                choice = 1;
            }
            break;
        case 'W':
        case 'w':
        case 72:
            if (choice == 1)
            {
                console.SetColor(6, 0);
                ui.printExit();
                console.SetColor(0, 7);
                choice = 2;
                break;
            }
            if (choice == 2)
            {
                console.SetColor(6, 0);
                ui.printStart();
                console.SetColor(0, 7);
                choice = 1;
            }
            break;
        case 13:
            if (choice == 1)
            {
                system("cls");
                LevelMenu(board);
                return;
            }
            if (choice == 2)
            {
                system("cls");
                ui.printWhenExit();
                system("pause");
                return;
            }
            break;
        }
    }   
}