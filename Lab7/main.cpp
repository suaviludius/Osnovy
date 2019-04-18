#include <stdio.h>
#include <locale.h>

int main()
{
	long z; // исходное число
	unsigned long y; // беззнаковая версия исходного числа
	unsigned long mask = 0b0; // маска
	int schet=0; //переменная для подсчета битов
	int n = 0; // количество единиц

	setlocale(LC_ALL, "Rus");
	printf("Введите число z: ");
	scanf_s("%x", &z); // ввод в шестнадцатиричном формате

	y = (unsigned int)z;
	unsigned long m = y; 

	while (m != 0)
	{
		m=m & (~(1 << n));
		n++;
		schet++;
	}

	//printf("%d\n", schet);
	n = 0;


	while (y!=0)
	{
		/*0b01001011 - количество единичных битов 4
			считаем:
		    0b01001011 & (0b01001011 - 1) = 0b01001010
			0b01001010 & (0b01001010 - 1) = 0b01001000
			0b01001000 & (0b01001000 - 1) = 0b01000000
			0b01000000 & (0b01000000 - 1) = 0b00000000
		*/
		y= y & (y-1);
		mask=(mask | (1 << (schet-1-n)));
		n++;
		//printf(" %d ", n);
		//printf("%x\n", mask);
	}
	
	z = mask;
	printf("Результат: %x\n", z );
	return 0;
}
