#include <iostream>
#include "myconsole.h"
#include <windows.h>
#include <fstream>
using namespace std;


const int COLS=2;

void PrintBoundary(int BoundaryCoordinates[][COLS]);
void PrintBlocks(int block_locations_stage_1[][COLS]);
void PrintDots(int DotsLocationStage1[][COLS]);
void PrintWindowBorder();
char PrintStartMenu();
void PrintStylishPacman();
void PrintInstruction();
void PrintGameRules();
void LivePrinter(int lives);
void PrintStylishPacmanDuringStage();

bool CheckWithBlocks(int x_pacman , int y_pacman , int block_locations_stage_1[][COLS]);
bool CheckWithDots(int x_pacman ,int y_pacman , int DotsLocationStage1[][COLS] , bool CheckWithWhat);

void PositionOfPacman(int User_Control , int & x_pacman , int & y_pacman );
void DoorCrossing(int & x_pacman, int y_pacman);

bool Ghost1(int x_pacman , int y_pacman, float & x_ghost1 , float & y_ghost1 , float & speed_controler_of_ghost_1 , int DotsLocationStage1[][COLS] , int block_locations_stage_1[][COLS]);
bool Ghost2(int x_pacman , int y_pacman, float & x_ghost1 , float & y_ghost1 , float & speed_controler_of_ghost_2, int DotsLocationStage1[][COLS] , int block_locations_stage_1[][COLS]);

int CalculateTotalDotsOFfStage(int Dots_Locations[][COLS]);
int FindLengthOfString(char String[]);

void StartingPage();
void StageCompletePage();
void EndingPage(int grand_total_score);


void LoadingStyle();

bool Stage(int BoundaryCoordinates[][COLS] , int block_locations_stage_1[][COLS] , int DotsLocationStage1[][COLS] , int & grand_total_score);

void SavePlayerNameInFile(char player_name[]);
void PrintPlayerNameFromFile(char player_name[]);
void SavePlayerScoreinFile(int grand_total_score);
void PrintHallOfFame();

