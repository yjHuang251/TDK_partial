/*
 * localization.h
 *
 *  Created on: Jul 16, 2024
 *      Author: yujungHuang
 */

#ifndef INC_LOCALIZATION_H_
#define INC_LOCALIZATION_H_


typedef class localize{
public:
	void Initialize();

	float delta_x_update(float,float);
	float delta_y_update(float,float);
	float thetaUpdate(float);

	void getLineData();
	//int locLineAssisting(int);

	int hitWall_Near();
	int hitWall_CLP();

	int line[5]={0};
private:
	float delta_x=0;
	float delta_y=0;
	float theta=0;
	float last_theta=0;
	float last_spd=0;
	float last_omega=0;
}localize;



#endif /* INC_LOCALIZATION_H_ */
