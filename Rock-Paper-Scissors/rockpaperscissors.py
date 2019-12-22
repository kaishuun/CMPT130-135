#rock paper scissors

import random
import time

choices = ["rock","paper","scissors"]

#intro screen
print("Welcome to Rock Paper Scissors")

rounds = input("How many rounds would you like to play? ")
print("\n")

usrscore = 0;
compscore = 0;

for i in range(int(rounds)):
  print("Round " + str(i+1) + " Start! ")
  usr = "null";
  #user choosing rps
  while usr not in choices:
    usr = input("What do you pick? ").lower().strip("!@#.,? ")
  
  #comp choosing rps
  comp = random.choice(choices)

  #rps shoot
  for i in range(len(choices)):
    print(choices[i])
    time.sleep(1)
  print("shoot! \n\n You chose: " + usr + "\n Computer Chose: " + comp + "\n\n" )

  #winner declaration
  if usr == "rock" and comp == "scissors":
    print("You Win!")
    usrscore += 1
    print("computer: " + str(compscore) + "\n" + "user: " + str(usrscore))
  elif usr == "rock" and comp == "paper":
    print("Computer Wins!")
    compscore += 1
    print("computer: " + str(compscore) + "\n" + "user: " + str(usrscore))
  elif usr == "rock" and comp == "rock":
    print("It's a Tie!")
    print("computer: " + str(compscore) + "\n" + "user: " + str(usrscore))
  elif usr == "paper" and comp == "scissors":
    print("Computer Wins!")
    compscore += 1
    print("computer: " + str(compscore) + "\n" + "user: " + str(usrscore))
  elif usr == "paper" and comp == "paper":
    print("It's a Tie!")
    print("computer: " + str(compscore) + "\n" + "user: " + str(usrscore))
  elif usr == "paper" and comp == "rock":
    print("You Win!")
    usrscore += 1
    print("computer: " + str(compscore) + "\n" + "user: " + str(usrscore))
  elif usr == "scissors" and comp == "scissors":
    print("It's a Tie!")
    print("computer: " + str(compscore) + "\n" + "user: " + str(usrscore))
  elif usr == "scissors" and comp == "paper":
    print("You Win!")
    usrscore += 1
    print("computer: " + str(compscore) + "\n" + "user: " + str(usrscore))
  elif usr == "scissors" and comp == "rock":
    print("Computer Wins!")
    compscore += 1
    print("computer: " + str(compscore) + "\n" + "user: " + str(usrscore))
  time.sleep(1)
  print("\n ")
  
print("Game Over!")
#results
if compscore > usrscore:
  print("Computer Wins!")
elif usrscore > compscore:
  print("You Win!")
else:
  print("It's a Tie!")
