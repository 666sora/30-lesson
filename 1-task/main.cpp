#include <iostream>
#include <string>
#include <cstring>
#include <cpr/cpr.h>

int main() {
    std::string answer;
    while (answer != "exit") {
        std::cout << "Input command: ";
        std::cin >> answer;

        if (answer == "get") {
            cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get"));
            std::cout << r.text << std::endl;
        }
        else if (answer == "post") {
            std::string key, value;
            std::cout << "Input key and value: ";
            std::cin >> key >> value;
            cpr::Response r = cpr::Post(cpr::Url{"http://www.httpbin.org/post"},
                              cpr::Payload{{key.c_str(), value.c_str()}});
            std::cout << r.text << std::endl;
        }
        else if (answer == "put") {
            std::string key, value;
            std::cout << "Input key and value: ";
            std::cin >> key >> value;
            cpr::Response r = cpr::Put(cpr::Url{"http://www.httpbin.org/put"},
                              cpr::Payload{{key.c_str(), value.c_str()}});
            std::cout << r.text << std::endl;
        }
        else if (answer == "delete") {
            cpr::Response r = cpr::Delete(cpr::Url{"http://www.httpbin.org/delete"});
            std::cout << r.text << std::endl;
        }
        else if (answer == "patch") {
            std::string key, value;
            std::cout << "Input key and value: ";
            std::cin >> key >> value;
            cpr::Response r = cpr::Patch(cpr::Url{"http://www.httpbin.org/patch"},
                                         cpr::Payload{{key.c_str(), value.c_str()}});
            std::cout << r.text << std::endl;
        }
    }
    return 0;
}

/*
Реализуйте программу по осуществлению различных типов HTTP-запросов к сервису httpbin.org.
Пользователь взаимодействует с программой с помощью команд: “get”, “post”, “put”, “delete”, “patch”. В зависимости от команды к серверу httpbin.org осуществляется запрос того или иного типа. Содержимое ответа сервера выводится в стандартный вывод.
Программа завершается, когда пользователь вводит команду “exit”.
*/