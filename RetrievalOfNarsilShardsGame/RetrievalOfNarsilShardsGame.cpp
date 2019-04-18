//===========================================================================================
// RetrievalOfNarsilShardsGame.cpp : Defines the entry point for the console application.
// An adventure game based on The Lord of the Rings by JRR Tolkien.
// Author: Wesley Adams
// This program is entirely my own work
//===========================================================================================


#include <iostream>
#include <string>
using namespace std;


int main()
{
	string mystring;

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
	cin >> mystring;
}

