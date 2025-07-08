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

void bankers_algo();
void bankers_visualization();
void fifo_algo();
void lru_algorithm();
void page_optimal_algorithm();
void fifo_visualization();
void lru_visualization();
void page_optimal_visualization();
void ps_algorithm();
void ps_visualization();
void sjf_algorithm();
void sjf_visualization();

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
    new Field(15, 260, 785, 290, CYAN,WHITE ,"Member 1: Adil");
    new Field(15, 290, 785, 320, CYAN,WHITE ,"Member 2: Apan");
    new Field(15, 320, 785, 350, CYAN,WHITE ,"Member 3: Irtisum");
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


    Button bankers(125, 230, 395, 290, BLUE, "Bankers");
    Button bankersVis(405, 230, 675, 290, BLUE, "Banker Visual");

    // FIFO buttons moved down
    Button fifo(125, 300, 395, 360, BLUE, "FIFO");
    Button fifoVis(405, 300, 675, 360, BLUE, "FIFO Visual");

    // LRU buttons moved down
    Button lru(125, 370, 395, 430, BLUE, "LRU");
    Button lruVis(405, 370, 675, 430, BLUE, "LRU Visual");

    // Page Optimal buttons moved down
    Button pageOpt(125, 440, 395, 500, BLUE, "Page Optimal");
    Button pageOptVis(405, 440, 675, 500, BLUE, "Optimal Visual");

    // PS buttons moved down
    Button ps(125, 510, 395, 570, BLUE, "PS");
    Button psVis(405, 510, 675, 570, BLUE, "PS Visual");

    // SJF buttons moved down
    Button sjf(125, 580, 395, 640, BLUE, "SJF");
    Button sjfVis(405, 580, 675, 640, BLUE, "SJF Visual");

    // About Us and Exit buttons moved down
    Button aboutMe(125, 650, 675, 710, MAGENTA, "About Us");
    Button ext(125, 720, 675, 780, MAGENTA, "Exit");



    while(true)
    {
        //hovering over menu
        info.hover(GREEN);
        reginput.hover(GREEN);
        astatment.hover(GREEN);
        aboutMe.hover(GREEN);
        ptree.hover(GREEN);
        bankers.hover(GREEN);         // Add hover for Bankers
        bankersVis.hover(GREEN); 
        fifo.hover(GREEN);
        fifoVis.hover(GREEN);
        lru.hover(GREEN);
        lruVis.hover(GREEN);
        pageOpt.hover(GREEN);
        pageOptVis.hover(GREEN);
        ps.hover(GREEN);
        psVis.hover(GREEN);
        sjf.hover(GREEN);
        sjfVis.hover(GREEN);
        ext.hover(GREEN);

        //pressing the windows
        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
        {
            if(info.cursor()) info_start();
            else if(reginput.cursor()) regex_input();
            else if(astatment.cursor()) ar_input();
            else if(ptree.cursor()) {drawwwwwwww();}
            else if(aboutMe.cursor()) about_us();
            else if(bankers.cursor())
             {bankers_algo();}
            else if(bankersVis.cursor())
            {bankers_visualization();}
            else if(fifo.cursor()) fifo_algo();
            else if(fifoVis.cursor()) {
                fifo_visualization();
            }
            else if(lru.cursor()) {
                lru_algorithm();
            }
            else if(lruVis.cursor()) {
                lru_visualization();
            }
            else if(pageOpt.cursor()) {
                page_optimal_algorithm();
            }
            else if(pageOptVis.cursor()) {
                page_optimal_visualization();
            }
            else if(ps.cursor()) {
                ps_algorithm();
            }
            else if(psVis.cursor()) {
                ps_visualization();
            }
            else if(sjf.cursor()) {
                sjf_algorithm();
            }
            else if(sjfVis.cursor()) {
                sjf_visualization();
            }
           else if(ext.cursor()) exit();
        }
    }
}


void login()
{
    menu();
    // setbkcolor(LIGHTCYAN);
    // cleardevice();

    // settextstyle(6, 0, 4);
    // new Field(0,0,800,80,BLACK,WHITE,"WELCOME");//left,top,right,bottom
    // settextstyle(8, 0, 2);//void settextstyle(int font, int direction, int font_size);
    // new Field(100, 350, 350, 400, GREEN,WHITE, "ENTER YOUR NAME");//left,top,right,bottom
    // Input userName;//creating input object from the ui.h
    // userName.Name(350, 350,700, 400);//left,top,right,bottom
    // Button submit(370,430,450,480, BLUE, "OK");

    // while(true)
    // {
    //     int tr=0;
    //     submit.hover(GREEN);
    //     if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0))
    //     {
    //         if(userName.cursor()){ userName.getName(name); tr=1; }
    //         else if(submit.cursor())
    //         {
    //             if(strlen(name)>0){
    //                 //name[0]
    //                 menu();
    //             }
    //         }

    //     }
    // }

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
    outtextxy(500 - textwidth("Developed By Spartans")/2, 585 - textheight("A") / 2, "Developed By Spartans");
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

//#############################################################################################
//#############################################################################################
// FIFO Algorithm
// Replace the fifo_algo() function with this fixed version:

void fifo_algo(){
    setbkcolor(DARKGRAY);
    cleardevice();
    
    //footer
    setfillstyle(SOLID_FILL, CYAN);
    //void bar(int left, int top, int right, int bottom); drawing the bar
    bar(16, 580, 783, 620);  // Changed from 465-504 to 580-620
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    setbkcolor(CYAN);
    setcolor(BLACK);
    outtextxy(400 - textwidth("Developed By Spartan")/2, 600 - textheight("A") / 2, "Developed By Spartan");  // Changed from 485 to 600



    // Header
    settextstyle(8, 0, 3);
    setcolor(WHITE);
    outtextxy(400 - textwidth("FIFO Page Replacement Algorithm")/2, 30, "FIFO Page Replacement Algorithm");

    // Draw separator line
    setcolor(CYAN);
    line(50, 70, 750, 70);

    settextstyle(8, 0, 2);
    new Field(50, 90, 350, 140, GREEN, WHITE, "Enter Frame Size");
    new Field(50, 160, 350, 210, GREEN, WHITE, "Enter Page Count");
    new Field(50, 230, 700, 280, GREEN, WHITE, "Enter Pages (space separated)");

    Input frameInput, pageCountInput, pagesInput;
    frameInput.Name(370, 90, 600, 140);
    pageCountInput.Name(370, 160, 600, 210);
    pagesInput.Name(50, 300, 700, 350);

    Button submit(250, 370, 450, 420, BLUE, "Calculate FIFO");
    Button back(50, 520, 200, 560, RED, "BACK");
    Button clear(550, 520, 700, 560, RED, "CLEAR");

    char frameStr[10] = "", pageCountStr[10] = "", pagesStr[500] = "";
    bool showResult = false;
    bool resultDisplayed = false;  // NEW: Track if result is already displayed
    int pageFaults = 0;

    while(true) {
        submit.hover(GREEN);
        back.hover(LIGHTRED);
        clear.hover(RED);

        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if(frameInput.cursor()){
                frameInput.getName(frameStr);
                showResult = false;  // Hide result when user starts new input
                resultDisplayed = false;
            }
            else if(pageCountInput.cursor()){
                pageCountInput.getName(pageCountStr);
                showResult = false;
                resultDisplayed = false;
            }
            else if(pagesInput.cursor()){
                pagesInput.getName(pagesStr);
                showResult = false;
                resultDisplayed = false;
            }
            else if(submit.cursor()) {
                // Clear previous result first
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(150, 430, 600, 470);

                // Validate inputs first
                if(strlen(frameStr) == 0 || strlen(pageCountStr) == 0 || strlen(pagesStr) == 0) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 430, "Please fill all fields!");
                    showResult = false;
                    resultDisplayed = false;
                    delay(1000);  // Show error briefly
                    continue;
                }

                // Calculate FIFO
                int frame = atoi(frameStr);
                int pageCount = atoi(pageCountStr);

                if(frame <= 0 || pageCount <= 0) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 430, "Invalid frame size or page count!");
                    showResult = false;
                    resultDisplayed = false;
                    delay(1000);
                    continue;
                }

                queue<int> fifoQueue;
                unordered_set<int> pageInMemory;
                pageFaults = 0;

                // Parse pages from string
                istringstream iss(pagesStr);
                string pageStr;
                vector<int> pages;
                while(iss >> pageStr) {
                    pages.push_back(atoi(pageStr.c_str()));
                }

                // FIFO Algorithm
                for(int page : pages) {
                    if(pageInMemory.find(page) == pageInMemory.end()) {
                        pageFaults++;
                        if(fifoQueue.size() == frame) {
                            int victimPage = fifoQueue.front();
                            fifoQueue.pop();
                            pageInMemory.erase(victimPage);
                        }
                        fifoQueue.push(page);
                        pageInMemory.insert(page);
                    }
                }
                showResult = true;
                resultDisplayed = false;  // Allow new result to be drawn
            }
            else if(clear.cursor()) {
                // Clear all inputs and result
                strcpy(frameStr, "");
                strcpy(pageCountStr, "");
                strcpy(pagesStr, "");
                showResult = false;
                resultDisplayed = false;

                // Clear input fields visually
                setfillstyle(SOLID_FILL, WHITE);
                bar(371, 91, 599, 139);
                bar(371, 161, 599, 209);
                bar(51, 301, 699, 349);

                // Clear result area
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(150, 430, 600, 470);
            }
            else if(back.cursor()) {
                menu();
                break;
            }
        }

        // FIXED: Only draw result once when needed
        if(showResult && !resultDisplayed) {
            // Create result box
            setfillstyle(SOLID_FILL, LIGHTBLUE);
            bar(150, 430, 600, 470);
            setcolor(BLACK);
            rectangle(150, 430, 600, 470);

            char result[100];
            sprintf(result, "Total Page Faults: %d", pageFaults);
            settextstyle(8, 0, 2);
            setcolor(BLACK);
            outtextxy(300, 445, result);

            resultDisplayed = true;  // Mark as displayed to prevent redrawing
        }
    }
}

