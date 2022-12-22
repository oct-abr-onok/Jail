## Проект - Дилемма заключённых
[Техническое задание](https://docs.google.com/document/d/1--FpmFFmrvJVK8fyuw-73rmmw7O76_qR5usYF-jHQn8/edit)

### Реализация:
Стратегии - **класс**
записывают историю ходов, и результат в очках.
Матрица - заносится в структуру(3хмерный массив), после в результате выбора действий стратегиями - стратегиям добавляются очки согласно данной матрице.

#### Реализовать 1(выполнено):
Соревнование с детализацией. На каждом шаге программа ожидает нажатия клавиши от пользователя, после которого делает один шаг. Подробное состояние симуляции выводится после каждого шага (выбор каждой стратегии, очки за текущий ход, очки за текущую игру).
Игра прерывается по команде `quit`.

#### Тривиальные стратегии:
1.  Всегда D
2.  Всегда S
3.  50 на 50

#### Стандартная матрица игры:
    p1 p2 p3     p1 p2 p3
    С  С  С  =>  7  7  7  //заключённые 1, 2 и 3 получают по 7 очков
    C  C  D  =>  3  3  9
    C  D  C  =>  3  9  3
    D  C  C  =>  9  3  3
    C  D  D  =>  0  5  5
    D  C  D  =>  5  0  5
    D  D  C  =>  5  5  0
    D  D  D  =>  1  1  1

#### Реализовать 2:
Параметры коммандной строки.

#### Параметры коммандной строки:
* `-mode=[detailed|fast|tournament]` (опциональный, по умолчанию - `detailed` для трех стратегий, `tournament` для >3 стратегий)
* `--steps=<n>` (опциональный)
* `--matrix=<filename>`(опциональный)

Вроде сделал, надо проверить, уточнить по поводу доп аргументов(выбор стратегии)

#### Реализовать 3:
Быстрое соревнование: Соревнование без детализации. Программа вычисляет заданное количество ходов и выводит результат.

#### Реализовать 4:
Сложные стратегии, (подкласс с системой хранения истории ходов)

#### Сложные стратегии:
(нужно придумать после реализации основоного кода + тривиальных стартегий)

#### Реализовать 5:
Юнит тесты.
