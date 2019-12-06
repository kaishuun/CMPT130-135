
#include <iostream>
#include <fstream>
#include <string>
#include "cmpt_error.h"

using namespace std;
int num_lines(string file_name);
int num_chars(string file_name);
int num_words(string file_name);
bool find_file(string file_name);
bool check_empty_file(string file_name);

int main() {

	ifstream fin("commands.txt");//summons the file commands.txt

	if (fin.fail()){//if it fails to open it ends the program
		cout << "Sorry, it doesn't seem that the file"
		" is in the same folder as this program";
		return false;
	}// if fin fail

	 if(!check_empty_file("commands.txt") || num_words("commands.txt") == 0){//if commands.txt is empty then it ends the program
	 	cout << "commands.txt is empty!";
	 	return false;
	 }


	string command, file;
	int count = 0;
	char f = fin.get();//gets the first char in fin

		while(true){//repeats functions til end
			while (f == ' '){//skips spaces
				f = fin.get();
			}// whil f = ' '
			while( f != ' ' && f != '\n'){
				command += f;
				f = fin.get();
			}//line that gathers commands

			while (f == ' '){//does nothing if f is a space
				f = fin.get();
			}
			while(f != ' ' && f != '\n'){//gathers file name
				file += f;
				f = fin.get();
				}//else

			while (f == ' '){//does nothing if f is a space
				f = fin.get();
			}
			if( f != ' ' || f != '\n'){// if there are excessive strings after the 2 commands, adds 1 to count, and skips the strings
				while(f != '\n'){
					f = fin.get();
					count++;
				}//while
			}//if
		while( f == '\n'){//runs the commands &  files when it hits the end of the line
			if (count >= 1){//if count >= 1, it means that there are more than two words in a row
				cout << "there are more than 1 commands or files in this row";
			}else if (command.empty() && file.empty()){//does nothing if the row is empty

			}else if (command.empty()){//if only the command is empty, couts no command error
				cout << "There is no command\n";
			}else if (file.empty()){//if only the file is empty, couts no file error
				cout << "There is no file for the command: " << command << "\n";
			}else if ( command != "num_lines" && command != "num_words" && command != "num_chars"){//error msg if command is not one of the three available ones
				cout << "the command: " << command << " is not valid!\n";
			}else if(command == "num_lines"){//command num_lines
				if(find_file(file) == true){//finds the file, returns error if the file isnt found
					int lines = num_lines(file);
					cout << file << " has " << lines << " lines\n";
				}else{
					cout << "couldn't find the file: " << file << " for the command " << command << "\n";
				}
			}else if (command == "num_chars"){//command num_chars
				if(find_file(file) == true){//finds the file, returns error if the file isnt found
					int char_count = num_chars(file);
					cout << file << " has " << char_count << " characters\n";
				}else{
					cout << "couldn't find the file: " << file << " for the command " << command << "\n";
				}
			}else if (command == "num_words"){//command num_words
				if(find_file(file) == true){//finds the file, returns error if the file isnt found
					int word_count = num_words(file);
					cout << file << " has " << word_count << " words\n";
				}else{
					cout << "couldn't find the file: " << file << " for the command " << command << "\n";
				}
			}
			f = fin.get();
			if (fin.eof()){//stops program if eof is reached
				return false;
			}
			command = "";//clears and resets variables
			file = "";
			count = 0;
		}//while
		}//main while loop
}//main

int num_lines(string file_name){//counts for number of lines in a file
	int count = 0;
	ifstream fin(file_name);

	char n = fin.get();
	while(!fin.eof()){
		if(n == '\n'){
			++count;
		}//if
		n = fin.get();
	}//while
	return count;
}
int num_chars(string file_name){//counts for number of chars in a file, including space and \n
	int char_num = 0;
	ifstream fin(file_name);

	char n = fin.get();
	while (!fin.eof()){
		if (n == ' ' || n == '\n'){
			++char_num;
		}else{
			++char_num;
		}//else
		n = fin.get();
	}//while
	return char_num;
}
int num_words(string file_name){//counts number of whole words in the file
	string word;
	int count = 0;
	ifstream fin(file_name);

	while ( fin >> word ){
		count++;
	}
	return count;
}//num words

bool find_file(string file_name){//locates file, if it fails returns false, if it passes return true
	ifstream fin(file_name);

	if(fin.fail()){
		return false;
	}else {
		return true;
	}
}

bool check_empty_file(string file_name){//checks if file is empty
	ifstream fin(file_name);
	fin.seekg(0, fin.end);  
		if (fin.tellg() == 0) {    
	  	return false;
		}else {
			return true;
		}//else

}//check_empty_file