void fifo_visualization(){
    setbkcolor(DARKGRAY);
    cleardevice();
    
    // Footer
    setfillstyle(SOLID_FILL, CYAN);
    bar(16, 680, 783, 720);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    setbkcolor(CYAN);
    setcolor(BLACK);
    outtextxy(400 - textwidth("Developed By Spartan")/2, 700 - textheight("A") / 2, "Developed By Spartan");

    // Header
    settextstyle(8, 0, 3);
    setcolor(WHITE);
    outtextxy(400 - textwidth("FIFO Page Replacement Visualization")/2, 20, "FIFO Page Replacement Visualization");

    settextstyle(8, 0, 2);
    new Field(50, 50, 300, 80, GREEN, WHITE, "Enter Frame Size");
    new Field(350, 50, 700, 80, GREEN, WHITE, "Enter Pages (space separated)");

    Input frameInput, pagesInput;
    frameInput.Name(50, 90, 200, 120);
    pagesInput.Name(250, 90, 700, 120);

    Button submit(300, 130, 450, 160, BLUE, "Visualize");
    Button back(50, 640, 150, 670, RED, "BACK");

    char frameStr[10] = "", pagesStr[500] = "";

    while(true) {
        submit.hover(GREEN);
        back.hover(LIGHTRED);

        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if(frameInput.cursor()){ frameInput.getName(frameStr); }
            else if(pagesInput.cursor()){ pagesInput.getName(pagesStr); }
            else if(submit.cursor()) {
                // Start visualization
                int frame = atoi(frameStr);
                
                // Parse pages
                istringstream iss(pagesStr);
                string pageStr;
                vector<int> pages;
                while(iss >> pageStr && pages.size() < 20) {  // Limit to 20 pages
                    pages.push_back(atoi(pageStr.c_str()));
                }

                if(frame <= 0 || pages.empty()) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 170, "Invalid input! Please check frame size and pages.");
                    delay(2000);
                    // Clear error message
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(200, 170, 600, 190);
                    continue;
                }

                // Clear visualization area
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(30, 170, 770, 630);

                // Enhanced Header for visualization with better spacing
                settextstyle(8, 0, 2);
                setcolor(YELLOW);
                outtextxy(50, 180, "Step");
                outtextxy(100, 180, "Page");
                outtextxy(160, 180, "Memory Frames");
                outtextxy(160 + frame * 60 + 20, 180, "Status");
                
                // Fixed Legend positioning - moved to right side with proper spacing
                settextstyle(8, 0, 1);
                setcolor(WHITE);
                outtextxy(550, 180, "Legend:");
                
                // Page Fault legend
                setfillstyle(SOLID_FILL, LIGHTRED);
                bar(550, 195, 570, 205);
                setcolor(BLACK);
                rectangle(550, 195, 570, 205);
                setcolor(WHITE);
                outtextxy(575, 197, "Page Fault");
                
                // Page Hit legend  
                setfillstyle(SOLID_FILL, LIGHTGREEN);
                bar(550, 210, 570, 220);
                setcolor(BLACK);
                rectangle(550, 210, 570, 220);
                setcolor(WHITE);
                outtextxy(575, 212, "Page Hit");
                
                // Draw header separator
                setcolor(CYAN);
                line(30, 230, 770, 230);

                // Visualization with animation
                queue<int> fifoQueue;
                unordered_set<int> pageInMemory;
                int pageFaults = 0;
                int yPos = 245;  // Starting Y position for visualization rows
                int rowHeight = 25;  // Increased height for better spacing

                for(int i = 0; i < pages.size() && yPos < 620; i++) {
                    int page = pages[i];
                    bool isPageFault = (pageInMemory.find(page) == pageInMemory.end());

                    if(isPageFault) {
                        pageFaults++;
                        if(fifoQueue.size() == frame) {
                            int victimPage = fifoQueue.front();
                            fifoQueue.pop();
                            pageInMemory.erase(victimPage);
                        }
                        fifoQueue.push(page);
                        pageInMemory.insert(page);
                    }

                    // Clear current row area for animation
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(30, yPos - 5, 770, yPos + 20);

                    // Draw step number
                    setcolor(WHITE);
                    settextstyle(8, 0, 1);
                    char stepText[10];
                    sprintf(stepText, "%d", i+1);
                    outtextxy(55, yPos, stepText);

                    // Draw current page being accessed
                    char pageText[10];
                    sprintf(pageText, "%d", page);
                    setcolor(YELLOW);
                    outtextxy(105, yPos, pageText);

                    // Draw frames with better spacing and padding
                    queue<int> tempQueue = fifoQueue;
                    int frameIndex = 0;
                    while(!tempQueue.empty() && frameIndex < frame) {
                        int xPos = 160 + frameIndex * 60;  // Increased spacing between frames
                        
                        // Frame background color
                        int frameColor = isPageFault ? LIGHTRED : LIGHTGREEN;
                        setfillstyle(SOLID_FILL, frameColor);
                        bar(xPos, yPos - 3, xPos + 50, yPos + 17);  // Better frame size
                        
                        // Frame border
                        setcolor(BLACK);
                        rectangle(xPos, yPos - 3, xPos + 50, yPos + 17);

                        // Frame content - centered text
                        setcolor(BLACK);
                        settextstyle(8, 0, 1);
                        char frameText[10];
                        sprintf(frameText, "%d", tempQueue.front());
                        int textX = xPos + 25 - textwidth(frameText)/2;
                        outtextxy(textX, yPos + 2, frameText);

                        tempQueue.pop();
                        frameIndex++;
                    }

                    // Empty frames with better styling
                    for(int j = frameIndex; j < frame; j++) {
                        int xPos = 160 + j * 60;
                        setfillstyle(SOLID_FILL, WHITE);
                        bar(xPos, yPos - 3, xPos + 50, yPos + 17);
                        setcolor(BLACK);
                        rectangle(xPos, yPos - 3, xPos + 50, yPos + 17);
                        outtextxy(xPos + 22, yPos + 2, "-");
                    }

                    // Show page fault/hit status with better positioning
                    int statusX = 160 + frame * 60 + 30;
                    setcolor(isPageFault ? RED : GREEN);
                    settextstyle(8, 0, 1);
                    char statusText[10];
                    strcpy(statusText, isPageFault ? "FAULT" : "HIT");
                    outtextxy(statusX, yPos, statusText);

                    // Animation delay - 0.5 seconds
                    delay(500);

                    yPos += rowHeight;
                }

                // Show final result with better positioning
                setcolor(YELLOW);
                settextstyle(8, 0, 2);
                char result[100];
                sprintf(result, "Total Page Faults: %d out of %d pages", pageFaults, (int)pages.size());
                outtextxy(200, 625, result);

                // Wait for user to click back
                while(true) {
                    back.hover(LIGHTRED);
                    if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
                        if(back.cursor()) {
                            menu();
                            return;
                        }
                    }
                }
            }
            else if(back.cursor()) {
                menu();
                break;
            }
        }
    }
}

void lru_algorithm(){
    setbkcolor(DARKGRAY);
    cleardevice();
    
    //footer
    setfillstyle(SOLID_FILL, CYAN);
    bar(16, 580, 783, 620);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    setbkcolor(CYAN);
    setcolor(BLACK);
    outtextxy(400 - textwidth("Developed By Spartan")/2, 600 - textheight("A") / 2, "Developed By Spartan");

    // Header
    settextstyle(8, 0, 3);
    setcolor(WHITE);
    outtextxy(400 - textwidth("LRU Page Replacement Algorithm")/2, 30, "LRU Page Replacement Algorithm");

    // Draw separator line
    setcolor(CYAN);
    line(50, 70, 750, 70);

    settextstyle(8, 0, 2);
    new Field(50, 90, 350, 140, GREEN, WHITE, "Enter Frame Size");
    new Field(50, 160, 350, 210, GREEN, WHITE, "Enter Page Count");
    new Field(50, 230, 700, 280, GREEN, WHITE, "Enter Pages (space separated)");

    Input frameInput, pageCountInput, pagesInput;
    frameInput.Name(370, 90, 600, 140);
    pageCountInput.Name(370, 160, 600, 210);
    pagesInput.Name(50, 300, 700, 350);

    Button submit(250, 370, 450, 420, BLUE, "Calculate LRU");
    Button back(50, 520, 200, 560, RED, "BACK");
    Button clear(550, 520, 700, 560, RED, "CLEAR");

    char frameStr[10] = "", pageCountStr[10] = "", pagesStr[500] = "";
    bool showResult = false;
    bool resultDisplayed = false;
    int pageFaults = 0;

    while(true) {
        submit.hover(GREEN);
        back.hover(LIGHTRED);
        clear.hover(RED);

        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if(frameInput.cursor()){
                frameInput.getName(frameStr);
                showResult = false;
                resultDisplayed = false;
            }
            else if(pageCountInput.cursor()){
                pageCountInput.getName(pageCountStr);
                showResult = false;
                resultDisplayed = false;
            }
            else if(pagesInput.cursor()){
                pagesInput.getName(pagesStr);
                showResult = false;
                resultDisplayed = false;
            }
            else if(submit.cursor()) {
                // Clear previous result first
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(150, 430, 600, 470);

                // Validate inputs first
                if(strlen(frameStr) == 0 || strlen(pageCountStr) == 0 || strlen(pagesStr) == 0) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 430, "Please fill all fields!");
                    showResult = false;
                    resultDisplayed = false;
                    delay(1000);
                    continue;
                }

                // Calculate LRU
                int frame = atoi(frameStr);
                int pageCount = atoi(pageCountStr);

                if(frame <= 0 || pageCount <= 0) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 430, "Invalid frame size or page count!");
                    showResult = false;
                    resultDisplayed = false;
                    delay(1000);
                    continue;
                }

                // Parse pages from string
                istringstream iss(pagesStr);
                string pageStr;
                vector<int> pages;
                while(iss >> pageStr) {
                    pages.push_back(atoi(pageStr.c_str()));
                }

                // LRU Algorithm
                unordered_map<int, list<int>::iterator> pageMap;
                list<int> cache; // Doubly linked list to store page order
                pageFaults = 0;

                for (int page : pages) {
                    // If page is not in frame, we have a page fault
                    if (pageMap.find(page) == pageMap.end()) {
                        pageFaults++;

                        // If frame is full, remove the least recently used page
                        if (cache.size() == frame) {
                            int last = cache.back(); // Least Recently Used
                            cache.pop_back();
                            pageMap.erase(last);
                        }
                    }
                    else {
                        // If page is in frame, remove previous occurrence
                        cache.erase(pageMap[page]);
                    }

                    // Add current page to front (most recently used)
                    cache.push_front(page);
                    pageMap[page] = cache.begin();
                }

                showResult = true;
                resultDisplayed = false;
            }
            else if(clear.cursor()) {
                // Clear all inputs and result
                strcpy(frameStr, "");
                strcpy(pageCountStr, "");
                strcpy(pagesStr, "");
                showResult = false;
                resultDisplayed = false;

                // Clear input fields visually
                setfillstyle(SOLID_FILL, WHITE);
                bar(371, 91, 599, 139);
                bar(371, 161, 599, 209);
                bar(51, 301, 699, 349);

                // Clear result area
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(150, 430, 600, 470);
            }
            else if(back.cursor()) {
                menu();
                break;
            }
        }

        // Display result once when needed
        if(showResult && !resultDisplayed) {
            // Create result box
            setfillstyle(SOLID_FILL, LIGHTBLUE);
            bar(150, 430, 600, 470);
            setcolor(BLACK);
            rectangle(150, 430, 600, 470);

            char result[100];
            sprintf(result, "Total Page Faults: %d", pageFaults);
            settextstyle(8, 0, 2);
            setcolor(BLACK);
            outtextxy(300, 445, result);

            resultDisplayed = true;
        }
    }
}

