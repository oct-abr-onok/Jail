#ifndef SF_642
#define SF_642
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

//Фабрики стратегий:
class StrategyFactory
{
public:
    virtual Strategy *create() const;
};

class Triv1Factory : public StrategyFactory
{
public:
    Strategy *create() const;
};

class Triv2Factory : public StrategyFactory
{
public:
    Strategy *create() const;
};

class Triv3Factory : public StrategyFactory
{
public:
    Strategy *create() const;
};

//Стратегии:
class Strategy
{
private:
    int points = 0;

public:
    int points_cnt(void);
    virtual int choice(void);
    void add_points(int cnt);
};

class Triv1 : public Strategy
{
    int choice(void);
};

class Triv2 : public Strategy
{
    int choice(void);
};

class Triv3 : public Strategy
{
    int choice(void);
};

#endif /*SF_642*/