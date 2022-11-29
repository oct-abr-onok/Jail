#include "StrategyFactory.hpp"

//Стратегии:
int Strategy::points_cnt(void)
{
    return points;
}

void Strategy::add_points(int cnt)
{
    points += cnt;
}

int Strategy::choice(void)
{
    return 0;
}

int Triv1::choice(void)
{
    return 1;
}

int Triv2::choice(void)
{
    return 0;
}

int Triv3::choice(void)
{
    return rand() % 2;
}

//Фабрики стратегий:
Strategy *Triv1Factory::create() const
{
    return new Triv1;
}

Strategy *Triv2Factory::create() const //попробовать сделать через шаблон для всех
{
    return new Triv2;
}

Strategy *Triv3Factory::create() const //попробовать сделать через шаблон для всех
{
    return new Triv3;
}

//эксперименты
int main()
{
    srand(time(0));
    Triv3Factory T1F;
    Strategy *S = T1F.create();
    for (int j = 0; j < 10; j++)
    {
        int i = S->choice();
        std::cout << i << std::endl;
    }
    return 0;
}