int main()
{
	//this line will clear the garbage on screen
	void PrintHallOfFame();
	system("pause");
	system("cls");								

	//	this functoin will set the title of console window
	SetWindowTitle("PACMAN (DEVELOPED BY M Abdullah)");

	//this function will set the size of console windows
 	SetWindowSize(79,45);
	
	//this is my game starting page 
 	StartingPage();
	

	//this varable store the sum of scores of all the stages
	int grand_total_score=0; 
		

	//this bool control the stages that either player is eligible to play 2nd stage or not
	bool stage_result=false;

	//these are boundary coordinates of game
	int BoundaryCoordinates[][COLS]={{0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8},{0,9},{0,10},{0,11},{0,12},{0,13},{0,14},{0,15},{0,16},{0,17},{0,18},{0,19},{0,20},{0,21},{0,22},{0,23},{79,0},{79,1},{79,2},{79,3},{79,4},{79,5},{79,6},{79,7},{79,8},{79,9},{79,10},{79,11},{79,12},{79,13},{79,14},{79,15},{79,16},{79,17},{79,18},{79,19},{79,20},{79,21},{79,22},{79,23},      
	{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0},{11,0},{12,0},{13,0},{14,0},{15,0},{16,0},{17,0},{18,0},{19,0},{20,0},{21,0},{22,0},{23,0},{24,0},{25,0},{26,0},{27,0},{28,0},{29,0},{30,0},{31,0},{32,0},{33,0},{34,0},{35,0},{36,0},{37,0},{38,0},{39,0},{40,0},{41,0},{42,0},{43,0},{44,0},{45,0},{46,0},{47,0},{48,0},{49,0},{50,0},{51,0},{52,0},{53,0},{54,0},{55,0},{56,0},{57,0},{58,0},{59,0},{60,0},{61,0},{62,0},{63,0},{64,0},{65,0},{66,0},{67,0},{68,0},{69,0},{70,0},{71,0},{72,0},{73,0},{74,0},{75,0},{76,0},{77,0},{78,0},
	{1,23},{2,23},{3,23},{4,23},{5,23},{6,23},{7,23},{8,23},{9,23},{10,23},{11,23},{12,23},{13,23},{14,23},{15,23},{16,23},{17,23},{18,23},{19,23},{20,23},{21,23},{22,23},{23,23},{24,23},{25,23},{26,23},{27,23},{28,23},{29,23},{30,23},{31,23},{32,23},{33,23},{34,23},{35,23},{36,23},{37,23},{38,23},{39,23},{40,23},{41,23},{42,23},{43,23},{44,23},{45,23},{46,23},{47,23},{48,23},{49,23},{50,23},{51,23},{52,23},{53,23},{54,23},{55,23},{56,23},{57,23},{58,23},{59,23},{60,23},{61,23},{62,23},{63,23},{64,23},{65,23},{66,23},{67,23},{68,23},{69,23},{70,23},{71,23},{72,23},{73,23},{74,23},{75,23},{76,23},{77,23},{78,23},{-1,-1}};
	
	//these are blocks of stage 1
	int block_locations_stage_1[][2]={{15,5},{16,5},{17,5},{18,5},{19,5},{20,5},{21,5},{22,5},{23,5},{24,5},{25,5},{26,5},{27,5},{28,5},{29,5},{30,5},{31,5},{32,5},{33,5},{34,5},{35,5},{36,5},{37,5},{38,5},{39,5},{40,5},{41,5},{42,5},{43,5},{44,5},{45,5},{46,5},{47,5},{48,5},{49,5},{50,5},{51,5},{52,5},{53,5},{54,5},{55,5},{56,5},{57,5},{58,5},{59,5},{60,5},{61,5},{62,5},{63,5},{64,5},{65,5},{15,18},{16,18},{17,18},{18,18},{19,18},{20,18},{21,18},{22,18},{23,18},{24,18},{25,18},{26,18},{27,18},{28,18},{29,18},{30,18},{31,18},{32,18},{33,18},{34,18},{35,18},{36,18},{37,18},{38,18},{39,18},{40,18},{41,18},{42,18},{43,18},{44,18},{45,18},{46,18},{47,18},{48,18},{49,18},{50,18},{51,18},{52,18},{53,18},{54,18},{55,18},{56,18},{57,18},{58,18},{59,18},{60,18},{61,18},{62,18},{63,18},{64,18},{65,18},{-1,-1}};
	
	//these are coordinates of blocks of stage 1
	int DotsLocationStage1[][COLS]={
	{15,1},{16,1},{17,1},{18,1},{19,1},{20,1},{21,1},{22,1},{23,1},{24,1},{25,1},{26,1},{27,1},{28,1},{29,1},{30,1},{31,1},{32,1},{33,1},{34,1},{35,1},{36,1},{37,1},{38,1},{39,1},{40,1},{41,1},{42,1},{43,1},{44,1},{45,1},{46,1},{47,1},{48,1},{49,1},{50,1},{51,1},{52,1},{53,1},{54,1},{55,1},{56,1},{57,1},{58,1},{59,1},{60,1},{61,1},{62,1},{63,1},{64,1},{65,1},
	{15,2},{16,2},{17,2},{18,2},{19,2},{20,2},{21,2},{22,2},{23,2},{24,2},{25,2},{26,2},{27,2},{28,2},{29,2},{30,2},{31,2},{32,2},{33,2},{34,2},{35,2},{36,2},{37,2},{38,2},{39,2},{40,2},{41,2},{42,2},{43,2},{44,2},{45,2},{46,2},{47,2},{48,2},{49,2},{50,2},{51,2},{52,2},{53,2},{54,2},{55,2},{56,2},{57,2},{58,2},{59,2},{60,2},{61,2},{62,2},{63,2},{64,2},{65,2},
 	{15,3},{16,3},{17,3},{18,3},{19,3},{20,3},{21,3},{22,3},{23,3},{24,3},{25,3},{26,3},{27,3},{28,3},{29,3},{30,3},{31,3},{32,3},{33,3},{34,3},{35,3},{36,3},{37,3},{38,3},{39,3},{40,3},{41,3},{42,3},{43,3},{44,3},{45,3},{46,3},{47,3},{48,3},{49,3},{50,3},{51,3},{52,3},{53,3},{54,3},{55,3},{56,3},{57,3},{58,3},{59,3},{60,3},{61,3},{62,3},{63,3},{64,3},{65,3},

 	{15,11},{16,11},{17,11},{18,11},{19,11},{20,11},{21,11},{22,11},{23,11},{24,11},{25,11},{26,11},{27,11},{28,11},{29,11},{30,11},{31,11},{32,11},{33,11},{34,11},{35,11},{36,11},{37,11},{38,11},{39,11},{40,11},{41,11},{42,11},{43,11},{44,11},{45,11},{46,11},{47,11},{48,11},{49,11},{50,11},{51,11},{52,11},{53,11},{54,11},{55,11},{56,11},{57,11},{58,11},{59,11},{60,11},{61,11},{62,11},{63,11},{64,11},{65,11},
  	{15,12},{16,12},{17,12},{18,12},{19,12},{20,12},{21,12},{22,12},{23,12},{24,12},{25,12},{26,12},{27,12},{28,12},{29,12},{30,12},{31,12},{32,12},{33,12},{34,12},{35,12},{36,12},{37,12},{38,12},{39,12},{40,12},{41,12},{42,12},{43,12},{44,12},{45,12},{46,12},{47,12},{48,12},{49,12},{50,12},{51,12},{52,12},{53,12},{54,12},{55,12},{56,12},{57,12},{58,12},{59,12},{60,12},{61,12},{62,12},{63,12},{64,12},{65,12},
  	{15,13},{16,13},{17,13},{18,13},{19,13},{20,13},{21,13},{22,13},{23,13},{24,13},{25,13},{26,13},{27,13},{28,13},{29,13},{30,13},{31,13},{32,13},{33,13},{34,13},{35,13},{36,13},{37,13},{38,13},{39,13},{40,13},{41,13},{42,13},{43,13},{44,13},{45,13},{46,13},{47,13},{48,13},{49,13},{50,13},{51,13},{52,13},{53,13},{54,13},{55,13},{56,13},{57,13},{58,13},{59,13},{60,13},{61,13},{62,13},{63,13},{64,13},{65,13},
 	
  	{15,20},{16,20},{17,20},{18,20},{19,20},{20,20},{21,20},{22,20},{23,20},{24,20},{25,20},{26,20},{27,20},{28,20},{29,20},{30,20},{31,20},{32,20},{33,20},{34,20},{35,20},{36,20},{37,20},{38,20},{39,20},{40,20},{41,20},{42,20},{43,20},{44,20},{45,20},{46,20},{47,20},{48,20},{49,20},{50,20},{51,20},{52,20},{53,20},{54,20},{55,20},{56,20},{57,20},{58,20},{59,20},{60,20},{61,20},{62,20},{63,20},{64,20},{65,20},
  	{15,21},{16,21},{17,21},{18,21},{19,21},{20,21},{21,21},{22,21},{23,21},{24,21},{25,21},{26,21},{27,21},{28,21},{29,21},{30,21},{31,21},{32,21},{33,21},{34,21},{35,21},{36,21},{37,21},{38,21},{39,21},{40,21},{41,21},{42,21},{43,21},{44,21},{45,21},{46,21},{47,21},{48,21},{49,21},{50,21},{51,21},{52,21},{53,21},{54,21},{55,21},{56,21},{57,21},{58,21},{59,21},{60,21},{61,21},{62,21},{63,21},{64,21},{65,21},
  	{15,22},{16,22},{17,22},{18,22},{19,22},{20,22},{21,22},{22,22},{23,22},{24,22},{25,22},{26,22},{27,22},{28,22},{29,22},{30,22},{31,22},{32,22},{33,22},{34,22},{35,22},{36,22},{37,22},{38,22},{39,22},{40,22},{41,22},{42,22},{43,22},{44,22},{45,22},{46,22},{47,22},{48,22},{49,22},{50,22},{51,22},{52,22},{53,22},{54,22},{55,22},{56,22},{57,22},{58,22},{59,22},{60,22},{61,22},{62,22},{63,22},{64,22},{65,22},
	{-1,-1}
	};

	//this will clear the garbage on screen(printed by game starging page)
	system("cls");

	//this is my stage function (stage 1)
	stage_result=Stage(BoundaryCoordinates,block_locations_stage_1,DotsLocationStage1 ,grand_total_score);

	
	//these are coordinate of blocks of stage 2
	int block_locations_stage_2[][COLS]={
	{12,5},{13,5},{14,5},{15,5},{16,5},{17,5},{18,5},{19,5},{20,5},{21,5},{22,5},{23,5},{24,5},{25,5},{26,5},{27,5},{28,5},{29,5},{30,5},{31,5},
	{12,18},{13,18},{14,18} ,{15,18},{16,18},{17,18},{18,18} ,{19,18} ,{20,18},{21,18},{22,18},{23,18},{24,18},{25,18},{26,18},{27,18},{28,18},{29,18},{30,18},{31,18},
	{49,5},{50,5},{51,5},{52,5},{53,5},{54,5},{55,5},{56,5},{57,5},{58,5},{59,5},{60,5},{61,5},{62,5},{63,5},{64,5},{65,5},{66,5},{67,5},{68,5},
	{49,18},{50,18},{51,18},{52,18},{53,18},{54,18},{55,18},{56,18},{57,18},{58,18},{59,18},{60,18},{61,18},{62,18},{63,18},{64,18},{65,18},{66,18},{67,18},{68,18},
	

	//centre block of stage 2 blocks

	{34,8},{35,8},{36,8},{37,8},{38,8},{39,8},{40,8},{41,8},{42,8},{43,8},{43,8},{44,8},{45,8},{46,8},
	{34,9},{35,9},{36,9},{37,9},{38,9},{39,9},{40,9},{41,9},{42,9},{43,9},{43,9},{44,9},{45,9},{46,9},
	{34,10},{35,10},{36,10},{37,10},{38,10},{39,10},{40,10},{41,10},{42,10},{43,10},{43,10},{44,10},{45,10},{46,10},
	{34,11},{35,11},{36,11},{37,11},{38,11},{39,11},{40,11},{41,11},{42,11},{43,11},{43,11},{44,11},{45,11},{46,11},
	{34,12},{35,12},{36,12},{37,12},{38,12},{39,12},{40,12},{41,12},{42,12},{43,12},{43,12},{44,12},{45,12},{46,12},
	{34,13},{35,13},{36,13},{37,13},{38,13},{39,13},{40,13},{41,13},{42,13},{43,13},{43,13},{44,13},{45,13},{46,13},
	{34,14},{35,14},{36,14},{37,14},{38,14},{39,14},{40,14},{41,14},{42,14},{43,14},{43,14},{44,14},{45,14},{46,14},
	{34,15},{35,15},{36,15},{37,15},{38,15},{39,15},{40,15},{41,15},{42,15},{43,15},{43,15},{44,15},{45,15},{46,15},
	{-1,-1}};


	//dots location os stage 2
	int dots_location_2[][COLS]={
	{32,5},{33,5},{34,5},{35,5},{36,5},{37,5},{38,5},{39,5},{40,5},{41,5},{42,5},{43,5},{44,5},{45,5},{46,5},{47,5},{48,5},
	{32,6},{33,6},{34,6},{35,6},{36,6},{37,6},{38,6},{39,6},{40,6},{41,6},{42,6},{43,6},{44,6},{45,6},{46,6},{47,6},{48,6},
	{32,7},{33,7},{34,7},{35,7},{36,7},{37,7},{38,7},{39,7},{40,7},{41,7},{42,7},{43,7},{44,7},{45,7},{46,7},{47,7},{48,7},
	{32,8},{33,8},          {47,8},{48,8},
	{32,9},{33,9},			{47,9},{48,9},
	{32,10},{33,10},		{47,10},{48,10},
	{32,11},{33,11},		{47,11},{48,11},
	{32,12},{33,12},		{47,12},{48,12},
	{32,13},{33,13},		{47,13},{48,13},
	{32,14},{33,14},		{47,14},{48,14},
	{32,15},{33,15},		{47,15},{48,15},
	{32,16},{33,16},{34,16},{35,16},{36,16},{37,16},{38,16},{39,16},{40,16},{41,16},{42,16},{43,16},{44,16},{45,16},{46,16},{47,16},{48,16},
	{32,17},{33,17},{34,17},{35,17},{36,17},{37,17},{38,17},{39,17},{40,17},{41,17},{42,17},{43,17},{44,17},{45,17},{46,17},{47,17},{48,17},
	{32,18},{33,18},{34,18},{35,18},{36,18},{37,18},{38,18},{39,18},{40,18},{41,18},{42,18},{43,18},{44,18},{45,18},{46,18},{47,18},{48,18},
	{-1,-1}};

	//this if condition check that either player has cleared the first stage or not
	if(stage_result==true)	
	{	
		//this is my stage completion page
 		StageCompletePage();	
 
 		//this clear the garbage printed by StageCompletepage
 		system("cls");
 		//here i called again my stage function  (stage 2)
 		Stage(BoundaryCoordinates , block_locations_stage_2 , dots_location_2 ,grand_total_score);//this is stage number 2
 	}


	int block_locations_stage_3[][COLS]={
	{1,6},{2,6},{3,6},{4,6},{5,6},{6,6},
	{6,1},{6,2},{6,3},{6,4},{6,5},{6,6},
	

	{1,17},{2,17},{3,17},{4,17},{5,17},{6,17},
	{6,22},{6,21},{6,20},{6,19},{6,18},{6,17},

	{73,6},{74,6},{75,6},{76,6},{77,6},{78,6},
	{72,1},{72,2},{72,3},{72,4},{72,5},{72,6},

	{73,17},{74,17},{75,17},{76,17},{77,17},{78,17},
	{72,22},{72,21},{72,20},{72,19},{72,18},{72,17},

	{8,11},{10,11},{12,11},{14,11},{16,11},{18,11},{20,11},{22,11},{24,11},{26,11},{28,11},{30,11},{32,11},{34,11},{36,11},{38,11},{40,11},{42,11},{44,11},{46,11},{48,11},{50,11},{52,11},{54,11},{56,11},{58,11},{60,11},{62,11},{64,11},{66,11},{68,11},{70,11},
	{8,13},{10,13},{12,13},{14,13},{16,13},{18,13},{20,13},{22,13},{24,13},{26,13},{28,13},{30,13},{32,13},{34,13},{36,13},{38,13},{40,13},{42,13},{44,13},{46,13},{48,13},{50,13},{52,13},{54,13},{56,13},{58,13},{60,13},{62,13},{64,13},{66,13},{68,13},{70,13},
	
	{-1,-1} 
	};


	int dots_location_3[][COLS]={
	{8,1},{10,1},{12,1},{14,1},{16,1},{18,1},{20,1},{22,1},{24,1},{26,1},{28,1},{30,1},{32,1},{34,1},{36,1},{38,1},{40,1},{42,1},{44,1},{46,1},{48,1},{50,1},{52,1},{54,1},{56,1},{58,1},{60,1},{62,1},{64,1},{66,1},{68,1},{70,1},
	{8,2},{10,2},{12,2},{14,2},{16,2},{18,2},{20,2},{22,2},{24,2},{26,2},{28,2},{30,2},{32,2},{34,2},{36,2},{38,2},{40,2},{42,2},{44,2},{46,2},{48,2},{50,2},{52,2},{54,2},{56,2},{58,2},{60,2},{62,2},{64,2},{66,2},{68,2},{70,2},
	{8,22},{10,22},{12,22},{14,22},{16,22},{18,22},{20,22},{22,22},{24,22},{26,22},{28,22},{30,22},{32,22},{34,22},{36,22},{38,22},{40,22},{42,22},{44,22},{46,22},{48,22},{50,22},{52,22},{54,22},{56,22},{58,22},{60,22},{62,22},{64,22},{66,22},{68,22},{70,22},
	{8,21},{10,21},{12,21},{14,21},{16,21},{18,21},{20,21},{22,21},{24,21},{26,21},{28,21},{30,21},{32,21},{34,21},{36,21},{38,21},{40,21},{42,21},{44,21},{46,21},{48,21},{50,21},{52,21},{54,21},{56,21},{58,21},{60,21},{62,21},{64,21},{66,21},{68,21},{70,21},

		{-1,-1}
	};


	system("cls");
	
	if(stage_result==true)	
	{	
		//this is my stage completion page
 		StageCompletePage();	
 
 		//this clear the garbage printed by StageCompletepage
 		system("cls");
 		//here i called again my stage function  (stage 3)
 		Stage(BoundaryCoordinates ,block_locations_stage_3 , dots_location_3 , grand_total_score);
 	}

 	SavePlayerScoreinFile(grand_total_score);


	//ending page of game
	EndingPage(grand_total_score);

	return 0;
}

