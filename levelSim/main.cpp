#include "appwrapper.h"

//v1.0 
	//added Skill, Player, and Classes
	//pickSkillsRandomly() implemented fully

//v1.1
	//added mt19937 capability
	//overrode levelUp() for every class
	//added randomASI() and weightedASI()

//v1.2
	//added getInitiative()
	//added ToolNode
	//added backgrounds


//v2.0
	//had a manic episode
		//forgot patch notes (I'm doing this retroactively)
		//declared the concept of Classes as their own classes to be defunct
			//made class a quality of player
		//
//stuff to add:
	//races (make a class that inherits from player?)
		// okay so crazy idea: player includes a pointer to a Race (make a class for that) object that's stored on the heap, the pointer actually points to a class that inherits Race
		// okay so less crazy idea: instead of making classes for races, we just have functions for each of them that we run in constructor, maybe with an enumerated type for it
	//custom class stuff
	//consider languages (store in race class? store on heap?)

//v2.1 (June 10th, 2022)
	//fixed everything(?) that I broke in 2.0's manic episode
	//decided to add dates to patch notes from here forward

//v2.2 (???)
	//Added simple GUI
	//Added some output mechanisms

//v2.3 (August 5th, 2022)
	//Added Save DCs




int main()
{
	std::mt19937 rng(time(NULL));
	srand((unsigned int)time(NULL));

	Appwrapper tester;

	tester.runApp();

	/*tester.addPlayer(className::wizard);
	tester.addPlayer(className::wizard);
	std::cout << "average athletics: "<<tester.getAverageMod(skillName::athletics) << std::endl;
	std::cout << "average health: " << tester.getAverageHealth() << std::endl;*/
	

	
}