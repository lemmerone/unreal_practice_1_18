#include <iostream>
#include <string>
#include <algorithm>
#include <ranges>

class Player
{
private:
    std::string name;
    float score;
public:
    Player() : name(""), score(0)
    {}
    Player(std::string _name, float _score) : name(_name), score(_score)
    {}

    std::string getName()
    {
        return name;
    }
    float getScore()
    {
        return score;
    }
};

//получение параметров каждого игрока
void getPlayerParameters(Player **arrayPlayers, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::string name;
        float score;

        std::cout << "\n" << "Player name " << i << ": ";
        std::cin >> name;
        std::cout << "\n" << "Player score " << name << ": ";
        std::cin >> score;
        arrayPlayers[i] = new Player(name, score);
    }
}

//сортировка массива пузырьком
void bubbleSort(Player** arrayPlayers, int size)
{
    while (size--)
    {
        bool swapped = false;

        for (int i = 0; i < size; i++)
        {
            if (arrayPlayers[i] > arrayPlayers[i + 1])
            {
                std::swap(arrayPlayers[i], arrayPlayers[i + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

//вывод массива
void printArray(Player** arrayPlayers, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "\n" << arrayPlayers[i]->getName();
        std::cout << " " << arrayPlayers[i]->getScore();
    }
}

int main()
{
    int size;
    std::cout << "Number of players: ";
    std::cin >> size;

    Player **arrayPlayers = new Player*[size];

    getPlayerParameters(arrayPlayers, size);
    bubbleSort(arrayPlayers, size);
    printArray(arrayPlayers, size);

    for (int i = 0; i < size; ++i) {
        delete arrayPlayers[i];
    }

    // Освобождение памяти, выделенной для массива указателей
    delete[] arrayPlayers;
}

