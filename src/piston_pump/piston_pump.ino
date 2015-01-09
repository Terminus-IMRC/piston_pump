#define INTERVAL 100
#define SPIN 7
#define LEDPIN 13

void setup()
{
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(SPIN, INPUT_PULLUP);
	pinMode(LEDPIN, OUTPUT);

	digitalWrite(8, LOW);
	digitalWrite(9, LOW);
	digitalWrite(10, LOW);
	digitalWrite(11, LOW);

	return;
}

void write_high_gradually(int a, int b)
{
	/* now 'a' should be pulled up */

	digitalWrite(b, HIGH);
	delay(INTERVAL/2);

	digitalWrite(a, LOW);
	delay(INTERVAL/2);
}

void loop()
{
	int state=digitalRead(SPIN);

	if(state==HIGH){
		digitalWrite(LEDPIN, HIGH);
		write_high_gradually(8, 9);
		write_high_gradually(9, 10);
		write_high_gradually(10, 11);
		write_high_gradually(11, 8);
	}else{
		digitalWrite(LEDPIN, LOW);
		digitalWrite(11,LOW);
		digitalWrite(8, HIGH);
		delay(INTERVAL);
		digitalWrite(8,LOW);
		digitalWrite(9, HIGH);
		delay(INTERVAL);
		digitalWrite(9,LOW);
		digitalWrite(10, HIGH);
		delay(INTERVAL);
		digitalWrite(10,LOW);
		digitalWrite(11, HIGH);
		delay(INTERVAL);
	}
}
