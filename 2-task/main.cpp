#include <iostream>
#include <conio.h>
#include <string>
#include <cpr/cpr.h>

int main() {
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
                      cpr::Header({{"Accept", "text/html"}}));
    
    size_t start = r.text.find("<h1>");
    size_t finish = r.text.find("</h1>");
    std::cout << r.text.substr(start + 4, finish - start - 4);
    getch();
    return 0;   
}

/*
Запросите с сервера HTML-страницу. Для этого изучите документацию о запросах, 
поддерживаемых сервисом httpbin.org/html. Найдите там запрос, который выдаёт 
именно HTML-страницу. Затем сделайте запрос, явным образом используя заголовок 
accept: text/html. В полученном ответе найдите заголовок статьи и выведите его в консоль.
*/