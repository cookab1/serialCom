		
/*
 * delay_usec.s
 *
 * Created: 1/25/2018 2:53:16 PM
 *  Author: cookab1
 */ 

		.text
		.global delay_usec

delay_usec:
		dec r24		// 1 cycle
		brlt L3		// 0 ? 1 : 2 maybe L1
		//nop			// 1
		//nop			// 1
		rcall L2	// 4 cycles
		//brge L1		// 0 ? 1 : 2 useless
L1:		breq L2		// 0 ? 1 : 2
		dec r24		// 1 cycle
		rcall L2	// 4 cycles
		nop			// 1
		nop			// 1
		nop			// 1
		nop			// 1
		brge	L1	// 0 ? 1 : 2 
L2:  	ret			// 5 cycles
L3:		mov	r24, $65536 // 1
		brge L1:

// for 0 -- 
// for 1 -- 1111/1111/1111/111
// for 2 -- 