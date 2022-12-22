#include "jail.hpp"
#include "StrategyFactory.hpp"

struct matrix
{
    int p1_res, p2_res, p3_res;
};

void read_matrix(matrix ***matrix, std::string filename = "default_matrix.txt")
{
    std::ifstream fin(filename);
    std::string buf;
    std::getline(fin, buf);

    // чтение всей остальной матрицы
    int p1, p2, p3;
    for (int i = 0; i < 8; i++)
    {
        std::getline(fin, buf);
        // выбор заключённых
        buf[0] == 'C' ? p1 = 1 : p1 = 0;
        buf[3] == 'C' ? p2 = 1 : p2 = 0;
        buf[6] == 'C' ? p3 = 1 : p3 = 0;

        // баллы заключённым соответственно
        matrix[p1][p2][p3].p1_res = buf[13] - '0';
        matrix[p1][p2][p3].p2_res = buf[16] - '0';
        matrix[p1][p2][p3].p3_res = buf[19] - '0';
    }

    fin.close();
}

void detailed_step(matrix ***matrix, Strategy *S1, Strategy *S2, Strategy *S3)
{
    int i = S1->choice();
    int j = S2->choice();
    int k = S3->choice();
    char is, js, ks;
    i == 0 ? is = 'D' : is = 'C';
    j == 0 ? js = 'D' : js = 'C';
    k == 0 ? ks = 'D' : ks = 'C';

    S1->add_points(matrix[i][j][k].p1_res);
    S2->add_points(matrix[i][j][k].p2_res);
    S3->add_points(matrix[i][j][k].p3_res);

    std::cout << std::endl;
    std::cout << "Choices: p1: " << is << " p2: " << js << " p3: " << ks << std::endl;
    std::cout << "Points for the current step: p1: " << matrix[i][j][k].p1_res << " p2: " << matrix[i][j][k].p2_res << " p3: " << matrix[i][j][k].p3_res << std::endl;
    std::cout << "Total points: p1: " << S1->points_cnt() << " p2: " << S2->points_cnt() << " p3: " << S3->points_cnt() << std::endl
              << std::endl;
}

void detailed_competition(matrix ***matrix, StrategyFactory *SF1, StrategyFactory *SF2, StrategyFactory *SF3, int steps = -1)
{
    Strategy *S1 = SF1->create();
    Strategy *S2 = SF2->create();
    Strategy *S3 = SF3->create();

    for (int i = 0; i != steps; i++)
    {
        std::string command;
        std::getline(std::cin, command);
        if (command == "quit")
            break;
        detailed_step(matrix, S1, S2, S3);
    }
}

int main(int argc, char *argv[])
{
    srand(time(0));

    // матрица баллов
    matrix ***matrix = new struct matrix **[2];
    for (int i = 0; i < 2; i++)
    {
        matrix[i] = new struct matrix *[2];
        for (int j = 0; j < 2; j++)
        {
            matrix[i][j] = new struct matrix[2];
        }
    }

    // работа с аргументами коммандной строки
    // jail.exe -mode detailed --steps 5 --matrix example_matrix.txt
    int mode = 0; // 0 - detailed, 1 - fast, 2 - tournament
    std::string matrix_file_name = "default_matrix.txt";
    int steps = -1;

    for (int i = 1; i < argc; i++)
    {
        std::string str = std::string(argv[i]);
        std::string command;
        command = str.substr(0, 5);
        if (command == "-mode=")
        {
            command = str.substr(6, std::string::npos);
            if (command == "detailed")
            {
                mode = 0;
            }
            else if (command == "fast")
            {
                mode = 1;
            }
            else if (command == "tournament")
            {
                mode = 2;
            }
        }
        command = str.substr(0, 7);
        if (command == "--steps=")
        {
            steps = stoi(str.substr(8, std::string::npos));
        }
        command = str.substr(0, 8);
        if (command == "--matrix=")
        {
            matrix_file_name = str.substr(9, std::string::npos);
        }
    }

    read_matrix(matrix, matrix_file_name);
    std::cout << "reading res: " << matrix[1][1][1].p1_res << std::endl;

    // соревнование с детализацией
    StrategyFactory *SF1 = new Triv1Factory;
    StrategyFactory *SF2 = new Triv2Factory;
    StrategyFactory *SF3 = new Triv3Factory;
    detailed_competition(matrix, SF1, SF2, SF3);

    return 0;
}