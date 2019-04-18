/*******************************************************************
	*   CS 121 Programming Assignment 4:5
	*   File: Retrieval Of Narsil Shards Game
	*   Author: Wesley Adams
	*   Desc: An adventure Game in which you play as the an hero in middle earth attempting to find the stolen shards 
	*         of narsil and return them to rivendell.
	*   Date: 03/10/2019
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/


#include <iostream>
#include <string>
using namespace std;

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
	cout << "    middle earth. When you find an item pick it up with a command like TAKE SHARD. Some " << endl;
	cout << "    locations are held by threatening creatures like orc legions, or dragons. Since you are one man " << endl;
	cout << "    you cannot hope to win so you must run." << endl;
	cout << "" << endl;
	cout <<"     Press the enter key to begin.\n"<<endl;
	getc(stdin);

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
		//microsoftGate4me@gmail32

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
			cout << "Command Verb is GO" << endl;
			if(cmdObj == "NORTH")
			{
				cout << "Direction is NORTH" << endl;
				if(iRow>0)
				{
					iRow--;//Move up a row
				}
			}
			else if (cmdObj == "SOUTH")
			{
				cout << "Direction is SOUTH" << endl;
				if(iRow<iNumRows-1)
				{
					iRow++;//Move down a row
				}
			}
			else if (cmdObj == "EAST")
			{
				cout << "Direction is EAST" << endl;
				if(iCol<iNumCols-1)
				{
					iCol++;//Move right a column
				}
			}
			else if (cmdObj == "WEST")
			{
				cout << "Direction is WEST" << endl;
				if(iCol>0)
				{
					iCol--;//Move left a column
				}
			}
			else
			{
				//if unknown command
				cout << "I dont understand GO" << cmdObj << endl;
			}	
		}
		else if(cmdVerb == "TAKE")
		{
			//to take an item
			cout << "Command Verb is TAKE" << endl;
			cout << "I havent learned how to TAKE"<< cmdObj << endl;
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
		cout << "The Command is: " << cmdVerb << " " << cmdObj << endl;
		cout << "The Location is: Row " << iRow << ", Col " << iCol << endl;
	}//End Game Loop

	cin>>mystring;
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
	cout << "    Before you lie the Misty Mountains a massive mountain range, and one of the most important features of Middle-earth's geography." << endl;
	cout << "    Its high peak shape the weather and provide natural barrier from the evil in the south east. There is not much here but cold, ice, and howling winds." << endl;
	cout << "    There are some nooks in the stone of the bare cliff faces..." << endl;
	
}
void DescribeRivendell00_03() {
	cout << "    Before you lies the trasure of the mountains - Rivendell. A hidden valley and fortress of the elves as well as the home of Lord Elrond and his family until his wife left for valinor." << endl;
	cout << "    Beautiful and peaceful Elrond always welcomes his allies. Harp music plays from within and the waterfalls rush in the back ground while sun shines through a partly clouded sky." << endl;
	
}
void DescribeLorien00_04() {
	cout << "    Lorien lies in front of you. Trees of monstrous size in every direction you look, it is largely considered the fairest realm of Elves within middle earth, it is the home of Galadriel and Celeborn… " << endl;
	cout << "    these people have a weird thing for bread, something called lambas yet I’m sure these people have never had carbs before, they’re also probably vegan." << endl;
	
}
void DescribeIsengard00_05() {
	cout << "    Walls, trees inside, giant dark ominous tower called Orthanc nothing bad could possibly happen here it's inhabited by a crazy old man afterall." << endl;
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
    cout << "    After Fornost was abandoned, the site became known as Deadmen's Dike, visited only by Rangers and fools. " << endl;
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
	cout << "    Mithlond or the Grey Havens stood near the mouth of the River Lhûn at the gulf's eastern end. " << endl;
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
	cout << "    and hamlets with little to no defenses on hand. It lies to the West of the Folde and Rohan's capital Edoras." << endl;

}
void DescribeRohanEastfold00_21() {
	cout << "    One of the poverty stricken lands of Rohan, lies to the east of Rohan's capital Edoras. " << endl;
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