/************************************************************************************************************************/

//this function print the boundary (in which PacMan moves)
void PrintBoundary(int BoundaryCoordinates[][COLS])
{
	//constant for color of boundary
	const int ColorNumberOfBoundary=2;
	//constant for boundary chracter		
	const	char BoundarCharacter=219;

	//i represents rows number, and j represents colums number
	int i=0,j=0;

	//this while loop print the boundary of pamna according to passed array 
	while(BoundaryCoordinates[i][j] !=-1 && BoundaryCoordinates[i][j+1] !=-1)
	{
		PlaceCursor(BoundaryCoordinates[i][j] , BoundaryCoordinates[i][j+1]);
		cout<<BoundarCharacter;
		SetColorAtPoint(BoundaryCoordinates[i][j] , BoundaryCoordinates[i][j+1],ColorNumberOfBoundary);
		i++;
	}


	int DoorXcoordinate=0,DoorYcoordinate=11;
	//these loop print the door on left side of screen
	for(int counter=0 ; counter<3 ; counter++)
	{
		PlaceCursor(DoorXcoordinate,DoorYcoordinate);
		cout<<" ";
		DoorYcoordinate++;
	}
	DoorXcoordinate=79;
	DoorYcoordinate--;

	//this loop print the door on right side of screen
	for(int counter=0 ; counter<3 ; counter++)
	{
		PlaceCursor(DoorXcoordinate,DoorYcoordinate);
		cout<<" ";
		DoorYcoordinate--;
	}
}

