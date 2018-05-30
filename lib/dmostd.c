void delay(int x){
	int unit = ROM_SysCtlClockGet()/3/1000;
	ROM_SysCtlDelay(unit * x);
}

