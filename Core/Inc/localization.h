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
	float linearDistance(float);
	float angularDistance(float);
	int lineAssisting();
	void thetaUpdate();
private:
	float theta=0;
	float linear_displacement=0;
	float angular_displacement=0;
	float last_spd=0;
	float last_omega=0;
	int line=0;
}localize;



#endif /* INC_LOCALIZATION_H_ */
