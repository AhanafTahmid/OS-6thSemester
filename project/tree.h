
// #include <graphics.h>
// #include <bits/stdc++.h>
// using namespace std;
// char name1[200] = "";//expression

// struct TreeNode {
//     string value;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
// };

// /////////foooter for tree 
// void Footers() {
//     setfillstyle(SOLID_FILL, CYAN);
//     settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
//     setbkcolor(CYAN);
//     outtextxy(500 - textwidth("Developed By Spartan")/2, 585 - textheight("A") / 2, "Developed By Spartan");
//     settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
// }


// void drawNode(int x, int y, const string& value, int color = WHITE) {
//     setcolor(color);
//     setfillstyle(SOLID_FILL, color);
//     circle(x, y, 20);
//     floodfill(x, y, color);

//     setbkcolor(color);
//     settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
//     setcolor(BLACK);

//     outtextxy(x - 10, y - 10, (char*)value.c_str());
// }


// void drawLine(int x1, int y1, int x2, int y2) {
//     setcolor(WHITE);
//     line(x1, y1, x2, y2);
// }

// void visualizeTree(TreeNode* root, int x, int y, int xOffset, int level = 0) {
//     if (!root) return;

//     drawNode(x, y, root->value, LIGHTBLUE);

//     // Draw leff
//     if (root->left) {
//         drawLine(x, y + 20, x - xOffset, y + 80);
//         visualizeTree(root->left, x - xOffset, y + 80, xOffset / 2, level + 1);
//     }

//     // Draw right
//     if (root->right) {
//         drawLine(x, y + 20, x + xOffset, y + 80);
//         visualizeTree(root->right, x + xOffset, y + 80, xOffset / 2, level + 1);
//     }
// }

// // construct a parsing tree from a mathematical expression
// TreeNode* constructTree(const string& expression) {
//     stack<TreeNode*> nodes;   // Stack for operand nodes
//     stack<char> operators;    // Stack for operators

//     for (char ch : expression) {
//         if (isspace(ch)) continue; // Skip spaces

//         // If character is a digit or variable, create a node
//         if (isalnum(ch)) {
//             nodes.push(new TreeNode(string(1, ch)));
//         }
//         // If character is an operator
//         else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
//             while (!operators.empty() &&
//                    ((ch == '+' || ch == '-') || (ch == '*' || ch == '/')) &&
//                    (operators.top() == '*' || operators.top() == '/')) {
//                 // Process higher precedence operators
//                 char op = operators.top();
//                 operators.pop();

//                 TreeNode* right = nodes.top(); nodes.pop();
//                 TreeNode* left = nodes.top(); nodes.pop();

//                 TreeNode* newNode = new TreeNode(string(1, op));
//                 newNode->left = left;
//                 newNode->right = right;

//                 nodes.push(newNode);
//             }
//             operators.push(ch);
//         }
//         // If opening parenthesis, push to operator stack
//         else if (ch == '(') {
//             operators.push(ch);
//         }
//         // If closing parenthesis, process until opening parenthesis
//         else if (ch == ')') {
//             while (!operators.empty() && operators.top() != '(') {
//                 char op = operators.top();
//                 operators.pop();

//                 TreeNode* right = nodes.top(); nodes.pop();
//                 TreeNode* left = nodes.top(); nodes.pop();

//                 TreeNode* newNode = new TreeNode(string(1, op));
//                 newNode->left = left;
//                 newNode->right = right;

//                 nodes.push(newNode);
//             }
//             if (!operators.empty() && operators.top() == '(') {
//                 operators.pop(); // Remove the opening parenthesis
//             }
//         }
//     }

//     // Process any remaining operators
//     while (!operators.empty()) {
//         char op = operators.top();
//         operators.pop();

//         TreeNode* right = nodes.top(); nodes.pop();
//         TreeNode* left = nodes.top(); nodes.pop();

//         TreeNode* newNode = new TreeNode(string(1, op));
//         newNode->left = left;
//         newNode->right = right;

//         nodes.push(newNode);
//     }

//     // The remaining node is the root of the tree
//     return nodes.empty() ? nullptr : nodes.top();
// }


// void visualizeParsingTree(const string& expression) {
//     cleardevice();
//     TreeNode* root = constructTree(expression);

//     if (!root) {
//         cout << "Invalid expression!\n";
//         return;
//     }

//     // Visualize the tree
//     visualizeTree(root, getmaxx() / 2, 50, getmaxx() / 4);
// }


// void tree_input() {
//     setbkcolor(LIGHTCYAN);
//     cleardevice();
//     Footers();
//     settextstyle(8, 0, 2);
//     new Field(100, 350, 350, 400, GREEN,WHITE, "ENT. Exp.");
//     Button back(15, 525, 130, 565, BLUE, "Exit");
//     Input exp;
//     exp.Name(350, 350,700, 400);
//     Button submit(370,430,450,480, BLUE, "OK");

//     while(true) {
//         int tr=0;
//         submit.hover(GREEN);
//         if(GetAsyncKeyState(VK_LBUTTON) & (0x8000 != 0)) {
//             if(exp.cursor()){ exp.getName(name1); tr=1; }
//             else if(submit.cursor()) {
//                 visualizeParsingTree(name1);
//             }
//             else if(back.cursor()) {
//                 closegraph();
//             }
//         }
//     }
// }


// int drawwwwwwww() {
//     int gd = DETECT, gm;
//     initgraph(&gd, &gm, "");

//     tree_input();
//     //string expression = "(a+b)+c+d";
//     //visualizeParsingTree(expression);
//     getch();
//     closegraph();
//     return 0;
// }
