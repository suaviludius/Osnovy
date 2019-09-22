#include <stdio.h> 
#include <locale.h>
// определение символических констант
#define YES 1 
#define NO 0
#define MAXLINE 1000

int main(void)
{
	setlocale(LC_ALL,"Russian");
	printf(" _   _   _  _ _ _ _  _  _   _  _  _\n"); printf("| | /-\\ / \\ |/| |-| /| |-\' | | |\\/|\n\n");

	char buffer[MAXLINE];
	gets_s(buffer);

	char c; // текущий символ
	int flag = NO; // признак слова
	int found = NO; // определение слова (NO значит слово)
	int cnt = 0; //счетчик для определения полиндрома
	int t = 1; // счетчик для приближения середины слова

	char *j = buffer; // позиция начала слова для изменения
	char *in_ptr = buffer; // (i) - позиция текущего символа
	char *out_ptr = buffer; // (pos) - позиция символа выхода
	char *word_ptr = buffer; // (start) - позиция начала слова

	
	// цикл чтения символов из строки
	do
	{
		c = *in_ptr; // взять текущий символ из буфера
 
		if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != ' ' && c != '.' && c != ',' && c != '\n' && c != '\0' && c != '\t' && c != ')' && c != '(' && c != ':' && c != ';' && c != '!' && c != '?')) // проверка на не слово
		{
			found = YES;
		}

		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '\t' || c == ')' || c == '(' || c == ':' || c == ';' || c == '!' || c == '?') // найден разделитель
		{
			if (flag == YES) // это первый разделить после слова
			{
				// проверить, обнаружен ли в слове 
				// искомый признак

				for (j = word_ptr; j <(in_ptr - (in_ptr - word_ptr + 1) / 2);j++)
				{
					int c1 = *j; //начало слова
					int c2 = *(in_ptr-t); //середина слова

					if ((c1 - 'A' == c2 - 'A' || c1 - 'a' == c2 - 'a' || c1 - 'a' == c2 - 'A' || c1 - 'A' == c2 - 'a') && (found != YES))  // проверка на условие
						cnt++;

					t++; //число приближающее к середине слова
				}
				
				if (cnt != ((in_ptr - word_ptr) / 2) || (cnt == 0 && found == YES))
				{
					// слово не подлежит удалению, оно копируется в результирующую строку

					for (j = word_ptr; j < in_ptr; j++)
					{
						*out_ptr++ = *j; 
					}

				}


			}

			//if (cnt != ((in_ptr - word_ptr) / 2) || (cnt == 0 && found == YES))
			//{  
			//	*out_ptr++ = c; //пробелы для "не пaлиндромов"
			//}
			//else  
				*out_ptr++ = c;

			found = NO;
			flag = NO;

		}
		else
		{
			if (flag == NO) // найдена буква
				word_ptr = in_ptr; // запомнить позицию начала слова
			flag = YES; //признак слова
			cnt = 0; //сброс счетчика
			t = 1; // сброс счетчика
		}

		in_ptr++; //переход к следующей ячейке буфера

	} while (c != '\0');

	puts(buffer);
	return 0;
}
