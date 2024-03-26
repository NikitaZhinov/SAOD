#include <locale>
#include <print>
#include <vector>

import BaseArrFuncs;
import Sorts;
import Search;

struct Abonent {
    std::string surname;
    std::string name;
    std::string patronymic;
    size_t number;
};

bool commpare(Abonent x, Abonent y) {
    if (x.surname.compare(y.surname) == 0) {
        if (x.name.compare(y.name) == 0) {
            if (x.patronymic.compare(y.patronymic) == 0)
                return x.number > y.number;
            return x.patronymic.compare(y.patronymic) > 0;
        }
        return x.name.compare(y.name) > 0;
    }
    return x.surname.compare(y.surname) > 0;
}

int main() {
    std::setlocale(LC_ALL, "rus");

    std::vector<Abonent> spravo4nik;
    spravo4nik.push_back({ "Иванов", "Иван", "Иванович", 88005553535 });
    spravo4nik.push_back({ "Иванов", "Аван", "Иванович", 88005553530 });
    spravo4nik.push_back({ "Хлебов", "Хлеб", "Хлебович", 88888888888 });
    spravo4nik.push_back({ "Романов", "Михаил", "Александрович", 89345672673 });
    spravo4nik.push_back({ "Абвгдов", "Абвгд", "Абвгдеев", 89000000000 });
    spravo4nik.push_back({ "Охлобыстин", "Иван", "Иванович", 0 });

    ShellSort(spravo4nik, commpare);

    for (int i = 0; i < spravo4nik.size(); i++)
        std::println("{:11} {:7} {:15} {:11}", spravo4nik[i].surname, spravo4nik[i].name, spravo4nik[i].patronymic, spravo4nik[i].number);

    return 0;
}