/************************************************************************************************************************/

//this function print the blocks accordint to the passed array
void PrintBlocks(int block_locations_stage_1[][COLS])
{
	//i represents rows number, and j represents colums number
	int i=0,j=0;

	//constant for block character

	const char BLOCK_CHARACTER=240;
	//constant for color of blocs
	const int COLOR_OF_BLOCKS=9;

	//this while loop print the blocks until the end of array
	while(block_locations_stage_1[i][j] !=-1 && block_locations_stage_1[i][j+1] !=0)
	{
		PlaceCursor(block_locations_stage_1[i][j], block_locations_stage_1[i][j+1]);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(block_locations_stage_1[i][j], block_locations_stage_1[i][j+1], COLOR_OF_BLOCKS);
		i++;
	}
}


/************************************************************************************************************************/

//this function printthe dots accordint to the passed array
void PrintDots(int DotsLocationStage1[][COLS])
{
	//constant for Dot character
	const char DOT_CHARACTER=46;
	
	//i represents rows number, and j represents colums number
	int i=0,j=0;

	//this while loop print the Dots until the end of array
	while(DotsLocationStage1[i][j] !=-1 && DotsLocationStage1[i][j+1] !=0)
	{
		PlaceCursor(DotsLocationStage1[i][j] , DotsLocationStage1[i][j+1]);
		cout<<DOT_CHARACTER;
		i++;
	}
}



/************************************************************************************************************************/


//print the border of console window in starging, StageCompletepage, and ending page
void PrintWindowBorder()
{
	//constant for block of border
	const char BLOCK_CHARACTER=240;

	//constant for color of block of border
	int front_page_block_color=2;

	//x-axix and y-axix of border 
	int console_x_size=-1,console_y_size=-1;

	//this function will get max size of console window 
	GetMaxWindowCoordinates(console_x_size,console_y_size);
	

	for(int i=0 ; i<console_x_size ; i++)
	{
		PlaceCursor(i,0);
		cout<<BLOCK_CHARACTER;
		PlaceCursor(i,1);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,0,front_page_block_color);
		SetColorAtPoint(i,1,front_page_block_color);
	}

	for(int i=0 ; i<console_x_size ; i++)
	{
		PlaceCursor(i,console_y_size-1);
		cout<<BLOCK_CHARACTER;
		PlaceCursor(i,console_y_size);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,console_y_size-1,front_page_block_color);
		SetColorAtPoint(i,console_y_size,front_page_block_color);
	}

	for(int i=0 ; i<console_y_size ; i++)
	{
		PlaceCursor(0,i);
		cout<<BLOCK_CHARACTER;
		PlaceCursor(1,i);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(0,i,front_page_block_color);
		SetColorAtPoint(1,i,front_page_block_color);
	}
	
	//left vartical border
	for(int i=0 ; i<console_y_size+1 ; i++)
	{
		PlaceCursor(78,i);
		cout<<BLOCK_CHARACTER;
		PlaceCursor(79,i);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(78,i,front_page_block_color);
		SetColorAtPoint(79,i,front_page_block_color);
	}

}


/************************************************************************************************************************/

//print menu in starting page
char PrintStartMenu()
{
	char checkkey=0;
	PlaceCursor(29,27);
	cout<<"PRESS A  TO START GAME.....";
	PlaceCursor(29,29);
	cout<<"PRESS B TO SEE INSTRUCTIONS";
	PlaceCursor(29,31);
	cout<<"PRESS C TO SEE GAME RULES..";

	//take the decion of of user and
	checkkey=CheckKeyPressed(30000);
		
	return checkkey;
}


/************************************************************************************************************************/

//this function print stylish pacman on stargin page, stagecompletion page and ending page
void PrintStylishPacman()
{
	char BLOCK_CHARACTER=219;

	int i=20,j=6;
	
	//printing of P

	//leg of p
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}
	i=21;
	j=6;
	for(int counter=0 ; counter<6 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}
	i=21;
	j=9;
	for(int counter=0 ; counter<6 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}
	i=26;
	j=7;
	for(int counter=0 ; counter<2 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//printing of A

	i=29;
	j=6;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}
	i=30;
	j=6;
	for(int counter=0 ; counter<7 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}
	i=30;
	j=9;
	for(int counter=0 ; counter<7 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}

	
	i=37;
	j=6;

	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//pring of C
	i=40;
	j=6;
	
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}
	//upper horizontal line of C
	i=41;
	j=6;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;

	}
	//lower horizontal line of C

	i=41;
	j=13;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}

	//printing of M

	//right leg of M

	i=29;
	j=16;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//uper line of M
	i=30;
	j=16;
	for(int counter=0 ; counter<7 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}
	i=30;
	j=17;
	for(int counter=0 ; counter<2 ;	counter++)
	{
		PlaceCursor(i,j);
		counter<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//middle vertical line
	i=33;
	j=17;
	for(int counter=0 ; counter<3 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//left leg of M
	i=37;
	j=16;

	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//printing of A

	//left leg of A

	i=40;
	j=16;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//uper line of A
	i=40;
	j=16;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}

	i=40;
	j=19;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}

	i=48;
	j=16;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//printinf of N of stylish PacMan

	//left leg of N
	i=51;
	j=16;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//right lef of N
	i=60;
	j=16;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//diagonal of N
	i=52;
	j=16;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
		i++;
	}
	cout<<endl;
}

