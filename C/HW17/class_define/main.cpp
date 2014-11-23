#include "main.h"

int main() {
    char filename[] = "sample";
    FILE *p_orig = fopen(filename, "r"); //открываем исходный файл на чтение
    FILE *p_edit = fopen(strcat(filename, "_edit"), "wb"); //открываем новый файл на запись
    dfn *dfn_array = new dfn [50]; //выделяем массив для дефайнов
    char str[256];//записываемая строка
    char buf[256];//буферная строка
    int count = 0; //Счетчик элементов массива
    char *find_name;//указатель на найденное имя макроса в строке
    int len_string;
    int len_value;
    int len_name;

    while (!feof(p_orig)) {
        fgets(str, 64, p_orig);
        if (strncmp(str, "#define", 7) == 0) {
            //ищем в строке слово #define если находим, выполняем данное условаие
            // p1 - " "  Указатель на первый пробел после дефайна
            // p2 - " " на второйч
            char *p1 = strchr(str, ' '); //указатель на первый пробел с начала строки
            char *p2 = strrchr(str, ' '); //указатель на первый пробел с конца строки, он соответсвует второму пробелу от начала
            len_string = strlen(str) - 1; //длина всей строки строки без учета \n
            len_value = strlen(p2) - 2; //длина строки с количеством символов value отнимаем, минус 2 это мы отнимаем второй пробел и '\n',
            len_name = len_string - len_value - 9; //длина строки с количеством симв. name, длин_общая-длина_значения-#define - пробелы
            strncpy((dfn_array + count)->name, p1 + 1, len_name);
            /*записываем в массив нужное количество символов для name, указатель p1+1 смещаем на единицу, т.к мы не записыываем пробел, а идем на
            один символ вперед*/
            strncpy((dfn_array + count)->value, p2 + 1, len_value); //тут то же самое, только для value
            (dfn_array + count)->value_lenght = len_value;
            count++;
            //Я ХОРОШИЙ КОД, ОТКОМПИЛИРУЙ МЕНЯ ПОЛНОСТЬЮ
        } else {
            strcpy(buf, str);
            for (int i = 0; i < count; ++i) {
                //Цикл перебирает имена из массива и смотрит есть ли такое же имя в строке
                for (int j = 0; j < len_string; ++j) {
                    /*т.к ф-ция strstr возвращает нам только указатель на первое вхождение имени внутри строки, то мы
                    делаем цикл который будет перебирать посимвольно всю строку и от каждого символа запускать заново поиск strstr
                    это сделано для того, чтобы мы могли найти в одной и той же строке все повторы букв*/
                    if (find_name = strstr(buf + j, (dfn_array + i)->name)) {
                        strncpy(find_name, (dfn_array + i)->value, (dfn_array + i)->value_lenght);
                    }
                }
            }
            cout << buf<<endl;
            fputs(buf, p_edit);
        }
    }
    fcloseall();
    delete []dfn_array;
    return 0;
}

