/*******************************************************************************
Project:	Tuffy Tetris
Class:		CS 462 - SW Design
Date:		3 November 2018
Members:	Stephen Cordasco, Ryan Oune, Noah Roberson
File:		UI_console_win.cpp
Purpose:	defines member functions for UI_console_win class
*******************************************************************************/


#ifdef _WIN32

#include "UI_console_win.h"
#include "../../Domain/Game/Game.h"
#include "../../Domain/Player/Player.h"
#include <iostream>

using UI::UI_console_win;

UI::UI_console_win::UI_console_win() : UI_console() {}

/*******************************************************************************
Name:		print_Frame
Parameters:	string object
Purpose:	clears the screen and prints a frame
*******************************************************************************/
void UI::UI_console_win::print_Frame(std::string frame)
{
	// stub
	clear_screen();
	std::cout << frame;
}

void UI::UI_console_win::game_Loop()
{
	bool endloop = false;
	std::string frame = "";
	clock_t start_time, end_time;
	//tick is the base time unit for the loop
	float tick = 0.1f;
	//loop while game is not over
	while (!endloop)
	{
		for (int i = 0; i < 3; i++)
		{
			start_time = clock();
			end_time = 0;
			float time_elapsed = 0.0f;
			//loop while one tick has not elapsed
			while (time_elapsed <= tick)
			{
				Sleep(10);
				//check for keyboard input
				if (_kbhit())
				{
					//get a character from the input buffer
					char inputchar = static_cast<char>(_getch());
					//process the input character and call appropriate
					//ui or board functions. break if user selected quit
					if (!(game->process_Input(inputchar)))
					{
						//endloop = true;
						endloop = pauseMenu();
						break;
					}
					//generate and print an output screen frame
					game->get_Frame(frame);
					print_Frame(frame);
				}
				end_time = clock();
				//find out how much time has elapsed in fractional seconds
				time_elapsed = static_cast<float>(end_time - start_time) /
					static_cast<float>(CLOCKS_PER_SEC);
			}
			if (endloop) break;
		}
		//do a system move after checking for user input 3 times
		//system move moves piece down one
		game->process_Input('$');
		//generate and print an output screen frame
		game->get_Frame(frame);
		print_Frame(frame);

		// TODO -- under construction --
		// check for a full row
		//board_ptr->checkFullRow();
	}
	if (game->end_Game()) 
	{
		hsMenu();
	}
	else 
	{
		std::cout << "\nGame Over!\nNo new highscore...\nScore: " << game->get_Score();
		std::cout << "Press any key to continue...\n";
		std::cin.get();
	}
		

}

/*******************************************************************************
Name:		displayLoginScreen
Parameters:	none
Purpose:	clears the screen and prints the startup menu or login screen
*******************************************************************************/
void UI_console_win::displayLoginScreen()
{
	clear_screen();
	std::cout << "======= WELCOME USER =======\n";
	std::cout << "1.) Login\n";
	std::cout << "2.) Register\n";
	std::cout << "3.) Quit\n";
	std::cout << "============================\n";
}

/*******************************************************************************
Name:		displayLogin
Parameters:	none
Purpose:	prints the fields for the user to enter information in order to
			log into the application
*******************************************************************************/
void UI_console_win::displayLogin()
{
	// prevent "new line" capture
	std::cin.get();
	// print the login fields
	std::cout << "Username: ";
	// ====================== LNK1120: 1 unresolved external ======================
	/*char name[20];
	std::cin.getline(name, 20, '\n');
	player->setUsername(name);*/
	// ============================================================================
	std::getline(std::cin, username);
	std::cout << "Password: ";
	std::getline(std::cin, password);
	std::cout << "email: ";
	std::getline(std::cin, email);
	
	// greet the user if login successful
	if (game->login(username, password))
	{	// print welcome message
		std::cout << "\nWelcome, " << username << "\n\n";
	}
	// login failed
	else
	{
		// print a message that login failed...
		std::cout << "Login failed. Please try again.\n";
		std::cout << "Press enter to continue...";
		std::cin.get();
		// ...print the login screen again
		login();
	}
	//clear password
	password = "";
}

