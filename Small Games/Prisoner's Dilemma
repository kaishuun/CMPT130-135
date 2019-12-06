int main() {
	cout << "----------------------------------------\n"
	<< "Welcome to the Prisoner's Dillemma Game!\n"
	<< "----------------------------------------\n"
	<< "\nHow many rounds would you like to play? "; //Outputs game title and asks for # of rounds the user wants to play
	int game_num = 0;
	cin >> game_num ;
	cout << "\n";

	if (game_num <= 0) { //if user inputs 0 or less rounds, output error statement
		cmpt::error("Sorry, we need more than 0 rounds to play!");
	} 
	else { //if user inputs 1 or more rounds, begin game

	cout << "Okay, " << game_num << " rounds it is.\n"; }


	int round = 1;//minimum number of rounds is 1
	char ans;
	char cmpt_ans = 'c';//computer always cooperates on turn 1
	int pts_usr = 0;
	int pts_cmpt = 0;

	while (game_num > 0) {
		cout << "\n" << "Round " << round << ": Cooperate (c) or defect (d)? "; //inputs cooperate(c) or defect (d)
		cin >> ans;

		if(ans == 'c' && cmpt_ans == 'c'){ //if user and computer inputs (c), output resultant
			cout << "         You chose cooperate.\n"
			"         The computer chose cooperate.\n"
			"         You get 1 penalty point.\n"
			"         The computer gets 1 penalty point.\n";
			++pts_usr; //adds penalty points
			++pts_cmpt;
		}
		if(ans == 'd' && cmpt_ans == 'd'){ //if user and computer inputs (d), output resultant
			cout << "         You chose defect.\n"
			"         The computer chose defect.\n"
			"         You get 2 penalty points.\n"
			"         The computer gets 2 penalty points.\n";
			pts_usr = pts_usr + 2; //adds penalty points
			pts_cmpt = pts_cmpt +2; 
		}
		if(ans == 'c' && cmpt_ans == 'd'){ //if user inputs (c) and computer inputs (d), output resultant
			cout << "         You chose cooperate.\n"
			"         The computer choose defect.\n"
			"         You get 3 penalty points.\n"
			"         The computer gets 0 penalty points.\n";
			cmpt_ans = ans; //uses tit by tat strategy by making the computer's answer equal to the old answer
			pts_usr = pts_usr + 3; //adds penalty points
		}
		if(ans == 'd' && cmpt_ans == 'c'){ //if user inputs (d) and computer inputs (c), output resultant
			cout << "         You chose defect.\n"
			"         The computer chose cooperate.\n"
			"         You get 0 penalty points.\n"
			"         The computer gets 3 penalty points.\n";
			cmpt_ans = ans;//uses tit by tat strategy by making the computer's answer equal to the old answer
			pts_cmpt = pts_cmpt + 3;//adds penalty points
		}
		else{//if the entry is not (c) or (d) output error
			cmpt::error("Sorry, that is not a valid entry!\n");
		}
		 game_num-- ; //decreases game number until it hits 0
		 round++ ; //increase round number
	}

	cout << "\nGame over! \n";
	cout << "\nYou have a total of " << pts_usr << " penalty points.\n"; //Outputs user penalty points
	cout << "The computer has a total of " << pts_cmpt << " penalty points\n"; //outputs computer's penalty points
	if (pts_usr < pts_cmpt) { //if computer has more penalty points, output "you win"
		cout << "\nYou win! \n";
	}
	if (pts_usr == pts_cmpt) { //If penalty points are equal, output "it's a tie"
		cout << "\nIt's a tie!\n";
	}
	if (pts_cmpt < pts_usr) { //if user has more penalty points, output "you lose"
		cout << "\nYou Lost!\n";
	}

}