/************************************************************************************************************************/

//print the instruction for user 
void PrintInstruction()
{

	const char arrow_character=26;
	PlaceCursor(29,33);

	//these are line of instruction
	cout<<"PACMAN MOVEMENT\n";
	PlaceCursor(29,34);
	cout<<arrow_character<<" For Up   UP KEY";
	PlaceCursor(29,35);
	cout<<arrow_character<<" For Down  DOWN KEY";
	PlaceCursor(29,36);
	cout<<arrow_character<<" For Right  RIGHT KEY";
	PlaceCursor(29,37);
	cout<<arrow_character<<" For Left  LEFT KEY";
	PlaceCursor(29,38);
	cout<<arrow_character<<" If You Caugh By Ghost Your Will Lose Your Live";
		
	//this gave a large pause for user to read instructions	
	Sleep(5000);
	
	//these line clear the data printed before sleep
	PlaceCursor(29,33);  
	cout<<"                 ";
	PlaceCursor(29,34);  
	cout<<"                 ";
	PlaceCursor(29,35);     
	cout<<"                    ";
	PlaceCursor(29,36);       
	cout<<"                      ";
	PlaceCursor(29,37);     
	cout<<"                    ";
	PlaceCursor(29,38);
	cout<<"                                                ";
}

/************************************************************************************************************************/
//print the rules of games
void PrintGameRules()
{
	//these are rules
	PlaceCursor(29,33);
	cout<<"YOU HAVE THREE LIVE";
	
	PlaceCursor(29,34);
	cout<<"EAT MORE AND MORE DOTS TO GET MORE SCORE";

	//this gave a large pause for user to read rules
	Sleep(5000);
	//these line clear the data printed before sleep
	PlaceCursor(29,33);
	cout<<"                   ";
	PlaceCursor(29,34);
	cout<<"                                          ";
}


/************************************************************************************************************************/

//print the lives os pacman on lower right corner of windows
void LivePrinter(int lives)
{
	const char lives_representative_character=3;
	PlaceCursor(68,24);
	cout<<"lIVES: ";

	for(int counter=0 ; counter<lives ; counter++)
	{
		cout<<lives_representative_character;
	}

	for(int counter=0 ; counter<(3-lives) ; counter++)
	{
		cout<<" ";
	}
}


/************************************************************************************************************************/

