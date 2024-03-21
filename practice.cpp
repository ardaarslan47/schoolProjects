enum cities
{
    Istanbul,
    Ankara,
    Eskisehir,
    Adana,
    Isparta
};
enum status
{
    sale,
    rent
};
const int row = 5;
const int column = 2;

/*
            Sale    Rent
Istanbul     0       0
Ankara       0       0
Eskisehir    12      0
Adana        0       0
Isparta      0       0
*/
int estates[row][column];

void activateAll()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            estates[i][j] = 0;
        }
    }
}

int sumOfOneRow(int r)
{
    int sum;
    for (int i = 0; i < column; i++)
    {
        sum += estates[r][column];
    }
    return sum;
}

int* findLargest()
{
    int largest = estates[0][0];
    int index[2] = {0, 0};

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (estates[i][j] > largest)
            {
                largest = estates[i][j];
                index[0] = i;
                index[1] = j;
            }
        }
    }
    static int result[3] = {largest, index[0], index[1]};

    return result;
}

void sumOfOneColumn(int (*two_dimension_array)[])
{

}

int main()
{

    estates[Eskisehir][sale] = 12;
    sumOfOneColumn(estates);

    return 0;
}