/*******************************************************************************
Name:		displayRegister
Parameters:	none
Purpose:	prints the fields for the user to enter information in order to
			register a new account for the application
*******************************************************************************/
void UI_console_win::displayRegister()
{
	// prevent "new line" capture
	std::cin.get();
	// print the register fields
	std::cout << "\nPlease fill in the following fields:\n";
	std::cout << "\tUsername: ";
	std::getline(std::cin, username);
	std::cout << "\tPassword: ";
	std::getline(std::cin, password);
	std::cout << "\tCSUF email: ";
	std::getline(std::cin, email);

	// greet the user if registration successful
	if (game->register_acct(username, password, email))
	{	// print welcome message
		//std::cout << "\nWelcome, " << getUserName() << "\n\n";
	}
	else
	// registration failed
	{
		// print a message that registration failed...
		std::cout << "Registration failed. Please try again.";
		std::cout << "Press enter to continue...";
		std::cin.get();
		// ...print the login screen again
		login();
	}

	//clear password
	password = "";
}


/*******************************************************************************
Name:		login
Parameters:	none
Purpose:	prints the startup menu or login screen, gets a menu choice from
			the user, and determines what to do next
*******************************************************************************/
bool UI_console_win::login()
{
	// print the first menu
	displayLoginScreen();

	// store the menu choice
	char choice = getMenuChoice();
	switch (choice)
	{
		case '1':	// user chose to login
			displayLogin();
			break;

		case '2':	// user chose to register
			displayRegister();
			break;

		case '3':	// user chose to quit
			std::cout << "Goodbye!\n\n";
			return false;

		default:	// user entered an invalid key
			std::cout << "\nINVALID MENU CHOICE\n";
	}
	return true;
}

/*******************************************************************************
Name:		displayMainMenu
Parameters:	none
Purpose:	clears the screen, greets the user, and prints the main menu
*******************************************************************************/
void UI_console_win::displayMainMenu()
{
	clear_screen();
	// display username
	if (game->is_Admin(username))
	{
		std::cout << "Welcome, Admin\n";
	}
	else
	{
		std::cout << "\nWelcome, " << username << "\n";
	}
	// print main menu
	std::cout << "\n========== MAIN MENU =======\n";
	std::cout << "1.) Play Game\n";
	std::cout << "2.) Account Information\n";
	std::cout << "3.) Quit\n";
	std::cout << "============================\n";
}

/*******************************************************************************
Name:		mainMenu
Parameters:	none
Purpose:	prints the main menu, gets a menu choice from the user, and
			determines what to do next
*******************************************************************************/
bool UI_console_win::mainMenu()
{
	// print the main menu
	displayMainMenu();

	// store the menu choice
	char choice = getMenuChoice();
	switch (choice)
	{
		case '1':	// user chose to play game
			if (!(game->is_Started()))
			{
				game->start_Game();
				game_Loop();
			}
			break;

		case '2':	// user chose to access account information
			// display account menu
			accountMenu();
			break;
			
		case '3':	// user chose to quit
			std::cout << "\nLogging out...\n";
			if((game->logout(game->get_User())))
			{
				std::cout << "...Log out successful!\n";
			}
			else 
			{
				std::cout << "...Log out unsuccessful, quitting.\n";
			}
			std::cout << "Goodbye!\n\n";
			return false;

		default:	// user entered an invalid key
			std::cout << "\nINVALID MENU CHOICE\n";
	}
	return true;
}

/*******************************************************************************
Name:		displayAccountMenu
Parameters:	none
Purpose:	clears the scree, prints the current username and email of the
			user, and prints the account menu
*******************************************************************************/
void UI_console_win::displayAccountMenu()
{
	clear_screen();
	std::cout << "\n======= ACCOUNT MENU =======\n";
	std::cout << "Current Username: " << username << "\n";
	std::cout << "Current e-mail: " << email << "\n";
	std::cout << "============================\n";
	std::cout << "1.) Change Username\n";
	std::cout << "2.) Change Password\n";
	std::cout << "3.) Purchase Subscription\n";
	//std::cout << "4.) High Score\n";
	std::cout << "4.) Main Menu\n";
	std::cout << "============================\n";
}

