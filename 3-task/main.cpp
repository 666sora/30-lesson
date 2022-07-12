#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <cpr/cpr.h>

void doRequest(std::vector<cpr::Pair>& arguments, std::string& answer) {
    if (answer == "post") {
        cpr::Payload p(arguments.begin(), arguments.end());
        cpr::Response r = cpr::Post(cpr::Url{"http://httpbin.org/post"},
                                    cpr::Payload{arguments.begin(), arguments.end()});
        std::cout << r.text << std::endl;
    }
    else if(answer == "get") {
        std::string tempStr = "http://httpbin.org/get?";
        for (int i = 0; i < arguments.size(); i++) {
            tempStr += arguments[i].key + "=" + arguments[i].value + "&";
        }
        cpr::Response r = cpr::Get(cpr::Url{tempStr.c_str()});
        std::cout << r.text << std::endl;
    }
}

int main() {
    std::string answer;
    std::vector<cpr::Pair> arguments;

    while(answer != "post" && answer != "get") {
        std::cout << "Input key and value: ";
        std::getline(std::cin, answer);
        if (answer == "post" || answer == "get") continue;
        std::string first, second;
        first = answer.substr(0, answer.find(" "));
        second = answer.substr(answer.find(' ') + 1, answer.find('\0') - answer.find(' ') - 1);
        arguments.push_back({first.c_str(), second.c_str()});         
    }

    doRequest(arguments, answer);

    getch();
    return 0;   
}

/*
Сделайте запрос к сервису httpbin.org, отправив при этом несколько дополнительных аргументов с данными.
Все названия аргументов и их значения строковые и принимаются от пользователя. Пользователь 
последовательно вводит их названия вместе со значениями, пока не встретится аргумент с названием 
“post” или “get”, что будет означать, что ввод аргументов закончен и требуется отправить их на сервер выбранным способом.
Если пользователь выбрал “post”, то выполняется POST-запрос и аргументы отправляются 
POST-способом (как форма). Если “get”, то выполняется GET-запрос с GET-аргументами (прямо в URL).
По результатам выполнения запроса выведите ответ сервера в стандартную консоль и 
обратите внимание на поля form или args, в зависимости от типа запроса в которых должны быть перечислены все введённые вами аргументы.
*/