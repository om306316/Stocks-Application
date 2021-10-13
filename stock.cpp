#include <iostream>
#define MAX 50
using namespace std;
double totalstock = 0;
double totalP = 0;
void buy(int &front, int &rear, int stocks[], int price[], int sum[])
{
    if (rear == MAX - 1)
    {
        cout << "Queue is full" << endl;
        return;
    }
    else
    {
        cout << "Enter Amount of Shares " << endl;
        cin >> stocks[rear];
        totalstock += stocks[rear];
        cout << "Enter Price for each stocks" << endl;

        cin >> price[rear];
        rear++;
    }

    return;
}
void total1(double t)
{
    totalP = totalP + t;
}
void display(int totalstock, int totalP)
{
    cout << " STOCK MARKET APPLICATION " << endl;
    cout << "Total remaining Stocks :" << totalstock << endl;
    cout << "Total Profit or Loss done by all the TRANSACTIONS :" << totalP << endl;
}

int sell(int &front, int &rear, int stocks[], int price[])
{
    int diff[MAX];
    int p1, p2, p3, temp;
    double total = 0;
    {
        if (front == rear)
        {

            printf("\nQueue is empty\n");
            return 0;
        }
        else
        {
            cout << "Amount of shares you want to sell : ";
            cin >> p1;
            cout << "Enter Amount of price on which it's selling : ";
            cin >> p2;
            if (totalstock < p1)
            {
                cout << "You don't have enough stocks in your pscket " << endl;
                return 0;
            }
            else
            {
                totalstock -= p1;
            }
            while (p1 > 0)
            {
                if (p1 < stocks[front])
                {
                    stocks[front] = stocks[front] - p1;
                    total = total + p1 * (p2 - price[front]);
                    p1 = 0;
                }
                else
                {
                    total = total + stocks[front] * (p2 - price[front]);
                    p1 = p1 - stocks[front];
                    front++;
                }
            }
            total1(total);
        }
    }
}
int main()
{
    int rear;
    int front = rear = 0;
    int stocks[MAX];
    int price[MAX];
    int sum[MAX];
    while (1)
    {
        cout << "Choose any option :" << endl;
        cout << "1. Buy" << endl;
        cout << "2. Sell" << endl;
        cout << "3. Total Capital Gain So Far" << endl;
        cout << "4. Quit" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            buy(front, rear, stocks, price, sum);
            break;
        }
        case 2:
        {
            sell(front, rear, stocks, price);
            break;
        }
        case 3:
        {
            system("cls");
            display(totalstock, totalP);
            break;
        }

        case 4:
        {
            return 0;
        }
        }
    }
}