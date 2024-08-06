/*
 * mainpp.cpp
 *
 *  Created on: Jul 16, 2024
 *      Author: yujungHuang
 */

#include "mainpp.h"
#include "localization.h"
#include "navigation.h"
#include "timer.h"

float spd=0;
float omega=0;
float theta=0;
float x_distance=0;
float y_distance=0;
int lineInfo[5]={0};
int index=0;
int if_mission=0;
/*mission points:
	get_1st_ball=2,
	get_2nd_ball=3,
	get_3rd_ball=4,
	get_4th_ball=5,
	get_5th_ball=6,
	get_6th_ball=10,
	get_7th_ball=11,
	get_8th_ball=12,
	first_mission_complete=18,
	put_ball_to_archway=20,
	put_ball_1=27,
	put_ball_2=32
*/
float missions[]={
		//unit of distance: cm, unit of theta: rad
		//first mission
		100/*get left balls*/, pi/2/*turn right*/    , 10/*first ball*/     ,
		10/*second ball*/    , 10/*third ball*/      , 10/*fourth ball*/    ,
		10/*fifth ball*/     , pi/2/*turn right*/    , 200/*get right ball*/,
		pi/2/*turn right*/   , 15/*first ball*/      , 15/*second ball*/    ,
		15/*third ball*/     , pi/*turn back*/       , 45/*go back*/        ,
		pi/2/*turn left*/    , 150/*leave mission 1*/, pi/2/*turn right*/   ,
		//third mission
		300/*go straight*/   , pi/2/*turn left*/     , 200/*through the archway*/,
		200/*go to reset C*/ ,
		//fifth mission
		pi/2/*turn left*/    , 50/*go straight*/     , pi/2/*turn left*/    ,
		50/*put ball*/       , 50/*go to corner 1*/  , pi/2/*turn right*/   ,
		50/*go straight*/    , pi/2/*turn right*/    , 50/*put ball*/       ,
		50/*go to corner 2*/ , pi/2/*turn left*/     , 100/*go to reset D*/ ,
		//sixth mission
		pi/2/*turn left*/    , 100/*go straight*/,
		//missions complete
		2048
};

void main_function(){
	setup();
	while(1){
	}
}
