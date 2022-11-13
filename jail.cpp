#include "jail.hpp"

struct matrix
{
    int p1_res, p2_res, p3_res;
};

void read_matrix(matrix ***matrix, std::string filename = "default_matrix.txt")
{
    std::ifstream fin(filename);
    char buf[50];
    fin.getline(buf, 50); //читаем первую строку(бесполезную)

    //чтение всей остальной матрицы
    int p1, p2, p3;
    for (int i = 0; i < 8; i++)
    {
        fin.getline(buf, 50);
        //выбор заключённых
        buf[0] == 'C' ? p1 = 1 : p1 = 0;
        buf[3] == 'C' ? p2 = 1 : p2 = 0;
        buf[6] == 'C' ? p3 = 1 : p3 = 0;

        //баллы заключённым соответственно
        matrix[p1][p2][p3].p1_res = buf[13] - '0';
        matrix[p1][p2][p3].p2_res = buf[16] - '0';
        matrix[p1][p2][p3].p3_res = buf[19] - '0';
    }

    fin.close();
}

int main(int argc, char *argv[])
{
    matrix ***matrix = new struct matrix **[2];
    for (int i = 0; i < 2; i++)
    {
        matrix[i] = new struct matrix *[2];
        for (int j = 0; j < 2; j++)
        {
            matrix[i][j] = new struct matrix[2];
        }
    }

    read_matrix(matrix);

    return 0;
}