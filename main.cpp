#include <iostream>
#include <vector>

using namespace std;

int xtablero;
int ytablero;

//Opciones
int xcambios[] = {0, 1, 0, -1};
int ycambios[] = {1, 0, -1, 0};
char directions[] = {'N', 'E', 'S', 'W'};


int main()
{
    cin >>xtablero>>ytablero;
    //Se rellenan con filas de tipo vector bool con falses.
    vector<vector<bool>> tablero(ytablero + 1, vector<bool> (xtablero + 1, false));


    int x;
    int y;
    char inicio;
    string sequencia;
    string resultado;

    while (cin >> x >> y >> inicio >> sequencia)
    {
        int direccion;

            for (int i = 0; i < 4; ++i)
                if (inicio==directions[i])
                    direccion=i;

            bool fuera = false;

            for (int i=0; i < sequencia.size(); ++i)
            {
                if (sequencia[i]=='R')
                    direccion=(direccion+1)%4;
                else if (sequencia[i] =='L')
                    direccion=(direccion+3)%4;
                else
                {
                    //cout<<"test3"<<endl;
                    if (x + xcambios[direccion]== -1 or x + xcambios[direccion]==xtablero + 1 or y + ycambios[direccion] == -1 or y + ycambios[direccion]==ytablero + 1)
                    {
                       // cout<<"test4"<<endl;
                        if (!tablero[x][y])
                        {
                          //  cout<<"test1"<<endl;
                            tablero[x][y]=fuera=true;
                            break;
                        }
                    }

                    else
                    {
                        //cout<<"test2"<<endl;
                        x= x+xcambios[direccion];
                        y= y+ycambios[direccion];
                    }
                }
            }

            if(fuera){
                resultado=" LOST";
            }
            else{
                resultado="";
            }

            cout << x << ' ' << y << ' ' << directions[direccion] << resultado << '\n';
        }
}