import random
choices=["rock","paper","scissor"]
while True:
    player_entry = input("Enter choice from [rock,paper,scissor]   ")
    if(player_entry not in choices):
        print("Wrong input.")
    else:
        random.shuffle(choices)
        computer_choice=random.choice(choices)
        print("Computer choice is ",computer_choice)
        if computer_choice == "rock":
            if player_entry == "rock":
                print("Tie")
            elif player_entry == "scissor":
                print("You lose")
            else:
                print("You win")
        
        elif computer_choice == "scissor":
            if player_entry == "rock":
                print("You win")
            elif player_entry == "paper":
                print("You lose")
            else:
                print("Tie")
        else: 
            if player_entry == "paper":
                print("Tie")
            elif player_entry == "scissor":
                print("You win")
            else:
                print("You lose")
    if input("Enter A to end") == "A":
        break
        