void lru_visualization(){
    setbkcolor(DARKGRAY);
    cleardevice();
    
    // Footer
    setfillstyle(SOLID_FILL, CYAN);
    bar(16, 680, 783, 720);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    setbkcolor(CYAN);
    setcolor(BLACK);
    outtextxy(400 - textwidth("Developed By Spartan")/2, 700 - textheight("A") / 2, "Developed By Spartan");

    // Compact Header
    settextstyle(8, 0, 2);
    setcolor(WHITE);
    outtextxy(400 - textwidth("LRU Page Replacement Visualization")/2, 10, "LRU Page Replacement Visualization");

    // Compact input fields
    settextstyle(8, 0, 1);
    new Field(50, 30, 250, 55, GREEN, WHITE, "Frame Size");
    new Field(300, 30, 700, 55, GREEN, WHITE, "Pages (space separated)");

    Input frameInput, pagesInput;
    frameInput.Name(50, 60, 150, 80);
    pagesInput.Name(200, 60, 700, 80);

    Button submit(250, 85, 350, 105, BLUE, "Visualize");
    Button back(50, 650, 150, 675, RED, "BACK");

    char frameStr[10] = "", pagesStr[500] = "";

    while(true) {
        submit.hover(GREEN);
        back.hover(LIGHTRED);

        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if(frameInput.cursor()){ frameInput.getName(frameStr); }
            else if(pagesInput.cursor()){ pagesInput.getName(pagesStr); }
            else if(submit.cursor()) {
                // Start visualization
                int frame = atoi(frameStr);
                
                // Parse pages
                istringstream iss(pagesStr);
                string pageStr;
                vector<int> pages;
                while(iss >> pageStr && pages.size() < 20) {
                    pages.push_back(atoi(pageStr.c_str()));
                }

                if(frame <= 0 || pages.empty()) {
                    setcolor(RED);
                    settextstyle(8, 0, 1);
                    outtextxy(200, 110, "Invalid input! Check frame size and pages.");
                    delay(2000);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(200, 110, 600, 130);
                    continue;
                }

                // Clear visualization area
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(20, 110, 780, 640);

                // Compact header for visualization
                settextstyle(8, 0, 1);
                setcolor(YELLOW);
                outtextxy(30, 120, "Step");
                outtextxy(70, 120, "Page");
                outtextxy(110, 120, "Memory Frames (Most->Least Recent)");
                
                // Calculate position for status column
                int statusX = 110 + frame * 45 + 10;
                outtextxy(statusX, 120, "Status");
                
                // Compact Legend - positioned dynamically
                int legendX = statusX + 60;
                settextstyle(8, 0, 1);
                setcolor(WHITE);
                outtextxy(legendX, 120, "Legend:");
                
                // Page Fault legend
                setfillstyle(SOLID_FILL, LIGHTRED);
                bar(legendX, 130, legendX + 15, 140);
                setcolor(BLACK);
                rectangle(legendX, 130, legendX + 15, 140);
                setcolor(WHITE);
                outtextxy(legendX + 20, 132, "Fault");
                
                // Page Hit legend  
                setfillstyle(SOLID_FILL, LIGHTGREEN);
                bar(legendX, 145, legendX + 15, 155);
                setcolor(BLACK);
                rectangle(legendX, 145, legendX + 15, 155);
                setcolor(WHITE);
                outtextxy(legendX + 20, 147, "Hit");
                
                // Draw header separator
                setcolor(CYAN);
                line(20, 160, 780, 160);

                // LRU Visualization with animation - optimized for 20 pages
                unordered_map<int, list<int>::iterator> pageMap;
                list<int> cache;
                int pageFaults = 0;
                int yPos = 170;  // Starting position
                int rowHeight = 22;  // Reduced height for 20 rows

                for(int i = 0; i < pages.size() && yPos < 620; i++) {
                    int page = pages[i];
                    bool isPageFault = (pageMap.find(page) == pageMap.end());

                    if(isPageFault) {
                        pageFaults++;
                        // If frame is full, remove LRU page
                        if(cache.size() == frame) {
                            int last = cache.back();
                            cache.pop_back();
                            pageMap.erase(last);
                        }
                    }
                    else {
                        // Remove page from current position
                        cache.erase(pageMap[page]);
                    }

                    // Add page to front (most recently used)
                    cache.push_front(page);
                    pageMap[page] = cache.begin();

                    // Clear current row area for animation
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(20, yPos - 2, 780, yPos + 18);

                    // Draw step number (compact)
                    setcolor(WHITE);
                    settextstyle(8, 0, 1);
                    char stepText[10];
                    sprintf(stepText, "%d", i+1);
                    outtextxy(35, yPos, stepText);

                    // Draw current page being accessed
                    char pageText[10];
                    sprintf(pageText, "%d", page);
                    setcolor(YELLOW);
                    outtextxy(75, yPos, pageText);

                    // Draw frames with compact spacing - optimized for more frames
                    int frameIndex = 0;
                    for(auto it = cache.begin(); it != cache.end() && frameIndex < frame; ++it, ++frameIndex) {
                        int xPos = 110 + frameIndex * 45;  // Reduced spacing for more frames
                        
                        // Frame background color
                        int frameColor = isPageFault ? LIGHTRED : LIGHTGREEN;
                        setfillstyle(SOLID_FILL, frameColor);
                        bar(xPos, yPos - 1, xPos + 40, yPos + 15);  // Smaller frame size
                        
                        // Frame border
                        setcolor(BLACK);
                        rectangle(xPos, yPos - 1, xPos + 40, yPos + 15);

                        // Frame content - centered text
                        setcolor(BLACK);
                        settextstyle(8, 0, 1);
                        char frameText[10];
                        sprintf(frameText, "%d", *it);
                        int textX = xPos + 20 - textwidth(frameText)/2;
                        outtextxy(textX, yPos + 2, frameText);
                    }

                    // Empty frames
                    for(int j = frameIndex; j < frame; j++) {
                        int xPos = 110 + j * 45;
                        setfillstyle(SOLID_FILL, WHITE);
                        bar(xPos, yPos - 1, xPos + 40, yPos + 15);
                        setcolor(BLACK);
                        rectangle(xPos, yPos - 1, xPos + 40, yPos + 15);
                        outtextxy(xPos + 18, yPos + 2, "-");
                    }

                    // Show page fault/hit status - positioned dynamically
                    int statusPos = 110 + frame * 45 + 15;
                    setcolor(isPageFault ? RED : GREEN);
                    settextstyle(8, 0, 1);
                    char statusText[8];
                    strcpy(statusText, isPageFault ? "FAULT" : "HIT");
                    outtextxy(statusPos, yPos, statusText);

                    // Animation delay - 0.5 seconds
                    delay(500);

                    yPos += rowHeight;
                }

                // Show final result - positioned above footer
                setcolor(YELLOW);
                settextstyle(8, 0, 2);
                char result[100];
                sprintf(result, "Total Page Faults: %d / %d pages", pageFaults, (int)pages.size());
                outtextxy(300, 625, result);

                // Wait for user to click back
                while(true) {
                    back.hover(LIGHTRED);
                    if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
                        if(back.cursor()) {
                            menu();
                            return;
                        }
                    }
                }
            }
            else if(back.cursor()) {
                menu();
                break;
            }
        }
    }
}




void page_optimal_algorithm(){
    setbkcolor(DARKGRAY);
    cleardevice();
    
    //footer
    setfillstyle(SOLID_FILL, CYAN);
    bar(16, 580, 783, 620);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    setbkcolor(CYAN);
    setcolor(BLACK);
    outtextxy(400 - textwidth("Developed By Spartan")/2, 600 - textheight("A") / 2, "Developed By Spartan");

    // Header
    settextstyle(8, 0, 3);
    setcolor(WHITE);
    outtextxy(400 - textwidth("Optimal Page Replacement Algorithm")/2, 30, "Optimal Page Replacement Algorithm");

    // Draw separator line
    setcolor(CYAN);
    line(50, 70, 750, 70);

    settextstyle(8, 0, 2);
    new Field(50, 90, 350, 140, GREEN, WHITE, "Enter Frame Size");
    new Field(50, 160, 350, 210, GREEN, WHITE, "Enter Page Count");
    new Field(50, 230, 700, 280, GREEN, WHITE, "Enter Pages (space separated)");

    Input frameInput, pageCountInput, pagesInput;
    frameInput.Name(370, 90, 600, 140);
    pageCountInput.Name(370, 160, 600, 210);
    pagesInput.Name(50, 300, 700, 350);

    Button submit(250, 370, 450, 420, BLUE, "Calculate Optimal");
    Button back(50, 520, 200, 560, RED, "BACK");
    Button clear(550, 520, 700, 560, RED, "CLEAR");

    char frameStr[10] = "", pageCountStr[10] = "", pagesStr[500] = "";
    bool showResult = false;
    bool resultDisplayed = false;
    int pageFaults = 0;

    while(true) {
        submit.hover(GREEN);
        back.hover(LIGHTRED);
        clear.hover(RED);

        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if(frameInput.cursor()){
                frameInput.getName(frameStr);
                showResult = false;
                resultDisplayed = false;
            }
            else if(pageCountInput.cursor()){
                pageCountInput.getName(pageCountStr);
                showResult = false;
                resultDisplayed = false;
            }
            else if(pagesInput.cursor()){
                pagesInput.getName(pagesStr);
                showResult = false;
                resultDisplayed = false;
            }
            else if(submit.cursor()) {
                // Clear previous result first
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(150, 430, 600, 470);

                // Validate inputs first
                if(strlen(frameStr) == 0 || strlen(pageCountStr) == 0 || strlen(pagesStr) == 0) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 430, "Please fill all fields!");
                    showResult = false;
                    resultDisplayed = false;
                    delay(1000);
                    continue;
                }

                // Calculate Optimal
                int frame = atoi(frameStr);
                int pageCount = atoi(pageCountStr);

                if(frame <= 0 || pageCount <= 0) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 430, "Invalid frame size or page count!");
                    showResult = false;
                    resultDisplayed = false;
                    delay(1000);
                    continue;
                }

                // Parse pages from string
                istringstream iss(pagesStr);
                string pageStr;
                vector<int> pages;
                while(iss >> pageStr) {
                    pages.push_back(atoi(pageStr.c_str()));
                }

                // Optimal Page Replacement Algorithm
                vector<int> frames; // current pages in frame
                pageFaults = 0;

                for (int i = 0; i < pages.size(); i++) {
                    int page = pages[i];

                    // If page NOT in frame => page fault
                    if (find(frames.begin(), frames.end(), page) == frames.end()) {
                        pageFaults++; // increment page fault

                        // If frame has space, just add page
                        if (frames.size() < frame) {
                            frames.push_back(page);
                            continue;
                        }

                        // Frame full => replace using optimal
                        int index_to_replace = -1;
                        int farthest = i + 1;

                        for (int j = 0; j < frame; j++) {
                            int k;
                            for (k = i + 1; k < pages.size(); k++) {
                                if (frames[j] == pages[k]) {
                                    if (k > farthest) {
                                        farthest = k;
                                        index_to_replace = j;
                                    }
                                    break;
                                }
                            }
                            // If page is never used again, replace immediately
                            if (k == pages.size()) {
                                index_to_replace = j;
                                break;
                            }
                        }
                        frames[index_to_replace] = page;
                    }
                }

                showResult = true;
                resultDisplayed = false;
            }
            else if(clear.cursor()) {
                // Clear all inputs and result
                strcpy(frameStr, "");
                strcpy(pageCountStr, "");
                strcpy(pagesStr, "");
                showResult = false;
                resultDisplayed = false;

                // Clear input fields visually
                setfillstyle(SOLID_FILL, WHITE);
                bar(371, 91, 599, 139);
                bar(371, 161, 599, 209);
                bar(51, 301, 699, 349);

                // Clear result area
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(150, 430, 600, 470);
            }
            else if(back.cursor()) {
                menu();
                break;
            }
        }

        // Display result once when needed
        if(showResult && !resultDisplayed) {
            // Create result box
            setfillstyle(SOLID_FILL, LIGHTBLUE);
            bar(150, 430, 600, 470);
            setcolor(BLACK);
            rectangle(150, 430, 600, 470);

            char result[100];
            sprintf(result, "Total Page Faults: %d", pageFaults);
            settextstyle(8, 0, 2);
            setcolor(BLACK);
            outtextxy(300, 445, result);

            resultDisplayed = true;
        }
    }
}

