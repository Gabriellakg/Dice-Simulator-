#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int lancar_dado() // funcao que lanca os dois dados e retorna o valor da soma
{
	int dado_1, dado_2, soma_dados;
	dado_1 = rand() % 6 + 1;
	dado_2 = rand() % 6 + 1;
	soma_dados = dado_1 + dado_2;
	return soma_dados;
}

int main()
{

	int somas[11] = {0}; //  um array de para guardar as somas de 2-12; elementos iniciados com valor 0)
	double frequencia[11] = {0};
	
	for (int i = 0; i < 34000; i++) // lanca os dados 34000 vezes
	{
		int lancamento = lancar_dado(); 
		somas[lancamento-2]++;	// vai incrementando somas[valor da soma lancamento] a medida que jogam os dados
	}
	
	for (int i = 2; i <= 12; i++)
	{
		frequencia[i - 2] = (static_cast<double>(somas[i - 2]) / 34000) * 100.0; // calculo da frequencia com o static_cast<double> para uma precisao decimal
		cout << "Somatorio " << i << ": " << somas[i-2] << " vezes / Frequencia " << i << ": " << frequencia[i-2] << "%" << endl;
	}
	

}

	
