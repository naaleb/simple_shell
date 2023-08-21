# Simple Shell Project
This is a simple shell project written in C that implements a basic command-line interface. The shell allows users to input simple commands and executes them. 


#Features:

 •	Displays a prompt and waits for the user to type a command.
 
 •	The prompt is redisplayed after each command execution.
 
 •	Supports simple command lines with no semicolons, pipes, redirections, or advanced features.
 
 •	Command lines are made up of a single word (no arguments).
 
 •	Handles cases where an executable program cannot be found, showing an error message before displaying the prompt again.
 
 •	Handles errors gracefully.
 
 •	Recognizes the "end of file" condition (Ctrl+D).
 
 •	Handles command lines with arguments.
 
 •	Handles the PATH to locate executable programs.
 
 •	Implements the exit built-in command, allowing users to exit the shell. Usage: exit.
 
 •	Implements the env built-in command, which prints the current environment.


#Usage:
 1.	Clone the repository to your local machine:
 	https://github.com/naaleb/simple_shell.git
 2.	Navigate to the project directory:
 	cd simple-shell-project 
 3.	Compile the code using your preferred C compiler (e.g., gcc):
 	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
 4.	Run the shell:
 ./hsh
 5.	You will see a prompt where you can enter commands. Type a command and press Enter to execute it.
 6.	To exit the shell, use the built-in exit command:
 exit 

#Authors:

•	Hermas

•	Almond

#Contributions:

Contributions to this project are welcome! If you encounter any issues or would like to suggest improvements, please create an issue or submit a pull request.
 