void page_optimal_visualization(){
    setbkcolor(DARKGRAY);
    cleardevice();
    
    // Footer
    setfillstyle(SOLID_FILL, CYAN);
    bar(16, 680, 783, 720);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    setbkcolor(CYAN);
    setcolor(BLACK);
    outtextxy(400 - textwidth("Developed By Spartan")/2, 700 - textheight("A") / 2, "Developed By Spartan");

    // Compact Header
    settextstyle(8, 0, 2);
    setcolor(WHITE);
    outtextxy(400 - textwidth("Optimal Page Replacement Visualization")/2, 10, "Optimal Page Replacement Visualization");

    // Compact input fields
    settextstyle(8, 0, 1);
    new Field(50, 30, 250, 55, GREEN, WHITE, "Frame Size");
    new Field(300, 30, 700, 55, GREEN, WHITE, "Pages (space separated)");

    Input frameInput, pagesInput;
    frameInput.Name(50, 60, 150, 80);
    pagesInput.Name(200, 60, 700, 80);

    Button submit(250, 85, 350, 105, BLUE, "Visualize");
    Button back(50, 650, 150, 675, RED, "BACK");

    char frameStr[10] = "", pagesStr[500] = "";

    while(true) {
        submit.hover(GREEN);
        back.hover(LIGHTRED);

        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if(frameInput.cursor()){ frameInput.getName(frameStr); }
            else if(pagesInput.cursor()){ pagesInput.getName(pagesStr); }
            else if(submit.cursor()) {
                // Start visualization
                int frame = atoi(frameStr);
                
                // Parse pages
                istringstream iss(pagesStr);
                string pageStr;
                vector<int> pages;
                while(iss >> pageStr && pages.size() < 20) {
                    pages.push_back(atoi(pageStr.c_str()));
                }

                if(frame <= 0 || pages.empty()) {
                    setcolor(RED);
                    settextstyle(8, 0, 1);
                    outtextxy(200, 110, "Invalid input! Check frame size and pages.");
                    delay(2000);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(200, 110, 600, 130);
                    continue;
                }

                // Clear visualization area
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(20, 110, 780, 640);

                // Header for visualization with better spacing
                settextstyle(8, 0, 1);
                setcolor(YELLOW);
                outtextxy(30, 120, "Step");
                outtextxy(70, 120, "Page");
                outtextxy(110, 120, "Memory Frames");
                
                // Calculate position for status column - better spacing
                int statusX = 110 + frame * 38 + 15;  // Reduced frame spacing even more
                if(statusX < 280) statusX = 280;  // Minimum position for status
                outtextxy(statusX, 120, "Status");
                
                // Legend positioning - moved to top right corner, separate from main content
                settextstyle(8, 0, 1);
                setcolor(WHITE);
                outtextxy(580, 120, "Legend:");
                
                // Page Fault legend - top right corner
                setfillstyle(SOLID_FILL, LIGHTRED);
                bar(650, 120, 665, 130);
                setcolor(BLACK);
                rectangle(650, 120, 665, 130);
                setcolor(WHITE);
                outtextxy(670, 122, "Fault");
                
                // Page Hit legend - top right corner  
                setfillstyle(SOLID_FILL, LIGHTGREEN);
                bar(720, 120, 735, 130);
                setcolor(BLACK);
                rectangle(720, 120, 735, 130);
                setcolor(WHITE);
                outtextxy(740, 122, "Hit");
                
                // Draw header separator - moved down more to give space
                setcolor(CYAN);
                line(20, 145, 780, 145);

                // Optimal Visualization with animation - optimized for 20 pages
                vector<int> frames; // current pages in frame
                int pageFaults = 0;
                int yPos = 155;  // Starting position - moved down more
                int rowHeight = 20;  // Further reduced for more space

                for(int i = 0; i < pages.size() && yPos < 605; i++) {  // Reduced max Y more
                    int page = pages[i];
                    bool isPageFault = (find(frames.begin(), frames.end(), page) == frames.end());

                    if(isPageFault) {
                        pageFaults++;

                        // If frame has space, just add page
                        if (frames.size() < frame) {
                            frames.push_back(page);
                        }
                        else {
                            // Frame full => replace using optimal
                            int index_to_replace = -1;
                            int farthest = i + 1;

                            for (int j = 0; j < frame; j++) {
                                int k;
                                for (k = i + 1; k < pages.size(); k++) {
                                    if (frames[j] == pages[k]) {
                                        if (k > farthest) {
                                            farthest = k;
                                            index_to_replace = j;
                                        }
                                        break;
                                    }
                                }
                                // If page is never used again, replace immediately
                                if (k == pages.size()) {
                                    index_to_replace = j;
                                    break;
                                }
                            }
                            frames[index_to_replace] = page;
                        }
                    }

                    // Clear current row area for animation
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(20, yPos - 2, 780, yPos + 16);

                    // Draw step number (compact)
                    setcolor(WHITE);
                    settextstyle(8, 0, 1);
                    char stepText[10];
                    sprintf(stepText, "%d", i+1);
                    outtextxy(32, yPos, stepText);

                    // Draw current page being accessed
                    char pageText[10];
                    sprintf(pageText, "%d", page);
                    setcolor(YELLOW);
                    outtextxy(72, yPos, pageText);

                    // Draw frames with compact spacing
                    for(int frameIndex = 0; frameIndex < frame; frameIndex++) {
                        int xPos = 110 + frameIndex * 38;  // Further reduced spacing
                        
                        // Frame background color
                        int frameColor = isPageFault ? LIGHTRED : LIGHTGREEN;
                        setfillstyle(SOLID_FILL, frameColor);
                        bar(xPos, yPos - 1, xPos + 34, yPos + 13);  // Smaller frames
                        
                        // Frame border
                        setcolor(BLACK);
                        rectangle(xPos, yPos - 1, xPos + 34, yPos + 13);

                        // Frame content - centered text
                        setcolor(BLACK);
                        settextstyle(8, 0, 1);
                        if(frameIndex < frames.size()) {
                            char frameText[10];
                            sprintf(frameText, "%d", frames[frameIndex]);
                            int textX = xPos + 17 - textwidth(frameText)/2;
                            outtextxy(textX, yPos + 1, frameText);
                        } else {
                            outtextxy(xPos + 15, yPos + 1, "-");
                        }
                    }

                    // Show page fault/hit status - positioned with guaranteed spacing
                    int statusPos = max(280, 110 + frame * 38 + 20);  // Guaranteed minimum position
                    setcolor(isPageFault ? RED : GREEN);
                    settextstyle(8, 0, 1);
                    char statusText[8];
                    strcpy(statusText, isPageFault ? "FAULT" : "HIT");
                    outtextxy(statusPos, yPos, statusText);

                    // Animation delay - 0.5 seconds
                    delay(500);

                    yPos += rowHeight;
                }

                // Show final result - positioned above footer with better spacing
                setcolor(YELLOW);
                settextstyle(8, 0, 2);
                char result[100];
                sprintf(result, "Total Page Faults: %d / %d pages", pageFaults, (int)pages.size());
                outtextxy(220, 615, result);  // Moved up and left slightly

                // Wait for user to click back
                while(true) {
                    back.hover(LIGHTRED);
                    if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
                        if(back.cursor()) {
                            menu();
                            return;
                        }
                    }
                }
            }
            else if(back.cursor()) {
                menu();
                break;
            }
        }
    }
}



