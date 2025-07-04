#include <bits/stdc++.h>
using namespace std;
#include <graphics.h>

//for the button and field
#include "ui.h"
//#include "tree.h"

//Below are the functions that will run in the application
//function age pore likhsi bole age theke ekhane define kore disi

void drawwwwwwww();

void get_ans();
void ar_input();//arithmetic expression
void regex_input();

//void loading();
void about_us();//it is the about us page
void exit();
void menu();
void info_start();
void Header();
void Footer();
bool isOperator();


void frame()
{
    //cleardevice() is a function of graphics which clears the screen
    cleardevice();
    //Frame Start
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(0, 0, 15, 505);//For Left Side
    bar(785, 0, 800, 505);//For Right Side
    bar(15, 0, 800, 15);//For Top Side
    bar(0, 505, 800, 520);//For Bottom Side
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(16, 16, 784, 504);//For Middle rectangle
    //Frame End
}

char name[200] = "";
char cpyname[200]="";
char exp1[200] = "";


void type_till_go(){}
// void type_till_go()
// {
//     cleardevice();
//     frame();
//     //for generating random time; time(0) - passing 0 for generating the current time
//     srand(time(0));

//     clock_t begin = clock();
//     double time_spent = 0.0;
//     settextstyle(4, 0, 3);//void settextstyle(int font, int direction, int font_size);


//     setcolor(WHITE);
//     rectangle(17, 150, 783, 150);//To remove bottom line of rectangular area
//     setcolor(BLACK);
//     rectangle(200, 150, 600, 150);//To print a line

//     Button back_button(15, 350, 250, 460, MAGENTA, "BACK");
//     Button re_start(501, 350, 783, 460, CYAN, "RE-START");
//     //Button next(501, 350, 783, 460, MAGENTA, "NEXT LEVEL");


//     char typed_word[50] = "";
//     int ccnt = 0, wcnt = 0;
//     bool timeOverWarning = false;
//     bool isStore = false;
//     int mx = 0;

//     Footer();

//     while(true)
//     {
//         re_start.hover(GREEN);
//         back_button.hover(GREEN);
//         //next.hover(GREEN);
//         //GetAsyncKeyState checks if the left mouse button is pressed using the GetAsyncKeyState
//         //GetAsyncKeyState is for seeing where the mouse is moving
//         //it will check whether a key is pressed or not.
//         if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
//         {
//             if(re_start.cursor())
//             {
//                 type_till_go();
//                 return;
//             }

//             else if(back_button.cursor())
//             {
//                 move_ahead();
//                 return;
//             }

//         }
//         char ch;
//         if(ch == 9)
//         {

//             outtextxy(210,210, "NOT Valid");

//             strcpy(typed_word, "");
//             settextstyle(4, 0, 3);
//             rand_word  = words[rand() % length];
//             strcpy(crand_word, rand_word.c_str());

//             new Field(16, 80, 783, 150,WHITE,BLACK,crand_word); //To print random word
//             new Field(16, 150, 783, 200,WHITE,BLACK,"");

//             setcolor(WHITE);
//             rectangle(16, 150, 783, 150);

//             setcolor(BLACK);
//             rectangle(200, 150, 600, 150);
//         }

//     }
// }


void Header()
{
    // Header Section
    setcolor(BLACK);
    //set background color
    setbkcolor(LIGHTCYAN);
    //font style
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
    //void outtextxy(int x, int y, char *string); displaying text at a specific position
    outtextxy(400 - textwidth("Typing Master") / 2, 58 - textheight("A") / 2, "Typing GAME");
    setlinestyle(1, 0, 1);
    //for drawing line in header
    line(16, 84.5 + textheight("A")/ 4, 784,84.5 + textheight("A")/ 4);
    setlinestyle(0, 0, 1);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
}
void Footer()
{
    //Footer Section

    //void setfillstyle(int pattern, int color)
    setfillstyle(SOLID_FILL, CYAN);
    //void bar(int left, int top, int right, int bottom); drawing the bar
    bar(16, 465, 783, 504);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    setbkcolor(CYAN);
    setcolor(BLACK);
    outtextxy(400 - textwidth("Developed By Spartan")/2, 485 - textheight("A") / 2, "Developed By Spartan");
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
}

