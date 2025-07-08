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

void fifo_algo();
void lru_algorithm();
void page_optimal_algorithm();
void fifo_visualization();
void lru_visualization();
void page_optimal_visualization();


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


Button fifo(125, 230, 395, 290, BLUE, "FIFO");
Button fifoVis(405, 230, 675, 290, BLUE, "FIFO Visual");

Button lru(125, 300, 395, 360, BLUE, "LRU");
Button lruVis(405, 300, 675, 360, BLUE, "LRU Visual");

Button pageOpt(125, 370, 395, 430, BLUE, "Page Optimal");
Button pageOptVis(405, 370, 675, 430, BLUE, "Optimal Visual");

Button aboutMe(125, 440, 675, 500, MAGENTA, "About Us");
Button ext(125, 510, 675, 570, MAGENTA, "Exit");


    while(true)
    {
        //hovering over menu
        info.hover(GREEN);
        reginput.hover(GREEN);
        astatment.hover(GREEN);
        aboutMe.hover(GREEN);
        ptree.hover(GREEN);
        fifo.hover(GREEN);
        fifoVis.hover(GREEN);
        lru.hover(GREEN);
        lruVis.hover(GREEN);
        pageOpt.hover(GREEN);
        pageOptVis.hover(GREEN);
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

}


void page_optimal_visualization(){

}
