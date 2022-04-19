#include "Console.h"

// Ham in giao dien cho Game
struct UI{

    void PrintTheGameName()
    {
        system("cls");
        console.GotoXY(25,0);
        console.SetColor(0,9);
        cout << "                                  ,'\\";
        console.GotoXY(25,1);
        cout << "    _.----.        ____         ,'  _\\   ___    ___     ____" ;
        console.GotoXY(25,2);
        console.SetColor(0,10);
        cout << "_,-'       `.     |    |  /`.  \\,-'     |   \\  /   |   |    \\  |` ." ;
        console.GotoXY(25,3);
        cout << "\\     __     \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |" ;
        console.GotoXY(25,4);
        console.SetColor(0,15);
        cout << " \\.   \\ \\    |  __  |  |/    ,','_  `.  |          | __  |    \\|  |" ;
        console.GotoXY(25,5);
        cout << "   \\   \\/    /,' _`.|      ,' / / / /   |          ,' _`.|     |  |" ;
        console.GotoXY(25,6);
        console.SetColor(0,6);
        cout << "    \\     ,-'/  /   \\    ,'  |  \\/ / ,`.|         /  /   \\  |     |" ;
        console.GotoXY(25,7);
        cout << "     \\    \\ |   \\_/  |   `-.  \\    `' / |  |    ||   \\_/  | |\\    |" ;
        console.GotoXY(25,8);
        console.SetColor(0,13);
        cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |" ;
        console.GotoXY(25,9);
        cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |" ;
        console.GotoXY(25,10);
        console.SetColor(0,14);
        cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |" ;
        console.GotoXY(25,11);
        cout << "                                `'                            '-._|" ;
        console.SetColor(0,7);

    }

    void PrintAfterCompleteGame()
    {
        console.GotoXY(20,7);
        console.SetColor(0,12);
        cout<<"                                         _           _";    
        console.GotoXY(20,8);  
        console.SetColor(0,5);
        cout<<"                                        ( )_        | |";        
        console.GotoXY(20,9);
        console.SetColor(0,13);
        cout<<"   ___    _     ___     __   _ __   _ _ | ,_)  ___  | |";
        console.GotoXY(20,10); 
        console.SetColor(0,6);  
        cout<<" /'___) /'_`\\ /' _ `\\ /'_ `\\( '__)/'_` )| |  /',__) | |";   
        console.GotoXY(20,11);
        console.SetColor(0,14);
        cout<<"( (___ ( (_) )| ( ) |( (_) || |  ( (_| || |_ \\__, \\ |_| "; 
        console.GotoXY(20,12); 
        console.SetColor(0,7); 
        cout<<"`\\____)`\\___/'(_) (_)`\\__  |(_)  `\\__,_)`\\__)(____/ |_|"; 
        console.GotoXY(20,13); 
        console.SetColor(0,15); 
        cout<<"                     ( )_) |                   "; 
        console.GotoXY(20,14);    
        cout<<"                      \\___/'                    "; 
        console.SetColor(0,7);

        console.GotoXY(82,3);
        console.SetColor(0,1);
        cout<<"`;-.          ___, ";
        console.GotoXY(82,4);
        console.SetColor(0,2);
        cout<<"  `.`\\_...._/`.-\"`  ";
        console.GotoXY(82,5);
        console.SetColor(0,3);
        cout<<"   \\        /      , ";
        console.GotoXY(82,6);
        //console.SetColor(0,4);
        cout<<"    /()   () \\    .' `-._ ";
        console.GotoXY(82,7);
        console.SetColor(0,5);
        cout<<"   |)  .    ()\\  /   _.' ";
        console.GotoXY(82,8);
        console.SetColor(0,6);
        cout<<"   \\  -'-     ,; '. < ";
        console.GotoXY(82,9);
        console.SetColor(0,7);
        cout<<"    ;.__     ,;|   > \\ ";
        console.GotoXY(82,10);
        console.SetColor(0,8);
        cout<<"   / ,    / ,  |.-'.-' ";
        console.GotoXY(82,11);
        console.SetColor(0,9);
        cout<<"  (_/    (_/ ,;|.<` ";
        console.GotoXY(82,12);
        console.SetColor(0,10);
        cout<<"    \\    ,     ;-` ";
        console.GotoXY(82,13);
        console.SetColor(0,11);
        cout<<"     >   \\    / ";
        console.GotoXY(82,14);
        console.SetColor(0,12);
        cout<<"    (_,-'`> .' ";
        console.GotoXY(82,15);
        console.SetColor(0,13);
        cout<<"         (_,' ";
        console.SetColor(0,7);

    }

    void printStart()
    {
        console.GotoXY(49, 14);
        //console.SetColor(0,9);
        cout << " ===================== ";
        console.GotoXY(49, 15);
        //console.SetColor(0,10);
        cout << "|                     |";
        console.GotoXY(49, 16);
        cout << "|        START        |";
        console.GotoXY(49, 17);
        cout << "|                     |";
        console.GotoXY(49, 18);
        //console.SetColor(0,9);
        cout << " ===================== ";
        //console.SetColor(0,7);
    }