void ps_algorithm() {
    setbkcolor(DARKGRAY);
    cleardevice();

    // Footer
    setfillstyle(SOLID_FILL, CYAN);
    bar(16, 580, 783, 620);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    setbkcolor(CYAN);
    setcolor(BLACK);
    outtextxy(400 - textwidth("Developed By Spartan")/2, 600 - textheight("A") / 2, "Developed By Spartan");

    // Header
    settextstyle(8, 0, 3);
    setcolor(WHITE);
    outtextxy(400 - textwidth("Priority Scheduling Algorithm")/2, 30, "Priority Scheduling Algorithm");

    setcolor(CYAN);
    line(50, 70, 750, 70);

    settextstyle(8, 0, 2);
    new Field(50, 90, 350, 140, GREEN, WHITE, "Enter Process Count");
    new Field(50, 160, 700, 210, GREEN, WHITE, "Enter Processes (priority arrival burst, space separated)");

    Input procCountInput, procInput;
    procCountInput.Name(370, 90, 600, 140);
    procInput.Name(50, 220, 700, 270);

    Button submit(250, 300, 450, 350, BLUE, "Calculate PS");
    Button back(50, 520, 200, 560, RED, "BACK");
    Button clear(550, 520, 700, 560, RED, "CLEAR");

    char procCountStr[10] = "", procStr[1000] = "";
    bool showResult = false;
    bool resultDisplayed = false;
    struct Proc { int prio, arr, burst, pid, start, finish, wait, tat; };
    vector<Proc> result;
    double avgTAT = 0, avgWT = 0;

    while(true) {
        submit.hover(GREEN);
        back.hover(LIGHTRED);
        clear.hover(RED);

        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if(procCountInput.cursor()){
                procCountInput.getName(procCountStr);
                showResult = false;
                resultDisplayed = false;
            }
            else if(procInput.cursor()){
                procInput.getName(procStr);
                showResult = false;
                resultDisplayed = false;
            }
            else if(submit.cursor()) {
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(100, 370, 700, 500);
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(100, 510, 700, 570); // Clear avg box

                if(strlen(procCountStr) == 0 || strlen(procStr) == 0) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 370, "Please fill all fields!");
                    showResult = false;
                    resultDisplayed = false;
                    delay(1000);
                    continue;
                }

                int n = atoi(procCountStr);
                if(n <= 0) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 370, "Invalid process count!");
                    showResult = false;
                    resultDisplayed = false;
                    delay(1000);
                    continue;
                }

                // Parse process input
                istringstream iss(procStr);
                vector<Proc> procs;
                for(int i = 0; i < n; i++) {
                    int prio, arr, burst;
                    if(!(iss >> prio >> arr >> burst)) break;
                    procs.push_back({prio, arr, burst, i+1, -1, -1, 0, 0});
                }
                if(procs.size() != n) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 370, "Invalid process input!");
                    showResult = false;
                    resultDisplayed = false;
                    delay(1000);
                    continue;
                }

                // Sort by arrival then priority
                sort(procs.begin(), procs.end(), [](const Proc& a, const Proc& b){
                    if(a.arr != b.arr) return a.arr < b.arr;
                    return a.prio < b.prio;
                });

                int time = 0, finished = 0;
                vector<bool> done(n, false);
                while(finished < n) {
                    // Find ready processes
                    vector<Proc*> ready;
                    for(auto& p : procs)
                        if(!done[p.pid-1] && p.arr <= time)
                            ready.push_back(&p);
                    Proc* run = nullptr;
                    if(!ready.empty()) {
                        run = *min_element(ready.begin(), ready.end(), [](Proc* a, Proc* b){
                            return a->prio < b->prio || (a->prio == b->prio && a->arr < b->arr);
                        });
                    }
                    if(run) {
                        run->start = time;
                        run->finish = time + run->burst;
                        run->tat = run->finish - run->arr;
                        run->wait = run->start - run->arr;
                        time += run->burst;
                        done[run->pid-1] = true;
                        finished++;
                    } else {
                        time++;
                    }
                }
                result = procs;
                // Calculate averages
                avgTAT = 0; avgWT = 0;
                for(auto &p : result) {
                    avgTAT += p.tat;
                    avgWT += p.wait;
                }
                if(n) {
                    avgTAT /= n;
                    avgWT /= n;
                }
                showResult = true;
                resultDisplayed = false;
            }
            else if(clear.cursor()) {
                strcpy(procCountStr, "");
                strcpy(procStr, "");
                showResult = false;
                resultDisplayed = false;
                setfillstyle(SOLID_FILL, WHITE);
                bar(371, 91, 599, 139);
                bar(51, 221, 699, 269);
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(100, 370, 700, 500);
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(100, 510, 700, 570); // Clear avg box
            }
            else if(back.cursor()) {
                menu();
                break;
            }
        }

        if(showResult && !resultDisplayed) {
            // Draw result table
            setfillstyle(SOLID_FILL, LIGHTBLUE);
            bar(100, 370, 700, 500);
            setcolor(BLACK);
            rectangle(100, 370, 700, 500);

            settextstyle(8, 0, 1);
            setcolor(BLACK);
            int y = 380;
            outtextxy(110, y, "PID");
            outtextxy(160, y, "Priority");
            outtextxy(230, y, "Arrival");
            outtextxy(300, y, "Burst");
            outtextxy(370, y, "Start");
            outtextxy(430, y, "Finish");
            outtextxy(500, y, "Wait");
            outtextxy(570, y, "TAT");
            y += 20;
            for(auto &p : result) {
                char buf[32];
                sprintf(buf, "P%d", p.pid);
                outtextxy(110, y, buf);
                sprintf(buf, "%d", p.prio);
                outtextxy(160, y, buf);
                sprintf(buf, "%d", p.arr);
                outtextxy(230, y, buf);
                sprintf(buf, "%d", p.burst);
                outtextxy(300, y, buf);
                sprintf(buf, "%d", p.start);
                outtextxy(370, y, buf);
                sprintf(buf, "%d", p.finish);
                outtextxy(430, y, buf);
                sprintf(buf, "%d", p.wait);
                outtextxy(500, y, buf);
                sprintf(buf, "%d", p.tat);
                outtextxy(570, y, buf);
                y += 18;
                if(y > 480) break;
            }

            // Draw averages in a separate box below
            setfillstyle(SOLID_FILL, LIGHTCYAN);
            bar(100, 510, 700, 570);
            setcolor(BLACK);
            rectangle(100, 510, 700, 570);
            settextstyle(8, 0, 2);
            setcolor(BLUE);
            char buf[128];
            sprintf(buf, "Avg Turnaround: %.2lf, Avg Waiting: %.2lf", avgTAT, avgWT);
            outtextxy(150, 530, buf);

            resultDisplayed = true;
        }
    }
}

void ps_visualization() {
    setbkcolor(DARKGRAY);
    cleardevice();

    // Footer
    setfillstyle(SOLID_FILL, CYAN);
    bar(16, 680, 783, 720);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    setbkcolor(CYAN);
    setcolor(BLACK);
    outtextxy(400 - textwidth("Developed By Spartan")/2, 700 - textheight("A") / 2, "Developed By Spartan");

    // Header
    settextstyle(8, 0, 3);
    setcolor(WHITE);
    outtextxy(400 - textwidth("Priority Scheduling Visualization")/2, 20, "Priority Scheduling Visualization");

    settextstyle(8, 0, 2);
    new Field(50, 50, 300, 80, GREEN, WHITE, "Process Count");
    new Field(350, 50, 700, 80, GREEN, WHITE, "Processes (priority arrival burst, space separated)");

    Input procCountInput, procInput;
    procCountInput.Name(50, 90, 200, 120);
    procInput.Name(250, 90, 700, 120);

    Button submit(300, 130, 450, 160, BLUE, "Visualize");
    Button back(50, 640, 150, 670, RED, "BACK");

    char procCountStr[10] = "", procStr[1000] = "";

    while(true) {
        submit.hover(GREEN);
        back.hover(LIGHTRED);

        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if(procCountInput.cursor()) procCountInput.getName(procCountStr);
            else if(procInput.cursor()) procInput.getName(procStr);
            else if(submit.cursor()) {
                int n = atoi(procCountStr);
                if(n <= 0 || strlen(procStr) == 0) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 170, "Invalid input! Check process count and data.");
                    delay(2000);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(200, 170, 600, 190);
                    continue;
                }

                // Parse process input
                istringstream iss(procStr);
                struct Proc { int prio, arr, burst, pid, remain, start, finish; };
                vector<Proc> procs;
                for(int i = 0; i < n; i++) {
                    int prio, arr, burst;
                    if(!(iss >> prio >> arr >> burst)) break;
                    procs.push_back({prio, arr, burst, i+1, burst, -1, -1});
                }
                if(procs.size() != n) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 170, "Invalid process input!");
                    delay(2000);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(200, 170, 600, 190);
                    continue;
                }

                // Clear visualization area
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(30, 170, 770, 630);

                // Draw Gantt chart style
                settextstyle(8, 0, 2);
                setcolor(YELLOW);
                outtextxy(50, 180, "Gantt Chart (PID | Priority)");

                int time = 0, finished = 0, xPos = 60, yPos = 220;
                vector<bool> done(n, false);
                vector<int> finishTime(n, -1);
                int boxWidth = 60, boxHeight = 40;

                // Find total time for scaling
                int totalTime = 0;
                vector<pair<int,int>> gantt; // {pid, duration}
                vector<int> prioMap(n+1, 0);
                while(finished < n) {
                    vector<Proc*> ready;
                    for(auto& p : procs)
                        if(!done[p.pid-1] && p.arr <= time)
                            ready.push_back(&p);
                    Proc* run = nullptr;
                    if(!ready.empty()) {
                        run = *min_element(ready.begin(), ready.end(), [](Proc* a, Proc* b){
                            return a->prio < b->prio || (a->prio == b->prio && a->arr < b->arr);
                        });
                    }
                    if(run) {
                        run->start = time;
                        run->finish = time + run->burst;
                        prioMap[run->pid] = run->prio;
                        gantt.push_back({run->pid, run->burst});
                        time += run->burst;
                        done[run->pid-1] = true;
                        finished++;
                    } else {
                        gantt.push_back({-1, 1});
                        time++;
                    }
                }
                totalTime = time;

                // Draw Gantt chart with animation and correct time markers
                xPos = 60;
                int currTime = 0;
                int rowStartX = xPos;
                int rowY = yPos;
                int rowEndX = 700;
                for(size_t idx = 0; idx < gantt.size(); ++idx) {
                    auto& g = gantt[idx];
                    // Draw box
                    if(g.first == -1) {
                        setfillstyle(SOLID_FILL, LIGHTGRAY);
                        bar(xPos, rowY, xPos+boxWidth, rowY+boxHeight);
                        setcolor(BLACK);
                        rectangle(xPos, rowY, xPos+boxWidth, rowY+boxHeight);
                        setcolor(RED);
                        outtextxy(xPos+10, rowY+10, "Idle");
                    } else {
                        setfillstyle(SOLID_FILL, LIGHTGREEN);
                        bar(xPos, rowY, xPos+boxWidth, rowY+boxHeight);
                        setcolor(BLACK);
                        rectangle(xPos, rowY, xPos+boxWidth, rowY+boxHeight);
                        char buf[32];
                        sprintf(buf, "P%d | %d", g.first, prioMap[g.first]);
                        setcolor(BLUE);
                        outtextxy(xPos+5, rowY+10, buf);
                    }
                    // Draw time marker at the left of each box
                    setcolor(BLACK);
                    char tbuf[16];
                    sprintf(tbuf, "%d", currTime);
                    outtextxy(xPos, rowY+boxHeight+5, tbuf);

                    delay(400);
                    currTime += g.second;
                    xPos += boxWidth;
                    // If out of row, move to next row and draw time marker at row end
                    if(xPos > rowEndX || idx == gantt.size()-1) {
                        // Draw time marker at the end of the row
                        char tbufEnd[16];
                        sprintf(tbufEnd, "%d", currTime);
                        outtextxy(xPos, rowY+boxHeight+5, tbufEnd);
                        rowY += boxHeight+30;
                        xPos = rowStartX;
                    }
                }

                // Show legend
                settextstyle(8, 0, 1);
                setcolor(WHITE);
                outtextxy(600, 180, "Legend:");
                setfillstyle(SOLID_FILL, LIGHTGREEN);
                bar(600, 195, 620, 205);
                setcolor(BLACK);
                rectangle(600, 195, 620, 205);
                setcolor(WHITE);
                outtextxy(625, 197, "Running");
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                bar(600, 210, 620, 220);
                setcolor(BLACK);
                rectangle(600, 210, 620, 220);
                setcolor(WHITE);
                outtextxy(625, 212, "Idle");

                // Wait for user to click back
                while(true) {
                    back.hover(LIGHTRED);
                    if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
                        if(back.cursor()) {
                            menu();
                            return;
                        }
                    }
                }
            }
            else if(back.cursor()) {
                menu();
                break;
            }
        }
    }
}

