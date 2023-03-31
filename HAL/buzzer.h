/*
 * buzzer.h
 *
 *  Created on: Oct 30, 2022
 *      Author: tarek
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#define BUZZER_PORT       PORTB_ID
#define BUZZER_PIN        PIN0_ID


void Buzzer_init(void);



void Buzzer_on(void);



void Buzzer_off(void);


#endif /* BUZZER_H_ */
