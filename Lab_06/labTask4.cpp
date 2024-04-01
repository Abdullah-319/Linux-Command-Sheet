#include <bits/stdc++.h>
#include <sys/wait.h>

using namespace std;

int main()
{   
    //Task1
    //print current directory.
    	
    //string instruction = "pwd";
    //const char *command = instruction.c_str();
    //system(command);



    //Task2
    //print contents of directory in long format.

    //string instruction = "ls -l";
    //const char *command = instruction.c_str();
    //system(command);
    
    
    
    //Task3
    //print the current date and time

    //string instruction = "date";
    //const char *command = instruction.c_str();
    //system(command);
    
    
    
    
    //Task4
    //create file using Cat and add your name, roll no and your 10 skills.
    
    system("echo 'Name: Abdullah Ahmad' | cat >> hello.txt");
    system("echo 'Roll No: SP22-BCS-045' | cat >> hello.txt");
    system("echo 'Skills:' | cat >> hello.txt");
    system("echo '1. Python programming' | cat >> hello.txt");
    system("echo '2. Data analysis' | cat >> hello.txt");
    system("echo '3. Machine learning' | cat >> hello.txt");
    system("echo '4. Web development' | cat >> hello.txt");
    system("echo '5. Problem solving' | cat >> hello.txt");
    system("echo '6. Communication' | cat >> hello.txt");
    system("echo '7. Leadership' | cat >> hello.txt");
    system("echo '8. Time management' | cat >> hello.txt");
    system("echo '9. Teamwork' | cat >> hello.txt");
    system("echo '10. Critical thinking' | cat >> hello.txt");

    //string skills = "cat > skills.txt <<EOF\n"
    //                 "Name: Abdullah Ahmad\n"
    //                 "Roll No: SP22-BCS-045\n"
    //                 "Skills:\n"
    //                 "1. Python programming\n"
    //                 "2. Data analysis\n"
    //                 "3. Machine learning\n"
    //                 "4. Web development\n"
    //                 "5. Problem solving\n"
    //                 "6. Communication\n"
    //                 "7. Leadership\n"
    //                 "8. Time management\n"
    //                 "9. Teamwork\n"
    //                 "10. Critical thinking\n"
    //                 "EOF";
                     
    
        
    //	const char *cmd = skills.c_str();
    //	system(cmd);
    	
    //	string instruction = "cat skills.txt";
    //	const char *command = instruction.c_str();
    //	system(command);
    
    
    
    //Task5
    //print its contents on the terminal using head and tail.

    //string instruction = "head skills.txt -n 7";
    //const char *command = instruction.c_str();
    //system(command);
    
    
    //string instruction = "tail skills.txt -n 7";
    //const char *command = instruction.c_str();
    //system(command);




    //Task6
    //ask user to enter a specific extension and search the current directory with files of that extension.

    // string ext;
    // cout<<"Enter the extension of the files you want to search (.txt): ";
    // cin>>ext;

    // string instruction = "ls *"+ext;
    // const char *command = instruction.c_str();
    // system(command);

    
    
    
    //Task7
    //print the current running process.

    // cout<<"Printing current running processes: ";

    // string instruction = "ps aux";
    // const char *command = instruction.c_str();
    // system(command);


    return 0;
}