void sjf_algorithm() {
    setbkcolor(DARKGRAY);
    cleardevice();

    // Footer
    setfillstyle(SOLID_FILL, CYAN);
    bar(16, 580, 783, 620);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    setbkcolor(CYAN);
    setcolor(BLACK);
    outtextxy(400 - textwidth("Developed By Spartan")/2, 600 - textheight("A") / 2, "Developed By Spartan");

    // Header
    settextstyle(8, 0, 3);
    setcolor(WHITE);
    outtextxy(400 - textwidth("Shortest Job First Algorithm")/2, 30, "Shortest Job First Algorithm");

    setcolor(CYAN);
    line(50, 70, 750, 70);

    settextstyle(8, 0, 2);
    new Field(50, 90, 350, 140, GREEN, WHITE, "Enter Process Count");
    new Field(50, 160, 700, 210, GREEN, WHITE, "Enter Processes (arrival burst, space separated)");

    Input procCountInput, procInput;
    procCountInput.Name(370, 90, 600, 140);
    procInput.Name(50, 220, 700, 270);

    Button submit(250, 300, 450, 350, BLUE, "Calculate SJF");
    Button back(50, 520, 200, 560, RED, "BACK");
    Button clear(550, 520, 700, 560, RED, "CLEAR");

    char procCountStr[10] = "", procStr[1000] = "";
    bool showResult = false;
    bool resultDisplayed = false;
    struct Proc { int arr, burst, pid, start, finish, wait, tat; };
    vector<Proc> result;

    double avgTAT = 0, avgWT = 0;

    while(true) {
        submit.hover(GREEN);
        back.hover(LIGHTRED);
        clear.hover(RED);

        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if(procCountInput.cursor()){
                procCountInput.getName(procCountStr);
                showResult = false;
                resultDisplayed = false;
            }
            else if(procInput.cursor()){
                procInput.getName(procStr);
                showResult = false;
                resultDisplayed = false;
            }
            else if(submit.cursor()) {
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(100, 370, 700, 500);
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(100, 510, 700, 570); // Clear avg box

                if(strlen(procCountStr) == 0 || strlen(procStr) == 0) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 370, "Please fill all fields!");
                    showResult = false;
                    resultDisplayed = false;
                    delay(1000);
                    continue;
                }

                int n = atoi(procCountStr);
                if(n <= 0) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 370, "Invalid process count!");
                    showResult = false;
                    resultDisplayed = false;
                    delay(1000);
                    continue;
                }

                // Parse process input
                istringstream iss(procStr);
                vector<Proc> procs;
                for(int i = 0; i < n; i++) {
                    int arr, burst;
                    if(!(iss >> arr >> burst)) break;
                    procs.push_back({arr, burst, i+1, -1, -1, 0, 0});
                }
                if(procs.size() != n) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 370, "Invalid process input!");
                    showResult = false;
                    resultDisplayed = false;
                    delay(1000);
                    continue;
                }

                // Sort by arrival
                sort(procs.begin(), procs.end(), [](const Proc& a, const Proc& b){
                    return a.arr < b.arr;
                });

                int time = 0, finished = 0;
                vector<bool> done(n, false);
                while(finished < n) {
                    // Find ready processes
                    vector<Proc*> ready;
                    for(auto& p : procs)
                        if(!done[p.pid-1] && p.arr <= time)
                            ready.push_back(&p);
                    Proc* run = nullptr;
                    if(!ready.empty()) {
                        run = *min_element(ready.begin(), ready.end(), [](Proc* a, Proc* b){
                            return a->burst < b->burst || (a->burst == b->burst && a->arr < b->arr);
                        });
                    }
                    if(run) {
                        run->start = time;
                        run->finish = time + run->burst;
                        run->tat = run->finish - run->arr;
                        run->wait = run->start - run->arr;
                        time += run->burst;
                        done[run->pid-1] = true;
                        finished++;
                    } else {
                        time++;
                    }
                }
                result = procs;
                // Calculate averages
                avgTAT = 0; avgWT = 0;
                for(auto &p : result) {
                    avgTAT += p.tat;
                    avgWT += p.wait;
                }
                if(n) {
                    avgTAT /= n;
                    avgWT /= n;
                }
                showResult = true;
                resultDisplayed = false;
            }
            else if(clear.cursor()) {
                strcpy(procCountStr, "");
                strcpy(procStr, "");
                showResult = false;
                resultDisplayed = false;
                setfillstyle(SOLID_FILL, WHITE);
                bar(371, 91, 599, 139);
                bar(51, 221, 699, 269);
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(100, 370, 700, 500);
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(100, 510, 700, 570); // Clear avg box
            }
            else if(back.cursor()) {
                menu();
                break;
            }
        }

        if(showResult && !resultDisplayed) {
            // Draw result table
            setfillstyle(SOLID_FILL, LIGHTBLUE);
            bar(100, 370, 700, 500);
            setcolor(BLACK);
            rectangle(100, 370, 700, 500);

            settextstyle(8, 0, 1);
            setcolor(BLACK);
            int y = 380;
            outtextxy(110, y, "PID");
            outtextxy(160, y, "Arrival");
            outtextxy(230, y, "Burst");
            outtextxy(300, y, "Start");
            outtextxy(370, y, "Finish");
            outtextxy(440, y, "Wait");
            outtextxy(510, y, "TAT");
            y += 20;
            for(auto &p : result) {
                char buf[32];
                sprintf(buf, "P%d", p.pid);
                outtextxy(110, y, buf);
                sprintf(buf, "%d", p.arr);
                outtextxy(160, y, buf);
                sprintf(buf, "%d", p.burst);
                outtextxy(230, y, buf);
                sprintf(buf, "%d", p.start);
                outtextxy(300, y, buf);
                sprintf(buf, "%d", p.finish);
                outtextxy(370, y, buf);
                sprintf(buf, "%d", p.wait);
                outtextxy(440, y, buf);
                sprintf(buf, "%d", p.tat);
                outtextxy(510, y, buf);
                y += 18;
                if(y > 480) break;
            }

            // Draw averages in a separate box below
            setfillstyle(SOLID_FILL, LIGHTCYAN);
            bar(100, 510, 700, 570);
            setcolor(BLACK);
            rectangle(100, 510, 700, 570);
            settextstyle(8, 0, 2);
            setcolor(BLUE);
            char buf[128];
            sprintf(buf, "Avg Turnaround: %.2lf, Avg Waiting: %.2lf", avgTAT, avgWT);
            outtextxy(150, 530, buf);

            resultDisplayed = true;
        }
    }
}

void sjf_visualization() {
    setbkcolor(DARKGRAY);
    cleardevice();

    // Footer
    setfillstyle(SOLID_FILL, CYAN);
    bar(16, 680, 783, 720);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    setbkcolor(CYAN);
    setcolor(BLACK);
    outtextxy(400 - textwidth("Developed By Spartan")/2, 700 - textheight("A") / 2, "Developed By Spartan");

    // Header
    settextstyle(8, 0, 3);
    setcolor(WHITE);
    outtextxy(400 - textwidth("SJF Visualization")/2, 20, "SJF Visualization");

    settextstyle(8, 0, 2);
    new Field(50, 50, 300, 80, GREEN, WHITE, "Process Count");
    new Field(350, 50, 700, 80, GREEN, WHITE, "Processes (arrival burst, space separated)");

    Input procCountInput, procInput;
    procCountInput.Name(50, 90, 200, 120);
    procInput.Name(250, 90, 700, 120);

    Button submit(300, 130, 450, 160, BLUE, "Visualize");
    Button back(50, 640, 150, 670, RED, "BACK");

    char procCountStr[10] = "", procStr[1000] = "";

    while(true) {
        submit.hover(GREEN);
        back.hover(LIGHTRED);

        if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if(procCountInput.cursor()) procCountInput.getName(procCountStr);
            else if(procInput.cursor()) procInput.getName(procStr);
            else if(submit.cursor()) {
                int n = atoi(procCountStr);
                if(n <= 0 || strlen(procStr) == 0) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 170, "Invalid input! Check process count and data.");
                    delay(2000);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(200, 170, 600, 190);
                    continue;
                }

                // Parse process input
                istringstream iss(procStr);
                struct Proc { int arr, burst, pid, remain, start, finish; };
                vector<Proc> procs;
                for(int i = 0; i < n; i++) {
                    int arr, burst;
                    if(!(iss >> arr >> burst)) break;
                    procs.push_back({arr, burst, i+1, burst, -1, -1});
                }
                if(procs.size() != n) {
                    setcolor(RED);
                    settextstyle(8, 0, 2);
                    outtextxy(200, 170, "Invalid process input!");
                    delay(2000);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(200, 170, 600, 190);
                    continue;
                }

                // Clear visualization area
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(30, 170, 770, 630);

                // Draw Gantt chart style
                settextstyle(8, 0, 2);
                setcolor(YELLOW);
                outtextxy(50, 180, "Gantt Chart (PID)");

                int time = 0, finished = 0, xPos = 60, yPos = 220;
                vector<bool> done(n, false);
                int boxWidth = 60, boxHeight = 40;
                vector<pair<int,int>> gantt; // {pid, duration}
                while(finished < n) {
                    vector<Proc*> ready;
                    for(auto& p : procs)
                        if(!done[p.pid-1] && p.arr <= time)
                            ready.push_back(&p);
                    Proc* run = nullptr;
                    if(!ready.empty()) {
                        run = *min_element(ready.begin(), ready.end(), [](Proc* a, Proc* b){
                            return a->burst < b->burst || (a->burst == b->burst && a->arr < b->arr);
                        });
                    }
                    if(run) {
                        run->start = time;
                        run->finish = time + run->burst;
                        gantt.push_back({run->pid, run->burst});
                        time += run->burst;
                        done[run->pid-1] = true;
                        finished++;
                    } else {
                        gantt.push_back({-1, 1});
                        time++;
                    }
                }
                int totalTime = time;

                // Draw Gantt chart with animation and correct time markers
                xPos = 60;
                int currTime = 0;
                int rowStartX = xPos;
                int rowY = yPos;
                int rowEndX = 700;
                for(size_t idx = 0; idx < gantt.size(); ++idx) {
                    auto& g = gantt[idx];
                    // Draw box
                    if(g.first == -1) {
                        setfillstyle(SOLID_FILL, LIGHTGRAY);
                        bar(xPos, rowY, xPos+boxWidth, rowY+boxHeight);
                        setcolor(BLACK);
                        rectangle(xPos, rowY, xPos+boxWidth, rowY+boxHeight);
                        setcolor(RED);
                        outtextxy(xPos+10, rowY+10, "Idle");
                    } else {
                        setfillstyle(SOLID_FILL, LIGHTGREEN);
                        bar(xPos, rowY, xPos+boxWidth, rowY+boxHeight);
                        setcolor(BLACK);
                        rectangle(xPos, rowY, xPos+boxWidth, rowY+boxHeight);
                        char buf[32];
                        sprintf(buf, "P%d", g.first);
                        setcolor(BLUE);
                        outtextxy(xPos+15, rowY+10, buf);
                    }
                    // Draw time marker at the left of each box
                    setcolor(BLACK);
                    char tbuf[16];
                    sprintf(tbuf, "%d", currTime);
                    outtextxy(xPos, rowY+boxHeight+5, tbuf);

                    delay(400);
                    currTime += g.second;
                    xPos += boxWidth;
                    // If out of row, move to next row and draw time marker at row end
                    if(xPos > rowEndX || idx == gantt.size()-1) {
                        // Draw time marker at the end of the row
                        char tbufEnd[16];
                        sprintf(tbufEnd, "%d", currTime);
                        outtextxy(xPos, rowY+boxHeight+5, tbufEnd);
                        rowY += boxHeight+30;
                        xPos = rowStartX;
                    }
                }

                // Show legend
                settextstyle(8, 0, 1);
                setcolor(WHITE);
                outtextxy(600, 180, "Legend:");
                setfillstyle(SOLID_FILL, LIGHTGREEN);
                bar(600, 195, 620, 205);
                setcolor(BLACK);
                rectangle(600, 195, 620, 205);
                setcolor(WHITE);
                outtextxy(625, 197, "Running");
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                bar(600, 210, 620, 220);
                setcolor(BLACK);
                rectangle(600, 210, 620, 220);
                setcolor(WHITE);
                outtextxy(625, 212, "Idle");

                // Wait for user to click back
                while(true) {
                    back.hover(LIGHTRED);
                    if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
                        if(back.cursor()) {
                            menu();
                            return;
                        }
                    }
                }
            }
            else if(back.cursor()) {
                menu();
                break;
            }
        }
    }
}



