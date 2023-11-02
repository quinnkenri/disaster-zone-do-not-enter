//MouseMaze - Program to simulate a mouse searching a maze for a piece of cheese 

//This program uses a recursive algorithm to move the "mouse".


#include <iostream> // allows us to use cin, cout, etc

#include <stdlib.h> // allows us to use rand(), N = rand() % 100 will give random int in range [0-99] 

#include <time.h>   // allows us to use time() and create time delays.


const int NumRows = 5; //sizing the maze

const int NumCols = 5; //sizing the maze

const int WallChance = 35;  //percent chance of a space being a wall 

const short CheeseLoc[2] = { 4,4 }; //location of cheese 

const short MouseStartLoc[2] = { 0,0 }; //starting location of mouse 



//Boolean variable indicating when the cheese has been found

bool Found = 0; // Found Cheese 



//Maze: -1 -> Wall, else -> number of times visited 

short Maze[NumRows][NumCols];


using namespace std; // to avoid using std::cout or std::cin everywhere



void InitMaze(); // randomly assign wall positions to maze 

void DrawMaze(short LocR, short LocC); //draws a graphical representation of maze on console window

void DrawHorizontal(); // used by DrawMaze() 

void Move(short LocR, short LocC, short PrevR, short PrevC); //moves mouse from one location in the maze to another



int main()

{

	//init random seed -> otherwise the "random" numbers will be the same each time program is run 

	srand(time(NULL));



	//initialize mouse locations using the MouseStartLoc[] variable we defined earlier. Both are set to 0.

	short MouseRow = MouseStartLoc[0];

	short MouseCol = MouseStartLoc[1];


	//initialize maze 

	InitMaze();


	//begin searching maze for cheese 

	Move(MouseRow, MouseCol, -1, -1); // use dummy values for previous location 



	//maze output

	cout << endl << endl;

	if (Found)

		cout << "Found Cheese!";

	else

		cout << "Impossible maze.";


	cin.get();
	return 0;

}



void Move(short LocR, short LocC, short PrevR, short PrevC)

{// (LocR, LocC) = current mouse location 

 // (PrevR, PrevC) = previous mouse location (the space that the mouse was in, before this move) 


	DrawMaze(LocR, LocC); //draw maze 

	Maze[LocR][LocC]++; //increment maze element (increments the number of times a particular location in the maze has been visited)

	cin.get(); //wait for user to press enter



	if (CheeseLoc[0] == LocR && CheeseLoc[1] == LocC)

		Found = 1; // Found Cheese! 

	else

	{//move along any available path (up/down/left/right) - recursively 

	 //only move if the cheese has not yet been found, and if the space in a given direction is: 

	 //		- Within the maze's outer boundary 

	 //		- Has been visited fewer than 3 times previously 

	 //		- Not a wall 

	 //		- Not the space that the mouse just left (previous location)

		if (LocR < NumRows - 1 && Maze[LocR + 1][LocC] >= 0 && Maze[LocR + 1][LocC] < 3 && !(LocR + 1 == PrevR && LocC == PrevC) && !Found)

			// English translation of above code: "If the mouse is not in the bottom row, AND the space below the mouse has been visited between 0 and 3 times, AND the space below the mouse is not the space that the mouse just left, AND the cheese has not yet been found, proceed."

			Move(LocR + 1, LocC, LocR, LocC); //moves DOWN if all above conditions are met
		
		
		if (LocC < NumCols - 1 && Maze[LocR][LocC + 1] >= 0 && Maze[LocR][LocC + 1] < 3 && !(LocR == PrevR && LocC + 1 == PrevC) && !Found)

			// English translation of above code: "If current mouse location is to the left of the rightmost column, AND the space to the right of the mouse has been visited between 0 and 3 times, AND the space to the right of the mouse is not the space that the mouse just left, AND the cheese has not yet been found, proceed." 

			Move(LocR, LocC + 1, LocR, LocC); //moves RIGHT if all above conditions are met


		if (LocR > 0 && Maze[LocR - 1][LocC] >= 0 && Maze[LocR - 1][LocC] < 3 && !(LocR - 1 == PrevR && LocC == PrevC) && !Found) 
			
		//English translation of above code: "If the mouse is not in the top row, AND the space above the mouse has been visited between 0 and 3 times, AND the space above the mouse is not the space that the mouse just left, AND the cheese has not yet been found, proceed."

			Move(LocR - 1, LocC, LocR, LocC); //moves UP if all above conditions are met

		if (LocC > 0 && Maze[LocR][LocC - 1] >= 0 && Maze[LocR][LocC - 1] < 3 && !(LocR == PrevR && LocC - 1 == PrevC) && !Found)

		// English translation of above code: "If the mouse is not in the leftmost column, AND the space to the left of the mouse has been visited between 0 and 3 times, AND the space to te left of the mouse is not the space that the mouse just left, AND the cheese has not yet been found, proceed."

			Move(LocR, LocC - 1, LocR, LocC); //moves LEFT if all above conditions are met

		// These moves are ordered in a SPECIFIC WAY, FOR A REASON!
		// By biasing toward moves that are RIGHT or DOWN, the cheese in the bottom right will be found faster. LEFT or UP moves bring us away from the cheese, so should only happen if it is not possible to move RIGHT or DOWN.

	}

}