//this function print the large pacman during the stage
void PrintStylishPacmanDuringStage()
{

	char BLOCK_CHARACTER=219;

	int i=8,j=32;
	
	//printing of P

	//leg of p
	for(int counter=0 ; counter<9 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}
	i=8;
	j=32;
	for(int counter=0 ; counter<7 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}
	i=8;
	j=36;
	for(int counter=0 ; counter<7 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}
	i=14;
	j=33;
	for(int counter=0 ; counter<3 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//printing of A

	i=18;
	j=32;
	for(int counter=0 ; counter<9 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}
	i=19;
	j=32;
	for(int counter=0 ; counter<7 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}
	i=19;
	j=35;
	for(int counter=0 ; counter<7 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}

	
	i=25;
	j=32;

	for(int counter=0 ; counter<9 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//pring of C
	i=28;
	j=32;
	
	for(int counter=0 ; counter<9 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}
	//upper horizontal line of C
	i=29;
	j=32;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;

	}
	//lower horizontal line of C

	i=29;
	j=40;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}

	//printing of M

	//right leg of M

	i=39;
	j=32;
	for(int counter=0 ; counter<9 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//uper line of M
	i=40;
	j=32;
	for(int counter=0 ; counter<9 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}
	i=30;
	j=32;
	for(int counter=0 ; counter<2 ;	counter++)
	{
		PlaceCursor(i,j);
		counter<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}
	//middle vertical line
	i=44;
	j=33;
	for(int counter=0 ; counter<3 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//left leg of M
	i=49;
	j=32;

	for(int counter=0 ; counter<9 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//printing of A

	//right leg of A

	i=52;
	j=32;
	for(int counter=0 ; counter<9 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//uper horizontal line of A
	i=53;
	j=32;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}
	//lower horizontal line of A

	i=53;
	j=35;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		i++;
	}
	//left leg of A

	i=61;
	j=32;
	for(int counter=0 ; counter<9 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//printi N of stylish PacMan

	//left leg of N
	i=64;
	j=32;
	for(int counter=0 ; counter<9 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//right lef of N
	i=73;
	j=32;
	for(int counter=0 ; counter<9 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
	}

	//diagonal of N
	i=65;
	j=33;
	for(int counter=0 ; counter<8 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<BLOCK_CHARACTER;
		SetColorAtPoint(i,j,2);
		j++;
		i++;
	}

	cout<<endl;	
}


/************************************************************************************************************************/

//this function check the position of pacman , ghost with poition of blocks
bool CheckWithBlocks(int x_pacman , int y_pacman , int block_locations_stage_1[][COLS])
{

	bool block_found=true;

	//
	int i=0,j=0;
	while(block_found==true && block_locations_stage_1[i][j] !=-1 && block_locations_stage_1[i][j+1] !=0)
	{
		if(block_locations_stage_1[i][j]==x_pacman && block_locations_stage_1[i][j+1]==y_pacman)
		{
			block_found=false;
		}
		i++;
	}
	return block_found;
}


/************************************************************************************************************************/

//this function check the position of pacman , ghost with poition of dots
bool CheckWithDots(int x_pacman ,int y_pacman , int DotsLocationStage1[][COLS] , bool check_with_what)
{
	bool DotFound=false;

	//i represents the row number while j represents the colum number
	int i=0,j=0;	
	
	//loop will execueted unti the end of array or until the dot founded
	while(DotFound==false && DotsLocationStage1[i][j] !=0 && DotsLocationStage1[i][j+1] !=0 )
	{				
		if(x_pacman==DotsLocationStage1[i][j] && y_pacman==DotsLocationStage1[i][j+1])
		{
			if(check_with_what==true)//if checking is with pacman then these values will be changed otherwise not
			{	
				DotsLocationStage1[i][j]=-1;
				DotsLocationStage1[i][j+1]=-1;
			}
			DotFound=true;
		}
		i++;
	}
	return DotFound;
}

/************************************************************************************************************************/

//this function control the position of pacman according to the user commands and and from boundary as well
void PositionOfPacman(int User_Control , int & x_pacman , int & y_pacman )
{
	//if pacman is in between boundary
	if(y_pacman>1 && y_pacman<22 && x_pacman<78 && x_pacman >1)
	{
		if(User_Control==77)//right arrow

		{
			PlaceCursor(x_pacman,y_pacman);
			cout<<" ";	
			x_pacman=x_pacman+1;
		}
		else
		if(User_Control==75) // left arrow
		{

			PlaceCursor(x_pacman,y_pacman);
			cout<<" ";
			x_pacman=x_pacman-1;
		}
		else
		if(User_Control==80)//down arrow
		{

			PlaceCursor(x_pacman,y_pacman);
			cout<<" ";
			y_pacman=y_pacman+1;
		}
		else
		if(User_Control==72) // up arrow
		{

			PlaceCursor(x_pacman,y_pacman);
			cout<<" ";
			y_pacman=y_pacman-1;
		}
	}
	//if pacman is on edge of boundary
	else
	{
		//pacman isn on right vertical edge
		if(x_pacman==78)
		{
			if(User_Control==75)
			{
				PlaceCursor(x_pacman,y_pacman);
				cout<<" "; 
				x_pacman--;
			}
			else if(User_Control==72 && y_pacman!=1)
			{
				PlaceCursor(x_pacman,y_pacman);
				cout<<" "; 
				y_pacman--;
			}
			else if(User_Control==80 && y_pacman!=22)
			{
				PlaceCursor(x_pacman,y_pacman);
				cout<<" "; 
				y_pacman++;	
			}
			else if(User_Control==77)
				DoorCrossing(x_pacman,y_pacman);
		} 
		//pacman isn on left vertical edge
		else if(x_pacman==1)
		{			
			if(User_Control==77)
			{
				PlaceCursor(x_pacman,y_pacman);
				cout<<" "; 
				x_pacman++;
			}
			else if(User_Control==80 && y_pacman!=22)
			{

				PlaceCursor(x_pacman,y_pacman);
				cout<<" "; 
				y_pacman++;
					
			}
			else if(User_Control==72 && y_pacman !=1)
			{

				PlaceCursor(x_pacman,y_pacman);
				cout<<" "; 
				y_pacman--;
			}
			else if(User_Control==75)
				DoorCrossing(x_pacman,y_pacman);

		}
		//pacman isn on upper horizontal edge
		else if(y_pacman==1)
		{
			if(User_Control==80)
			{
				PlaceCursor(x_pacman,y_pacman);
				cout<<" "; 
				y_pacman++;
			}
			else if(User_Control==75)
			{
				PlaceCursor(x_pacman,y_pacman);
				cout<<" "; 
				x_pacman--;

			}
			else if(User_Control==77)
			{
				PlaceCursor(x_pacman,y_pacman);
				cout<<" "; 
				x_pacman++;
			}



		}
		//pacman isn on lower horizontal edge
		else if(y_pacman==22)
		{
			if(User_Control==72)
			{
				PlaceCursor(x_pacman,y_pacman);
				cout<<" "; 
				y_pacman--;
			}
			else if(User_Control==75)
			{
				PlaceCursor(x_pacman,y_pacman);
				cout<<" "; 
				x_pacman--;

			}
			else if(User_Control==77)
			{
				PlaceCursor(x_pacman,y_pacman);
				cout<<" "; 
				x_pacman++;
			}
		}	
	}
}


/************************************************************************************************************************/

//this function will move the pacman from on Door to another
void DoorCrossing(int & x_pacman, int y_pacman)
{
	//pacman is on the left door
	if(x_pacman==1 && (y_pacman==11 || y_pacman==12 || y_pacman==13))
	{
		PlaceCursor(x_pacman,y_pacman);
		cout<<" ";
		x_pacman=77;
	}
	//pacman is on the right door
	else if(x_pacman==78 && (y_pacman==11 || y_pacman==12 || y_pacman==13))
	{
		PlaceCursor(x_pacman,y_pacman);
		cout<<" ";
		x_pacman=2;
	}
}

/************************************************************************************************************************/


bool Ghost1(int x_pacman , int y_pacman, float & x_ghost_1 , float & y_ghost_1 , float & speed_controler_of_ghost_1 , int DotsLocationStage1[][COLS] , int block_locations_stage_1[][COLS])
{
	speed_controler_of_ghost_1=speed_controler_of_ghost_1+.01;

	bool GhostWin=false;
	bool DotExist=false;
	bool block_exist=false;
	float x_ghost_temp=x_ghost_1,y_ghost_temp=y_ghost_1;

	bool check_with_ghost=false;
	

	if(x_ghost_temp==x_pacman && y_ghost_temp==y_pacman)		//pacman caught by ghost
 	{
 		GhostWin=true;
 	}
 	else
	if(speed_controler_of_ghost_1>15)
	{	
		speed_controler_of_ghost_1=0;
		DotExist=CheckWithDots( int(x_ghost_1) , int (y_ghost_1) ,DotsLocationStage1 , check_with_ghost );
		if(DotExist==true)
		{
			PlaceCursor(int(x_ghost_1),int(y_ghost_1));
			cout<<".";
		}
		else 
		{
			PlaceCursor(int(x_ghost_1) , int(y_ghost_1));
			cout<<" ";
		}



		if(x_ghost_temp<x_pacman)
		{
			x_ghost_temp++;
		}
		else if(x_ghost_temp>x_pacman)
		{
			x_ghost_temp--;
		}
		else if(y_ghost_temp<y_pacman)
		{
			y_ghost_temp++;
			
		}
		else if(y_ghost_temp>y_pacman)
		{
			y_ghost_temp--;
			
		}
 		block_exist=CheckWithBlocks(int(x_ghost_temp),int(y_ghost_temp),block_locations_stage_1);
		if(block_exist==true)
		{
			DotExist=CheckWithDots( int(x_ghost_1) , int (y_ghost_1) ,DotsLocationStage1 , check_with_ghost);
			if(DotExist==true)
			{
				PlaceCursor(int(x_ghost_1),int(y_ghost_1));
				cout<<".";
			}
			else
			{
				PlaceCursor(int(x_ghost_1),int(y_ghost_1));
				cout<<" ";
			}				
		}	
		else
		{
			while(block_exist==false)
			{
				x_ghost_temp=x_ghost_1;
				y_ghost_temp=y_ghost_1;

				if(0==rand()%4)
					x_ghost_temp++;
				else if(1==rand()%4)
					x_ghost_temp--;
				else if(2==rand()%4)
					y_ghost_temp++;
				else if(3==rand()%4)
					y_ghost_temp--;

				block_exist=CheckWithBlocks(int(x_ghost_temp),int(y_ghost_temp),block_locations_stage_1);
			}
		}
		x_ghost_1=x_ghost_temp;
		y_ghost_1=y_ghost_temp;
		PlaceCursor(int(x_ghost_1) , int(y_ghost_1));
		cout<<"#";
		SetColorAtPoint(int(x_ghost_1) , int(y_ghost_1),14);		
	}
	
	return GhostWin;
}


/************************************************************************************************************************/



bool Ghost2(int x_pacman , int y_pacman, float & x_ghost_2 , float & y_ghost_2 , float & speed_controler_of_ghost_2 , int DotsLocationStage1[][COLS] , int block_locations_stage_1[][COLS])
{

	speed_controler_of_ghost_2=speed_controler_of_ghost_2+.01;

	bool GhostWin=false;
	bool DotExist=false,block_exist=false;
	float x_ghost_temp=x_ghost_2,y_ghost_temp=y_ghost_2;

	bool check_with_ghost=false;
	

	if(x_ghost_temp==x_pacman && y_ghost_temp==y_pacman)		//pacman caught by ghost
 	{
 		GhostWin=true;
 	}
	else if(speed_controler_of_ghost_2>15)
	{
		speed_controler_of_ghost_2=0;

		DotExist=CheckWithDots( int(x_ghost_temp) , int (y_ghost_temp) ,DotsLocationStage1 , check_with_ghost);
		if(DotExist==false)
		{
			PlaceCursor(int(x_ghost_temp),int(y_ghost_temp));
			cout<<" ";
		}
		else
		{
			PlaceCursor(int(x_ghost_temp),int(y_ghost_temp));
			cout<<".";
		}

		


		if(y_ghost_temp<y_pacman)
		{
			y_ghost_temp++;
			
		}
		else if(y_ghost_temp>y_pacman)
		{
			y_ghost_temp--;
			
		}else
		if(x_ghost_temp<x_pacman)
		{
			x_ghost_temp++;
			
		}
		else if(x_ghost_temp>x_pacman)
		{
			x_ghost_temp--;
			
		}
	
	


		if(x_ghost_temp==x_pacman && y_ghost_temp==y_pacman)		//pacman caught by ghost
	 	{
	 		GhostWin=true;
	 	}
	 	else
	 	{
			block_exist=CheckWithBlocks(int(x_ghost_temp),int(y_ghost_temp),block_locations_stage_1);
			if(block_exist==true)
			{
				x_ghost_2=x_ghost_temp;
				y_ghost_2=y_ghost_temp;
			}
			else
			{
				while(block_exist==false)
				{
					x_ghost_temp=x_ghost_2;
					y_ghost_temp=y_ghost_2;

					if(0==rand()%4)
						x_ghost_temp++;
					else if(1==rand()%4)
						x_ghost_temp--;
					else if(2==rand()%4)
						y_ghost_temp++;
					else if(3==rand()%4)
						y_ghost_temp--;

					block_exist=CheckWithBlocks(int(x_ghost_temp),int(y_ghost_temp),block_locations_stage_1);
				}
			}
		}
		x_ghost_2=x_ghost_temp;
		y_ghost_2=y_ghost_temp;
		PlaceCursor(int(x_ghost_2) , int(y_ghost_2));
		cout<<"#";
		SetColorAtPoint(int(x_ghost_2) , int(y_ghost_2),77);

	}
	
	return GhostWin;
}


/************************************************************************************************************************/

//this function calculate the total dots passed to stage function and return it
int CalculateTotalDotsOFfStage(int Dots_Locations[][COLS])
{
	int total_dots=0;
	//i represents the row number, j represents the colums number
	int i=0,j=0;

	// loop will be execueted until the end of array
	while(Dots_Locations[i][j] !=-1 && Dots_Locations[i][j+1] !=-1)
	{
		i++;
		total_dots++;
	}

	return total_dots;
}


/************************************************************************************************************************/

//this function is used to find the length of name of player

int FindLengthOfString(char String[]) 		// defination of length functoin
{
	int Length=0;							//this is length variable of 
	bool Flag=true; 						// this bool variable will become false when the the element "zero" of the array come
	while(Flag==true) 						// while loop 
	{
		if(String[Length] ==0 )				// this will check for element '0' of the array, if it come the Flag become False and loop will break out
		{
			Flag=false;
		}
		else Length++; 						// until the element '0' no come it will go in increasing
	}

	return Length; 							//this is returnning of the size  of string
}



/************************************************************************************************************************/

//this is starting page of game when game start's 
void StartingPage()
{
	int maximum_lengt_of_player_name=25;
	char player_name[maximum_lengt_of_player_name];
	int player_name_length_returned_by_length_function=-1;
	PrintWindowBorder();	

	PrintStylishPacman();

	char user_input=0;
	while(user_input !=-1)
	{
		user_input=PrintStartMenu();
		if(user_input==66 || user_input == 98) //to print instruction
		{
			PrintInstruction();
		}
		else if(user_input == 67 || user_input ==99)	//to print game rules
		{
			PrintGameRules();
		}
		else if(user_input==65 || user_input==97)	//to start games
		{
			PlaceCursor(29,27);
			cout<<"                            ";
			PlaceCursor(29,29);
			cout<<"                           ";
			PlaceCursor(29,31);
			cout<<"                           ";
			user_input=-1;

			
			PlaceCursor(27,27);
			cout<<"ENTER YOUR NAME : ";
			//this will get the user name from input device
			cin.getline(player_name , 20 , '\n');

			player_name_length_returned_by_length_function=FindLengthOfString(player_name);
			
			//this loop will make sure that user has entered his name
			while(player_name_length_returned_by_length_function==0)
			{
				PlaceCursor(27,27);
				cout<<"ENTER YOUR NAME : ";
				cin.getline(player_name , 20 , '\n');
				player_name_length_returned_by_length_function=FindLengthOfString(player_name);
			}

			//this will save the player name in file
			SavePlayerNameInFile(player_name);
			
			//here is loading style of game
			LoadingStyle();
		}	
	}
}

/************************************************************************************************************************/

//this is starting page, when the game is start
void StageCompletePage()
{
	system("cls");
	char user_input=-1;
	PrintWindowBorder();
	PrintStylishPacman();

	//this print the formal line for uers
	PlaceCursor(22,27);
	cout<<"Congratulations, Your have cleared the level"<<endl;
	PlaceCursor(22,28);
	
	//this will ask the usr to press "enter" to start next stage 
	cout<<"Press Enter to start next level";
	while(user_input !=13)
	{
		user_input=CheckKeyPressed1();
	}
}


/************************************************************************************************************************/

//this is ending page, when the game is finished
void EndingPage(int grand_total_score)
{
	system("cls");
	char player_name[20];

	//print the borde of windows
	PrintWindowBorder();

	//print stylish pacman
	PrintStylishPacman();
	//take player name from file
	PrintPlayerNameFromFile(player_name);
	
	//these lined print formal line for the user
	PlaceCursor(22,27);
	cout<<"Congratulations ";
	cout<<player_name;
	cout<<", YOUR SCORED "<<grand_total_score;
	PlaceCursor(22,28);
	cout<<"Thanks For Playing My Game";
}

/************************************************************************************************************************/

//this function make a awesome style on stargin page
void LoadingStyle()
{
	PlaceCursor(30,26);
	cout<<"Loading.... Please Wait";

	//i represents rows number, and j represents colums number
	int i=20,j=27;

	//loading style character constant(border of loading figure)
	const char loadng_figure_character=196;

	//pacman character
	const char PackmanCharacter='\2';
	PlaceCursor(19,27);
	cout<<"|";
	PlaceCursor(19,28);
	cout<<"|";
	PlaceCursor(19,29);
	cout<<"|";

	//this print the boundary of loading figure
	for(int counter=0 ; counter<41 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<loadng_figure_character;
		PlaceCursor(i,j+2);
		cout<<loadng_figure_character;
		i++;
	}

	PlaceCursor(61,27);
	cout<<"|";
	PlaceCursor(61,28);
	cout<<"|";
	PlaceCursor(61,29);
	cout<<"|";


	i=20;
	j=28;
	//this loop fill that empty figure  with pacman characters
	for(int counter=0 ; counter<41 ; counter++)
	{
		PlaceCursor(i,j);
		cout<<PackmanCharacter;
		SetColorAtPoint(i,j,2);
		i++;
		Sleep(200);
	}	
}


/************************************************************************************************************************/


bool Stage(int BoundaryCoordinates[][COLS] , int block_locations_stage_1[][COLS] , int DotsLocationStage1[][COLS] , int & grand_total_score)
{
	//this print the stylish PacMan on screen
	PrintStylishPacmanDuringStage();
	PrintBoundary(BoundaryCoordinates);
	PrintBlocks(block_locations_stage_1);
	PrintDots(DotsLocationStage1);

	int total_dots_of_stage=-1;

	total_dots_of_stage=CalculateTotalDotsOFfStage(DotsLocationStage1);

	
	int User_Control=-1;
	int lives=3;
	int x_pacman=2,y_pacman=2;
	int x_intial_pacman=1,y_intial_pacman=1;
	int score=0;
	bool DotExist;
	float speed_controler_of_ghost_1=0,speed_controler_of_ghost_2=0;


	bool player_win=false;

	bool pacman_alive=true,permission_from_block=false,dot_exist,ghost_1_return,ghost_2_return;
	const char PackmanCharacter='\2';

	float x_ghost1=-1,y_ghost1=-1;
	float x_ghost2=-1,y_ghost2=-1;

	bool check_with_pacman=true;
	bool check_with_ghost=false;
	bool stage_result=true;

	//these three line print the the score at starting of stage only.
	PlaceCursor(2,24);
	cout<<"Score: ";
	cout<<score;


	while(player_win==false &&  lives>0 )
	{
		
		LivePrinter(lives);

		x_pacman=40;
		y_pacman=3;
		x_intial_pacman=40,y_intial_pacman=1;
		x_ghost1=71;
		y_ghost1=21;
		x_ghost2=7;
		y_ghost2=21;

		while(player_win==false && pacman_alive==true)
		{
			PlaceCursor(x_intial_pacman,y_intial_pacman); 
			cout<<PackmanCharacter;
			x_pacman=x_intial_pacman;
			y_pacman=y_intial_pacman;
			User_Control=CheckKeyPressed1();
			PositionOfPacman(User_Control ,x_pacman ,y_pacman);
			permission_from_block=CheckWithBlocks(x_pacman,y_pacman,block_locations_stage_1);
			
			if(score==total_dots_of_stage)
			{
				player_win=true;
				stage_result=true;
			}
			else
			if(permission_from_block==true)
			{
				dot_exist=CheckWithDots(x_pacman,y_pacman ,DotsLocationStage1 , check_with_pacman);
				if(dot_exist==true)
				{
					score++;
					PlaceCursor(2,24);
					cout<<"Score: ";
					cout<<score;
				}
				x_intial_pacman=x_pacman;
				y_intial_pacman=y_pacman;
			}

			//these are ghost functions
			ghost_1_return=Ghost1(x_pacman , y_pacman, x_ghost1 , y_ghost1 , speed_controler_of_ghost_1 , DotsLocationStage1 , block_locations_stage_1);
			ghost_2_return=Ghost2(x_pacman,y_pacman,x_ghost2 ,y_ghost2 ,speed_controler_of_ghost_2,DotsLocationStage1,block_locations_stage_1);
				
			//if ghost1 caught pacman	
			if(ghost_1_return==true)
			{
				PlaceCursor(x_pacman,y_pacman);
				cout<<" ";


				DotExist=CheckWithDots( int(x_ghost2) , int (y_ghost2) ,DotsLocationStage1 , check_with_ghost);
				if(DotExist==true)
				{
					PlaceCursor(int(x_ghost2),int(y_ghost2));
					cout<<".";
				}
				else
				{
					PlaceCursor(int(x_ghost2),int(y_ghost2));
					cout<<" ";
				}
				pacman_alive=false;
				lives--;

			}
			//in case if ghost2 caught pacman
			else if(ghost_2_return==true)
			{
				PlaceCursor(x_pacman,y_pacman);
				cout<<" ";

				DotExist=CheckWithDots( int(x_ghost1) , int (y_ghost1) ,DotsLocationStage1 , check_with_ghost);
				if(DotExist==true)
				{
					PlaceCursor(int(x_ghost1),int(y_ghost1));
					cout<<".";
				}
				else
				{
					PlaceCursor(int(x_ghost1),int(y_ghost1));
					cout<<" ";
				}
				pacman_alive=false;
				lives--;
			}
		}

		pacman_alive=true;
		LivePrinter(lives);
	}

	if(lives==0)
	{
		stage_result=false;
	}

	grand_total_score=grand_total_score+score;

	return stage_result;
}

/************************************************************************************************************************/

//this function save the name of player in file
void SavePlayerNameInFile(char player_name[])
{
	ofstream InputStream; 
	InputStream.open("PlayerNameFile.txt", std::ofstream::out | std::ofstream::app);

	if(InputStream.is_open())		//check either file is open or not
	{
		InputStream << player_name;
		InputStream<<" ";
		cout<<" ";
		
	}
	else
	{
		cout<<"PLAYER NAME FILE NOT OPENED";		// in case file is not opened this will be printed
	}
}

/************************************************************************************************************************/

//take the player name from file and save it in string
void PrintPlayerNameFromFile(char player_name[])
{
	ifstream InputStream ("PlayerNameFile.txt");

	if(InputStream.is_open())			//check either file is open or not
	{
		InputStream>>player_name;
	}
	else
	{
		cout<<"PLAYER NAME FILE NOT OPENED";	// in case file is not opened this will be printed
	}
}

/************************************************************************************************************************/

void SavePlayerScoreinFile(int grand_total_score)
{	if(InputStream.is_open())		//check either file is open or not

	ofstream InputStream;
	InputStream.open("PlayerNameFile.txt", std::ofstream::out | std::ofstream::app);
	
	{
		InputStream<<" ";
		InputStream<<grand_total_score;
		InputStream<<endl;
	}
	else
		cout<<"PLAYER NAME FIE NOT OPENED";		// in case file is not opened this will be printed
}
void PrintHallOfFame()
{
	char player_name[20];
	int player_score=-1;

	ifstream lol ("PlayerNameFile.txt");

	if(lol.is_open())			//check either file is open or not
	{
		lol>>player_name;
	}
	else
	{
		cout<<"PLAYER NAME FILE NOT OPENED";	// in case file is not opened this will be printed
	}
}