void bankers_algo()
{
    setbkcolor(DARKGRAY);
    cleardevice();
    Footer();

    settextstyle(8, 0, 3);
    setcolor(WHITE);
    outtextxy(400 - textwidth("Banker's Algorithm")/2, 30, "Banker's Algorithm");

    settextstyle(8, 0, 2);
    new Field(50, 90, 350, 140, GREEN, WHITE, "Processes (P)");
    new Field(400, 90, 700, 140, GREEN, WHITE, "Resources (R)");

    Input pInput, rInput;
    pInput.Name(60, 150, 340, 190);
    rInput.Name(410, 150, 690, 190);

    Button next(300, 210, 500, 250, BLUE, "Next");
    Button back(50, 420, 200, 460, RED, "BACK");

    char pStr[10] = "", rStr[10] = "";
    int p = 0, r = 0;

    while (true) {
        next.hover(GREEN);
        back.hover(LIGHTRED);

        if (GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if (pInput.cursor()) pInput.getName(pStr);
            else if (rInput.cursor()) rInput.getName(rStr);
            else if (next.cursor()) {
                p = atoi(pStr);
                r = atoi(rStr);
                if (p <= 0 || r <= 0) {
                    setcolor(RED);
                    outtextxy(250, 270, "Invalid input! Enter valid numbers.");
                    delay(1000);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(250, 270, 600, 290);
                    continue;
                }
                break;
            }
            else if (back.cursor()) {
                menu();
                return;
            }
        }
    }

    // Input matrices and vectors
    vector<vector<int>> allocation(p, vector<int>(r, 0));
    vector<vector<int>> max_need(p, vector<int>(r, 0));
    vector<vector<int>> rem_need(p, vector<int>(r, 0));
    vector<int> given_resources(r, 0), available(r, 0);

    // Input: Total Available Resources
    cleardevice();
    Footer();
    settextstyle(8, 0, 2);
    outtextxy(100, 100, "Enter total available resources (space separated):");
    Input availInput;
    availInput.Name(100, 150, 700, 190);
    Button next2(300, 210, 500, 250, BLUE, "Next");
    Button back2(50, 420, 200, 460, RED, "BACK");
    char availStr[200] = "";

    while (true) {
        next2.hover(GREEN);
        back2.hover(LIGHTRED);
        if (GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if (availInput.cursor()) availInput.getName(availStr);
            else if (next2.cursor()) {
                istringstream iss(availStr);
                int cnt = 0, val;
                while (iss >> val && cnt < r) given_resources[cnt++] = val;
                if (cnt != r) {
                    setcolor(RED);
                    outtextxy(250, 270, "Enter exactly R values!");
                    delay(1000);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(250, 270, 600, 290);
                    continue;
                }
                break;
            }
            else if (back2.cursor()) {
                menu();
                return;
            }
        }
    }

// ...existing code...

// --- Allocation Matrix Input ---
cleardevice();
Footer();
settextstyle(8, 0, 2);
outtextxy(100, 60, "Enter Allocation Matrix (each row space separated):");
vector<Input> allocInputs(p);
char allocStrs[32][200] = {0}; // supports up to 32 processes, increase if needed
for (int i = 0; i < p; i++) {
    allocInputs[i].Name(180, 100 + i * 40, 700, 130 + i * 40); // Input box starts at x=180
    char label[20];
    sprintf(label, "P%d:", i);
    setcolor(WHITE);
    setbkcolor(DARKGRAY); // or whatever your background is
    outtextxy(120, 110 + i * 40 - textheight(label)/2, label); // Draw label at x=120, vertically centered
}
Button next3(300, 120 + p * 40, 500, 160 + p * 40, BLUE, "Next");
Button back3(50, 420, 200, 460, RED, "BACK");

while (true) {
    next3.hover(GREEN);
    back3.hover(LIGHTRED);
    if (GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
        for (int i = 0; i < p; i++)
            if (allocInputs[i].cursor()) allocInputs[i].getName(allocStrs[i]);
        if (next3.cursor()) {
            bool ok = true;
            for (int i = 0; i < p; i++) {
                istringstream iss(allocStrs[i]);
                int cnt = 0, val;
                while (iss >> val && cnt < r) allocation[i][cnt++] = val;
                if (cnt != r) ok = false;
            }
            if (!ok) {
                setcolor(RED);
                outtextxy(250, 100 + p * 40, "Each row must have R values!");
                delay(1000);
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(250, 100 + p * 40, 700, 120 + p * 40);
                continue;
            }
            break;
        }
        else if (back3.cursor()) {
            menu();
            return;
        }
    }
}

// --- Maximum Need Matrix Input ---
cleardevice();
Footer();
settextstyle(8, 0, 2);
outtextxy(100, 60, "Enter Maximum Need Matrix (each row space separated):");
vector<Input> maxInputs(p);
char maxStrs[32][200] = {0}; // supports up to 32 processes, increase if needed
for (int i = 0; i < p; i++) {
    maxInputs[i].Name(180, 100 + i * 40, 700, 130 + i * 40); // Input box starts at x=180
    char label[20];
    sprintf(label, "P%d:", i);
    setcolor(WHITE);
    setbkcolor(DARKGRAY); // or whatever your background is
    outtextxy(120, 110 + i * 40 - textheight(label)/2, label); // Draw label at x=120, vertically centered
}
Button next4(300, 120 + p * 40, 500, 160 + p * 40, BLUE, "Calculate");
Button back4(50, 420, 200, 460, RED, "BACK");

while (true) {
    next4.hover(GREEN);
    back4.hover(LIGHTRED);
    if (GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
        for (int i = 0; i < p; i++)
            if (maxInputs[i].cursor()) maxInputs[i].getName(maxStrs[i]);
        if (next4.cursor()) {
            bool ok = true;
            for (int i = 0; i < p; i++) {
                istringstream iss(maxStrs[i]);
                int cnt = 0, val;
                while (iss >> val && cnt < r) max_need[i][cnt++] = val;
                if (cnt != r) ok = false;
            }
            if (!ok) {
                setcolor(RED);
                outtextxy(250, 100 + p * 40, "Each row must have R values!");
                delay(1000);
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(250, 100 + p * 40, 700, 120 + p * 40);
                continue;
            }
            break;
        }
        else if (back4.cursor()) {
            menu();
            return;
        }
    }
}

// ...existing code...
    // Calculate remaining need = max - allocation
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            rem_need[i][j] = max_need[i][j] - allocation[i][j];

    // Calculate available = given - allocated
    for (int j = 0; j < r; j++) {
        int sum = 0;
        for (int i = 0; i < p; i++)
            sum += allocation[i][j];
        available[j] = given_resources[j] - sum;
    }

    // Banker's Algorithm
    vector<bool> finished(p, false);
    vector<int> safe_sequence;
    int completed = 0;

    // Show Remaining Need Matrix
    cleardevice();
    Footer();
    settextstyle(8, 0, 2);
    setcolor(YELLOW);
    outtextxy(100, 60, "Remaining Need Matrix:");
    setcolor(WHITE);
    for (int i = 0; i < p; i++) {
        char row[200] = "";
        sprintf(row, "P%d: ", i);
        for (int j = 0; j < r; j++) {
            char buf[10];
            sprintf(buf, "%3d ", rem_need[i][j]);
            strcat(row, buf);
        }
        outtextxy(120, 100 + i * 30, row);
    }
    delay(1500);

    // Run Banker's Algorithm and show result
    while (completed < p) {
        bool found = false;
        for (int i = 0; i < p; i++) {
            if (!finished[i]) {
                bool can_run = true;
                for (int j = 0; j < r; j++) {
                    if (rem_need[i][j] > available[j]) {
                        can_run = false;
                        break;
                    }
                }
                if (can_run) {
                    for (int j = 0; j < r; j++)
                        available[j] += allocation[i][j];
                    finished[i] = true;
                    safe_sequence.push_back(i);
                    completed++;
                    found = true;
                }
            }
        }
        if (!found) break;
    }

    setcolor(YELLOW);
    outtextxy(100, 120 + p * 30, "Result:");
    setcolor(WHITE);
    if (completed == p) {
        char seq[200] = "Safe Sequence: ";
        for (int i = 0; i < safe_sequence.size(); i++) {
            char buf[10];
            sprintf(buf, "P%d", safe_sequence[i]);
            strcat(seq, buf);
            if (i != safe_sequence.size() - 1) strcat(seq, " -> ");
        }
        outtextxy(120, 150 + p * 30, seq);
        outtextxy(120, 180 + p * 30, "System is in a Safe state.");
    } else {
        outtextxy(120, 150 + p * 30, "System is in an Unsafe state.");
    }

    Button back5(50, 420, 200, 460, RED, "BACK");
    while (true) {
        back5.hover(LIGHTRED);
        if (GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if (back5.cursor()) {
                menu();
                return;
            }
        }
    }
}