void info_start() {
    cleardevice();
    frame();
    Footer();

    // Creating parameterized Button objects from ui.h
    Button back(15, 425, 130, 465, BLUE, "BACK");

    // Displaying content
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);

    outtextxy(50, 50, "Our Project Takes Arithmetic Expression and Analyzes.");
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    outtextxy(50, 120, "Tokens include:");
    outtextxy(100, 150, "- Numbers (e.g., 42, 3.14)");
    outtextxy(100, 180, "- Operators (+, -, *)");
    outtextxy(100, 210, "- Parentheses (, )");
    outtextxy(100, 240, "- Identifiers (e.g., x, sum)");

    outtextxy(50, 300, "These tokens simplify expression analysis.");

    while (true) {
        back.hover(GREEN); // Highlight the "BACK" button on hover

        if (GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) { // Left mouse button clicked
            if (back.cursor()) {
                menu(); // Go back to the main menu
                break;
            }
        }
    }
}



void about_us()
{
    setbkcolor(DARKGRAY);
    cleardevice();
    frame();
    Footer();
    settextstyle(6, 0, 4);
    new Field(0, 0, 800, 70, GREEN,BLACK,"About Us");
    settextstyle(8, 0, 1);
    new Field(15, 200, 785, 230, CYAN,WHITE ,"Team Members");
    new Field(15, 230, 785, 260, CYAN,WHITE ,"Team Leader: Ahanaf");
    new Field(15, 260, 785, 290, CYAN,WHITE ,"Member 1: Irtisum");
    settextstyle(8, 0, 2);
    Button back(15, 425, 130, 465, BLUE, "BACK");
    while(true)
    {
        back.hover(GREEN);

        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
        {
            if(back.cursor())menu();
        }
        if(kbhit()) getch();
    }
}



//#######################################################################################
//#######################################################################################



void exit()
{
    setbkcolor(BLACK);
    cleardevice();
    frame();
    Footer();
    new Field(0, 0, 800, 40, MAGENTA,WHITE, "WHAT YOU WANT TO DO");
    Button back(15, 425, 130, 465, BLUE, "BACK");
    Button exit(650, 425, 785, 465, BLUE, "EXIT");
    while(true)
    {
        back.hover(GREEN);

        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
        {
            if(back.cursor())menu();
            else if(exit.cursor())closegraph();
        }
        if(kbhit()) getch();
    }

}
void menu()
{
    setbkcolor(CYAN);
    cleardevice();
    settextstyle(6, 0, 4);
    new Field(0, 0, 800, 70, GREEN,BLACK, "MAIN MENU");

    Footer();

    ////left,top,right,bottom

    Button info(125, 90, 395, 150, MAGENTA, "Info + Rules");
    Button astatment(405, 90, 675, 150, MAGENTA, "Statement?");


    Button reginput(125, 160, 395, 220, BLUE, "Regex box");    
    Button ptree(405, 160, 675, 220, BLUE, "Parse Tree");

    Button aboutMe(125, 240, 675, 300, MAGENTA, "About Us");
    Button ext(125, 310, 675, 370, MAGENTA, "Exit");


    while(true)
    {
        //hovering over menu
        info.hover(GREEN);
        reginput.hover(GREEN);
        astatment.hover(GREEN);
        aboutMe.hover(GREEN);
        ptree.hover(GREEN);
        //newsfeed.hover(GREEN);
        ext.hover(GREEN);

        //pressing the windows
        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
        {
            if(info.cursor()) info_start();
            else if(reginput.cursor()) regex_input();
            else if(astatment.cursor()) ar_input();
            else if(ptree.cursor()) {drawwwwwwww();}
            else if(aboutMe.cursor()) about_us();
           else if(ext.cursor()) exit();
        }
    }
}