    void printExit()
    {
        console.GotoXY(49, 21);
        //console.SetColor(0,9);
        cout << " ===================== ";
        console.GotoXY(49, 22);
        //console.SetColor(0,10);
        cout << "|                     |";
        console.GotoXY(49, 23);
        cout << "|         EXIT        |";
        console.GotoXY(49, 24);
        cout << "|                     |";
        console.GotoXY(49, 25);
        //console.SetColor(0,9);
        cout << " ===================== ";
        //console.SetColor(0,7);
    }

    void printWhenExit()
    {
        console.GotoXY(28,7);
        console.SetColor(0,9);
        cout<<"  ________                  ._____________   "  ;  
        console.GotoXY(28,8);   
        cout<<" /  _____/  ____   ____   __| _/\\______   \\___.__. ____   ";
        console.GotoXY(28,9);
        console.SetColor(0,15);
        cout<<"/   \\  ___ /  _ \\ /  _ \\ / __ |  |    |  _<   |  |/ __ \\  ";
        console.GotoXY(28,10);
        cout<<"\\    \\_\\  (  <_> |  <_> ) /_/ |  |    |   \\\\___   \\ ___/  ";
        console.GotoXY(28,11);
        console.SetColor(0,10);
        cout<<" \\______  /\\____/ \\____/\\____ |  |______  // ____| \\_  > ";
        console.GotoXY(28,12);
        cout<<"        \\/                   \\/         \\/ \\/        \\/  ";
        console.SetColor(0,7);
    }

    void printEasy()
    {
        console.GotoXY(49, 4);
        //console.SetColor(0,9);
        cout << " ===================== ";
        console.GotoXY(49, 5);
        //console.SetColor(0,10);
        cout << "|                     |";
        console.GotoXY(49, 6);
        cout << "|        EASY         |";
        console.GotoXY(49, 7);
        cout << "|                     |";
        console.GotoXY(49, 8);
        //console.SetColor(0,9);
        cout << " ===================== ";
        //console.SetColor(0,7);
    }

    void printMedium()
    {
        console.GotoXY(49, 10);
        //console.SetColor(0,9);
        cout << " ===================== ";
        console.GotoXY(49, 11);
        //console.SetColor(0,10);
        cout << "|                     |";
        console.GotoXY(49, 12);
        cout << "|       MEDIUM        |";
        console.GotoXY(49, 13);
        cout << "|                     |";
        console.GotoXY(49, 14);
        //console.SetColor(0,9);
        cout << " ===================== ";
        //console.SetColor(0,7);
    }

    void printHard()
    {
        console.GotoXY(49, 16);
        //console.SetColor(0,9);
        cout << " ===================== ";
        console.GotoXY(49, 17);
        //console.SetColor(0,10);
        cout << "|                     |";
        console.GotoXY(49, 18);
        cout << "|        HARD         |";
        console.GotoXY(49, 19);
        cout << "|                     |";
        console.GotoXY(49, 20);
        //console.SetColor(0,9);
        cout << " ===================== ";
        //console.SetColor(0,7);
    }

    void printExit2()
    {
        console.GotoXY(49, 22);
        //console.SetColor(0,9);
        cout << " ===================== ";
        console.GotoXY(49, 23);
        //console.SetColor(0,10);
        cout << "|                     |";
        console.GotoXY(49, 24);
        cout << "|        EXIT         |";
        console.GotoXY(49, 25);
        cout << "|                     |";
        console.GotoXY(49, 26);
        //console.SetColor(0,9);
        cout << " ===================== ";
        //console.SetColor(0,7);
    }

    // generate a box with value inside
    void printbox(int i, int j, char x)
    {
        console.GotoXY(i*10, j*5);
        cout << " ------- ";
        console.GotoXY(i*10, j*5 + 1);
        cout << "|       |";
        console.GotoXY(i*10, j*5 + 2);
        cout << "|   " << x << "   |";
        console.GotoXY(i*10, j*5 + 3);
        cout << "|       |";
        console.GotoXY(i*10, j*5 + 4);
        cout << " ------- ";
    }

    // generate a empty box
    void printEmptyBox(int i,int j)
    {
        console.GotoXY(i*10, j*5);
        cout << "         ";
        console.GotoXY(i*10, j*5 + 1);
        cout << "         ";
        console.GotoXY(i*10, j*5 + 2);
        cout << "         ";
        console.GotoXY(i*10, j*5 + 3);
        cout << "         ";
        console.GotoXY(i*10, j*5 + 4);
        cout << "         ";
    }

    void ShowCredit()
    {
        system("cls");
        console.changecolour(14);
        // GotoXY(45,5);
        cout << "The game was created by: " << endl;
        console.changecolour(15);
        cout << "Student 1: Duong Phuoc Sang" << endl;
        // GotoXY(45,6);
        cout << "MSSV: 21127157" << endl;
        // GotoXY(45,7);
        cout << "Student 2: Trinh Hoang An" << endl;
        // GotoXY(45,8);
        cout << "MSSV: 21127577" << endl;
        console.changecolour(7);
        cout << "PRESS ANY KEY TO RETURN MENU GAME...";
        sp;
    }

} ui;