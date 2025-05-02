#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

void read();
void write();
void clear();
void help();
void dt();
void exits();
void startscreen();
void rm();
void ls();
void whoami();
void pwd();
void mkdir();
void dir();
void touch();
void cd();
void cp();
void echo();
void sleep();
void head();
void tail();
void less();
void nano();
void uname();
void hostname();
void find();
void w();
void ps();
void cat();

int main()
{
    char a[100];

    cout << "Noman17's Terminal\n\n";

    dt();
    cout << "Welcome To Noman17's Terminal\n";
    cout << "Type \"help\" for more things!\n\n";

    while (true)
    {
        cout << ">>> ";
        cin >> a;

        if (strcmp(a, "read") == 0)
        {
            read();
        }
        else if (strcmp(a, "write") == 0)
        {
            write();
        }
        else if (strcmp(a, "clr") == 0)
        {
            clear();
        }
        else if (strcmp(a, "help") == 0)
        {
            help();
        }
        else if (strcmp(a, "dt") == 0)
        {
            dt();
        }
        else if (strcmp(a, "stscr") == 0)
        {
            startscreen();
        }
        else if (strcmp(a, "rm") == 0)
        {
            rm();
        }
        else if (strcmp(a, "ls") == 0)
        {
            ls();
        }
        else if (strcmp(a, "whoami") == 0)
        {
            whoami();
        }
        else if (strcmp(a, "pwd") == 0)
        {
            pwd();
        }
        else if (strcmp(a, "mkdir") == 0)
        {
            mkdir();
        }
        else if (strcmp(a, "dir") == 0)
        {
            dir();
        }
        else if (strcmp(a, "touch") == 0)
        {
            touch();
        }
        else if (strcmp(a, "cd") == 0)
        {
            cd();
        }
        else if (strcmp(a, "cp") == 0)
        {
            cp();
        }
        else if (strcmp(a, "rm") == 0)
        {
            rm();
        }
        else if (strcmp(a, "echo") == 0)
        {
            echo();
        }
        else if (strcmp(a, "sleep") == 0)
        {
            sleep();
        }
        else if (strcmp(a, "head") == 0)
        {
            head();
        }
        else if (strcmp(a, "tail") == 0)
        {
            tail();
        }
        else if (strcmp(a, "less") == 0)
        {
            less();
        }
        else if (strcmp(a, "nano") == 0)
        {
            nano();
        }
        else if (strcmp(a, "uname") == 0)
        {
            uname();
        }
        else if (strcmp(a, "hostname") == 0)
        {
            hostname();
        }
        else if (strcmp(a, "find") == 0)
        {
            find();
        }
        else if (strcmp(a, "w") == 0)
        {
            w();
        }
        else if (strcmp(a, "ps") == 0)
        {
            ps();
        }
        else if (strcmp(a, "cat") == 0)
        {
            cat();
        }
        else if (strcmp(a, "exit") == 0)
        {
            exits();
        }
        else
        {
            cout << "Enter only stated things in help\n";
        }
    }

    return 0;
}

void read()
{
    char command[100];
    cout << "Enter a Linux command: ";
    cin.ignore();
    cin.getline(command, 100);

    // Execute the command and print its output
    system(command);
}

void write()
{
    // Execute the "ls -l" command
    system("ls -l");

    // Execute the "echo Hello World" command
    system("echo Hello World");
}

void clear()
{
    system("clear");
}

void dt()
{
    time_t tt = time(NULL);
    cout << ctime(&tt);
}

void startscreen()
{
    system("clear");
    cout << "Noman17 Terminal\n\n";
    dt();
    cout << "Welcome To  Noman17 Terminal\n";
    cout << "Type \"help\" for more things!\n\n";
}

void rm()
{
    char a[100];
    int m;

    cout << "Enter a file name to remove: ";
    cin >> a;

    m = remove(a);

    if (m == 0)
    {
        cout << "Successfully removed a file\n";
    }
    else
    {
        cout << "Error in removing. Please check if the file exists in the directory\n";
    }
}

void ls()
{
    system("ls");
}

void whoami()
{
    system("whoami");
}

void pwd()
{
    system("pwd");
}

void mkdir()
{
    system("mkdir A");
}

void dir()
{
    system("dir");
}

void touch()
{
    system("touch B");
}

void cd()
{
    system("cd mydir");
}

void cp()
{
    system("cp B h");
}

void echo()
{
    char *text = "Hello, world!"; // The text to be echoed
    char command[100];            // The command to be executed

    // Construct the command string
    sprintf(command, "echo '%s'", text);

    // Execute the command
    system(command);
}

void sleep()
{
    int sleep_time = 5;          // set sleep time in seconds
    char command[50];
    sprintf(command, "sleep %d", sleep_time); // create command string
    system(command);                          // execute command using system function
}

void head()
{
    char command[100];
    int n;

    cout << "Enter the number of lines to display: ";
    cin >> n;

    // build the command string using sprintf
    sprintf(command, "head -n %d Paragraph.txt", n);

    // execute the command using system
    system(command);
}

void tail()
{
    int n;                    // Number of lines to display from end of file
    char command[50];         // Buffer to store the command string

    cout << "Enter the number of lines to display: ";
    cin >> n;

    // Form the command string with user-specified number of lines
    sprintf(command, "tail -n %d Paragraph.txt", n);

    // Execute the command using system() function
    system(command);
}

void less()
{
    char filename[100];
    cout << "Enter filename to display: ";
    cin >> filename;
    char command[200];
    sprintf(command, "less %s", filename);
    system(command);
}

void nano()
{
    system("nano");
}

void uname()
{
    system("uname -a"); // execute the uname command
}

void hostname()
{
    system("hostname");
}

void find()
{
    system("find");
}

void w()
{
    system("w");
}

void ps()
{
    system("ps");
}

void cat()
{
    system("cat");
}

void help()
{
    cout << "\n";
    cout << "You can enter the following commands:\n\n";
    cout << "write  >>> To write to a file\n";
    cout << "read   >>> To read from a file\n";
    cout << "rm     >>> To remove a file\n";
    cout << "clr    >>> To clear the screen\n";
    cout << "dt     >>> To show date and time\n";
    cout << "stscr  >>> To show start screen\n";
    cout << "ls     >>> To execute ls\n";
    cout << "whoami >>> To execute whoami\n";
    cout << "pwd    >>> To execute pwd\n";
    cout << "mkdir  >>> To execute mkdir\n";
    cout << "dir    >>> To execute dir\n";
    cout << "touch  >>> To execute touch\n";
    cout << "cd     >>> To execute cd\n";
    cout << "cp     >>> To execute cp\n";
    cout << "echo   >>> To execute echo\n";
    cout << "sleep  >>> To execute sleep\n";
    cout << "head   >>> To execute head\n";
    cout << "tail   >>> To execute tail\n";
    cout << "less   >>> To execute less\n";
    cout << "nano   >>> To execute nano\n";
    cout << "uname  >>> To execute uname\n";
    cout << "hostname>>> To execute hostname\n";
    cout << "find   >>> To execute find\n";
    cout << "w      >>> To execute w\n";
    cout << "ps     >>> To execute ps\n";
    cout << "cat    >>> To execute cat\n";
    cout << "exit   >>> To exit\n";
    cout << "\n";
}

void exits()
{
    exit(1);
}