/*******************************************************************************
Name:		displayPurchaseSubscriptionScreen
Parameters:	none
Purpose:	displays the purchase subscription screen going to use a stub here
			so that any values entered will always be accepted and a
			subscription purchase will be successful
*******************************************************************************/
void UI_console_win::displayPurchaseSubscriptionScreen()
{
	//setHasSubscription(get_Server()->check_sub());
	// check if the user already has a subscription
	if (game->get_Sub())
	{
		// inform user they already have a subscription
		std::cout << "\nYou already have a subscription!\n";
		std::cout << "Press enter to continue...";
		std::cin.get();
		// return to the account menu
		accountMenu();
		return;
	}

	// temp variables to hold the user input
	std::string cardNumber = " ";
	std::string accountHolder = " ";
	std::string securityNumber = " ";
	std::string expirationDate = " ";
	std::string billingAddress = " ";
	std::string zipCode = " ";

	// prevent "new line" capture
	std::cin.get();
	// print the card information fields
	std::cout << "\nPlease enter your card information:\n";
	std::cout << "Card Number: ";
	getline(std::cin, cardNumber);
	std::cout << "Account Holder: ";
	getline(std::cin, accountHolder);
	std::cout << "Security Number: ";
	getline(std::cin, securityNumber);
	std::cout << "Expiration Date: ";
	getline(std::cin, expirationDate);
	std::cout << "Billing Address: ";
	getline(std::cin, billingAddress);
	std::cout << "Zip Code: ";
	getline(std::cin, zipCode);

	// stub: payment is successful, hasSubscription assigned true
	if(game->purchase_Sub(cardNumber, accountHolder, securityNumber,
								expirationDate, billingAddress, zipCode))
	{
		std::cout << "\nPurchase successful!\n";
		std::cout << "You now have access to online scores!\n";
	}
	else 
	{
		std::cout << "Transaction denied. Please try again.\n";
		std::cout << "Press enter to continue...";
		std::cin.get();
		accountMenu();
	}
	// if the payment was successful take the user back to the account menu
	if (game->get_Sub())
	{
		std::cout << "Press enter to continue...";
		std::cin.get();
		accountMenu();
	}
}

/*******************************************************************************
Name:		displayPauseMenu
Parameters:	none
Purpose:	clears the screen and displays the pause menu
*******************************************************************************/
void UI::UI_console_win::displayPauseMenu()
{
	clear_screen();
	std::cout << "\n======== PAUSE MENU ========\n";
	std::cout << "1.) Continue Game\n";
	std::cout << "2.) Exit to Main Menu\n";
	std::cout << "============================\n";
}

/*******************************************************************************
Name:		displayHighScoreScreen
Parameters:	integer value
Purpose:	clears the scree and displays the high score menu
*******************************************************************************/
void UI::UI_console_win::displayHighScoreScreen(int score)
{
	clear_screen();
	std::cout << "\n======== New High Score ========\n";
	std::cout << "\n======== " << score << " ========\n";
	std::cout << "1.) Save New High Score\n";
	std::cout << "2.) Exit to Main Menu\n";
	std::cout << "============================\n";
}

/*******************************************************************************
Name:		saveNewHighScoreScreen
Parameters:	integer value
Purpose:	checks if user has a subscription; if true, user enters in a
			nickname and the score is saved, message is printed to screen,
			otherwise the user is informed to purchase a subscription in order
			to save a score
*******************************************************************************/
void UI::UI_console_win::saveNewHighScoreScreen()
{	

	if( game->get_Sub() )
	{
		std::cin.get();
		std::string nickname = " ";
		std::cout << "\nPlease enter a name for your score: ";
		getline(std::cin, nickname);
		std::cout << "\nsaving Score...\n";
		if (game->save_Score())
		{
			std::cout << "\n======== Congratulations " << nickname << " ========\n";
			std::cout << "\nYour score has been saved.\n";
			std::cout << "Enter any button to exit to Main Menu\n";
			std::cout << "============================\n";
		}
		else
		{
			std::cout << "Unable to save score. Please try again.\n";
		}
	}
	else 
	{
		std::cout << "You must purchase a subscription to use this feature.\n";
	}
	
}

