/*******************************************************************
	*   CS 121 Programming Assignment 4:8
	*   File: Retrieval Of Narsil Shards Game
	*   Author: Wesley Adams
	*   Desc: An adventure Game in which you play as the an hero in middle earth attempting to find the stolen shards 
	*         of narsil and return them to rivendell.
	*   Date: 04/10/2019
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;
//Take item 
int TakeItem(unsigned int rooms[][5], int row, int col, string Object);


void DescribeTheShire00_00();
void DescribeWeatherTop00_01();
void DescribeMistyMountains00_02();
void DescribeRivendell00_03();
void DescribeLorien00_04();
void DescribeIsengard00_05();
void DescribeErebor00_06();
void DescribeIronHills00_07();
void DescribeFornost00_08();
void DescribeAngmar00_09();
void DescribeEttenmoors00_10();
void DescribeMountGundabad00_11();
void DescribeMinasTirith00_12();
void DescribeForestFangorn00_13();
void DescribeLondDaer00_14();
void DescribeGreyHavens00_15();
void DescribeMirkwood00_16();
void DescribeBlackGate00_17();
void DescribeHelmsDeep00_18();
void DescribeDagorlad00_19();
void DescribeRohanWesfold00_20();
void DescribeRohanEastfold00_21();
void DescribeHarlindon00_22();
void DescribeDeadMarshes00_23();
void DescribeMinasMorgul00_24();

//Describe Room Contents
void DescribeRoomContents(int roomDesc, int row, int col);
void BuildRooms(unsigned int rooms[][5]);

//define doors
#define DOOR_NORTH	0x00000001
#define DOOR_EAST	0x00000002
#define DOOR_SOUTH	0x00000004
#define DOOR_WEST	0x00000008

//define treasure items
#define First_Shard_of_Narsil	0x00000010
#define Second_Shard_of_Narsil	0x00000020
#define Third_Shard_of_Narsil	0x00000040
#define Fourth_Shard_of_Narsil	0x00000080
	
//other items
#define Sword							0x00000100
#define Palantir						0x00000200
#define A_Pint_From_The_Green_Dragon	0x00000400
#define Elven_Harp						0x00000800
#define Narya							0x00001000
#define Salted_Pork						0x00002000
#define Shield							0x00004000
#define Old_Boot						0x00008000

//define creatures
#define Warg							0x00010000
#define Halfling						0x00020000
#define Orc_Legion						0x00040000
#define Dragon							0x00080000
#define Ranger							0x00100000
#define Troll							0x00200000
#define Elves							0x00400000
#define Dwarves							0x00800000

//define conditions
#define DANGEROUS						0x01000000
#define DEADLY							0x02000000
#define FRIENDLY						0x04000000
#define CAUTION							0x08000000



int main()
{
	string mystring;

	//declare vars
	string cmdVerb;
	string cmdObj;
	int iRow;
	int iCol;
	int iNumRows;
	int iNumCols;

	//initialize vars; start in 2,1 (shire)
	iRow = 2;
	iCol = 1;
	iNumRows = 5;
	iNumCols = 5;

	//Fancy Art
	cout << "" << endl;
	cout << "                                                                                **                                                                             " << endl;
	cout << "                                                                               *&&/.                                                                           " << endl;
	cout << "                                                                             ,(&&&@&.                                                                          " << endl;
	cout << "                                                                             %@&&&@@&(                                                                         " << endl;
	cout << "                                                                           ,#@&@@@@@&@#,                                                                       " << endl;
	cout << "                                                                          .%@@&@&&@@@&@&*                                                                      " << endl;
	cout << "                                                                         ,#@&&@@@%(&&@&&&%.                                                                    " << endl;
	cout << "                                                                        .%@@@@@&&/ ,&@@&@&%/                                                                   " << endl;
	cout << "                                                                       ,#&&&@@&@/.  ,#&@&@@@/.                                                                 " << endl;
	cout << "                                                                      .&@&&@@&@&.     #&@@@&&%.                                                                " << endl;
	cout << "                                                                     *#@@&@@&@@%      .*&@@@&@%*                                                               " << endl;
	cout << "                                                                    .&@&&&&@@@&/        *#@@@@@&*.                                                             " << endl;
	cout << "                                                                   *%&&&&&&@@,          /%@&@@&%                                                               " << endl;
	cout << "                                                                  .&@@@&&&&@&%*             (%&&&&%*.                                                          " << endl;
	cout << "                                                                 .(&&@&&&&&&@(.              ,&&&&@&(                                                          " << endl;
	cout << "                                                                 %&@@@@&&&&@@*                .*&&@@@(,                                                        " << endl;
	cout << "                                              .,                *@@&&@@&&&&@&.                  ./&@@@&,                                                       " << endl;
	cout << "                                             ,&@%(             /%&&&@@@&&&&                     ,(&@&                                                          " << endl;
	cout << "                                            #&&&&@%/          ,&@&@@@&&&&&&@&.                       #&@@%/                                                    " << endl;
	cout << "                                          *%@&/.,(@@#*       #&@@&&@@@@&&&&@@%*                       .%&@@(,                                                  " << endl;
	cout << "                                        ./@@%*    ,(@@#,  .*%@@@@&&&&&&&&&&@&@&(                        ,&@@&,                                                 " << endl;
	cout << "                                       (&@        *#@@(*%@@@@@@&&&&&&&&&&&&@@&/. ,##                   .(@@&%                                                  " << endl;
	cout << "                                     *%@@&,           *%@@&@&&&&&&&&&&&&&&&&@&&&&%&@&%                     (&@@%*                                              " << endl;
	cout << "                                   .(@@&(,             .&@&&&&&&&&&&&&&&&&&&@@&&&&@@@%                      .&@&&/.               (#                           " << endl;
	cout << "                                  *&@@@#,          .(,/%&@&&&&&&&&&&&&&&&&&&&&&&@@@&@%         *%/           .(@&@%.             ,&@(.                         " << endl;
	cout << "                                .%@@@@@#,          ,&&&@@@&&&&&&&&&&&&&&&&&&&&&&&&&@&%.        *@@%(,          (&&@%/           *%@@&%                         " << endl;
	cout << "                               #&@@&@@@(.   **     *@@@&@&@@&&&&&&&&&&&&&&&&&&&&&@@&@&. ,*.    /@&@@*         .&@@@/.         %@&&@@(.                         " << endl;
	cout << "                             /%@@&&&&&@/.,#&@&.   .#@@@@&@@&&&&&&&&&&&&&&&&&&&&&&@&@@&&&@@/.  .(@@@&@@@#*        .(@@@%/     .#&@@@&(%@%                       " << endl;
	cout << "                           ,#@&@@&&&&@&&&@&&@@,   /&@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@&@#. ,&@&&@@&@&@@%/        (&&@@/..*&&&@&@%* .%@#,                     " << endl;
	cout << "                         ./@@&@@&&&&&&&@@@@&&@/.  %@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@&@@%/%&&@@&**(&&@&@@%/       .&@@@&@@@@&&@&%,  ,#@&.                    " << endl;
	cout << "                        *&&&&&&&&&&&&&&&&&&&@@#, *@@@@&&@@(#&@&@@&&&&&&&&&&&&&&&&&&&&&&&@@@@@@&&&@*    *(&@@@%(      .(&@&@@@&&&&&&(    %@%*                   " << endl;
	cout << "                      .%@&@&&&&&&&&&&&&&&&@@&&%/(&@@&&@@&@#, (%@@&&&&&&&&&&&&&&&&&&&&&&&&&&@&@#(@@(.     .*&@&@%/     .(@@&&@&&&&&@&.   ./@&(                  " << endl;
	cout << "                     #&&@@@&@&@&&@@@@@&&&&@@@&&&&@&&&&%#%&&(..(@@&&&&&&&&@@@@&&@&&@&@@@@&@&@@%  #,       .*&@@&.    ,#@@@&@&&&&@&@*     (&@(.                  " << endl;
	cout << "                  ,(&@@&@@@@@&&&&@@@&&&&&&&&&&@&@&@&.   ,*,.(@@&&&&@@@@&&@&@&&&&@@@&@&@&&@(.  .(&/.        ./&@#,   .(@@&&@&&&&&&&     ,#@%.                   " << endl;
	cout << "                 .%&@&&,.&@@@@@@&&&@@@&&&&&&&&&&@@@@&(       .#@@&&&&@@@@&&&&&@@@@@&&@&&@&@&.    ,&(.          (%&(   .(@&@&@&&&&&&@&&/.    .&&/.              " << endl;
	cout << "                #&&@&*  .&@%&@@@@@@&&@&@@&&@@@&@&&&@/.       /&&@@@&&&&&@@&(,(&@@@(,%&@&&@%*      /#*            #&.   *@@@@@&&@&&&&@&@&,    .(@%.             " << endl;
	cout << "              /%@@#*.   ,%/(&&&&@%* .%@@#&&@%%@@@%        .&@@@&&&@&&@@%/  ,#&  /&&@&&.        ,,             ./,  .&@&&&&@&@@&&&@@@&%.    (&%*                " << endl;
	cout << "            *#&@#*      .  %@@@&%    ./&/.*%&@*.&@&/       ,#@&&&@@&&&@&(     ,%%*  .(@,                              (&&@#*%&//&@@@@@&%%(,   .%&*             " << endl;
	cout << "          ,(@,          ,&@@&*          ./@&. /,      ,#& .%&&&.      ,##,   *@%.                               .(@@#, *, .,&@@@@@(,.     *&%                  " << endl;
	cout << "        ./&@(,           ./@&%/            ,%/  .//.      %&@/.   .%%.       ./&(.   .(,                                 .&@#,       .%&@&@&&,     ,(%*        " << endl;
	cout << "       ,&&/.             ,#@&,              *.   .*      *@                ,#&*                                         (&/.          ///(((/      *%/.        " << endl;
	cout << "     .&&*.               /&&(                           /%%/.                *%&,                                         .*.                          /#,     " << endl;
	cout << "   .%%.                  %&*                            ,.                   (#*                                                                         /(    " << endl;
	cout << "  ((                    .%/                                                                                                                                **  " << endl;
	cout << ",,                      ,.                                                                                                                                   ,." << endl;
	cout << "_______________________________________________________________________________________________________________________________________________________________" << endl;
	cout << "    The fellowship of the ring will congregate at Rivendell to decide what should be done about the" << endl;
	cout << "    threat of the one ring and the Dark Lord Sauron, but Eol an elf with jealousy in his heart has" << endl;
	cout << "    spirited away four shards of Narsil. You must search for them across middle earth braving" << endl;
	cout << "    various monsters, dangerous terrain, and legendary locations and return them to Rivendell " << endl;
	cout << "    before the fellowship convenes." << endl;
	cout << "" << endl;
	cout << "    To move from location to location use commands such as GO NORTH to go to new locations in" << endl;
	cout << "    middle earth. When you find an item pick it up with a command like TAKE FIRST_SHARD_OF_NARSIL. Some " << endl;
	cout << "    locations are held by threatening creatures like orc legions, or dragons. Since you are one man " << endl;
	cout << "    you cannot hope to win so you must run." << endl;
	cout << "" << endl;
	cout <<"     Press the enter key to begin.\n"<<endl;
	getc(stdin);
 
	//Game board
	unsigned int MiddleEarth[5][5];

	//InitializeGameboard to 0
	for(int x= 0; x<5; x++)
	{
		for(int y = 0; y<5; y++)
		{
			MiddleEarth[x][y] = 0x00000000;
		}
	}
	BuildRooms(MiddleEarth);

	//player variables
	int iPlayer = 0;
	int endRow = 1;
	int endCol =2;

	//set quit game var
	bool bQuitGame = false;

	//write start location description
	DescribeTheShire00_00();
	
	//start game loop
	while(!bQuitGame)
	{
		cout << "\n What do you want to do?"<<endl;

		//read in commands
		cin >> cmdVerb >> cmdObj;

		//set counter var
		int idx = 0;

		//set up loop to caps
		while(idx<cmdVerb.length())
		{
			//loop through each char in string to change to uppercase
			cmdVerb[idx] = toupper(cmdVerb[idx]);
			idx++;
		}
		

		//reset counter var 
		idx = 0;

		//set up loop to caps for obj
		while(idx<cmdObj.length())
		{
			//loop through each char in string to change to uppercase
			cmdObj[idx] = toupper(cmdObj[idx]);
			idx++;
		}
		cout << endl;

		if (cmdVerb == "GO")
		{
			//cout << "Command Verb is GO" << endl;
			if(cmdObj == "NORTH")
			{
				//cout << "Direction is NORTH" << endl;
				if(MiddleEarth[iRow][iCol] & DOOR_NORTH)//  if(iRow>0)
				{
					iRow--;//Move up a row
					DescribeRoomContents(MiddleEarth[iRow][iCol],iRow,iCol);
				}
				else{
					cout << "There is no passage in that direction from here...." << endl;
				}

			}
			else if (cmdObj == "SOUTH")
			{
				//cout << "Direction is SOUTH" << endl;
				if(MiddleEarth[iRow][iCol] & DOOR_SOUTH)//if(iRow<iNumRows-1)
				{
					iRow++;//Move down a row
					DescribeRoomContents(MiddleEarth[iRow][iCol],iRow,iCol);
				}
				else{
					cout << "There is no passage in that direction from here...." << endl;
				}
			}
			else if (cmdObj == "EAST")
			{
				//cout << "Direction is EAST" << endl;
				if(MiddleEarth[iRow][iCol] & DOOR_EAST)//if(iCol<iNumCols-1)
				{
					iCol++;//Move right a column
					DescribeRoomContents(MiddleEarth[iRow][iCol],iRow,iCol);
				}
				else{
					cout << "There is no passage in that direction from here...." << endl;
				}
			}
			else if (cmdObj == "WEST")
			{
				//cout << "Direction is WEST" << endl;
				if(MiddleEarth[iRow][iCol] & DOOR_WEST)//if(iCol>0)
				{
					iCol--;//Move left a column
					DescribeRoomContents(MiddleEarth[iRow][iCol],iRow,iCol);
				}
				else{
					cout << "There is no passage in that direction from here...." << endl;
				}
			}
			else
			{
				//if unknown command
				cout << "I dont understand GO" << cmdObj << endl;
			}	
			//Finish
			if((iRow == endRow)&&(iCol == endCol))
			{
				//see if player has the goods
				if((iPlayer & First_Shard_of_Narsil) && (iPlayer & Second_Shard_of_Narsil) && (iPlayer & Third_Shard_of_Narsil) && (iPlayer & Fourth_Shard_of_Narsil))
				{
					//if yes inform player
					cout << "You tell Elrond that you have the four Shards of Narsil" << endl;
					cout << "the first meeting of the fellowship can now commence at Rivendell." << endl;
					cout << "Congratulations! You have won the game!" << endl;
					getc(stdin);
					//end game
					bQuitGame = true;
				}

			}

		}
		else if(cmdVerb == "TAKE")
		{
			//to take an item
			int TakeVal = TakeItem(MiddleEarth, iRow, iCol, cmdObj);

			if (TakeVal)
			{
				iPlayer |= TakeVal;
				cout << "You are now carrying " << cmdObj << endl;

			}
			else
			{
				cout << "You cannot take " << cmdObj << " from this location." << endl;
			}
		}
		else if(cmdVerb == "QUIT")
		{
			//quit command
			bQuitGame = true;
			cout << "Command Verb is QUIT" << endl;
			return 0;
		}

		else
		{
			cout << "I dont understand" << cmdVerb << endl;
		}
		//cout << "The Command is: " << cmdVerb << " " << cmdObj << endl;
		cout << "The Location is: Row " << iRow << ", Col " << iCol << endl;
	}//End Game Loop

	cin>>mystring;
}

void DescribeRoomContents(int roomDesc, int row, int col)
{
	switch(row)
	{
	case 0:
		switch(col)
		{
		case 0:
			//0,0 fornost
			DescribeFornost00_08();
			break;
        case 1:
			//0,1 angmar
			DescribeAngmar00_09();
			break;
		case 2:
			//0,2 mount gundabad
			DescribeMountGundabad00_11();
			break;
		case 3:
			//0,3 misty mountains
			DescribeMistyMountains00_02();
			break;
		case 4:
			//0,4 iron hills
			DescribeIronHills00_07();
			break;
		}
	break;

	case 1:
		switch(col)
		{
		case 0:
			//1,0 weathertop
			DescribeWeatherTop00_01();
			break;
        case 1:
			//1,1 ettenmoors
			DescribeEttenmoors00_10();
			break;
		case 2:
			//1,2 rivendell
			DescribeRivendell00_03();
			break;
		case 3:
			//1,3 mirkwood
			DescribeMirkwood00_16();
			break;
		case 4:
			//1,4 erebor
			DescribeErebor00_06();
			break;
		}
	break;

	case 2:
		switch(col)
		{
		case 0:
			//2,0 Harlindon
			DescribeHarlindon00_22();
			break;
        case 1:
			//2,1 Shire
			DescribeTheShire00_00();
			break;
		case 2:
			//2,2 Lorien
			DescribeLorien00_04();
			break;
		case 3:
			//2,3 DeadMarshes
			DescribeDeadMarshes00_23();
			break;
		case 4:
			//2,4 BlackGate
			DescribeBlackGate00_17();
			break;
		}
	break;

	case 3:
		switch(col)
		{
		case 0:
			//3,0 Grey Havens
			DescribeGreyHavens00_15();
			break;
        case 1:
			//3,1 Lond Daer
			DescribeLondDaer00_14();
			break;
		case 2:
			//3,2 Isengard
			DescribeIsengard00_05();
			break;
		case 3:
			//3,3 Fangorn
			DescribeForestFangorn00_13();
			break;
		case 4:
			//3,4 Minas Tirith
			DescribeMinasTirith00_12();
			break;
		}
	break;


	case 4:
		switch(col)
		{
		case 0:
			//4,0 HelmsDeep
			DescribeHelmsDeep00_18();
			break;
        case 1:
			//4,1 Rohan:Westfold
			DescribeRohanWesfold00_20();
			break;
		case 2:
			//4,2 Rohan:Eastfold
			DescribeRohanEastfold00_21();
			break;
		case 3:
			//4,3 Dagorlad
			DescribeDagorlad00_19();
			break;
		case 4:
			//4,4 Minas Morgul
			DescribeMinasMorgul00_24();
			break;
		}
	break;

	}

	//Check creatures
	if(roomDesc & Warg)
	{
		cout <<"You see a wild Warg in front of you..."<<endl;
	}
	if(roomDesc & Halfling)
	{
		cout <<"You see a bunch of drunk halflings stumbling in front of you..."<<endl;
	}
	if(roomDesc & Orc_Legion)
	{
		cout <<"You see an orc legion in front of you..."<<endl;
	}
	if(roomDesc & Dragon)
	{
		cout <<"You see a large dragon flying overhead..."<<endl;
	}
	if(roomDesc & Ranger)
	{
		cout <<"A Ranger of the north stands before you..."<<endl;
	}
	if(roomDesc & Troll)
	{
		cout <<"A large troll is mucking about in your path..."<<endl;
	}
	if(roomDesc & Elves)
	{
		cout <<"An elven citizen stands before you..."<<endl;
	}
	if(roomDesc & Dwarves)
	{
		cout <<"An angry dwarf is shouting at you...Hes drunk ignore him..."<<endl;
	}

	//check conditions
	if(roomDesc & DEADLY)
	{
		cout << "These are deadly..." << endl;
	}
	if(roomDesc & DANGEROUS)
	{
		cout << "These are dangerous..." << endl;
	}
	if(roomDesc & CAUTION)
	{
		cout <<"Be cautious..."<<endl;
	}
	if(roomDesc & FRIENDLY)
	{
		cout <<"It poses no threat and may be helpful..."<<endl;
	}

	//Check for other items
	if(roomDesc & Sword)
	{
		cout <<"There is a Sword off to the side..."<<endl;
	}
	if(roomDesc & Palantir)
	{
		cout <<"there is something dark glinting in the water...its a Palantir"<<endl;
	}
	if(roomDesc & A_Pint_From_The_Green_Dragon)
	{
		cout <<"You can get a pint of the finest ale here, A_Pint_From_The_Green_Dragon..."<<endl;
	}
	if(roomDesc & Elven_Harp)
	{
		cout <<"there is an Elven_Harp playing music to your right..."<<endl;
	}
	if(roomDesc & Narya)
	{
		cout <<"The see intricate metal work of an elven ring in a nook over there...its Narya..."<<endl;
	}
	if(roomDesc & Salted_Pork)
	{
		cout <<"You can get a leg of Salted_Pork here..."<<endl;
	}
	if(roomDesc & Shield)
	{
		cout <<"Theres a Shield off to the side..."<<endl;
	}
	if(roomDesc & Old_Boot)
	{
		cout <<"You see an Old_Boot on the ground..."<<endl;
	}

	//check for treasure items
	if(roomDesc & First_Shard_of_Narsil)
	{
		cout <<"The First_Shard_of_Narsil is laying on the floor..."<<endl;
	}
	if(roomDesc & Second_Shard_of_Narsil)
	{
		cout <<"The Second_Shard_of_Narsil is on the floor..."<<endl;
	}
	if(roomDesc & Third_Shard_of_Narsil)
	{
		cout <<"The Third_Shard_of_Narsil of Narsil lays ahead..."<<endl;
	}
	if(roomDesc & Fourth_Shard_of_Narsil)
	{
		cout <<"The Fourth_Shard_of_Narsil of Narsil lays ahead..."<<endl;
	}
	
	//check DOORS
	if(roomDesc & DOOR_NORTH)
	{
		cout <<"There is a trail to the North..."<<endl;
	}
	if(roomDesc & DOOR_EAST)
	{
		cout <<"There is a passage to the East..."<<endl;
	}
	if(roomDesc & DOOR_SOUTH)
	{
		cout <<"There is a path to the South..."<<endl;
	}
	if(roomDesc & DOOR_WEST)
	{
		cout <<"There is a road to the West..."<<endl;
	}
}

void BuildRooms(unsigned int rooms[][5])
{
	
//FORNOST SE
rooms[0][0] = DOOR_SOUTH | DOOR_EAST | Ranger | FRIENDLY | Sword | Second_Shard_of_Narsil;

//ANGMAR SWE
rooms[0][1] = DOOR_SOUTH | DOOR_EAST | DOOR_WEST | Orc_Legion | DANGEROUS;

//MOUNT GUNDABAD WES
rooms[0][2] = DOOR_WEST | DOOR_EAST | DOOR_SOUTH | Dragon | DEADLY;

//MISTY MOUNTAINS EW
rooms[0][3] = DOOR_WEST | DOOR_EAST;

//IRON HILLS SW
rooms[0][4] = DOOR_SOUTH | DOOR_WEST | Dwarves | CAUTION | First_Shard_of_Narsil;

//WEATHER TOP NS
rooms[1][0] = DOOR_SOUTH | DOOR_NORTH | Ranger | FRIENDLY | Shield;

//ETTENMOORS NS
rooms[1][1] = DOOR_SOUTH | DOOR_NORTH;

//RIVENDELL WE
rooms[1][2] = DOOR_WEST | DOOR_EAST | Elves | FRIENDLY | Elven_Harp;

//MIRKWOOD WS
rooms[1][3] = DOOR_SOUTH | DOOR_WEST | Elves | CAUTION;

//EREBOR SNW
rooms[1][4] = DOOR_SOUTH | DOOR_NORTH | DOOR_WEST | Dwarves | FRIENDLY | Third_Shard_of_Narsil;

//HARLINDON NE
rooms[2][0] = DOOR_NORTH | DOOR_EAST | Halfling | FRIENDLY;

//SHIRE NSEW
rooms[2][1] = DOOR_SOUTH | DOOR_EAST |DOOR_NORTH | DOOR_WEST | Old_Boot | A_Pint_From_The_Green_Dragon | Salted_Pork | Halfling | FRIENDLY;

//LORIEN EW
rooms[2][2] = DOOR_WEST | DOOR_EAST | DOOR_NORTH | Elves | FRIENDLY;

//DEAD MARSHES SE
rooms[2][3] = DOOR_SOUTH | DOOR_EAST | Troll | CAUTION;

//BLACK GATE SW
rooms[2][4] = DOOR_SOUTH | DOOR_WEST | DOOR_NORTH | Orc_Legion | CAUTION;

//LOND DAER S
rooms[3][0] = DOOR_SOUTH | Halfling | Elves | FRIENDLY | Fourth_Shard_of_Narsil;

//ISENGARD NSEW
rooms[3][1] = DOOR_SOUTH | DOOR_EAST | DOOR_NORTH | DOOR_WEST | Palantir;

//FANGORN EW
rooms[3][2] = DOOR_WEST | DOOR_EAST | Warg | CAUTION;

//MINAS TIRITH NWSE
rooms[3][3] = DOOR_SOUTH | DOOR_EAST | DOOR_WEST | DOOR_NORTH | Narya | Old_Boot;

//DEAD MARSHES SW
rooms[3][4] = DOOR_SOUTH | DOOR_WEST ;

//HELMS DEEP EN
rooms[4][0] = DOOR_NORTH | DOOR_EAST | Troll | CAUTION;

//ROHAN WESTFOLD NEW
rooms[4][1] = DOOR_WEST | DOOR_EAST | DOOR_NORTH | Warg | CAUTION;

//ROHAN EASTFOLD NEW
rooms[4][2] = DOOR_NORTH | DOOR_EAST | DOOR_WEST;

//DAGORLAD WE
rooms[4][3] = DOOR_WEST | DOOR_EAST ;

//MINAS MORGUL NW
rooms[4][4] = DOOR_NORTH | DOOR_WEST | Orc_Legion | DEADLY;

}


void DescribeTheShire00_00() {
	cout << "    You see the Green dragon, a tavern in the Shire....An area settled almost exclusively by hobbits and largely removed from the goings-on in the rest of Middle-earth. " << endl;
	cout << "    Peaceful and domestic this place is very boring. However rumors of their ale are of the highest praise. Most of the tavern is made from Oak with beautiful inlays" << endl;
	cout << "    Its almost as if not much ever changes here. " << endl;
}
void DescribeWeatherTop00_01() {
	cout << "    You see a large Hill with the ruins of an old fortress of men atop, Amon Sul is a hill in Eriador, a region of Middle-earth. It is the southernmost and highest summit " << endl;
    cout << "    of the Weather Hills. It once belonged to the proud kingdom of Arthedain before it fell before the witch king of Angmar." << endl;
	cout << "    This place feels old and forgotten and looks like years of forgotten majesty." << endl;
}
void DescribeMistyMountains00_02() {
	cout << "    Before you lie the Misty Mountains a massive mountain range, and one of the most important features of Middle-earths geography." << endl;
	cout << "    Its high peak shape the weather and provide natural barrier from the evil in the south east. There is not much here but cold, ice, and howling winds." << endl;
	cout << "    There are some nooks in the stone of the bare cliff faces..." << endl;
	
}
void DescribeRivendell00_03() {
	cout << "    Before you lies the trasure of the mountains - Rivendell. A hidden valley and fortress of the elves as well as the home of Lord Elrond and his family until his wife left for valinor." << endl;
	cout << "    Beautiful and peaceful Elrond always welcomes his allies. Harp music plays from within and the waterfalls rush in the back ground while sun shines through a partly clouded sky." << endl;
	
}
void DescribeLorien00_04() {
	cout << "    Lorien lies in front of you. Trees of monstrous size in every direction you look, it is largely considered the fairest realm of Elves within middle earth, it is the home of Galadriel and Celeborn… " << endl;
	cout << "    these people have a weird thing for bread, something called lambas yet I am sure these people have never had carbs before, they are also probably vegan." << endl;
	
}
void DescribeIsengard00_05() {
	cout << "    Walls, trees inside, giant dark ominous tower called Orthanc nothing bad could possibly happen here it is inhabited by a crazy old man afterall." << endl;
	cout << "    pretty sure we all have a neighbor like this." << endl;
	
}
void DescribeErebor00_06() {
	cout << "    A recently reclaimed Dwarven kingdom it has enriched the lands of the north" << endl;
	cout << "    east and the surrounding areas such as Dale" << endl;
}
void DescribeIronHills00_07() {
	cout << "    You see before you the land of the Iron Hills. Gror son of Dain I founded the Iron "<< endl;
    cout << "    Hills as an independent lordship after the Dwarves were exiled" << endl; 
	cout << "    from the Grey Mountains to the west because of attacks by Cold-drakes seeking the vast wealth of the mountains, " << endl;
	cout << "    which had resulted in the death of the king Dain I. The exiles who settled in the Iron Hills were of " << endl; 
	cout << "    course in friendly relations with the Dwarves of Erebor. Dain II is said to have aided in the " << endl; 
	cout << "    legendary battle of the Five Armies." << endl;
	
}
void DescribeFornost00_08() {
	cout << "    The ruined Capital city of Arthedain. It was located at the south end of the North Downs, about 100 miles north of Bree. " << endl;
    cout << "    After Fornost was abandoned, the site became known as Deadmens Dike, visited only by Rangers and fools. " << endl;
    cout << "    It is not but a sad reminder of what the men of the north could have been and a hiding place for burglars." << endl;
	
}
void DescribeAngmar00_09() {
	cout << "    Before you lies the city of darkness....The Chief Fortress of Angmar and main lair of the Witch King during the wars with Arthedain. " << endl;
	cout << "    The location where the Witch King was defeated and the Dunedain were ended. Mostly ruins but could contains valuables." << endl;
	
}
void DescribeEttenmoors00_10() {
	cout << "    In front of you lies great pleateaus...The Ettenmoors are highlands west of the Misty Mountains and north of the Coldfells." << endl; 
	cout << "    It was a location of warfare between the Free Peoples and Angmar in the Third Age when the Witch-king fled after losing the battle of Fornost." << endl;

}
void DescribeMountGundabad00_11() {
	cout << "    Mount Gundabad rises likes rotten teeth before you, a mountain in the northernmost section of the Misty Mountains, " << endl;
	cout << "    close to the western extremity of the Grey Mountains. It was originally a stronghold of Dwarves, but since has been overrun by orcs  " << endl;
	cout << "    and is extremely dangerous." << endl;

}
void DescribeMinasTirith00_12() {
	cout << "    The heavily fortified capital of Gondor lies ahead. It was originally built to guard the former capital, Osgiliath, from attack from the west, " << endl;
	cout << "    but became the capital when Osgiliath fell into ruin following the Kin-strife and the Great Plague. It is often referred to as the White " << endl;
	cout << "    City for the pale stone used to construct it." << endl;

}
void DescribeForestFangorn00_13() {
	cout << "    One of the oldest forest in Middle Earth, a place that smells like years gone by, wisdom, and well moss. There is lots of moss and trees." << endl;
	cout << "    There seems to be something almost alive about the place...." << endl;
}
void DescribeLondDaer00_14() {
	cout << "    You can see the old ruins of Lond Daer Enedh, the first permanent settlement of the Numenoreans in Middle-earth. It was located on the coast of Enedwaith, " << endl;
	cout << "    on the southern banks of the estuary of the Gwathlo; this river provided access to the great region of Eregion in the hinterland to the north. " << endl;
	cout << "    This land fell into ruin after the fall of Arnor and the Numenoreans" << endl;

}
void DescribeGreyHavens00_15() {
	cout << "    Mithlond or the Grey Havens stood near the mouth of the River Lhun at the gulfs eastern end. " << endl;
	cout << "    It is a place of great beauty the largest elven harbor and considered the portal to Arda to which few are granted passage outside elves. " << endl;
	cout << "    The air itself tastes of good bye and melancholy as well as sea salt." << endl;
}
void DescribeMirkwood00_16() {
	cout << "    This place was originally known as Green Wood the Great after falling under the influence of a necromancer it because known as Mirkwood. " << endl;
	cout << "    The forest even now retains shadows and the feeling of an internal conflict as though corrupted even after the passing of the necromancer." << endl;

}
void DescribeBlackGate00_17() {
	cout << "    The black gate is a great stone rampart built across Cirith Gorgor, the pass into Mordor between the ends of the Mountains of " << endl;
	cout << "    Shadow and the Ash Mountains. It is vast and imposing and feels of a deep evil orcs are seen here often." << endl;
	cout << "    It is said to be so heavy it takes four mountain trolls to open..." << endl;
}
void DescribeHelmsDeep00_18() {
	cout << "    A phrase often used to refer to the fortress of rohan and its surrounding fortifications. Supposedly it " << endl;
	cout << "    contains immeasurable halls, filled with everlasting music of water that tinkles into pools that " << endl;
	cout << "    stretch far back into the surrounding mountainous hillside. It has immense walls and towers." << endl;

}
void DescribeDagorlad00_19() {
	cout << "    A great, treeless, open plain between the Emyn Muil and Cirith Gorgor -Dagorlad- the north-west entrance to Mordor lies before you. " << endl;
	cout << "    The name means the Battle Plain in Sindarin, and refers to the Battle of Dagorlad fought there between the forces of Sauron " << endl;
	cout << "    and the Last Alliance of Elves and Men at the end of the Second Age. " << endl;
	cout << "    The bodies of the dead decayed as normal, but over time part of the field became a wetland, the Dead Marshes, where the" << endl;
	cout << "    images of the fallen could be seen. Many a man have fallen to visions and all manner of hallucinations." << endl;

}
void DescribeRohanWesfold00_20() {
	cout << "    One of the poverty stricken lands of Rohan, possibly a good target for the enemy as it is mainly scattered villages " << endl;
	cout << "    and hamlets with little to no defenses on hand. It lies to the West of the Folde and Rohans capital Edoras." << endl;

}
void DescribeRohanEastfold00_21() {
	cout << "    One of the poverty stricken lands of Rohan, lies to the east of Rohans capital Edoras. " << endl;
	cout << "    These lands extend along the White Mountains and share a border with Gondor." << endl;
}
void DescribeHarlindon00_22() {
	cout << "    Harlindon used to be a primarily Elvish land until several battles with sauron that resulted in many of " << endl;
	cout << "    these elves departing into the West, which left these lands primarily unoccupied but many ruins abandoned filled with secrets." << endl;

}
void DescribeDeadMarshes00_23() {
	cout << "    Part of Dagorlad that devolved into thick stinking marshes that engulfed the dead that had lain upon that ancient battlefield. " << endl;
	cout << "    Considered to be a haunted and cursed place it is overlooked by Mordor which seems to press in on the poor souls of those who find themselves here." << endl;

}
void DescribeMinasMorgul00_24() {
	cout << "    Originally known by its earlier name of Minas Ithil, the city used to be the mirror of Minas tirith and acted as the " << endl;
	cout << "    second of two fortresses defending Osgiliath. Something of evil origin, a plague of sorts, descended upon the inhabitants " << endl;
	cout << "    decimating the population afterwards the Gondor continued to hold the city until the Nazgul returning to mordor took the " << endl;
	cout << "    city and it remained forever a haunting mirror of the dread that continues to torment the people of Gondor." << endl;

}

//Take method
int TakeItem(unsigned int rooms[][5], int row, int col, string Object)
{
	//Shards of Narsil
	if(Object == "FIRST_SHARD_OF_NARSIL" && (rooms[row][col] & First_Shard_of_Narsil))
	{
		rooms[row][col]^=First_Shard_of_Narsil;
		return First_Shard_of_Narsil;
	}
	if(Object == "SECOND_SHARD_OF_NARSIL" && (rooms[row][col] & Second_Shard_of_Narsil))
	{
		rooms[row][col]^=Second_Shard_of_Narsil;
		return Second_Shard_of_Narsil;
	}
	if(Object == "THIRD_SHARD_OF_NARSIL" && (rooms[row][col] & Third_Shard_of_Narsil))
	{
		rooms[row][col]^=Third_Shard_of_Narsil;
		return Third_Shard_of_Narsil;
	}
	if(Object == "FOURTH_SHARD_OF_NARSIL" && (rooms[row][col] & Fourth_Shard_of_Narsil))
	{
		rooms[row][col]^=Fourth_Shard_of_Narsil;
		return Fourth_Shard_of_Narsil;
	}

	//Take Methods for everything else...
	if(Object == "SWORD" && (rooms[row][col] & Sword))
	{
		rooms[row][col]^=Sword;
		return Sword;
	}
	if(Object == "SHIELD" && (rooms[row][col] & Shield))
	{
		rooms[row][col]^=Shield;
		return Shield;
	}
	if(Object == "PALANTIR" && (rooms[row][col] & Palantir))
	{
		rooms[row][col]^=Palantir;
		return Palantir;
	}
	if(Object == "A_PINT_FROM_THE_GREEN_DRAGON" && (rooms[row][col] & A_Pint_From_The_Green_Dragon))
	{
		rooms[row][col]^=A_Pint_From_The_Green_Dragon;
		return A_Pint_From_The_Green_Dragon;
	}
	if(Object == "ELVEN_HARP" && (rooms[row][col] & Elven_Harp))
	{
		rooms[row][col]^=Elven_Harp;
		return Elven_Harp;
	}
	if(Object == "NARYA" && (rooms[row][col] & Narya))
	{
		rooms[row][col]^=Narya;
		return Narya;
	}
	if(Object == "SALTED_PORK" && (rooms[row][col] & Salted_Pork))
	{
		rooms[row][col]^=Salted_Pork;
		return Salted_Pork;
	}
	if(Object == "OLD_BOOT" && (rooms[row][col] & Old_Boot))
	{
		rooms[row][col]^=Old_Boot;
		return Old_Boot;
	}

	//return 0 if did not find anything
	return 0;

}
