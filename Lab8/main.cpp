#include <stdio.h> 
// определение символических констант
#define YES 1 
#define NO 0
#define MAXLINE 1000
void process_line(char buffer[]);
int main(void)
{
	char line[MAXLINE];
	gets_s(line);
	process_line(line);
	puts(line);
	return 0;
}

void process_line(char buffer[])
{
	char c; // текущий символ
	int flag = NO; // признак слова
	int found = NO; // определение слова
	int cnt = 0; //счетчик для определения полиндрома
	int t = 1; // счетчик для приближения середины слова

	char *j = buffer; // позиция начала слова
	char *in_ptr; // (i) - позиция текущего символа
	char *out_ptr; // (pos) - позиция символа выхода
	char *word_ptr; // (start) - позиция начала слова

	in_ptr = buffer; // текущий символ входа
	out_ptr = buffer; // текущий символ выхода ...
	word_ptr = buffer; //начало слова ...

	
	// цикл чтения символов из строки
	do
	{
		c = *in_ptr; // взять текущий символ из буфера
 
		if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != ' ' && c != '.' && c != ',' && c != '\n' && c != '\0' && c != '\t')) // проверка на не слово
		{
			found = YES;
		}

		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0')
		{
			// найден разделитель
			if (flag == YES)
			{
				// это первый разделить после слова
				// проверить, обнаружен ли в слове 
				// искомый признак

				for (j = word_ptr; j <(in_ptr - (in_ptr - word_ptr + 1) / 2);j++)
				{
					int c1 = *j;
					int c2 = *(in_ptr-t);

					if ((c1 - 'A' == c2 - 'A' || c1 - 'a' == c2 - 'a' || c1 - 'a' == c2 - 'A' || c1 - 'A' == c2 - 'a') && (found != YES))  // проверка на условие
						cnt++;

					t++; //число приближающее к середине слова
				}
				
				if (cnt != ((in_ptr - word_ptr) / 2) || cnt == 0)
				{
					// слово не подлежит удалению
					// оно копируется в результирующую 
					// строку

					for (j = word_ptr; j < in_ptr; j++)
						*out_ptr++ = *word_ptr++;

				}


			}
			flag = NO;
			found = NO;
			if (cnt != ((in_ptr - word_ptr) / 2) || cnt == 0)
				*out_ptr++ = c; //пробелы для "не пaлиндромов"
			else *out_ptr = c;

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
}
