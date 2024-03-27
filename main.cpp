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

    std::vector<size_t> B(spravo4nik.size());
    FillInc(B, B.size());

    size_t M = (int)std::log2(spravo4nik.size()) - 1;
    std::vector<int> h(M);
    h[0] = 1;
    for (int i = 1; i < M; i++)
        h[i] = 2 * h[i - 1] + 1;
    for (int a = M - 1; a >= 0; a--)
        for (size_t i = h[a]; i < spravo4nik.size(); i++)
            for (int j = i - h[a]; j >= 0 and commpare(spravo4nik[B[j]], spravo4nik[B[j + h[a]]]); j -= h[a])
                std::swap(B[j], B[j + h[a]]);

    for (auto i : B)
        std::println("{:11} {:7} {:15} {:11}", spravo4nik[i].surname, spravo4nik[i].name, spravo4nik[i].patronymic, spravo4nik[i].number);

    return 0;
}
