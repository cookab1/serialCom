		
/*
 * delay_usec.s
 *
 * Created: 1/25/2018 2:53:16 PM
 *  Author: cookab1
 */ 

		.text
		.global add2
		.global delay_usec
		.global delay
add2:
		add r24, r22
		adc r25, r23
		ret

delay_usec:
		nop
		nop
		dec r24
		brge L2
L1:		dec r24
		call L2
		nop
		nop
		nop
		nop
		brge	L1	
L2:  	ret