/*******************************************************************************
Name:		accountMenu
Parameters:	none
Purpose:	displays the account menu, gets a menu choice from the user, and
			determines what to do next
*******************************************************************************/
bool UI_console_win::accountMenu()
{
	// print the account menu
	displayAccountMenu();

	// store the menu choice
	char choice = getMenuChoice();
	switch (choice)
	{
		case '1':	// user chose to change username
			// print the change username screen
			std::cin.get();
			// print current username
			std::cout << "\nYour current username: " << username << "\n";
			std::cout << "Enter a new username: ";
			std::getline(std::cin, username);
			if(game->set_User(username))
			{
				// print new username
				std::cout << "\nThank you! Your new username is " << username << "\n";
				std::cout << "Press enter to continue...";
				std::cin.get();
				// in this case, take user back to account menu
				accountMenu();
			}
			else 
			{
				username = game->get_User();
				std::cout << "Setting username failed, please try again later.\n";
				std::cout << "Press enter to continue...";
				std::cin.get();
				accountMenu();
			}
			break;

		case '2':	// user chose to change password
			// print the change password screen
			std::cin.get();
			std::cout << "Enter a new password: ";
			std::getline(std::cin, username);
			if (game->set_Email(username)) 
			{
				// print new password
				std::cout << "\nThank your! Your new password is " << password << "\n\n";
				password = "";
				std::cout << "Press enter to continue...";
				std::cin.get();
				// in this case, take user back to account menu
				accountMenu();
			}
			else 
			{
				std::cout << "Resetting password failed, please try again later.\n";
				std::cout << "Press enter to continue...";
				std::cin.get();
				accountMenu();
			}
			
			break;

		case '3':	// user chose to purchase subscription
			// print the subscription screen
			displayPurchaseSubscriptionScreen();
			break;

		case '4':	// user chose to return to main menu
			std::cout << "\nGoing back to main menu...\n";
			std::cout << "Press enter to continue...";
			std::cin.get();
			return false;
			break;

		default:
			std::cout << "\nINVALID MENU CHOICE\n";
			std::cout << "Press enter to continue...";
			std::cin.get();
	}
	return true;
}

/*******************************************************************************
Name:		pauseMenu
Parameters:	none
Purpose:	displays the pause menu, gets a menu choice from the user, and
			determines what to do next
*******************************************************************************/
bool UI::UI_console_win::pauseMenu()
{
	// display pause menu
	displayPauseMenu();
	// store the user menu choice
	char inputchar = getMenuChoice();
		game->set_Paused(false);
	switch (inputchar)
	{
	case '1':	// user chose to continue game
		return false;
	case '2':	// user chose to quit game
		return true;
	default:
		return true;
	}
}

/*******************************************************************************
Name:		hsMenu
Parameters:	none
Purpose:	displays the high score screen with the user's score, gets a menu
			choice from the user and determines what to do next
*******************************************************************************/
void UI::UI_console_win::hsMenu()
{
	// print the high score screen with user score
	displayHighScoreScreen(game->get_Score());
	// get menu choice from the user
	char inputchar = getMenuChoice();
	switch (inputchar)
	{
		//save high score screen
	case '1':
		saveNewHighScoreScreen();
		//enter key to go to main menu
		std::cout << "Press enter to continue...";
		std::cin.get();
		break;
		//go directly to main menu
	case '2':
		break;
	}
}

/*******************************************************************************
Name:		clear_screen
Parameters:	none
Purpose:	Helper function that simply prints 100 newlines to clear console
			screen
*******************************************************************************/
void UI::UI_console_win::clear_screen()
{
	std::cout << std::string(50, '\n');
}

/*******************************************************************************
Name:		getMenuChoice
Parameters:	none
Purpose:	prompts the user to enter a menu choice, gets the menu choice,
			and returns it to the calling function
*******************************************************************************/
char UI_console_win::getMenuChoice()
{
	std::cout << "Enter a menu choice: ";
	std::string choice = "";
	std::cin >> choice;
	return choice[0];

}

void UI::UI_console_win::set_Game(Domain::Game * g)
{
	game = g;
}

void UI::UI_console_win::set_Player(Domain::Player * p)
{
	player = p;
}

#endif

