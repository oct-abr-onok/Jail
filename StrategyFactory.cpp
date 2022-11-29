#include "StrategyFactory.hpp"

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

//Стратегии:
int Strategy::points_cnt(void)
{
    return points;
}

void Strategy::add_points(int cnt)
{
    points += cnt;
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
    srand(time(0));
    return rand() % 2;
}

//эксперименты
Triv1Factory T1F;
Strategy *S = T1F.create();
int i = S->choice();