// ---------------------------------
// everything below here is for drawing the maze

void DrawMaze(short LocR, short LocC)

{/*Sample output:

|---------------------------------------|

|       |       |       |       |       |

|   M   |       |       |       |       |

|       |       |       |       |       |

|---------------------------------------|

|       |XXXXXXX|       |XXXXXXX|       |

|       |XXXXXXX|       |XXXXXXX|       |

|       |XXXXXXX|       |XXXXXXX|       |

|---------------------------------------|

|       |XXXXXXX|       |       |XXXXXXX|

|       |XXXXXXX|       |       |XXXXXXX|

|       |XXXXXXX|       |       |XXXXXXX|

|---------------------------------------|

|XXXXXXX|       |XXXXXXX|       |XXXXXXX|

|XXXXXXX|       |XXXXXXX|       |XXXXXXX|

|XXXXXXX|       |XXXXXXX|       |XXXXXXX|

|---------------------------------------|

|       |       |       |       |       |

|       |       |       |       |   C   |

|       |       |       |       |       |

|---------------------------------------|

 */

 //clear console (clears the screen)

	system("cls"); 



	//Draw top row 

	DrawHorizontal();



	for (int i = 0; i < NumRows; i++)

	{//draw a row of maze (3 lines of text) 

		cout << "|";


		for (int j = 0; j < NumCols; j++)

		{//draw first text line of each element of row i 



			switch (Maze[i][j])

			{

			case -1:

				cout << "XXXXXXX|";

				break;

			case 0:

			case 1:

			case 2:

			case 3:

				cout << "       |";

				break;

			default:

				system("cls");

				cout << "ERROR"; //this should never happen 

				exit(0);

			}



		}



		cout << endl << "|";



		for (int j = 0; j < NumCols; j++)

		{//draw second text line of each element for row i 



			if (LocR == i && LocC == j)

				cout << "   M   |";

			else if (CheeseLoc[0] == i && CheeseLoc[1] == j)

				cout << "   C   |";

			else if (Maze[i][j] == -1)

				cout << "XXXXXXX|";

			else if (Maze[i][j] >= 0 && Maze[i][j] <= 3)

				cout << "       |";

			else

			{//ERROR 

				system("cls");

				cout << "ERROR"; //this should never happen 

				exit(0);

			}

		}



		cout << endl << "|";



		for (int j = 0; j < NumCols; j++)

		{//draw third text line of each element for row i 





			switch (Maze[i][j])

			{

			case -1:

				cout << "XXXXXXX|";

				break;

			case 0:

			case 1:

			case 2:

			case 3:

				cout << "       |";

				break;

			default:

				system("cls");

				cout << "ERROR"; //this should never happen 

				exit(0);

			}

		}

		cout << endl;

		DrawHorizontal();

	}



}



void DrawHorizontal()

{//used by DrawMaze() 



	cout << "|";

	for (int i = 0; i < NumCols - 1; i++)

	{

		cout << "--------";

	}

	cout << "-------|" << endl;



}



void InitMaze()

{

	int Num;



	for (int i = 0; i < NumRows; i++)

	{

		for (int j = 0; j < NumCols; j++)

		{

			Num = rand() % 100 + 1; // generate random integer in range [1 - 100] 

			if (Num <= WallChance)

				Maze[i][j] = -1; // Set Maze element to "Wall" 

		}

	}



	Maze[MouseStartLoc[0]][MouseStartLoc[1]] = 0; //cannot have "Wall" at mouse starting location -> ALWAYS set element to "empty" 

	Maze[CheeseLoc[0]][CheeseLoc[1]] = 0;  //cannot have "Wall" at cheese location -> ALWAYS set element to "empty" 

}