void bankers_visualization()
{
    setbkcolor(DARKGRAY);
    cleardevice();
    Footer();

    settextstyle(8, 0, 3);
    setcolor(WHITE);
    outtextxy(400 - textwidth("Banker's Visualization")/2, 30, "Banker's Visualization");

    settextstyle(8, 0, 2);
    new Field(50, 90, 350, 140, GREEN, WHITE, "Processes (P)");
    new Field(400, 90, 700, 140, GREEN, WHITE, "Resources (R)");

    Input pInput, rInput;
    pInput.Name(60, 150, 340, 190);
    rInput.Name(410, 150, 690, 190);

    Button next(300, 210, 500, 250, BLUE, "Next");
    Button back(50, 420, 200, 460, RED, "BACK");

    char pStr[10] = "", rStr[10] = "";
    int p = 0, r = 0;

    while (true) {
        next.hover(GREEN);
        back.hover(LIGHTRED);

        if (GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if (pInput.cursor()) pInput.getName(pStr);
            else if (rInput.cursor()) rInput.getName(rStr);
            else if (next.cursor()) {
                p = atoi(pStr);
                r = atoi(rStr);
                if (p <= 0 || r <= 0) {
                    setcolor(RED);
                    outtextxy(250, 270, "Invalid input! Enter valid numbers.");
                    delay(1000);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(250, 270, 600, 290);
                    continue;
                }
                break;
            }
            else if (back.cursor()) {
                menu();
                return;
            }
        }
    }

    // Input matrices and vectors
    vector<vector<int>> allocation(p, vector<int>(r, 0));
    vector<vector<int>> max_need(p, vector<int>(r, 0));
    vector<vector<int>> rem_need(p, vector<int>(r, 0));
    vector<int> given_resources(r, 0), available(r, 0);

    // Input: Total Available Resources
    cleardevice();
    Footer();
    settextstyle(8, 0, 2);
    outtextxy(100, 100, "Enter total available resources (space separated):");
    Input availInput;
    availInput.Name(100, 150, 700, 190);
    Button next2(300, 210, 500, 250, BLUE, "Next");
    Button back2(50, 420, 200, 460, RED, "BACK");
    char availStr[200] = "";

    while (true) {
        next2.hover(GREEN);
        back2.hover(LIGHTRED);
        if (GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if (availInput.cursor()) availInput.getName(availStr);
            else if (next2.cursor()) {
                istringstream iss(availStr);
                int cnt = 0, val;
                while (iss >> val && cnt < r) given_resources[cnt++] = val;
                if (cnt != r) {
                    setcolor(RED);
                    outtextxy(250, 270, "Enter exactly R values!");
                    delay(1000);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(250, 270, 600, 290);
                    continue;
                }
                break;
            }
            else if (back2.cursor()) {
                menu();
                return;
            }
        }
    }

    // ...existing code...

// --- Allocation Matrix Input ---
cleardevice();
Footer();
settextstyle(8, 0, 2);
outtextxy(100, 60, "Enter Allocation Matrix (each row space separated):");
vector<Input> allocInputs(p);
char allocStrs[32][200] = {0}; // supports up to 32 processes, increase if needed
for (int i = 0; i < p; i++) {
    allocInputs[i].Name(180, 100 + i * 40, 700, 130 + i * 40); // Input box starts at x=180
    char label[20];
    sprintf(label, "P%d:", i);
    setcolor(WHITE);
    setbkcolor(DARKGRAY); // or whatever your background is
    outtextxy(120, 110 + i * 40 - textheight(label)/2, label); // Draw label at x=120, vertically centered
}
Button next3(300, 120 + p * 40, 500, 160 + p * 40, BLUE, "Next");
Button back3(50, 420, 200, 460, RED, "BACK");

while (true) {
    next3.hover(GREEN);
    back3.hover(LIGHTRED);
    if (GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
        for (int i = 0; i < p; i++)
            if (allocInputs[i].cursor()) allocInputs[i].getName(allocStrs[i]);
        if (next3.cursor()) {
            bool ok = true;
            for (int i = 0; i < p; i++) {
                istringstream iss(allocStrs[i]);
                int cnt = 0, val;
                while (iss >> val && cnt < r) allocation[i][cnt++] = val;
                if (cnt != r) ok = false;
            }
            if (!ok) {
                setcolor(RED);
                outtextxy(250, 100 + p * 40, "Each row must have R values!");
                delay(1000);
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(250, 100 + p * 40, 700, 120 + p * 40);
                continue;
            }
            break;
        }
        else if (back3.cursor()) {
            menu();
            return;
        }
    }
}

// --- Maximum Need Matrix Input ---
cleardevice();
Footer();
settextstyle(8, 0, 2);
outtextxy(100, 60, "Enter Maximum Need Matrix (each row space separated):");
vector<Input> maxInputs(p);
char maxStrs[32][200] = {0}; // supports up to 32 processes, increase if needed
for (int i = 0; i < p; i++) {
    maxInputs[i].Name(180, 100 + i * 40, 700, 130 + i * 40); // Input box starts at x=180
    char label[20];
    sprintf(label, "P%d:", i);
    setcolor(WHITE);
    setbkcolor(DARKGRAY); // or whatever your background is
    outtextxy(120, 110 + i * 40 - textheight(label)/2, label); // Draw label at x=120, vertically centered
}
Button next4(300, 120 + p * 40, 500, 160 + p * 40, BLUE, "Calculate");
Button back4(50, 420, 200, 460, RED, "BACK");

while (true) {
    next4.hover(GREEN);
    back4.hover(LIGHTRED);
    if (GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
        for (int i = 0; i < p; i++)
            if (maxInputs[i].cursor()) maxInputs[i].getName(maxStrs[i]);
        if (next4.cursor()) {
            bool ok = true;
            for (int i = 0; i < p; i++) {
                istringstream iss(maxStrs[i]);
                int cnt = 0, val;
                while (iss >> val && cnt < r) max_need[i][cnt++] = val;
                if (cnt != r) ok = false;
            }
            if (!ok) {
                setcolor(RED);
                outtextxy(250, 100 + p * 40, "Each row must have R values!");
                delay(1000);
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(250, 100 + p * 40, 700, 120 + p * 40);
                continue;
            }
            break;
        }
        else if (back4.cursor()) {
            menu();
            return;
        }
    }
}

// ...existing code...
    // Calculate remaining need = max - allocation
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            rem_need[i][j] = max_need[i][j] - allocation[i][j];

    // Calculate available = given - allocated
    for (int j = 0; j < r; j++) {
        int sum = 0;
        for (int i = 0; i < p; i++)
            sum += allocation[i][j];
        available[j] = given_resources[j] - sum;
    }

    // Animated Banker's Algorithm Visualization
    cleardevice();
    Footer();
    settextstyle(8, 0, 2);
    setcolor(YELLOW);
    outtextxy(100, 30, "Banker's Algorithm Visualization");

    // Draw table headers
    setcolor(CYAN);
    outtextxy(100, 70, "Process");
    outtextxy(200, 70, "Allocation");
    outtextxy(350, 70, "Max");
    outtextxy(500, 70, "Need");
    outtextxy(650, 70, "Finished");

    // Draw initial table
    for (int i = 0; i < p; i++) {
        char row[300] = "";
        sprintf(row, "P%d", i);
        setcolor(WHITE);
        outtextxy(100, 100 + i * 30, row);

        // Allocation
        char alloc[100] = "";
        for (int j = 0; j < r; j++) {
            char buf[10];
            sprintf(buf, "%2d ", allocation[i][j]);
            strcat(alloc, buf);
        }
        outtextxy(200, 100 + i * 30, alloc);

        // Max
        char maxx[100] = "";
        for (int j = 0; j < r; j++) {
            char buf[10];
            sprintf(buf, "%2d ", max_need[i][j]);
            strcat(maxx, buf);
        }
        outtextxy(350, 100 + i * 30, maxx);

        // Need
        char need[100] = "";
        for (int j = 0; j < r; j++) {
            char buf[10];
            sprintf(buf, "%2d ", rem_need[i][j]);
            strcat(need, buf);
        }
        outtextxy(500, 100 + i * 30, need);

        // Finished
        outtextxy(650, 100 + i * 30, "No");
    }

    // Show Available vector
    setcolor(YELLOW);
    outtextxy(100, 120 + p * 30, "Available:");
    char avail[100] = "";
    for (int j = 0; j < r; j++) {
        char buf[10];
        sprintf(buf, "%2d ", available[j]);
        strcat(avail, buf);
    }
    setcolor(WHITE);
    outtextxy(220, 120 + p * 30, avail);

    // Animation: Step by step
    vector<bool> finished(p, false);
    vector<int> safe_sequence;
    int completed = 0;
    int step = 0;
    int yBase = 100;

    while (completed < p) {
        bool found = false;
        for (int i = 0; i < p; i++) {
            if (!finished[i]) {
                bool can_run = true;
                for (int j = 0; j < r; j++) {
                    if (rem_need[i][j] > available[j]) {
                        can_run = false;
                        break;
                    }
                }
                if (can_run) {
                    // Highlight current row
                    setfillstyle(SOLID_FILL, LIGHTGREEN);
                    bar(95, yBase + i * 30 - 2, 780, yBase + i * 30 + 22);

                    // Redraw row text
                    setcolor(BLACK);
                    char row[300] = "";
                    sprintf(row, "P%d", i);
                    outtextxy(100, yBase + i * 30, row);

                    char alloc[100] = "";
                    for (int j = 0; j < r; j++) {
                        char buf[10];
                        sprintf(buf, "%2d ", allocation[i][j]);
                        strcat(alloc, buf);
                    }
                    outtextxy(200, yBase + i * 30, alloc);

                    char maxx[100] = "";
                    for (int j = 0; j < r; j++) {
                        char buf[10];
                        sprintf(buf, "%2d ", max_need[i][j]);
                        strcat(maxx, buf);
                    }
                    outtextxy(350, yBase + i * 30, maxx);

                    char need[100] = "";
                    for (int j = 0; j < r; j++) {
                        char buf[10];
                        sprintf(buf, "%2d ", rem_need[i][j]);
                        strcat(need, buf);
                    }
                    outtextxy(500, yBase + i * 30, need);

                    outtextxy(650, yBase + i * 30, "No");

                    delay(800);

                    // Update available
                    for (int j = 0; j < r; j++)
                        available[j] += allocation[i][j];
                    finished[i] = true;
                    safe_sequence.push_back(i);
                    completed++;
                    found = true;

                    // Mark as finished
                    setcolor(GREEN);
                    outtextxy(650, yBase + i * 30, "Yes");

                    // Update Available vector
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(220, 120 + p * 30, 700, 140 + p * 30);
                    setcolor(WHITE);
                    char avail2[100] = "";
                    for (int j = 0; j < r; j++) {
                        char buf[10];
                        sprintf(buf, "%2d ", available[j]);
                        strcat(avail2, buf);
                    }
                    outtextxy(220, 120 + p * 30, avail2);

                    delay(1000);

                    // Remove highlight
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(95, yBase + i * 30 - 2, 780, yBase + i * 30 + 22);

                    // Redraw row text
                    setcolor(WHITE);
                    outtextxy(100, yBase + i * 30, row);
                    outtextxy(200, yBase + i * 30, alloc);
                    outtextxy(350, yBase + i * 30, maxx);
                    outtextxy(500, yBase + i * 30, need);
                    setcolor(GREEN);
                    outtextxy(650, yBase + i * 30, "Yes");

                    break; // Only one process per step
                }
            }
        }
        if (!found) break;
    }

    // Show result
    setcolor(YELLOW);
    outtextxy(100, 160 + p * 30, "Result:");
    setcolor(WHITE);
    if (completed == p) {
        char seq[200] = "Safe Sequence: ";
        for (int i = 0; i < safe_sequence.size(); i++) {
            char buf[10];
            sprintf(buf, "P%d", safe_sequence[i]);
            strcat(seq, buf);
            if (i != safe_sequence.size() - 1) strcat(seq, " -> ");
        }
        outtextxy(120, 190 + p * 30, seq);
        outtextxy(120, 220 + p * 30, "System is in a Safe state.");
    } else {
        outtextxy(120, 190 + p * 30, "System is in an Unsafe state.");
    }

    Button back5(50, 420, 200, 460, RED, "BACK");
    while (true) {
        back5.hover(LIGHTRED);
        if (GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
            if (back5.cursor()) {
                menu();
                return;
            }
        }
    }
}