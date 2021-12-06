// C++ code
//
int contador = 4;
const int porcentajeTotal = 100;
const int valorAnalogTotal = 255;
int valorAnalogReq;


void setup()
{
  //entradas
  pinMode(4,INPUT);
  pinMode(7,INPUT);
  //salidas
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop()
{
  int pulsadorUno = digitalRead(4);
  int pulsadorDos = digitalRead(7);
  
  	if (pulsadorUno == HIGH)
    {
    	contador +=1;
    }
    if (pulsadorDos == HIGH)
    {
    	contador -=1;
    }
  delay(100);
  switch (contador)
  {
  	case 0:
    	Vizquierda(100);
    break;
    case 1:
    	Vizquierda(75);
    break;
    case 2:
    	Vizquierda(50);
    break;
    case 3:
    	Vizquierda(25);
    break;
    case 4:
    	paro();
    break;
    case 5:
    	Vderecha(25);
    break;
    case 6:
    	Vderecha(50);
    break;
    case 7:
    	Vderecha(75);
    break;
    case 8:
    	Vderecha(100);
    break;
    default:
    	if (contador > 8)
        {
        	contador = 8;
        }
    	if (contador < 0)
        {
        	contador = 0;
        }
    break;
  }
  delay(100);
  
}

void paro()
{
	digitalWrite(9,LOW);
  	digitalWrite(10,LOW);
}

void Vderecha(int porcentaje)
{
	digitalWrite(9,LOW);
  	valorAnalogReq = valorAnalogWrite(porcentaje);
  	analogWrite(10,valorAnalogReq);
}

void Vizquierda (int porcentaje)
{
	digitalWrite(10,LOW);
  	valorAnalogReq = valorAnalogWrite(porcentaje);
    analogWrite(9,valorAnalogReq);
  	
}

int valorAnalogWrite(int porcentaje)
{
	// 100 -> 255
    //  %  -> aw
   int aw = (porcentaje*valorAnalogTotal)/porcentajeTotal;
   return aw;
}