void login()
{

    setbkcolor(LIGHTCYAN);
    cleardevice();

    settextstyle(6, 0, 4);
    new Field(0,0,800,80,BLACK,WHITE,"WELCOME");//left,top,right,bottom
    settextstyle(8, 0, 2);//void settextstyle(int font, int direction, int font_size);
    new Field(100, 350, 350, 400, GREEN,WHITE, "ENTER YOUR NAME");//left,top,right,bottom
    Input userName;//creating input object from the ui.h
    userName.Name(350, 350,700, 400);//left,top,right,bottom
    Button submit(370,430,450,480, BLUE, "OK");

    while(true)
    {
        int tr=0;
        submit.hover(GREEN);
        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
        {
            if(userName.cursor()){ userName.getName(name); tr=1; }
            else if(submit.cursor())
            {
                if(strlen(name)>0){
                    //name[0]
                    menu();
                }
            }

        }
    }

}


//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------





///////regex box 

//#############################################################################################
//Regex input

void regex_input() {
    setbkcolor(DARKGRAY);
   // setbkcolor(LIGHTCYAN);
    cleardevice();
    //Footer();
    settextstyle(8, 0, 2);
    outtextxy(100,100, "The Follow Up expression: 55*");

    new Field(100, 350, 350, 400, GREEN,WHITE, "ENTER Numbers");
    //Button back(15, 525, 130, 565, BLUE, "Exit");
    Input exp;
    exp.Name(350, 350,700, 400);
    Button submit(370,430,450,480, BLUE, "OK");
    Button back(15, 425, 130, 480, BLUE, "BACK");

    while(true) {
        submit.hover(GREEN);
        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if(exp.cursor()){ exp.getName(exp1); }
            else if(submit.cursor()) {
                // evaluate exprresion
                bool ok = 0;
                int nn = strlen(exp1);
                if( nn == 1) ok = 1;
                for(int i=1;i<nn;i++){
                    if(exp1[i]!='5'){
                        ok = 1;
                        break;
                    }
                }
                // ok = 1 = invalid ,
                if(ok) outtextxy(100, 200, "Invalid Expression");
                else outtextxy(100, 200, "   Valid Expression  ");
            }
            else if(back.cursor()) {
                menu();
            }
        }
    }
}





//////treeeeeeeee



char name1[200] = "";//expression

struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
};

/////////foooter for tree 
void Footers() {
    setfillstyle(SOLID_FILL, CYAN);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    setbkcolor(CYAN);
    outtextxy(500 - textwidth("Developed By Spartan")/2, 585 - textheight("A") / 2, "Developed By Spartan");
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
}


void drawNode(int x, int y, const string& value, int color = WHITE) {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    circle(x, y, 20);
    floodfill(x, y, color);

    setbkcolor(color);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(BLACK);

    outtextxy(x - 10, y - 10, (char*)value.c_str());
}


void drawLine(int x1, int y1, int x2, int y2) {
    setcolor(WHITE);
    line(x1, y1, x2, y2);
}

void visualizeTree(TreeNode* root, int x, int y, int xOffset, int level = 0) {
    if (!root) return;

    drawNode(x, y, root->value, LIGHTBLUE);

    // Draw leff
    if (root->left) {
        drawLine(x, y + 20, x - xOffset, y + 80);
        visualizeTree(root->left, x - xOffset, y + 80, xOffset / 2, level + 1);
    }

    // Draw right
    if (root->right) {
        drawLine(x, y + 20, x + xOffset, y + 80);
        visualizeTree(root->right, x + xOffset, y + 80, xOffset / 2, level + 1);
    }
}

// construct a parsing tree from a mathematical expression
TreeNode* constructTree(const string& expression) {
    stack<TreeNode*> nodes;   // Stack for operand nodes
    stack<char> operators;    // Stack for operators

    for (char ch : expression) {
        if (isspace(ch)) continue; // Skip spaces

        // If character is a digit or variable, create a node
        if (isalnum(ch)) {
            nodes.push(new TreeNode(string(1, ch)));
        }
        // If character is an operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!operators.empty() &&
                   ((ch == '+' || ch == '-') || (ch == '*' || ch == '/')) &&
                   (operators.top() == '*' || operators.top() == '/')) {
                // Process higher precedence operators
                char op = operators.top();
                operators.pop();

                TreeNode* right = nodes.top(); nodes.pop();
                TreeNode* left = nodes.top(); nodes.pop();

                TreeNode* newNode = new TreeNode(string(1, op));
                newNode->left = left;
                newNode->right = right;

                nodes.push(newNode);
            }
            operators.push(ch);
        }
        // If opening parenthesis, push to operator stack
        else if (ch == '(') {
            operators.push(ch);
        }
        // If closing parenthesis, process until opening parenthesis
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                TreeNode* right = nodes.top(); nodes.pop();
                TreeNode* left = nodes.top(); nodes.pop();

                TreeNode* newNode = new TreeNode(string(1, op));
                newNode->left = left;
                newNode->right = right;

                nodes.push(newNode);
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop(); // Remove the opening parenthesis
            }
        }
    }

    // Process any remaining operators
    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        TreeNode* right = nodes.top(); nodes.pop();
        TreeNode* left = nodes.top(); nodes.pop();

        TreeNode* newNode = new TreeNode(string(1, op));
        newNode->left = left;
        newNode->right = right;

        nodes.push(newNode);
    }

    // The remaining node is the root of the tree
    return nodes.empty() ? nullptr : nodes.top();
}


