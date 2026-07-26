volatile unsigned int* gpio = (unsigned int*)0x20200000;

void main(void){

	gpio[4] &= ~(7 << 21);
	gpio[4] |= (1 << 21);
	
	gpio[11] = (1 << 15);

	while (1) {
		
	}
}

