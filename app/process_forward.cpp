#include "_text.h"

void process_forward(text txt,
                     void (*process)(int index, std::string contents, int cursor,
                                     void *data), void *data)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    }


    /* Стартуем с начальной строки текста */
    std::list<std::string>::iterator current = txt->myList->begin();
    int index = 0;
    int cursor_position = -1;

    /* К каждой строке текста применяем обработчик */
    while (current != txt->myList->end()) {
        if (txt->cursor->line == current)
            cursor_position = txt->cursor->position;
        else
            cursor_position = -1;
        process(index, *current, cursor_position, data);
        current++;
        index++;
    }
}