void visualizeParsingTree(const string& expression) {
    cleardevice();
    TreeNode* root = constructTree(expression);

    if (!root) {
        cout << "Invalid expression!\n";
        return;
    }

    // Visualize the tree
    visualizeTree(root, getmaxx() / 2, 50, getmaxx() / 4);
}


void tree_input() {
    setbkcolor(LIGHTCYAN);
    cleardevice();
    Footers();
    settextstyle(8, 0, 2);
    new Field(100, 350, 350, 400, GREEN,WHITE, "ENTER Expression");
    Input exp;
    exp.Name(350, 350,700, 400);
    Button submit(370,430,450,480, BLUE, "OK");
    Button back(15, 425, 130, 480, BLUE, "BACK");

    while(true) {
        int tr=0;
        submit.hover(GREEN);
        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if(exp.cursor()){ exp.getName(name1); tr=1; }
            else if(submit.cursor()) {
                visualizeParsingTree(name1);
                 Button back(15, 425, 130, 480, BLUE, "BACK");
            }
            else if(back.cursor()) {
                menu();
            }
        }
    }
}


void drawwwwwwww() {
    //int gd = DETECT, gm;
    //initgraph(&gd, &gm, "");

    tree_input();
    //string expression = "(a+b)+c+d";
    //visualizeParsingTree(expression);
}




//#############################################################################################
//Arithmetic input
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}


void ar_input() {
    setbkcolor(DARKGRAY);
   // setbkcolor(LIGHTCYAN);
    cleardevice();
    //Footer();
    settextstyle(8, 0, 2);
    new Field(100, 350, 350, 400, GREEN,WHITE, "ENTER Expression");
    //Button back(15, 525, 130, 565, BLUE, "Exit");
    Input exp;
    exp.Name(350, 350,700, 400);
    Button submit(370,430,450,480, BLUE, "OK");
    Button back(15, 425, 130, 480, BLUE, "BACK");

    while(true) {
        submit.hover(GREEN);
        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if(exp.cursor()){ exp.getName(exp1); }
            else if(submit.cursor()) {
                // evaluate exprresion
                bool ok = 0;
                int nn = strlen(exp1);
                if( nn == 1) ok = 1;
                for(int i=1;i<nn;i++){
                    if(i&1 && !isOperator(exp1[i])){
                        ok = 1;
                        break;
                    }
                    if(!(i&1) && isOperator(exp1[i])){
                        ok = 1;
                        break;
                    }
                }
                // ok = 1 = invalid ,
                if(ok) outtextxy(100, 200, "Invalid Expression");
                else outtextxy(100, 200, "   Valid Expression  ");
            }
            else if(back.cursor()) {
                menu();
            }
        }
    }
}



////sample
// void leaderboard()
// {
//     setbkcolor(DARKGRAY);
//     cleardevice();
//     //frame();
//     Footer();
//     // settextstyle(6, 0, 4);
//     // new Field(0, 0, 800, 70, GREEN,BLACK,"Leaderboard");
//     // settextstyle(8, 0, 1);


//     // settextstyle(8, 0, 2);
//     Button back(15, 425, 130, 465, BLUE, "BACK");
//     while(true)
//     {
//         back.hover(GREEN);

//         if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
//         {
//             if(back.cursor())menu();
//         }
//         if(kbhit()) getch();
//     }
// }
