// подключаем библиотеку работы с SD картой
#include <SD.h>
#define SD_ChipSelectPin 10

// подключаем TMRpcm библиотеку для работы с wav файлами
#include <TMRpcm.h>
TMRpcm tmrpcm;

// вкл и выкл - красная подсветка
void RedLed(int state);
// вкл и выкл - синяя подсветка
void BlueLed(int state);
// возвращает CO2 уровень в ppm
int getCO2Level();
// возвращает уровень освещенности (0-темно 1024-очень ярко)
int getLightLevel();

// Кнопка 1 состояние, нормально = 0 - выкл
int button1State = 0;
// Кнопка 2 состояние, нормально = 0 - выкл
int button2State = 0;
// Кнопка 3 состояние, нормально = 0 - выкл
int button3State = 0;

// храним время для уведомлений
unsigned long currentMillis, previousMillis;

// интервал опроса датчиков
unsigned long interval = 1000;

// счетчик секунд 50мин (3000 секунд)
unsigned long timer = 0;
// предел счетчика секунд  = 3000 секунд
#define TIMER_LIMIT 3000

// код асинхронных прерываний
// код обработки кнопки 1
void Button1Press()
{
  if (button1State == 0)
	   button1State = 1;
  else
  {
	  tmrpcm.stopPlayback();
	  button1State == 0;
  }	  
}
// код обработки кнопки 2
void Button2Press()
{
  if (button2State == 0)
	   button2State = 1;
  else
  {
	  tmrpcm.stopPlayback();
	  button2State == 0;
  }	  
}
// код обработки кнопки 3
void Button3Press()
{
  if (button3State == 0)
	   button3State = 1;
  else
  {
	  tmrpcm.stopPlayback();
	  button3State == 0;
  }	  
}

void setup()
{
	// настройки пинов кнопок
	pinMode(3, INPUT);
	pinMode(4, INPUT);
	pinMode(5, INPUT);
	
	// установить пин динамика для вывода звука
	tmrpcm.speakerpin = 9;
	
	// инициализировать SD карту, если все хорошо то продолжить, иначе все.
	if (!SD.begin(SD_ChipSelectPin))
	{
		return;
	}
	
	// проиграть звук я включился ))
	//tmrpcm.volume(1);
	tmrpcm.play("alive.wav");
	
	// выключить все светодиоды - сидим не отсвечиваем)
	RedLed(0);
	BlueLed(0);
	
	// назначаем функции прерываний 	
	attachInterrupt(0, Button1Press, FALLING);
}

void loop()
{
	// работать только с интервалом interval
	currentMillis = millis();
	if(currentMillis - previousMillis > interval) {
		previousMillis = currentMillis;
	
		// если света не достаточно, то включить красную подсветку
		if (getLightLevel() < 512) // магическое число, подобранное вручную в ходе опытов.
			// включить
			RedLed(1);
		else
			// выключить 
			RedLed(0);
		
		// интервал ppm для нормальной работы - выход за пределы = все плохо 
		if ((getCO2Level() < 1100) && (getCO2Level() > 300)) 
			// выключить
			BlueLed(0);
		else
			// включить
			BlueLed(1);
		
		if (timer == TIMER_LIMIT)
			// уведомить что время пришло ...
			tmrpcm.play("alert.wav");
			while (1)
			{
				// ожидание нажатия на кнопку 1
				if (button1State == 1)
				{
					// проиграть файл зарядки
					tmrpcm.play("zaryadka1.wav");
					break;
				}					
				// ожидание нажатия на кнопку 2
				if (button2State == 1)
				{
					// проиграть файл зарядки
					tmrpcm.play("zaryadka2.wav");
					break;
				}	
				// ожидание нажатия на кнопку 3
				if (button3State == 1)
				{
					// проиграть файл зарядки
					tmrpcm.play("zaryadka3.wav");
					break;
				}					
			}
			timer = 0;
		else
			timer++;
	}
}
